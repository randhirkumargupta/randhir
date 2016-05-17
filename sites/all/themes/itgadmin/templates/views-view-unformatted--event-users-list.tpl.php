<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

$node = node_load(arg(1));
$count = count($node->field_erf_registration_fee[LANGUAGE_NONE]);

?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

  <?php for($item = 0; $item < $count; $item++){
    $page_no = $_GET['page'] ? $_GET['page'] : 0;
    $field_collection_id = $node->field_erf_registration_fee[LANGUAGE_NONE][$page_no]['value'];
  }
  
  $entity = entity_load('field_collection_item', array($field_collection_id));
  $entity[$field_collection_id]->field_erf_gender[LANGUAGE_NONE][0]['value'];
  
  ?>
  
  <div class="field">
    <div class="field-items"><strong>Gender Title: </strong><?php echo ucwords($entity[$field_collection_id]->field_erf_gender[LANGUAGE_NONE][0]['value']); ?></div>
  </div>
  <div>&nbsp;</div>
  <div class="field">
    <div class="field-items"><strong>First Name: </strong><?php echo ucwords($entity[$field_collection_id]->field_first_name[LANGUAGE_NONE][0]['value']); ?></div>
  </div>
  
  <?php if (isset($entity[$field_collection_id]->field_last_name[LANGUAGE_NONE][0]['value'])): ?>
  <div>&nbsp;</div>
  <div class="field">
    <div class="field-items"><strong>Last Name: </strong><?php echo ucwords($entity[$field_collection_id]->field_last_name[LANGUAGE_NONE][0]['value']); ?></div>
  </div>
  <?php endif; ?>
  
 <?php if (isset($entity[$field_collection_id]->field_email_address[LANGUAGE_NONE][0]['value'])): ?>
  <div>&nbsp;</div>
  <div class="field">
    <div class="field-items"><strong>Email: </strong><?php echo $entity[$field_collection_id]->field_email_address[LANGUAGE_NONE][0]['value']; ?></div>
  </div>
  <?php endif; ?>
  
  <?php if (isset($entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value'])): ?>
  <div>&nbsp;</div>
  <div class="field">
    <div class="field-items"><strong>Mobile: </strong><?php echo $entity[$field_collection_id]->field_erf_mobile[LANGUAGE_NONE][0]['value']; ?></div>
  </div>
  <?php endif; ?>
  
   <?php if (isset($entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value'])): ?>
  <div>&nbsp;</div>
  <div class="field">
    <div class="field-items"><strong>Company/Organization Name: </strong><?php echo ucwords($entity[$field_collection_id]->field_erf_company_name[LANGUAGE_NONE][0]['value']); ?></div>
  </div>
  <?php endif; ?>
  
  <?php if (isset($entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value'])): ?>
  <div>&nbsp;</div>
  <div class="field">
    <div class="field-items"><strong>Designation: </strong><?php echo ucwords($entity[$field_collection_id]->field_erf_designation[LANGUAGE_NONE][0]['value']); ?></div>
  </div>
   <?php endif; ?>
  
  <?php if (isset($entity[$field_collection_id]->field_erf_mailing_address[LANGUAGE_NONE][0]['value'])): ?>
  <div>&nbsp;</div>
  <div class="field">
    <div class="field-items"><strong>Mailing Address: </strong><?php echo ucwords($entity[$field_collection_id]->field_erf_mailing_address[LANGUAGE_NONE][0]['value']); ?></div>
  </div>
  <?php endif; ?>
  
  <?php if (isset($entity[$field_collection_id]->field_erf_postal_code[LANGUAGE_NONE][0]['value'])): ?>
  <div>&nbsp;</div>
  <div class="field">
    <div class="field-items"><strong>Postal Code: </strong><?php echo ucwords($entity[$field_collection_id]->field_erf_postal_code[LANGUAGE_NONE][0]['value']); ?></div>
  </div>
  <?php endif; ?>
  
  <div>&nbsp;</div>
  <?php if (!empty($entity[$field_collection_id]->field_erf_country[LANGUAGE_NONE][0]['taxonomy_term']->name)): ?>
    <div class="field">
      <div class="field-items"><strong>Country: </strong><?php echo $entity[$field_collection_id]->field_erf_country[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
    </div>
    <div>&nbsp;</div>
  <?php endif; ?>

  <?php if (!empty($entity[$field_collection_id]->field_erf_state[LANGUAGE_NONE][0]['taxonomy_term']->name)): ?>
    <div class="field">
      <div class="field-items"><strong>State: </strong><?php echo $entity[$field_collection_id]->field_erf_state[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
    </div>
    <div>&nbsp;</div>
  <?php endif; ?>

  <?php if (!empty($entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['taxonomy_term']->name)): ?>
    <div class="field">
      <div class="field-items"><strong>City: </strong><?php echo $entity[$field_collection_id]->field_erf_city[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
    </div>
  <?php endif; ?>
