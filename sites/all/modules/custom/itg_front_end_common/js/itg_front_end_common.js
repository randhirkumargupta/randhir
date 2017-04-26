/*
 * @file itg_front_end_common.js
 * Contains all functionality related to Ads Management
 */

(function($) {
    Drupal.behaviors.itg_ads = {
        attach: function(context) {
         
        }
        
        

    };
})(jQuery, Drupal, this, this.document);

jQuery(document).ready(function(){
  var input_range = jQuery('#slider-range').val();
  jQuery("#slider-range").ionRangeSlider({
    min: 0,
    max: 1439,
    from: 0,
    step: 1,
    onStart: function(){
      setTimeout(function(){
        jQuery('.irs-slider.single').text("00:00 AM");
      }, 0);
    },
    onChange: timeline
  });
  
  function timeline(data) {
        var num = data.from;
        var hs = Math.floor(num / 60);
        var ms = num - (hs * 60);
        if (hs.length == 1){
          hs = '0' + hs;
        } 
        if (ms.length == 1){
          ms = '0' + ms;
        } 
        if (ms == 0) ms = '00';
        if (hs >= 12) {
          if (hs == 12) {
              hs = hs;
              ms = ms + " PM";
          } else {
              hs = hs;
              ms = ms + " PM";
          }
        } else {
          hs = hs;
          ms = ms + " AM";
        }
        if (hs == 0) {
          hs = '00';
          ms = ms;
        }
        jQuery('.irs-slider.single').text(hs + ":" + ms);
        jQuery('.breaking-section').each(function(){
          var breakingDate = jQuery(this).find('.breaking-date').text();
          var text_array = breakingDate.split(" ");
          var timeVal = text_array[0].split(":");
          var hs_to_num = parseInt(timeVal[0] * 60);
          var ms_to_num = parseInt(timeVal[1]);
          var totla_num = hs_to_num + ms_to_num;
          if(num > totla_num){
            jQuery(this).hide();
          }
          else{
            jQuery(this).show();
          }
        });
    }
  
//jQuery("#slider-range").slider({
//        range: true,
//        min: 0,
//        max: 1439,
//        values: [0, 1439],
//        slide: slideTime
//      });
//      function slideTime(event, ui){
//           
//        var val0 = jQuery("#slider-range").slider("values", 0),
//          val1 = jQuery("#slider-range").slider("values", 1),
//          minutes0 = parseInt(val0 % 60, 10),
//          hours0 = parseInt(val0 / 60 % 24, 10),
//          minutes1 = parseInt(val1 % 60, 10),
//          hours1 = parseInt(val1 / 60 % 24, 10);
//					
//        startTime = getTime(hours0, minutes0);
//        console.log(startTime);
//        endTime = getTime(hours1, minutes1);
//        
//        var sTimestamp = startTime.replace(":","");
//        var sTimestamp1 = jQuery.trim(sTimestamp.replace("AM",""));
//          //console.log(sTimestamp1);
//        var flag = 0;
//        var tcount;
//        if(sTimestamp1 !="000")
//        {
//        jQuery('.dwrap').each(function(){
//           tcount = $(this).attr('tcount');
//          if(parseInt(sTimestamp1)>= parseInt($(this).attr('timevalue')))
//          {
//            jQuery(this).show().removeClass('hide-div');
//            jQuery('.no-record').hide();
//            jQuery(this).parent().show();
//
//          }
//          else {
//            jQuery(this).hide().addClass('hide-div');
//            jQuery(this).parent().hide();
//          }
//          
//            if (jQuery(this).hasClass('hide-div'))
//            {
//                flag = flag + 1;
//
//            }
//         
//
//        })
//
//        if(tcount <= flag)
//        {
//          jQuery('.no-record').show();
//        }
//    }
//
//       // jQuery("#time").text(startTime + ' - ' + endTime);
//       jQuery('#slider-range a').first().text(startTime);
//       jQuery("#time").text(startTime);
//      }
      
//      function getTime(hours, minutes) {
//        var time = null;
//        minutes = minutes + "";
//        if (hours < 12) {
//          time = "AM";
//        }
//        else {
//          time = "PM";
//        }
//
//        if (minutes.length == 1) {
//          minutes = "0" + minutes;
//        }
//        return hours + ":" + minutes + " " + time;
//      }
//      slideTime();
      });