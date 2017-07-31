<?php

$video_detail_flag = generateVideoDetailPageFeed($nid, $term_feed_path, $file_name);
$photo_detail_flag = generatePhotoDetailPageFeed($nid, $term_feed_path, $file_name);
$story_detail_flag = generateStoryDetailPageFeed($nid, $term_feed_path, $file_name);

// generate photo detail page
$fl = generatePhotoDetailPageFeed($nid);

// generate story detail page
$fl = generateStoryDetailPageFeed($nid);

// generate video detail page
$fl = generateVideoDetailPageFeed($nid);


$query = db_select('itg_widget_order', 'iwo');
$query->leftJoin('node', 'n', 'n.nid=iwo.nid');

//->orderBy('iwo.weight', $order_by);

$alias = drupal_get_path_alias('node/' . $nid . '');
$weburl = $base_url . "/" . $alias;


getRedis($key);
//return array building

$result['key_value'] = $key_value;
setRedis($key, $output);
//return array building

$result['set_flag'] = $set_flag;
