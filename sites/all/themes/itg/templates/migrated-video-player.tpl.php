<?php
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
// drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/jwplayer.min.js', array('scope' => 'header'));
// drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/jwplayer.gaevent.js', array('scope' => 'header'));
// drupal_add_js('https://sb.scorecardresearch.com/c2/plugins/streamingtag_plugin_jwplayer.js', array('type' => 'external', 'scope' => 'header'));
drupal_add_js('https://akm-img-a-in.tosshub.com/sites/player/jwplayer_config/jwplayer-lib-widget-1.0.js', array('type' => 'external', 'scope' => 'footer'));
drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/itg_dfp_tag.js', array('scope' => 'header'));
global $base_url;
$node_url_data = url(current_path(), array('absolute' => false));
$explode_url = explode('/', $node_url_data);
$pub_date = get_content_publish_date($nid);

// $video_node = node_load($nid);
// $tid = $video_node->field_primary_category[LANGUAGE_NONE][0]['value'];
// $term = get_term_name_from_tid($tid);
// $primary_category_name = itg_common_custompath_insert_val($term->name);

$argum = base64_encode($nid);
$primary_category_name = '';
$section_name = '';
$section_id = '';
$section_arr = itg_common_get_type_category($nid);
if(!empty($section_arr)){
  $section_id = $section_arr[0]['field_primary_category_value'];
}
if(isset($section_id) && is_numeric($section_id)){
  $section_name = get_term_name_from_tid($section_id)->name;
  $primary_category_name = itg_common_custompath_insert_val($term->name);
}
if (!empty($pub_date)) {
  $pub_date = date('Y-m-d', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
}
$node_url_alias = drupal_get_path_alias('node/'.$nid);
$node_url = FRONT_URL. "/" .$node_url_alias;
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
$autostart = "true";
if ($used_on == 'embed') {
  $autostart = "false";
}

$data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid, $used_on, $external_side);
?>
<div id="videoplayer"> </div>
<script type='text/javascript' >
var player_dfp = get_dfp_tags_script("<?php print $used_on; ?>", "<?php print $external_side; ?>", "<?php print $node_url; ?>");
var jwConfig = {
  config_url : 'https://akm-img-a-in.tosshub.com/sites/player/jwplayer_config/India_Today/it_player.js',
  content_id : "<?php echo $nid; ?>",//vdieo content id mandatory
  videoContainer :'videoplayer',  //  video contener element id
  /* playlist values .these parameter are mandatory*/
  file1: "<?php echo $data_video['bitrate_url']; ?>",
  file2: "<?php echo $data_video['file_url']; ?>",
  title: "<?php echo $title; ?>",
  media_id:"vod_<?php echo $nid; ?>",
  image: "<?php echo $image; ?>",

  /* share  sharing_link, sharing_code are mandatory*/
  sharing_link: "<?php echo  $node_url; ?>",
  sharing_code:encodeURI("<iframe src=\"<?php print $base_url . '/video/' .  $section_name . '/embed/' . $argum; ?>\" allowfullscreen  width='648' height='396' frameborder='0' scrolling='no' />"),

  hlslabels:{"156":"lowest","410":"low","512":"medium","864":"high","996":"Highest"},
  /*  */
  source:'jwplayer',//jwplayer/dailyomotion
  labelmapping: "c3=\"99000\", ns_st_pu=\"Indiatoday Group\", ns_st_ia=\"0\", ns_st_ge=\"<?php echo stripslashes($section_name); ?>\", ns_st_ddt=\"<?php echo $pub_date; ?>\", ns_st_ce=\"1\", ns_st_tdt=\"<?php echo $pub_date;?>\", ns_st_title=\"<?php echo ($title); ?>\", ns_st_ep=\"<?php echo ($title); ?>\", ns_st_pr=\"<?php echo ($title); ?>\"",

  publisherId: "8549097" ,
  /* show_ads : false,  */
  // overwrite ads code
  advertising: {
    client: "googima",
    skipoffset:5,
    schedule: {
      "myAds":{
        "offset":"pre", "tag":decodeURIComponent(player_dfp)
      }
    }
  },
};
</script>
