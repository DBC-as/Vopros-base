<?php

/**
 * @file
 * Template file for question messages.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="from">
  <span class="label"><?php print t('From:'); ?></span>
  <span class="value"><?php
    print render($content['message_from']);
  ?>
</span>
  </div>
  <div class="content"<?php print $content_attributes; ?>>
    <?php
      print render($content);
    ?>
  </div>
</div>
