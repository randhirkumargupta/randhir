/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */
Drupal.behaviors.itg_widgets = {
    attach: function (context, settings) {
        var base_url = settings.itg_widget.settings.base_url;
        jQuery("div.big-news-content-videogallery a.has-ajax-big-story").click(function () {
            jQuery('.big-story-col-1 .loading-popup').show();
            var nid = jQuery(this).attr("data-nid");
            jQuery.get("big-story-video-gallery/" + nid, function (data) {
                // add new data data.
                jQuery("#videogallery-iframe").html(data);
                videoGallery();
                jQuery("#videogallery-iframe").on('click', '#close-big-story', function () {
                    jQuery("#videogallery-iframe").html(" ");
                    jQuery("#videogallery-iframe").hide();
                });
            });
        });
        //Prevent stop video if it is palyed previously.
        jQuery('body').on('click', '.slick-track img', function (e) {
            jQuery(".iframe-video-dailymotion").each(function () {
                var url = jQuery(this).attr("src");
                jQuery(this).removeAttr("src");
                var Updatedurl = updateQueryStringParameter(url, 'autoplay', '0');
                jQuery(this).attr('src', Updatedurl);
            });
        });

        function updateQueryStringParameter(uri, key, value) {
            var re = new RegExp("([?&])" + key + "=.*?(&|$)", "i");
            var separator = uri.indexOf('?') !== -1 ? "&" : "?";
            if (uri.match(re)) {
                return uri.replace(re, '$1' + key + "=" + value + '$2');
            } else {
                return uri + separator + key + "=" + value;
            }
        }
        //common function for popup video
        function videoGallery() {
            jQuery("#videogallery-iframe").show();
            jQuery('.big-story-col-1 .loading-popup').hide();
            jQuery('.videogallery-slider').slick({
                slidesToShow: 1,
                slidesToScroll: 1, 
                prevArrow: '<i class="fa fa-chevron-left slick-prev" aria-hidden="true"></i>',
                nextArrow: '<i class="fa fa-chevron-right slick-next" aria-hidden="true"></i>',
                fade: false,
                asNavFor: '.video-slider-images ul'
            });
            jQuery('.video-slider-images ul').slick({
                slidesToShow: 7,
                slidesToScroll: 1,
                asNavFor: '.videogallery-slider',
                dots: false,
                centerMode: false,
                arrows: true,
                variableWidth: true,
                focusOnSelect: true,
                responsive: [
                    {
                        breakpoint: 1024,
                        settings: {
                            slidesToShow: 7,
                            slidesToScroll: 1,
                            arrows: false
                        }
                    },
                    {
                        breakpoint: 600,
                        settings: {
                            slidesToShow: 4,
                            arrows: false,
                            slidesToScroll: 1
                        }
                    },
                    {
                        breakpoint: 480,
                        settings: {
                            slidesToShow: 3,
                            arrows: false,
                            slidesToScroll: 1
                        }
                    }
                ]
            });
        }
        var videoIframe = jQuery(".story-associate-content #videogallery-iframe");
        var strImg = jQuery('.story-associate-content .stryimg');
        strImg.click(function () {
            videoIframe.show(1000, function () {
                var widgets_type = jQuery('.associate-content-block').attr('data-widget');
                var widgets_type_array = widgets_type.split("-");
                var widgets_type = widgets_type_array[0];
                var widgets_id = widgets_type_array[1];
                var imgurl = base_url + "/sites/all/themes/itg/images/reload.gif";
                videoIframe.append('<img class="loading-popup" src="' + imgurl + '" alt="loading image" />');
                jQuery.ajax({
                    url: Drupal.settings.basePath + "associate-photo-video-content/" + widgets_type + "/" + widgets_id,
                    method: 'post',
                    //data: {status_val: 1, section_name: section_name, template_name: template_name, layout_type:layout_type},
                    beforeSend: function () {
                        // $('.itg-ajax-loader').show();
                    },
                    success: function (data) {
                        videoIframe.html(data);
                        videoGallery();
                        videoIframe.css('height', 'auto');
                    }
                });
            });
            strImg.hide(1000);
        });

        videoIframe.on('click', '#close-big-story', function () {
            videoIframe.hide(1000, function () {
                videoIframe.empty();
                videoIframe.css('height', '340px');
            });
            strImg.show(1000);
        });

    //        var events = jQuery('#edit-actionitg-widget-categories-wise-node-group').data('events'); // Get the jQuery events.
    //        console.log(events);
    //jQuery('#edit-actionitg-widget-categories-wise-node-group').unbind('mousedown'); // Remove the click events.
    //        jQuery('#edit-actionitg-widget-categories-wise-node-group').mousedown(function() {
    //            if (confirm('Are you sure you want to delete that?')) {
    //                //jQuery("#views-form-section-wise-draggable-content-order-we-may-suggest-widget").submit();
    //                return true;
    //            }
    //            // Prevent default action.
    //            return false;
    //        });
    var videoIframe = jQuery (".story-associate-content #videogallery-iframe");
    var strImg = jQuery('.story-associate-content .stryimg');
        strImg.click(function(){
            videoIframe.show(1000, function(){             
            var widgets_type = jQuery('.associate-content-block').attr ('data-widget');              
            var widgets_type_array = widgets_type.split ("-");
            var widgets_type = widgets_type_array[0];
            var widgets_id = widgets_type_array[1];  
            var imgurl = base_url+"/sites/all/themes/itg/images/reload.gif";            
            videoIframe.append('<img class="loading-popup" src="'+imgurl+'" alt="loading image" />');      
                jQuery.ajax ({
                  url: Drupal.settings.basePath + "associate-photo-video-content/" + widgets_type + "/" + widgets_id,
                  method: 'post',
                  //data: {status_val: 1, section_name: section_name, template_name: template_name, layout_type:layout_type},
                  beforeSend: function () {
                    // $('.itg-ajax-loader').show();
                  },
                  success: function (data) {
                   videoIframe.html (data);
                   videoGallery ();
                    videoIframe.css('height', 'auto');
                  }
                });               
            });     
        strImg.hide(1000);                   
    });    
    
    videoIframe.on ('click', '#close-big-story', function () {                      
        videoIframe.hide(1000, function(){
            videoIframe.empty();
            videoIframe.css('height', '340px');
        });   
       strImg.show(1000);                                             
    });

    jQuery ('#edit-state1').change (function () {
      var getval = jQuery (this).val ();
      if (getval == 0)
      {
        getval = "";
      }
      jQuery ('#edit-state').val (getval);
    })
    jQuery ('#edit-cat1_id').change (function () {
      var getval = jQuery (this).val ();
      if (getval == 0)
      {
        getval = "";
      }
      jQuery ('#edit-cat_id').val (getval);
    })
// This code use for mark candidate status
        jQuery('.key-radio').live('click', function () {
            var getname = jQuery(this).attr('name');
            var getstatus = jQuery(this).val();
            jQuery.ajax({
                url: Drupal.settings.basePath + 'update-keycandidate-status',
                type: 'post',
                beforeSend: function () {
                    jQuery('#widget-ajex-loader').show();

                },
                data: {
                    'fname': getname,
                    'status': getstatus,
                },
                success: function (data) {

 jQuery('#widget-ajex-loader').hide();
                },
                error: function (xhr, desc, err) {
                    console.log(xhr);
                    console.log("Details: " + desc + "\nError:" + err);
                }
            });
        })
        jQuery(".remove_from_nodequeue_draggable_view").click(function () {
            var nid = jQuery(this).attr("data-nid");
            var qid = jQuery(this).attr("data-queueid");
            var view_name = jQuery(this).attr("data-view");
            var view_page = jQuery(this).attr("data-page");
            // get query parameter
            var c_tid = get_url_parameter('field_story_category_tid');
            var type = get_url_parameter('type');
            if (typeof (c_tid) != "undefined" && c_tid !== null && typeof (type) != "undefined" && type !== null) {
                if (confirm('Are you sure you want to move this content ?')) {
                    jQuery("#widget-ajex-loader").css("display", "block");
                    jQuery.get("remove_from_widgets_section/" + nid + "/" + qid + "/" + view_name + "/" + view_page + "/" + c_tid + "/" + type, function (data, status) {
                        if (data == 'deleted') {
                            //window.location.reload();
                        }
                    });
                }
                console.log("section and type found");
            } else {
                if (confirm('Are you sure you want to move this content ?')) {
                    jQuery("#widget-ajex-loader").css("display", "block");
                    jQuery.get("remove_from_widgets/" + nid + "/" + qid + "/" + view_name + "/" + view_page, function (data, status) {

                        if (data == 'deleted') {
                            window.location.reload();

                        }
                        window.location.reload();
                    });
                }
            }
        });

        jQuery(".add-so-sorry-extra-data").click(function () {
            var extra_type = jQuery(this).val();
            var nid = jQuery(this).attr('data-nid');
            window.location.replace("add-so-sorry-extra-data/" + nid + "/" + extra_type);
            jQuery("#widget-ajex-loader").css("display", "block");
        });

        jQuery(".remove-so-sorry-extra-data").click(function () {
            jQuery("#widget-ajex-loader").css("display", "block");
        });

        jQuery(".widgets-view .view-link").parent().attr("target", "_blank");
        //jQuery(".widgets-view .view-link").css("text-transform","capitalize");

        jQuery(".view-section-wise-content-ordering-list span.move-link").on('click', function () {
            if (confirm("Are you sure you want to remove this content ?")) {
                return true;
            } else {
                return false;
            }
        });

        jQuery(".view-display-id-poll_widget_list span.move-link").on('click', function () {
            if (confirm("Are you sure you want to remove this content ?")) {
                return true;
            } else {
                return false;
            }
        });

    }

};

