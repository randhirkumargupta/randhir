/*
 * @file itg_event_registration.js
 */

(function($) {
  Drupal.behaviors.itg_event_registration = {
    attach: function(context, settings) {

      //Hide left side vertical tabs in case of simple users
      var uid = settings.itg_event_registration.settings.uid;
      var nid = settings.itg_event_registration.settings.nid;
      $('#edit-title').val('event-' + nid);
      $('.form-item-title').hide();

      if (uid != 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
        $("#edit-field-story-source-id").hide();
      }

      //Hide skip button
      $('#edit-skip').hide();
      $('#edit-skip-1').hide();

      if (nid == '' || nid == null) {
        $('input[name="field_erf_registration_und_0_remove_button"]').hide();
        $('#edit-field-erf-registration-fee-und-0-remove-button').hide();
      }

      $("#edit-field-erf-registration-fee-und-0-remove-button").hide();

      for (var i = 0; i < 10; i++) {
        //Only Aplphabetic numbers are allowed for state and city
        $('#edit-field-erf-registration-fee-und-' + i + '-field-erf-name-und-0-value, #edit-field-erf-registration-fee-und-' + i + '-field-erf-state-und-0-value, #edit-field-erf-registration-fee-und-' + i + '-field-erf-city-und-0-value').keyup(function() {
          this.value = this.value.replace(/[^a-zA-Z\s.]/g, '');
        });

        //Only Numeric values are allowed for mobile and pincode
        $('#edit-field-erf-registration-fee-und-' + i + '-field-erf-mobile-und-0-value, #edit-field-erf-registration-fee-und-' + i + '-field-erf-postal-code-und-0-value').keyup(function() {
          this.value = this.value.replace(/[^0-9]/g, '');
        });
      }

      $('.form-field-name-field-erf-registration-fee').on('click', 'legend', function() {
        $(this).next('.fieldset-wrapper').stop().slideToggle();
      });

    }
  };
})(jQuery, Drupal, this, this.document);

