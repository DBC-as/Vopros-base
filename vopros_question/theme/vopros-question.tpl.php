<?php
/**
 *
 */
?>
<div id="question-<?php print $question->question_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php
      print render($content);
    ?>
    <?php if (isset($feed) && $feed): ?>
      <div class="feed">
        <?php print render($feed); ?>
      </div>
    <?php endif; ?>
  </div>
  <?php if (isset($right) && !empty($right)): ?>
    <div class="action right">
      <?php print render($right); ?>
    </div>
  <?php endif ?>
</div>
