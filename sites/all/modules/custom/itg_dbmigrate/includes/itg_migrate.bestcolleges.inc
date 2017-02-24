<?php

/**
 * ItgBestcollegeMigration extends Migration
 */
class ItgBestcollegeMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);  

    //The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns = array(
      1 => array('collegeid', 'College Id'),
      2 => array('collegename', 'College Name'),
      3 => array('city', 'City'),
      4 => array('description', 'Description'),
      5 => array('image', 'Image'),
      6 => array('websiteurl', 'Website Url'),
      7 => array('storyids', 'Story Ids'),
      8 => array('photoids', 'Photo Ids'),
      9 => array('videoids', 'Video Ids'),
      10 => array('created_date', 'Created Date'),
      12 => array('year', 'Year'),
      13 => array('rank', 'Rank'),
      14 => array('stream', 'Stream'),
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import of Best College content.');
    
    // This can also be an URL instead of a local file path.
    $file_path = DRUPAL_ROOT . '/sites/default/files';
    
    $xml_folder = $file_path . '/' . 'migrate/bestcollege/';
    
    $item_xpath = $xml_folder . 'bestcolleges.csv';

    //The Source of the import
    //$this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/../data/page.csv', $fields, array('delimiter' => ',', 'header_rows' => 1));
    
    $this->source = new MigrateSourceCSV($item_xpath, $columns, array('delimiter' => ',', 'header_rows' => 1));

    //The destination CCK (boundle)
    $this->destination = new MigrateDestinationNode('bestcolleges');

    //Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'import'
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    
    $this->addFieldMapping('language')->defaultValue('en');  
    //Field ampping
    $this->addFieldMapping('field_story_category', 'field_story_category');
    $this->addFieldMapping('title', 'collegename');
    $this->addFieldMapping('field_bestcollege_city', 'city');
    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('body:format', 'format')->defaultValue('full_html');
    $this->addFieldMapping('field_story_extra_large_image', 'image');
    $this->addFieldMapping('field_bestcollege_website_url', 'websiteurl');
    $this->addFieldMapping('field_bestcollege_related_story', 'storyids');
    $this->addFieldMapping('field_bestcollege_related_photo', 'photoids');
    $this->addFieldMapping('field_bestcollege_related_video', 'videoids');
    
    $this->addFieldMapping('field_bestcollege_rank', 'rank');
    $this->addFieldMapping('field_college_id', 'collegeid');
   
  }
  
  public function prepareRow($row) {
    $data_category = '';
    if(isset($row->year) && !empty($row->year)) {
      switch ($row->year) {
        case '2016':
          $tid = '787';
          $final_tid = $this->itg_bestcollege_get_tid($tid, $row->stream);
          $data_category[1]['tid'] = $final_tid;

          break;

        default:
          break;
      }
    }
    $row->category_new = $data_category;    
    return TRUE;
  }
  
  public function prepare($node, stdClass $row) {
    if (!empty($row->category_new)) {
      $node->field_story_category[LANGUAGE_NONE] = $row->category_new;
    }
    $node->uid = 3;  
  }
  
  public function itg_bestcollege_get_tid($tid, $stream) {
    if(isset($tid) && !empty($tid) && !empty($stream)) {
        $children = taxonomy_get_children($tid);
        foreach($children as $term) {
          $category[strtolower($term->name)] = $term->tid;
        }
      return $category[strtolower($stream)];
    }
  }      

}

