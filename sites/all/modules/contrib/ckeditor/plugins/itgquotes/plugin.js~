/**
 * Copyright (c) 2014-2016, CKSource - Frederico Knabben. All rights reserved.
 * Licensed under the terms of the MIT License (see LICENSE.md).
 *
 * Basic sample plugin inserting dropcap elements into the CKEditor editing area.
 *
 * Created out of the CKEditor Plugin SDK:
 * http://docs.ckeditor.com/#!/guide/plugin_sdk_sample_1
 */

// Register the plugin within the editor.
CKEDITOR.plugins.add( 'dropcap', {

	// Register the icons.
	icons: 'dropcap',

	// The plugin initialization logic goes inside this method.
	init: function( editor ) {

		// Define an editor command that opens our dialog window.
		editor.addCommand( 'dropcap', new CKEDITOR.dialogCommand( 'dropcapDialog' ) );

		// Create a toolbar button that executes the above command.
		editor.ui.addButton( 'dropcap', {

			// The text part of the button (if available) and the tooltip.
			label: 'Insert Dropcap',

			// The command to execute on click.
			command: 'dropcap',
icon: this.path + 'icons/dropcap.png',

			// The button placement in the toolbar (toolbar group name).
			toolbar: 'insert'
		});

		// Register our dialog file -- this.path is the plugin folder path.
		CKEDITOR.dialog.add( 'dropcapDialog', this.path + 'dialogs/dropcap.js' );
	}
});
