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
  <div class="field"><div class="field-label">Title: </div><div class="field-items"><?php print date('d/m/Y', strtotime($title)); ?></div></div>
  <div class="field"><div class="field-label">Magazine: </div><div class="field-items"><?php print $node->field_issue_magazine[LANGUAGE_NONE][0]['entity']->title; ?></div></div>
  <div class="field"><div class="field-label">Supplement: </div><div class="field-items"><?php print $node->field_issue_supplement[LANGUAGE_NONE][0]['entity']->title; ?></div></div>
  <div class="field"><div class="field-label"><strong>Issue Cover Images:</strong> </div><div class="field-items"></div></div>
  <div class="field"><div class="field-label">Large Cover Image: </div><div class="field-items"><img src="<?php print image_style_url("thumbnail", $node->field_issue_large_cover_image[LANGUAGE_NONE][0]['uri']); ?>" /></div></div>
  <div class="field"><div class="field-label">Small Cover Image: </div><div class="field-items"><img src="<?php print image_style_url("thumbnail", $node->field_issue_small_cover_image[LANGUAGE_NONE][0]['uri']); ?>" /></div></div>
  <div class="field"><div class="field-label">Status: </div><div class="field-items"><?php print $status ? 'Published' : 'Unpublished';?></div></div>
  <div class="field">
    <div class="field-label"><strong>Attached XML Files:</strong></div>
    <div class="field-items">
    <?php 
    $count_file = count($node->field_field_issue_import_xml[LANGUAGE_NONE]);
    $i = 1;
    foreach($node->field_field_issue_import_xml[LANGUAGE_NONE] as $file){
      print $file['filename'];
      if($count_file > $i){
        echo ', ';
      }
      $i++;
    }
    ?>
    </div>
  </div>
</div>
