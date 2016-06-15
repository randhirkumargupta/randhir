<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

$node = node_load(arg(1));
if(count($node->field_erf_registration_fee[LANGUAGE_NONE]) < 1){
   echo 'No group users registered!';
} else {
echo '<table class="views-table">
      <thead>
        <tr>
        <th>S.No</th>
        <th>Name</th>
        <th>Email</th>
        <th>Mobile</th>
        <th>Company</th>
        <th>Designation</th>
        <th>City</th>
      </tr></thead><tbody>';
$sn = 1;
foreach ($node->field_erf_registration_fee[LANGUAGE_NONE] as $field_collection) {
  echo '<tr>';
  $entity = entity_load('field_collection_item', array($field_collection['value']));
  $field_collection_id = $field_collection['value'];
  $name = ucwords($entity[$field_collection_id]->field_erf_gender[LANGUAGE_NONE][0]['value']).' '. ucwords($entity[$field_collection_id]->field_first_name[LANGUAGE_NONE][0]['value']).' '.ucwords($entity[$field_collection_id]->field_last_name[LANGUAGE_NONE][0]['value']);
  echo '<td>' . $sn . '</td>';
  echo '<td>' . $name . '</td>';
  echo '<td>' . ucwords($entity[$field_collection_id]->field_email_address[LANGUAGE_NONE][0]['value']) . '</td>';
  echo '<td>' . ucwords($entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value']) . '</td>';
  echo '<td>' . ucwords($entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value']) . '</td>';
  echo '<td>' . ucwords($entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value']) . '</td>';
  echo '<td>' . ucwords(taxonomy_term_load($entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['tid'])->name) . '</td>';
  echo '</tr>';
  $sn++;
}



echo '</tbody></table>';
}
?>
  
