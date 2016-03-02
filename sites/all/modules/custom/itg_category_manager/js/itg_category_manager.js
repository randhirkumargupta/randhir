(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_category_manager = {
    attach: function (context, settings) {
      // Place your code here.
      var setting = Drupal.settings.baseUrl;
      // Term status mode show hide
      $('#edit-term-state').click(function () {
        var state = $(this).is(':checked');
        if (state) {
          $("#state-mode").css("display", "none");
        }
        else {
          $("#state-mode").css("display", "block");
        }
      });

      // Disable manual or forcefully
      $('#edit-state-mode-1, #edit-state-mode-0').click(function () {
        var state = $(this).is(':checked');
        var tid = $('input[name="term_tid"]').val();
        switch ($(this).val()) {
          case '0':            
            $.ajax({
              url: setting.baseUrl + "/category-management/disable-forcefully",
              type: 'post',
              data: {'tid': tid},
              dataType: "JSON",
              success: function (data) {                
                window.location = setting.baseUrl + "/category-manager";                
              }
            });
            break;
          case '1':            
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
      
      // Pager settings
      var monthNames = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
      var d = new Date();      
      var currentMonth = monthNames[d.getMonth()]+' '+d.getFullYear();
      var currentMonthPager = $(".date-heading h3").text();
      if (currentMonth === currentMonthPager) {        
        $(".date-next").css("display", "none");
      }
      
      // Check frequency and select range date.
      // Hide date range field from display      
      $('.field-name-field-astro-zodiac-sign-name').css('display', 'none');
      // Weekly
      $('#edit-field-astro-frequency-und-weekly').click(function() {        
        var state = $(this).is(':checked');
        if (state) {
          var startDay = moment().day(0); // Sun
          var endDay = moment().day(6); // Sat          
          $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(startDay.format('L'));
          $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val(endDay.format('L'));
          var titleText = startDay.format('MMM Do YYYY')+" - "+endDay.format('MMM Do YYYY');          
          $("#edit-title").val(titleText);
        }
      });
      // Monthly
      $('#edit-field-astro-frequency-und-monthly').click(function() {
        var state = $(this).is(':checked');
        if (state) {
          var firstDay = moment().date(1);
          var lastDay = moment().endOf('month');
          $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(firstDay.format('L'));
          $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val(lastDay.format('L'));
          var titleText = firstDay.format('MMM Do YYYY')+" - "+lastDay.format('MMM Do YYYY');          
          $("#edit-title").val(titleText);
        }
      });
      // Yearly
      $('#edit-field-astro-frequency-und-yearly').click(function() {
        var state = $(this).is(':checked');
        if (state) {
          var firstDay = moment().dayOfYear(1).format('L');          
          $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(firstDay);
          $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val('12/31/'+moment().year());
          var startYear = moment().format('MMM Do YYYY');
          var endyear = "Dec 31st "+moment().year();
          $("#edit-title").val(startYear + " - " + endyear);
        }
      });
    }
  };
})(jQuery, Drupal, this, this.document);
