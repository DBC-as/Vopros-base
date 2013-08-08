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
   * Ensures that created, uuid and changed is set, and enforces creation of new
   * revision, before calling parent implementation.
   *
   * @param $transaction
   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
   *   in their transaction object.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $entity->revision_uid = $GLOBALS['user']->uid;
    $entity->revision_timestamp = REQUEST_TIME;
    if (empty($entity->created)) {
      $entity->created = REQUEST_TIME;
    }
    if (empty($entity->uuid)) {
      $entity->uuid = uuid_generate();
    }
    if (!isset($entity->revision)) {
      $entity->revision = 1;
    }
    if (!isset($entity->log)) {
      $entity->log = '';
    }
    $entity->changed = REQUEST_TIME;
    return parent::save($entity, $transaction);
  }
}

/**
 * Entity UI controller API class for vopros entities.
 *
 * Extends the EntityDefaultUIController class.
 */
class VoprosUIController extends EntityDefaultUIController {}
