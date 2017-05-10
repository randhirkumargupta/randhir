<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $rows: An array of row items. Each row is an array of content
 *   keyed by field ID.
 * - $header: an array of headers(labels) for fields.
 * - $themed_rows: a array of rows with themed fields.
 * @ingroup views_templates
 */
?>
<?php
  global $base_url;
  $logo = $base_url . '/' . drupal_get_path('theme', 'itg') . '/logo.png';
?>
<<?php print "channel"; ?>>
<<?php print $xml_tag['path']; ?>><![CDATA[<?php print $base_url; ?>]]></<?php print $xml_tag['path']; ?>>
<<?php print "description"; ?>><?php print t("India Today"); ?></<?php print "description"; ?>>
<<?php print $xml_tag['title']; ?>><![CDATA[<?php print t("India Today Editor's Picks"); ?>]]></<?php print $xml_tag['title']; ?>>
<<?php print "lastBuildDate"; ?>><?php print $themed_rows[0]['created']; ?></<?php print "lastBuildDate"; ?>>
<<?php print "image"; ?>>
  <<?php print "url"; ?>><?php print $logo; ?></<?php print "url"; ?>>
  <<?php print "title"; ?>><![CDATA[<?php print t("India Today Editor's Picks"); ?>]]></<?php print "title"; ?>>
  <<?php print $xml_tag['path']; ?>><![CDATA[<?php print $base_url; ?>]]></<?php print $xml_tag['path']; ?>>
</<?php print "image"; ?>>

<?php foreach ($themed_rows as $count => $row): ?>
  <<?php print $item_node; ?>>
<?php foreach ($row as $field => $content): ?>
    <<?php print $xml_tag[$field]; ?>><?php print $content; ?></<?php print $xml_tag[$field]; ?>>
<?php endforeach; ?>
  </<?php print $item_node; ?>>
<?php endforeach; ?>
</<?php print "channel"; ?>>

