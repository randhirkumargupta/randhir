(function ($) {
    Drupal.behaviors.itg_newsletter = {
        attach: function (context, settings) {

            (function ($, window) {
                $.fn.replaceOptions = function (options) {
                    var self, $option;

                    this.empty();
                    self = this;

                    $.each(options, function (index, option) {
                        $option = $("<option></option>")
                                .attr("value", option.value)
                                .text(option.text);
                        self.append($option);
                    });
                };
            })(jQuery, window);
            
            var options = JSON.parse(settings.itg_newsletter.options);
            $("#edit-field-story-category-und").replaceOptions(options);
            if(options.length>2) {
                jQuery("#edit-field-story-category").css("display","block");
            }else {
                jQuery("#edit-field-story-category").css("display","none");
            }
        }
    };
})(jQuery);
