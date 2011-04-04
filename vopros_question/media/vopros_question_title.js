(function ($) {
  Drupal.behaviors.exampleModule = {
    attach: function(context, settings) {
      $(".views-field-question-title .field-content").click(function() {
        $(this).hide().after($(".title-form > *"));
      });
    }
  };
})(jQuery);