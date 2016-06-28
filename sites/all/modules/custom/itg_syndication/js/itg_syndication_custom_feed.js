/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


(function($) {
	$.fn.feed_pattern = function(data) {
            /* add pattern into textarea*/
            $("textarea#edit-body-und-0-value").val(data);
            /*Now do the formatting of textarea value*/
            $("textarea#edit-body-und-0-value").format({method: 'xml'});
	};
})(jQuery);