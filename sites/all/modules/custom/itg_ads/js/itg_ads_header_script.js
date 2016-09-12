/*
 * @file itg_ads.js
 * Contains all functionality related to Ads Management
 */

// #######################################################################################
    var _sf_startpt=(new Date()).getTime()

// #######################################################################################
    var crtg_nid = '5603';
    var crtg_cookiename = 'crtg_rta';
    var crtg_varname = 'crtg_content';
    function crtg_getCookie(c_name){ var i,x,y,ARRCookies=document.cookie.split(";");for(i=0;i<ARRCookies.length;i++){x=ARRCookies[i].substr(0,ARRCookies[i].indexOf("="));y=ARRCookies[i].substr(ARRCookies[i].indexOf("=")+1);x=x.replace(/^\s+|\s+$/g,"");if(x==c_name){return unescape(y);} }return'';}
    var crtg_content = crtg_getCookie(crtg_cookiename);
    var crtg_rnd=Math.floor(Math.random()*99999999999);
    (function(){
    var crtg_url=location.protocol+'//rtax.criteo.com/delivery/rta/rta.js?netId='+escape(crtg_nid);
    crtg_url +='&cookieName='+escape(crtg_cookiename);
    crtg_url +='&rnd='+crtg_rnd;
    crtg_url +='&varName=' + escape(crtg_varname);
    var crtg_script=document.createElement('script');crtg_script.type='text/javascript';crtg_script.src=crtg_url;crtg_script.async=true;
    if(document.getElementsByTagName("head").length>0)document.getElementsByTagName("head")[0].appendChild(crtg_script);
    else if(document.getElementsByTagName("body").length>0)document.getElementsByTagName("body")[0].appendChild(crtg_script);
    })();
// #########################################################################################
    window._newsroom=window._newsroom||[],window._newsroom.push({pageTemplate:"home"}),window._newsroom.push({pageDashboard:"home"}),window._newsroom.push("auditClicks"),window._newsroom.push("trackPage"),!function(o,e,n){o.async=1,o.src=n,e.parentNode.insertBefore(o,e)}(document.createElement("script"),document.getElementsByTagName("script")[0],"//c2.taboola.com/nr/indiatoday-indiatoday/newsroom.js");
// #########################################################################################
    var _sf_async_config = _sf_async_config || {};
    /** CONFIGURATION START **/
        _sf_async_config.uid = 60355;
        _sf_async_config.domain = 'indiatoday.intoday.in';
        _sf_async_config.useCanonical = true;
    /** CONFIGURATION END **/
    var _sf_startpt = (new Date()).getTime();
// ##########################################################################################

    var zmt_mtag;
    function zd_get_placements(){
     zmt_mtag = zmt_get_tag(821,"29198");
     p29198_1 = zmt_mtag.zmt_get_placement("zt_29198_1", "29198", "1" , "2045" , "31" , "2" ,"1", "1");
     p29198_2 = zmt_mtag.zmt_get_placement("zt_29198_2", "29198", "2" , "1138" , "14" , "2" ,"728", "90");
     p29198_2.zmt_add_ct("criteo:"+crtg_content+"^viz728x90:" + vizPAM.isVizInterested("728x90")['int']);
     p29198_3 = zmt_mtag.zmt_get_placement("zt_29198_3", "29198", "3" , "1140" , "9" , "2" ,"300", "250");
     p29198_3.zmt_add_ct("criteo:"+crtg_content+"^viz300x250:" + vizPAM.isVizInterested("300x250")['int']);
     p29198_4 = zmt_mtag.zmt_get_placement("zt_29198_4", "29198", "4" , "2423" , "9" , "2" ,"300", "250");
     p29198_5 = zmt_mtag.zmt_get_placement("zt_29198_5", "29198", "5" , "1139" , "14" , "2" ,"728", "90");
     p29198_5.zmt_add_ct("criteo:"+crtg_content+"^viz728x90:" + vizPAM.isVizInterested("728x90")['int']);
     p29198_6 = zmt_mtag.zmt_get_placement("zt_29198_6", "29198", "6" , "2045" , "54" , "2" ,"1", "1");
     p29198_7 = zmt_mtag.zmt_get_placement("zt_29198_7", "29198", "7" ,  "2134" , "19" , "2" ,"300", "100");
     zmt_mtag.zmt_set_async();
     zmt_mtag.zmt_load(zmt_mtag); 
    }
// ############################################################################################
