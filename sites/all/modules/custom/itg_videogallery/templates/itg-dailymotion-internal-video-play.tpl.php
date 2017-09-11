
<link rel="stylesheet" href="http://fortawesome.github.io/Font-Awesome/assets/font-awesome/css/font-awesome.css" />
<style>
    #right-section .rt-colum{float:left}
    .jw-controlbar .jw-option{line-height:12px !important; line-height:17px !important; font-family:"Roboto", sans-serif !important;}
    .jw-icon-hd::before{content: "\f013" !important; font-family: FontAwesome;}
    span.flasherror{ display:block; text-align:center; margin-top:33%; position:relative; margin-bottom:5px; font-family:roboto; font-weight:400;}
    a.flashlogo{ width:100px; margin:0 auto; display:block;}
    .videocat-ancorlist{ background:#F3F3F3; margin-bottom:20px;}
    .videocat-ancorlist ul li{ list-style:none; width:auto; float:left;  padding:8px 0;}
    .videocat-ancorlist ul li a{ font-size:16px; color:#838383; display:block; float:left; width:auto; font-weight:300; padding:0 10px; border-right:1px solid #838383; line-height:16px;}
    .videocat-ancorlist ul li:last-child a{border-right:0px;}

    #fullvideosdisplay{width:650px !important;}

    @media screen and (max-width :800px){
        .watchright_now{float:left !important;}
        #rightpanel #right-section #rosRightColumn .rt-colum:nth-child(4), #rightpanel #right-section #rosRightColumn .rt-colum:nth-child(5) { float:left;}
        #rightpanel #right-section #rosRightColumn .rt-colum:nth-child(6), #rightpanel #right-section #rosRightColumn .rt-colum:nth-child(7) { float:right;}

    }
    *{box-sizing:border-box!important;}
</style>

<?php
$width = 420;
$height = 500;
$video_all_data = json_decode($video_data, TRUE);
$player_content = itg_videogallery_make_parm_for_jwpalyer($video_all_data);

?>
<script>
  jwplayer.key = "XRiQ7SgnSBR9/smfQ9+YZsn3S7EMc/Am440mYg==";</script>
<div id="setupplayer" style="width:<?php echo $width . 'px'; ?>;">
    <div id="videoplayer">                </div></div>


<script type="text/javascript">
  var myUserAgent = navigator.userAgent;

  var myUserAgent = navigator.userAgent;
  var currentItem = 0;
  //var videoSectionId=321;
  var vdopiavideoid = '15719';
  //var arrPlaylist=[""];

  var autoplay = "true";
  var mp4videoFlagJS = 1;
  //$(document).ready(function() {	

  function loadplayerjw() {

      // var playerInstance = jwplayer('videoplayer');
      jwplayer('videoplayer').setup({
          //var multipart=0;
          playlist: [{
                  title: "",
                  'image': "<?php echo  $player_content['player_image'];?>",
                  sources: [
                      {
                          file: "<?php echo $player_content['bitrate_url']; ?>"
                      }, {
                          file: "<?php echo $player_content['file_url']; ?>"

                      }]
              }],
          primary: "html5",
          width: "100%",
          height: "100%",
          aspectratio: "16:9",
          "stretching": "exactfit",
          androidhls: "true",
          fallback: "false",
          hlslabels: {"156": "lowest", "410": "low", "512": "medium", "996": "Highest"},
          sharing: {
              code: encodeURI("<iframe class='embedframe' src='http://indiatoday.intoday.in/embed/3d6foqhpi51c' width='100%' height='100%' frameborder='0' scrolling='no' />"),
              link: "http://indiatoday.intoday.in/embed/3d6foqhpi51c",
              heading: "Share video"
          },
          autostart: true,
          advertising: {
              client: "googima", skipoffset: 5,
              schedule: {"myAds": {"offset": "pre", "tag": "https://pubads.g.doubleclick.net/gampad/ads?sz=400x300|640x480&iu=/1007232/Indiatoday_VOD_Pre_Roll_WEB&impl=s&gdfp_req=1&env=vp&output=xml_vast2&unviewed_position_start=1&url=[referrer_url]&description_url=[description_url]&correlator=[timestamp]"}}},
          ga: {
              idstring: "",
              label: "73d673"
          }
      });
  }

  var playerInstance = jwplayer('videoplayer');
  loadplayerjw();
  playerInstance.on('setupError', function (event) {
      //alert('Setup Error:'+event.message);
      if (event.message == 'Error loading player: No playable sources found') {

          //alert(event.message);
          document.getElementById("videoplayer").innerHTML = '<span class="flasherror">Install Flash to Watch this Video</span><a target="_blank" href="https://get.adobe.com/flashplayer/" class="flashlogo"><img src="http://media2.intoday.in/images/getadobeflashplayer.gif" width="100"></a>';
      } else {
          loadplayerjw();
      }
  });

  //});           




</script>




<script>
  $(document).ready(function () {

      playerInstance.play();

  });

  var duration = jwplayer().getDuration();
</script>