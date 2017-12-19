/*
 * @file itg_section_header.js
 * Contains all functionality related to Section header Management
 */
jQuery('body').find(".blocks-ul").sortable();
jQuery('body').find(".blocks-ul").disableSelection();
jQuery('.multi-right-block').click(function (event) {
    var selected_blocks = jQuery('.section_right_side_block select').val();
    var html = '';
    var label = '';
    for (var i = 0; i < selected_blocks.length; i++) {
        label = jQuery('.section_right_side_block select [value="' + selected_blocks[i] + '"]').text()
        html += '<li id="' + selected_blocks[i] + '"><i class="fa fa-arrows" aria-hidden="true"></i><input type="hidden" name="rightsideblock[' + i + ']" value="' + selected_blocks[i] + '"><span>' + label + '</span></span></li>';
    }
    jQuery('.blocks-ul').html(html);
});
