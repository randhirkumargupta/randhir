const res_version = 'indiatoday-1.1'; 
var ROUTE_SITE_URL = 'staging-it.indiatodayonline.in'; 
const SITE_CACHE_HOST_NAME = ["staging-it.indiatodayonline.in"];
const MEDIA_CACHE_HOST_NAME = ["static-dev.indiatodayonline.in/indiatoday"];
const STATIC_CACHE_NAME = 	{
	cache: {
		name: 'indiatoday-static-cache-'+res_version,
		notifyOnCacheUpdate: true,
		maxAgeSeconds: null,
		maxEntries: null
	},
	debug: false,
	networkTimeoutSeconds: null,
	preCacheItems: [],
	// A regular expression to apply to HTTP response codes. Codes that match
	// will be considered successes, while others will not, and will not be
	// cached.
	successResponses: /^0|([123]\d\d)|(40[14567])|410$/
};
const globalOptions = 	{
	cache: {
		name: 'indiatoday-global-cache-'+res_version,
		notifyOnCacheUpdate: true,
		maxAgeSeconds: null,
		maxEntries: null
	},
	debug: false,
	networkTimeoutSeconds: null,
	preCacheItems: [],
	// A regular expression to apply to HTTP response codes. Codes that match
	// will be considered successes, while others will not, and will not be
	// cached.
	successResponses: /^0|([123]\d\d)|(40[14567])|410$/
};

const APP_CACHE_NAME =  {
	cache: {
		name: 'indiatoday-app-cache-'+res_version,
		notifyOnCacheUpdate: true,
		maxAgeSeconds: null,
		maxEntries: null
	},
	debug: false,
	networkTimeoutSeconds: 7,
	preCacheItems: [],
	// A regular expression to apply to HTTP response codes. Codes that match
	// will be considered successes, while others will not, and will not be
	// cached.
	successResponses: /^0|([123]\d\d)|(40[14567])|410$/
};
const MEDIA_CACHE_PATH_NAME = 'https://akm-img-a-in.tosshub.com/indiatoday/'; 

var DEBUG_MODE = false;
var hwid = "hwid";
var deviceType = navigator.userAgent.toLowerCase().indexOf('firefox') > -1 ? 12 : 11;


// variable for offline analytics
var idbDatabase;
var IDB_VERSION = 1;
var STOP_RETRYING_AFTER = 86400000; // One day, in milliseconds.
var STORE_NAME = 'indiatoday-urls';
var savedRequests = [];
function openDatabaseAndReplayRequests() {
  var indexedDBOpenRequest = indexedDB.open('indiatoday-offline-analytics', IDB_VERSION);

  // This top-level error handler will be invoked any time there's an IndexedDB-related error.
  indexedDBOpenRequest.onerror = function(error) {
    console.error('IndexedDB error:', error);
  };

  // This should only execute if there's a need to create a new database for the given IDB_VERSION.
  indexedDBOpenRequest.onupgradeneeded = function() {
    this.result.createObjectStore(STORE_NAME, {keyPath: 'url'});
  };

  // This will execute each time the database is opened.
  indexedDBOpenRequest.onsuccess = function() {
    idbDatabase = this.result;
    replayAnalyticsRequests();
  };
}

// Open the IndexedDB and check for requests to replay each time the service worker starts up.
// Since the service worker is terminated fairly frequently, it should start up again for most
// page navigations. It also might start up if it's used in a background sync or a push
// notification context.
openDatabaseAndReplayRequests();

// Helper method to get the object store that we care about.
function getObjectStore(storeName, mode) {
  return idbDatabase.transaction(storeName, mode).objectStore(storeName);
}

