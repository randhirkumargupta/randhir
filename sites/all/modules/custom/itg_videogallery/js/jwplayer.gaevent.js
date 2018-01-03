jQuery(document).ready(function() {	  
	playerInstance = jwplayer('videoplayer');
	var playlist=playerInstance.getPlaylist();
	ga("send","event","video",'playlist', JSON.stringify(playlist));

	var fileName=playlist[0].sources[0].file;
	var ext = fileName.split('.').pop();

	ga("send","event","video",'playlist-sources-file', playlist[0].sources[0].file);
	ga("send","event","video",'playlist-sources-extn', ext);
//	ga("send","event","video",'playlist-sources-type', playlist[0].sources[0].type);

	playerInstance.on('complete', function(e) {
		ga("send","event","video",'complete-stringify', JSON.stringify(e));
	});

	var upto = 0;
	var upto1 = 0;

	playerInstance.on('time', function(e) {
		var current = Math.floor(e.position / 60);
		if (current > upto) {
			upto = current;
			ga("send","event","video",'video-time-stringify', JSON.stringify(parseInt(e.position)));
		}
		var current_10 = Math.floor(e.position / 10);

		if (current_10 > upto1) {
			upto1 = current_10;
			ga("send","event","video",'video-time-10Sec-played', "1");
		}
	});

	var MaxBitrate=0

	/*playerInstance.on('visualQuality', function(e) {
		ga("send","event","video",'visualQuality-type', e.type);
		ga("send","event","video",'visualQuality-mode', e.mode);
		ga("send","event","video",'visualQuality-reason', e.reason);
		ga("send","event","video",'visualQuality-level-width', e.level.width);
		ga("send","event","video",'visualQuality-level-index', e.level.index);
		ga("send","event","video",'visualQuality-level-height', e.level.height);
		ga("send","event","video",'Bitrate', e.level.bitrate);
		if(MaxBitrate < e.level.bitrate ){
			MaxBitrate = e.level.bitrate;
			ga("send","event","video",'Max Bitrate', MaxBitrate);
		}
		ga("send","event","video",'visualQuality-level-label', e.level.label);
	});*/

	playerInstance.on('buffer', function(e) { 
		var state1=e.oldstate;
		if(state1=="playing") {
			ga("send","event","video",'buffer-stringify-all', JSON.stringify(e));  
		}
	});

	playerInstance.on('levelsChanged', function(e) {
		var getCurrentQuality=playerInstance.getCurrentQuality();
		ga("send","event","video",'getCurrentQualitychange', JSON.stringify(getCurrentQuality));
	});

	playerInstance.on('audioTrackChanged',function(e) {
		var getCurrentAudioTrack=playerInstance.getAudioTracks();
		ga("send","event","video",'audioTrackChanged', JSON.stringify(getCurrentAudioTrack));
	});

	playerInstance.on('adBlock',function(e) {
		ga("send","event","video",'adBlock', JSON.stringify(e));
	}); 

	playerInstance.on('adCompanions',function(e) {
		ga("send","event","video",'adCompanions', JSON.stringify(e));
	}); 
 
	playerInstance.on('adComplete',function(e) {
		ga("send","event","video",'adComplete', JSON.stringify(e));
	}); 
 
	playerInstance.on('ready', function(event) {
		sharingPlugin = playerInstance.getPlugin('sharing');
		sharingPlugin.on('open',function () {
			ga("send","event","video",'sharingPluginopen', true);
		});

		sharingPlugin.on('close',function () {
			ga("send","event","video",'sharingPluginclose', true);
		});
	});

	playerInstance.on('setupError',function(e) {
		ga("send","event","video",'setupError', JSON.stringify(e));
	}); 
	playerInstance.on('error',function(e) {
		ga("send","event","video",'error', JSON.stringify(e));
	}); 
	playerInstance.on('firstFrame',function(e) {
		var ff=JSON.stringify(e);
		obj = JSON.parse(ff);
		var ld=obj.loadTime;
		var ld=parseInt(ld) / 1000;
		var ld=parseInt(ld);
		ga("send","event","video",'firstFrame',ld);
	}); 
 
	playerInstance.on('mute',function(e) {
		ga("send","event","video",'mute', JSON.stringify(e));
	}); 
 
	playerInstance.on('volume',function(e) {
		var v1=JSON.stringify(e);
		var obj=JSON.parse(v1);
		var v1=obj.volume;
		ga("send","event","video",'volume', v1);
	}); 
	playerInstance.on('fullscreen',function(e) {
		ga("send","event","video",'fullscreen', JSON.stringify(e));
	}); 
	/*playerInstance.on('resize',function(e) {
		ga("send","event","video",'resize', JSON.stringify(e));
	});*/ 
 
	playerInstance.on('beforePlay',function(e) {
		var provider=playerInstance.getProvider();
		var pv=JSON.stringify(provider);
		obj = JSON.parse(pv);
	    ga("send","event","video",'provider',obj.name);
	}); 
 
	/*playerInstance.on('adClick', function(e) {
		ga("send","event","video",'adClick', true);
		ga("send","event","video",'adClick-client', e.client);
		ga("send","event","video",'adClick-id', e.id);
		ga("send","event","video",'adClick-adposition', e.adposition);
		ga("send","event","video",'adClick-adtitle', e.adtitle);
		ga("send","event","video",'adClick-adsystem', e.adsystem);
		ga("send","event","video",'adClick-tag', e.tag);
		ga("send","event","video",'adClick-creativetype', e.creativetype);
		ga("send","event","video",'adClick-type', e.type);
		ga("send","event","video",'adClick-duration', e.duration);
		ga("send","event","video",'adClick-linear', e.linear);
	}); 

	playerInstance.on('adCompanions', function(e) {
		ga("send","event","video",'adCompanions-stringify', JSON.stringify(e));
		ga("send","event","video",'adCompanions', JSON.stringify(e.companions));
		ga("send","event","video",'adCompanions-tag', e.tag);
	});*/

	playerInstance.on('adComplete', function(e) {
		ga("send","event","video",'adComplete', true);
		ga("send","event","video",'adComplete-client', e.client);
		ga("send","event","video",'adComplete-creativetype', e.creativetype);
		ga("send","event","video",'adComplete-tag', e.tag);
	}); 
	
	/*playerInstance.on('adSkipped', function(e) {
		ga("send","event","video",'adSkipped', "Yes");
		ga("send","event","video",'adSkipped-adsystem', e.adsystem);
		ga("send","event","video",'adSkipped-linear', e.linear);
		ga("send","event","video",'adSkipped-adposition', e.adposition);
		ga("send","event","video",'adSkipped-type', e.type);
		ga("send","event","video",'adSkipped-duration', e.duration);
		ga("send","event","video",'adSkipped-adtitle', e.adtitle);
	});*/
	playerInstance.on('adError', function(e) {
		ga("send","event","video",'adError', true);
		ga("send","event","video",'adError-message', e.message); //
	});

	playerInstance.on('adRequest', function(e) {
		ga("send","event","video",'adRequest', true);
		ga("send","event","video",'adRequest-adposition', e.adposition);
		ga("send","event","video",'adRequest-client', e.client);
		ga("send","event","video",'adRequest-offset', e.offset);
		ga("send","event","video",'adRequest-tag', e.tag);
	});

	var AdPlays = 0;
	playerInstance.on('adStarted', function(e) {
		AdPlays++;
		ga("send","event","video",'adStarted', true);
		ga("send","event","video",'adStarted-creativetype', e.creativetype);
		ga("send","event","video",'adStarted-tag', e.tag);
		ga("send","event","video",'Ad Plays', AdPlays);
	});
	playerInstance.on('adImpression', function(e) {
		ga("send","event","video",'adImpression', true);
		ga("send","event","video",'adImpression-client', e.client);
		ga("send","event","video",'adImpression-adsystem', e.adsystem);
		ga("send","event","video",'adImpression-creativetype', e.creativetype);
		ga("send","event","video",'adImpression-linear', e.linear);
		ga("send","event","video",'adImpression-tag', e.tag);
		ga("send","event","video",'adImpression-adposition', e.adposition);
		ga("send","event","video",'adImpression-type', e.type);
		ga("send","event","video",'adImpression-adtitle', e.adtitle);
		ga("send","event","video",'adImpression_vastversion', e.vastversion);  
	});

	playerInstance.on('adPlay', function(e) {
		ga("send","event","video",'adPlay', "1");
		ga("send","event","video",'adPlay-tag', e.tag);
		ga("send","event","video",'adPlay-linear', e.linear);
		ga("send","event","video",'Ad Title', e.adtitle);//adPlay-adtitle
		ga("send","event","video",'adPlay-adsystem', e.adsystem);
		ga("send","event","video",'Ad Duration', e.duration);
		ga("send","event","video",'Ad Partner Id', e.client);//adPlay-client 
		ga("send","event","video",'adPlay-type', e.type);
		ga("send","event","video",'adPlay-creativetype', e.creativetype);
		ga("send","event","video",'Ad Placement', e.adposition); //adPlay-adposition
	});

	playerInstance.on('adPause', function(e) {
		ga("send","event","video",'adPause', true);
		ga("send","event","video",'adPause-tag', e.tag);
		ga("send","event","video",'adPause-adtitle', e.adtitle);
		ga("send","event","video",'adPause-adsystem', e.adsystem);
		ga("send","event","video",'adPause-creativetype', e.creativetype);
		ga("send","event","video",'adPause-duration', e.duration);
		ga("send","event","video",'adPause-linear', e.linear);
		ga("send","event","video",'adPause-id', e.id);
		ga("send","event","video",'adPause-adposition', e.adposition);
		ga("send","event","video",'adPause-newstate', e.newstate);
		ga("send","event","video",'adPause-client', e.client);
		ga("send","event","video",'adPause-type', e.type);
		ga("send","event","video",'adPause-oldstate', e.oldstate);
	});
});
