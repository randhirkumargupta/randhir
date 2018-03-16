<script type="text/javascript">var __at__ = 0;</script>
<?php 
if (!empty($_GET['preview_log'])) {
     $display_style = 'block'; 
	} else {
    $display_style = 'none';
  }
?>
<div style="display:<?php print $display_style; ?>">
<?php print render($content); ?>
</div>
<?php print $node->view_output; ?>
<?php
// get config value
if (!empty($node->field_photogallery_configuration['und'])) {
  foreach ($node->field_photogallery_configuration['und'] as $value) {
    $config[] = $value['value'];
  }
}

if (function_exists('taboola_view')) {
  $tab_org = "_taboola.push({article:";
  $tab_rep = "_taboola.push({photo:";
  $tabula_view = taboola_view();
  str_replace($tab_org, $tab_rep, $tabula_view);
}
     
if (function_exists(global_comment_last_record)) {
  $last_record = $global_comment_last_record;
  $config_name = trim($last_record[0]->config_name);
}
if ($config_name == 'vukkul' && in_array('commentbox', $config)) {
  ?>
  <div class="vukkul-comment">
      <div id="vuukle-emote"></div>
      <!-- <div id="vuukle_div"></div> -->
      <div id="vuukle-comments"></div>
      <div class='vuukle-powerbar'></div>
      <?php
      if (function_exists('vukkul_view')) {
        vukkul_view();
      }
      ?>

  </div>
<?php
}
if ($config_name == 'other' && in_array('commentbox', $config)) {
  ?>
  <div id="other-comment">
        <?php
        $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
        print render($block['content']);
        ?>
  </div>
<?php } ?>