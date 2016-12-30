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
CKEDITOR.plugins.add( 'expertchunk', {
  init: function( editor )
  {
   editor.addCommand( 'expertchunk_command', {
    exec : function( editor ) {
     //here is where we tell CKEditor what to do.
     editor.insertHtml( '[ITG:EXPERT-CHUNK]' );
    }
   });
   
   editor.ui.addButton( 'expertchunk_button', {
    label: 'Insert Expert Chunk', //this is the tooltip text for the button
    command: 'expertchunk_command',
    icon: this.path + 'icons/expert.png'
   });
  }
 });