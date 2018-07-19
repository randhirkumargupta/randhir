
<style type="text/css">
.section-authors-list h1{display:none;}
.section-authors-list .author-listing{padding: 20px 0; border-bottom: 1px solid #ddd; overflow:hidden}
.section-authors-list .author-listing .pic{float:left; margin-right:22px;}
.section-authors-list .author-listing .detail{display:block}
.section-authors-list .author-listing .social-icon{}
.section-authors-list .author-listing .social-icon ul{list-style:none;}
.section-authors-list .author-listing .social-icon ul li{width:auto; display:inline; margin-right:10px;}
.section-authors-list .author-listing .social-icon ul li a{font-size:13px;}
.section-authors-list .item-list{display:block; text-align:center}
.section-authors-list .item-list ul.pager{list-style:none; margin-top:20px;}
.section-authors-list .item-list ul.pager li{width:auto; display:inline; margin:10px 0 15px 0; padding:0 3px;}
.section-authors-list .item-list ul.pager li a{display: inline-block;width: 25px;height: 25px;font-size: 1rem;text-align: center;line-height: 25px;}
.section-authors-list .item-list ul.pager li.pager-current{width:25px; height:25px; border-radius:50%;background:#337ab7; display:inline-block; font-size:1rem; line-height:25px; color:#fff;}
.section-authors-list .item-list ul.pager li a:hover{background:#337ab7; border-radius:50%; color:#fff;}
.section-authors-list .view-authors-and-people-listing input#edit-submit-authors-and-people-listing{border:0;background-color:#2c333c;padding:7px 10px;font-size:14px;color: #fff; margin-top:0}
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
              // print l($img, 'node/' . $item->nid, array('html' => TRUE));

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
                if (!empty($item->_field_data['nid']['entity']->field_story_expert_name['und'][0]['value'])) { ?>

                <li>
                  <a class="def-cur-pointer" href="<?php  print  $item->_field_data['nid']['entity']->field_story_expert_name['und'][0]['value'];?>" target="_blank"><i class="fa fa-facebook"></i></a></a>
                </li>
              <?php } ?>


               <?php
                if (!empty($item->_field_data['nid']['entity']->field_reporter_twitter_handle['und'][0]['value'])) { ?>

                <li>
                  <a class="def-cur-pointer" href="<?php  print 'https://twitter.com/'.ltrim($item->_field_data['nid']['entity']->field_reporter_twitter_handle['und'][0]['value'], '@'); ?>" target="_blank"><i class="fa fa-twitter"></i></a>
                </li>
              <?php } ?>
          </ul>
        </div>

      </div>
  </div>
</div>
</div>

<?php endforeach; ?>
