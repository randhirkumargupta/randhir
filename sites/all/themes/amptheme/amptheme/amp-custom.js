    
    window.onload = function (event) {
    event.stopPropagation(true);
    var get_actual_uri_param = getUrlVars();
    if (get_actual_uri_param[0].length > 0 && get_actual_uri_param[0] == 'amp') {
        var uri = window.location.href;
        var remove_amp = uri.replace("?amp", "");
        var remove_http = remove_amp.replace("http://", "");
        var other_string = remove_http.split('/');
        var st_domain = other_string.splice(0, 1);
        var res4 = 'http://' + st_domain + '/amp/' + other_string.join('/');
        window.location = res4;
    }
 }

function getUrlVars()
{
    var vars = [], hash;
    var hashes = window.location.href.slice(window.location.href.indexOf('?') + 1).split('&');
    for (var i = 0; i < hashes.length; i++)
    {
        hash = hashes[i].split('=');
        vars.push(hash[0]);
        vars[hash[0]] = hash[1];
    }
    return vars;
}