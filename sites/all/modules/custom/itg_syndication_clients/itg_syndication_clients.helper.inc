<?php

/**
 * @file
 * The ITG Syndication clients for store configuration
 */

function getbsb_client_array() {
  $story = array(
    '1206533' => 'it-story-movies.xml',
    '1206550' => 'it-story-sports.xml',
    '1206567' => 'it-story-lifestyle.xml',
    '1206574' => 'it-story-business.xml',
    '1206577' => 'it-story-world.xml',
    '1206578' => 'it-story-india.xml',
    '1206676' => 'it-story-cricket.xml',
    '1206687' => 'it-story-topstories.xml',
    '1206719' => 'it-story-elections.xml',
    '1206793' => 'it-story-foodanddrink.xml',
    '1206796' => 'it-story-television.xml',
    '1207046' => 'it-story-gossip.xml',
    '1207051' => 'it-story-north.xml',
    '1207536' => 'it-story-ipl-2013.xml',
    '1207645' => 'it-story-diary.xml',
    '1207665' => 'it-story-ground-report.xml',
    '1207666' => 'it-story-highlights.xml',
    '1207667' => 'it-story-more-stories.xml',
    '1207715' => 'it-story-mobile-main.xml',
    '1208001' => 'it-story-news.xml',
    '1208185' => 'it-story-uttar-pradesh.xml',
    '1208365' => 'it-story-gujarat.xml',
    '1208366' => 'it-story-karnataka.xml',
    '1208367' => 'it-story-tamilnadu.xml',
    '1208368' => 'it-story-maharashtra.xml',
    '1208369' => 'it-story-westbengal.xml',
  );
  return $story;
}


function getbsb_client_photo_array(){
  $photo = array(
    '1208655' => 'cinema-superfast-photos.xml',
  );
  return $photo;
}

function getbsb_client_video_array(){
  $video = array(
    '1206552' => 'video_latest.xml',
  );
  return $video;
}

function getindiatoday_yahoo_client_array(){
  $yahoo_story = array(
    'ids' => array(1206533,1206567,1206688,1206689,1206572,1206578),
    'filename' => 'top-indiatoday.xml'
  );
  return $yahoo_story;
}

function getmsn_story_section_array(){
  $msn_story = array(
    '1206589' => 'msn/indiatoday/story-travel.xml',
    '1206793' => 'msn/indiatoday/story-food.xml',
    '1206567' => 'msn/indiatoday/story-lifestyle.xml',
    '1206676' => 'msn/indiatoday/story-cricket.xml',
    '1206578' => 'msn/indiatoday/latest-news.xml',
    '1206734' => 'msn/mailtoday/story-msn-mail-today.xml',
    '1207674' => 'msn/indiatoday/story-national.xml',
    '1207675' => 'msn/indiatoday/story-sports.xml',
    '1207676' => 'msn/indiatoday/story-states.xml',
    '1207677' => 'msn/indiatoday/story-health.xml',
    '1207678' => 'msn/indiatoday/story-leisure.xml',
    '1207868' => 'msn/indiatoday/story-wellness.xml',
    '1207044' => 'msn/indiatoday/story-whats-hot.xml',
    '1207039' => 'msn/indiatoday/story-relationship.xml',
    '1207103' => 'msn/indiatoday/story-fashion.xml',
    '1207862' => 'msn/indiatoday/story-music.xml',
    '1207869' => 'msn/indiatoday/story-culture.xml',
    '1207947' => 'msn/indiatoday/story-people.xml',
    '1207861' => 'msn/indiatoday/story-celebrity.xml',
    '1206931' => 'msn/indiatoday/story-aspire.xml',
    '1206942' => 'msn/indiatoday/story-spice.xml',
    '1206930' => 'msn/indiatoday/story-home.xml',
    '1206932' => 'msn/indiatoday/story-woman.xml',
    '1207679' => 'msn/mailtoday/story-national.xml',
    '1207681' => 'msn/mailtoday/story-sports.xml',
    '1207682' => 'msn/mailtoday/story-states.xml',
    '1207680' => 'msn/mailtoday/story-entertainment.xml',
    '1207044' => 'xml_it/stories/fromthemagazine.xml',
    '1206533' => 'xml_it/stories/movies.xml',
    '1208384' => 'msn/mailtoday/story-cricket.xml'
  );
  return $msn_story;
}

function get_cabbytabby_feed_videos_array(){
  $cabbytabby_feed_videos = array(
    '1207580' => 'sosorry.xml'
  );
  return $cabbytabby_feed_videos;
}