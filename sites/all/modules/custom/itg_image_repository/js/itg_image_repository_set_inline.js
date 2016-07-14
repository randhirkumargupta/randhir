/*
 * @file itg_image_repository_set_inline.js
 */

/*
 * @file itg_image_repository_set_inline.js
 * Contains all itg image repository
 */
(function($) {

var ii = window.itg_image_repositoryInline = {};

// Drupal behavior
Drupal.behaviors.itg_image_repositoryInline = {attach: function(context, settings) {
  $('div.itg_image_repository-inline-wrapper', context).not('.processed').addClass('processed').show().find('a').click(function() {
    var i = this.name.indexOf('-itg_image_repository-');
    ii.activeTextarea = $('#'+ this.name.substr(0, i)).get(0);
    ii.activeType = this.name.substr(i+6);
 
    if (typeof ii.pop == 'undefined' || ii.pop.closed) {
      ii.pop = window.open(this.href + (this.href.indexOf('?') < 0 ? '?' : '&') +'app=nomatter|itg_image_repositoryload@itg_image_repositoryInline.load', '', 'width='+ 760 +',height='+ 560 +',resizable=1');
    }

    ii.pop.focus();
    return false;
  });
}};

//function to be executed when itg_image_repository loads.
ii.load = function(win) {
  win.itg_image_repository.setSendTo(Drupal.t('Insert file'), ii.insert);
  $(window).bind('unload', function() {
    if (ii.pop && !ii.pop.closed) ii.pop.close();
  });
};

//insert html at cursor position
ii.insertAtCursor = function (field, txt, type) {
  field.focus();
  if ('undefined' != typeof(field.selectionStart)) {
    if (type == 'link' && (field.selectionEnd-field.selectionStart)) {
      txt = txt.split('">')[0] +'">'+ field.value.substring(field.selectionStart, field.selectionEnd) +'</a>';
    }
    field.value = field.value.substring(0, field.selectionStart) + txt + field.value.substring(field.selectionEnd, field.value.length);
  }
  else if (document.selection) {
    if (type == 'link' && document.selection.createRange().text.length) {
      txt = txt.split('">')[0] +'">'+ document.selection.createRange().text +'</a>';
    }
    document.selection.createRange().text = txt;
  }
  else {
    field.value += txt;
  }
};

//sendTo function
ii.insert = function (file, win) {
  var type = ii.activeType == 'link' ? 'link' : (file.width ? 'image' : 'link');
  var html = type == 'image' ? ('<img src="'+ file.url +'" width="'+ file.width +'" height="'+ file.height +'" alt="'+ file.name +'" />') : ('<a href="'+ file.url +'">'+ file.name +' ('+ file.size +')</a>');
  ii.activeType = null;
  win.blur();
  ii.insertAtCursor(ii.activeTextarea, html, type);
};

})(jQuery);