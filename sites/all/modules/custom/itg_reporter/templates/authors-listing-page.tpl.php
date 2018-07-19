<?php

print views_embed_view('authors_and_people_listing', 'block_1');

  $content_type = 'reporter';
  $query = db_select('node', 'n');
  $query->Join('field_data_field_celebrity_pro_occupation', 'fo', 'fo.entity_id = n.nid');
  $query->Join('field_data_field_reporter_profile_type', 'pro', 'pro.entity_id = n.nid');
  $query->Join('itg_multi_byline_info', 'bi', 'bi.byline_id = n.nid');
  $query->leftJoin('field_data_body', 'bv', 'bv.entity_id = n.nid');
  $query->leftJoin('field_data_field_inactive_profile', 'ip', 'ip.entity_id = n.nid');
  $query->leftJoin('field_data_field_story_expert_name', 'fb', 'fb.entity_id = n.nid');
  $query->leftJoin('field_data_field_reporter_twitter_handle', 'tw', 'tw.entity_id = n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'img', 'img.entity_id = n.nid');
  $query->condition('bi.publish_status', 1, '=');
  $query->condition('n.status', 1, '=');
  $query->fields('n', array('title', 'nid'));
  $query->fields('bv', array('body_value'));
  $query->fields('fb', array('field_story_expert_name_value'));
  $query->fields('tw', array('field_reporter_twitter_handle_value'));
  $query->fields('img', array('field_story_extra_large_image_fid'));
  $query->condition('n.type', $content_type, '=');
  $query->condition('fo.field_celebrity_pro_occupation_tid', '285750', '=');
  $query->condition('fo.bundle', 'reporter', '=');
  $query->condition('pro.bundle', 'reporter', '=');
  $query->condition('pro.field_reporter_profile_type_value', 'internal', '=');
  $or = db_or();
  $or->condition('ip.field_inactive_profile_value', '0', '=');
  $or->condition('ip.field_inactive_profile_value', NULL);
  $query->condition($or);
  $query->orderBy('bi.nid', 'DESC');
  $query->groupBy('bi.byline_id');
  $query->range(0, 20);
  $result = $query->execute()->fetchAll();
  if(!empty($result)){ ?>
<div class="custom-author-listing-wrapper">
  <?php foreach ($result as $key => $value){?>
  <div class="author-listing">
    <div class="pic">
      <?php if(!empty($value->field_story_extra_large_image_fid)) {
                $file = file_load($value->field_story_extra_large_image_fid);
                $uri = $file->uri;
                $image = theme('image_style',array(
                            'style_name' => 'widget_small',
                            'path' => $uri,
                            'attributes' => array('class' => 'custom-inline', 'style' => 'border:1px solid #aaa;')
                          )
                        );
               print l($image, 'node/' . $value->nid, array('html' => TRUE));

              }
            ?>
    </div>
    <div class="detail">
      <div class="author-right">
        <h3>
          <?php print l($value->title , 'node/' . $value->nid) ?>
        </h3>
        <p>
          <?php print mb_strimwidth(html_entity_decode(strip_tags($value->body_value)), 0, 245, "..");  ?>
        </p>
        <div class="social-icon">
          <ul>
            <?php
                      if (!empty($value->field_story_expert_name_value)) { ?>

            <li>
              <a class="def-cur-pointer" href="<?php  print  $value->field_story_expert_name_value;?>" target="_blank"><i class="fa fa-facebook"></i></a></a>
            </li>
            <?php } ?>


            <?php
                      if (!empty($value->field_reporter_twitter_handle_value)) { ?>

            <li>
              <a class="def-cur-pointer" href="<?php  print 'https://twitter.com/'.ltrim($value->field_reporter_twitter_handle_value, '@'); ?>" target="_blank"><i class="fa fa-twitter"></i></a>
            </li>
            <?php } ?>
          </ul>
        </div>
      </div>
    </div>
  </div>
  <?php } ?>
</div>
<?php } ?>


<script type="text/javascript">
(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.itg_reporter = {
        attach: function (context, settings) {
            jQuery("#edit-submit-authors-and-people-listing").click(function () {
                var title = jQuery("#edit-title").val();
                if(title != '' && title != null){
                    jQuery(".custom-author-listing-wrapper").hide();
                }else{
                    jQuery(".custom-author-listing-wrapper").show();
                }

            })
        }
    };
})(jQuery, Drupal, this, this.document);
</script>
