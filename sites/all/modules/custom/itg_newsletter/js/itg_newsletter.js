/*
 * @file itg_newsletter.js
 */

(function ($) {
    Drupal.behaviors.itg_newsletter = {
        attach: function (context, settings) {

            //Collect required variables
            var uid = settings.itg_newsletter.settings.uid;
            base_url = settings.itg_newsletter.settings.base_url;
            var type = settings.itg_newsletter.settings.type;
            var nid = settings.itg_newsletter.settings.nid;

            if (nid) {
                $('input[name="field_newsl_add_news_und_0_remove_button"]').show();
            } else {
                //$('input[name="field_newsl_add_news_und_0_remove_button"]').hide();
                $('#edit-field-newsl-add-news-und-0-remove-button').hide();
            }

            //Hide left side vertical tabs in case of simple users
            if (uid != 1) {
                $('.field-edit-link').hide();
                $('#edit-body-und-0-format').hide();
                $('.vertical-tabs-list').hide();
                $('#edit-metatags').show();
            }

            //Hide/Sho Automatic and manual fields
            if ($("input[name='field_newsl_newsletter_type[und]']:checked").val() === 'automatic') {

                $('#edit-field-newsl-schedule').hide();
                $('#edit-field-newsl-frequency').show();
                $('#edit-field-newsl-newsletter-content').show();
                $('.group-newsl-add-news').hide();
                $('.form-field-name-field-survey-start-date').hide();

                //Day, date and time
                if ($("input[name='field_newsl_frequency[und]']:checked").val() === 'daily') {
                    $('#edit-field-newsl-time').show();
                    $('#edit-field-newsl-time-period').show();
                    $('#edit-field-newsl-day').hide();
                    $('#edit-field-newsl-date').hide();
                } else if ($("input[name='field_newsl_frequency[und]']:checked").val() === 'weekly') {
                    $('#edit-field-newsl-day').show();
                    $('#edit-field-newsl-time').show();
                    $('#edit-field-newsl-time-period').hide();
                    $('#edit-field-newsl-date').hide();
                } else {
                    $('#edit-field-newsl-date').show();
                    $('#edit-field-newsl-time').show();
                    $('#edit-field-newsl-time-period').hide();
                    $('#edit-field-newsl-day').hide();
                }
            } else {
                $('#edit-field-newsl-schedule').show();
                $('.group-newsl-add-news').show();
                $('#edit-field-newsl-frequency').hide();
                $('#edit-field-newsl-newsletter-content').hide();
                $('#edit-field-newsl-day').hide();
                $('#edit-field-newsl-date').hide();
                $('#edit-field-newsl-time-period').hide();

                if ($("input[name='field_newsl_schedule[und]']:checked").val() === 'later') {
                    $('#edit-field-survey-start-date').show();
                    $('#edit-field-newsl-time').show();
                } else {
                    $('#edit-field-newsl-time').hide();
                    $('#edit-field-survey-start-date').hide();
                    $('#edit-field-newsl-date').hide();
                }

            }

            //Aautomatic and manual hide/show onclick
            $("input[name='field_newsl_newsletter_type[und]']").on("click", function () {
                var check_radio_name = $(this).val();

                if (check_radio_name === 'automatic') {

                    $('#edit-field-newsl-schedule').hide();
                    $('.form-field-name-field-survey-start-date').hide();
                    $('#edit-field-newsl-frequency').show();
                    $('#edit-field-newsl-newsletter-content').show();
                    $('.group-newsl-add-news').hide();

                    //Day, date and time
                    if ($("input[name='field_newsl_frequency[und]']:checked").val() === 'daily') {
                        $('#edit-field-newsl-time').show();
                        $('#edit-field-newsl-time-period').show();
                        $('#edit-field-newsl-day').hide();
                        $('#edit-field-newsl-date').hide();
                    } else if ($("input[name='field_newsl_frequency[und]']:checked").val() === 'weekly') {
                        $('#edit-field-newsl-day').show();
                        $('#edit-field-newsl-time').show();
                        $('#edit-field-newsl-time-period').show();
                        $('#edit-field-newsl-time-date').hide();
                    } else {
                        $('#edit-field-newsl-date').show();
                        $('#edit-field-newsl-time').show();
                        $('#edit-field-newsl-time-period').show();
                        $('#edit-field-newsl-day').hide();
                    }
                } else {
                    $('#edit-field-newsl-schedule').show();
                    $('.group-newsl-add-news').show();
                    $('#edit-field-newsl-frequency').hide();
                    $('#edit-field-newsl-newsletter-content').hide();
                    $('#edit-field-newsl-day').hide();
                    $('#edit-field-newsl-date').hide();
                    $('#edit-field-newsl-time-period').hide();
                    if ($("input[name='field_newsl_schedule[und]']:checked").val() === 'later') {
                        $('#edit-field-survey-start-date').show();
                        $('#edit-field-newsl-time').show();
                    } else {
                        $('#edit-field-survey-start-date').hide();
                        $('#edit-field-newsl-time').hide();
                    }
                }
            });
            
            //Newsletter Content hide/show onclick for section select
            
            $("input[name='field_newsl_newsletter_type[und]']").on("click", function () {
                var newsletter_type = $(this).val();
                if (newsletter_type === 'manual') {
                    $('#edit-field-story-category').hide();
                } 
                 if (newsletter_type === 'automatic') {
                    $('#edit-field-story-category').show();
                    $("input[name='field_newsl_newsletter_content[und]']:checked").trigger('click');
                 } 
             });
            
            var newsletter_content = $("input[name='field_newsl_newsletter_content[und]']:checked").val();
            if (newsletter_content === 'select_section') {
                $('#edit-field-story-category').show();
            } else  {
                $('#edit-field-story-category').hide();
            }
            
            $("input[name='field_newsl_newsletter_content[und]']").on("click", function () {
                var newsletter_content = $(this).val();
                if (newsletter_content === 'select_section') {
                    $('#edit-field-story-category').show();
                } else  {
                    $('#edit-field-story-category').hide();
                }
                
            });
            //Aautomatic and manual hide/show onclick for section select

            
            //Day,date and time hide/show on click
            $("input[name='field_newsl_frequency[und]']").on("click", function () {
                var check_radio_name = $(this).val();
                if (check_radio_name === 'daily') {
                    $('#edit-field-newsl-time').show();
                    $('#edit-field-newsl-time-period').show();
                    $('#edit-field-newsl-day').hide();
                    $('#edit-field-newsl-date').hide();
                } else if (check_radio_name === 'weekly') {
                    $('#edit-field-newsl-day').show();
                    $('#edit-field-newsl-time').show();
                    $('#edit-field-newsl-time-period').show();
                    $('#edit-field-newsl-date').hide();
                } else {
                    $('#edit-field-newsl-date').show();
                    $('#edit-field-newsl-time').show();
                    $('#edit-field-newsl-time-period').show();
                    $('#edit-field-newsl-day').hide();
                }
            });

            //Now and Later Hide show
            $("input[name='field_newsl_schedule[und]']").on("click", function () {
                var check_radio_name = $(this).val();
                if (check_radio_name === 'later') {
                    $('#edit-field-survey-start-date').show();
                    $('#edit-field-newsl-time').show();
                } else {
                    $('#edit-field-survey-start-date').hide();
                    $('#edit-field-newsl-time').hide();
                }
            });

            //Read only newsletter date field
            if (type === 'Newsletter') {
                $('#edit-field-survey-start-date-und-0-value-datepicker-popup-0, #edit-field-survey-start-date-und-0-value-datepicker-popup-1, #edit-field-survey-start-date-und-0-value-datepicker-popup-2, #edit-field-survey-start-date-und-0-value-datepicker-popup-3, #edit-field-survey-start-date-und-0-value-datepicker-popup-4, #edit-field-survey-start-date-und-0-value-datepicker-popup-5').prop("readonly", true);
            }


        }
    };

})(jQuery, Drupal, this, this.document);

