<?php
/**
 * @file
 * online_story_archive.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function online_story_archive_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'Arun server';
  $environment->url = 'http://54.86.136.158:8080/solr';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_access_always_add_grants' => 0,
    'apachesolr_direct_commit' => 0,
    'apachesolr_read_only' => '0',
    'apachesolr_soft_commit' => 0,
    'multisitesearch' => 1,
    'multisitesearch_sites' => array(
      '2e1u4m' => '2e1u4m',
      'e49it8' => 'e49it8',
      '5fyeg7' => '5fyeg7',
    ),
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'ads_management',
      1 => 'blog',
      2 => 'magazine',
      3 => 'photogallery',
      4 => 'podcast',
      5 => 'story',
      6 => 'videogallery',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
