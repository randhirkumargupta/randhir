<?php
// configuration for sharing
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . '/funalytics';
$short_url = shorten_url($row->url, 'goo.gl');
?>
<span class="close-popup"><i class="fa fa-times" aria-hidden="true"></i></span>
        <div class="funalytics-slider-wrapper">
            <div class="funalytics-slider">
                <?php foreach ($rows as $index => $row): ?>
              <?php 
              $search_title = preg_replace("/'/", "\\'", $row['title']);
              $fb_share_title= htmlentities($search_title, ENT_QUOTES);
              $twitter_title = addslashes($row['title']);
              $share_desc = '';
              $changed = date("D j M Y", $row->node_changed);
              preg_match('/(src=["\'](.*?)["\'])/', $row['field_itg_funalytics_image'], $match);  //find src="X" or src='X'
              $split = preg_split('/["\']/', $match[0]); // split by quotes
              $src = $split[1]; // X between quotes
              ?>
                    <div>
                      <div class="title" title="<?php echo strip_tags($row['title']);?>"><?php print $row['title']; ?></div>
                      <div class="pic">
                        <?php print $row['field_itg_funalytics_image']; ?>
                        <div class="funalytics-socials">
                          <a class="download-nf" href="javascript:;" title=""></a>
                          <a class="google-play" href="javascript:;" title=""></a>
                          <a class="app-store" href="javascript:;" title=""></a>
                          <span class="funalytics-social-links">
                            <a class="fn-facebook facebook" title = "share on facebook " href="javascript:void(0)"  onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_share_title; ?>', '<?php print $share_desc; ?>', '<?php print $src; ?>')"></a>
                            <a class="fn-twitter twitter user-activity" title = "share on twitter" class="" rel="<?php print $row['nid']; ?>" data-tag="itg_funalytics" data-activity="twitter_share" data-status="1" href="javascript:void(0)" onclick="twitter_popup('<?php print urlencode($twitter_title); ?>', '<?php print urlencode($short_url); ?>')"></a>
                            <a title="share on google+" class="fn-gplus google user-activity" rel="<?php print $row['nid']; ?>" data-tag="itg_funalytics" data-activity="google_share" data-status="1" href="javascript:void(0)" onclick="return googleplusbtn('<?php print $actual_link; ?>')"></a>
                          </span>
                        </div>
                      </div>
                    </div>
                <?php endforeach; ?>
            </div>            
        </div> 