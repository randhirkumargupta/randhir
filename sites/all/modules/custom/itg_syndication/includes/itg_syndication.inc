<?php

/*
 * Inc file contains the functions
 */
function feed_generator_of_content() {
  $node_array = array(220, 363);
  
  $file_path = drupal_realpath('public://');
  $file_path = '/var/www/html/itgcms/sites/default/files/syndication_xml';
  $dom = new DOMDocument('1.0','UTF-8');
	$dom->formatOutput = true;

	$root = $dom->createElement('student');
	$dom->appendChild($root);

	
  foreach ($node_array as $key => $val) {
    $node = node_load($val);
    //p($node);
    $result = $dom->createElement('result');
    $root->appendChild($result);
    $result->setAttribute('id', $key+1);
    $result->appendChild( $dom->createElement('title', $node->title) );
    $result->appendChild( $dom->createElement('body', $node->body[LANGUAGE_NONE][0]['value']) );
    $result->appendChild( $dom->createElement('headline', $node->body[LANGUAGE_NONE][0]['value']) );
    
  }
	//echo '<xmp>'. $dom->saveXML() .'</xmp>';
  
	$dom->save($file_path.'/result.xml') or die('XML Create Error');
}