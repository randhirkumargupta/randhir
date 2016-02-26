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

<div class="cm-node-view">
  <div class="field-div"><div class="field-label">Supplement Title: </div><div class="field-item"><?php print $title; ?></div></div>
  <div class="field-div"><div class="field-label">Magazine: </div><div class="field-item"><?php print $node->field_supp_select_magazine[LANGUAGE_NONE][0]['entity']->title; ?></div></div>
  <div class="field-div"><div class="field-label">Issue: </div><div class="field-item"><?php print date('m/d/Y', strtotime($node->field_supp_issue[LANGUAGE_NONE][0]['value'])); ?></div></div>
  <div class="field-div"><div class="field-label">Status: </div><div class="field-item"><?php print $status ? 'Published' : 'Unpublished';?></div></div>
</div>