/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */
Drupal.behaviors.itg_widgets = {
  attach: function (context, settings) {
    jQuery ("div.big-news-content-videogallery a.has-ajax-big-story").click (function () {
      jQuery ('.big-story-col-1 .loading-popup').show ();
      var nid = jQuery (this).attr ("data-nid");
      jQuery.get ("big-story-video-gallery/" + nid, function (data) {
        // add new data data.
        jQuery ("#videogallery-iframe").html (data);
        videoGallery ();
      jQuery ("#videogallery-iframe").on ('click', '#close-big-story', function () {
        jQuery ("#videogallery-iframe").html (" ");
        jQuery ("#videogallery-iframe").hide ();
      });
      });
    });
    //Prevent stop video if it is palyed previously.
    jQuery ('body').on('click', '.slick-track img', function (e){
      jQuery (".iframe-video-dailymotion").each (function () {
        var url = jQuery (this).attr ("src");
        jQuery (this).removeAttr("src");
        var Updatedurl = updateQueryStringParameter (url, 'autoplay', '0');
        jQuery (this).attr ('src', Updatedurl);
      });
    });

    function updateQueryStringParameter (uri, key, value) {
      var re = new RegExp ("([?&])" + key + "=.*?(&|$)", "i");
      var separator = uri.indexOf ('?') !== -1 ? "&" : "?";
      if (uri.match (re)) {
        return uri.replace (re, '$1' + key + "=" + value + '$2');
      } else {
        return uri + separator + key + "=" + value;
      }
    }
    //common function for popup video
    function videoGallery () {
      jQuery ("#videogallery-iframe").show ();
      jQuery ('.big-story-col-1 .loading-popup').hide ();
      jQuery ('.videogallery-slider').slick ({
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: false,
        fade: false,
        asNavFor: '.video-slider-images ul'
      });
      jQuery ('.video-slider-images ul').slick ({
        slidesToShow: 7,
        slidesToScroll: 1,
        asNavFor: '.videogallery-slider',
        dots: false,
        centerMode: false,
        arrows: true,
        variableWidth: true,
        focusOnSelect: true,
        responsive: [
          {
            breakpoint: 1024,
            settings: {
              slidesToShow: 7,
              slidesToScroll: 1,
              arrows: false
            }
          },
          {
            breakpoint: 600,
            settings: {
              slidesToShow: 4,
              arrows: false,
              slidesToScroll: 1
            }
          },
          {
            breakpoint: 480,
            settings: {
              slidesToShow: 3,
              arrows: false,
              slidesToScroll: 1
            }
          }
        ]
      });
    }
    //alert('@@@');

    //        jQuery('#edit-actionitg-widget-categories-wise-node-group').click(function() {
    //            if (confirm('Are you sure?'))
    //                return true;
    //            else
    //                return false;
    //        });

    //        var events = jQuery('#edit-actionitg-widget-categories-wise-node-group').data('events'); // Get the jQuery events.
    //        console.log(events);
    //jQuery('#edit-actionitg-widget-categories-wise-node-group').unbind('mousedown'); // Remove the click events.
    //        jQuery('#edit-actionitg-widget-categories-wise-node-group').mousedown(function() {
    //            if (confirm('Are you sure you want to delete that?')) {
    //                //jQuery("#views-form-section-wise-draggable-content-order-we-may-suggest-widget").submit();
    //                return true;
    //            }
    //            // Prevent default action.
    //            return false;
    //        });
    jQuery ('.associate-content-block').click (function () {
      var widgets_type = jQuery (this).attr ('data-widget');      
      var widgets_type_array = widgets_type.split ("-");
      var widgets_type = widgets_type_array[0];
      var widgets_id = widgets_type_array[1];
      jQuery ("#videogallery-iframe").append('<img class="loading-popup" src="http://qa.indiatodayonline.in/sites/all/themes/itg/images/tab-loading.gif" alt="loading">');
      jQuery(this).parents('.stryimg').hide(700, function(){
          jQuery('#videogallery-iframe').show(1000);          
      });             
      jQuery.ajax ({
        url: Drupal.settings.basePath + "associate-photo-video-content/" + widgets_type + "/" + widgets_id,
        method: 'post',
        //data: {status_val: 1, section_name: section_name, template_name: template_name, layout_type:layout_type},
        beforeSend: function () {
          // $('.itg-ajax-loader').show();
        },
        success: function (data) {
          jQuery ("#videogallery-iframe").html (data);
          videoGallery ();
          jQuery('.story-associate-content').css('height', 'auto');
        }
      });
    });
    jQuery (".story-associate-content #videogallery-iframe").on ('click', '#close-big-story', function () {       
        jQuery('.story-associate-content').css('height', '340px'); 
        jQuery('#videogallery-iframe').hide(700, function(){          
            jQuery('.stryimg').show(1000);         
            jQuery ("#videogallery-iframe").empty();
      }); 
    });

    jQuery ('#edit-state1').change (function () {
      var getval = jQuery (this).val ();
      if (getval == 0)
      {
        getval = "";
      }
      jQuery ('#edit-state').val (getval);
    })
    jQuery ('#edit-cat1_id').change (function () {
      var getval = jQuery (this).val ();
      if (getval == 0)
      {
        getval = "";
      }
      jQuery ('#edit-cat_id').val (getval);
    })
// This code use for mark candidate status
    jQuery ('.key-radio').live ('click', function () {
      var getname = jQuery (this).attr ('name');
      var getstatus = jQuery (this).val ();
      jQuery.ajax ({
        url: Drupal.settings.basePath + 'update-keycandidate-status',
        type: 'post',
        beforeSend: function () {
          jQuery ('#widget-ajex-loader').show ();

        },
        data: {
          'fname': getname,
          'status': getstatus,
        },
        success: function (data) {


        },
        error: function (xhr, desc, err) {
          console.log (xhr);
          console.log ("Details: " + desc + "\nError:" + err);
        }
      });
    })
    jQuery (".remove_from_nodequeue_draggable_view").click (function () {
      var nid = jQuery (this).attr ("data-nid");
      var qid = jQuery (this).attr ("data-queueid");
      var view_name = jQuery (this).attr ("data-view");
      var view_page = jQuery (this).attr ("data-page");
      // get query parameter
      var c_tid = get_url_parameter ('field_story_category_tid');
      var type = get_url_parameter ('type');
      if (typeof (c_tid) != "undefined" && c_tid !== null && typeof (type) != "undefined" && type !== null) {
        if (confirm ('Are you sure you want to move this content ?')) {
          jQuery ("#widget-ajex-loader").css ("display", "block");
          jQuery.get ("remove_from_widgets_section/" + nid + "/" + qid + "/" + view_name + "/" + view_page + "/" + c_tid + "/" + type, function (data, status) {
            if (data == 'deleted') {
              //window.location.reload();
            }
          });
        }
        console.log ("section and type found");
      } else {
        if (confirm ('Are you sure you want to move this content ?')) {
          jQuery ("#widget-ajex-loader").css ("display", "block");
          jQuery.get ("remove_from_widgets/" + nid + "/" + qid + "/" + view_name + "/" + view_page, function (data, status) {

            if (data == 'deleted') {
              window.location.reload ();

            }
            window.location.reload ();
          });
        }
      }
    });

    jQuery (".add-so-sorry-extra-data").click (function () {
      var extra_type = jQuery (this).val ();
      var nid = jQuery (this).attr ('data-nid');
      window.location.replace ("add-so-sorry-extra-data/" + nid + "/" + extra_type);
      jQuery ("#widget-ajex-loader").css ("display", "block");
    });

    jQuery (".remove-so-sorry-extra-data").click (function () {
      jQuery ("#widget-ajex-loader").css ("display", "block");
    });

    // This code use form check/uncheck all check box function
//    jQuery ('.widgets-view .vbo-table-select-all').click (function () {
//
//      var mainids = [];
//      var formid = jQuery ("input[name='form_id']").val ();
//      if (jQuery (this).is (':checked')) {
//        type = 'ADD';
//
//      } else {
//        type = 'REMOVE';
//      }
//
//      jQuery ('.vbo-select').each (function () {
//        var checkids = jQuery (this).val ();
//        mainids.push (jQuery (this).val ());
//        if (type == 'ADD') {
//          if (!jQuery (this).is (':checked')) {
//            jQuery ('.nodes_id_container').append ('<span id="spn_' + checkids + '" class="content-ids">' + checkids + '<a class="removeid" cid="' + checkids + '" href="javascript:void(0)">X</a></span>');
//          }
//        } else {
//          jQuery ('#spn_' + checkids).remove ();
//        }
//      })
//      jQuery.ajax ({
//        url: Drupal.settings.basePath + 'setids',
//        type: 'post',
//        beforeSend: function () {
//         // jQuery ('#widget-ajex-loader').show ();
//
//        },
//        data: {
//          'checkid': mainids,
//          'formid': formid,
//          'type': type
//        },
//        success: function (data) {
//          setTimeout (function () {
//
//           // jQuery ('#widget-ajex-loader').hide ();
//
//          }, 500);
//
//        },
//        error: function (xhr, desc, err) {
//          console.log (xhr);
//          console.log ("Details: " + desc + "\nError:" + err);
//        }
//      });
//    });

    //This code use remove ids functionality from top 

//    jQuery ('.widgets-view .removeid').live ('click', function () {
//      var getids = jQuery (this).attr ('cid');
//      jQuery (this).parent ().remove ();
//      jQuery ('.vbo-select').each (function () {
//        if (jQuery (this).val () == getids) {
//          jQuery (this).attr ('checked', false);
//
//        }
//
//      })
//      var formid = jQuery ("input[name='form_id']").val ();
//      var type = 'REMOVE';
//      jQuery.ajax ({
//        url: Drupal.settings.basePath + 'setids',
//        type: 'post',
//        beforeSend: function () {
//        //  jQuery ('#widget-ajex-loader').show ();
//          jQuery (".vbo-select").attr ("disabled", true);
//        },
//        data: {
//          'checkid': getids,
//          'formid': formid,
//          'type': type
//        },
//        success: function (data) {
//          console.log (data.length);
//          var json_obj = JSON.parse (data);
//          if (json_obj.length === 0) {
//            jQuery (".handle-unckeck-on-page").attr ('checked', false);
//          }
//          setTimeout (function () {
//
//           // jQuery ('#widget-ajex-loader').hide ();
//            jQuery (".vbo-select").attr ("disabled", false);
//          }, 500);
//
//        },
//        error: function (xhr, desc, err) {
//          console.log (xhr);
//          console.log ("Details: " + desc + "\nError:" + err);
//        }
//      });
//
//    })

    //This code use add ids functionality from top 

//    jQuery ('.widgets-view .vbo-select').unbind ().click (function () {
//      var formid = jQuery ("input[name='form_id']").val ();
//      var checkids = jQuery (this).val ();
//      if (jQuery (this).is (':checked')) {
//        type = 'ADD';
//        jQuery ('.nodes_id_container').append ('<span id="spn_' + checkids + '" class="content-ids">' + checkids + '<a class="removeid" cid="' + checkids + '" href="javascript:void(0)">X</a></span>');
//
//      } else {
//        type = 'REMOVE';
//        jQuery ('#spn_' + checkids).remove ();
//      }
//
//      jQuery.ajax ({
//        url: Drupal.settings.basePath + 'setids',
//        type: 'post',
//        beforeSend: function () {
//          //jQuery ('#widget-ajex-loader').show ();
//          jQuery (".vbo-select").attr ("disabled", true);
//        },
//        data: {
//          'checkid': checkids,
//          'formid': formid,
//          'type': type
//        },
//        success: function (data) {
//          setTimeout (function () {
//
//           // jQuery ('#widget-ajex-loader').hide ();
//            jQuery (".vbo-select").attr ("disabled", false);
//          }, 500);
//
//        },
//        error: function (xhr, desc, err) {
//          console.log (xhr);
//          console.log ("Details: " + desc + "\nError:" + err);
//        }
//      });
//    });


    jQuery (".widgets-view .view-link").parent ().attr ("target", "_blank");
    //jQuery(".widgets-view .view-link").css("text-transform","capitalize");

    jQuery (".view-section-wise-content-ordering-list span.move-link").on ('click', function () {
      if (confirm ("Are you sure you want to remove this content ?")) {
        return true;
      } else {
        return false;
      }
    });

    jQuery (".view-display-id-poll_widget_list span.move-link").on ('click', function () {
      if (confirm ("Are you sure you want to remove this content ?")) {
        return true;
      } else {
        return false;
      }
    });

  }

};

