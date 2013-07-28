<?php

/**
 * @file
 * Entity classes defined by vopros_email module.
 */


/**
 * Entity class for vopros service entities.
 */
class VoprosService extends VoprosEntity {}

/**
 * Entity class for vopros service message entities.
 */
class VoprosServiceMessage extends VoprosEntity {

  /**
   * Default label for vopros service message.
   */
  protected function defaultLabel() {
    if (strlen($this->message_content) < 31) {
      return $this->message_content;
    }
    else {
      return substr($this->message_content, 0, 30) . '…';
    }
  }
}
