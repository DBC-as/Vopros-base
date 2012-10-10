(function ($) {
  Drupal.behaviors.voprosQuestion = {
    attach: function(context, settings) {
      $("#vopros-question-question-frontend-form .fake-form-item").tooltip({position: "right"});
      $("#vopros-question-question-frontend-form .fake-form-item").click(function() {
        $(this).parents('.fake-wrapper').hide().next().show();
      });
    }
  };
  Drupal.behaviors.voprosQuestionList = {
    attach: function(context, settings) {
      $("#views-exposed-form-vopros-question-list-page input.form-submit").hide();
      $("#views-exposed-form-vopros-question-list-page select").change(function() {
        $("#views-exposed-form-vopros-question-list-page input.form-submit").click();
        // We need to wait a little bit for IE to send the request and send
        // the request before disabling the dropdowns.
        setTimeout(function () {$("#views-exposed-form-vopros-question-list-page select").attr("disabled","disabled")}, 100);
      });
    }
  };
})(jQuery);
