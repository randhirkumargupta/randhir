<?php

/**
* callback for the reported to username
*  
*/

function itg_task_allocation_autocomplete($title) {

    if (strlen(trim($title)) > 0) {
        $content_type = arg(1);
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('users', 'u');
        $query->fields('u', array('mail', 'created'));
        $query->condition('mail', '%' . $title . '%', 'LIKE');
        $query->condition('u.status', '1', '=');
        $query->range(0, 20);

        $result = $query->execute();
        while ($record = $result->fetchAssoc()) {
            $options[$record['mail']] = $record['mail'];
        }
        drupal_json_output($options);
    }
}
