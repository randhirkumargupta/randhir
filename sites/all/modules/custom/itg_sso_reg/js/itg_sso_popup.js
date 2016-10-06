/*
 * @file itg_sso_popup.js
 * Contains all functionality related to login
 */


function Go() {
  
    var child = window.open("http://dev.indiatodayonline.in/saml_login/other", "_blank", "height=550,width=490");
 
    var leftDomain = false;
    var interval = setInterval(function() {
        try {
            if (child.document.domain === document.domain)
            {
             
                if (leftDomain && child.document.readyState === "complete")
                {
                    // we're here when the child window returned to our domain
                    clearInterval(interval);
                    alert("returned: " + child.document.URL);
                    child.postMessage({ message: "requestResult" }, "*");
                }
            }
            else {
                // this code should never be reached, 
                // as the x-site security check throws
                // but just in case
                leftDomain = true;
            }
        }
        catch(e) {
            // we're here when the child window has been navigated away or closed
            if (child.closed) {
                clearInterval(interval);
                window.location.reload();
                return; 
            }
            // navigated to another domain  
            leftDomain = true;
        }
    }, 10);
}
