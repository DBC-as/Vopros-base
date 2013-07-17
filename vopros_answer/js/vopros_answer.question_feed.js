/**
 * Small script for handling emails on question list.
 */

(function ($) {
  Drupal.behaviors.voprosAnswerQuestionFeed = {
    attach: function(context, settings) {
      console.log('sdfdsf');
      $(".vopros-answer .see-more").click(function () {
        $(this).hide().next().show();
      });
    }
  };
})(jQuery);
