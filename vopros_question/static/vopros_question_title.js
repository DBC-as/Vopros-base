(function ($) {
  Drupal.behaviors.voprosQuestion = {
    attach: function(context, settings) {
      $("h2.question-title").click(function() {
        $(this).hide().after($(".title-form > *"));
      });
    }
  };
})(jQuery);