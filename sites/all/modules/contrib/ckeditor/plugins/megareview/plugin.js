/**
 * Plugin file for survey
 */

// Register the plugin within the editor.
CKEDITOR.plugins.add( 'megareview', {

	// Register the icons.
	icons: 'megareview',

	// The plugin initialization logic goes inside this method.
	init: function( editor ) {

		// Define an editor command that opens our dialog window.
		editor.addCommand( 'megareview', new CKEDITOR.dialogCommand( 'megareviewDialog' ) );

		// Create a toolbar button that executes the above command.
		editor.ui.addButton( 'megareview', {

			// The text part of the button (if available) and the tooltip.
			label: 'Insert Mega Review',

			// The command to execute on click.
			command: 'megareview',
      icon: this.path + 'icons/megareview.png',

			// The button placement in the toolbar (toolbar group name).
			toolbar: 'insert'
		});

		// Register our dialog file -- this.path is the plugin folder path.
		CKEDITOR.dialog.add( 'megareviewDialog', this.path + 'dialogs/megareview.js' );
	}
});
