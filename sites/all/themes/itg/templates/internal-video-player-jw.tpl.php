<?php
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

drupal_add_js('https://akm-img-a-in.tosshub.com/sites/player/jwplayer_config/jwplayer-lib-widget-1.0.js', array('type' => 'external', 'scope' => 'footer'));
drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/itg_dfp_tag.js', array('scope' => 'header'));
global $base_url;
$node_url_data = url(current_path(), array('absolute' => false));
$explode_url = explode('/', $node_url_data);
$pub_date = get_content_publish_date($nid);

$argum = base64_encode($nid);
$primary_category_name = '';
$section_name = '';

if(isset($tid) && !empty($tid)){
  $section_name = get_term_name_from_tid($tid)->name;
  $primary_category_name = itg_common_custompath_insert_val($section_name);
}

if (!empty($pub_date)) {
  $pub_date = date('Y-m-d', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
}
$node_url_alias = drupal_get_path_alias('node/'.$nid);
$node_url = FRONT_URL. "/" .$node_url_alias;
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


<script type='text/javascript' >
<?php
  $arg = arg();
  if(($arg[0] == 'video' && $arg[2] == 'embed')) { ?>
   ga('create', 'UA-20047041-23', 'auto');
   ga('send', 'pageview');
<?php } ?>
var player_dfp = get_dfp_tags_script("<?php print $used_on; ?>", "<?php print $external_side; ?>", "<?php print $node_url; ?>");
var jwConfig = {
  config_url : 'https://akm-img-a-in.tosshub.com/sites/player/jwplayer_config/India_Today/it_player.js',
  content_id : "<?php echo $nid; ?>",//vdieo content id mandatory
  videoContainer :'videoplayer',  //  video contener element id
  /* playlist values .these parameter are mandatory*/
  file1: "<?php echo $player_content['bitrate_url']; ?>",
  file2: "<?php echo $player_content['file_url']; ?>",
  title: "<?php echo $title; ?>",
  media_id:"vod_<?php echo $nid; ?>",
  image: "<?php echo $image; ?>",

  /* share  sharing_link, sharing_code are mandatory*/
  sharing_link: "<?php echo  $node_url; ?>",
  sharing_code:encodeURI("<iframe src=\"<?php print $base_url . '/video/' . $primary_category_name . '/embed/' . $argum; ?>\" allowfullscreen  width='648' height='396' frameborder='0' scrolling='no' />"),

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
