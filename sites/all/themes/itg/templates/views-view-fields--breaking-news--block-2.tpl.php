<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php global $base_url; ?>
<?php
  $actual_link = $base_url . '/node/' . $row->nid;
  $short_url = shorten_url($actual_link, 'goo.gl');
  $fb_title = itg_common_only_text_string($row->field_field_breaking_tile[0]['rendered']['#markup']);  
  $image = '';
  $share_desc = '';
  if (!empty($row->field_field_story_extra_large_image[0]['raw']['uri'])) {
    $image = file_create_url($row->field_field_story_extra_large_image[0]['raw']['uri']);
  }
?>

<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <?php print $field->wrapper_prefix; ?>
    <?php print $field->label_html; ?>

    <div class="breakingnew-home">
      <div class="title">Breaking</div>    
      <div class="new-detail">  
          <div class="marquee">
          <?php print $field->content; ?>        
          </div>
                  
          <div class="live-tv-link">
              <?php $live_tv_img = '<img src="'. $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/imgpsh_fullsize.png" alt="LiveTV" title="LiveTV">'; ?>
              <?php print l($live_tv_img, 'livetv', array('html' => TRUE, 'attributes' => array('class' => array('live-tv-icon')))); ?>
              <a href="javascript:void(0)" class="breaking-new-close">X</a>            
          </div>
          <div class="social-share">
              <ul>
                  <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                  <li><a title = "share on facebook" class="def-cur-pointer facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $row->nid; ?>')"><i class="fa fa-facebook"></i></a></li>
                  <li><a title = "share on twitter" class="twitter" onclick="twitter_popup('<?php print urlencode($fb_title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                  <li><a title="share on google+" class="google" onclick="return googleplusbtn('<?php print $actual_link; ?>')"></a></li>                  
              </ul>
          </div>
      </div>
  </div>    
  <?php print $field->wrapper_suffix; ?>
<?php endforeach; ?>

<script type="text/javascript">
jQuery(document).ready(function(){
    //commom marque function
    function marquee(a, b) {
    var width = b.width();
    var start_pos = a.width();
    var end_pos = -width;

    function scroll() {
        if (b.position().left <= -width) {
            b.css('left', start_pos);
            scroll();
        }
        else {
            time = (parseInt(b.position().left, 10) - end_pos) *
                (15000 / (start_pos - end_pos)); 
            b.animate({
                'left': -width
            }, time, 'linear', function() {
                scroll();
            });
        }
    }

    b.css({
        'width': width,
        'left': start_pos
    });
    scroll(a, b);

    b.mouseenter(function() {     
        b.stop();                 
        b.clearQueue();           
    });                           
    b.mouseleave(function() {     
        scroll(a, b);             
    });                           

    }
    
    marquee(jQuery('.marquee'), jQuery('.marquee .field-content'));
    
});

</script>