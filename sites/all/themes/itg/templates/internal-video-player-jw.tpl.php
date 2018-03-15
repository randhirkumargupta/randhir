<?php
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/jwplayer.min.js', array('scope' => 'header'));
drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/jwplayer.gaevent.js', array('scope' => 'header'));
drupal_add_js('https://sb.scorecardresearch.com/c2/plugins/streamingtag_plugin_jwplayer.js', array('type' => 'external', 'scope' => 'header'));
global $base_url;
$node_url_data = url(current_path(), array('absolute' => false));
$explode_url = explode('/', $node_url_data);
$pub_date = get_content_publish_date($nid);
if (!empty($pub_date)) {
  $pub_date = date('Y-m-d', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
}
?>
<?php
$width = 622;
$height = 446;
$external_side = 0;
$data_video = itg_videogallery_get_video_xml_data_by_fid($data);
$video_all_data = json_decode($data_video[0]->video_xml_data, TRUE);
$refral_site = itg_common_get_domain($_SERVER["HTTP_REFERER"]);
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
$player_content = itg_videogallery_make_parm_for_jwpalyer($video_all_data, $used_on, $external_side);
if(empty($image)){
  $image = $base_url . "/" . drupal_get_path('theme', 'itg') . '/images/itg_image370x208.jpg';
}
?>
<div id="videoplayer"> </div>
<script type="text/javascript">
function deferjw(method) {
  if (window.jwplayer) {
    method();
  } else {
    setTimeout(function() { deferjw(method) }, 50);
  }
}
</script>
<script type="text/javascript">
  
  function loadplayerjw() {
      var player_dfp = "<?php echo urlencode($player_content['dfp_tags']); ?>";
      jwplayer.key = "XRiQ7SgnSBR9/smfQ9+YZsn3S7EMc/Am440mYg==";
      jwplayer('videoplayer').setup({
          playlist: [{
                  title: "<?php echo stripslashes($title); ?>",
                  mediaid:"vod_<?php echo $nid; ?>",
                  'image': "<?php echo $image; ?>",
                  sources: [
                      {
                          file: "<?php echo $player_content['bitrate_url']; ?>"
                      }, {
                          file: "<?php echo $player_content['file_url']; ?>"

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
          //autostart: true,
                  advertising: {
                      client: "googima", skipoffset: 5,
                      schedule: {"myAds": {"offset": "pre", "tag": decodeURIComponent(player_dfp)}}},
          ga: {
              idstring: "<?php echo stripslashes($title); ?>",
              label: ""
          }
      });
      
  }
  
  deferjw(loadplayerjw);
<?php
  $arg = arg();
  if(($arg[0] == 'video' && $arg[2] == 'embed')) { ?>
   ga('create', 'UA-20047041-23', 'auto');
   ga('send', 'pageview');
<?php } ?>

</script>

<?php
//drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/jwplayer.min.js', array('scope' => 'header'));
//drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/jwplayer.gaevent.js', array('scope' => 'header'));
?>
