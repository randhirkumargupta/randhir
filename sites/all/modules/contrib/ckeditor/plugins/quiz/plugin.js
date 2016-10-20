/**
 * Plugin file for quiz
 */

// Register the plugin within the editor.
CKEDITOR.plugins.add( 'quiz', {

	// Register the icons.
	icons: 'quiz',

	// The plugin initialization logic goes inside this method.
	init: function( editor ) {

		// Define an editor command that opens our dialog window.
		editor.addCommand( 'quiz', new CKEDITOR.dialogCommand( 'quizDialog' ) );

		// Create a toolbar button that executes the above command.
		editor.ui.addButton( 'quiz', {

			// The text part of the button (if available) and the tooltip.
			label: 'Insert Quiz',

			// The command to execute on click.
			command: 'quiz',
      icon: this.path + 'icons/quiz.png',

			// The button placement in the toolbar (toolbar group name).
			toolbar: 'insert'
		});

		// Register our dialog file -- this.path is the plugin folder path.
		CKEDITOR.dialog.add( 'quizDialog', this.path + 'dialogs/quiz.js' );
	}
});
