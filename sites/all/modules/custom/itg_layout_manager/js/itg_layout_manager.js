/*
 * @file itg_layout_manager.js
 * Contains all functionality related to layout manager
 */

(function($) {
        Drupal.behaviors.itg_layout = {
             attach: function(context, settings) {
                 
                draggable_widgets();
                
                // code for layout setting save in db
                function draggable_widgets() {
                    
                var widget_name = '';
                
                $(".templates-widgets li").draggable({
                    appendTo: "body",
                    helper: "clone",
                    drag: function (event, ui) {                       
                        widget_name = $(this).attr('data-widget');                    
                    }
                });
                
                $(".droppable").droppable({
                    drop: function (event, ui) {
                        
                        $(this).addClass("dropped").find("p").hide();
                
                        var block_name = $(this).attr('id');
                        var section_name = $('#edit-section').val();
                        var template_name = $('#edit-template-name').val();

                        var base_url = settings.itg_story.settings.base_url;

                        $.ajax({
                              url: base_url + "/insert-layout-setting-ajax/layout",
                              method: 'post',
                              data: {block_name:block_name, widget_name:widget_name, section_name:section_name, template_name:template_name}, 
                              beforeSend:function(){
                                $('#'+block_name).html('<img class="widget-loader" align="center" src="'+Drupal.settings.basePath+'/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />');                                
                              },
                              success: function(data) {
                                 $('#'+block_name).html(data);  
                              }
                        });
                    }
                });
                }                
               
               $('#layout-button-save').click(function() {
                    var base_url = settings.itg_story.settings.base_url;
                    var section_name = $('#edit-section').val();
                    var template_name = $('#edit-template-name').val();
                    $.ajax({
                          url: base_url + "/insert-layout-setting-ajax/publish",
                          method: 'post',
                          data: {status_val:1, section_name:section_name, template_name:template_name},
                          beforeSend:function(){                                
                            $('.itg-ajax-loader').show();
                          },
                          success: function(data) {
                            window.location.href = base_url + "/itg-layout-manager/home?section=home_page&template_name=page--front";                            
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
                          data: {status_val:1, section_name:section_name, template_name:template_name},
                          beforeSend:function(){                                
                            $('.itg-ajax-loader').show();
                          },
                          success: function(data) {                              
                            window.location.href = base_url + "/itg-layout-manager/home?section=home_page&template_name=page--front"; 
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
                          data: {block_name:block_id,section_name:section_name,template_name:template_name, block_title:block_title},
                          beforeSend:function(){
                              $('.block_title_id').addClass('input-loader');                             
                          },
                          success: function(data) {                              
                            $('.block_title_id').removeClass('input-loader');  
                          }
                    });
                 });
                 
                 $('#layout-section-save').click(function() {
                    var base_url = settings.itg_story.settings.base_url;
                    var category_name = $('#edit-section-name').val();
                    var section_name = $('#edit-section').val();
                    var template_name = $('#edit-template-name').val();
                    if (category_name) {
                        $.ajax({
                              url: base_url + "/section-widgets-ajax/insert",
                              method: 'post',
                              data: {cid:1, section_name:section_name, template_name:template_name, category_name:category_name},
                              beforeSend:function(){                                
                                $('#section_widgets_list').html('<img class="widget-loader" align="center" src="'+Drupal.settings.basePath+'/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />');
                              },
                              success: function(data) {
                                 $('#section_widgets_list').html(data);
                                 draggable_widgets();
                              }
                        });
                    }
                });
                
                $('body').on('click', '.layout-section-delete', function() {
                    var base_url = settings.itg_story.settings.base_url;
                    var widget_id = $(this).attr('data-widget');
                    var section_name = $('#edit-section').val();
                    var template_name = $('#edit-template-name').val();
                    
                    $.ajax({
                          url: base_url + "/section-widgets-ajax/delete",
                          method: 'post',
                          data: {id:widget_id, section_name:section_name, template_name:template_name,},
                          beforeSend:function(){                                
                            $('#section_widgets_list').html('<img class="widget-loader" align="center" src="'+Drupal.settings.basePath+'/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." />');
                          },
                          success: function(data) {
                             $('#section_widgets_list').html(data);
                             draggable_widgets();
                          }
                    });
                });
                
            }   
            
 };
})(jQuery, Drupal, this, this.document);