function replayAnalyticsRequests() {
  

  getObjectStore(STORE_NAME).openCursor().onsuccess = function(event) {
    // See https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API/Using_IndexedDB#Using_a_cursor
    var cursor = event.target.result;

    if (cursor) {
      // Keep moving the cursor forward and collecting saved requests.
      savedRequests.push(cursor.value);
      cursor.continue();
    } else {
      // At this point, we have all the saved requests.
      savedRequests.forEach(function(savedRequest) {
        var queueTime = Date.now() - savedRequest.timestamp;
        if (queueTime > STOP_RETRYING_AFTER) {
          getObjectStore(STORE_NAME, 'readwrite').delete(savedRequest.url);
          console.warn(' Request has been queued for %d milliseconds. ' +
            'No longer attempting to replay.', queueTime);
        } else {
          // The qt= URL parameter specifies the time delta in between right now, and when the
          // /collect request was initially intended to be sent. See
          // https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#qt
          var requestUrl = savedRequest.url + '&qt=' + queueTime;

          fetch(requestUrl).then(function(response) {
            if (response.status < 400) {
              // If sending the /collect request was successful, then remove it from the IndexedDB.
              getObjectStore(STORE_NAME, 'readwrite').delete(savedRequest.url);
            } else {
              // This will be triggered if, e.g., Google Analytics returns a HTTP 50x response.
              // The request will be replayed the next time the service worker starts up.
              console.error(' Replaying failed:', response);
            }
          }).catch(function(error) {
            // This will be triggered if the network is still down. The request will be replayed again
            // the next time the service worker starts up.
            console.error(' Replaying failed:', error);
          });
        }
      });
    }
  };
}
function checkForAnalyticsRequest(requestUrl) {
  // Construct a URL object (https://developer.mozilla.org/en-US/docs/Web/API/URL.URL)
  // to make it easier to check the various components without dealing with string parsing.
  var url = new URL(requestUrl);

  if ((url.hostname === 'www.google-analytics.com' ||
       url.hostname === 'ssl.google-analytics.com') &&
       url.pathname === '/collect') {
    //console.log('  Storing Google Analytics request in IndexedDB to be replayed later.');
    saveAnalyticsRequest(requestUrl);
  }
}

function saveAnalyticsRequest(requestUrl) {
  getObjectStore(STORE_NAME, 'readwrite').add({
    url: requestUrl,
    timestamp: Date.now()
  });
}
const CACHE_APP = [
  '/',
  '/offline'
]
const OFFLINE_URL = '/offline';
const CACHE_STATIC = [
  '/manifest.json',
  MEDIA_CACHE_PATH_NAME+'images/misc/chrome-touch-icon-192x192.png',
  MEDIA_CACHE_PATH_NAME+'images/misc/icon-128x128.png',
  MEDIA_CACHE_PATH_NAME+'images/misc/ms-touch-icon-144x144-preco.png',
  MEDIA_CACHE_PATH_NAME+'images/misc/medium-icon.png',
  MEDIA_CACHE_PATH_NAME+'images/misc/icon-256x256.png',
  MEDIA_CACHE_PATH_NAME+'images/misc/icon-384x384.png',
  MEDIA_CACHE_PATH_NAME+'images/misc/icon-512x512.png',
 ]

self.addEventListener('install',function(e){
    e.waitUntil(
        Promise.all([caches.open(STATIC_CACHE_NAME.cache.name),caches.open(APP_CACHE_NAME.cache.name),self.skipWaiting()]).then(function(storage){
			var static_cache = storage[0];
            var app_cache = storage[1];
			return Promise.all([static_cache.addAll(CACHE_STATIC),app_cache.addAll(CACHE_APP)]);
        })
    );
});

self.addEventListener('activate', function(e) {
    e.waitUntil(
        Promise.all([
            self.clients.claim(),
            caches.keys().then(function(cacheNames) {
                return Promise.all(
                    cacheNames.map(function(cacheName) {
						//console.log('Above deleting',cacheName);
                        if (cacheName !== APP_CACHE_NAME && cacheName !== STATIC_CACHE_NAME) {
                            //console.log('deleting',cacheName);
                            return caches.delete(cacheName);
                        }
                    })
                );
            })
        ])
    );
});



