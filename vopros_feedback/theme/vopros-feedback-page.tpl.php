<?php

/**
 * @file
 * Default theme implementation to display a feedback page used in iframe.
 *
 * Available variables:
 * - $page: The rendered page content.
 *
 */

?>

<div id="vopros-feedback-page"<?php print $content_attributes; ?>>
  <div id="vopros-feedback-page-inner" class="clearfix">
    <?php print $page['#children']; ?>
  </div>
</div>
