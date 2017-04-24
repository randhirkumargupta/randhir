/**
 * Copyright (c) 2014-2016, CKSource - Frederico Knabben. All rights reserved.
 * Licensed under the terms of the MIT License (see LICENSE.md).
 *
 * The editorquotes plugin dialog window definition.
 *
 * Created out of the CKEditor Plugin SDK:
 * http://docs.ckeditor.com/#!/guide/plugin_sdk_sample_1
 */

// Our dialog definition.

CKEDITOR.dialog.add( 'editorquotesDialog', function( editor ) {
	return {

		// Basic properties of the dialog window: title, minimum size.
		title: 'Quotes Properties',
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
						id: 'quotes-text',
						label: 'Quotes Text',

						// Validation checking whether the field is not empty.
						validate: CKEDITOR.dialog.validate.notEmpty( "Quotes field cannot be empty." )
					},

                                        {
						// Text input field for the abbreviation title (explanation).
						type: 'text',
						id: 'author',
						label: 'Author Name',
						//validate: CKEDITOR.dialog.validate.notEmpty( "Author field cannot be empty." )
					}



				]

			},

			
		],

		// This method is invoked once a user clicks the OK button, confirming the dialog.
		onOk: function() {

			// The context of this function is the dialog object itself.
			// http://docs.ckeditor.com/#!/api/CKEDITOR.dialog
                        author_check = '';
			var dialog = this;
                        var div = editor.document.createElement( 'div' );
                        div.setAttribute( 'class', 'quotes' );
                        var quotestext=dialog.getValueOf( 'tab-basic', 'quotes-text' );
                        var author=dialog.getValueOf( 'tab-basic', 'author' );
                        if(author) {
                         author_check = '<div style="text-align:right" class="author"> - '+author+'</div>'   
                        } 
                        var first_element = '<blockquote>'+quotestext+'</blockquote>'+author_check
			div.setHtml(first_element);
			// Finally, insert the element into the editor at the caret position.
			editor.insertElement( div );

		}
	};
});
