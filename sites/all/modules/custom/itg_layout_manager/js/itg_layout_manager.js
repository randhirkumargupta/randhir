/*
 * @file itg_layout_manager.js
 * Contains all functionality related to layout manager
 */

(function($) {
        Drupal.behaviors.itg_layout = {
             attach: function(context, settings) {                 
                // $('.block_title_id').hide(); 
                // code for layout setting save in db
                
                var widget_name = '';
                
                $("#templates-widgets li").draggable({
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
                              success: function(data) {                              
                                 $('#'+block_name).html(data);  
                              }
                        });
                    }
                });                
               
               $('#layout-button-save').click(function() {
                    var base_url = settings.itg_story.settings.base_url;
                    var section_name = $('#edit-section').val();
                    var template_name = $('#edit-template-name').val();
                    $.ajax({
                          url: base_url + "/insert-layout-setting-ajax/publish",
                          method: 'post',
                          data: {status_val:1, section_name:section_name, template_name:template_name},
                          success: function(data) {                              
                             
                          }
                    });
               });
               
               
               $('.block_title_id').blur(function() {
                    var block_id = $(this).attr("name");                    
                    var section_name = $('#edit-section').val();
                    var template_name = $('#edit-template-name').val();
                    var block_title = $(this).val();
                    
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
                          success: function(data) {                              
                              
                          }
                    });
                 });
            }   
            
 };
})(jQuery, Drupal, this, this.document);
