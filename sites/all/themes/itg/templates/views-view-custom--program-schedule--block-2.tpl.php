<?php
  global $base_url;
  $arg = arg();
  if($arg[0] == 'event') {
    $baseurl = $base_url.'/'.$arg[0].'/'.$arg[1];
  } elseif(!empty($arg[1]) && is_numeric($arg[1])) {//shravan
    $baseurl = $base_url.'/'.drupal_get_path_alias('node/'.  $arg[1]);
  }
?>
    <?php foreach ($rows as $index => $row): ?>
<ul class="profile-detail">
    <li>Speaker: </li>
    <li class="image"><?php
    if(!empty($row['field_story_extra_large_image'])){
      print l($row['field_story_extra_large_image'], $baseurl.'/speaker-details?speaker='.$row['nid'], array('attributes' => array('target'=>'_blank'), 'html' => TRUE)); 
    }else{
      $img = "<img width='72' height='72'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image72x72.jpg' alt='' />";
      print l($img, $baseurl.'/speaker-details', array('attributes' => array('target'=>'_blank'), 'query' => array('speaker' => $row['nid']), 'html' => TRUE));
    }
    ?></li>
        <li>
            <span class="title"  title="<?php print strip_tags($row['title']) ; ?>"><?php print l(strip_tags($row['title']), $baseurl.'/speaker-details?speaker='.$row['nid'], array('attributes' => array('target'=>'_blank'))); ?></span>
            <span class="designation"><?php print $row['field_story_new_title']; ?></span>
        </li>
        </ul>
    <?php endforeach; ?>
