/*
 * @file itg_breaking_news.js
 */

/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function ($) {
    Drupal.behaviors.itg_breaking_news = {
        attach: function (context, settings) {
            var uid = settings.itg_breaking_news.settings.uid;
            var type = $('#edit-field-type-und').val();
            
           
            // code to hide body text format filter 
            if (uid != 1) {
            $('.vertical-tabs-list').hide();
            $('#edit-metatags').show();
            $('#edit-metatags-und-advanced').hide();
            
            }
            
            // type check for add form
            $("#edit-field-type-und").change(function () {
                //alert(this.value);
                if (this.value == 'Live Blog') {

                    $("input[id*=field-mark-as-breaking-band]").hide();
                    $("input[id*=field-mark-as-breaking-band]").removeAttr('checked');
                    $('label[for*="field-mark-as-breaking-band"]').hide();
                   
                    

                }
                else
                {

                    $("input[id*=field-mark-as-breaking-band]").show();
                    $('label[for*="field-mark-as-breaking-band"]').show();

                }
            });         
  
            // type check for edit form
            if (type == 'Live Blog') {
                $('input[id*=field-mark-as-breaking-band]').hide();
                $('label[for*="field-mark-as-breaking-band"]').hide();
            }
            
                                       

        }

    };
})(jQuery, Drupal, this, this.document);
