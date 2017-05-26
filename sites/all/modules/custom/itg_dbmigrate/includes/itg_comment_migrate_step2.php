<?php

$args = drush_get_arguments(); // Get the arguments.

itg_comments_migrate_step2();

/**
 * shift marking for photo
 */
function itg_comments_migrate_step2() {

  echo "Start migrating comments(Step2)...\n";

  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->itgcms_comment;
    $cond = array('migrated_data' => 1);
    $cursor = $people->find($cond);
    $count = 0;
    foreach ($cursor as $document) {
      if (isset($document['parent_id']) && !empty($document['parent_id'])) {
        $parent_id = itg_comments_migrate_step2_get_mapping($document['parent_id']);
        if (isset($parent_id) && !empty($parent_id)) {
          $parent_id = itg_comments_migrate_step2_update_parent($document['id'], $parent_id);
        }
      }
      $count++;
      echo (string) $document['id'] . ' ';
    }
    echo "\n Total Processed:".$count;
  }



  echo "\nMigration step2 finished...\n";
}

function itg_comments_migrate_step2_get_mapping($parent_id) {
  $id = '';
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->itgcms_comment;
    $cond = array('id' => (string) $parent_id);
    $cursor = $people->find($cond);
    foreach ($cursor as $document) {
      $id = $document['_id']->{'$id'};
      if (isset($id) && !empty($id)) {
        return $id;
      }
    }
  }
}

function itg_comments_migrate_step2_update_parent($id, $parent_id) {
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->itgcms_comment;
    if ($con) {
      $newdata = array('$set' => array('parent_comment_id' => $parent_id));
      $people->update(array("id" => $id), $newdata);
    }
  }
}
