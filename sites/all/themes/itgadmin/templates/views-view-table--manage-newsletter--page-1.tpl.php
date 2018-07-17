<?php
/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): 
           if($field == 'nid')
             continue;
          ?>
          <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?> scope="col">
            <?php print $label; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php foreach ($row as $field => $content):
          if($field == 'nid')
             continue;
          ?>
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php print $content; ?>
            <?php if($field == 'nothing_1') {
                $node = node_load($row['nid']);
                $previoustimestamp = itg_newsletter_get_previous_time($node->nid);
                $selectedTemplatenid = $node->field_newsl_select_template[LANGUAGE_NONE][0]['target_id'];
                if($node->field_newsl_newsletter_type[LANGUAGE_NONE][0]['value'] == 'automatic'){
                  $newletterContents = $node->field_newsl_newsletter_content[LANGUAGE_NONE][0]['value'];
                  $current_nid = $node->nid;
                  if ($newletterContents == 'top_20_trending') {
                    if (function_exists('_get_most_popular_nodes_based_on_top_20_trending')) {
                      $story_nodes = _get_most_popular_nodes_based_on_top_20_trending($previoustimestamp);
                      foreach ($story_nodes as $new_array) {
                        $news_detail = node_load($new_array);
                        $manual_nids[] = $news_detail->nid;
                      }
                    }
                    $manualnids = implode(',' , $manual_nids);
                    echo l( '<span class="preview-class">' .t(' preview') . '</span>' , 'newsletter-data-preview-before-download/' . $selectedTemplatenid . '/' . $newletterContents . '/' . $manualnids . '/' . $current_nid, array("attributes" => array("class" => array("colorbox-load")) ,  "query"=>array("width" => "900", "height" => "600", "iframe" => "true" , "nid" => $node->nid) , 'html' => true));
                  } 
                  elseif ($newletterContents == 'top_20_shared') {
                    if (function_exists('_get_most_popular_nodes_based_on_top_20_shared')) {
                      $story_nodes = _get_most_popular_nodes_based_on_top_20_shared($previoustimestamp);
                      foreach ($story_nodes as $new_array) {
                        $news_detail = node_load($new_array);
                        $manual_nids[] = $news_detail->nid;
                      }
                    }
                    $manualnids = implode(',' , $manual_nids);
                    echo l( '<span class="preview-class">' .t(' preview') . '</span>' , 'newsletter-data-preview-before-download/' . $selectedTemplatenid . '/' . $newletterContents . '/' . $manualnids . '/' . $current_nid, array("attributes" => array("class" => array("colorbox-load")) ,  "query"=>array("width" => "900", "height" => "600", "iframe" => "true" , "nid" => $node->nid) , 'html' => true));
                  } 
                  elseif ($newletterContents == 'top_20_most_viewed') {
                    if (function_exists('_get_most_popular_nodes_based_on_top_20_most_viewed')) {
                      $story_nodes = _get_most_popular_nodes_based_on_top_20_most_viewed($previoustimestamp);
                      foreach ($story_nodes as $new_array) {
                        $news_detail = node_load($new_array);
                        $manual_nids[] = $news_detail->nid;
                      }
                    }
                    $manualnids = implode(',' , $manual_nids);
                    echo l( '<span class="preview-class">' .t(' preview') . '</span>' , 'newsletter-data-preview-before-download/' . $selectedTemplatenid . '/' . $newletterContents . '/' . $manualnids . '/' . $current_nid, array("attributes" => array("class" => array("colorbox-load")) ,  "query"=>array("width" => "900", "height" => "600", "iframe" => "true" , "nid" => $node->nid) , 'html' => true));
                  } 
                  elseif ($newletterContents == 'select_section') {
                    foreach ($node->field_story_category[LANGUAGE_NONE] as $key => $values) {
                      $cat_array[] = $values['tid'];
                    }
                    // $cat_array = array(1206686, 1206620); // for testing purpose
                    $tid_val = implode(',' , $cat_array);
                    echo l( '<span class="preview-class">' .t(' preview') . '</span>' , 'newsletter-data-preview-before-download/' . $selectedTemplatenid . '/' . $newletterContents . '/' . $tid_val . '/' . $current_nid, array("attributes" => array("class" => array("colorbox-load")) ,  "query"=>array("width" => "900", "height" => "600", "iframe" => "true" , "nid" => $node->nid) , 'html' => true));
                  }
                } 
                else {
                  foreach($node->field_newsl_add_news[LANGUAGE_NONE] as $k => $v){
                    $load_fc = field_collection_item_load($v['value']);
                    $manual_nids[] = $load_fc->field_news_cid[LANGUAGE_NONE][0]['target_id'];
                  }
                  $manualnids = implode(',' , $manual_nids);
                  echo l( '<span class="preview-class">' .t(' preview') . '</span>' , 'newsletter-data-preview-before-download/' . $selectedTemplatenid . '/' . $manualnids , array("attributes" => array("class" => array("colorbox-load")) ,  "query"=>array("width" => "900", "height" => "600", "iframe" => "true" , "nid" => $node->nid) , 'html' => true));                  
                }
             } ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>