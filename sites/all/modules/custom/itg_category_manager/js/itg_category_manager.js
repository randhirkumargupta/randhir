(function($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_category_manager = {
    attach: function(context, settings) {
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

      if (jQuery('#edit-parent-hierarchical-select-selects-0').val() != '0')
      {
        jQuery('#edit-field-set-as-featured-cate').hide();
      }


      // Disable manual or forcefully
      $('#edit-state-mode-1, #edit-state-mode-0').click(function() {
        var state = $(this).is(':checked');
        var tid = $('input[name="term_tid"]').val();
        switch ($(this).val()) {
          case '0':
            $.ajax({
              url: setting.baseUrl + "/category-management/disable-forcefully",
              type: 'post',
              data: {'tid': tid},
              dataType: "JSON",
              beforeSend: function(xhr) {
                showLoadingImage();
              },
              success: function(data) {
                window.location = setting.baseUrl + "/category-manager-listing";
              }
            });
            break;
          case '1':
            showLoadingImage();
            window.location = setting.baseUrl + "/category-management/disable-manually/" + tid;
        }
      });

      // Ajax callback to check number of node associated with term.
      $('#show-content-count').on('click', function() {
        var tid = $('.tid').text();
        //Call Ajax
        $.ajax({
          url: setting.baseUrl + "/content-associated",
          type: 'post',
          data: {'tid': tid},
          dataType: "JSON",
          success: function(data) {
            $('span.count').html(' : ' + data);
          }
        });
      });
      $('.hierarchical-select select').on('change', function() {
        if ($(this).val() != 0)
        {
          $('#edit-field-set-as-featured-cate-und-yes').prop('checked', false);
          $('#edit-field-set-as-featured-cate').hide();
          $('#edit-field-cm-select-type-und').attr('disabled', true);
          $('#edit-field-cm-select-type-und').removeAttr('required');
        } else {
          jQuery('#edit-field-set-as-featured-cate').show();
          $('#edit-field-cm-select-type-und').attr('disabled', false);
          $('#edit-field-cm-select-type-und').attr('required', 'required');

        }
      })


      var getthisvalue = $('select[name="parent[hierarchical_select][selects][0]"]').val();

      if (getthisvalue != "" && getthisvalue != 'undefined') {
        $.ajax({
          url: Drupal.settings.basePath + 'getsection_content',
          type: 'post',
          data: {'getthisvalue': getthisvalue},
          success: function(data) {
            var myArr = $.parseJSON(data);
            $("#edit-field-cm-select-type-und > option").each(function() {
              var thisvalue = $(this).val();
              var inarray_data = $.inArray(thisvalue, myArr);
              if (inarray_data >= 0) {
                $(this).attr("selected", "selected");
              }
            });
          },
          error: function(xhr, desc, err) {
            console.log(xhr);
            console.log("Details: " + desc + "\nError:" + err);
          }
        });
      }


      $('select[name="parent[hierarchical_select][selects][0]"]').on('change', function() {

        $("#edit-field-cm-select-type-und > option").each(function() {

          $(this).removeAttr("selected");

        });
        var getthisvalue = $(this).val();

        if (getthisvalue != "" && getthisvalue != 'undefined') {
          $.ajax({
            url: Drupal.settings.basePath + 'getsection_content',
            type: 'post',
            data: {'getthisvalue': getthisvalue},
            success: function(data) {
              var myArr = $.parseJSON(data);
              $("#edit-field-cm-select-type-und > option").each(function() {
                var thisvalue = $(this).val();
                var inarray_data = $.inArray(thisvalue, myArr);
                if (inarray_data >= 0) {
                  $(this).attr("selected", "selected");
                }
              });
            },
            error: function(xhr, desc, err) {
              console.log(xhr);
              console.log("Details: " + desc + "\nError:" + err);
            }
          });
        }

      })
      var getdec = jQuery('.text-format-wrapper').html();
      getdec = '<div class="text-format-wrapper" >' + getdec + '</div>';
      var getsechedulehtml = jQuery('#edit-field-user-name').html();
      getsechedulehtml = getdec + '<div class="field-type-text field-name-field-user-name field-widget-text-textfield form-wrapper" id="edit-field-user-name">' + getsechedulehtml + '</div>';
      jQuery('#edit-field-user-name').remove();
      jQuery('.text-format-wrapper').remove();
      jQuery("#edit-field-user-city").after(getsechedulehtml);

      // jQuery('.setting-div').prepend(getsechedulehtml);

      //jQuery('.setting-div').prepend(getsechedulehtml);
      // Pager settings
      var monthNames = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
      var d = new Date();
      var currentMonth = monthNames[d.getMonth()] + ' ' + d.getFullYear();
      var currentMonthPager = $(".date-heading h3").text();
      if (currentMonth === currentMonthPager) {
        $(".date-next").css("display", "none");
      }
    }
  };
})(jQuery, Drupal, this, this.document);
