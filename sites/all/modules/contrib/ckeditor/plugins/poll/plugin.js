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
CKEDITOR.plugins.add( 'poll', {

	// Register the icons.
	icons: 'poll',

	// The plugin initialization logic goes inside this method.
	init: function( editor ) {

		// Define an editor command that opens our dialog window.
		editor.addCommand( 'poll', new CKEDITOR.dialogCommand( 'pollDialog' ) );

		// Create a toolbar button that executes the above command.
		editor.ui.addButton( 'poll', {

			// The text part of the button (if available) and the tooltip.
			label: 'Insert Polls',

			// The command to execute on click.
			command: 'poll',
icon: this.path + 'icons/poll.png',

			// The button placement in the toolbar (toolbar group name).
			toolbar: 'insert'
		});

		// Register our dialog file -- this.path is the plugin folder path.
		CKEDITOR.dialog.add( 'pollDialog', this.path + 'dialogs/poll.js' );
	}
});
