/*
 Election constituency js 
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
                var _widget_name = widget_name.replace("_", "-");
                var _delta = delta.replace("_", "-");
                var replacewith = "#block-"+_widget_name+_delta;
                jQuery(replacewith).replaceWith(data);
            }            
        },
        error: function (error) {
            console.log(error, 'Refresh Block error');
        }
    });
    if(refresh_time === undefined){
        refresh_time = 30000;
    }
    setTimeout(function(){
       refresh_election_blocks(jsonUrl, widget_name, delta, refresh_time); 
    }, refresh_time);
}
