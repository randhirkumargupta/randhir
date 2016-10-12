/**
 * Plugin file for survey
 */

// Register the plugin within the editor.
CKEDITOR.plugins.add( 'survey', {

	// Register the icons.
	icons: 'survey',

	// The plugin initialization logic goes inside this method.
	init: function( editor ) {

		// Define an editor command that opens our dialog window.
		editor.addCommand( 'survey', new CKEDITOR.dialogCommand( 'surveyDialog' ) );

		// Create a toolbar button that executes the above command.
		editor.ui.addButton( 'survey', {

			// The text part of the button (if available) and the tooltip.
			label: 'Insert Survey',

			// The command to execute on click.
			command: 'survey',
      icon: this.path + 'icons/survey.png',

			// The button placement in the toolbar (toolbar group name).
			toolbar: 'insert'
		});

		// Register our dialog file -- this.path is the plugin folder path.
		CKEDITOR.dialog.add( 'surveyDialog', this.path + 'dialogs/survey.js' );
	}
});
