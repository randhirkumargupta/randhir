<?php
global $base_url;
// configuration for social sharing
$photo_node = node_load(arg(1));
$f_collection = entity_load('field_collection_item', array($photo_node->field_gallery_image[LANGUAGE_NONE][0]['value']));
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = shorten_url($actual_link, 'goo.gl');
$share_title = addslashes($photo_node->title);
$share_desc = '';
$image = file_create_url($f_collection[$photo_node->field_gallery_image[LANGUAGE_NONE][0]['value']]->field_images[LANGUAGE_NONE][0]['uri']);
?>
<div class="row">
  <div class="col-md-12">
    <h1 class="photo-heading" title="<?php print $rows[0]['title']; ?>"><?php print $rows[0]['title']; ?></h1>    <?php global $user;
if (in_array('Social Media', $user->roles)) {
  ?>
      <a class="def-cur-pointer colorbox-load promote-btn" title="promote" href="<?php print $base_url; ?>/itg-social-media-promote/<?php echo $photo_node->nid; ?>?width=850&height=850&iframe=true&type=<?php print $video_node->type; ?>"><span>promote</span></a>   
<?php } ?>
    <div class="social-icon desktop-hide">
      <ul>
        <li><a title="share on facebook" class="def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a></li>
        <li><a title="share on google+" class="user-activity def-cur-pointer" rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="google_share" data-status="1" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>
        <li><a title="share on twitter" class="user-activity def-cur-pointer" rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="twitter_share" data-status="1" onclick="twitter_popup('<?php print urlencode($share_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
        <li><a href="mailto:?body=<?php print urlencode($actual_link); ?>" title="Email"><i class="fa fa-envelope"></i></a></li>
        <?php
        if (function_exists(global_comment_last_record)) {
          $last_record = $global_comment_last_record;
          $config_name = trim($last_record[0]->config_name);
        }
        if ($config_name == 'vukkul') {
          ?>
          <li><a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
        <?php } if ($config_name == 'other') { ?> 
          <li><a onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
<?php } ?>
        <li class="show-embed-code-link">
          <a class="embed-link" href="javascript:;" title="Embed"><i class="fa fa-link"></i></a>
          <div class="show-embed-code-div">
            <div class="copy-sample-code">
              <textarea readonly><div id='IndiaToday_gallery' data-type='UAT'></div><script src='<?php print $base_url; ?>/sites/all/themes/itg/js/photo_iframeResizer.js'></script><script><?php echo "iFrameResize({galleryid: $photo_node->nid})"; ?></script></textarea> 
                    </div>
                  </div>
                </li>
        <?php global $user; ?>
        <?php
        if ($user->uid > 0) {
          if (function_exists(itg_get_front_activity_info)) {
            $opt = itg_get_front_activity_info($photo_node->nid, $photo_node->type, $user->uid, 'read_later', $status = '');
          }

          if (empty($opt['status']) || $opt['status'] == 0) {
            ?> 
                                              <li class="later" title = "Saved"><a title = "Save" href="javascript:void(0)" class="user-activity" rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i></a></li>
          <?php
          } else {
            ?>
                                              <li title = "Saved"><a title = "Save" href="javascript:" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i></a></li>
            <?php
          }
        } else {
          if (function_exists(itg_sso_url)) {
            print '<li>' . itg_sso_url('<i class="fa fa-bookmark"></i> <span>' . t('') . '</span>', t('Save')) . '</li>';
          }
        }
        ?>
        <?php if ($user->uid > 0): ?>
                    <li><a class="def-cur-pointer colorbox-load" title="post content" href="<?php print $base_url; ?>/personalization/my-content/"><i class="fa fa-share"></i></a></li>
        <?php else: ?>
                    <li><a class="def-cur-pointer colorbox-load" title="post content" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $photo_node->type; ?>"><i class="fa fa-share"></i></a></li>
        <?php endif; ?>
            </ul>
        </div>
    </div>
    
    <div class="col-md-8">
        <ul class="slickslide">
  <?php foreach ($rows as $index => $row):
    ?>
                  <li >
                      <figure class="photo-landing-slider-pic" data-img-fid=" <?php print $row['fid']; ?>">

        <?php print $row['field_images']; ?>                    
                      </figure>
                  </li>
        <?php endforeach; ?>
        </ul>
        <div class="slick-thumbs">
            <ul class="slick-thumbs-slider">
      <?php foreach ($rows as $index => $row): ?>
                      <li >
      <?php
      if (!empty($row['field_photo_small_image'])) {
        print $row['field_photo_small_image'];
      } else {
        print '<img  height="66" width="88" src="' . $base_url . "/" . drupal_get_path('theme', 'itg') . '/images/itg_image88x66.jpg" alt="" />';
      }
      ?>
                      </li>
          <?php endforeach; ?>
            </ul>
        </div>
        <div class="photo-by-slider">
          <?php foreach ($rows as $index => $row): ?>
          <?php if (!empty($row['field_photo_byline'])) { ?>
                <p class="photo-by">PHOTO: <?php print $row['field_photo_byline']; ?></p>
        <?php } elseif (!empty($row['field_photo_by'])) { ?>
                <p class="photo-by">PHOTO: <?php print $row['field_photo_by']; ?></p>
      <?php } ?>
      <?php endforeach; ?>
        </div>
    </div>
    <div class="col-md-4">
        <div class="other-details-main">
        <ul class="counterslide">
          <?php foreach ($rows as $index => $row): ?>
                  <li>
                      <div class="other-details">
                        <div class="counter">
                          <i class="fa fa-camera" aria-hidden="true"></i>
                          <?php print $row['counter']; ?>
                        </div>
                        <div class="caption"><?php print $row['field_image_caption']; ?>
                          <div class="section-like-dislike">
                            <!--<div id="btn-div">-->
                            <div class="btn-div">
                              <?php
                              if (function_exists(itg_event_backend_highlights_like_dislike)) {
                                $val = $row['item_id'];
                                print itg_event_backend_highlights_like_dislike($val);
                              }
                              ?>
                            </div>
                          </div>
                        </div>
                      </div>
                  </li>
                  <?php endforeach; ?>
        </ul>
        
        <div class="social-icon mhide">
            <ul>
                <li><a title="share on facebook" class="def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a></li>
                <li><a title="share on google+" class="user-activity def-cur-pointer" rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="google_share" data-status="1" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>
                <li><a title="share on twitter" class="user-activity def-cur-pointer" rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="twitter_share" data-status="1" onclick="twitter_popup('<?php print urlencode($share_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                <li><a href="mailto:?body=<?php print urlencode($actual_link); ?>" title="Email"><i class="fa fa-envelope"></i></a></li>
      <?php
        if (function_exists(global_comment_last_record)) {
          $last_record = global_comment_last_record();
          $config_name = trim($last_record[0]->config_name);
        }
        if ($config_name == 'vukkul') {
          ?>
                  <li><a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
          <?php } if ($config_name == 'other') { ?> 
                  <li><a onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
          <?php } ?>
                <li class="show-embed-code-link">
                  <a class="embed-link" href="javascript:;" title="Embed"><i class="fa fa-link"></i></a>
                  <div class="show-embed-code-div">
                    <div class="copy-sample-code">
                    <textarea readonly><div id='IndiaToday_gallery' data-type='UAT'></div><script src='<?php print $base_url; ?>/sites/all/themes/itg/js/photo_iframeResizer.js'></script><script><?php echo "iFrameResize({galleryid: $photo_node->nid})"; ?></script></textarea>
                    </div>
                  </div>
                </li>
            <?php if ($user->uid > 0): ?>
                    <li class="mhide"><a class="def-cur-pointer colorbox-load" title="post content" href="<?php print $base_url; ?>/personalization/my-content/<?php print $photo_node->type; ?>"><i class="fa fa-share"></i></a></li>
                <?php else: ?>
                    <li class="mhide"><a class="def-cur-pointer colorbox-load" title="post content" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $photo_node->type; ?>"><i class="fa fa-share"></i></a></li>
            <?php endif; ?>
          <?php global $user; ?>
          <?php
          if ($user->uid > 0) {
            if (function_exists(itg_get_front_activity_info)) {
              $opt = itg_get_front_activity_info($photo_node->nid, $photo_node->type, $user->uid, 'read_later', $status = '');
            }

            if (empty($opt['status']) || $opt['status'] == 0) {
              ?> 
                                              <li class="later" title = "Saved"><a title = "Save" href="javascript:void(0)" class="user-activity" rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i></a></li>
            <?php
            } else {
              ?>
                                              <li title = "Saved"><a title = "Save" href="javascript:" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i></a></li>
              <?php
            }
          } else {
            if (function_exists(itg_sso_url)) {
              print '<li>' . itg_sso_url('<i class="fa fa-bookmark"></i> <span>' . t('') . '</span>', t('Save')) . '</li>';
            }
          }
          ?>
            </ul>
        </div>
        
        
        <div class="photo-ad">
          <?php
          $block = block_load('itg_ads', ADS_RHS1);
          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
          print render($render_array);
          ?>
        </div>
        
    </div>
    </div>
