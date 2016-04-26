<?php

/*
 * Inc file contains the functions
 */
function mobile_services_generator_of_content_old() {
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


function mobile_services_generator_of_content() {
 
  $result = get_services_result();
      
  foreach ($result as $item) {

    $sid = $item->association_service_target_id;
    $content_type = $item->service_content_type;
    $content_count = $item->service_content_count_value;
    $header = $item->header;
    $footer = $item->footer;
    $delivery_mode = $item->delivery_mode_value;
    $frequency = $item->frequency_value;
    $sharing_mode = $item->sharing_mode;
    
    
           $query = db_query("SELECT service_association.field_service_association_title_target_id AS association_service_target_id, 
          content_text.entity_id AS content_nid,
content_text.field_story_expert_description_value AS content_text,
content_image.field_story_large_image_fid AS content_image_fid,
content_image.field_story_large_image_width AS content_image_width,
content_image.field_story_large_image_height AS content_image_height
FROM field_data_field_service_association_title service_association 
left join field_data_field_story_expert_description as content_text ON service_association.entity_id = content_text.entity_id
left join field_data_field_story_large_image as content_image ON service_association.entity_id = content_image.entity_id
where service_association.field_service_association_title_target_id = '$sid' AND content_text.entity_id <>  'NULL'")->fetchAll();
           
           
    switch($delivery_mode){
    case 1:
        // Code for XMLs
      print_xml($query);
      
  
        break;
    case 2:
        // Code for RSS
        break;
    case 3:
      // Code for MRSS
      break;
    case 4:
      // Code for USSD
      break;
    case 5:
      // Code for SMS
      break;
    case 6:
      // Code for Simple Text Feed
      break;

    }
        
  }
  
  

}


function get_services_result() {
   $service_id = '210';
  $client_id = '2569';

  return $result = db_query("SELECT service_association.field_service_association_title_target_id AS association_service_target_id, 
      service_association.entity_id AS service_nid,
      service_content_type.field_service_content_type_value AS service_content_type,
      service_content_count.field_service_content_count_value AS service_content_count_value,
      service_header.field_header_value AS header,
      service_footer.field_footer_value AS footer,
      service_delivery.field_service_delivery_mode_value AS delivery_mode_value,
      service_frequency.field_service_frequency_value AS frequency_value,
      sharing_mode.field_content_sharing_mode_value AS sharing_mode,
      service_expiry_date.field_story_expiry_date_value,
      client_selection.field_client_selection_target_id AS client_target_id
      FROM field_data_field_service_association_title service_association 
      left join field_data_field_service_content_type as service_content_type ON service_association.entity_id = service_content_type.entity_id
      left join field_data_field_service_content_count as service_content_count ON service_association.entity_id = service_content_count.entity_id
      left join field_data_field_header AS service_header ON service_association.entity_id = service_header.entity_id
      left join field_data_field_footer AS service_footer ON service_association.entity_id = service_footer.entity_id
      left join field_data_field_service_delivery_mode AS service_delivery ON service_association.field_service_association_title_target_id = service_delivery.entity_id
      left join field_data_field_service_frequency AS service_frequency ON service_association.field_service_association_title_target_id = service_frequency.entity_id
      left join field_data_field_content_sharing_mode AS sharing_mode ON service_association.field_service_association_title_target_id = sharing_mode.entity_id
      left join field_data_field_story_expiry_date AS service_expiry_date ON service_association.field_service_association_title_target_id = service_expiry_date.entity_id
      left join field_data_field_client_selection AS client_selection ON service_association.entity_id = client_selection.entity_id
      where service_expiry_date.field_story_expiry_date_value > now() AND client_selection.field_client_selection_target_id = '$client_id' AND service_association.field_service_association_title_target_id = '$service_id'")->fetchAll();

  
}


function print_xml($query) {
  
   foreach ($query as $row) {
            //echo "<pre>";
            //print_r($row);
            //echo "</pre>";
            $content_text = $row->content_text;
            $content_image_fid = $row->content_image_fid;
            $content_image_width = $row->content_image_width;
            $content_image_height = $row->content_image_height;
            
            $file_path = drupal_realpath('public://');
            $file_path = '/var/www/html/itgcms/sites/default/files/mobile_xml';
            $dom = new DOMDocument('1.0','UTF-8');
            $dom->formatOutput = true;
            
            $root = $dom->createElement('feed');
            $dom->appendChild($root);
            $root->appendChild( $dom->createElement('provider', $content_text) );
            $root->appendChild( $dom->createElement('language', $content_text) );
            
            $currentTrack = $dom->createElement("news");
            $currentTrack = $root->appendChild($currentTrack);
            $currentTrack->appendChild($dom->createElement('category','Scores'));
            
            $result = $dom->createElement('item');
            $root->appendChild($result);
            
            $result->setAttribute('id', $key+1);
            $result->appendChild( $dom->createElement('title', $content_text) );
            $result->appendChild( $dom->createElement('body', $content_image_fid) );
            $result->appendChild( $dom->createElement('headline', $header) );
        }
    $dom->save($file_path.'/result.xml') or die('XML Create Error');    
      
}