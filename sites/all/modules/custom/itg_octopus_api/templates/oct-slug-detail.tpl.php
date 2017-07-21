<?php
global $base_url;
?>
<div class="slug-details">
  <ul class="slug-data">
    <li><strong>Video Title: </strong>  <span><?php print $result->story_title ?></span></li>
    <li><strong>Category: </strong>  <span><?php print $result->category ?></span></li>
    <li><strong>Video Created By: </strong> <span><?php print $result->story_created_by ?></span></li>
    <li><strong>Video Modified By: </strong> <span><?php print $result->story_modified_by ?></span></li>
    <li><strong>Video Description </strong> <span><?php print $result->text; ?></span></li>
    <li><strong>Created Date & Time</strong> <span> <?php print $result->story_created ?></span></li>
    <li><strong>Modified Date & Time</strong> <span><?php print $result->story_modified ?></span></li>
  </ul>

  <div class="slug-video">
    <video width="320" height="240" controls>
      <source src="http://125.19.34.234:7777/Proxy/Lowres/<?php print $result->clip_data[0]->clipobj_id; ?>.mp4" type="video/mp4">
      <source src="http://125.19.34.234:7777/Proxy/Lowres/<?php print $result->clip_data[0]->clipobj_id; ?>.ogg" type="video/ogg">
      Your browser does not support the video tag.
    </video>
  </div>

  <?php
  $get_video = 'block';
  $file_video = 'none';
  if (isset($result->dm_success) && !empty($result->dm_success)) {
    $get_video = 'none';
    $file_video = 'block';
  }
  ?>
  <div class="slug-link" style="display:<?php print $get_video; ?>" id="get-video-<?php print $result->id; ?>">
    <a href="javascript:void(0);" class="get-video btn-submit btn-small" attribute_id ="<?php print $result->id; ?>" data="<?php print $result->clip_data[0]->clipobj_id . '.mov'; ?>">Get Video</a>
  </div>

  <div class="slug-link" style="display:<?php print $file_video; ?>;" id="file-video-article-<?php print $result->id; ?>">
    <?php
    $url_file_video = $base_url . '/node/add/videogallery?element=vo&story_id=' . $result->storyid . '&destination=rundown/listing';
    ?>
    <a href="javascript:void(0);" class="file-video btn-submit btn-small" attribute_id ="<?php print $result->id; ?>" data="<?php print $result->clip_data[0]->clipobj_id . '.mov'; ?>">File Video Article</a>
  </div>
   <div style="display:none;" class="video-process-bar-<?php print $result->id; ?>">
  </div>

</div>