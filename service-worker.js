<script type="text/javascript">"serviceWorker" in navigator && window.addEventListener("load", function() {
                navigator.serviceWorker.register("/service-worker.js").then(function(e) {
                    console.log("Service worker registered."), e.onupdatefound = function() {
                        var n = e.installing;
                        n.onstatechange = function() {
                            switch (n.state) {
                                case "installed":
                                    navigator.serviceWorker.controller ? (console.log("New or updated content is available."), window.location.reload()) : console.log("Content is now available offline!");
                                    break;
                                case "redundant":
                                    console.error("The installing service worker became redundant.")
                            }
                        }
                    }
                }).catch(function(e) {
                    console.error("Error during service worker registration:", e)
                })
            });


		console.log("%cStop!","font-size:48px; font-weight: bold; color: red;");console.log("\n%cThe JavaScript console is intended for developers. If someone told you to copy-paste something here to enable special features, it is a scam and will expose your personal information.","font-size:24px;");</script><script type="text/javascript">function loadScript(e, t) {
            if (navigator.onLine) {
                var n = document.createElement("script");
                n.type = "text/javascript", n.async = !0, n.readyState ? n.onreadystatechange = function() {
                    "loaded" != n.readyState && "complete" != n.readyState || (n.onreadystatechange = null, t && "function" == typeof t && t())
                } : n.onload = function() {
                    t && "function" == typeof t && t()
                }, n.src = e, (document.getElementsByTagName("head")[0] || document.getElementsByTagName("body")[0]).appendChild(n)
            } else {
                var a = new Request(e);
                caches.match(a).then(function(n) {
                    if (n) {
                        var a = document.createElement("script");
                        a.type = "text/javascript", a.async = !0, a.readyState ? a.onreadystatechange = function() {
                            "loaded" != a.readyState && "complete" != a.readyState || (a.onreadystatechange = null, t && "function" == typeof t && t())
                        } : a.onload = function() {
                            t && "function" == typeof t && t()
                        }, a.src = e, (document.getElementsByTagName("head")[0] || document.getElementsByTagName("body")[0]).appendChild(a)
                    }
                })
            }
        }
		var loadDeferredStyles = function() {
            var e = '<link rel="stylesheet" type="text/css" href="https://smedia2.intoday.in/mobiletv/1.4/resources/assets/css/googlefonts.min.css">';
            var t = document.createElement("div");
            t.innerHTML = e, document.body.appendChild(t)
        };
		setTimeout(function() {
								var raf = window.requestAnimationFrame || window.mozRequestAnimationFrame ||
									window.webkitRequestAnimationFrame || window.msRequestAnimationFrame || window.oRequestAnimationFrame;
								if (raf) raf(function() {
									window.setTimeout(loadDeferredStyles, 0);
								});
								loadScript("https://connect.facebook.net/en_US/sdk.js");
								loadScript("https://apis.google.com/js/platform.js");
        }, 500);</script>