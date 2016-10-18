/**
 * Plungin for poll
 * @param {type} string
 * 
 */

// Our dialog definition.
function capitalise(string) {
  return string.charAt(0).toUpperCase() + string.slice(1).toLowerCase();
}

CKEDITOR.dialog.add('pollDialog', function(editor) {
  return {
    // Basic properties of the dialog window: title, minimum size.
    title: 'Poll',
    minWidth: 400,
    minHeight: 200,
    
    // Dialog window content definition.
    contents: [
      {
        // Definition of the Basic Settings dialog tab (page).
        id: 'tab-basic',
        label: 'Basic Settings',
       
        elements: [
          {
            type: 'text',
            id: 'inset-polls-nid',
            label: 'Poll',
            className: 'polls-txt',
            validate: CKEDITOR.dialog.validate.notEmpty("This field cannot be empty.")
          },
          {
            type: 'button',
            label: 'Get Polls',
            title: 'Poll',
            onClick: function() {
              var bas_path = window.location.origin?window.location.origin+'/':window.location.protocol+'/'+window.location.host+'/';
   
              if(bas_path == 'http://localhost/') {
                bas_path = bas_path+'itgcms/';
              }
              editor.popup(bas_path + 'pqs/associate-with-story/poll', 400, 600);
              
            }
          },
        ]
      }

    ],
    
    // This method is invoked once a user clicks the OK button, confirming the dialog.
    onOk: function() {

      // The context of this function is the dialog object itself.
      // http://docs.ckeditor.com/#!/api/CKEDITOR.dialog
      var dialog = this;

      // Create a new <div> element.
      var dropcap = editor.document.createElement('div');

      var title = dialog.getValueOf('tab-basic', 'inset-polls-nid');

      // Set element attribute and text by getting the defined field values.
      dropcap.setAttribute('class', 'poll');

      dropcap.setText(title);

      // Finally, insert the element into the editor at the caret position.
      editor.insertElement(dropcap);
    }
  };
});
