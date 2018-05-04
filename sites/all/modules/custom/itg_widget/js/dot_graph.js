/**
 * @file dot_graph.js
 * This is used for drawing the dot graph in election template
 */

function hmelectioninner(a, x, chart_path, refresh_time) {
    if (x = 1) {
        var b = a;
    }

    var stateURL = chart_path;
    jQuery.ajax({
        type: "GET",
        url: stateURL,
        dataType: "jsonp",
        cache: "true",
        crossDomain: true,
        jsonpCallback: 'ehmfhd_' + a.replace("-", ""),
        success: function (data1) {
			var loksabha_html = "<script> $ = jQuery;</script>";
			loksabha_html += data1.loksabha.htm;			
            jQuery("#fhs-" + a).html(loksabha_html);

        }});
    if(refresh_time === undefined){refresh_time = 3000;}
    setTimeout(function () {
        hmelectioninner(b, 2, chart_path, refresh_time)
    }, parseInt(refresh_time));
}

function hmelection(a, type, json_path, chart_path, refresh_time) {
    var b = a;
    var feedURL = json_path;
    jQuery.ajax({
        type: "GET",
        url: feedURL,
        dataType: "jsonp",
        cache: "true",
        crossDomain: true,
        jsonpCallback: 'ehmfh_' + a.replace("-", ""),
        success: function (data) {
            //console.log(refresh_time, 'refresh_time11');
            jQuery("#hmelect-" + a).html(data.loksabha.htm);
            //console.log("#hmelect-"+data.loksabha.htm);
            hmelectioninner(b, 1, chart_path, refresh_time);
        }
    });
}
