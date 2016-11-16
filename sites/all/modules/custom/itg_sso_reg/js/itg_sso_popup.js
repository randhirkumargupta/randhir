/*
 * @file itg_sso_popup.js
 * Contains all functionality related to login
 */


function Go(windowWidth, windowHeight, windowOuterHeight, wname, features, site_url, pass_arg) {

    var centerLeft = parseInt((window.screen.availWidth - windowWidth) / 2);
    var centerTop = parseInt(((window.screen.availHeight - windowHeight) / 2) - windowOuterHeight);
    var windowFeatures = 'width=' + windowWidth + ',height=' + windowHeight + ',left=' + centerLeft + ',top=' + centerTop + misc_features;
    var misc_features;
    if (features) {
        misc_features = ', ' + features;
    }
    else {
        misc_features = ', status=no, location=no, scrollbars=yes, resizable=yes';
    }
    
    if (pass_arg){
        pass_arg = pass_arg;
    }
    var child = window.open("http://"+site_url+ pass_arg, wname, windowFeatures);

    var leftDomain = false;
    var interval = setInterval(function () {
        try {
            if (child.document.domain === document.domain)
            {

                if (leftDomain && child.document.readyState === "complete")
                {
                    // we're here when the child window returned to our domain
                    clearInterval(interval);
                    alert("returned: " + child.document.URL);
                    child.postMessage({message: "requestResult"}, "*");
                }
            }
            else {
                // this code should never be reached, 
                // as the x-site security check throws
                // but just in case
                leftDomain = true;
            }
        }
        catch (e) {
            // we're here when the child window has been navigated away or closed
            if (child.closed) {
                clearInterval(interval);
                window.location.reload(true);
                return;
            }
            // navigated to another domain  
            leftDomain = true;
        }
    }, 10);
}


function CenterWindow(windowWidth, windowHeight, windowOuterHeight, url, wname, features) {
    var centerLeft = parseInt((window.screen.availWidth - windowWidth) / 2);
    var centerTop = parseInt(((window.screen.availHeight - windowHeight) / 2) - windowOuterHeight);
 
    var misc_features;
    if (features) {
      misc_features = ', ' + features;
    }
    else {
      misc_features = ', status=no, location=no, scrollbars=yes, resizable=yes';
    }
    var windowFeatures = 'width=' + windowWidth + ',height=' + windowHeight + ',left=' + centerLeft + ',top=' + centerTop + misc_features;
    var win = window.open(url, wname, windowFeatures);
    win.focus();
    return win;
  }