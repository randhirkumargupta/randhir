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
jQuery("#slider-range").slider({
        range: true,
        min: 0,
        max: 1439,
        values: [0, 1439],
        slide: slideTime
      });
      function slideTime(event, ui){
                           
        var val0 = jQuery("#slider-range").slider("values", 0),
          val1 = jQuery("#slider-range").slider("values", 1),
          minutes0 = parseInt(val0 % 60, 10),
          hours0 = parseInt(val0 / 60 % 24, 10),
          minutes1 = parseInt(val1 % 60, 10),
          hours1 = parseInt(val1 / 60 % 24, 10);
					
        startTime = getTime(hours0, minutes0);
        console.log(startTime);
        endTime = getTime(hours1, minutes1);
        
        var sTimestamp = startTime.replace(":","");
        var sTimestamp1 = jQuery.trim(sTimestamp.replace("AM",""));
          //console.log(sTimestamp1);
        var flag=1;
        jQuery('.dwrap').each(function(){
          //console.log(parseInt($(this).attr('timevalue')))
          if(parseInt(sTimestamp1)< parseInt($(this).attr('timevalue')))
          {
            jQuery(this).show().removeClass('hide-div');
            jQuery('.no-record').hide();

          }else{
            jQuery(this).hide().addClass('hide-div');
          }
          if(!jQuery(this).hasClass('hide-div'))
          {
            flag=0;

          }
          else
          {
            flag = 1;
          }

        })

        if(flag==1)
        {
          jQuery('.no-record').show();
        }

        jQuery("#time").text(startTime + ' - ' + endTime);
      }
      
      function getTime(hours, minutes) {
        var time = null;
        minutes = minutes + "";
        if (hours < 12) {
          time = "AM";
        }
        else {
          time = "PM";
        }

        if (minutes.length == 1) {
          minutes = "0" + minutes;
        }
        return hours + ":" + minutes + " " + time;
      }
      slideTime();
      });