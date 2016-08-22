<ul class="photo-list">
<?php foreach($rows as $index => $row): ?>
<?php $img = $row['field_story_extra_large_image']; 
  $section_cat_id = $row['field_story_category']; 
?>
    <li class="col-md-3">
 <figure>
 <?php print l($img, 'node/'.$row['nid'], array('query' => array('category' => $section_cat_id, 'sid' => $_GET['sid']), 'html' => TRUE)); ?>
<figcaption><i class="fa fa-camera" ></i><?php print $row['field_video_duration']; ?></figcaption>

      </figure>

      <span class="posted-on"><?php print $row['created']; ?></span>
<?php // print $row['field_story_expert_name'];?>
      </li>
<?php endforeach; ?>
      </ul>
<?php

$term = end($row->_field_data['nid']['entity']->field_story_category[LANGUAGE_NONE]);
$tid = $term['tid'];
$img = $field->original_value;
$output = l($img, 'node/'.$row->nid, array('query' => array('category' => $tid), 'html' => TRUE));
?>

