webpackJsonpjwplayer([8],{76:function(t,n,e){var r,o;r=[e(1)],o=function(t){function n(t,n){return function(){t.apply(n,arguments)}}function e(t){if("object"!=typeof this)throw new TypeError("Promises must be constructed via new");if("function"!=typeof t)throw new TypeError("not a function");this._state=null,this._value=null,this._deferreds=[],f(t,n(o,this),n(i,this))}function r(t){var n=this;return null===this._state?void this._deferreds.push(t):void l(function(){var e=n._state?t.onFulfilled:t.onRejected;if(null===e)return void(n._state?t.resolve:t.reject)(n._value);var r;try{r=e(n._value)}catch(o){return void t.reject(o)}t.resolve(r)})}function o(t){try{if(t===this)throw new TypeError("A promise cannot be resolved with itself.");if(t&&("object"==typeof t||"function"==typeof t)){var e=t.then;if("function"==typeof e)return void f(n(e,t),n(o,this),n(i,this))}this._state=!0,this._value=t,c.call(this)}catch(r){i.call(this,r)}}function i(t){this._state=!1,this._value=t,c.call(this)}function c(){for(var t=0,n=this._deferreds.length;t<n;t++)r.call(this,this._deferreds[t]);this._deferreds=null}function u(t,n,e,r){this.onFulfilled="function"==typeof t?t:null,this.onRejected="function"==typeof n?n:null,this.resolve=e,this.reject=r}function f(t,n,e){var r=!1;try{t(function(t){r||(r=!0,n(t))},function(t){r||(r=!0,e(t))})}catch(o){if(r)return;r=!0,e(o)}}var l=t.defer,s=Array.isArray||function(t){return"[object Array]"===Object.prototype.toString.call(t)};e.prototype["catch"]=function(t){return this.then(null,t)},e.prototype.then=function(t,n){var o=this;return new e(function(e,i){r.call(o,new u(t,n,e,i))})},e.all=function(){var t=Array.prototype.slice.call(1===arguments.length&&s(arguments[0])?arguments[0]:arguments);return new e(function(n,e){function r(i,c){try{if(c&&("object"==typeof c||"function"==typeof c)){var u=c.then;if("function"==typeof u)return void u.call(c,function(t){r(i,t)},e)}t[i]=c,0===--o&&n(t)}catch(f){e(f)}}if(0===t.length)return n([]);for(var o=t.length,i=0;i<t.length;i++)r(i,t[i])})},e.resolve=function(t){return t&&"object"==typeof t&&t.constructor===e?t:new e(function(n){n(t)})},e.reject=function(t){return new e(function(n,e){e(t)})},e.race=function(t){return new e(function(n,e){for(var r=0,o=t.length;r<o;r++)t[r].then(n,e)})},e._setImmediateFn=function(t){l=t},window.Promise||(window.Promise=e)}.apply(n,r),!(void 0!==o&&(t.exports=o))}});