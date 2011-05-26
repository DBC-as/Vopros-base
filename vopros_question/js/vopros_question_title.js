(function ($) {
  Drupal.behaviors.voprosQuestionTitle = {
    attach: function(context, settings) {
      $("h2.question-title").click(function() {
        if ($(this).parents($('#vopros-answer-form')).length === 0) {
          $(this).hide().after($(".title-form > *"));
        }
      });
    }
  };
})(jQuery);