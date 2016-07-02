/**
 * @file itg_syndication_custom_feed.js
 * This is used for settting value in body textarea and formatting in proper humanreadble format
 */

(function($) {
    $.fn.feed_pattern = function(data) {
        /* add pattern into textarea*/
        content =   $("textarea.xml-field-codemirror").val(data);
        $("textarea.xml-field-codemirror").val(data);
        $("textarea.edit-field-syndication-xml-formate-und-0-xml").val(data);
        /*Now do the formatting of textarea value*/
        $("textarea.xml-field-codemirror").format({method: 'xml'});
        /* Removed dublicacey*/
        $("div.CodeMirror").remove();
        // initialize editor
        CodeMirror.fromTextArea(document.getElementById("edit-field-syndication-xml-formate-und-0-xml"), {
            mode: "text/xml",
            lineNumbers: true
        });    
    };
})(jQuery);