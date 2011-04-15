(function ($) {
  Drupal.behaviors.voprosSMSForm = {
    attach: function(context, settings) {
      $("#edit-content").bind('keyup', function(){
        var chars, smsCount;
        chars =  $(this).val().length;
        if (chars <= 160) {
          smsCount = 1;
        }
        else {
          smsCount = parseInt((chars-1)/153, 10) + 1;
        }
        $("#sms-counter .counter").text(chars + ' / ' + smsCount);
      });
    }
  };
})(jQuery);