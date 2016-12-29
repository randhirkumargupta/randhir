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
<?php if (isset($node->op)): ?>
<h3 class="show">Preview full version</h3>
<?php endif; ?>
<a class="close-preview" href="javascript:;"> </a>
<div class="node node-preview">
  <div class="field"><div class="field-label">Product Title: </div><div class="field-items"><?php print $title; ?></div></div>
  <div class="field"><div class="field-label">Image: </div><div class="field-items"><img src="<?php print image_style_url("thumbnail", $node->field_lrp_image[LANGUAGE_NONE][0]['uri']); ?>" /></div></div>
  <div class="field"><div class="field-label">Product Description: </div><div class="field-items"><?php print $node->body[LANGUAGE_NONE][0]['value']; ?></div></div>
  <div class="field"><div class="field-label">Product Count: </div><div class="field-items"><?php print $node->field_lrp_product_count[LANGUAGE_NONE][0]['value']; ?></div></div>
  <div class="field"><div class="field-label">Product Expiry Date: </div><div class="field-items"><?php print date('d/m/Y', strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value'])); ?></div></div>
  <div class="field"><div class="field-label">Actual Price: </div><div class="field-items"><?php print $node->field_lrp_actual_price[LANGUAGE_NONE][0]['value']; ?></div></div>
  <?php if(!empty($node->field_lrp_discounted_price[LANGUAGE_NONE][0]['value'])) { ?>
    <div class="field"><div class="field-label">Discounted Price: </div><div class="field-items"><?php print $node->field_lrp_discounted_price[LANGUAGE_NONE][0]['value']; ?></div></div>
  <?php } ?>
  <div class="field"><div class="field-label">Loyalty Points: </div><div class="field-items"><?php print $node->field_lrp_loyalty_points[LANGUAGE_NONE][0]['value']; ?></div></div>
  <div class="field"><div class="field-label">Status: </div><div class="field-items"><?php print $node->field_lrp_completed[LANGUAGE_NONE][0]['value'] ? $node->field_lrp_completed[LANGUAGE_NONE][0]['value'] : 'In Stock';?></div></div>
</div>
