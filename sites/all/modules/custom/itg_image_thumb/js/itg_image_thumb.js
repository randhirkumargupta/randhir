(function ($) {
    
Drupal.behaviors.itg_image_thumb= {
attach: function (context, settings) {
    
$('#edit-field-story-resize-extra-large-und-yes', context).click(function (event) {
event.preventDefault();

//get form value in serialize array      
var frm=$("#story-node-form").serializeArray();

//console.log(frm);

//fetch position of image element from array
var fid =frm[25].value;

//console.log(fid);
//passing the value using 'POST' method

var dt = 'fid='+fid;
var base_url = settings.itg_image_thumb.settings.base_url; 

$.ajax({
'url':base_url + '/itgimagethumb-ajax',
'data': dt,
'type': 'POST',
success: function(data)
{
 
}
});
//ajax close
}

//else close
);
}
};
})(jQuery);
