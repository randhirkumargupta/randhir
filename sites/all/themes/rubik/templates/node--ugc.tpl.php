<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
  <?php endif; ?>

  <?php if (!empty($submitted)): ?>
    <!-- <div class='<?php print $hook ?>-submitted clearfix'><?php // print $submitted ?></div>-->
  <?php endif; ?>

  <?php if (!empty($links)): ?>
    <div class='<?php print $hook ?>-links clearfix'>
      <?php print render($links) ?>
    </div>
  <?php endif; ?>

  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    </div></div>
  <?php endif; ?>

  <?php if ($layout): ?>
    <div class='column-main'><div class='column-wrapper'>
  <?php endif; ?>

  <?php if (!empty($title_prefix)) print render($title_prefix); ?>

  <?php if (!empty($title) && !$page): ?>
    <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
      <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
      <a href="<?php print $node_url ?>"><?php print $title ?></a>
    </h2>
  <?php endif; ?>

  <?php if (!empty($title_suffix)) print render($title_suffix); ?>

  <?php if (!empty($content)): ?>
    <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
      <?php //print render($content) ?>
          <?php if ($view_mode == 'full'):  ?>
                <div class="content-node-view">
                 <?php
                 $content_type = $node->field_ugc_content_type[LANGUAGE_NONE][0]['value'];
                 print render($content['field_user_name']);
                 print  render($content['field_user_email']);
                 print  render($content['field_ugc_content_type']);
                 ?>
                 <div class="field">
                  <div class="field-label"><?php print t('Title:'); ?></div>
                  <div class="field-items"><?php print $title; ?></div>
                 </div>
                    <?php
                 if($content_type == 'story' || $content_type == 'recipe' || $content_type == 'blog') { 
                   print  render($content['field_user_message']);
                  
                 }
                  
                 if($content_type == 'photogallery') {
                   
                   print  render($content['field_ugc_upload_photo']);
                 }
                 
                 if($content_type == 'recipe') {
                   print  render($content['field_ugc_upload_photo']);
                   print  render($content['field_astro_video']);
                 }
                 
                 ?>
                <div class="field">
                  <div class="field-label"><?php print t('Created on:'); ?></div>
                  <div class="field-items"><?php print  date(ITGDATE, $node->created); ?></div>
                </div>
                <?php 
                // create path for approve and reject
               $arg_id = arg(1);
               $node_status = $node->node_status;
                if($node_status == '1') {
                  print '<strong>Action :</strong> ';
                  print l(  t('Approve'),  'node/add/'.$content_type,  array('attributes' =>array('class'=>'approve-ugc', 'id'=>'approve-ugc'), 'query'=>array('destination'=>'manage-ugc','id'=>$arg_id) ));
                  print ' | ';
                  print l(  t('Reject'),  'ugc-title/'.$arg_id.'/reject',  array('attributes' =>array('class'=>'reject-ugc', 'id'=>'reject-ugc')));
                  print ' | ';
                  print l(  t('Cancel'),  'manage-ugc',  array('attributes' =>array('class'=>'manage-ugc', 'id'=>'manage-ugc')));
                }
                else
                {
                  print '<strong>Action :</strong> ';
                  print l(  t('Cancel'),  'reject-ugc-content-list',  array('attributes' =>array('class'=>'reject-ugc-content-list', 'id'=>'reject-ugc-content-list')));
                }
                ?>
                <?php
              // end of view mode full condition
              endif;
              ?>
    </div>
  <?php endif; ?>

  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