jQuery(document).ready(function () {
  
    //Get Newsletter data using AJAX
    jQuery('body').on('click', '.newsletter-get-content', function () {
        var contentId = jQuery(this).parent().siblings('.field-name-field-news-cid').find('.form-text').val();
        var relval = jQuery(this).attr('rel');

        var loaderImg = base_url + '/misc/throbber-active.gif';
        jQuery('.newsletter-get-content[rel="' + relval + '"]').parent().find(".newsletter-loader").html('<img src="' + loaderImg + '" alt="" />');
        
        if (contentId === '') {
            alert(Drupal.t('Please select Content ID.'));
            jQuery('.newsletter-get-content[rel="' + relval + '"]').parent().find(".newsletter-loader").html('');
            jQuery(this).parent().siblings('.field-name-field-news-cid').find('.form-text').focus();
        }
        else {
            if (jQuery('.newsletter-get-content[rel="' + relval + '"]').parent().siblings('.field-name-field-news-thumbnail').find('div').hasClass('image-preview')) {
                jQuery('.newsletter-get-content[rel="' + relval + '"]').parent().find(".newsletter-loader").html('');
                alert(Drupal.t('Please remove existing thumbnail'));
            }
            else {
                var contentIdArr = contentId.split(' (');
                jQuery.ajax({
                    url: Drupal.settings.basePath + 'newsletter_data',
                    type: "post",
                    data: {content_id: contentIdArr[0]},
                    cache: false,
                    dataType: "JSON",
                    success: function (data) {
                        jQuery('.newsletter-get-content[rel="' + relval + '"]').parent().find(".newsletter-loader").html('');
                        jQuery('.newsletter-get-content[rel="' + relval + '"]').removeClass('inactive');
                        jQuery('.newsletter-get-content[rel="' + relval + '"]').parent().find('.ajax-progress-throbber').hide();
                        jQuery('.newsletter-get-content[rel="' + relval + '"]').parent().siblings('.field-name-field-news-title').find('.form-text').val(data.title);
                        jQuery('.newsletter-get-content[rel="' + relval + '"]').parent().siblings('.field-name-field-news-kicker').find('.form-textarea').val(data.kicker);
                        jQuery('.newsletter-get-content[rel="' + relval + '"]').parent().siblings('.field-name-field-news-thumbnail').find('div.image-widget-data :hidden').attr('value', data.fid);
                        jQuery('.newsletter-get-content[rel="' + relval + '"]').parent().siblings('.field-name-field-news-thumbnail').find('div.image-widget-data .form-submit').triggerHandler('mousedown');
                    },
                    error: function () {
                        return false;
                    }
                });
            }

        }
    });

});