<div class="slug-details">
  <ul class="slug-data">
    <li><strong>Video Title: </strong>  <span><?php print $result->story_title ?></span></li>
    <li><strong>Video Duration: </strong> <span><?php print $result->story_duration ?></span></li>
    <li><strong>Video Created By: </strong> <span><?php print $result->story_created_by ?></span></li>
    <li><strong>Video Modified By: </strong> <span><?php print $result->story_modified_by ?></span></li>
  </ul>
  <div class="slug-video">
<video width="320" height="240" controls>
  <source src="http://125.19.34.234:7777/Proxy/Lowres/<?php print $result->clip_data[0]->clipobj_id;?>.mp4" type="video/mp4">
  <source src="http://125.19.34.234:7777/Proxy/Lowres/<?php print $result->clip_data[0]->clipobj_id;?>.ogg" type="video/ogg">
  Your browser does not support the video tag.
</video>
  </div>
  
  <div class="slug-link">
    <?php
    print l('Get Video', 'itg-octopus-get-high-reso-video', array('attributes' => array('class' => 'submit')));
    ?>
  </div>
</div>

<style>
  .slug-details{
    display: inline-block;
    vertical-align: top;
    width: 800px;
    background: #fff;
  }
  .slug-video{
    overflow: hidden;
    padding: 20px;
  }
  .slug-data{
    float: left;
    list-style: none;
    width: 438px;
    padding: 20px;
    text-align: left;
  }
  .slug-data li{display: inline-block; vertical-align: top; width: 100%;}
  .slug-data li strong{float: left; width: 140px;}
  .slug-data li span{display: block; overflow: hidden;}
</style>