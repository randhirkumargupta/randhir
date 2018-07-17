<style>
#section_video #border {
    border-bottom: 9px solid #D81920;
    border-top: 9px solid #243A71;
    float: left;
    margin: 0;
    padding: 0;
    width: 660px;
	margin-left: 350px;
 }
#section_video #section_video_top {
    border-color: #D81920 #D81920 #243A71;
    border-left: 3px solid #D81920;
    border-right: 3px solid #D81920;
    border-style: solid;
    border-width: 7px 3px;
    float: right;
    font: 13px/16px Tahoma;
    margin: 0;
    padding: 0 10px 0 0;
    width: 644px;
}
</style>
<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
<script type="text/javascript" src="http://media2.intoday.in/microsites/affle-player/jwplayer/jwplayer.js"></script>
<script type="text/javascript" src="http://media2.intoday.in/microsites/affle-player/jwplayer/ripple.js"></script> 

	<script type="text/javascript">
	
	var myUserAgent = navigator.userAgent;
	var currentItem=0;
	var videoSectionId=42;
	var vdopiavideoid=327297;
	//	var arrPlaylist=[];
	var arrPlaylist=["http://videodeliverys3.s3.amazonaws.com/indiatoday/video/December2013/Arvind Kejriwal_seedhi_baat_25 nov 2012.mp4"];
	var autoplay="true";
	var mp4videoFlagJS = 1;
	
            $(document).ready(function() {
                jwplayer("videoplayer").setup({
                    'flashplayer': "http://media2.intoday.in/microsites/affle-player/jwplayer/player.swf",
                    'controlbar.position': 'bottom',
                    'image': 'http://media2.intoday.in/indiatoday/kejriwal/thumb5.jpg',
		        	'autostart': false,
				    'stretching': 'fill',
					'skin': 'http://media2.intoday.in/microsites/affle-player/newtubedark1/NewTubeDark.xml',	 					
					
					 	
					'width': 650,
                    'height': 400,
                    
                    'provider': "rtmp",
		 'streamer': "rtmp://mediaclouds3.intoday.in:80/cfx/st",
		 
		 
                    
				 'file': 'mp4:indiatoday/video/December2013/Arvind Kejriwal_seedhi_baat_25 nov 2012.mp4',						
					'modes': [
        {type: 'flash', src: 'http://media2.intoday.in/microsites/affle-player/jwplayer/player.swf',
        config: {
		 'file': 'mp4:indiatoday/video/December2013/Arvind Kejriwal_seedhi_baat_25 nov 2012.mp4'
		 
		}
		},
		{
          type: 'html5',
          config: {
          
          
           'file': 'http://wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3/indiatoday/video/December2013/Arvind Kejriwal_seedhi_baat_25 nov 2012.mp4/playlist.m3u8',
           'provider': 'video'
          }
		  
        },
		{
          type: 'download',
          config: {
         
          
           'file': 'http://medias3d.intoday.in/indiatoday/video/December2013/Arvind Kejriwal_seedhi_baat_25 nov 2012.3gp',
           'provider': 'video'
          }

        }
    ],   
    
    
	

	'plugins': {
	       
                        'http://media2.intoday.in/microsites/affle-player/jwplayer/ova-jw.swf': {
                        
                       
                        "debug": {
                     "levels": "none" },
                       'like-1': {},
						                            'ads': {
														'enforceLinearAdsOnPlaylistSelection': true,   
							  'companions': {
									'class':"storm-vast-companion",
                                    'restore': false,
                                    'regions': [
                                        {
                                        'id': "companion",
                                        'width': 300,
                                        'height': 250
                                        }
                                    ]
                                },
                                'vpaid': {
                                    'holdingClipUrl': "http://medias3d.intoday.in/indiatoday/video/jwplayer/blank.mp4"
                                },
                                'schedule': [
                                    {
                                    'position': "pre-roll",
                                    
									
                                    'tag': "",
										 
                                    'duration': 25
                                    },
									{
										'position': "mid-roll",'startTime': "00:02:00",
										tag: ''
									}
                                ]
                            }
                        }
                    }
                }); 
            });
        	
	
	
	
	
	</script>

<div id="videoplayer"></div>
                         