/**
 * Copyright (c) 2014-2016, CKSource - Frederico Knabben. All rights reserved.
 * Licensed under the terms of the MIT License (see LICENSE.md).
 *
 * The Blurb plugin dialog window definition.
 *
 * Created out of the CKEditor Plugin SDK:
 * http://docs.ckeditor.com/#!/guide/plugin_sdk_sample_1
 */

// Our dialog definition.

function capitalise(string) {
    return string.charAt(0).toUpperCase() + string.slice(1).toLowerCase();
}

CKEDITOR.dialog.add( 'blurbDialog', function( editor ) {
	return {

		// Basic properties of the dialog window: title, minimum size.
		title: 'Blurb Properties',
		minWidth: 400,
		minHeight: 200,

		// Dialog window content definition.
		contents: [
			{
				// Definition of the Basic Settings dialog tab (page).
				id: 'tab-basic',
				label: 'Basic Settings',

				// The tab content.
				elements: [
					{
						// Text input field for the abbreviation text.
						type: 'text',
						id: 'blurb',
						label: 'Enter Title',

						// Validation checking whether the field is not empty.
						validate: CKEDITOR.dialog.validate.notEmpty( "Title field cannot be empty." )
					}



				]

			},

			
		],

		// This method is invoked once a user clicks the OK button, confirming the dialog.
		onOk: function() {

			// The context of this function is the dialog object itself.
			// http://docs.ckeditor.com/#!/api/CKEDITOR.dialog
			var dialog = this;

			// Create a new <div> element.
			var dropcap = editor.document.createElement( 'div' );

			var title=dialog.getValueOf( 'tab-basic', 'blurb' );

			// Set element attribute and text by getting the defined field values.
			dropcap.setAttribute( 'class', 'blurb' );

			dropcap.setText(title);

			// Finally, insert the element into the editor at the caret position.
			editor.insertElement( dropcap );
		}
	};
});