</div>


<script>
                  jQuery(document).ready(function (e) {
                    jQuery('.slickslide').slick({
                      slidesToShow: 1,
                      slidesToScroll: 1,
                      arrows: true,
                      fade: false,
                      asNavFor: '.slick-thumbs-slider, .counterslide, .photo-by-slider'
                    });
                    jQuery('.slick-thumbs-slider').slick({
                      slidesToShow: 7,
                      slidesToScroll: 1,
                      asNavFor: '.slickslide, .counterslide, .photo-by-slider',
                      dots: false,
                      centerMode: false,
                      arrows: true,
                      variableWidth: true,
                      focusOnSelect: true,
                      responsive: [
                        {
                          breakpoint: 1024,
                          settings: {
                            slidesToShow: 7,
                            slidesToScroll: 1,
                            arrows: false
                          }
                        },
                        {
                          breakpoint: 600,
                          settings: {
                            slidesToShow: 4,
                            arrows: false,
                            slidesToScroll: 1
                          }
                        },
                        {
                          breakpoint: 480,
                          settings: {
                            slidesToShow: 3,
                            arrows: false,
                            slidesToScroll: 1
                          }
                        }
                      ]
                    });

                    jQuery('.counterslide').slick({
                      slidesToShow: 1,
                      slidesToScroll: 1,
                      arrows: true,
                      fade: true,
                      asNavFor: '.slick-thumbs-slider, .slickslide, .photo-by-slider'
                    });
                    jQuery('.photo-by-slider').slick({
                      slidesToShow: 1,
                      slidesToScroll: 1,
                      arrows: false,
                      fade: true,
                      asNavFor: '.slick-thumbs-slider, .slickslide, .counterslide'
                    });
                  });

</script>








    
  



