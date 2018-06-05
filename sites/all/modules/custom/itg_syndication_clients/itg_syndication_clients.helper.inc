<?php

/**
 * @file
 * The ITG Syndication clients for store configuration
 */

/**
 * Function is used to get BSB Story tids and File
 * @return array
 */
function getbsb_client_array() {
  $story = array(
    '1206584' => 'indiatoday_stories.xml',
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
    //'1207536' => 'it-story-ipl-2013.xml',
    //'1207645' => 'it-story-diary.xml',
    //'1207665' => 'it-story-ground-report.xml',
    //'1207666' => 'it-story-highlights.xml',
    //'1207667' => 'it-story-more-stories.xml',
    //'1207715' => 'it-story-mobile-main.xml',
    //'1208001' => 'it-story-news.xml',
    //'1208185' => 'it-story-uttar-pradesh.xml',
    //'1208365' => 'it-story-gujarat.xml',
    //'1208366' => 'it-story-karnataka.xml',
    //'1208367' => 'it-story-tamilnadu.xml',
    //'1208368' => 'it-story-maharashtra.xml',
    //'1208369' => 'it-story-westbengal.xml',
  );
  return $story;
}

/**
 * Function is used to get BSB Photo tids and File
 * @return array
 */
function getbsb_client_photo_array() {
  $photo = array(
    '1208655' => 'cinema-superfast-photos.xml',
  );
  return $photo;
}

/**
 * Function is used to get BSB Video tids and File
 * @return array
 */
function getbsb_client_video_array() {
  $video = array(
    '1206552' => 'video_latest.xml',
    '1206952' => 'video_entertainment.xml',
    '1206955' => 'video_india.xml',
    '1206956' => 'video_world.xml',
    '1206957' => 'video_sports.xml',
    '1206959' => 'video_business.xml',
    '1207303' => 'video_movies.xml',
    '1207304' => 'video_lifestyle.xml',
  );
  return $video;
}

/**
 * Function is used to get Yahoo tids and File
 * @return array
 */
function getindiatoday_yahoo_client_array() {
  $yahoo_story = array(
    'ids' => array(1206533, 1206567, 1206688, 1206689, 1206572, 1206578),
    'filename' => 'top-indiatoday.xml'
  );
  return $yahoo_story;
}

/**
 * Function is used to get Yahoo video tids and File
 * @return array
 */
function getindiatoday_yahoo_client_sections() {
  $video = array(
    'top' => 'top-indiatoday-20170407.xml',
    '1206533' => 'movies.xml',
    '1206689' => 'auto.xml',
    '1206567' => 'lifestyle.xml'
  );
  return $video;
}

/**
 * Function is used to get Yahoo video tids and File
 * @return array
 */
function itg_indiatoday_yahoo_unionbudget2018_section() {
  $unionbudget2018 = array(
    'unionbudget2018.xml' => array(1778508, 1783640, 1783624, 1783641, 1783642, 1783643)
  );
  return $unionbudget2018;
}

/**
 * Function is used to get msn story tids and File
 * @return array
 */
