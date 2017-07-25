<?php

$field_collection_data = itg_syndication_get_rules_detaiils();
echo "<div class='field'><div class='field-label'>Syndication rule details: </div><div class='field-items'>";
foreach ($field_collection_data as $data) {
  echo "<table class='views-table'>";
  echo "<tr>";
  echo "<th>Select Content Type: </th>";
  echo "<td>" . $data['content_type'] . "</td>";
  echo "</tr>";
  echo "<tr>";
  echo "<th>Select Section: </th>";
  echo "<td>" . $data['section'] . "</td>";
  echo "</tr>";
  echo "<tr>";
  echo "<th>Select Feed type: </th>";
  echo "<td>" . $data['feed_type'] . "</td>";
  echo "</tr>";
  echo "<tr>";
  echo "<th>Select Delivery End Point: </th>";
  echo "<td>";
  if (is_integer(strpos($data['feed_mode'], "Weburl:"))) {
    $feed_type = $data['feed_type'];
    $client = $data['node_obj']->title;
    $section_name = $data['section'];
    $content_type = $data['content_type'];
    $url_friendly_path = itg_common_url_friendly_path("$feed_type/$client/$section_name-$content_type");
    $feed_dir = "public://$url_friendly_path-feed.xml";
    echo "<a target='_blank' href='" . file_create_url($feed_dir) . "'>" . file_create_url($feed_dir) . "</a>";
  } else {
    echo $data['feed_mode'];
  }
  echo "</td>";
  echo "</tr>";
  echo "<tr>";
  echo "<th>Set Time: </th>";
  echo "<td>" . $data['feed_time'] . "</td>";
  echo "</tr>";
  echo "<tr>";
  echo "<th>Number of feeds: </th>";
  echo "<td>" . $data['feed_num'] . "</td>";
  echo "</tr>";
  echo "<tr>";
  echo "<th>Select Frequency: </th>";
  echo "<td>" . $data['feed_frequency'] . "</td>";
  echo "</tr>";
  echo "</table>";
}
echo "</div></div>";
//field--field_syndication_mode--field_syndication_rule_details.tpl