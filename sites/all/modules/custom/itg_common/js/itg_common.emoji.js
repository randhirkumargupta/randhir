/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


(function ($) {
  Drupal.behaviors.itg_common = {
    attach: function (context, settings) {
      var path = Drupal.settings.itg_common.base_url;
      if (CKEDITOR !== undefined) {
        // Smiley Settings
        CKEDITOR.config.smiley_columns = 6;
        // Default settings.
        // Below is the description of the simly on popups.
        // Which comes on hover the smily.
        CKEDITOR.config.smiley_descriptions = [
                    'angel_smile'
                  , 'cry_smile'
                  , 'envelope'
                  , 'omg_smile'
                  , 'teeth_smile'
                  , 'tongue_smile'
                  , 'angry_smile'
                  , 'devil_smile'
                  , 'heart'
                  , 'regular_smile'
                  , 'thumbs_down'
                  , 'welcome'
                  , 'broken_heart'
                  , 'embaressed_smile'
                  , 'kiss'
                  , 'sad_smile'
                  , 'thumbs_up'
                  , 'whatchutalkingabout_smile'
                  , 'confused_smile'
                  , 'embarrassed_smile'
                  , 'lightbulb'
                  , 'shades_smile'
                  , 'thumbs_up'
                  , 'wink_smile'
                  , 'standingboy'
        ];
        // Below array is the image name.
        CKEDITOR.config.smiley_images = [
          'angel_smile.gif'
                  , 'cry_smile.gif'
                  , 'envelope.gif'
                  , 'omg_smile.gif'
                  , 'teeth_smile.gif'
                  , 'tongue_smile.gif'
                  , 'angry_smile.gif'
                  , 'devil_smile.gif'
                  , 'heart.gif'
                  , 'regular_smile.gif'
                  , 'thumbs_down.gif'
                  , 'welcome.gif'
                  , 'broken_heart.gif'
                  , 'embaressed_smile.gif'
                  , 'kiss.gif'
                  , 'sad_smile.gif'
                  , 'thumbs_up.gif'
                  , 'whatchutalkingabout_smile.gif'
                  , 'confused_smile.gif'
                  , 'embarrassed_smile.gif'
                  , 'lightbulb.gif'
                  , 'shades_smile.gif'
                  , 'thumbs_up.png'
                  , 'wink_smile.gif'
                  , 'standingboy.jpg'
        ];
        // below is the path of the image.
        CKEDITOR.config.smiley_path = path + '/sites/all/themes/itg/smiley/';
      }
    }
  }
} (jQuery));