/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/**
 * @file Plugin for quiz
 */
( function() {
  CKEDITOR.plugins.add( 'quiz',
  {
    init: function( editor )
    {
      //adding button
      editor.ui.addButton( 'IMCE',
      {
        label: 'IMCE',
        command: 'IMCEWindow',
        icon: this.path + 'images/icon.png'
      });

      //opening imce window
      editor.addCommand( 'IMCEWindow', {
        exec : function () {
           editor.popup(Drupal.settings.basePath + 'pqs/associate-with-story/quiz?CKEditorFuncNum=' + editor._.filebrowserFnIMCE, 400, 600);
        }
      });

      //add editor function
      editor._.filebrowserFnIMCE = CKEDITOR.tools.addFunction( setFile, editor );

      //function which receive imce response
      window.ckeditor_setFile = function (file, win) {
        var cfunc = win.location.href.split('&');
        for (var x in cfunc) {
          if (cfunc[x].match(/^CKEditorFuncNum=\d+$/)) {
            cfunc = cfunc[x].split('=');
            break;
          }
        }
        CKEDITOR.tools.callFunction(cfunc[1], file);
        win.close();
      };

    }
  } );
  function setFile(file) {
    var sel = this.getSelection(),
    text = sel.getSelectedText();
    if (file.width != 0 && file.height != 0) {
      if (text) {
        this.insertHtml('<a href="' + document.location.protocol + '//'+ document.location.host +  file.url + '">' + text + '</a>');
      } else {
        this.insertHtml('<img src="' + file.url + '" style="width:' + file.width + 'px;height:' + file.height + 'px;" alt="' + file.name + '" />');
      }
    } else {
      if (text) {
        this.insertHtml('<a href="' +document.location.protocol + '//'+ document.location.host + file.url + '">' + text + '</a>');
      } else {
        this.insertHtml('<a href="' + document.location.protocol + '//'+ document.location.host +  file.url + '">' + file.name + '</a>');
      }
    }
  }
} )();