var get_url_parameter = function get_url_parameter(sParam) {
    var sPageURL = decodeURIComponent(window.location.search.substring(1)),
            sURLVariables = sPageURL.split('&'),
            sParameterName,
            i;
    for (i = 0; i < sURLVariables.length; i++) {
        sParameterName = sURLVariables[i].split('=');

        if (sParameterName[0] === sParam) {
            return sParameterName[1] === undefined ? true : sParameterName[1];
        }
    }
};


jQuery(document).ready(function () {
    jQuery('.cat-wraper').html(jQuery('.form-item-cat1-id').html());
    jQuery('.state-wraper').html(jQuery('.form-item-state1').html());
    jQuery('.form-item-cat1-id').remove();
    jQuery('.form-item-state1').remove();
    jQuery('#edit-cat1-id').attr('name', 'cat_id');
    jQuery('#edit-state1').attr('name', 'state');
    jQuery(".custom-weight-draggable input[type=number]").change(function () {
        jQuery(this).next().children().find('option').remove().end().append('<option value="' + jQuery(this).val() + '">' + jQuery(this).val() + '</option>').val(jQuery(this).val());
    });
    jQuery("select#fake-soruce-type").on("change", function () {
        var soruce_type = jQuery(this).val();
        jQuery("#edit-field-story-source-type-value").val(soruce_type);
    });

    jQuery('#views-exposed-form-most-read-widget-most-read-widget-contents #edit-category-tid > option[value=All]').html("- Any -");
    jQuery('#views-exposed-form-most-read-widget-most-read-widget-list #edit-category-tid > option[value=All]').html("- Any -");
    jQuery('#views-exposed-form-special-how-i-made-it-special-how-made-it-widget-contents #edit-category-tid > option[value=All]').html("- Any -");
    jQuery('#views-exposed-form-special-how-i-made-it-special-how-made-widget-list #edit-category-tid > option[value=All]').html("- Any -");
    // Handel colorbox for custom widget.
    jQuery("#create-view-custom-widget").on("click", function (e) {
        e.preventDefault();
        jQuery("#cboxOverlay").html("..");
        jQuery.colorbox({
            href: "itg-custom-widget-content?widget_name_delete",
            width: "900", height: "600",
            iframe: true,
            overlayClose: false,
            onClosed: function () {
                jQuery("#widget-ajex-loader").show();
                location.reload(true);
            }
        });
    });
});

