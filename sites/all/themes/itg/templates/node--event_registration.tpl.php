<?php 
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $status: Flag for published status.
 * 
 * @ingroup themeable
 */

?>
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
            <div class="field">
              <div class="field-items"><strong><?php print t('Gender Title:');?> </strong><?php echo ucwords($node->field_erf_gender[LANGUAGE_NONE][0]['value']); ?></div>
            </div>
          
            <div>&nbsp;</div>
            <div class="field">
              <div class="field-items"><strong><?php print t('First Name:');?> </strong><?php echo ucwords($title); ?></div>
            </div>
            
            <div>&nbsp;</div>
            <div class="field">
              <div class="field-items"><strong><?php print t('Last Name:'); ?> </strong><?php echo ucwords($node->field_last_name[LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            <div>&nbsp;</div>
            <div class="field">
              <div class="field-items"><strong><?php print t('Email:');?> </strong><?php echo $node->field_email_address[LANGUAGE_NONE][0]['value']; ?></div>
            </div>
            
            <div>&nbsp;</div>
            <div class="field">
              <div class="field-items"><strong><?php print t('Mobile:'); ?> </strong><?php echo ucwords($node->field_erf_mobile[LANGUAGE_NONE][0]['value']); ?></div>
            </div>
          
           <div>&nbsp;</div>
            <div class="field">
              <div class="field-items"><strong><?php print t('ID Type:'); ?> </strong><?php echo ucwords(itg_event_registration_get_id_type($node->field_erf_select_id_type[LANGUAGE_NONE][0]['value'])); ?></div>
            </div>
            
           <div>&nbsp;</div>
            <div class="field">
              <div class="field-items"><strong><?php print t('ID Number:'); ?> </strong><?php echo ucwords($node->field_erf_id_number[LANGUAGE_NONE][0]['value']); ?></div>
            </div>
           
            <div>&nbsp;</div>
            <div class="field">
              <div class="field-items"><strong><?php print t('Company/Organization Name:'); ?> </strong><?php echo ucwords($node->field_erf_company_name[LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            
            <div>&nbsp;</div>
            <div class="field">
              <div class="field-items"><strong><?php print t('Designation:'); ?> </strong><?php echo ucwords($node->field_erf_designation[LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            
            <div>&nbsp;</div>
            <div class="field">
              <div class="field-items"><strong><?php print t('Mailing Address:');?> </strong><?php echo ucwords($node->field_erf_mailing_address[LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            
            <div>&nbsp;</div>
            <div class="field">
              <div class="field-items"><strong><?php print t('Postal Code:'); ?> </strong><?php echo ucwords($node->field_erf_postal_code[LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            
            <div>&nbsp;</div>
             <?php if (!empty($node->field_erf_country[LANGUAGE_NONE][0]['taxonomy_term']->name)): ?>
              <div class="field">
                <div class="field-items"><strong><?php print t('Country:');?> </strong><?php echo $node->field_erf_country[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
              </div>
            <div>&nbsp;</div>
           <?php endif; ?>
          
            <?php if (!empty($node->field_erf_state[LANGUAGE_NONE][0]['taxonomy_term']->name)): ?>
              <div class="field">
                <div class="field-items"><strong><?php print t('State:');?> </strong><?php echo $node->field_erf_state[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
              </div>
            <div>&nbsp;</div>
            <?php endif; ?>

            <?php if (!empty($node->field_erf_city[LANGUAGE_NONE][0]['taxonomy_term']->name)): ?>
               <div class="field">
                <div class="field-items"><strong><?php print t('City:');?> </strong><?php echo $node->field_erf_city[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
              </div>
            <?php endif; ?>
          
          </div>   
  <?php endif; ?>

  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>