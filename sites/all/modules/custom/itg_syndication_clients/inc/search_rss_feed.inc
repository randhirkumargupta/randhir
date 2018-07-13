<?php
/**
 * Call back function for search API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_search_data_rest_fun() {
    $key_title = $_GET['key'];
    $nid_ar = array();
    $searchpage = solr_search_custom_results_restapi_fun($key_title);

    $data_json = array();
    $data = array();
    $list = array();
    $loop_c = 0;
    if(!empty($searchpage)){
      foreach ($searchpage as $key => $result) {
          $nid = $result->entity_id;
          $title = $result->label;
          $image_courtesy = FRONT_URL;

          $extra_large_image = empty($result->sm_field_custom_story_extra_large_url[0]) ? '' : $result->sm_field_custom_story_extra_large_url[0];
          $field_story_medium_image = empty($result->sm_field_custom_story_medium_large_url[0]) ? '' : $result->sm_field_custom_story_medium_large_url[0];
          $byline = empty($result->sm_field_itg_common_by_line_name[0]) ? '' : $result->sm_field_itg_common_by_line_name[0];
          $body = empty($result->content) ? '' : $result->content;
          $changed = date("Y-m-d H:i:s", strtotime($result->ds_changed));
          $bundle = empty($result->bundle) ? '' : $result->bundle;
          $url = empty($result->url) ? '' : $result->url;
          $teaser = empty($result->teaser) ? '' : $result->teaser;
          $ds_changed = empty($result->ds_changed) ? '' : $result->ds_changed;
          $list[$loop_c]['n_id'] = "$nid";
          //$list[$loop_c]['n_type'] = "$bundle";
          if ($bundle == "breaking_news") {
                  $list[$loop_c]['n_type'] = "story";
                  $list[$loop_c]['n_is_blog'] = "1";
              } else {
                  $list[$loop_c]['n_type'] = "$bundle";
                  $list[$loop_c]['n_is_blog'] = "0";
              }
          $date_val = date("Y-m-d H:i:s", strtotime($ds_changed));
          $list[$loop_c]['n_is_sponsored'] = "0";
          $list[$loop_c]['n_share_link'] = "$url";
          $list[$loop_c]['n_title'] = "$title";
          $list[$loop_c]['n_short_desc'] = "$teaser";
          $list[$loop_c]['n_small_image'] = "$field_story_medium_image";
          $list[$loop_c]['n_large_image'] = "$extra_large_image";
          $list[$loop_c]['n_updated_datetime'] = "$date_val";
          $loop_c++;
      }
    }
    $data_json['status_code'] = "1";
    $data_json['status_message'] = "";
    if ($loop_c == 0) {
        $data_json['status_code'] = "0";
        $data_json['status_message'] = "";
    }
    $data['id'] = "0";
    $data['search_title'] = "$key_title";
    $data['layout_id'] = "0";
    $data['news_count'] = "$loop_c";
    $data['news_display_count'] = "100";
    $data['news_pagination_cap'] = "50";
    $data['updated_datetime'] = "";
    $data['news'] = $list;
    $data_json['data'] = $data;
    print_r($data_json);
    die('qwerty');

    echo $xml = generate_rss_feed_search_xml($result);
    die;


}
/**
 * Callback for solr service.
 */
function solr_search_custom_results_restapi_fun($key) {
    $results = array();
    try {
        $key = preg_replace('/\s+/', ' OR ', $key);
        $solr = apachesolr_get_solr();
        $query = apachesolr_drupal_query("custom", array('q' => $key));
        $query->setSolrsort('ds_changed', 'desc');
        $query->removeFilter('bundle_name');
        $query->addParam('fq', "hash:(" . apachesolr_site_hash() . ")");
        $query->addParam('rows', '100');
        //$query->addParam('fq', "bundle_name:Video");
        //$query->addParam('sort', "ds_changed DESC");
        $resp = $query->search();
        if (!empty($resp->data)) {
            $data = json_decode($resp->data);
        }
        $results = $data->response->docs;
    } catch (Exception $e) {
        watchdog('solr_service', $e->getMessage(), NULL, WATCHDOG_ERROR);
        apachesolr_failure(t('Solr search'), $key);
    }

    if ($results and is_array($results) and count($results)) {
        return $results;
    }
    return array();
}

/**
 *
 * @global string $base_url
 * @param array $result
 * @return string
 */
function generate_rss_feed_search_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<Data>';
    // foreach ($result as $key => $value) {
    //   if (is_lock_story($value['nid'])) {
    //     continue;
    //   }
    //   $publish_date = date("D, j M Y H:i:s", strtotime($value['field_itg_content_publish_date_value']));
    //   $medium_img = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
    //   $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
    //   $body = remove_extra_tag_in_body($value["body_value"]);
    //   $body = itg_replace_token_with_data($body, $value['nid']);
    //   $body = itg_remove_extra_custom_tags($body);
    //   $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
    //   $xml .= '<item>';
    //   $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
    //   $xml .= '<link><![CDATA[' . $url . ']]></link>';
    //   $xml .= '<pubdate><![CDATA[' . $publish_date . ' +0000 ]]></pubdate>';
    //   $xml .= '<image>' . $medium_img['imag_url'] . '</image>';
    //   $xml .= '<youtubeEmbedURL></youtubeEmbedURL>';
    //   $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
    //   $xml .= '<content><![CDATA[' . $body . ']]></content>';
    //   $xml .= '</item>';
    // }
    $xml .= '</Data>';
  }
  return $xml;
}
