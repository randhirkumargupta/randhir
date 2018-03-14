<?php
global $base_url;
// configuration for social sharing
$photo_node = node_load(arg(1));

$comment_flag = FALSE;
if (!empty($photo_node->field_photogallery_configuration['und'])) {
  foreach ($photo_node->field_photogallery_configuration['und'] as $photo_config) {
    if ($photo_config['value'] == 'commentbox') {
      $comment_flag = TRUE;
    }
  }
}

$tid = $photo_node->field_primary_category[LANGUAGE_NONE][0]['value'];
$term = taxonomy_term_load($tid);
$primary_category_name = itg_common_custompath_insert_val($term->name);
$f_collection = entity_load('field_collection_item', array($photo_node->field_gallery_image[LANGUAGE_NONE][0]['value']));
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$short_url = $actual_link;
$share_title = addslashes($photo_node->title);
$share_desc = '';
$image = file_create_url($f_collection[$photo_node->field_gallery_image[LANGUAGE_NONE][0]['value']]->field_images[LANGUAGE_NONE][0]['uri']);
$uri = base64_encode($actual_link);
$argum = base64_encode(arg(1));
?>
<div class="row">
    <div class="col-md-12">
        <h1 class="photo-heading" title="<?php print strip_tags($rows[0]['title']); ?>"><?php print $rows[0]['title']; ?></h1>    <?php
        global $user;
        if (in_array('Social Media', $user->roles)) {
          ?>
          <a class="def-cur-pointer colorbox-load promote-btn" title="promote" href="<?php print $base_url; ?>/itg-social-media-promote/<?php echo $photo_node->nid; ?>?width=850&height=850&iframe=true&type=<?php print $video_node->type; ?>"><span>promote</span></a>   
        <?php } ?>
        <div class="social-icon desktop-hide">
            <ul>
                <li><a title="share on facebook" class="def-cur-pointer" onclick='fbpop("<?php print $actual_link; ?>", "<?php print $share_title; ?>", "<?php print $share_desc; ?>", "<?php print $image; ?>", "<?php print $base_url; ?>", "<?php print $photo_node->nid; ?>")'><i class="fa fa-facebook"></i></a></li>
                <li><a title="share on google+" class="user-activity def-cur-pointer" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="google_share" data-status="1" onclick='return googleplusbtn("<?php print $actual_link; ?>")'><i class="fa fa-google-plus"></i></a></li>
                <li><a title="share on twitter" class="user-activity def-cur-pointer" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="twitter_share" data-status="1" onclick='twitter_popup("<?php print urlencode($share_title); ?>", "<?php print urlencode($short_url); ?>")'><i class="fa fa-twitter"></i></a></li>
                <li><a href="mailto:?body=<?php print urlencode($actual_link); ?>" title="Email"><i class="fa fa-envelope"></i></a></li>
                <?php
                if (function_exists('global_comment_last_record')) {
                  $last_record = $global_comment_last_record;
                  $config_name = trim($last_record[0]->config_name);
                }
                // If comment box is checked then only comment icon will come otherwise it will not come.
                if ($comment_flag) {
                  if ($config_name == 'vukkul') {
                    ?>
                    <li><a onclick ="scrollToAnchor('vuukle-comments');" title="comment"><i class="fa fa-comment"></i></a></li>
                  <?php } if ($config_name == 'other') { ?> 
                    <li><a onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
                  <?php } ?>
                <?php } ?>

                <li class="show-embed-code-link">
                    <a class="embed-link" href="javascript:;" title="Embed"><i class="fa fa-link"></i></a>
                    <div class="show-embed-code-div">
                        <div class="copy-sample-code">
                            <textarea readonly><iframe src=<?php print $base_url . '/photo/' . $primary_category_name . '/embed/' . $argum; ?> allowfullscreen  width='648' height='550' frameborder='0' scrolling='no' /></textarea> 
                        </div>
                    </div>
                </li>
                <div class = "photo-refresh-top">
                <?php global $user; ?>
                <?php
                if ($user->uid > 0) {
                  if (function_exists(itg_get_front_activity_info)) {
                    $opt = itg_get_front_activity_info($photo_node->nid, $photo_node->type, $user->uid, 'read_later', $status = '');
                  }

                  if (empty($opt['status']) || $opt['status'] == 0) {
                    ?> 
                    <li class="later" title = "Saved"><a title = "Save" href="javascript:void(0)" class="user-activity" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i></a></li>
                    <?php
                  }
                  else {
                    ?>
                    <li title = "Saved"><a title = "Save" href="javascript:" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i></a></li>
                    <?php
                  }
                }
                else {
                  ?>
                  <li><a href="<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri; ?>" class="user-icon sso-click"><i class="fa fa-bookmark"></i> <span></span> </a></li>
                  <?php
                }
                ?>
                </div>  
                <!-- Comment by vishal <?php if ($user->uid > 0): ?>
                  <li><a class="def-cur-pointer photo-login-akamai" title="post content" href="javascript:"><i class="fa fa-share"></i></a></li>
                <?php else: ?>
                  <li class="replace-submit-story"><a class="def-cur-pointer colorbox-load" title="post content" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $photo_node->type; ?>"><i class="fa fa-share"></i></a></li>
                <?php endif; ?>
               <a title = "post content" class="def-cur-pointer colorbox-load akamai-submit-story-col hide" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=470&iframe=true&type=<?php print $photo_node->type; ?>"><i class="fa fa-share"></i></span></a>   -->
               <!--<li class="replace-submit-story"><a class="" title="post content" href="#"><i class="fa fa-share"></i></a></li>-->
            </ul>
        </div>
    </div>
    <div class="col-md-8">
        <ul class="slickslide">

            <?php foreach ($rows as $index => $row):
              ?>
              <li data-slide-number="<?php echo $index ?>">
                  <figure class="photo-landing-slider-pic" data-img-fid=" <?php print $row['item_id']; ?>">


                      <?php
                      if (!empty($row['field_images'])) {

                        print $row['field_images'];
                      }
                      else {
                        print '<img height="448" width="650" src="' . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image647x363.jpg').'" alt="" title="" />';
                      }
                      ?>                    
                  </figure>
              </li>
            <?php endforeach; ?>
        </ul>        
        <div class="photo-by-slider">
            <?php foreach ($rows as $index => $row): ?>              
              <?php if(!empty($row['field_credit'])) : ?>
                <p class="photo-by"><?php print t('PHOTO:'); ?> <?php print $row['field_credit']; ?></p>
              <?php endif; ?>
              <?php if (!empty($row['field_photo_byline'])) { ?>
                <p class="photo-by"><?php print t('PHOTO:'); ?> <?php print $row['field_photo_byline']; ?></p>
                <?php
              }
              elseif (!empty($row['field_photo_by'])) {
                ?>
                <p class="photo-by"><?php print t('PHOTO:'); ?> <?php print $row['field_photo_by']; ?></p>
              <?php } ?>
            <?php endforeach; ?>
        </div>
    </div>
    <div class="col-md-4">
        <div class="other-details-main">
            <ul class="counterslide">
                <?php $like_id = 1000; ?>
                <?php foreach ($rows as $index => $row): ?>
                  <li>
                      <div class="other-details">
                          <div class="counter">
                              <i class="fa fa-camera" aria-hidden="true"></i>
                              <?php print $row['counter']; ?>
                          </div>
                          <div class="caption">
                              <div class="mCustomScrollbar cap-text">
                                  <?php print html_entity_decode(strip_tags($row['field_image_caption'])); ?>
                              </div>

                              <div class="section-like-dislike">
                                  <!--<div id="btn-div">-->
                                  <div class="btn-div">
                                      <?php
                                      if (function_exists(itg_event_backend_highlights_like_dislike)) {
                                        //$val = $row['item_id'];
                                        $val = arg(1) . $like_id;
                                        $datatype = $photo_node->type;
                                        print itg_event_backend_highlights_like_dislike($val, $datatype, arg(1));
                                      }
                                      ?>
                                  </div>
                              </div>

                          </div>
                      </div>
                  </li>
                  <?php
                  $like_id++;
                endforeach;
                ?>
            </ul>

            <div class="social-icon mhide">
                <ul>
                    <li><a title="share on facebook" class="def-cur-pointer" onclick='fbpop("<?php print $actual_link; ?>", "<?php print $share_title; ?>", "<?php print $share_desc; ?>", "<?php print $image; ?>", "<?php print $base_url; ?>", "<?php print $photo_node->nid; ?>")'><i class="fa fa-facebook"></i></a></li>
                    <li><a title="share on google+" class="user-activity def-cur-pointer" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="google_share" data-status="1" onclick='return googleplusbtn("<?php print $actual_link; ?>")'><i class="fa fa-google-plus"></i></a></li>
                    <li><a title="share on twitter" class="user-activity def-cur-pointer" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="twitter_share" data-status="1" onclick='twitter_popup("<?php print urlencode($share_title); ?>", "<?php print urlencode($short_url); ?>")'><i class="fa fa-twitter"></i></a></li>
                    <li><a href="mailto:?body=<?php print urlencode($actual_link); ?>" title="Email"><i class="fa fa-envelope"></i></a></li>
                    <?php
                    if (function_exists(global_comment_last_record)) {
                      $last_record = global_comment_last_record();
                      $config_name = trim($last_record[0]->config_name);
                    }
                    // If comment box is checked then only comment icon will come otherwise it will not come.
                    if ($comment_flag) {
                      if ($config_name == 'vukkul') {
                        ?>
                        <li><a onclick ="scrollToAnchor('vuukle-comments');" title="comment"><i class="fa fa-comment"></i></a></li>
                      <?php } if ($config_name == 'other') { ?> 
                        <li><a onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
                      <?php } ?>
                    <?php } ?>
                    <li class="show-embed-code-link">
                        <a class="embed-link" href="javascript:;" title="Embed"><i class="fa fa-link"></i></a>
                        <div class="show-embed-code-div">
                            <div class="copy-sample-code">
                                <textarea readonly><iframe src="<?php print $base_url . '/photo/' . $primary_category_name . '/embed/' . $argum; ?>" allowfullscreen  width='648' height='550' frameborder='0' scrolling='no' /></textarea>
                            </div>
                        </div>
                    </li>
                    <!-- Comment by Vishal<?php if ($user->uid > 0): ?>
                      <li class="mhide"><a class="def-cur-pointer photo-login-akamai" title="post content" href="javascript:"><i class="fa fa-share"></i></a></li>
                    <?php else: ?>
                      <li class="mhide replace-submit-story"><a class="def-cur-pointer colorbox-load" title="post content" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $photo_node->type; ?>"><i class="fa fa-share"></i></a></li>
                    <?php endif; ?> -->
                    <!--<li class="mhide replace-submit-story"><a class="" title="post content" href="#"><i class="fa fa-share"></i></a></li>-->
                    <div class = "photo-refresh-bottom">
                    <?php global $user; ?>
                    <?php
                    if ($user->uid > 0) {
                      if (function_exists(itg_get_front_activity_info)) {
                        $opt = itg_get_front_activity_info($photo_node->nid, $photo_node->type, $user->uid, 'read_later', $status = '');
                      }
                      if (empty($opt['status']) || $opt['status'] == 0) {
                        ?> 
                        <li class="later" title = "Saved"><a title = "Save" href="javascript:void(0)" class="user-activity" data-rel="<?php print $photo_node->nid; ?>" data-tag="<?php print $photo_node->type; ?>" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i></a></li>
                        <?php
                      }
                      else {
                        ?>
                        <li title = "Saved"><a title = "Save" href="javascript:" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i></a></li>
                        <?php
                      }
                    }
                    else {
                      ?>
                      <li><a href="<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri; ?>" class="user-icon sso-click"><i class="fa fa-bookmark"></i> <span></span> </a></li>
                      <?php
                    }
                    ?>
                      </div>      
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

