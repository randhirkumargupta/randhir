/**
 * Copyright (c) 2014-2016, CKSource - Frederico Knabben. All rights reserved.
 * Licensed under the terms of the MIT License (see LICENSE.md).
 *
 * Basic sample plugin inserting blurb elements into the CKEditor editing area.
 *
 * Created out of the CKEditor Plugin SDK:
 * http://docs.ckeditor.com/#!/guide/plugin_sdk_sample_1
 */

// Register the plugin within the editor.
CKEDITOR.plugins.add('itgvideo', {
    // Register the icons.
    icons: 'itgvideo',
    // The plugin initialization logic goes inside this method.
    init: function(editor) {

        // Define an editor command that opens our dialog window.
        editor.addCommand('itgvideo', new CKEDITOR.dialogCommand('itgvideoDialog'));

        // Create a toolbar button that executes the above command.
        editor.ui.addButton('itgvideo', {
            // The text part of the button (if available) and the tooltip.
            label: 'Insert video',
            // The command to execute on click.
            command: 'itgvideo',
            icon: this.path + 'icons/itgvideo.png',
            // The button placement in the toolbar (toolbar group name).
            toolbar: 'insert'
        });

        // Register our dialog file -- this.path is the plugin folder path.
        CKEDITOR.dialog.add('itgvideoDialog', this.path + 'dialogs/itgvideo.js');
    }
});