jQuery(document).ready(function() {
  var offset = jQuery('.form-field-name-field-erf-payment-gateway').offset();
  //event regestration
  jQuery('.event-form-add').click(function() {
    jQuery('html, body').animate({
      scrollTop: offset.top - 200
    }, 'slow');
    var $eventNum = jQuery(".event-form-number");
    var a = $eventNum.val();
    a++;
    $eventNum.val(a);
    jQuery(".field-add-more-submit").trigger("mousedown");
  });

  jQuery('.event-form-remove').click(function() {
    var $eventNum = jQuery(".event-form-number");
    var b = $eventNum.val();
    console.log(b);
    if (b > 1) {
      jQuery("table.field-multiple-table tr td:last").prev().find(".cancel.form-submit").trigger("mousedown");
      jQuery('html, body').animate({
        scrollTop: offset.top - 200
      }, 'slow');
      jQuery("table.field-multiple-table tr").eq(b).remove();
      b--;
      $eventNum.val(b);
    }
    priceCalc();
    var totalMember = jQuery('.event-total-fees-text .event-number-of-members');
    var a = $eventNum.val();
    totalMember.html(a);
  });

  var priceCalc = function() {
    var memberPrice = 0;
    jQuery('.form-radio').each(function() {
      if (jQuery(this).is(':checked'))
      {
        memberPrice = parseInt(memberPrice) + parseInt(jQuery(this).val());
      }
    });
    var $total = jQuery('#edit-total-fees-container .event-fees-amount');
    $total.html("Rs " + memberPrice);
    jQuery('input[name="total_value"]').val(memberPrice);  // Adding total value for coupons handling and payment
    jQuery('input[name="discounted_value"]').val(memberPrice); // Adding total value for coupons handling and payment
  }

  jQuery(document).on('change', 'input[type="radio"]', function() {
    var $eventNum = jQuery(".event-form-number");
    var totalMember = jQuery('.event-total-fees-text .event-number-of-members');
    var a = $eventNum.val();
    totalMember.html(a);
    priceCalc();
  });


  jQuery(document).on('click', '.event-registration-form-header', function() {
    jQuery('.event-registration-form-header').removeClass('.event-registration-header-open');
    var nextContent = jQuery(this).next('.event-registration-form-content');
    if (nextContent.is(":visible")) {
      nextContent.stop().slideUp();
      jQuery(this).addClass('event-registration-header-close');
      jQuery(this).removeClass('event-registration-header-open');
    } else {
      nextContent.stop().slideDown();
      jQuery(this).addClass('event-registration-header-open');
      jQuery(this).removeClass('event-registration-header-close');
    }

  });



  // Code start for Coupon code  

  jQuery('#event-registration-node-form .have-a-coupon-code-link').click(function() {

    if (jQuery('#edit-coupon-code').val().length <= 0) {
      jQuery('.coupon_code_message').html('<span class="error" style="display: block;">Coupon code field is required.</span>');
    } else {

      var payment_mode = jQuery('[name="field_erf_payment_gateway[und]"]').val();
      var total_fee = jQuery('input[name="total_value"]').val();
      var coupon_code = jQuery('input[name="coupon_code"]').val();
      var c_mobile = jQuery('input[name="field_erf_registration_fee[und][0][field_erf_mobile][und][0][value]"]').val();
      var c_email = jQuery('input[name="field_erf_registration_fee[und][0][field_erf_email][und][0][value]"]').val();

      var itg_coupons_vals = {payment_mode: payment_mode, total_fee: total_fee, coupon_code: coupon_code, c_mobile: c_mobile, c_email: c_email};

      var savecoupon_data = jQuery.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + "itg-event-coupon-check-auth",
        data: itg_coupons_vals,
        dataType: "text",
        success: function(resultData) {
          console.log(resultData);
          var obj_success = jQuery.parseJSON(resultData);
          if (obj_success['success'] == 0) {
            jQuery('.coupon_code_message').html('<span class="error" style="display: block;">' + obj_success['success_message'] + '</span>');
          }
          if (obj_success['success'] == 1) {
            jQuery('.event-fees-amount').html('Rs ' + obj_success['discounted_value']);
            jQuery('[name="discounted_value"]').val(obj_success['discounted_value']);
            jQuery('.coupon_code_message').html('<span class="success" style="display: block;">' + obj_success['success_message'] + '</span>');
            jQuery('[name="coupon_code"]').attr('readonly', true);
          }
        }
      });


    }


  });


  // Code End for Coupon code  


  // Code start for coupon reset
  
  jQuery('#event-registration-node-form .event-coupon-reset').click(function() {
    if (jQuery('#edit-coupon-code').val().length <= 0) {
      jQuery('.coupon_code_message').html('<span class="error" style="display: block;">Coupon code field is required.</span>');
    } else {
      jQuery('input[name="coupon_code"]').val('');
      jQuery('input[name="discounted_value"]').val(jQuery('input[name="total_value"]').val());
      jQuery('.event-fees-amount').html('Rs ' + jQuery('input[name="total_value"]').val());
      jQuery('[name="coupon_code"]').attr('readonly', false);
      jQuery('.coupon_code_message').html('');
    }

  });

  // Code end for coupon reset

  jQuery('#event-registration-node-form #edit-coupon-code').on('keyup keypress blur change', function(e) {
    if (jQuery('#edit-coupon-code').val().length <= 0) {

      jQuery('.coupon_code_message').html('<span class="error" style="display: block;">Coupon code field is required.</span>');
    } else {

      if (jQuery('.coupon_code_message').find('span').attr('class') == 'success') {

      } else {
        jQuery('.coupon_code_message').html('');
      }
    }
  });


  // End code for Coupon Code


});

//jQuery(document).ready(function(){
//    jQuery('.field-name-field-erf-ticket-type .form-radio').click(function(){
//        var val = jQuery(this).val();
//        var base_url = Drupal.settings.baseUrl.baseUrl;
//        jQuery.ajax({
//        type: 'POST',
//        url: base_url + "/itg_reg_group_msg",
//        data: {'case': val},
//        success: function(resultData) {
//            alert(resultData);
//            jQuery('.group-price-msg').show();
//            jQuery('.group-price-msg').text(resultData);
//        }
//     });
// });
//});