<?php

function itg_zuppit_feed_latest_story(){
  global $base_url;
  $page_number = (isset($_GET['pageNumber']) ? $_GET['pageNumber'] : 0);
  $pagesize = (isset($_GET['pagesize']) ? $_GET['pagesize'] : 50);
  $partner = 'zuppit';
  $type = array('story');
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  
  $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');  

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('sli', array('field_story_large_image_fid'));  
  $query->fields('pc', array('field_primary_category_value'));  

  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('n.status', 1);
  $query->condition('n.type', $type, 'IN');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range($page_number, $pagesize);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  
  $json_output = array();
  $json_output['code'] = 200;
  $json_output['error'] = NULL;  
  $json_output['data']['size'] = count($result);
  $json_output['data']['nextPage'] = $base_url.'/ucbrowser/story/feed/??pageNumber='.($page_number+1).'&pagesize='.$pagesize.'&partner='.$partner;
  $json_output['data']['rows'] = array();
  foreach($result as $value){
    $nid = $value['nid'];
    $publish_date = strtotime($value['field_itg_content_publish_date_value']);
    $city = get_content_city($value['nid']);
    $tags = get_content_tags($value['nid']);
    $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);
    
    $url = $base_url . "/" . drupal_get_path_alias('node/' . $value['nid']);
    $body = remove_extra_tag_in_body($value["body_value"]);
    $category_name = get_term_name_by_tid($value['field_primary_category_value']);
    $json_output['data']['rows'][] = array(
      'id'=>$nid,
      'language'=>"English",
      'title'=>$value["title"],
      'category'=>$category_name,
      'tags'=>$tags,
      'summary'=>$value["title"],
      'detailUrl'=>$url,
      'pages'=>array(
        'pageNumber' => 1,
        'pageContent' => $body,
        'originalUrl' => $url,
      ),
      'articleFrom'=>'',
      'publishTime'=>$publish_date,
      'createTime'=>$value['created'],
      'coverPic'=>array($large_img['imag_url']),
      'province'=>'',
      'city'=>$city,
    );
  }
  drupal_json_output($json_output);
  drupal_exit();
}