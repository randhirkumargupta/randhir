/*
 Election Block Refresh JS 
 */

function refresh_election_blocks(jsonUrl, widget_name, delta, refresh_time) {
    if (jsonUrl === undefined || widget_name === undefined) {
        return;
    }
    jQuery.ajax({
        type: "GET",
        url: jsonUrl,
        cache: true,
        crossDomain: true,
        success: function (data) {
            if (data !== undefined && data !== '') {
                var _widget_name = widget_name.replace(/_/g, "-");
                var _delta = delta.replace(/_/g, "-");
                var replacewith = "#block-"+_widget_name + "-" + _delta;
                if(jQuery(replacewith) !== undefined){
                    jQuery(replacewith).replaceWith(data);
                }                
            }            
        },
        error: function (error) {
            console.log(error, 'Refresh Block error');
        }
    });
    if(refresh_time === undefined){
        refresh_time = 60000;
    }
    setTimeout(function(){
       refresh_election_blocks(jsonUrl, widget_name, delta, refresh_time); 
    }, refresh_time);
}


function refresh_election_view_blocks(jsonUrl, viewid, view_display_id, refresh_time) {
    if (jsonUrl === undefined || viewid === undefined || view_display_id === undefined) {
        return;
    }
    jQuery.ajax({
        type: "GET",
        url: jsonUrl,
        cache: true,
        crossDomain: true,
        success: function (data) {
            if (data !== undefined && data !== '') {
                var replacewith = ".view-id-"+viewid + ".view-display-id-" + view_display_id;
                if(jQuery(replacewith) !== undefined){
                    jQuery(replacewith).replaceWith(data);
                }                
            }            
        },
        error: function (error) {
            console.log(error, 'Refresh View Block error');
        }
    });
}
