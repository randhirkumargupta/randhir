
/*
 * @file itg_image_repository_set_app.js
 */

/*
 * @file itg_image_repository_set_app.js
 * Contains all itg image repository
 */
/*
 * itg_image_repository Integration by URL
 * Ex-1: http://example.com/itg_image_repository?app=XEditor|url@urlFieldId|width@widthFieldId|height@heightFieldId
 * Creates "Insert file" operation tab, which fills the specified fields with url, width, height properties
 * of the selected file in the parent window
 * Ex-2: http://example.com/itg_image_repository?app=XEditor|sendto@functionName
 * "Insert file" operation calls parent window's functionName(file, itg_image_repositoryWindow)
 * Ex-3: http://example.com/itg_image_repository?app=XEditor|itg_image_repositoryload@functionName
 * Parent window's functionName(itg_image_repositoryWindow) is called as soon as itg_image_repository UI is ready. Send to operation
 * needs to be set manually. See itg_image_repository.setSendTo() method in itg_image_repository.js
 */

(function($) {

var appFields = {}, appWindow = (top.appiFrm||window).opener || parent;

// Execute when itg_image_repository loads.
itg_image_repository.hooks.load.push(function(win) {
  var index = location.href.lastIndexOf('app=');
  if (index == -1) return;
  var data = decodeURIComponent(location.href.substr(index + 4)).split('|');
  var arr, prop, str, func, appName = data.shift();
  // Extract fields
  for (var i = 0, len = data.length; i < len; i++) {
    str = data[i];
    if (!str.length) continue;
    if (str.indexOf('&') != -1) str = str.split('&')[0];
    arr = str.split('@');
    if (arr.length > 1) {
      prop = arr.shift();
      appFields[prop] = arr.join('@');
    }
  }
  // Run custom onload function if available
  if (appFields.itg_image_repositoryload && (func = isFunc(appFields.itg_image_repositoryload))) {
    func(win);
    delete appFields.itg_image_repositoryload;
  }
  // Set custom sendto function. appFinish is the default.
  var sendtoFunc = appFields.url ? appFinish : false;
  //check sendto@funcName syntax in URL
  if (appFields.sendto && (func = isFunc(appFields.sendto))) {
    sendtoFunc = func;
    delete appFields.sendto;
  }
  // Check old method windowname+itg_image_repositoryFinish.
  else if (win.name && (func = isFunc(win.name +'itg_image_repositoryFinish'))) {
    sendtoFunc = func;
  }
  // Highlight file
  if (appFields.url) {
    // Support multiple url fields url@field1,field2..
    if (appFields.url.indexOf(',') > -1) {
      var arr = appFields.url.split(',');
      for (var i in arr) {
        if ($('#'+ arr[i], appWindow.document).length) {
          appFields.url = arr[i];
          break;
        }
      }
    }
    var filename = $('#'+ appFields.url, appWindow.document).val() || '';
    itg_image_repository.highlight(filename.substr(filename.lastIndexOf('/')+1));
  }
  // Set send to
  sendtoFunc && itg_image_repository.setSendTo(Drupal.t('Insert file'), sendtoFunc);
});

// Default sendTo function
var appFinish = function(file, win) {
  var $doc = $(appWindow.document);
  for (var i in appFields) {
    $doc.find('#'+ appFields[i]).val(file[i]);
  }
  if (appFields.url) {
    try{
      $doc.find('#'+ appFields.url).blur().change().focus();
    }catch(e){
      try{
        $doc.find('#'+ appFields.url).trigger('onblur').trigger('onchange').trigger('onfocus');//inline events for IE
      }catch(e){}
    }
  }
  appWindow.focus();
  win.close();
};

// Checks if a string is a function name in the given scope.
// Returns function reference. Supports x.y.z notation.
var isFunc = function(str, scope) {
  var obj = scope || appWindow;
  var parts = str.split('.'), len = parts.length;
  for (var i = 0; i < len && (obj = obj[parts[i]]); i++);
  return obj && i == len && (typeof obj == 'function' || typeof obj != 'string' && !obj.nodeName && obj.constructor != Array && /^[\s[]?function/.test(obj.toString())) ? obj : false;
}

})(jQuery);