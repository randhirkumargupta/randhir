<?php

foreach($rows as $row) {
  
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$search_title = preg_replace("/'/", "\\'", $row['title']);
$fb_share_title= htmlentities($search_title, ENT_QUOTES);    
$short_url = shorten_url($row->url, 'goo.gl');
$twitter_title = addslashes($row['title']);
$share_desc = '';

$file = file_load($row['fid']);
$print_image = $file->uri;
$image = file_create_url($file->uri);
$changed = $row['changed'];
?>


<div class="col-md-4 col-sm-6 col-xs-1">
<div class="funalytics-tile">
  <div class="pic"><a class="funalytic-popup" data-nid="<?php echo $row['counter']?>" href="javascript:;"><?php print theme('image_style', array('style_name' => 'anchors_landing', 'path' => $file->uri)); ?></a></a></div>
  <div class="funalytics-text">
      <div class="updated-date"><?php print $changed; ?></div>
      <div class="title"><?php print $row['title']; ?></div>
      <div class="social-share">
              <ul>
                  <li><a href="javascript:;" class="share"><i class="fa fa-share-alt"></i></a></li>
                  <li><a class="def-cur-pointer facebook" title = "share on facebook " href="javascript:void(0)"  onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a></li>
                  <li><a class="def-cur-pointer twitter user-activity" title = "share on twitter" class="" rel="<?php print $row->nid; ?>" data-tag="itg_funalytics" data-activity="twitter_share" data-status="1" href="javascript:void(0)" onclick="twitter_popup('<?php print urlencode($twitter_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                  <li><a title="share on google+" class="def-cur-pointer google user-activity" rel="<?php print $row->nid; ?>" data-tag="itg_funalytics" data-activity="google_share" data-status="1" href="javascript:void(0)" onclick="return googleplusbtn('<?php print $actual_link; ?>')"></a></li>                  
              </ul>
          </div>
  </div>
</div>
</div>
<?php 
} 