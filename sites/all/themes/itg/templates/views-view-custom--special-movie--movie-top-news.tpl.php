<div class="special-top-news">
    <ul class="itg-listing">
<?php foreach($rows as $index => $row){?>
  <?php  $desc=$row['title'];
    if($row['field_story_kicker_text']!="")
    {
        $desc = $row['field_story_kicker_text'];
    }else if($row['field_story_kicker_text']=="" && $row['body']!=""){
         $desc = $row['body'];
    }
  
   
    ?>
<li  title="<?php print $row['title'] ; ?>">
  <?php //echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?>
<?php
  if (function_exists('itg_common_get_smiley_title')) {
    echo l(itg_common_get_smiley_title($row['nid'], 0, 140), "node/" . $row['nid'], array("html" => TRUE));
  }
  else {
    echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), "node/" . $row['nid']);
  }
  ?>
</li>
  
<?php }; ?>
    </ul>
</div>
