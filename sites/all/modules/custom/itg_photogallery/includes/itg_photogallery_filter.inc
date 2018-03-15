<?php

/**
 * callback for all the workbench photogallery of title
 * @param $title
 */
function itg_photogallery_get_workbench_title($title) {
  global $user;
    if (strlen(trim($title)) > 0) {
        $current_time = date("Y-m-d H:i:s");
        $content_type = arg(1);
        $state = trim(arg(2));
        
        $state_array = array('mydraft-photogallery' => 'draft', 'in-queue-photogallery' => 'needs_review', 'my-queue-photogallery' => 'needs_review', 'my-rejected-photogallery' => 'rejected', 'my-unpublished-photogallery' => 'draft', 'unpublished-photogallery' => 'draft', 'archive-photogallery' => 'published');
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('node', 'n');
        $query->Join('field_data_field_story_source_type', 'sourcetype', 'sourcetype.entity_id = n.nid');
        if ($state =='my-published-photogallery' || $state =='published-photogallery') {
          $query->condition('n.status', 1, '=');
        } else if ($state !='expired-photogallery' && $state !='my-expired-photogallery') {
            $query->Join('workbench_moderation_node_history', 'wm', 'n.nid = wm.nid');
            $or = db_or();
            $or->condition('wm.state', $state_array[$state]);
            $or->condition('sourcetype.field_story_source_type_value', 'migrated');
            $query->condition($or);
           if ($state =='my-unpublished-photogallery' || $state == 'published-photogallery') {
            $un_or = db_or();
            $un_or->condition('wm.from_state', 'published');
            $un_or->condition('sourcetype.field_story_source_type_value', 'migrated');
            $query->condition($un_or);
           }
           $query->condition('wm.is_current', 1); 
           $query->condition('n.status', 0);
        }
        $query->leftJoin('field_data_field_story_expiry_date', 'expiry', 'n.nid = expiry.entity_id');
        $query->leftJoin('field_data_field_story_archive', 'archive', 'n.nid = archive.entity_id');
        $query->fields('n', array('title'));
        $query->condition('n.title', '%' . $title . '%', 'LIKE');
        $query->condition('n.type', $content_type, '=');        
        
        if ($state == 'mydraft-photogallery' || $state == 'my-queue-photogallery' || $state =='my-expired-photogallery' || $state == 'my-unpublished-photogallery' || $state == 'my-rejected-photogallery') {
          $query->condition('n.uid', $user->uid);
        }
        
        if ($state =='expired-photogallery' || $state =='my-expired-photogallery' || $state =='expired-video') {
          $query->condition('expiry.field_story_expiry_date_value', $current_time, '<');        
        } else {
          $query->condition(db_or()->isNull('expiry.field_story_expiry_date_value')->condition('expiry.field_story_expiry_date_value', $current_time, '>='));
        }
        
        
        if ($state == 'archive-photogallery') {
         $query->condition('archive.field_story_archive_value', 'Yes'); 
        } else {
         $query->isNull('archive.field_story_archive_value');
        }
        
        $query->range(0, 20);

        $result = $query->execute();

        while ($record = $result->fetchAssoc()) {
            $options[$record['title']] = $record['title'];
        }

        drupal_json_output($options);
    }
}