function getmsn_story_section_array() {
  $msn_story = array(
    'msn/indiatoday/story-movies.xml' => 1206533,
    'msn/indiatoday/story-travel.xml' => 1206589,
    'msn/indiatoday/story-food.xml' => 1206793,
    'msn/indiatoday/story-lifestyle.xml' => 1206567,
    'msn/indiatoday/story-cricket.xml' => 1206676,
    'msn/indiatoday/latest-news.xml' => 1206578,
    'msn/mailtoday/story-msn-mail-today.xml' => 1206734,
    'msn/indiatoday/story-national.xml' => 1207674,
    'msn/indiatoday/story-sports.xml' => 1206550,
    'msn/indiatoday/story-states.xml' => 1207676,
    'msn/indiatoday/story-health.xml' => 1207677,
    'msn/indiatoday/story-leisure.xml' => 1207678,
    'msn/indiatoday/story-wellness.xml' => 1207868,
    'msn/indiatoday/story-whats-hot.xml' => 1207044,
    'msn/indiatoday/story-relationship.xml' => 1207039,
    'msn/indiatoday/story-fashion.xml' => 1207103,
    'msn/indiatoday/story-music.xml' => 1207862,
    'msn/indiatoday/story-culture.xml' => 1207869,
    'msn/indiatoday/story-people.xml' => 1207947,
    'msn/indiatoday/story-celebrity.xml' => 1207861,
    'msn/indiatoday/story-aspire.xml' => 1206931,
    'msn/indiatoday/story-spice.xml' => 1206942,
    'msn/indiatoday/story-home.xml' => 1206930,
    'msn/indiatoday/story-woman.xml' => 1206932,
    'msn/mailtoday/story-national.xml' => 1207679,
    'msn/mailtoday/story-sports.xml' => 1207681,
    'msn/mailtoday/story-states.xml' => 1207682,
    'msn/mailtoday/story-entertainment.xml' => 1207680,
    'msn/mailtoday/story-cricket.xml' => 1208384,
    'msn/indiatoday/story-world.xml' => 1206577,
    'msn/indiatoday/story-india.xml' => 1206578,
    'msn/indiatoday/story-top-stories.xml' => 1206584,
    'msn/indiatoday/story-technology.xml' => 1206688,
    'msn/indiatoday/story-auto.xml' => 1206689,
    'msn/mailtoday/story-education.xml' => 1206666,
    'msn/mailtoday/story-television.xml' => 1206796,
    'msn/mailtoday/story-latest-of-the-lot.xml' => 1206723,
    'msn/indiatoday/from-india-today-magazine.xml' => 1206598,
    'msn/indiatoday/karnataka-election-2018.xml' => 1790070
      
      
  );
  return $msn_story;
}

/**
 * Function is used to get Cabbytabby Video tids and File
 * @return array
 */
function get_cabbytabby_feed_videos_array() {
  $cabbytabby_feed_videos = array(
    '1207580' => 'sosorry.xml'
  );
  return $cabbytabby_feed_videos;
}

/**
 * Function is used to get Ola tids and File
 * @return array
 */
function get_ola_feed_videos_array() {
  $cabbytabby_feed_videos = array(
    '1207580' => 'sosorry.xml',
    '1207978' => 'auto_today.xml',
    '1207304' => 'lifestyle.xml',
    '1208898' => 'person_of_interest.xml',
    '1208061' => 'the_long_story.xml',
    '1208898' => 'person_of_interest.xml',
    '1207303' => 'movies.xml',
  );
  return $cabbytabby_feed_videos;
}

/**
 * Function is used to get Dekho Video tids and File
 * @return array
 */
function get_dekkho_feed_videos_array() {
  $video_sectios = array(
    '1207304' => 'lifestyle.xml',
    '1207978' => 'auto_today.xml',
    '1208177' => 'education.xml',
    '1207580' => 'sosorry.xml',
    '1207303' => 'bollywood_movie_reviews.xml',
    '1206955' => 'india.xml',
    '1208164' => 'worldspecial.xml',
    '1206957' => 'sportscricket.xml',
    '1207872' => 'moneytoday.xml'
  );
  return $video_sectios;
}

/**
 * Function is used to get Proquest Story tids and File
 * @return array
 */
function getproquest_feed_story_client_array() {
  $story_sectios = array(
    '1206578' => 'india.xml',
    '1206793' => 'food-drink.xml',
    '1206572' => 'mailtoday.xml',
    '1206638' => 'mustread.xml',
    '1206688' => 'technology.xml',
    '1206584' => 'topstories.xml',
    '1206589' => 'travel.xml',
    '1206577' => 'world.xml',
  );
  return $story_sectios;
}

/**
 * Function is used to get Proquest Story tids and File
 * @return array
 */
function getceltick_feed_story_client_array() {
  $story_sectios = array(
    '1206578' => 'india.xml',
    '1206795' => 'fyi.xml',
    '1206567' => 'lifestyle.xml',
    '1206533' => 'movies.xml',
    '1206550' => 'sports.xml',
    '1206676' => 'cricket.xml'
  );
  return $story_sectios;
}

/**
 * Function is used to get Dailyhunt story tids and File
 * @return array
 */
