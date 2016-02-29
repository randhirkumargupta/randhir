<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
  <?php endif; ?>

  <?php if (!empty($submitted)): ?>
    <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
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
          <?php if ($view_mode == 'full'): 
            
            ?>
      
            <div class="content-node-view">
                <h2>Basic Details</h2>
                <div class="content-details">
                    <?php print render($content['field_type']); ?>
                    <?php print render($content['field_content_type']); ?>
                     <div class="field">
                        <div class="field-label">Breaking Text:</div>
                        <div class="field-items"><?php print $title; ?></div>
                    </div>
                    
               

                    <?php $short_des = render($content['field_label']);
                    ?>
                    <?php if (!empty($short_des)): ?>
            <!--<div class="content-node-view">-->
                    <?php
                    if (!empty($short_des)):
                    print render($content['field_label']);
                    ?>
                    <?php endif; ?>
                    
            <!--</div>-->
                <?php endif; ?>
            <div class="field">
              <?php
              $type=$node->field_type[LANGUAGE_NONE][0]['value'];
              if($type == 'Live Blog') {
             print '<div class="field-label">Section</div>';     
 foreach ($node->field_section[LANGUAGE_NONE] as $value) {
  print '<div class="field-item even">'.$value[taxonomy_term]->name.'</div>';
}
                 } ?>
                 </div>
             </div>
            </div>
        
        <?php
                    $display_on = render($content['field_display_on']);
                    $cnd = $content['field_display_on']['#items']['0']['value'];
                    if (!empty($display_on)):
                    ?>
              <div class="content-node-view">
                  <?php if($cnd != '') { ?>
                  <h2>Display on</h2>
                  <?php } ?>
                  <div class="content-details">
                    <?php
                  
                    if ($cnd == 'Home Page' ) {
                print render($content['field_display_on']);
              }
              if ($cnd == 'Section') {
                print render($content['field_section']);
              }
              
                      
              ?>
                  </div>
              </div>
              <?php endif; ?>
              
                 <?php
              $keywords = render($content['field_keywords']);
  
                  if (!empty($keywords)):
              ?>
              <div class="display content-box">
              <?php print render($content['field_keywords']); ?>
              </div>
              <?php endif; ?>
        <?php 
            $browsemediaextra = render($content['field_story_extra_large_image']);
            $browsemedialarge = render($content['field_story_large_image']);
            $browsemediamedium = render($content['field_story_medium_image']);
            $browsemediasmall = render($content['field_story_small_image']);
            $browsemediaextrasmall = render($content['field_story_extra_small_image']);
            if(!empty($browsemedia) || !empty($browsemedialarge) || !empty($browsemediamedium) || !empty($browsemediasmall) || !empty($browsemediaextrasmall)):?>
          <div class="content-node-view">
            <h2>Browse Media</h2>
            <div class="content-details">
            <?php print render($content['field_story_extra_large_image']); ?>
            <?php print render($content['field_story_large_image']); ?>
            <?php print render($content['field_story_medium_image']); ?>
            <?php print render($content['field_story_small_image']); ?>
            <?php print render($content['field_story_extra_small_image']); ?>
            </div>
          </div>
           <?php endif;?>
             
        
        
            
          <div class="content-node-view">
            <h2>Content Details</h2>
            <div class="content-details">
            <?php print render($content['field_breaking_content_details']); ?>
                        </div>
          </div>
         
                    
                    
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

