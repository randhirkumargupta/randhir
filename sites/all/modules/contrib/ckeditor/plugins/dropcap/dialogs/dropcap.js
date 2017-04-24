/**
 * Copyright (c) 2014-2016, CKSource - Frederico Knabben. All rights reserved.
 * Licensed under the terms of the MIT License (see LICENSE.md).
 *
 * The dropcap plugin dialog window definition.
 *
 * Created out of the CKEditor Plugin SDK:
 * http://docs.ckeditor.com/#!/guide/plugin_sdk_sample_1
 */

// Our dialog definition.

function capitalise(string) {
    return string.charAt(0).toUpperCase() + string.slice(1).toLowerCase();
}

CKEDITOR.dialog.add( 'dropcapDialog', function( editor ) {
	return {

		// Basic properties of the dialog window: title, minimum size.
		title: 'Dropcap Properties',
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
						id: 'dropcap',
						label: 'Enter Text',

						// Validation checking whether the field is not empty.
						validate: CKEDITOR.dialog.validate.notEmpty( "Text field cannot be empty." )
					}
//                                        ,
//
//{
//						// Text input field for the abbreviation title (explanation).
//						type: 'text',
//						id: 'size',
//						label: 'Font Size',
//						validate: CKEDITOR.dialog.validate.notEmpty( "Size field cannot be empty." )
//					},
//
//{
//						// Text input field for the abbreviation title (explanation).
//						type: 'text',
//						id: 'color',
//						label: 'Font Color',
//						validate: CKEDITOR.dialog.validate.notEmpty( "Color field cannot be empty." )
//					}



				]

			},

			
		],

		// This method is invoked once a user clicks the OK button, confirming the dialog.
		onOk: function() {

			// The context of this function is the dialog object itself.
			// http://docs.ckeditor.com/#!/api/CKEDITOR.dialog
			var dialog = this;

			// Create a new <abbr> element.
			//var dropcap = editor.document.createElement( 'div' );

			var str=dialog.getValueOf( 'tab-basic', 'dropcap' );
			str1 = str.substring(0,1).toUpperCase() + str.substring(1);
			//get first character from string
			var first=str1.substring(0,1)
			//get other string excluding first character
			var other_string=str.slice(1)
			//get size value
			//var size=dialog.getValueOf( 'tab-basic', 'size' );
			var size= '58';
			//get color value
			//var color=dialog.getValueOf( 'tab-basic', 'color' )
			var color= '#777879';

			//style for first element
			var drp_first_element = '<span style="font-size:'+size+'px;color:'+color+';">'+first+'</span>'
			//merge first and other string
			var final=drp_first_element+other_string;

			//insert into editor
			editor.insertHtml( final);

		}
	};
});
