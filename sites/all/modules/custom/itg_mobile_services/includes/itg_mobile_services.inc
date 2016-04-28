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
     // itg_mobile_services_generate_rss($query);
      
  
        break;
    case 2:
        // Code for RSS
      itg_mobile_services_generate_rss($query);
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
            
            $short_title1 = "<![CDATA[
Ramdev's business plan: Make Nestle's bird, Colgate's gate disappear
]]>";
            $short_title = "Ramdev's business plan: Make Nestle's bird, Colgate's gate disappear";
            
            $file_path = drupal_realpath('public://');
            $file_path = '/var/www/html/itgcms/sites/default/files/mobile_xml';
           // $dom = new DOMDocument('1.0','UTF-8');
           // $dom->formatOutput = true;
            $doc = new DOMDocument('1.0','UTF-8');
            $doc->formatOutput = true;
            //$doc->preserveWhiteSpace = false;     

            $root = $doc->appendChild($doc->createElement('feed'));
            $root = $doc->appendChild($root);
            $root->appendChild( $doc->createElement('provider', 'indiatoday') );
            $root->appendChild( $doc->createElement('language', 'en-US') );
            
            $items = $root->appendChild($doc->createElement('news'));

            $item = $doc->createElement('item');
            $item->appendChild($doc->createElement('id', 'Noodle'));
            $item->appendChild($doc->createCDATASection($short_title));
            $item->appendChild($doc->createCDATASection($short_title));
            $item->appendChild($doc->createElement('publish_date', 'Noodle'));
            $item->appendChild($doc->createElement('last_update', 'Noodle'));
            $item->appendChild($doc->createElement('detail', 'Noodle'));

            $items->appendChild($item);
            
           // $multimedia = $items->appendChild($doc->createElement('multimedia'));
            // for multimedia
            //$multimedia = $doc->createElement('multimedia');
           
            
           //   $multimedia = $root->appendChild($doc->createElement('multimedia'));
            
           // $images = $multimedia->appendChild($doc->createElement('images'));

          //  $item = $doc->createElement('item');
           // $item->appendChild($doc->createElement('id', 'Noodle'));
            
            
            
           // $multimedia->appendChild($doc->createElement('id', 'Noodle'));
         //   $items->appendChild($multimedia);
            //$items->appendChild($item_short_title);


            $item = $doc->createElement('item');
            $item->appendChild($doc->createElement('name', 'Sausage'));
            $item->appendChild($doc->createElement('age', '3'));
            $items->appendChild($item);
            
         
        }
       // echo $doc->saveXML();
        $doc->save($file_path.'/result.xml') or die('XML Create Error');    
      
}



/**
 * Function to generate rss
 * @param array $data
 * @param array $syndication_node
 */

function itg_mobile_services_generate_rss($query) {
  
// The XML structure

        $data = '<?xml version="1.0"?><rss version="2.0" xmlns:atom="http://www.w3.org/2005/Atom">';
        $data .= '<channel>';
        $data .= '<title>India Today | KARNATAKA NEWS</title>';
        $data .= '<description>India Today</description>';
        $data .= '<link>http://indiatoday.intoday.in/</link>';
        $data .= '<lastBuildDate>Mon, 03 Feb 2014 12:38:02 IST</lastBuildDate>';
        $data .= '<generator>FeedCreator 1.7.2</generator>';
        $data .= '<image>';
        $data .= '<url>http://mobileservice.digitaltoday.in/content/img/rss/karnataka.jpg</url>';
        $data .= '<title>India Today | KARNATAKA NEWS</title>';			
        $data .= '<description>India Today</description>';
        $data .= '</image>';

       foreach ($query as $row) {
          $content_text = $row->content_text;
          $short_title = "Ramdev's business plan: Make Nestle's bird, Colgate's gate disappear";

          $file_path = drupal_realpath('public://');
          $file_path = '/var/www/html/itgcms/sites/default/files/mobile_xml';
          $data .= '<item>';
          $data .= '<title>Karnataka team gets Rs 1 crore</title>';
          $data .= '<link>http://indiatoday.intoday.in/</link>';
          $data .= "<description>".$content_text."</description>";
          $data .= '<image></image>';
          $data .= '<image></image>';
          $data .= '</item>';
        }  
      $data .= '</channel>';
      $data .= '</rss>';
      //$doc->save($file_path.'/result_rss.xml') or die('XML Create Error');   
       // header('Content-Type: application/xml');
      echo $data;
       watchdog('mobile_rss', 'RSS created');
      drupal_set_message('rss file has been created.', 'status');   
  
}

/**
 * Function to generate rss
 * @param array $data
 * @param array $syndication_node
 */

function itg_mobile_services_generate_simple_text($query) {
  
// The XML structure

        $data .= '<channel>';
        $data .= '<title>India Today | KARNATAKA NEWS</title>';
        $data .= '<description>India Today</description>';
        $data .= '<link>http://indiatoday.intoday.in/</link>';
        $data .= '<lastBuildDate>Mon, 03 Feb 2014 12:38:02 IST</lastBuildDate>';
        $data .= '<generator>FeedCreator 1.7.2</generator>';
        $data .= '<image>';
        $data .= '<url>http://mobileservice.digitaltoday.in/content/img/rss/karnataka.jpg</url>';
        $data .= '<title>India Today | KARNATAKA NEWS</title>';			
        $data .= '<description>India Today</description>';
        $data .= '</image>';

       foreach ($query as $row) {
          $content_text = $row->content_text;
          $short_title = "Ramdev's business plan: Make Nestle's bird, Colgate's gate disappear";

          $file_path = drupal_realpath('public://');
          $file_path = '/var/www/html/itgcms/sites/default/files/mobile_xml';
          $data .= '<item>';
          $data .= '<title>Karnataka team gets Rs 1 crore</title>';
          $data .= '<link>http://indiatoday.intoday.in/</link>';
          $data .= "<description>".$content_text."</description>";
          $data .= '<image></image>';
          $data .= '<image></image>';
          $data .= '</item>';
        }  
      $data .= '</channel>';
      $data .= '</rss>';
      //$doc->save($file_path.'/result_rss.xml') or die('XML Create Error');   
       // header('Content-Type: application/xml');
      echo $data;
       watchdog('mobile_rss', 'RSS created');
      drupal_set_message('rss file has been created.', 'status');   
  
}