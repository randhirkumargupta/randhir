/*
 * @file itg_image_repository.js
 */

/*
 * @file itg_image_repository.js
 * Contains all itg image repository
 */

(function($) {
//Global container.
window.itg_image_repository = {tree: {}, findex: [], fids: {}, selected: {}, selcount: 0, ops: {}, cache: {}, urlId: {},
vars: {previewImages: 1, cache: 1},
hooks: {load: [], list: [], navigate: [], cache: []},

//initiate itg_image_repository.
initiate: function() {
  itg_image_repository.conf = Drupal.settings.itg_image_repository || {};
  if (itg_image_repository.conf.error != false) return;
  itg_image_repository.ie = (navigator.userAgent.match(/msie (\d+)/i) || ['', 0])[1] * 1;
  itg_image_repository.FLW = itg_image_repository.el('file-list-wrapper'), itg_image_repository.SBW = itg_image_repository.el('sub-browse-wrapper');
  itg_image_repository.NW = itg_image_repository.el('navigation-wrapper'), itg_image_repository.BW = itg_image_repository.el('browse-wrapper');
  itg_image_repository.PW = itg_image_repository.el('preview-wrapper'), itg_image_repository.FW = itg_image_repository.el('forms-wrapper');
  itg_image_repository.updateUI();
  itg_image_repository.prepareMsgs();//process initial status messages
  itg_image_repository.initiateTree();//build directory tree
  itg_image_repository.hooks.list.unshift(itg_image_repository.processRow);//set the default list-hook.
  itg_image_repository.initiateList();//process file list
  itg_image_repository.initiateOps();//prepare operation tabs
  itg_image_repository.refreshOps();
  // Bind global error handler
  $(document).ajaxError(itg_image_repository.ajaxError);
  itg_image_repository.invoke('load', window);//run functions set by external applications.
},

//process navigation tree
initiateTree: function() {

  $('#navigation-tree li').each(function(i) {
    var a = this.firstChild, txt = a.firstChild;
    txt && (txt.data = itg_image_repository.decode(txt.data));
    var branch = itg_image_repository.tree[a.title] = {'a': a, li: this, ul: this.lastChild.tagName == 'UL' ? this.lastChild : null};
    if (a.href) itg_image_repository.dirClickable(branch);
    itg_image_repository.dirCollapsible(branch);
  });
},

//Add a dir to the tree under parent
dirAdd: function(dir, parent, clickable) {
  if (itg_image_repository.tree[dir]) return clickable ? itg_image_repository.dirClickable(itg_image_repository.tree[dir]) : itg_image_repository.tree[dir];
  var parent = parent || itg_image_repository.tree['.'];
  parent.ul = parent.ul ? parent.ul : parent.li.appendChild(itg_image_repository.newEl('ul'));
  var branch = itg_image_repository.dirCreate(dir, itg_image_repository.decode(dir.substr(dir.lastIndexOf('/')+1)), clickable);
  parent.ul.appendChild(branch.li);
  return branch;
},

//create list item for navigation tree
dirCreate: function(dir, text, clickable) {
  if (itg_image_repository.tree[dir]) return itg_image_repository.tree[dir];
  var branch = itg_image_repository.tree[dir] = {li: itg_image_repository.newEl('li'), a: itg_image_repository.newEl('a')};
  $(branch.a).addClass('folder').text(text).attr('title', dir).appendTo(branch.li);
  itg_image_repository.dirCollapsible(branch);
  return clickable ? itg_image_repository.dirClickable(branch) : branch;
},

//change currently active directory
dirActivate: function(dir) {
  if (dir != itg_image_repository.conf.dir) {
    if (itg_image_repository.tree[itg_image_repository.conf.dir]){
      $(itg_image_repository.tree[itg_image_repository.conf.dir].a).removeClass('active');
    }
    $(itg_image_repository.tree[dir].a).addClass('active');
    itg_image_repository.conf.dir = dir;
  }
  return itg_image_repository.tree[itg_image_repository.conf.dir];
},

//make a dir accessible
dirClickable: function(branch) {
  if (branch.clkbl) return branch;
  $(branch.a).attr('href', '#').removeClass('disabled').click(function() {itg_image_repository.navigate(this.title); return false;});
  branch.clkbl = true;
  return branch;
},

//sub-directories expand-collapse ability
dirCollapsible: function (branch) {
  if (branch.clpsbl) return branch;
  $(itg_image_repository.newEl('span')).addClass('expander').html('&nbsp;').click(function() {
    if (branch.ul) {
      $(branch.ul).toggle();
      $(branch.li).toggleClass('expanded');
      itg_image_repository.ie && $('#navigation-header').css('top', itg_image_repository.NW.scrollTop);
    }
    else if (branch.clkbl){
      $(branch.a).click();
    }
  }).prependTo(branch.li);
  branch.clpsbl = true;
  return branch;
},

//update navigation tree after getting subdirectories.
dirSubdirs: function(dir, subdirs) {
  var branch = itg_image_repository.tree[dir];
  if (subdirs && subdirs.length) {
    var prefix = dir == '.' ? '' : dir +'/';
    for (var i in subdirs) {//add subdirectories
      itg_image_repository.dirAdd(prefix + subdirs[i], branch, true);
    }
    $(branch.li).removeClass('leaf').addClass('expanded');
    $(branch.ul).show();
  }
  else if (!branch.ul){//no subdirs->leaf
    $(branch.li).removeClass('expanded').addClass('leaf');
  }
},

//process file list
initiateList: function(cached) {
  var L = itg_image_repository.hooks.list, dir = itg_image_repository.conf.dir, token = {'%dir':  dir == '.' ? $(itg_image_repository.tree['.'].a).text() : itg_image_repository.decode(dir)}
  itg_image_repository.findex = [], itg_image_repository.fids = {}, itg_image_repository.selected = {}, itg_image_repository.selcount = 0, itg_image_repository.vars.lastfid = null;
  itg_image_repository.tbody = itg_image_repository.el('file-list').tBodies[0];
  if (itg_image_repository.tbody.rows.length) {
    
    for (var row, i = 0; row = itg_image_repository.tbody.rows[i]; i++) {
      var fid = row.id;
      itg_image_repository.findex[i] = itg_image_repository.fids[fid] = row;
      if (cached) {
        if (itg_image_repository.hasC(row, 'selected')) {
          itg_image_repository.selected[itg_image_repository.vars.lastfid = fid] = row;
          itg_image_repository.selcount++;
        }
      }
      else {
        for (var func, j = 0; func = L[j]; j++) func(row);//invoke list-hook
      }
    }
  }
  if (!itg_image_repository.conf.perm.browse) {
    //itg_image_repository.setMessage(Drupal.t('File browsing is disabled in directory %dir.', token), 'error');
  }
},

//add a file to the list. (having properties name,size,formatted size,width,height,date,formatted date)
fileAdd: function(file) {
  var row, fid = file.name, i = itg_image_repository.findex.length, attr = ['name', 'size', 'width', 'height', 'date'];
  if (!(row = itg_image_repository.fids[fid])) {
    row = itg_image_repository.findex[i] = itg_image_repository.fids[fid] = itg_image_repository.tbody.insertRow(i);
    for (var i in attr) row.insertCell(i).className = attr[i];
  }
  row.cells[0].innerHTML = row.id = fid;
  row.cells[1].innerHTML = file.fsize; row.cells[1].id = file.size;
  row.cells[2].innerHTML = file.width;
  row.cells[3].innerHTML = file.height;
  row.cells[4].innerHTML = file.fdate; row.cells[4].id = file.date;
  itg_image_repository.invoke('list', row);
  if (itg_image_repository.vars.prvfid == fid) itg_image_repository.setPreview(fid);
  if (file.id) itg_image_repository.urlId[itg_image_repository.getURL(fid)] = file.id;
},

//remove a file from the list
fileRemove: function(fid) {
  if (!(row = itg_image_repository.fids[fid])) return;
  itg_image_repository.fileDeSelect(fid);
  itg_image_repository.findex.splice(row.rowIndex, 1);
  $(row).remove();
  delete itg_image_repository.fids[fid];
  if (itg_image_repository.vars.prvfid == fid) itg_image_repository.setPreview();
},

//return a file object containing all properties.
fileGet: function (fid) {
  var row = itg_image_repository.fids[fid];
  var url = itg_image_repository.getURL(fid);
  return row ? {
    name: itg_image_repository.decode(fid),
    url: url,
    size: row.cells[1].innerHTML,
    bytes: row.cells[1].id * 1,
    width: row.cells[2].innerHTML * 1,
    height: row.cells[3].innerHTML * 1,
    date: row.cells[4].innerHTML,
    time: row.cells[4].id * 1,
    id: itg_image_repository.urlId[url] || 0, //file id for newly uploaded files
    relpath: (itg_image_repository.conf.dir == '.' ? '' : itg_image_repository.conf.dir +'/') + fid //rawurlencoded path relative to file directory path.
  } : null;
},

//simulate row click. selection-highlighting
fileClick: function(row, ctrl, shft) {
  if (!row) return;
  var fid = typeof(row) == 'string' ? row : row.id;
  if (ctrl || fid == itg_image_repository.vars.prvfid) {
    itg_image_repository.fileToggleSelect(fid);
  }
  else if (shft) {
    var last = itg_image_repository.lastFid();
    var start = last ? itg_image_repository.fids[last].rowIndex : -1;
    var end = itg_image_repository.fids[fid].rowIndex;
    var step = start > end ? -1 : 1;
    while (start != end) {
      start += step;
      itg_image_repository.fileSelect(itg_image_repository.findex[start].id);
    }
  }
  else {
    for (var fname in itg_image_repository.selected) {
      itg_image_repository.fileDeSelect(fname);
    }
    itg_image_repository.fileSelect(fid);
  }
  //set preview
  itg_image_repository.setPreview(itg_image_repository.selcount == 1 ? itg_image_repository.lastFid() : null);
},

//file select/deselect functions
fileSelect: function (fid) {
  if (itg_image_repository.selected[fid] || !itg_image_repository.fids[fid]) return;
  itg_image_repository.selected[fid] = itg_image_repository.fids[itg_image_repository.vars.lastfid=fid];
  alert( itg_image_repository.selected[fid])
  $(itg_image_repository.selected[fid]).addClass('selected');
  itg_image_repository.selcount++;
},
fileDeSelect: function (fid) {
  if (!itg_image_repository.selected[fid] || !itg_image_repository.fids[fid]) return;
  if (itg_image_repository.vars.lastfid == fid) itg_image_repository.vars.lastfid = null;
  $(itg_image_repository.selected[fid]).removeClass('selected');
  delete itg_image_repository.selected[fid];
  itg_image_repository.selcount--;
},
fileToggleSelect: function (fid) {
  itg_image_repository['file'+ (itg_image_repository.selected[fid] ? 'De' : '') +'Select'](fid);
},

//process file operation form and create operation tabs.
initiateOps: function() {
  itg_image_repository.setHtmlOps();
  itg_image_repository.setUploadOp();//upload
  itg_image_repository.setFileOps();//thumb, delete, resize
},

//process existing html ops.
setHtmlOps: function () {
  $(itg_image_repository.el('ops-list')).children('li').each(function() {
    if (!this.firstChild) return $(this).remove();
    var name = this.id.substr(8);
    var Op = itg_image_repository.ops[name] = {div: itg_image_repository.el('op-content-'+ name), li: itg_image_repository.el('op-item-'+ name)};
    Op.a = Op.li.firstChild;
    Op.title = Op.a.innerHTML;
    $(Op.a).click(function() {itg_image_repository.opClick(name); return false;});
  });
},

//convert upload form to an op.
setUploadOp: function () {
  var el, form = itg_image_repository.el('itg_image_repository-upload-form');
  if (!form) return;
  $(form).ajaxForm(itg_image_repository.uploadSettings()).find('fieldset').each(function() {//clean up fieldsets
    this.removeChild(this.firstChild);
    $(this).after(this.childNodes);
  }).remove();
  // Set html response flag
  el = form.elements['files[itg_image_repository]'];
  if (el && el.files && window.FormData) {
    if (el = form.elements.html_response) {
      el.value = 0;
    }
  } 
  itg_image_repository.opAdd({name: 'upload', title: Drupal.t('Upload'), content: form});//add op
},

//convert fileop form submit buttons to ops.
setFileOps: function () {
  var form = itg_image_repository.el('itg_image_repository-fileop-form');
  if (!form) return;
  $(form.elements.filenames).parent().remove();
  $(form).find('fieldset').each(function() {//remove fieldsets
    var $sbmt = $('input:submit', this);
    if (!$sbmt.length) return;
    var Op = {name: $sbmt.attr('id').substr(5)};
    var func = function() {itg_image_repository.fopSubmit(Op.name); return false;};
    $sbmt.click(func);
    Op.title = $(this).children('legend').remove().text() || $sbmt.val();
    Op.name == 'delete' ? (Op.func = func) : (Op.content = this.childNodes);
    itg_image_repository.opAdd(Op);
  }).remove();
  itg_image_repository.vars.opform = $(form).serialize();//serialize remaining parts.
},

//refresh ops states. enable/disable
refreshOps: function() {
  for (var p in itg_image_repository.conf.perm) {
    if (itg_image_repository.conf.perm[p]) itg_image_repository.opEnable(p);
    else itg_image_repository.opDisable(p);
  }
},

//add a new file operation
opAdd: function (op) {
  var oplist = itg_image_repository.el('ops-list'), opcons = itg_image_repository.el('op-contents');
  var name = op.name || ('op-'+ $(oplist).children('li').length);
  var title = op.title || 'Untitled';
  var Op = itg_image_repository.ops[name] = {title: title};
  if (op.content) {
    Op.div = itg_image_repository.newEl('div');
    $(Op.div).attr({id: 'op-content-'+ name, 'class': 'op-content'}).appendTo(opcons).append(op.content);
  }
  Op.a = itg_image_repository.newEl('a');
  Op.li = itg_image_repository.newEl('li');
  $(Op.a).attr({href: '#', name: name, title: title}).html('<span>' + title +'</span>').click(itg_image_repository.opClickEvent);
  $(Op.li).attr('id', 'op-item-'+ name).append(Op.a).appendTo(oplist);
  Op.func = op.func || itg_image_repository.opVoid;
  return Op;
},

//click event for file operations
opClickEvent: function(e) {
  itg_image_repository.opClick(this.name);
  return false;
},

//void operation function
opVoid: function() {},

//perform op click
opClick: function(name) {
  var Op = itg_image_repository.ops[name], oldop = itg_image_repository.vars.op;
  if (!Op || Op.disabled) {
    return itg_image_repository.setMessage(Drupal.t('You can not perform this operation.'), 'error');
  }
  if (Op.div) {
    if (oldop) {
      var toggle = oldop == name;
      itg_image_repository.opShrink(oldop, toggle ? 'fadeOut' : 'hide');
      if (toggle) return false;
    }
    var left = Op.li.offsetLeft;
    var $opcon = $('#op-contents').css({left: 0});
    $(Op.div).fadeIn('normal', function() {
      setTimeout(function() {
        if (itg_image_repository.vars.op) {
          var $inputs = $('input', itg_image_repository.ops[itg_image_repository.vars.op].div);
          $inputs.eq(0).focus();
          //form inputs become invisible in IE. Solution is as stupid as the behavior.
          $('html').hasClass('ie') && $inputs.addClass('dummyie').removeClass('dummyie');
       }
      });
    });
    var diff = left + $opcon.width() - $('#itg_image_repository-content').width();
    $opcon.css({left: diff > 0 ? left - diff - 1 : left});
    $(Op.li).addClass('active');
    $(itg_image_repository.opCloseLink).fadeIn(300);
    itg_image_repository.vars.op = name;
  }
  Op.func(true);
  return true;
},

//enable a file operation
opEnable: function(name) {
  var Op = itg_image_repository.ops[name];
  if (Op && Op.disabled) {
    Op.disabled = false;
    $(Op.li).show();
  }
},

//disable a file operation
opDisable: function(name) {
  var Op = itg_image_repository.ops[name];
  if (Op && !Op.disabled) {
    Op.div && itg_image_repository.opShrink(name);
    $(Op.li).hide();
    Op.disabled = true;
  }
},

//hide contents of a file operation
opShrink: function(name, effect) {
  if (itg_image_repository.vars.op != name) return;
  var Op = itg_image_repository.ops[name];
  $(Op.div).stop(true, true)[effect || 'hide']();
  $(Op.li).removeClass('active');
  $(itg_image_repository.opCloseLink).hide();
  Op.func(false);
  itg_image_repository.vars.op = null;
},

//navigate to dir
navigate: function(dir) {
  if (itg_image_repository.vars.navbusy || (dir == itg_image_repository.conf.dir && !confirm(Drupal.t('Do you want to refresh the current directory?')))) return;
  var cache = itg_image_repository.vars.cache && dir != itg_image_repository.conf.dir;
  var set = itg_image_repository.navSet(dir, cache);
  if (cache && itg_image_repository.cache[dir]) {//load from the cache
    set.success({data: itg_image_repository.cache[dir]});
    set.complete();
  }
  else $.ajax(set);//live load
},
//ajax navigation settings
navSet: function (dir, cache) {
  $(itg_image_repository.tree[dir].li).addClass('loading');
  itg_image_repository.vars.navbusy = dir;
  return {url: itg_image_repository.ajaxURL('navigate', dir),
  type: 'GET',
  dataType: 'json',
  success: function(response) {
    if (response.data && !response.data.error) {
      if (cache) itg_image_repository.navCache(itg_image_repository.conf.dir, dir);//cache the current dir
      itg_image_repository.navUpdate(response.data, dir);
    }
    itg_image_repository.processResponse(response);
  },
  complete: function () {
    $(itg_image_repository.tree[dir].li).removeClass('loading');
    itg_image_repository.vars.navbusy = null;
  }
  };
},

//update directory using the given data
navUpdate: function(data, dir) {
  var cached = data == itg_image_repository.cache[dir], olddir = itg_image_repository.conf.dir;
  if (cached) data.files.id = 'file-list';
  $(itg_image_repository.FLW).html(data.files);
  itg_image_repository.dirActivate(dir);
  itg_image_repository.dirSubdirs(dir, data.subdirectories);
  $.extend(itg_image_repository.conf.perm, data.perm);
  itg_image_repository.refreshOps();
  itg_image_repository.initiateList(cached);
  itg_image_repository.setPreview(itg_image_repository.selcount == 1 ? itg_image_repository.lastFid() : null);
  itg_image_repository.SBW.scrollTop = 0;
  itg_image_repository.invoke('navigate', data, olddir, cached);
},

//set cache
navCache: function (dir, newdir) {
  var C = itg_image_repository.cache[dir] = {'dir': dir, files: itg_image_repository.el('file-list'), dirsize: itg_image_repository.el('dir-size').innerHTML, perm: $.extend({}, itg_image_repository.conf.perm)};
  C.files.id = 'cached-list-'+ dir;
  itg_image_repository.FW.appendChild(C.files);
  itg_image_repository.invoke('cache', C, newdir);
},

//validate upload form
uploadValidate: function (data, form, options) {
  var path = $('#edit-itg_image_repository').val();
  if (!path) return false;
  if (itg_image_repository.conf.extensions != '*') {
    var ext = path.substr(path.lastIndexOf('.') + 1);
    if ((' '+ itg_image_repository.conf.extensions +' ').indexOf(' '+ ext.toLowerCase() +' ') == -1) {
      return itg_image_repository.setMessage(Drupal.t('Only files with the following extensions are allowed: %files-allowed.', {'%files-allowed': itg_image_repository.conf.extensions}), 'error');
    }
  }
  options.url = itg_image_repository.ajaxURL('upload');//make url contain current dir.
  itg_image_repository.fopLoading('upload', true);
  return true;
},

//settings for upload
uploadSettings: function () {
  return {
    beforeSubmit: itg_image_repository.uploadValidate,
    success: function (response) {
      try{
        itg_image_repository.processResponse($.parseJSON(response));
      } catch(e) {}
    },
    complete: function () {
      itg_image_repository.fopLoading('upload', false);
    },
    resetForm: true,
    dataType: 'text'
  };
},

//validate default ops(delete, thumb, resize)
fopValidate: function(fop) {
  if (!itg_image_repository.validateSelCount(1, itg_image_repository.conf.filenum)) return false;
  switch (fop) {
    case 'delete':
      return confirm(Drupal.t('Delete selected files?'));
    case 'thumb':
      if (!$('input:checked', itg_image_repository.ops['thumb'].div).length) {
        return itg_image_repository.setMessage(Drupal.t('Please select a thumbnail.'), 'error');
      }
      return itg_image_repository.validateImage();
    case 'resize':
      var w = itg_image_repository.el('edit-width').value, h = itg_image_repository.el('edit-height').value;
      var maxDim = itg_image_repository.conf.dimensions.split('x');
      var maxW = maxDim[0]*1, maxH = maxW ? maxDim[1]*1 : 0;
      if (!(/^[1-9][0-9]*$/).test(w) || !(/^[1-9][0-9]*$/).test(h) || (maxW && (maxW < w*1 || maxH < h*1))) {
        return itg_image_repository.setMessage(Drupal.t('Please specify dimensions within the allowed range that is from 1x1 to @dimensions.', {'@dimensions': maxW ? itg_image_repository.conf.dimensions : Drupal.t('unlimited')}), 'error');
      }
      return itg_image_repository.validateImage();
  }

  var func = fop +'OpValidate';
  if (itg_image_repository[func]) return itg_image_repository[func](fop);
  return true;
},

//submit wrapper for default ops
fopSubmit: function(fop) {
  switch (fop) {
    case 'thumb': case 'delete': case 'resize':  return itg_image_repository.commonSubmit(fop);
  }
  var func = fop +'OpSubmit';
  if (itg_image_repository[func]) return itg_image_repository[func](fop);
},

//common submit function shared by default ops
commonSubmit: function(fop) {
  if (!itg_image_repository.fopValidate(fop)) return false;
  itg_image_repository.fopLoading(fop, true);
  $.ajax(itg_image_repository.fopSettings(fop));
},

//settings for default file operations
fopSettings: function (fop) {
  return {url: itg_image_repository.ajaxURL(fop), type: 'POST', dataType: 'json', success: itg_image_repository.processResponse, complete: function (response) {itg_image_repository.fopLoading(fop, false);}, data: itg_image_repository.vars.opform +'&filenames='+ encodeURIComponent(itg_image_repository.serialNames()) +'&jsop='+ fop + (itg_image_repository.ops[fop].div ? '&'+ $('input, select, textarea', itg_image_repository.ops[fop].div).serialize() : '')};
},

//toggle loading state
fopLoading: function(fop, state) {
  var el = itg_image_repository.el('edit-'+ fop), func = state ? 'addClass' : 'removeClass';
  if (el) {
    $(el)[func]('loading').attr('disabled', state);
  }
  else {
    $(itg_image_repository.ops[fop].li)[func]('loading');
    itg_image_repository.ops[fop].disabled = state;
  }
},

//preview a file.
setPreview: function (fid) {
  var row, html = '';
  itg_image_repository.vars.prvfid = fid;
  if (fid && (row = itg_image_repository.fids[fid])) {
    var width = row.cells[2].innerHTML * 1;
    html = itg_image_repository.vars.previewImages && width ? itg_image_repository.imgHtml(fid, width, row.cells[3].innerHTML) : itg_image_repository.decodePlain(fid);
    html = '<a href="#" onclick="itg_image_repository.send(\''+ fid +'\'); return false;" title="'+ (itg_image_repository.vars.prvtitle||'') +'">'+ html +'</a>';
  }
  itg_image_repository.el('file-preview').innerHTML = html;
},

//default file send function. sends the file to the new window.
send: function (fid) {
  fid && window.open(itg_image_repository.getURL(fid));
},

//add an operation for an external application to which the files are send.
setSendTo: function (title, func) {
  itg_image_repository.send = function (fid) { fid && func(itg_image_repository.fileGet(fid), window);};
  var opFunc = function () {
    if (itg_image_repository.selcount != 1) return itg_image_repository.setMessage(Drupal.t('Please select a file.'), 'error');
    itg_image_repository.send(itg_image_repository.vars.prvfid);
  };
  itg_image_repository.vars.prvtitle = title;
  return itg_image_repository.opAdd({name: 'sendto', title: title, func: opFunc});
},

//move initial page messages into log
prepareMsgs: function () {
  var msgs;
  if (msgs = itg_image_repository.el('itg_image_repository-messages')) {
    $('>div', msgs).each(function (){
      var type = this.className.split(' ')[1];
      var li = $('>ul li', this);
      if (li.length) li.each(function () {itg_image_repository.setMessage(this.innerHTML, type);});
      else itg_image_repository.setMessage(this.innerHTML, type);
    });
    $(msgs).remove();
  }
},

//insert log message
setMessage: function (msg, type) {
  var $box = $(itg_image_repository.msgBox);
  var logs = itg_image_repository.el('log-messages') || $(itg_image_repository.newEl('div')).appendTo('#help-box-content').before('<h4>'+ Drupal.t('Log messages') +':</h4>').attr('id', 'log-messages')[0];
  var msg = '<div class="message '+ (type || 'status') +'">'+ msg +'</div>';
  $box.queue(function() {
    $box.css({opacity: 0, display: 'block'}).html(msg);
    $box.dequeue();
  });
  var q = $box.queue().length, t = itg_image_repository.vars.msgT || 1000;
  q = q < 2 ? 1 : q < 3 ? 0.8 : q < 4 ? 0.7 : 0.4;//adjust speed with respect to queue length
  $box.fadeTo(600 * q, 1).fadeTo(t * q, 1).fadeOut(400 * q);
  $(logs).append(msg);
  return false;
},

//invoke hooks
invoke: function (hook) {
  var i, args, func, funcs;
  if ((funcs = itg_image_repository.hooks[hook]) && funcs.length) {
    (args = $.makeArray(arguments)).shift();
    for (i = 0; func = funcs[i]; i++) func.apply(this, args);
  }
},

//process response
processResponse: function (response) {
  if (response.data) itg_image_repository.resData(response.data);
  if (response.messages) itg_image_repository.resMsgs(response.messages);
},

//process response data
resData: function (data) {
  var i, added, removed;
  if (added = data.added) {
    var cnt = itg_image_repository.findex.length;
    for (i in added) {//add new files or update existing
      itg_image_repository.fileAdd(added[i]);
    }
    if (added.length == 1) {//if it is a single file operation
      itg_image_repository.highlight(added[0].name);//highlight
    }
    if (itg_image_repository.findex.length != cnt) {//if new files added, scroll to bottom.
      $(itg_image_repository.SBW).animate({scrollTop: itg_image_repository.SBW.scrollHeight}).focus();
    }
  }
  if (removed = data.removed) for (i in removed) {
    itg_image_repository.fileRemove(removed[i]);
  }
  itg_image_repository.conf.dirsize = data.dirsize;
  itg_image_repository.updateStat();
},

//set response messages
resMsgs: function (msgs) {
  for (var type in msgs) for (var i in msgs[type]) {
    itg_image_repository.setMessage(msgs[type][i], type);
  }
},

//return img markup
imgHtml: function (fid, width, height) {
  return '<img src="'+ itg_image_repository.getURL(fid) +'" width="'+ width +'" height="'+ height +'" alt="'+ itg_image_repository.decodePlain(fid) +'" />';
},

//check if the file is an image
isImage: function (fid) {
  return itg_image_repository.fids[fid].cells[2].innerHTML * 1;
},

//find the first non-image in the selection
getNonImage: function (selected) {
  for (var fid in selected) {
    if (!itg_image_repository.isImage(fid)) return fid;
  }
  return false;
},

//validate current selection for images
validateImage: function () {
  var nonImg = itg_image_repository.getNonImage(itg_image_repository.selected);
  return nonImg ? itg_image_repository.setMessage(Drupal.t('%filename is not an image.', {'%filename': itg_image_repository.decode(nonImg)}), 'error') : true;
},

//validate number of selected files
validateSelCount: function (Min, Max) {
  if (Min && itg_image_repository.selcount < Min) {
    return itg_image_repository.setMessage(Min == 1 ? Drupal.t('Please select a file.') : Drupal.t('You must select at least %num files.', {'%num': Min}), 'error');
  }
  if (Max && Max < itg_image_repository.selcount) {
    return itg_image_repository.setMessage(Drupal.t('You are not allowed to operate on more than %num files.', {'%num': Max}), 'error');
  }
  return true;
},

//update file count and dir size
updateStat: function () {
  itg_image_repository.el('file-count').innerHTML = itg_image_repository.findex.length;
  itg_image_repository.el('dir-size').innerHTML = itg_image_repository.conf.dirsize;
},

//serialize selected files. return fids with a colon between them
serialNames: function () {
  var str = '';
  for (var fid in itg_image_repository.selected) {
    str += ':'+ fid;
  }
  return str.substr(1);
},

//get file url. re-encode & and # for mod rewrite
getURL: function (fid) {
  var path = (itg_image_repository.conf.dir == '.' ? '' : itg_image_repository.conf.dir +'/') + fid;
  return itg_image_repository.conf.furl + (itg_image_repository.conf.modfix ? path.replace(/%(23|26)/g, '%25$1') : path);
},

//el. by id
el: function (id) {
  return document.getElementById(id);
},

//find the latest selected fid
lastFid: function () {
  if (itg_image_repository.vars.lastfid) return itg_image_repository.vars.lastfid;
  for (var fid in itg_image_repository.selected);
  return fid;
},

//create ajax url
ajaxURL: function (op, dir) {
  return itg_image_repository.conf.url + (itg_image_repository.conf.clean ? '?' :'&') +'jsop='+ op +'&dir='+ (dir||itg_image_repository.conf.dir);
},

//fast class check
hasC: function (el, name) {
  return el.className && (' '+ el.className +' ').indexOf(' '+ name +' ') != -1;
},

//highlight a single file
highlight: function (fid) {
  if (itg_image_repository.vars.prvfid) itg_image_repository.fileClick(itg_image_repository.vars.prvfid);
  itg_image_repository.fileClick(fid);
},

//process a row
processRow: function (row) {
  row.cells[0].innerHTML = '<span>' + itg_image_repository.decodePlain(row.id) + '</span>';
  row.onmousedown = function(e) {
    var e = e||window.event;
    itg_image_repository.fileClick(this, e.ctrlKey, e.shiftKey);
    return !(e.ctrlKey || e.shiftKey);
  };
  row.ondblclick = function(e) {
    itg_image_repository.send(this.id);
    return false;
  };
},

//decode urls. uses unescape. can be overridden to use decodeURIComponent
decode: function (str) {
  try {
    return decodeURIComponent(str);
  } catch(e) {}
  return str;
},

//decode and convert to plain text
decodePlain: function (str) {
  return Drupal.checkPlain(itg_image_repository.decode(str));
},

//global ajax error function
ajaxError: function (e, response, settings, thrown) {
  itg_image_repository.setMessage(Drupal.ajaxError(response, settings.url).replace(/\n/g, '<br />'), 'error');
},

//convert button elements to standard input buttons
convertButtons: function(form) {
  $('button:submit', form).each(function(){
    $(this).replaceWith('<input type="submit" value="'+ $(this).text() +'" name="'+ this.name +'" class="form-submit" id="'+ this.id +'" />');
  });
},

//create element
newEl: function(name) {
  return document.createElement(name);
},

//scroll syncronization for section headers
syncScroll: function(scrlEl, fixel, bottom) {
  var $fixel = $(fixel);
  var prop = bottom ? 'bottom' : 'top';
  var factor = bottom ? -1 : 1;
  var syncScrl = function(el) {
    $fixel.css(prop, factor * el.scrollTop);
  }
  $(scrlEl).scroll(function() {
    var el = this;
    syncScrl(el);
    setTimeout(function() {
      syncScrl(el);
    });
  });
},

//get UI ready. provide backward compatibility.
updateUI: function() {
  //file urls.
  var furl = itg_image_repository.conf.furl, isabs = furl.indexOf('://') > -1;
  var absurls = itg_image_repository.conf.absurls = itg_image_repository.vars.absurls || itg_image_repository.conf.absurls;
  var host = location.host;
  var baseurl = location.protocol + '//' + host;
  if (furl.charAt(furl.length - 1) != '/') {
    furl = itg_image_repository.conf.furl = furl + '/';
  }
  itg_image_repository.conf.modfix = itg_image_repository.conf.clean && furl.indexOf(host + '/system/') > -1;
  if (absurls && !isabs) {
    itg_image_repository.conf.furl = baseurl + furl;
  }
  else if (!absurls && isabs && furl.indexOf(baseurl) == 0) {
    itg_image_repository.conf.furl = furl.substr(baseurl.length);
  }
  //convert button elements to input elements.
  itg_image_repository.convertButtons(itg_image_repository.FW);
  //ops-list
  $('#ops-list').removeClass('tabs secondary').addClass('clear-block clearfix');
  itg_image_repository.opCloseLink = $(itg_image_repository.newEl('a')).attr({id: 'op-close-link', href: '#', title: Drupal.t('Close')}).click(function() {
    itg_image_repository.vars.op && itg_image_repository.opClick(itg_image_repository.vars.op);
    return false;
  }).appendTo('#op-contents')[0];
  //navigation-header
  if (!$('#navigation-header').length) {
    $(itg_image_repository.NW).children('.navigation-text').attr('id', 'navigation-header').wrapInner('<span></span>');
  }
  //log
  $('#log-prv-wrapper').before($('#log-prv-wrapper > #preview-wrapper')).remove();
  $('#log-clearer').remove();
  //content resizer
  $('#content-resizer').remove();
  //message-box
  itg_image_repository.msgBox = itg_image_repository.el('message-box') || $(itg_image_repository.newEl('div')).attr('id', 'message-box').prependTo('#itg_image_repository-content')[0];
  //create help tab
  var $hbox = $('#help-box');
  $hbox.is('a') && $hbox.replaceWith($(itg_image_repository.newEl('div')).attr('id', 'help-box').append($hbox.children()));
  itg_image_repository.hooks.load.push(function() {
    itg_image_repository.opAdd({name: 'help', title: $('#help-box-title').remove().text(), content: $('#help-box').show()});
  });
  //add ie classes
  itg_image_repository.ie && $('html').addClass('ie') && itg_image_repository.ie < 8 && $('html').addClass('ie-7');
  // enable box view for file list
  itg_image_repository.vars.boxW && itg_image_repository.boxView();
  //scrolling file list
  itg_image_repository.syncScroll(itg_image_repository.SBW, '#file-header-wrapper');
  itg_image_repository.syncScroll(itg_image_repository.SBW, '#dir-stat', true);
  //scrolling directory tree
  itg_image_repository.syncScroll(itg_image_repository.NW, '#navigation-header');
}

};

(function(){
  
  jQuery('.div-upload-img').live('click',function()
  {
      
    jQuery('.div-upload-img').addClass('active');
     jQuery('#search-preview').hide();
     jQuery('.div-search-img').removeClass('active');
    jQuery('#forms-wrapper').show();
    jQuery('#imce-search-form').hide();
    jQuery('#itg-image-repository-upload-form').show();
    jQuery('#itg-image-repository-filesearch-form').hide();
    jQuery('.dz-details').trigger('click');
    jQuery('#file-preview').hide();
  })
  
  jQuery('.div-search-img').live('click',function()
  {
    jQuery('.div-upload-img').removeClass('active');
    jQuery('.div-search-img').addClass('active');
    jQuery('#forms-wrapper').show();
    jQuery('#imce-search-form').show();
     jQuery('#file-preview').hide();
     jQuery('#search-preview').show();
    jQuery('#itg-image-repository-upload-form').hide();
    jQuery('#itg-image-repository-filesearch-form').show();
  })
 
  
})(jQuery);


//initiate
$(document).ready(itg_image_repository.initiate);

})(jQuery);

 