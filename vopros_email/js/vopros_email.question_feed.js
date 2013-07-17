/**
 * Small script for handling emails on question list.
 */

(function ($) {
  Drupal.behaviors.voprosEmailQuestionFeed = {
    attach: function(context, settings) {
      $(".vopros-email-display .see-more").click(function () {
        $(this).hide().next().show();
      });
      $(".vopros-email-display").first().find('.see-more').trigger('click');
    }
  };
})(jQuery);
