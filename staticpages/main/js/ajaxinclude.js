function ajaxinclude(t){var e=!1;if(window.XMLHttpRequest)e=new XMLHttpRequest;else{if(!window.ActiveXObject)return!1;try{e=new ActiveXObject("Msxml2.XMLHTTP")}catch(n){try{e=new ActiveXObject("Microsoft.XMLHTTP")}catch(n){}}}e.open("GET",t,!1),e.setRequestHeader("If-Modified-Since","Thu, 1 Jan 1970 00:00:00 GMT"),e.send(null),writecontent(e)}function writecontent(t){(-1==window.location.href.indexOf("http")||200==t.status)&&document.write(t.responseText)}var rootdomain="http://"+window.location.hostname;