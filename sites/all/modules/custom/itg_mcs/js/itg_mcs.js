
 /**
 * @file
 * Custom behaviors for Multiple Category select.
 */
(function ($) {

  Drupal.behaviors.itgMCS = {

    // Default function to attach the behavior.
    attach: function (context, settings) {

    // hide main select category list
    //$('#edit-field-story-category').hide();    

     var checkForm = 'add';
     // check for is edit   
     if ($( "body" ).hasClass('page-node-edit') == true) {
       var checkForm = 'edit';
     }
   
    
      // Click action
      $(document).on( 'click', '.itg-category', function( e ) {
        var selectCategory = $(this).val();
        
        var selectCategoryArray = new Array;

        var get_id = $(this).attr("id");
        var getdepth = get_id.split("-");
        var currentDepth = parseInt(getdepth[1]) + 1;

        if (checkForm == 'add') {
          $("#category-wrapper-"+currentDepth).nextAll('div[id^="category-wrapper"]').remove();
        }
       
       if (selectCategory != ''){
   
         // First, remove all selected options
         $('.form-item-field-story-category-und .form-select option').removeAttr('selected');

         var preSelectedCategoryArray = new Array;
         // Find pre selected options
         var wrapperID = 0;
         $('select[id^="itgcategory"]').each(function () {
           $('#itgcategory-'+wrapperID+' option:selected').each(function () {
             preSelectedCategoryArray.push($(this).val());
             getpreSelectedUniqueArray = $.unique(preSelectedCategoryArray);
             
             var optionSelected = $(this).val();
             // $(".form-item-field-story-category-und .form-select option[value="+optSelected+"]").attr("selected","selected");
             $("#itgcategory-"+wrapperID+" option[value="+optionSelected+"]").attr("selected","selected");
            
           });
           wrapperID++;
         });
        
          // Push cuurent selected category
          selectCategoryArray.push(selectCategory);
          getUniqueCategoryArray = $.unique(selectCategoryArray);

          var base_path = Drupal.settings.basePath;
          var request_url = base_path+"itg-category";
            
          $.ajax({
            type: 'POST',
            dataType : "html",
            url: request_url,
            data: {
                currentSelectedValue : getUniqueCategoryArray,
                preSelectedValue : getpreSelectedUniqueArray,
                checkEdit : checkForm
              },

            success: function(html) {
              if (html) {
       
                 var newDepth = currentDepth+1;
                 $("#category-wrapper-"+currentDepth).html(html);
                 var numOfSelectDiv = $("#category-wrapper-"+newDepth).length;
                 if (checkForm == 'add' && numOfSelectDiv == 0) {
                    $('<div id ="category-wrapper-'+newDepth+'"></div>').insertAfter("#category-wrapper-"+currentDepth);
                 }
                 else {
                    $("#category-wrapper-"+currentDepth).nextAll('div[id^="category-wrapper"]').remove();
                 }

                // Set selected options
                var categoryWrapperID = 0;
                 $('select[id^="itgcategory"]').each(function () {
                   $('#itgcategory-'+categoryWrapperID+' option:selected').each(function () {
                     
                     var optionsSelected = $(this).val();
                     $(".form-item-field-story-category-und .form-select option[value="+optionsSelected+"]").attr("selected","selected");
                     
                     $("#itgcategory-"+categoryWrapperID+" option[value="+optionsSelected+"]").attr("selected","selected");
                    
                   });
                   categoryWrapperID++;
                 });
         
              }
            } // end success
          });
        
        } // end if
      }); // end click fun

    }
  }
  
})(jQuery);
