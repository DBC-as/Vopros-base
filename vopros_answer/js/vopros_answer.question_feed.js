/**
 * Small script for handling emails on question list.
 */

(function ($) {
  Drupal.behaviors.voprosAnswerQuestionFeed = {
    attach: function(context, settings) {
      $(".vopros-answer .see-more").click(function () {
        $(this).hide().next().show();
      });
    }
  };
})(jQuery);
