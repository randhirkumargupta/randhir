/*
 * @file itg_layout_manager.js
 * Contains all functionality related to layout manager
 */

(function($) {
    Drupal.behaviors.itg_layout = {
        attach: function(context, settings) {
            var layout_type = settings.itg_story.settings.layout_type;
            
            // after error display
            if ($('.messages--error').html() != null) {
                return false;
            }

            draggable_widgets();

            // code for layout setting save in db
            function draggable_widgets() {

                var widget_name = '';

                $(".templates-widgets li").draggable({
                    appendTo: "body",
                    helper: "clone",
                    drag: function(event, ui) {
                        widget_name = $(this).attr('data-widget');
                        
                        widget_info = $(this).attr('data-widget-info');
                        
                        // for category tab
                        category_name_tab = $(this).attr('id');
                        //alert(widget_name);
                    }
                });

                $(".droppable").droppable({
                    
                    hoverClass: "drop-hover",
                    drop: function(event, ui) {
                        
                        var ad_class = $(this).attr('class');

                        if (ad_class == 'sidebar-ad droppable ui-droppable') { // code change by avanish
                            alert("You can't drag any widget in this content area!");
                            return false;
                        }
                        //alert(widget_name);

                        
                        $(this).removeClass("gray-bg-layout");
                        // content block id for display content widget
                        var block_name = $(this).find('.data-holder').attr('id');
                        //  content block style for display content widget
                        var wid_name=widget_name;
                        var splitewidgitname=widget_name.split('#');
                        if(splitewidgitname[0]=='section_wise_order') {
                            var widget_style = $(this).find('.data-holder').attr('widget-style');
                            if(widget_style != "" && widget_style != "undefined") {
                               widget_info ='custom|'+widget_style;
                            }
                            else {
                              widget_info = 'custom|common-category-style';  
                            }
                            wid_name='section_wise_order';
                        }
                        //alert(block_name);
                        // tamplate section value
                        var section_name = $('#edit-section').val();
                        // template name
                        var template_name = $('#edit-template-name').val();

                        //if content place is define
                        var display_area = $(this).attr('data-tabwidget_display');
                        // for photo and video section
                        var ulId = $('li[data-widget="' + widget_name + '"]').closest('ul').attr('id');

                        if (display_area == 'region-section-content' && ulId != 'templates-widgets-section') {
                            alert("You can't drag this widget in this content area!");
                            return false;
                        }

                        

                        if (display_area) {
                            var content_place = display_area;
                        }
                        else {
                            var content_place = block_name;
                        }
                        
                        var base_url = settings.itg_story.settings.base_url;
                        $.ajax({
                            url: base_url + "/insert-layout-setting-ajax/layout",
                            method: 'post',
                            data: {block_name: block_name, widget_name: widget_name, section_name: section_name, template_name: template_name, layout_type:layout_type, block_title: category_name_tab, widget_info:widget_info},
                            beforeSend: function() {

                                $('#' + content_place).html('<div class="widget-loader-wrapper"><img class="widget-loader" align="center" src="' + Drupal.settings.basePath + '/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." /></div>');
                            },
                            success: function(data) {
                                      var splitewigitinfo= widget_info.split('|');
                                      if(splitewigitinfo[1] !="")
                                      {
                                         wid_name=wid_name+'-'+ splitewigitinfo[1];
                                      }
                                // for category tab widget
                                $('input[name = ' + block_name + ']').val(category_name_tab);
                                $('.widget-title[data-id="' + block_name + '"]').html(category_name_tab);
                                $('.tab-buttons span[data-class="' + block_name + '"]').html(category_name_tab);
                                if(wid_name=='sport_poll_widget_block'){
                                $('#' + block_name).closest('.widget-wrapper').attr('class', 'widget-wrapper ' + wid_name);
                            }
                        
                                //$('#block_name').html(category_name_tab);
                                if (display_area) {
                                    $('#' + block_name).html(category_name_tab);
                                }

                                $('#' + content_place).html(data);
                                //code by sunil
                                //console.log("here i am");
                                jQuery('#auto-new-block .widget-settings, #tech-new-block .widget-settings, #education-new-block .widget-settings, #movie-new-block .widget-settings').prependTo('.auto-block-2 .special-top-news');
                                //code by avanish
                              
                                if (widget_name == 'featured_photo_carousel' || splitewigitinfo[1]== 'block_5') {
                                    jQuery(".flexslider").flexslider({
                                        animation: "slide",
                                        prevText: "",
                                        nextText: "",
                                    });
                                }
                                jQuery('.year-slider').slick({
                                    slidesToShow: 1,
                                    slidesToScroll: 1,
                                    arrows: true,
                                    fade: false         
                                });  
                            }
                        });
                    }
                });
            }

            $('#layout-button-save').click(function() {

                var base_url = settings.itg_story.settings.base_url;
                var layout_type_url = settings.itg_story.settings.layout_type;
                var section_name = $('#edit-section').val();
                var template_name = $('#edit-template-name').val();

                $.ajax({
                    url: base_url + "/insert-layout-setting-ajax/publish",
                    method: 'post',
                    data: {status_val: 1, section_name: section_name, template_name: template_name, layout_type:layout_type},
                    beforeSend: function() {
                        $('.itg-ajax-loader').show();
                    },
                    success: function(data) {
                        if (section_name == 'home_page') {
                            var dis_url = "/itg-layout-manager/home?section=home_page&template_name=page--front";
                        } else {
                            var dis_url = "/itg-layout-list/"+layout_type_url;
                        }
                        window.location.href = base_url + dis_url;
                    }
                });
            });

            $('#layout-button-cancel').click(function() {
                var base_url = settings.itg_story.settings.base_url;
                var section_name = $('#edit-section').val();
                var template_name = $('#edit-template-name').val();
                $.ajax({
                    url: base_url + "/insert-layout-setting-ajax/delete",
                    method: 'post',
                    data: {status_val: 1, section_name: section_name, template_name: template_name, layout_type:layout_type},
                    beforeSend: function() {
                        $('.itg-ajax-loader').show();
                    },
                    success: function(data) {
                        if (section_name == 'home_page') {
                            var dis_url = "/itg-layout-manager/home?section=home_page&template_name=page--front";
                        } else {
                            var dis_url = "/itg-layout-list";
                        }
                        window.location.href = base_url + dis_url;
                    }
                });
            });


            $('.block_title_id').blur(function() {
                var block_id = $(this).attr("name");
                var section_name = $('#edit-section').val();
                var template_name = $('#edit-template-name').val();
                var block_title = $(this).val();
                // alert(block_id);
                var base_url = settings.itg_story.settings.base_url;

                /* var input_val = '';
                 $('#'+block_id).find("input[type='text']").each(function (index) {
                 //get value                    
                 input_val += $(this).val()+'@';                   
                 });*/

                $.ajax({
                    url: base_url + "/insert-layout-setting-ajax/title",
                    method: 'post',
                    data: {block_name: block_id, section_name: section_name, template_name: template_name, layout_type:layout_type, block_title: block_title},
                    beforeSend: function() {
                        $('.block_title_id').addClass('input-loader');
                    },
                    success: function(data) {
                        $('.block_title_id').removeClass('input-loader');
                    }
                });
            });
            // for section cards
            $('#layout-section-save').click(function() {
                var base_url = settings.itg_story.settings.base_url;
                // category value
                var category_name = $('#edit-section-name').val();
                // tamplate section value
                var section_name = $('#edit-section').val();
                // tamplate name
                var template_name = $('#edit-template-name').val();
                // widget name for content display
                var widgets_type = $(this).attr('data-tabwidget');

                if (category_name) {
                    $.ajax({
                        url: base_url + "/section-widgets-ajax/insert",
                        method: 'post',
                        data: {cid: 1, section_name: section_name, template_name: template_name, layout_type:layout_type, category_name: category_name, widgets_type: widgets_type},
                        beforeSend: function() {
                            $('#section_widgets_list').html('<img class="widget-loader" align="center" src="' + Drupal.settings.basePath + '/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />');
                        },
                        success: function(data) {
                            // display category list in block
                            $('#section_widgets_list').html(data);
                            draggable_widgets();
                        }
                    });
                }
            });

            // for section widgets

            $('#layout-section_widget2-save').click(function() {

                var base_url = settings.itg_story.settings.base_url;
                // category value
                var category_name = $('#edit-section-widget2-name').val();
                // tamplate section value
                var section_name = $('#edit-section').val();
                // tamplate name
                var template_name = $('#edit-template-name').val();
                // widget name for content display
                var widgets_type = $(this).attr('data-section-widget2');

                if (category_name) {
                    $.ajax({
                        url: base_url + "/section-widgets-ajax/insert",
                        method: 'post',
                        data: {cid: 1, section_name: section_name, template_name: template_name, layout_type:layout_type, category_name: category_name, widgets_type: widgets_type},
                        beforeSend: function() {
                            $('#section_widget2_list').html('<img class="widget-loader" align="center" src="' + Drupal.settings.basePath + '/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />');
                        },
                        success: function(data) {
                            // display category list in block
                            $('#section_widget2_list').html(data);
                            draggable_widgets();
                        }
                    });
                }
            });

            //code end for section_widget2

            // delete section cards
            $('body').on('click', '.layout-section-delete', function() {
                var base_url = settings.itg_story.settings.base_url;
                var widget_id = $(this).attr('data-widget');
                var section_name = $('#edit-section').val();
                var template_name = $('#edit-template-name').val();

                $.ajax({
                    url: base_url + "/section-widgets-ajax/delete",
                    method: 'post',
                    data: {id: widget_id, section_name: section_name, template_name: template_name, layout_type:layout_type },
                    beforeSend: function() {
                        $('#section_widgets_list').html('<img class="widget-loader" align="center" src="' + Drupal.settings.basePath + '/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />');
                    },
                    success: function(data) {
                        $('#section_widgets_list').html(data);
                        draggable_widgets();
                    }
                });
            });

            // delete section widgets
            $('body').on('click', '.layout-section-widget2-delete', function() {
                var base_url = settings.itg_story.settings.base_url;
                var widget_id = $(this).attr('data-widget');
                var section_name = $('#edit-section').val();
                var template_name = $('#edit-template-name').val();

                $.ajax({
                    url: base_url + "/section-widgets-ajax/delete",
                    method: 'post',
                    data: {id: widget_id, section_name: section_name, template_name: template_name, layout_type:layout_type },
                    beforeSend: function() {
                        $('#section_widget2_list').html('<img class="widget-loader" align="center" src="' + Drupal.settings.basePath + '/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />');
                    },
                    success: function(data) {
                        $('#section_widget2_list').html(data);
                        draggable_widgets();
                    }
                });
            });

            // add more section widgets

            $('.content-section-widget').click(function() {
                var widgets_id = $(this).attr('id');
                //alert(widgets_id);
                $('#content-section-widget-' + widgets_id).show();
                $('#' + widgets_id).hide();
                var newValue = parseInt(widgets_id) + 1;
                $('#' + newValue).show();
            })

            $('.delete-block-widget').click(function() {
                //return false;
                var block_id = $(this).attr("delete-block-id");
                var section_name = $('#edit-section').val();
                var template_name = $('#edit-template-name').val();

                var base_url = settings.itg_story.settings.base_url;

                $.ajax({
                    url: base_url + "/insert-layout-setting-ajax/widget_delete",
                    method: 'post',
                    data: {block_name: block_id, section_name: section_name, template_name: template_name, layout_type:layout_type},
                    beforeSend: function() {
                        $('#' + block_id).addClass('input-loader');
                    },
                    success: function(data) {
                        $('#' + block_id).html('');
                        jQuery('span[data-id="' + block_id + '"]').html('');
                        $('.block_id').removeClass('input-loader');
                    }
                });
            });
            jQuery('.removes-more-block').on('click', function() {
                jQuery(this).hide();
                
                jQuery(this).parent().parent('.itg-common-section').find('.delete-block-widget').each(function() {
                    var block_id = jQuery(this).attr("delete-block-id");
                    var section_name = jQuery('#edit-section').val();
                    var template_name = jQuery('#edit-template-name').val();

                    var base_url = settings.itg_story.settings.base_url;

                    jQuery.ajax({
                        url: base_url + "/insert-layout-setting-ajax/widget_delete",
                        method: 'post',
                        data: {block_name: block_id, section_name: section_name, template_name: template_name, layout_type:layout_type},
                        beforeSend: function() {
                            jQuery('#' + block_id).addClass('input-loader');
                        },
                        success: function(data) {
                            jQuery('#' + block_id).html('');
                            jQuery('span[data-id="' + block_id + '"]').html('');
                            jQuery('#' + block_id).removeClass('input-loader');
//                            $('body').$('.slider-container').slick({
//                              infinite: true,
//                              slidesToShow: 3,
//                              variableWidth: true,
//                              slidesToScroll: 1
//                            });
                        }
                    });
                })
                jQuery(this).parent().parent('.itg-common-section').slideUp( 1000);
                jQuery(this).parent().parent('.itg-common-section').prev('.itg-common-section').find('.add-more-block').show();
            });

            jQuery('.add-more-block').on('click', function() {
                jQuery(this).hide();
                jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').slideDown( 1000);
                jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').find('.removes-more-block').show();
                jQuery(this).parent().parent('.itg-common-section').next('.show-on-add').find('.add-more-block').show();
            if (jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').next('.itg-common-section').is(':visible')) {
                  jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').find('.add-more-block').hide();
                }
            });
            jQuery('.add-more-block').each(function() {

                if (jQuery(this).parent().parent('.itg-common-section').next('.itg-common-section').is(":visible")) {
                    jQuery(this).hide();
                }
            });
            // jquery code to add aajtak sliding slider
            $('.slider-container').slick({
              infinite: true,
              slidesToShow: 3,
              variableWidth: true,
              slidesToScroll: 1
            });
            // jquery code to add aajtak stack card slider
            function mobilecheck() {
              var check = false;
              (function(a) {
                if (/(android|ipad|playbook|silk|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i.test(a) || /1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i.test(a.substr(0, 4)))
                  check = true
              })(navigator.userAgent || navigator.vendor || window.opera);
              return check;
            }
            var clickeventtype = mobilecheck() ? 'touchstart' : 'click';
            krisna = new Stack(document.getElementById('stack-card'));
            // controls the click ring effect on the button
            var buttonClickCallback = function(bttn) {
              var bttn = bttn || this;
              bttn.setAttribute('data-state', 'unlocked');
            };
            document.querySelector('.button--accept[data-stack = stack-card]').addEventListener(clickeventtype, function() {
              krisna.accept(buttonClickCallback.bind(this));
            });
            document.querySelector('.button--reject[data-stack = stack-card]').addEventListener(clickeventtype, function() {
              krisna.reject(buttonClickCallback.bind(this));
            });
        }

    };
})(jQuery, Drupal, this, this.document);
