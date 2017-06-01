/*
 * @file itg_related.js
 * Contains all functionality Related Content
 */

(function ($) {
    Drupal.behaviors.itg_front_search = {
        attach: function (context, settings) {
            var base_url = Drupal.settings.itg_front_search.settings.base_url;
            var custom_field_val = getParameterByName('custom_drp');
            $("#edit-submit-front-end-global-search").hide();
            $("#edit-reset").hide();

            $('#edit-custom-drp').change(function () {
                 $(".searh-all-filters .views-widget").hide();
                var datetypevalue = $('#edit-custom-drp').val();

                if (datetypevalue == 'calender') { // Image question
                    $(".caln").show();
                    $(".caln").show();                   
                } else {
                    $(".caln").hide();
                    $(".caln").hide();
                    $('#edit-ds-changed-datepicker-popup-0').val("");
                    $('#edit-ds-changed-max-datepicker-popup-0').val("");
                }
            });

            if (custom_field_val != 'calender') {
                $(".caln").hide();
                $(".caln").hide();
                $('#edit-ds-changed-datepicker-popup-0').val("");
                $('#edit-ds-changed-max-datepicker-popup-0').val("");
            }

            // trigger submit button
            $('#search_button').click(function () {
                $('#edit-submit-front-end-global-search').trigger('click');
            });

            // trigger reset button
            $('#reset_button').click(function () {
                $('#edit-reset').trigger('click');
            });
            

            $(function () {
                $("#edit-ds-changed-datepicker-popup-0").datepicker({
                    dateFormat: 'dd-mm-yy',
                    changeMonth: true,
                    changeYear: true,
                    onSelect: function (selected) {
                        var dt = new Date(selected);
                        dt.setDate(dt.getDate() + 1);
                        $("#edit-ds-changed-max-datepicker-popup-0").datepicker("option", "minDate", dt);
                    }
                });
                $("#edit-ds-changed-max-datepicker-popup-0").datepicker({
                    dateFormat: 'dd-mm-yy',
                    changeMonth: true,
                    changeYear: true,
                    onSelect: function (selected) {
                        var dt = new Date(selected);
                        dt.setDate(dt.getDate() - 1);
                        $("#edit-ds-changed-datepicker-popup-0").datepicker("option", "maxDate", dt);
                    }
                });
            });

            // for online story archive
            if (Drupal.settings.itg_front_search.settings.archive_story) {
                jQuery(".caln").show();
                jQuery('#edit-bundle-name-wrapper').hide();
                jQuery('.form-item-ds-changed label').hide();
                jQuery('#edit-hash-wrapper').css("display", "none");
                if (Drupal.settings.itg_front_search.settings.archive_story_front) {
                    jQuery('#archive-story-date-slider ul').slick({
                        dots: false,
                        infinite: false,
                        speed: 300,
                        slidesToShow: 7,
                        slidesToScroll: 1,
                         responsive: [  
                                       {
                                          breakpoint: 600,
                                          settings: {
                                            slidesToShow: 5                                            
                                          }
                                        }
                                      ]
                    });
                }                

                jQuery('#edit-ds-changed-datepicker-popup-0').datepicker({
                    dateFormat: 'dd-mm-yy',
                    changeMonth: true,
                    changeYear: true,
                    maxDate: -1,
                    onSelect: function (dateText, inst) {
                        urlpath = window.location.href;
                        url = urlpath.split("/");
                        console.log(url[3]);
                        console.log(url[4]);
                        var ctype = ["Story", "photogallery", "Videogallery"];
                        if(jQuery.inArray(url[4], ctype) != -1) {
                         var pathname = base_url + '/' + 'archives/' + url[4] + '/' + dateText;   
                        } else {
                          var pathname = base_url + '/' + 'archives/' + dateText;    
                        }
                        //jQuery('#edit-submit-archive-story').trigger('click');
                        window.location.href = pathname;
                    }
                });

            }
        }

    };
})(jQuery, Drupal, this, this.document);


function getParameterByName(name, url) {
    if (!url)
        url = window.location.href;
    name = name.replace(/[\[\]]/g, "\\$&");
    var regex = new RegExp("[?&]" + name + "(=([^&#]*)|&|#|$)"),
            results = regex.exec(url);
    if (!results)
        return null;
    if (!results[2])
        return '';
    return decodeURIComponent(results[2].replace(/\+/g, " "));
}

jQuery(document).ready(function(){
     //ON CLICK SHOW FILTER TYPES
    jQuery("body, html").find('.searh-all-filters').prepend('<div class="views-exposed-widget search-filter">Filters: </div>');
    jQuery("body, html").on("click", ".searh-all-filters label", function(){
      jQuery(".searh-all-filters .views-widget, .searh-all-filters .caln").hide();
      jQuery(this).next('div').show();    
    });
});