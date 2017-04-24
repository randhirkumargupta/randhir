/*
 * @file itg_notification.js
 */

(function ($) {
  Drupal.behaviors.itg_notification = {
    attach: function (context, settings) {

      var uid = settings.itg_notification.settings.uid;
      var nid = settings.itg_notification.settings.nid;

      // If user is not drupal admin
      if (uid !== 1) {
        $ ('#edit-body-und-0-format').hide ();
      }

      $ ('input[name="field_ntf_schedule[und][0][value][date]"]').prop ("readonly", true);
      $ ('#edit-field-cm-display-title-und-0-value').prop ("readonly", true);
        
      
      $(".form-field-name-field-ntf-select-device input[type=checkbox]").click(function(){
        var checked_devices = [];
        if(jQuery(this).val()!=='all') {
            $(".form-field-name-field-ntf-select-device input[type=checkbox]").each(function(){
              if(jQuery (this).is (":checked")) {
                  checked_devices.push(jQuery (this).val());
                  // Logic to remove all value from array.
                  checked_devices = checked_devices.filter(function(item) { 
                      return item !== 'all';
                  });
                }
            });
        }
        else if(jQuery (this).is (":checked") && jQuery(this).val() == 'all') {
            $(".form-field-name-field-ntf-select-device input[type=checkbox]").each(function(){
                checked_devices.push(jQuery (this).val());
                // Logic to remove all value from array.
                checked_devices = checked_devices.filter(function(item) { 
                    return item !== 'all';
                });
            });
        }
        else if(!jQuery (this).is (":checked") && jQuery(this).val() == 'all') {
            checked_devices = [];
            $(".form-item-field-ntf-select-device-und input[type=checkbox]").each(function(){
              jQuery (this).prop ('checked', false);
            });
        }
        else {
          checked_devices = [];
        }
        
        if(checked_devices.length===3) {
          $(".form-item-field-ntf-select-device-und input[type=checkbox]").each(function(){
            jQuery (this).prop ('checked', true);
          });
        }
        if(checked_devices.length<=2) {
          $(".form-item-field-ntf-select-device-und-all [type=checkbox]").prop('checked', false);
        }
      });
      
      
      // Assign story checkbox value (show/hide Content ID)
      if ($ ("#edit-field-ntf-assign-story-und-1").prop ("checked") === true) {
        $ ('#edit-field-news-cid').show ();

      }
      else {
        $ ('#edit-field-news-cid').hide ();
      }

      // Assign story checkbox click event (show/hide Content ID)
      $ ("#edit-field-ntf-assign-story-und-1").on ("click", function () {

        if ($ (this).prop ("checked") === true) {
          $ ('#edit-field-news-cid').show ();
        }
        else {
          $ ('#edit-field-news-cid').hide ();
        }
      });

      // Notification message title counter
      $ ('#edit-title').keyup (function () {
        var len = $ (this).val ().length;
        $ ('#notification-text-counter').text ('Text Count: ' + len);
      });

      // Select device for notification
      $ ('body').on ('change', '.form-field-name-field-ntf-select-device .form-checkbox', function () {
//        var el_value = $ (this).attr ('value');
//        var el_check = $ (this).is (':checked');
//        var iOS = $ (this).parents ('.form-field-name-field-ntf-select-device').find ('.form-checkbox[value="iOS"]').is (':checked');
//        var Android = $ (this).parents ('.form-field-name-field-ntf-select-device').find ('.form-checkbox[value="Android"]').is (':checked');
//        var Windows = $ (this).parents ('.form-field-name-field-ntf-select-device').find ('.form-checkbox[value="Windows"]').is (':checked');
//        if (el_value == "all" && el_check == true) {
//          $ (this).parents ('.form-field-name-field-ntf-select-device').find ('.form-checkbox').attr ('checked', false);
//          $ (this).attr ('checked', true);
//        }
//        if (el_value == "iOS" || el_value == "Android" || el_value == "Windows" && el_check == true) {
//          $ (this).parents ('.form-field-name-field-ntf-select-device').find ('.form-checkbox[value="all"]').attr ('checked', false);
//        }
        
//        jQuery (document).ready (function () {
//          jQuery ("input[type=checkbox]#edit-field-ntf-select-device-und-all").on ("click", function () {
//            if (jQuery (this).is (":checked")) {
//              jQuery (".form-item-field-ntf-select-device-und").find ("input[type=checkbox]").each (function () {
//                jQuery (this).prop ('checked', true);
//              });
//            }
//            else {
//              jQuery (".form-item-field-ntf-select-device-und").find ("input[type=checkbox]").each (function () {
//                jQuery (this).prop ('checked', false);
//              });
//            }
//          });
//        });
        
      });
    }
  };
}) (jQuery, Drupal, this, this.document);