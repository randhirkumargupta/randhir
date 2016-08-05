(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_category_manager = {
    attach: function (context, settings) {
      // Place your code here.
      var setting = Drupal.settings.baseUrl;
      // Show loader image
      $('.term-spinner').hide();
      function showLoadingImage() {
        $('.term-spinner').show();
      }
      
      // Hide loader image
      function hideLodingImage() {
        $('.term-spinner').hide();
      }

      // Disable manual or forcefully
      $('#edit-state-mode-1, #edit-state-mode-0').click(function () {
        var state = $(this).is(':checked');
        var tid = $('input[name="term_tid"]').val();
        switch ($(this).val()) {
          case '0':
            showLoadingImage();
            $.ajax({
              url: setting.baseUrl + "/category-management/disable-forcefully",
              type: 'post',
              data: {'tid': tid},
              dataType: "JSON",
              success: function (data) {                
                window.location = setting.baseUrl + "/category-manager-listing";                
              },
              complete: function () {
                hideLoadingImage();
              }
            });
            break;
          case '1': 
            showLoadingImage();
            window.location = setting.baseUrl + "/category-management/disable-manually/"+tid;
        }
      });

      // Ajax callback to check number of node associated with term.
      $('#show-content-count').on('click', function () {
        var tid = $('.tid').text();
        //Call Ajax
        $.ajax({
          url: setting.baseUrl + "/content-associated",
          type: 'post',
          data: {'tid': tid},
          dataType: "JSON",
          success: function (data) {
            $('span.count').html(' : ' + data);
          }
        });
      });
      $('.hierarchical-select select').on('change',function(){
          if($(this).val()!=0)
          {
              $('#edit-field-cm-select-type-und').attr('disabled',true);
          }else{
            $('#edit-field-cm-select-type-und').attr('disabled',false);

          }
      })
      
      // Pager settings
      var monthNames = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
      var d = new Date();      
      var currentMonth = monthNames[d.getMonth()]+' '+d.getFullYear();
      var currentMonthPager = $(".date-heading h3").text();
      if (currentMonth === currentMonthPager) {        
        $(".date-next").css("display", "none");
      }     
    }
  };
})(jQuery, Drupal, this, this.document);
