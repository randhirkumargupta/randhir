/**
 * @file itg_syndication_custom_feed.js
 * This is used for settting value in body textarea and formatting in proper humanreadble format
 */

(function($) {
	$.fn.feed_pattern = function(data) {
            /* add pattern into textarea*/
            $("textarea#edit-body-und-0-value").val(data);
            /*Now do the formatting of textarea value*/
            $("textarea#edit-body-und-0-value").format({method: 'xml'});
	};
})(jQuery);