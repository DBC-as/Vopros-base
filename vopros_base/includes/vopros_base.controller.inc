<?php

/**
 * Entity controller API class for vopros entities.
 *
 * Extends the EntityAPIController class, but adds support for revisions.
 */
class VoprosAPIEntityController extends EntityAPIController {
  /**
   * Implements EntityAPIControllerInterface.
   *
   * This code is basically a cope of the function defined by EntityAPIController
   * but with added support for revisions.
   *
   * @param $transaction
   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
   *   in their transaction object.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (empty($entity->created)) {
      $entity->created = REQUEST_TIME;
    }
    if (empty($entity->uuid)) {
      $entity->uuid = uuid_uuid();
    }
    if (!isset($entity->revision)) {
      $entity->revision = 1;
    }
    $transaction = isset($transaction) ? $transaction : db_transaction();
    try {
      $entity->changed = REQUEST_TIME;
      // Load the stored entity, if any.
      if (!empty($entity->{$this->idKey}) && !isset($entity->original)) {
        // In order to properly work in case of name changes, load the original
        // entity using the id key if it is available.
        $entity->original = entity_load_unchanged($this->entityType, $entity->{$this->idKey});
      }
      // Update the status for entities getting overridden.
      if (entity_has_status($this->entityType, $entity, ENTITY_IN_CODE) && empty($entity->is_rebuild)) {
        $entity->{$this->statusKey} |= ENTITY_CUSTOM;
      }

      $this->invoke('presave', $entity);

      if (!empty($entity->{$this->idKey}) && empty($entity->is_new)) {
        // Save a new revision
        if ($entity->revision) {
          unset($entity->{$this->entityInfo['entity keys']['revision']});
          $this->saveRevision($this->entityInfo['revision table'], $entity);
        }
        else {
          $this->saveRevision($this->entityInfo['revision table'], $entity, TRUE);
        }
        $return = drupal_write_record($this->entityInfo['base table'], $entity, $this->idKey);
        $this->resetCache(array($entity->{$this->idKey}));
        $this->invoke('update', $entity);
      }
      else {
        // Save revision.
        $this->saveRevision($this->entityInfo['revision table'], $entity);
        $return = drupal_write_record($this->entityInfo['base table'], $entity);
        // Update the revision.
        db_update($this->entityInfo['revision table'])
          ->fields(array($this->idKey => $entity->{$this->idKey}))
          ->condition($this->entityInfo['entity keys']['revision'], $entity->{$this->entityInfo['entity keys']['revision']})
          ->execute();
        $this->invoke('insert', $entity);
      }
      // Ignore slave server temporarily.
      db_ignore_slave();
      unset($entity->is_new);
      unset($entity->original);

      return $return;
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception($this->entityType, $e);
      throw $e;
    }
  }

  /**
   * Saves a revision with the uid of the current user.
   *
   * @param $order
   *   The fully loaded entity object.
   * @param $uid
   *   The user's uid for the current revision.
   * @param $log
   *   The log to save for the revision.
   * @param $update
   *   TRUE or FALSE indicating whether or not the existing revision should be
   *     updated instead of a new one created.
   */
  function saveRevision($table, $entity, $update = FALSE, $uid = FALSE, $log = '') {
    if ($uid === FALSE) {
      $uid = $GLOBALS['user']->uid;
    }
    $entity->revision_uid = $uid;
    $entity->revision_timestamp = REQUEST_TIME;
    if (!isset($entity->log) || (!empty($log))) {
      $entity->log = $log;
    }

    // Update the existing revision if specified.
    if ($update) {
      drupal_write_record($table, $entity, 'revision_id');
    }
    else {
      // Otherwise insert a new revision. This will automatically update $order
      // to include the revision_id.
      drupal_write_record($table, $entity);
    }
  }
}