jQuery(".delete-link-anchor").click(function () {
    if (confirm("Are you sure want to delete this content.")) {
        jQuery("#widget-ajex-loader").show();
    } else {
        return false;
    }
});

jQuery("#edit-widget-name").on("keyup", function () {
    var widget_name = jQuery(this).val();
    if (widget_name.length > 0) {
        jQuery.ajax({
            url: "custom_widget_name_list/" + jQuery(this).val(),
            success: function (data) {
                console.log(data);
                if(data != null) {
                    jQuery(".error-message-widget").remove();
                    jQuery(".form-item-widget-name").append("<div class='messages error error-message-widget'><ul><li>Widget <b>"+widget_name+"</b> already exists in database. Please change it or new content will add in <b>"+widget_name+"</b> widget..</li></ul></div>");
                }
                else {
                    jQuery(".error-message-widget").remove();
                }
            }
        });
    }
});

jQuery(document).ajaxSuccess(function () {
    var forms = [
        'views-exposed-form-story-widget-page-1'
                , 'views-exposed-form-story-widget-top-takes-video'
                , 'views-exposed-form-story-widget-trending-videos'
                , 'views-exposed-form-story-widget-watch-right-now'
                , 'views-exposed-form-highlights-widget-highlights-widget-conent'
                , 'views-exposed-form-photo-carousel-widget-photo-carousel-list'
                , 'views-exposed-form-photo-carousel-widget-video-carousel-list'
                , 'views-exposed-form-home-page-feature-widget-page-1'
                , 'views-exposed-form-section-wise-draggable-content-order-dont-miss-content'
                , 'views-exposed-form-section-wise-draggable-content-order-we-may-suggest-widget'
                , 'views-exposed-form-most-read-widget-most-read-widget-contents'
    ];
    for (i = 0; i < forms.length; i++) {
        jQuery('#' + forms[i] + ' #edit-field-story-category-tid-select-1 > option[value=0]').html("- Any -");
        jQuery('#' + forms[i] + ' #edit-shs-term-node-tid-depth-select-1 > option[value=0]').html("- Any -");
        jQuery('#' + forms[i] + ' #edit-category-tid-select-1 > option[value=0]').html("- Any -");
    }
});
