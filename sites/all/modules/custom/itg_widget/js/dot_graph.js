/**
 * @file itg_widget.ipl.js
 * This is used for widgets setting
 */


function hmelectioninner(a,x,chart_path){
      if(x=1) {
      var b=a;
      }

      var stateURL = chart_path;
      //console.log(stateURL);
      jQuery.ajax({
       type: "GET",
       url: stateURL,
       dataType: "jsonp",
       cache: "true",
       crossDomain: true,
       jsonpCallback: 'ehmfhd_'+a.replace("-",""),
       success: function (data1){
         jQuery("#fhs-"+a).html(data1.loksabha.htm);

     }});

      setTimeout(function(){hmelectioninner(b,2,chart_path) },3000);
}

function hmelection(a,type,json_path,chart_path){
         var b =a;
         var feedURL = json_path;
         //console.log(feedURL);
         jQuery.ajax({
            type: "GET",
            url: feedURL,
            dataType: "jsonp",
            cache: "true",
            crossDomain: true,
            jsonpCallback: 'ehmfh_'+a.replace("-",""),
            success: function (data){
             //console.log(data.loksabha.htm);
             jQuery("#hmelect-"+a).html(data.loksabha.htm);
              //console.log("#hmelect-"+data.loksabha.htm);
              hmelectioninner(b, 1,chart_path);
            }
         });
}
