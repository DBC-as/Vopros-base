<?php

/**
 * @file
 * VorposMailhandlerProcessor class.
 */

/**
 * Parses an IMAP stream and creates and email entity.
 */
class VorposMailhandlerProcessor extends FeedsProcessor {
  /**
   * Entity type this processor operates on.
   */
  public function entityType() {
    // The entity type is alsways vopros_email.
    return 'vopros_email';
  }

  /**
   * Create a new entity.
   *
   * @param $source
   *   The feeds source that spawns this entity.
   *
   * @return
   *   A new entity object.
   */
  protected function newEntity(FeedsSource $source) {
    $email = vopros_email_new(array(
      'type' => 'ingoing',
      'status' => 'sent',
    ));
    return $email;
    
  }

  /**
   * Load an existing entity.
   *
   * @param $source
   *   The feeds source that spawns this entity.
   * @param $entity_id
   *   The unique id of the entity that should be loaded.
   *
   * @return
   *   A new entity object.
   */
  protected function entityLoad(FeedsSource $source, $entity_id) {
    
  }

  /**
   * Validate an entity.
   *
   * @throws FeedsValidationException $e
   *   If validation fails.
   */
  protected function entityValidate($entity) {
    
  }

  /**
   * Save an entity.
   *
   * @param $entity
   *   Entity to b saved.
   */
  protected function entitySave($entity) {
    vopros_email_save($entity);
  }

  /**
   * Delete a series of entities.
   *
   * @param $entity_ids
   *   Array of unique identity ids to be deleted.
   */
  protected function entityDeleteMultiple($entity_ids) {
    
  }

  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    $properties = entity_get_property_info('vopros_email');
    $properties = $properties['properties'];
    foreach ($properties as $key => $property) {
      $properties[$key]['name'] = $property['label'];
    }
    $targets += $properties;
    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_processor_targets', $targets, 'vopros_email', 'vopros_email');
    return $targets;
  }

  public function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Emails');
    return $info;
  }
}