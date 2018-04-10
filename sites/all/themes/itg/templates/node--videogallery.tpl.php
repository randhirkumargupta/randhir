<script type="text/javascript">var __at__ = 0;</script>
<?php 
if (!empty($_GET['preview_log'])) {
?>     
     <div style="display:block">
      <?php print render($content); ?>
     </div>
<?php } ?>

<?php print $node->view_output; ?>
<div class="taboola mhide">
<?php
//~ if (function_exists('taboola_view')) {
  //~ taboola_view();
//~ }
?>
<div class="taboola">
   <script type="text/javascript">
		window._taboola = window._taboola || [];
		_taboola.push({video:"auto"});
		!function (e, f, u) {
		e.async = 1;
		e.src = u;
		f.parentNode.insertBefore(e, f);
		}(document.createElement("script"), document.getElementsByTagName("script")[0], "https://cdn.taboola.com/libtrc/indiatoday-indiatoday/loader.js");
		</script>
		<div class="divclear"></div>
		<div class="nocontent">
				<div id="taboola-below-main-column"></div>
				<script type="text/javascript">
					if (jQuery(window).width() > 767) {
						window._taboola = window._taboola || [];
						_taboola.push({mode: "thumbs-2r", container: "taboola-below-main-column", placement: "below-main-column"});
				 }
				</script>
				<div id="taboola-text-2-columns"></div>
				<script type="text/javascript">
					if (jQuery(window).width() > 767) {
						window._taboola = window._taboola || [];
						_taboola.push({mode: "hybrid-text-links-2c", container: "taboola-text-2-columns", placement: "text-2-columns", target_type: "mix"});
					}
				</script>
				<script type="text/javascript">
					window._taboola = window._taboola || [];
					_taboola.push({flush: true});
				</script>
		</div>
		</div>
</div>
<?php
// get config value 
if (!empty($node->field_video_configurations['und'])) {
  foreach ($node->field_video_configurations['und'] as $value) {
    $config[] = $value['value'];
  }
}

if (function_exists(global_comment_last_record)) {
  $last_record = $global_comment_last_record;
  $config_name = trim($last_record[0]->config_name);
}
if ($config_name == 'vukkul' && in_array('comment_box', $config)) {
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
if ($config_name == 'other' && in_array('comment_box', $config)) {
  ?>
  <div id="other-comment">
      <?php
      $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
      print render($block['content']);
      ?>
  </div>
<?php } ?>