function get_dailyhunt_sections_for_feed() {
  $story_sectios = array(
    '1206599' => 'celebrities.xml',
    '1206795' => 'fyi.xml',
    '1206600' => 'gossip.xml',
    '1206578' => 'india.xml',
    '1206567' => 'lifestyle.xml',
    '1206598' => 'magazine.xml',
    '1206572' => 'mailtoday.xml',
    '1206533' => 'movies.xml',
    '1206550' => 'sports.xml',
    '1206944' => 'supplementsgujarati.xml',
    '1207249' => 'supplementshyderabad.xml',
    '1206947' => 'supplementsmumbai.xml',
    '1206942' => 'supplementsspice.xml',
    '1206499' => 'supplementshome.xml',
    '1206688' => 'technology.xml',
    '1206796' => 'television.xml',
    '1206577' => 'world.xml',
    '1206584' => 'latestnews.xml',
  );
  return $story_sectios;
}

/**
 * Function is used to get Video Elephant Video tids and File
 * @return array
 */
function get_videoelephant_feed_videos_array() {
  $story_sectios = array(
    '1207304' => 'lifestyle.xml',
    '1207916' => 'cookery.xml',
    '1207580' => 'sosorry_polytoons.xml',
    '1208177' => 'education_today.xml',
    '1207978' => 'auto_today.xml',
    '1206955' => 'india.xml',
    '1208164' => 'world.xml',
    '1207303' => 'bollywood_movie_reviews.xml'
  );
  return $story_sectios;
}

/**
 * Function is used to get Hltapps tids and File
 * @return array
 */
function get_hltapps_sections($type) {
  switch ($type) {
    case 'story':
      return array(
        'topnews.xml' => '-1',
        'india.xml' => '1206578',
        'entertainment.xml' => '1206749',
        'world.xml' => '1206577',
        'sports.xml' => '1206550',
        'business.xml' => '1206574',
        'so-sorry.xml' => '1709237',
        'election.xml' => '1206719'
      );
      break;
    case 'video':
      return array(
        'topten.xml' => array('section' => '-1', 'limit' => 10),
        'news.xml' => array('section' => '-1', 'limit' => 25),
        'india.xml' => array('section' => '1206955', 'limit' => 25),
        'world.xml' => array('section' => '1206956', 'limit' => 25),
        'sports.xml' => array('section' => '1206550', 'limit' => 25),
        'so-sorry.xml' => array('section' => '1207580', 'limit' => 25),
        'entertainment.xml' => array('section' => '1206952', 'limit' => 25),
        'business.xml' => array('section' => '1206959', 'limit' => 25),
        'election.xml' => array('section' => '1207655', 'limit' => 25)
      );
    case 'photo':
      return array(
        'india.xml' => array('section' => '1208560', 'limit' => 25),
        'world.xml' => array('section' => '1208562', 'limit' => 25),
        'sports.xml' => array('section' => '1208561', 'limit' => 25),
        'entertainment.xml' => array('section' => '1208559', 'limit' => 25),
        'business.xml' => array('section' => '1208558', 'limit' => 25),
        'must-see.xml' => array('section' => '1208598', 'limit' => 25),
        'election.xml' => array('section' => '1208667', 'limit' => 25)
      );
    case 'programme':
      return array(
        'sports-today.xml' => array('section' => '1206960', 'limit' => 25),
        'news-today.xml' => array('section' => '1207797', 'limit' => 25),
        'to-the-point.xml' => array('section' => '1207722', 'limit' => 25),
        'newsroom.xml' => array('section' => '1207827', 'limit' => 25),
        'first-up.xml' => array('section' => '1207755', 'limit' => 25),
        'popular-show.xml' => array('section' => '1208908', 'limit' => 25),
        'person-of-interest.xml' => array('section' => '1208898', 'limit' => 25),
        'india-first.xml' => array('section' => '1208095', 'limit' => 25),
        'peoples-court.xml' => array('section' => '1208900', 'limit' => 25),
        //'lunch-break-.xml' => array('section'=> '1403', 'limit' => 25),
        '5ive-live-.xml' => array('section' => '1208902', 'limit' => 25),
        'auto-today.xml' => array('section' => '1207972', 'limit' => 25),
        'long-story.xml' => array('section' => '1208061', 'limit' => 25),
        'in-da-club.xml' => array('section' => '1208173', 'limit' => 25),
      );
      break;
    case 'mixed':
      return array(
        'news-mixed-view.xml' => array(
          'section' => -1,
          'title' => 'News Mixed View'
        ),
        'india-mixed-view.xml' => array(
          'section' => array(
            'story' => 1206578,
            'video' => 1206955,
            'photo' => 1208560,
          ),
          'title' => 'India Mixed View'
        ),
        'world-mixed-view.xml' => array(
          'section' => array(
            'story' => 1206577,
            'video' => 1206956,
            'photo' => 1208562,
          ),
          'title' => 'World Mixed View'
        ),
        'sosorry-mixed-view.xml' => array(
          'section' => array(
            'story' => 1709237,
            'video' => 1709237,
            'photo' => 1709237
          ),
          'title' => 'So Sorry Mixed View'
        ),
        'entertainment-mixed-view.xml' => array(
          'section' => array(
            'story' => 1206749,
            'video' => 1206952,
            'photo' => 1208559,
          ),
          'title' => 'Entertainment Mixed View'
        )
      );
      break;
    case 'msn_hlt_video':
      return array(
        'india.xml' => array('section' => '1206955', 'limit' => 15),
        'world.xml' => array('section' => '1206956', 'limit' => 15),
        'so-sorry.xml' => array('section' => '1207580', 'limit' => 15),
        'entertainment.xml' => array('section' => '1206952', 'limit' => 15),
        'movies.xml' => array('section' => '1207303', 'limit' => 15),
        'karnataka-election-2018.xml' => array('section' => '1790562', 'limit' => 15)
      );
      break;
    case 'programmes':
      return 1206553;
  }
}

