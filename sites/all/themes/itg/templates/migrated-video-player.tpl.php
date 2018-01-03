<?php
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/jwplayer.min.js', array('scope' => 'header'));
drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/jwplayer.gaevent.js', array('scope' => 'header'));
global $base_url;
?>

<?php
$refral_site = itg_common_get_domain($_SERVER["HTTP_REFERER"]);
$external_side = 0;
if (!empty($refral_site)) {
  if (strpos($base_url, $refral_site) === false) {
    $external_side = 1;
    $used_on = 'embed';
  }
}
$autostart = "TRUE";
if ($used_on == 'embed') {
  $autostart = "FALSE";
}

$data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid, $used_on, $external_side);
?>
<div id="videoplayer"> </div>
<script type="text/javascript">
  jwplayer.key = "XRiQ7SgnSBR9/smfQ9+YZsn3S7EMc/Am440mYg==";
  function loadplayerjw() {
      var player_dfp = "<?php echo urlencode($data_video['dfp_tags']); ?>";
      jwplayer('videoplayer').setup({
          playlist: [{
                  title: "<?php echo stripslashes($title); ?>",
                  'image': "<?php echo $image; ?>",
                  sources: [
                      {
                          file: "<?php echo $data_video['bitrate_url']; ?>"
                      },
                      {
                          file: "<?php echo $data_video['file_url']; ?>"

                      }]
              }],
          primary: "html5",
          autostart: "<?php echo $autostart; ?>",
          width: "100%",
          height: "100%",
          aspectratio: "4:3",
          "stretching": "uniform",
          androidhls: "true",
          //fallback: "false",
          hlslabels: {"156": "lowest", "410": "low", "512": "medium", "996": "Highest"},
          autostart: true,
                  advertising: {
                      client: "googima", skipoffset: 5,
                      schedule: {"myAds": {"offset": "pre", "tag": decodeURIComponent(player_dfp)}}},
          ga: {
              idstring: "<?php echo stripslashes($title); ?>",
              label: "<?php echo $player_content["ga_code"]; ?>"
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
  jQuery(document).ready(function () {

      playerInstance.play();

  });

</script>

<?php
//drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/jwplayer.min.js', array('scope' => 'header'));
//drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/jwplayer.gaevent.js', array('scope' => 'header'));
?>
