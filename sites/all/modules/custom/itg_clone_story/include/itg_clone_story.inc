<?php

/**
 * Implements itg_clone_story_search_autocompletelabel().
 * @param string $string
 */
function itg_clone_story_search_autocompletelabel($string) {

  unset($results);
  $results = array();
  $matches = array();
  $num = '';
  $string = trim($string);
  //replace the space with %20
  $key = preg_replace('/[[:space:]]+/', '%20', $string);
  //number of results you want to show
  $num_result = 15;
  //your Solr server path
  $solr_server = variable_get('solr_server_url');

  //this is the trick. first you should capture the Solr query, which executed when you hit search. I use the Solr level module to catch the query. you can change parameters if you want, I'm only changing the search keyword and number of results
  $request_url = $solr_server . "/select?start=0&rows=$num_result&&spellcheck=true&q=label:$key+AND+bundle:story&fl=id%2Centity_id%2Centity_type%2Cbundle%2Cbundle_name%2Clabel%2Css_language%2Cis_comment_count%2Cds_created%2Cds_changed%2Cscore%2Cpath%2Curl%2Cis_uid%2Ctos_name%2Czm_parent_entity%2Css_filemime%2Css_file_entity_title%2Css_file_entity_url&mm=1&pf=content%5E2.0&ps=15&hl=true&hl.fl=content&hl.snippets=3&hl.mergeContigious=true&f.content.hl.alternateField=teaser&f.content.hl.maxAlternateFieldLength=256&spellcheck.q=$key&qf=content%5E40&qf=label%5E21.0&qf=tags_h1%5E3.0&qf=tags_h2_h3%5E3.0&qf=tags_inline%5E1.0&qf=taxonomy_names%5E2.0&qf=tos_name%5E3.0&facet=true&facet.sort=count&facet.mincount=1&facet.field=im_field_taxonomy_app_cat&f.im_field_taxonomy_app_cat.facet.limit=50&f.im_field_taxonomy_app_cat.facet.mincount=1&boost=eff_popularity&debugQuery=on&wt=json&json.nl=map";
  // Retrieve data from the external API
  $response = drupal_http_request($request_url);

  // Check the HTTP response code to see if a valid response was received
  if ($response->code >= 200 && $response->code < 300) {

    //make sure response has values
    if (isset($response)) {
      $results = (array) json_decode($response->data);
    }
    if (isset($results)) {
      //store the values into an array
      if (isset($results['response']->docs)) {
        $arrResults = $results['response']->docs;
      }
    }

    //check array count
    if (count($arrResults) > 0) {
      //loop the results and add to array for json return data
      foreach ($arrResults as $row) {
        $key = html_entity_decode($row->label, ENT_QUOTES);
          $matches[$key] = $row->label;
      }
    }
    else {
      $matches[''] = "No Results Found!";
    }
  }
  else {
    $matches[''] = "Check server settings!";
  }

  drupal_json_output($matches);
}

/**
 * Implements itg_clone_story_search_autocompleteid().
 * @param string $string
 */
function itg_clone_story_search_autocompleteid($string) {

  unset($results);
  $results = array();
  $matches = array();
  $num = '';
  $next = $string + 100;
  //replace the space with %20
  $key = preg_replace('/[[:space:]]+/', '%20', $string);
  //number of results you want to show
  $num_result = 15;
  //your Solr server path
  $solr_server = variable_get('solr_server_url');

  //this is the trick. first you should capture the Solr query, which executed when you hit search. I use the Solr level module to catch the query. you can change parameters if you want, I'm only changing the search keyword and number of results
  $request_url = $solr_server . "/select?start=0&rows=$num_result&&spellcheck=true&q=entity_id:$key+AND+bundle:story&fl=id%2Centity_id%2Centity_type%2Cbundle%2Cbundle_name%2Clabel%2Css_language%2Cis_comment_count%2Cds_created%2Cds_changed%2Cscore%2Cpath%2Curl%2Cis_uid%2Ctos_name%2Czm_parent_entity%2Css_filemime%2Css_file_entity_title%2Css_file_entity_url&mm=1&pf=content%5E2.0&ps=15&hl=true&hl.fl=content&hl.snippets=3&hl.mergeContigious=true&f.content.hl.alternateField=teaser&f.content.hl.maxAlternateFieldLength=256&spellcheck.q=$key&qf=content%5E40&qf=label%5E21.0&qf=tags_h1%5E3.0&qf=tags_h2_h3%5E3.0&qf=tags_inline%5E1.0&qf=taxonomy_names%5E2.0&qf=tos_name%5E3.0&facet=true&facet.sort=count&facet.mincount=1&facet.field=im_field_taxonomy_app_cat&f.im_field_taxonomy_app_cat.facet.limit=50&f.im_field_taxonomy_app_cat.facet.mincount=1&boost=eff_popularity&debugQuery=on&wt=json&json.nl=map";
  // Retrieve data from the external API
  $response = drupal_http_request($request_url);

  // Check the HTTP response code to see if a valid response was received
  if ($response->code >= 200 && $response->code < 300) {

    //make sure response has values
    if (isset($response)) {
      $results = (array) json_decode($response->data);
    }
    if (isset($results)) {
      //store the values into an array
      if (isset($results['response']->docs)) {
        $arrResults = $results['response']->docs;
      }
    }

    //check array count
    if (count($arrResults) > 0) {
      //loop the results and add to array for json return data
      foreach ($arrResults as $row) {
          $matches[$row->entity_id] = $row->entity_id;
      }
    }
    else {
      $matches[''] = "No Results Found!";
    }
  }
  else {
    $matches[''] = "Check server settings!";
  }

  drupal_json_output($matches);
}