/**
 * Function is used to get VUClip Video tids and File
 * @return array
 */
function get_vuclip_sections() {
  return array(
    'videsectionlist_program_sosorry.xml' => array('section' => '1207580', 'limit' => 25),
    'videsectionlist_program_tothepoint.xml' => array('section' => '1207722', 'limit' => 25),
    'videsectionlist_program_couching-with-koel.xml' => array('section' => '1207810', 'limit' => 25),
    'videsectionlist_program_news_today_at_nine.xml' => array('section' => '1207722', 'limit' => 25),
  );
}

/**
 * Function is used to get Mauj Video tids and File
 * @return array
 */
function get_mauj_sections() {
  return array(
    'videsectionlist_world.xml' => array('section' => '1206956', 'limit' => 25),
    'videsectionlist_movie.xml' => array('section' => '1207303', 'limit' => 25),
    'videsectionlist_sosorry.xml' => array('section' => '1207580', 'limit' => 25),
    'videsectionlist_latestvideo.xml' => array('section' => -1, 'limit' => 25)
  );
}

/**
 * Function is used to get Samsung Video tids and File
 * @return array
 */
function get_samsungtv_it_sections() {
  return array(
    'india.xml' => array('section' => 1206955, 'limit' => 25),
    'world.xml' => array('section' => 1206956, 'limit' => 25),
    'business.xml' => array('section' => 1206959, 'limit' => 25),
    'entertainment.xml' => array('section' => 1206952, 'limit' => 25)
  );
}

/**
 * Function is used to get Samsung Video tids and File
 * @return array
 */
function get_samsungtv_it_live_now_sections() {
  return array(
    1206958, 1206971, 1206967, 1206961, 1206963, 1206965, 1206968, 1206960
  );
}

/**
 * Function is used to get Election 2017 tids and File
 * @return array
 */
function get_elections2017_election_finals_sections() {
  return array(
    '1208078' => 'UP',
    '1208079' => 'punjab',
    '1208170' => 'Goa',
    '1208181' => 'Manipur',
    '1208183' => 'uttarakhand',
  );
}

/**
 * Function is used to get Micromax Video tids and File
 * @return array
 */
function get_micromax_videsectionlist_sections() {
  return array(
    'videsectionlist_sosorry.json' => array('section' => '1207580', 'limit' => 25),
    'videsectionlist_lifestyle.json' => array('section' => '1207304', 'limit' => 25),
    'videsectionlist_cricket.json' => array('section' => '1207443', 'limit' => 25),
    'videsectionlist_business.json' => array('section' => '1206959', 'limit' => 25)
  );
}

/**
 * Function is used to get Electio 2017 Video tids and File
 * @return array
 */
