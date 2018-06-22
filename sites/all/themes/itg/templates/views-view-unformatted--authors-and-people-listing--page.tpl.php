
<style type="text/css">
.section-authors-list h1{display:none;}
.section-authors-list .author-listing{padding: 20px 0; border-bottom: 1px solid #ddd; overflow:hidden}
.section-authors-list .author-listing .pic{float:left; margin-right:22px;}
.section-authors-list .author-listing .detail{display:block}
.section-authors-list .author-listing .social-icon{}
.section-authors-list .author-listing .social-icon ul{list-style:none;}
.section-authors-list .author-listing .social-icon ul li{width:auto; display:inline; margin-right:10px;}
.section-authors-list .author-listing .social-icon ul li a{font-size:13px;}
.section-authors-list .item-list ul.pager{list-style:none; margin-top:20px;}
.section-authors-list .item-list ul.pager li{width:auto; display:inline; margin:10px 0 15px 0; border:1px solid #ccc; padding:0 8px;}
</style>


<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
global $base_url;
?>
<?php
foreach ($view->result as $id => $item): ?>
<div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
<div class="author-listing">
  <div class="pic">
   <?php if (empty($item->_field_data['nid']['entity']->field_story_extra_large_image['und'][0]['uri'])) { ?>
            <?php
              $img = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') . "' alt='' title=''/>";
              print l($img, 'node/' . $item->nid, array('html' => TRUE));

           }
           else {
            $image = theme('image_style',array(
                        'style_name' => 'widget_small',
                        'path' => $item->_field_data['nid']['entity']->field_story_extra_large_image['und'][0]['uri'],
                        'attributes' => array('class' => 'custom-inline', 'style' => 'border:1px solid #aaa;')
                      )
                    );
           print l($image, 'node/' . $item->nid, array('html' => TRUE));

          } ?>
  </div>
  <div class="detail">
       <div class="author-right" >
            <h3><?php print l($item->node_title , 'node/' . $item->nid) ?></h3>

            <p><?php print mb_strimwidth(html_entity_decode(strip_tags($item->field_body[0]['rendered']['#markup'])), 0, 245, "..");  ?></p>
          <div class="social-icon">
            <ul>
              <?php
              $fb_title = itg_common_only_text_string($item->node_title);
              $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
              $short_url = $actual_link;
              $share_desc = '';
              $src = '';

              ?>
              <li>
              <a class="user-activity def-cur-pointer" rel="<?php print $item->nid; ?>" data-tag="anchor-listing" data-activity="twitter_share" data-status="1" title="share on twitter" onclick="twitter_popup('<?php print urlencode($fb_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i><?php print t('Twitter'); ?></a>
            </li>
            <li>
              <a class="def-cur-pointer" title="share on facebook" onclick='fbpop("<?php print $actual_link; ?>", "<?php print urlencode($fb_title); ?>", "<?php print urlencode($share_desc); ?>", "<?php print $src; ?>")'><i class="fa fa-facebook"></i><?php print t('Facebook'); ?></a>
            </li>
          </ul>
        </div>

      </div>
  </div>
</div>
</div>
<?php endforeach; ?>
