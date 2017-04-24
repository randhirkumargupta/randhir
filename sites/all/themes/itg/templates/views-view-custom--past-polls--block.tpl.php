<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row):
$fb_share_image = '';
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = shorten_url($actual_link, 'goo.gl');
$factoidsSocialShare_title = preg_replace("/'/", "\\'", $row['title']);
$fb_share_title = htmlentities($factoidsSocialShare_title, ENT_QUOTES);
preg_match('/(src=["\'](.*?)["\'])/', $row['field_poll_banner'], $match);  //find src="X" or src='X'
$split = preg_split('/["\']/', $match[0]); // split by quotes
$fb_share_image = $split[1]; // X between quotes
$fb_share_desc = '';
?>
        <div class="poll-banner test">
<div class="poll-list">
	<div class="pic"><?php echo $row['field_poll_banner'];?> </div>
	<div class="detail">
		<div class="detail-content">
			<h4><?php echo $row['title'];?></h4>
			<div class="vota-time mhide">
				<div class="vota"><?php echo $row['php_1'];?></div>
				<div class="time">Updated: <?php echo $row['changed'];?> <div class="social-share"><ul><li><span class="share"><i class="fa fa-share-alt"></i></span></li><li><a href="javascript:;" onclick="<?php echo 'fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $fb_share_title . "'" . ', ' . "'" . $fb_share_desc . "'" . ', ' . "'" . $fb_share_image . "'" . ')';?>" class="facebook"><i class="fa fa-facebook"></i></a></li><li><a title = "share on twitter"  <?php echo ' onclick="twitter_popup(\'' . urlencode($row['title']) . ',' . urlencode($short_url) . '\')" href="javascript:;"';?> class="twitter"><i class="fa fa-twitter"></i></a></li><li><a title="share on google+" <?php echo 'onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')"';?> href="javascript:;"  class="google"></a></li></ul></div>			</div>								
			</div>
			
			
		</div>		
	</div>
	<div class="vota-time desktop-hide">
				<div class="vota"><?php echo $row['php_1'];?> | </div>
				<div class="time">Updated: <?php echo $row['changed'];?></div>
				
				<div class="social-share"><ul><li><span class="share"><i class="fa fa-share-alt"></i></span></li><li><a href="javascript:;" onclick="<?php echo 'fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $fb_share_title . "'" . ', ' . "'" . $fb_share_desc . "'" . ', ' . "'" . $fb_share_image . "'" . ')';?>" class="facebook"><i class="fa fa-facebook"></i></a></li><li><a title = "share on twitter"  <?php echo ' onclick="twitter_popup(\'' . urlencode($row['title']) . ',' . urlencode($short_url) . '\')" href="javascript:;"';?> class="twitter"><i class="fa fa-twitter"></i></a></li><li><a title="share on google+" <?php echo 'onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')"';?> href="javascript:;"  class="google"></a></li></ul></div>			
				
			</div>
	<div class="voting-data">
		<?php echo $row['php'];?>
		</div>
</div>
</div>
        <?php endforeach; ?>