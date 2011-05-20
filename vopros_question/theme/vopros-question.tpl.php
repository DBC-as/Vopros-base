<?php
/**
 *
 */
?>
<div id="question-<?php print $question->question_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php
      if (isset($content['action'])) {
        hide($content['action']);
      }
      print render($content);
    ?>
  </div>
  <?php if (isset($content['action'])): ?>
    <div class="action">
      <?php print render($content['action']); ?>
    </div>
  <?php endif ?>

</div>
