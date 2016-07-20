(function($) {
    var timer;
    jQuery('#edit-terms').live('keyup', function() {
        window.clearTimeout(timer);
        timer = window.setTimeout(function() {

            var serializeform = $("#itg-image-repository-filesearch-form").serialize();

            jQuery.ajax({
                url: Drupal.settings.basePath + 'findimage',
                type: 'post',
                beforeSend: function() {
                    showloader();

                },
                data: {'formdata': serializeform},
                success: function(data) {
                    jQuery('#search-preview').html(data);
                },
                complete: function() {hideloader();},
                error: function(xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                }
            });

        }, 2000);
    })


})(jQuery);