self.addEventListener('fetch',function(e){
    const url = new URL(e.request.url);
	if(e.request.method === 'GET'){
		if (SITE_CACHE_HOST_NAME.indexOf(url.hostname) !== -1 ){
			if (e.request.url.indexOf(ROUTE_SITE_URL)  !== -1 || e.request.url.indexOf(ROUTE_SITE_URL+'/')  !== -1 ) {
				if(e.request.url.indexOf(OFFLINE_URL)  !== -1){
					e.respondWith(
					caches.match(e.request).then(function(response){
							if (response) {
								return response;
							}
							var fetchRequest = e.request.clone();
							return fetch(fetchRequest).then(function(response) {
								if (!response || response.status !== 200 || response.type !== 'basic') {
									return response;
								} 
								var responseToCache = response.clone();
								caches.open(APP_CACHE_NAME.cache.name).then(function(cache) {
									cache.put(e.request, responseToCache);
								});
								return response;
							});
						})
					);
				}else{
					if (navigator.onLine) {
						e.respondWith(networkFirst(e.request, APP_CACHE_NAME));
					}else{
						e.respondWith(cacheOnly(e.request, APP_CACHE_NAME));
					}
				}
			}else{
				if (navigator.onLine) {
					e.respondWith(
					caches.match(e.request).then(function(response){
							if (response) {
								return response;
							}
							var fetchRequest = e.request.clone();
							return fetch(fetchRequest).then(function(response) {
								if (!response || response.status !== 200 || response.type !== 'basic') {
									return response;
								} 
								var responseToCache = response.clone();
								caches.open(STATIC_CACHE_NAME.cache.name).then(function(cache) {
									cache.put(e.request, responseToCache);
								});
								return response;
							});
						})
					);
				}else{
					e.respondWith(cacheOnly(e.request, APP_CACHE_NAME));
				}
			}
			
			
		}else if (MEDIA_CACHE_HOST_NAME.indexOf(url.hostname) !== -1){			
				if (navigator.onLine) {
				e.respondWith(
					caches.match(e.request).then(function(response){
							if (response) {
								return response;
							}
							var fetchRequest = new Request(e.request.url, { mode: 'no-cors' });
							return fetch(fetchRequest).then(function(response) {
								if (response || response.type !== 'opaque' || response.type !== 'opaqueredirect') {
									var responseToCache = response.clone();
									caches.open(STATIC_CACHE_NAME.cache.name).then(function(cache) {
										cache.put(e.request, responseToCache);
									});
									return response;
								}
							});
						})
					);
				}else{
					e.respondWith(cacheOnly(e.request, STATIC_CACHE_NAME));
				}
			
		}else if (CACHE_APP.indexOf(url.pathname) !== -1){
			e.respondWith(caches.match(e.request));
		}else {
			if (navigator.onLine) {
				
			}else{
				e.respondWith(
					caches.open(globalOptions.cache.name).then(function(cache) {
					  return cache.match(e.request).then(function(response) {
						 if (response) {
							return response;
						} 

						return fetch(e.request.clone()).then(function(response) {
							if (response.status < 400) {
									cache.put(e.request, response.clone());
									return response;
							} else if (response.status >= 500) {
								checkForAnalyticsRequest(e.request.url);
								cacheOnly(e.request, globalOptions);
							}
							
						}).catch(function(error) {
						  checkForAnalyticsRequest(e.request.url);
							//console.log('Error in url'+e.request.url+' | Error Message=>'+error);
							cacheOnly(e.request, globalOptions);
						  //throw error;
						});
					  }).catch(function(error) {
						  //console.log('Error in url'+e.request.url+' | Error Message=>'+error);
						  cacheOnly(e.request, globalOptions);
						//throw error;
					  });
					})
				);
			}
			
			
		}
	}
	
});


function networkFirst(request,  options) {
  options = options || {};
  var successResponses = options.successResponses ||
      globalOptions.successResponses;
  // This will bypass options.networkTimeout if it's set to a false-y value like
  // 0, but that's the sane thing to do anyway.
  var networkTimeoutSeconds = options.networkTimeoutSeconds ||
      globalOptions.networkTimeoutSeconds;
  //console.log('Strategy: network first [' + request.url + ']', JSON.stringify(options));

  return openCache(options).then(function(cache) {
    var timeoutId;
    var promises = [];
    var originalResponse;

    if (networkTimeoutSeconds) {
      var cacheWhenTimedOutPromise = new Promise(function(resolve) {
        timeoutId = setTimeout(function() {
          cache.match(request).then(function(response) {
            if (response) {
              // Only resolve this promise if there's a valid response in the
              // cache. This ensures that we won't time out a network request
              // unless there's a cached entry to fallback on, which is arguably
              // the preferable behavior.
			  //console.log('Resolve Response with timeout and Response From Cache[' + request.url + ']');
              resolve(response);
            }
          });
        }, networkTimeoutSeconds * 1000);
      });
      promises.push(cacheWhenTimedOutPromise);
    }

    var networkPromise = fetchAndCache(request, options)
      .then(function(response) {
        // We've got a response, so clear the network timeout if there is one.
        if (timeoutId) {
          clearTimeout(timeoutId);
        }

        if (successResponses.test(response.status)) {
			return response;
        }

        //console.log('Response was an HTTP error: ' + response.statusText,JSON.stringify(options));
        originalResponse = response;
        throw new Error('Bad response');
      }).catch(function(error) {
        return cache.match(request).then(function(response) {
          // If there's a match in the cache, resolve with that.
          if (response) {
			  return response;
          }

          // If we have a Response object from the previous fetch, then resolve
          // with that, even though it corresponds to an error status code.
          if (originalResponse) {
			  //console.log("OriginalResponse returning from cache");
            return originalResponse;
          }

          // If we don't have a Response object from the previous fetch, likely
          // due to a network failure, then reject with the failure error.
          //throw error;
		  return openCache(APP_CACHE_NAME).then(function(cache) {
			  return cache.match(OFFLINE_URL);
			});
        }).catch(function(err) {
			return caches.match(request).then(function(response){
				if(response){
					return response;
				}else{
					return openCache(APP_CACHE_NAME).then(function(cache) {
					  return cache.match(OFFLINE_URL);
					});
				}
			})
		});
      });

    promises.push(networkPromise);

    return Promise.race(promises);
  });
}