function getelections2016_westbenga_sections() {
  return array(
    1206846 => 'assemblyelections2016-westbengal.xml'
  );
}

function get_feed_base_url() {
  return 'http://feeds.intoday.in';
}

function get_content_fetch_time($section_id) {
  $time_array = array(
    '1206577' => 15,
    '1206533' => 10,
    '1206552' => 10,
    '1206550' => 15,
    '1206566' => 60,
    '1206567' => 10,
    '1206572' => 15,
    '1206574' => 60,
    '1206578' => 15,
    '1206640' => 10,
    '1206584' => 7,
    '1206638' => 30,
    '1206723' => 10,
    '1206666' => 15,
    '1206670' => 15,
    '1206674' => 30,
    '1206676' => 15,
    '1206687' => 15,
    '1206688' => 30,
    '1206689' => 30,
    '1206719' => 15,
    '1206733' => 15,
    '1206955' => 10,
    '1207045' => 15,
    '1207048' => 60,
    '1207049' => 30,
    '1207051' => 30,
    '1207084' => 30,
    '1207085' => 30,
    '1207086' => 30,
    '1207113' => 90,
    '1207303' => 90,
    '1207440' => 180,
    '1208296' => 60,
    '1208365' => 60,
    '1208559' => 120,
    '1208561' => 120,
    '1208589' => 120,
    '1208598' => 120,
    '1208618' => 120,
    '1206734' => 30,
    '1207678' => 15, 
  );
  if (isset($time_array[$section_id])) {
    return $time_array[$section_id];
  }
  else {
    return 730;
  }
}

function get_factiva_sections() {
  return array('1206578' => 'india.xml',
    '-1' => 'latest-news.xml');
}
function get_factiva_sections_v1() {
  return array(
      '1206578' => 'india.xml',
      '1206577' => 'world.xml',
      '1206795' => 'fyi.xml',
      '1206567' => 'lifestyle.xml',
      '1206723' => 'latest-of-the-lot.xml',
      '1206584' => 'top-stories.xml',
      '1206572' => 'mail-today.xml',
      '1206674' => 'home-top.xml',
      '1206688' => 'technology.xml',
      '1206689' => 'auto.xml',
      '1206676' => 'cricket.xml',
      '1206638' => 'must-read.xml',
      '1206670' => 'buzz-tool.xml',
      '1206733' => 'msn-it.xml',
      '1206735' => 'msn-itt.xml',
      '1207926' => 'food.xml',
      '1206589' => 'travel.xml',
      '1206550' => 'sports.xml',
      '1206796' => 'television.xml',
      '1206734' => 'msn-mail-today.xml',
      );
}


function get_samsung_video_category(){
  return array(
    'videolist-featured.json' => 1, 
    'videolist-popular-now.json' => 1207974, 
    'videolist-india.json' => 1206955, 
    'videolist-movie.json' => array(1207303,1207980),
    'videolist-tech.json' => 1207486, 
    'videolist-sosorry.json' => 1207580, 
    'videolist-news-today.json' => 1207797, 
    'videolist-newsroom.json' => 1207827, 
    'videolist-to-the-point.json' => 1207722, 
    'videolist-people-court.json' => 1208900, 
    'videolist-india-first.json' => 1208095, 
    'videolist-5ive-live.json' => 1208902, 
    'videolist-in-the-club.json' => 1208173, 
    'videolist-first-up.json' => 1207755, 
    'videolist-sports-today.json' => 1206960, 
    'videolist-auto-today.json' => 1207978, 
    'videolist-long-story.json' => 1208061, 
    'videolist-world.json' => 1206956, 
    'videolist-world-special.json' => 1208164, 
    'videolist-television.json' => 1207980
  );
}
/**
 * 
 * @param type $str
 * @return type
 */
function badUnicodeparse_clients($str) {
    $str = preg_replace("/\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1")).chr(hexdec("$2")).chr(hexdec("$3")).chr(hexdec("$4"))', $str);
    $str = preg_replace("/\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1")).chr(hexdec("$2")).chr(hexdec("$3"))', $str);
    $str = preg_replace("/\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1")).chr(hexdec("$2"))', $str);
    $str = preg_replace("/\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1"))', $str);
    return $str;
}