var get_url_parameter = function get_url_parameter (sParam) {
  var sPageURL = decodeURIComponent (window.location.search.substring (1)),
          sURLVariables = sPageURL.split ('&'),
          sParameterName,
          i;
  for (i = 0; i < sURLVariables.length; i++) {
    sParameterName = sURLVariables[i].split ('=');

    if (sParameterName[0] === sParam) {
      return sParameterName[1] === undefined ? true : sParameterName[1];
    }
  }
};


jQuery (document).ready (function () {
  jQuery ('.cat-wraper').html (jQuery ('.form-item-cat1-id').html ());
  jQuery ('.state-wraper').html (jQuery ('.form-item-state1').html ());
  jQuery ('.form-item-cat1-id').remove ();
  jQuery ('.form-item-state1').remove ();
  jQuery ('#edit-cat1-id').attr ('name', 'cat_id');
  jQuery ('#edit-state1').attr ('name', 'state');
  jQuery (".custom-weight-draggable input[type=number]").change (function () {
    jQuery (this).next ().children ().find ('option').remove ().end ().append ('<option value="' + jQuery (this).val () + '">' + jQuery (this).val () + '</option>').val (jQuery (this).val ());
  });
  //    jQuery("#edit-actionitg-widget-categories-wise-node-group").click(function(e){
  //        e.preventDefault();
  //        if(confirm("Are you sure want to perform action.")) {
  //            return ture;
  //        } else {
  //            return false;
  //        }
  //    });

  jQuery ("select#fake-soruce-type").on ("change", function () {
    var soruce_type = jQuery (this).val ();
    jQuery ("#edit-field-story-source-type-value").val (soruce_type);
  });
});
  