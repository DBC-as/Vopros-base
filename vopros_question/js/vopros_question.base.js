(function ($) {
  Drupal.behaviors.voprosQuestion = {
    attach: function(context, settings) {
      $("#vopros-question-question-frontend-form .fake-form-item").tooltip({position: "right"});
      $("#vopros-question-question-frontend-form .fake-form-item").click(function() {
        $(this).parents('.fake-wrapper').hide().next().show();
      });
    }
  };
})(jQuery);