function openCache(options) {
  var cacheName = getCacheName(options);
  return caches.open(cacheName);
}
function getCacheName(options) {
  var cacheName;
  if (options && options.cache) {
    cacheName = options.cache.name;
  }
  return cacheName || globalOptions.cache.name;
}
function fetchAndCache(request, options) {
  options = options || {};
  var successResponses = options.successResponses ||
      globalOptions.successResponses;

  return fetch(request.clone()).then(function(response) {
    var clonedResponse = response.clone();

    // Only cache GET requests with successful responses.
    // Since this is not part of the promise chain, it will be done
    // asynchronously and will not block the response from being returned to the
    // page.
    if (request.method === 'GET' && successResponses.test(response.status)) {
      openCache(options).then(function(cache) {
        // If any of the options are provided in options.cache then use them.
        // Do not fallback to the global options for any that are missing
        // unless they are all missing.
        var cacheOptions = options.cache || globalOptions.cache;

        var readyForCacheUpdate = Promise.resolve();
        var shouldNotify = false;
        if (cacheOptions.notifyOnCacheUpdate) {
          // The readyForCacheUpdate promise will resolve once we've read in
          // the previously cached entry.
          readyForCacheUpdate = cache.match(request)
            .then(function(cachedResponse) {
              if (cachedResponse && !sameResponses(cachedResponse, response)) {
                //console.log('sameResponses was false.');
                shouldNotify = true;
              } else {
                //console.log('sameResponses was true.');
              }
            });
        }

        // To ensure that notifyOnCacheUpdate works, wait to update the cache
        // until after we've had a chance to read the previously cached entry.
        readyForCacheUpdate.then(function() {
          cache.put(request, response).then(function() {
            // Only run the cache expiration logic if at least one of the
            // maximums is set, and if we have a name for the cache that the
            // options are being applied to.
            if ((cacheOptions.maxEntries || cacheOptions.maxAgeSeconds) &&
              cacheOptions.name) {
              queueCacheExpiration(request, cache, cacheOptions);
            }
          }).then(function() {
            if (shouldNotify) {
              notifyClientsOfUpdate(request.url, getCacheName(options));
            }
          });
        });
      });
    }

    return clonedResponse;
  });
}
 
function sameResponses(responseA, responseB) {
  // If the responses are both same-origin, then we'll have the full set of
  // headers available to check.
  // See https://fetch.spec.whatwg.org/#cors-safelisted-response-header-name for
  // a list of headers that are exposed for CORS requests. Only last-modified
  // is present in that list, so if we're dealing with CORS resources, hopefully
  // last-modified is being set by the remote server.
  return ['content-length', 'last-modified', 'etag'].every(function(header) {
    return (responseA.headers.has(header) === responseB.headers.has(header)) &&
      (responseA.headers.get(header) === responseB.headers.get(header));
  });
}

function notifyClientsOfUpdate(url, cacheName) {
  self.clients.matchAll().then(function(clients) {
    clients.forEach(function(client) {
      client.postMessage({
        type: 'cache-updated',
        source: 'Indiatoday',
        cacheName: cacheName,
        url: url
      });
    });
  });
}
function cacheOnly(request, options) {
  //console.log('Strategy: cache only [' + request.url + ']', options);
  return openCache(options).then(function(cache) {
    return caches.match(request).then(function(response){
			if(response){
				return response;
			}else{
				return openCache(APP_CACHE_NAME).then(function(cache) {
				  return cache.match(OFFLINE_URL);
				});
			}
		}).catch(function(err) {
			return openCache(APP_CACHE_NAME).then(function(cache) {
			  return cache.match(OFFLINE_URL);
			});
		});
  });
}
