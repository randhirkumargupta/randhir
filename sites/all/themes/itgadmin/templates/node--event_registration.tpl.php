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


<?php if (!empty($content)): ?>
  <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
    <div class="field">
      <div class="field-label"><?php print t('Gender Title:'); ?> </div><div class="field-items"><?php echo ucwords($node->field_erf_gender[LANGUAGE_NONE][0]['value']); ?></div>
    </div>

    <div class="field">
      <div class="field-label"><?php print t('First Name:'); ?> </div><div class="field-items"><?php echo ucwords($title); ?></div>
    </div>

    <div class="field">
      <div class="field-label"><?php print t('Last Name:'); ?> </div><div class="field-items"><?php echo ucwords($node->field_last_name[LANGUAGE_NONE][0]['value']); ?></div>
    </div>

    <div class="field">
      <div class="field-label"><?php print t('Email:'); ?> </div><div class="field-items"><?php echo $node->field_email_address[LANGUAGE_NONE][0]['value']; ?></div>
    </div>

    <div class="field">
      <div class="field-label"><?php print t('Mobile:'); ?> </div><div class="field-items"><?php echo ucwords($node->field_erf_mobile[LANGUAGE_NONE][0]['value']); ?></div>
    </div>

    <div class="field">
      <div class="field-label"><?php print t('ID Type:'); ?> </div><div class="field-items"><?php echo ucwords(itg_event_registration_get_id_type($node->field_erf_select_id_type[LANGUAGE_NONE][0]['value'])); ?></div>
    </div>

    <div class="field">
      <div class="field-label"><?php print t('ID Number:'); ?> </div><div class="field-items"><?php echo ucwords($node->field_erf_id_number[LANGUAGE_NONE][0]['value']); ?></div>
    </div>

    <div class="field">
      <div class="field-label"><?php print t('Company/Organization Name:'); ?> </div><div class="field-items"><?php echo ucwords($node->field_erf_company_name[LANGUAGE_NONE][0]['value']); ?></div>
    </div>

    <div class="field">
      <div class="field-label"><?php print t('Designation:'); ?> </div><div class="field-items"><?php echo ucwords($node->field_erf_designation[LANGUAGE_NONE][0]['value']); ?></div>
    </div>

    <div class="field">
      <div class="field-label"><?php print t('Mailing Address:'); ?></div><div class="field-items"><?php echo ucwords($node->field_erf_mailing_address[LANGUAGE_NONE][0]['value']); ?></div>
    </div>

    <div class="field">
      <div class="field-label"><?php print t('Postal Code:'); ?></div><div class="field-items"><?php echo ucwords($node->field_erf_postal_code[LANGUAGE_NONE][0]['value']); ?></div>
    </div>

    <?php if (!empty($node->field_erf_country[LANGUAGE_NONE][0]['taxonomy_term']->name)): ?>
      <div class="field">
        <div class="field-label"><?php print t('Country:'); ?></div><div class="field-items"><?php echo $node->field_erf_country[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
      </div>
    <?php endif; ?>

    <?php if (!empty($node->field_erf_state[LANGUAGE_NONE][0]['taxonomy_term']->name)): ?>
      <div class="field">
        <div class="field-label"><?php print t('State:'); ?> </div><div class="field-items"><?php echo $node->field_erf_state[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
      </div>
    <?php endif; ?>

    <?php if (!empty($node->field_erf_city[LANGUAGE_NONE][0]['taxonomy_term']->name)): ?>
      <div class="field">
        <div class="field-label"><?php print t('City:'); ?></div><div class="field-items"><?php echo $node->field_erf_city[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
      </div>
    <?php endif; ?>

  </div>   
<?php endif; ?>