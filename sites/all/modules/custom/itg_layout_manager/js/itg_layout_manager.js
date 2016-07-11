/*
 * @file itg_layout_manager.js
 * Contains all functionality related to story
 */

(function($) {
        Drupal.behaviors.itg_layout = {
             attach: function(context, settings) {                  
                 
                // Code issue date exit or not.
                $('.block_title_id').blur(function() {
                    var block_id = $(this).parent().attr("id");
                    
                    var section_name = $('#edit-section').val();
                    var template_name = $('#edit-template-name').val();
                    
                    var input_val = '';
                    $('#'+block_id).find("input[type='text']").each(function (index) {
                        //get value                    
                        input_val += $(this).val()+'@';                   
                    });
                    
                    var base_url = settings.itg_story.settings.base_url;
                    
                    $.ajax({
                          url: base_url + "/insert-layout-setting-ajax",
                          method: 'post',
                          data: {input_data:input_val, block_name:block_id,section_name:section_name,template_name:template_name},
                          success: function(data) {                              
                             $('#'+block_id+'-display').html(data);  
                          }
                    });
                 });
                 
                 // Code issue date exit or not.
                $('#layout-button-save').click(function() {
                    var block_id = $(this).parent().attr("id");
                    
                    var section_name = $('#edit-section').val();
                    var template_name = $('#edit-template-name').val();
                    
                    var input_val = '';
                    $('#'+block_id+'-block').find("input[type='text']").each(function (index) {
                        //get value                    
                        input_val += $(this).val()+'@';                   
                    });
                    
                    var base_url = settings.itg_story.settings.base_url;
                    
                    $.ajax({
                          url: base_url + "/insert-layout-setting-ajax",
                          method: 'post',
                          data: {input_data:input_val, block_name:block_id,section_name:section_name,template_name:template_name},
                          success: function(data) {                              
                             $('#'+block_id+'-display').html(data);  
                          }
                    });
                 });
                                 
                $("#templates-widgets li").draggable({
                    appendTo: "body",
                    helper: "clone"
                });
                
                $(".droppable").droppable({
                    drop: function (event, ui) {
                        $(this)
                        .addClass("dropped")
                        .find("p")
                        .hide();
                    }
                });
            }   
            
 };
})(jQuery, Drupal, this, this.document);
