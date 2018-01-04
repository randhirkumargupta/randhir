<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
global $base_url;
?>
  <script type="text/javascript" src="<?php echo $base_url.'/sites/all/modules/custom/itg_videogallery/js/jwplayer.min.js';?>"></script>

<?php
$width = 622;
$height = 446;
echo $data."hi andy";
$data_video = itg_videogallery_get_video_xml_data_by_fid($data);
$video_all_data = json_decode($data_video[0]->video_xml_data, TRUE);
$player_content = itg_videogallery_make_parm_for_jwpalyer($video_all_data);
print_r($player_content);

?>
<script>
  jwplayer.key = "XRiQ7SgnSBR9/smfQ9+YZsn3S7EMc/Am440mYg==";</script>

    <div id="videoplayer"> </div>
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
      if (event.message == 'Error loading player: No playable sources found') {
          document.getElementById("videoplayer").innerHTML = '<span class="flasherror">Install Flash to Watch this Video</span><a target="_blank" href="https://get.adobe.com/flashplayer/" class="flashlogo"><img src="http://media2.intoday.in/images/getadobeflashplayer.gif" width="100"></a>';
      } else {
          loadplayerjw();
      }
  });

           

</script>




<script>
  jQuery(document).ready(function () {

      playerInstance.play();

  });

  var duration = jwplayer().getDuration();
</script>