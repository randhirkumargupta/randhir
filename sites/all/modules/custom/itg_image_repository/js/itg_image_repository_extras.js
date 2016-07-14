
/*
 * @file itg_image_repository_extras.js
 */

/*
 * @file itg_image_repository_extras.js
 * Contains all itg image repository
 */
//This pack implemets: keyboard shortcuts, file sorting, resize bars, and inline thumbnail preview.

(function($) {

// add scale calculator for resizing.
itg_image_repository.hooks.load.push(function () {
  $('#edit-width, #edit-height').focus(function () {
    var fid, r, w, isW, val;
    if (fid = itg_image_repository.vars.prvfid) {
      isW = this.id == 'edit-width', val =  itg_image_repository.el(isW ? 'edit-height' : 'edit-width').value*1;
      if (val && (w = itg_image_repository.isImage(fid)) && (r = itg_image_repository.fids[fid].cells[3].innerHTML*1 / w))
        this.value = Math.round(isW ? val/r : val*r);
    }
  });
});

// Shortcuts
var F = null;
itg_image_repository.initiateShortcuts = function () {
  $(itg_image_repository.NW).attr('tabindex', '0').keydown(function (e) {
    if (F = itg_image_repository.dirKeys['k'+ e.keyCode]) return F(e);
  });
  $(itg_image_repository.FLW).attr('tabindex', '0').keydown(function (e) {
    if (F = itg_image_repository.fileKeys['k'+ e.keyCode]) return F(e);
  }).focus();
};

//shortcut key-function pairs for directories
itg_image_repository.dirKeys = {
  k35: function (e) {//end-home. select first or last dir
    var L = itg_image_repository.tree['.'].li;
    if (e.keyCode == 35) while (itg_image_repository.hasC(L, 'expanded')) L = L.lastChild.lastChild;
    $(L.childNodes[1]).click().focus();
  },
  k37: function (e) {//left-right. collapse-expand directories.(right may also move focus on files)
    var L, B = itg_image_repository.tree[itg_image_repository.conf.dir], right = e.keyCode == 39;
    if (B.ul && (right ^ itg_image_repository.hasC(L = B.li, 'expanded')) ) $(L.firstChild).click();
    else if (right) $(itg_image_repository.FLW).focus();
  },
  k38: function (e) {//up. select the previous directory
    var B = itg_image_repository.tree[itg_image_repository.conf.dir];
    if (L = B.li.previousSibling) {
      while (itg_image_repository.hasC(L, 'expanded')) L = L.lastChild.lastChild;
      $(L.childNodes[1]).click().focus();
    }
    else if ((L = B.li.parentNode.parentNode) && L.tagName == 'LI') $(L.childNodes[1]).click().focus();
  },
  k40: function (e) {//down. select the next directory
    var B = itg_image_repository.tree[itg_image_repository.conf.dir], L = B.li, U = B.ul;
    if (U && itg_image_repository.hasC(L, 'expanded')) $(U.firstChild.childNodes[1]).click().focus();
    else do {if (L.nextSibling) return $(L.nextSibling.childNodes[1]).click().focus();
    }while ((L = L.parentNode.parentNode).tagName == 'LI');
  }
};
//add equal keys
itg_image_repository.dirKeys.k36 = itg_image_repository.dirKeys.k35;
itg_image_repository.dirKeys.k39 = itg_image_repository.dirKeys.k37;

//shortcut key-function pairs for files
itg_image_repository.fileKeys = {
  k38: function (e) {//up-down. select previous-next row
    var fid = itg_image_repository.lastFid(), i = fid ? itg_image_repository.fids[fid].rowIndex+e.keyCode-39 : 0;
    itg_image_repository.fileClick(itg_image_repository.findex[i], e.ctrlKey, e.shiftKey);
  },
  k35: function (e) {//end-home. select first or last row
    itg_image_repository.fileClick(itg_image_repository.findex[e.keyCode == 35 ? itg_image_repository.findex.length-1 : 0], e.ctrlKey, e.shiftKey);
  },
  k13: function (e) {//enter-insert. send file to external app.
    itg_image_repository.send(itg_image_repository.vars.prvfid);
    return false;
  },
  k37: function (e) {//left. focus on directories
    $(itg_image_repository.tree[itg_image_repository.conf.dir].a).focus();
  },
  k65: function (e) {//ctrl+A to select all
    if (e.ctrlKey && itg_image_repository.findex.length) {
      var fid = itg_image_repository.findex[0].id;
      itg_image_repository.selected[fid] ? (itg_image_repository.vars.lastfid = fid) : itg_image_repository.fileClick(fid);//select first row
      itg_image_repository.fileClick(itg_image_repository.findex[itg_image_repository.findex.length-1], false, true);//shift+click last row
      return false;
    }
  }
};
//add equal keys
itg_image_repository.fileKeys.k40 = itg_image_repository.fileKeys.k38;
itg_image_repository.fileKeys.k36 = itg_image_repository.fileKeys.k35;
itg_image_repository.fileKeys.k45 = itg_image_repository.fileKeys.k13;
//add default operation keys. delete, R(esize), T(humbnails), U(pload)
$.each({k46: 'delete', k82: 'resize', k84: 'thumb', k85: 'upload'}, function (k, op) {
  itg_image_repository.fileKeys[k] = function (e) {
    if (itg_image_repository.ops[op] && !itg_image_repository.ops[op].disabled) itg_image_repository.opClick(op);
  };
});

//prepare column sorting
itg_image_repository.initiateSorting = function() {
  //add cache hook. cache the old directory's sort settings before the new one replaces it.
  itg_image_repository.hooks.cache.push(function (cache, newdir) {
    cache.cid = itg_image_repository.vars.cid, cache.dsc = itg_image_repository.vars.dsc;
  });
  //add navigation hook. refresh sorting after the new directory content is loaded.
  itg_image_repository.hooks.navigate.push(function (data, olddir, cached) {
    cached ? itg_image_repository.updateSortState(data.cid, data.dsc) : itg_image_repository.firstSort();
  });
  itg_image_repository.vars.cid = itg_image_repository.cookie('itg_image_repositorycid') * 1;
  itg_image_repository.vars.dsc = itg_image_repository.cookie('itg_image_repositorydsc') * 1;
  itg_image_repository.cols = itg_image_repository.el('file-header').rows[0].cells;
  $(itg_image_repository.cols).click(function () {itg_image_repository.columnSort(this.cellIndex, itg_image_repository.hasC(this, 'asc'));});
  itg_image_repository.firstSort();
};

//sort the list for the first time
itg_image_repository.firstSort = function() {
  itg_image_repository.columnSort(itg_image_repository.vars.cid, itg_image_repository.vars.dsc);
};

//sort file list according to column index.
itg_image_repository.columnSort = function(cid, dsc) {
  if (itg_image_repository.findex.length < 2) return;
  var func = 'sort'+ (cid == 0 ? 'Str' : 'Num') + (dsc ? 'Dsc' : 'Asc');
  var prop = cid == 2 || cid == 3 ? 'innerHTML' : 'id';
  //sort rows
  itg_image_repository.findex.sort(cid ? function(r1, r2) {return itg_image_repository[func](r1.cells[cid][prop], r2.cells[cid][prop])} : function(r1, r2) {return itg_image_repository[func](r1.id, r2.id)});
  //insert sorted rows
  for (var row, i=0; row = itg_image_repository.findex[i]; i++) {
    itg_image_repository.tbody.appendChild(row);
  }
  itg_image_repository.updateSortState(cid, dsc);
};

//update column states
itg_image_repository.updateSortState = function(cid, dsc) {
  $(itg_image_repository.cols[itg_image_repository.vars.cid]).removeClass(itg_image_repository.vars.dsc ? 'desc' : 'asc');
  $(itg_image_repository.cols[cid]).addClass(dsc ? 'desc' : 'asc');
  itg_image_repository.vars.cid != cid && itg_image_repository.cookie('itg_image_repositorycid', itg_image_repository.vars.cid = cid);
  itg_image_repository.vars.dsc != dsc && itg_image_repository.cookie('itg_image_repositorydsc', (itg_image_repository.vars.dsc = dsc) ? 1 : 0);
};

//sorters
itg_image_repository.sortStrAsc = function(a, b) {return a.toLowerCase() < b.toLowerCase() ? -1 : 1;};
itg_image_repository.sortStrDsc = function(a, b) {return itg_image_repository.sortStrAsc(b, a);};
itg_image_repository.sortNumAsc = function(a, b) {return a-b;};
itg_image_repository.sortNumDsc = function(a, b) {return b-a};

//set resizers for resizable areas and recall previous dimensions
itg_image_repository.initiateResizeBars = function () {
  itg_image_repository.setResizer('#navigation-resizer', 'X', itg_image_repository.NW, null, 1, function(p1, p2, m) {
    p1 != p2 && itg_image_repository.cookie('itg_image_repositorynww', p2);
  });
  itg_image_repository.setResizer('#browse-resizer', 'Y', itg_image_repository.BW, itg_image_repository.PW, 50, function(p1, p2, m) {
    p1 != p2 && itg_image_repository.cookie('itg_image_repositorybwh', p2);
  });
  itg_image_repository.recallDimensions();
};

//set a resize bar
itg_image_repository.setResizer = function (resizer, axis, area1, area2, Min, callback) {
  var opt = axis == 'X' ? {pos: 'pageX', func: 'width'} : {pos: 'pageY', func: 'height'};
  var Min = Min || 0;
  var $area1 = $(area1), $area2 = area2 ? $(area2) : null, $doc = $(document);
  $(resizer).mousedown(function(e) {
    var pos = e[opt.pos];
    var end = start = $area1[opt.func]();
    var Max = $area2 ? start + $area2[opt.func]() : 1200;
    var drag = function(e) {
      end = Math.min(Max - Min, Math.max(start + e[opt.pos] - pos, Min));
      $area1[opt.func](end);
      $area2 && $area2[opt.func](Max - end);
      return false;
    };
    var undrag = function(e) {
      $doc.unbind('mousemove', drag).unbind('mouseup', undrag);
      callback && callback(start, end, Max);
    };
    $doc.mousemove(drag).mouseup(undrag);
    return false;
  });
};

//get&set area dimensions of the last session from the cookie
itg_image_repository.recallDimensions = function() {
  var $body = $(document.body);
  if (!$body.hasClass('itg_image_repository')) return;
  //row heights
  itg_image_repository.recallHeights(itg_image_repository.cookie('itg_image_repositorybwh') * 1);
  $(window).resize(function(){itg_image_repository.recallHeights()});
  //navigation wrapper
  var nwOldWidth = itg_image_repository.cookie('itg_image_repositorynww') * 1;
  nwOldWidth && $(itg_image_repository.NW).width(Math.min(nwOldWidth, $body.width() - 10));
};

//set row heights with respect to window height
itg_image_repository.recallHeights = function(bwFixedHeight) {
  //window & body dimensions
  var winHeight = window.opera ? window.innerHeight : $(window).height();
  var bodyHeight = $(document.body).outerHeight(true);
  var diff = winHeight - bodyHeight;
  var bwHeight = $(itg_image_repository.BW).height(), pwHeight = $(itg_image_repository.PW).height();
  if (bwFixedHeight) {
    //row heights
    diff -= bwFixedHeight - bwHeight;
    bwHeight = bwFixedHeight;
    pwHeight += diff;
  }
  else {
    diff = parseInt(diff/2);
    bwHeight += diff;
    pwHeight += diff;
  }
  $(itg_image_repository.BW).height(bwHeight);
  $(itg_image_repository.PW).height(pwHeight);
};

//cookie get & set
itg_image_repository.cookie = function (name, value) {
  if (typeof(value) == 'undefined') {//get
    return document.cookie ? itg_image_repository.decode((document.cookie.match(new RegExp('(?:^|;) *' + name + '=([^;]*)(?:;|$)')) || ['', ''])[1].replace(/\+/g, '%20')) : '';
  }
  document.cookie = name +'='+ encodeURIComponent(value) +'; expires='+ (new Date(new Date() * 1 + 15 * 86400000)).toUTCString() +'; path=' + Drupal.settings.basePath + 'itg_image_repository';//set
};

//view thumbnails(smaller than tMaxW x tMaxH) inside the rows.
//Large images can also be previewed by setting itg_image_repository.vars.prvstyle to a valid image style(imagecache preset)
itg_image_repository.thumbRow = function (row) {
  var w = row.cells[2].innerHTML * 1;
  if (!w) return;
  var h = row.cells[3].innerHTML * 1;
  if (itg_image_repository.vars.tMaxW < w || itg_image_repository.vars.tMaxH < h) {
    if (!itg_image_repository.vars.prvstyle || itg_image_repository.conf.dir.indexOf('styles') == 0) return;
    var img = new Image();
    img.src = itg_image_repository.imagestyleURL(itg_image_repository.getURL(row.id), itg_image_repository.vars.prvstyle);
    img.className = 'imagestyle-' + itg_image_repository.vars.prvstyle;
  }
  else {
    var prvH = h, prvW = w;
    if (itg_image_repository.vars.prvW < w || itg_image_repository.vars.prvH < h) {
      if (h < w) {
        prvW = itg_image_repository.vars.prvW;
        prvH = prvW*h/w;
      }
      else {
        prvH = itg_image_repository.vars.prvH;
        prvW = prvH*w/h;
      }
    }
    var img = new Image(prvW, prvH);
    img.src = itg_image_repository.getURL(row.id);
  }
  var cell = row.cells[0];
  cell.insertBefore(img, cell.firstChild);
};

//convert a file URL returned by itg_image_repository.getURL() to an image style(imagecache preset) URL
itg_image_repository.imagestyleURL = function (url, stylename) {
  var len = itg_image_repository.conf.furl.length - 1;
  return url.substr(0, len) + '/styles/' + stylename + '/' + itg_image_repository.conf.scheme + url.substr(len);
};

// replace table view with box view for file list
itg_image_repository.boxView = function () {
  var w = itg_image_repository.vars.boxW, h = itg_image_repository.vars.boxH;
  if (!w || !h || itg_image_repository.ie && itg_image_repository.ie < 8) return;
  var $body = $(document.body);
  var toggle = function() {
    $body.toggleClass('box-view');
    // refresh dom. required by all except FF.
    $('#file-list').appendTo(itg_image_repository.FW).appendTo(itg_image_repository.FLW);
  };
  $body.append('<style type="text/css">.box-view #file-list td.name {width: ' + w + 'px;height: ' + h + 'px;} .box-view #file-list td.name span {width: ' + w + 'px;word-wrap: normal;text-overflow: ellipsis;}</style>');
  itg_image_repository.hooks.load.push(function() {
    toggle();
    itg_image_repository.SBW.scrollTop = 0;
    itg_image_repository.opAdd({name: 'changeview', title: Drupal.t('Change view'), func: toggle});
  });
  itg_image_repository.hooks.list.push(itg_image_repository.boxViewRow);
};

// process a row for box view. include all data in box title.
itg_image_repository.boxViewRow = function (row) {
  var s = ' | ', w = row.cells[2].innerHTML * 1, dim = w ? s + w + 'x' + row.cells[3].innerHTML * 1 : '';
  row.cells[0].title = itg_image_repository.decode(row.id) + s + row.cells[1].innerHTML + (dim) + s + row.cells[4].innerHTML;
};

})(jQuery);