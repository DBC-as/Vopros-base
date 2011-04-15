(function ($) {
  Drupal.behaviors.voprosQuestion = {
    attach: function(context, settings) {
      $(".views-field-question-title .field-content").click(function() {
        $(this).hide().after($(".title-form > *"));
      });
    }
  };
})(jQuery);