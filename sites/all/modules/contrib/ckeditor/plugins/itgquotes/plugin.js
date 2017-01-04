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
CKEDITOR.plugins.add( 'itgquotes', {

	// Register the icons.
	icons: 'itgquotes',

	// The plugin initialization logic goes inside this method.
	init: function( editor ) {

		// Define an editor command that opens our dialog window.
		editor.addCommand( 'itgquotes', new CKEDITOR.dialogCommand( 'itgquotesDialog' ) );

		// Create a toolbar button that executes the above command.
		editor.ui.addButton( 'itgquotes', {

			// The text part of the button (if available) and the tooltip.
			label: 'Insert Quotes',

			// The command to execute on click.
			command: 'itgquotes',
icon: this.path + 'icons/itgquotes.png',

			// The button placement in the toolbar (toolbar group name).
			toolbar: 'insert'
		});

		// Register our dialog file -- this.path is the plugin folder path.
		CKEDITOR.dialog.add( 'itgquotesDialog', this.path + 'dialogs/itgquotes.js' );
	}
});