<?php
$initial_slide = 0;

if(isset($_GET['photo']) && $_GET['photo']) {
  $initial_slide = $_GET['photo']-1;
}
?>
<script>
  jQuery(document).ready(function (e) {
      jQuery('.slickslide').slick({
          slidesToShow: 1,
          slidesToScroll: 1,
          arrows: true,
          fade: false,
          asNavFor: '.slick-thumbs-slider, .counterslide, .photo-by-slider',
          // For active slide
          initialSlide: <?php echo $initial_slide; ?>,
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
          responsive: [{
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
          asNavFor: '.slick-thumbs-slider, .slickslide, .photo-by-slider',
          // For active slide
          initialSlide: <?php echo $initial_slide; ?>,
      });
      jQuery('.photo-by-slider').slick({
          slidesToShow: 1,
          slidesToScroll: 1,
          arrows: false,
          fade: true,
          asNavFor: '.slick-thumbs-slider, .slickslide, .counterslide',
          // For active slide
          initialSlide: <?php echo $initial_slide; ?>,
      });
// Photogallery slider javascript
      jQuery(document).ready(function () {
        var query_val = get_photo_url_query('photo' , window.location);
          if(query_val != null) {
              var real_node_url = "<?php echo $base_url."/".$photo_node->path['alias']; ?>";
              ChangeUrl("page", real_node_url +"/"+query_val);
          }
          jQuery(".slick-arrow , li.slick-slide").on("click", function () {
              var active_slide = jQuery(".slick-active").attr("data-slick-index");
                       var real_node_url = "<?php echo $base_url.'/'.$photo_node->path['alias']; ?>";
              if (active_slide > 0) {
                  ++active_slide;
                  //window.history.pushState(null, null, real_node_url + "/" + active_slide);
                  ChangeUrl("page", real_node_url +"/"+active_slide);
              } else {
                  // If frist slide then put pull without query string.
                  window.history.pushState(null, null, real_node_url);
              }
          });
      });
      
    function ChangeUrl(page, url) {
        if (typeof (history.pushState) != "undefined") {
            var obj = { Page: page, Url: url };
            history.pushState(obj, obj.Page, obj.Url);
        } else {
            alert("Browser does not support HTML5.");
        }
    }
    
    function get_photo_url_query(name, url) {
        if (!url) {
          url = window.location.href; 
        }
        name = name.replace(/[\[\]]/g, "\\$&");
        var regex = new RegExp("[?&]" + name + "(=([^&#]*)|&|#|$)"),
            results = regex.exec(url);
        if (!results) return null;
        if (!results[2]) return '';
        return decodeURIComponent(results[2].replace(/\+/g, " "));
    }
    
  });
  // Photogallery slider javascript
  // Handle Thumb for active set class
  jQuery(window).load(function () {
      var active_slide = jQuery(".slick-active").attr("data-slick-index");
      jQuery('.slick-thumbs li').removeClass('slick-current');
      jQuery('.slick-thumbs li').each(function (key, item) {
          if (key == active_slide) {
              jQuery(this).addClass("slick-current");
          }
      });
  });
</script>
