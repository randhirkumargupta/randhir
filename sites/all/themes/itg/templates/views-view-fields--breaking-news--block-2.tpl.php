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
<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <?php print $field->wrapper_prefix; ?>
    <?php print $field->label_html; ?>

    <div class="breakingnew-home">
      <div class="title">Breaking</div>    
      <div class="new-detail">  
          <?php print $field->content; ?>        
          <div class="social-share">
              <ul>
                  <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                  <li><a  class="facebook"><i class="fa fa-facebook"></i></a></li>
                  <li><a href="javascript:"  class="twitter"><i class="fa fa-twitter"></i></a></li>
                  <li><a title="share on google+" href="#"  class="google"></a></li>
              </ul>
          </div>        
          <div class="live-tv-link">
              <a href="#"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/imgpsh_fullsize.png'; ?>"</a>
              <a href="javascript:void(0)" class="breaking-new-close">X</a>            
          </div>
      </div>
  </div>    
  <?php print $field->wrapper_suffix; ?>
<?php endforeach; ?>