


<?php
if ($width == "") {
  $width = 420;
}
if ($height == "") {
  $height = 500;
}
if (arg(0) == 'embeded-video') {
  global $base_url;
  ?>

 <?php } 
$video_all_data = json_decode($video_data, TRUE);
$player_content = itg_videogallery_make_parm_for_jwpalyer($video_all_data);
?>
<script>
  jwplayer.key = "XRiQ7SgnSBR9/smfQ9+YZsn3S7EMc/Am440mYg==";</script>

<div id="videoplayer"> </div>


<script type="text/javascript">
  function loadplayerjw() {
var player_dfp = "<?php echo urlencode($player_content['dfp_tags']); ?>";
      jwplayer('videoplayer').setup({
          playlist: [{
                  title: "",
                  'image': "<?php echo $player_content['player_image']; ?>",
                  sources: [
                      {
                          file: "<?php echo $player_content['bitrate_url']; ?>"
                      }, {
                          file: "<?php echo $player_content['file_url']; ?>"

                      }]
              }],
          primary: "flash",
          autostart: "true",
          width: "100%",
          height: "100%",
          aspectratio: "16:9",
          "stretching": "uniform",
          androidhls: "true",
          fallback: "false",
          hlslabels: {"156": "lowest", "410": "low", "512": "medium", "996": "Highest"},
          autostart: true,
          advertising: {
              client: "googima", skipoffset: 5,
              schedule: {"myAds": {"offset": "pre", "tag": decodeURIComponent(player_dfp)}}},
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