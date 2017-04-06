<script type="text/javascript">var __at__ = 0;</script>
<div style="display:none"><?php //print render($content); 
?> </div>
<?php print $node->view_output; ?>
<?php
if (function_exists('taboola_view')) {
  taboola_view();
}
?>

 <?php 
           if (function_exists(global_comment_last_record)) {
                 $last_record = $global_comment_last_record;
                 $config_name = trim($last_record[0]->config_name);
               }
               if($config_name == 'vukkul') {
               ?>
      <div class="vukkul-comment">
            <div id="vuukle-emote"></div>
            <div id="vuukle_div"></div>
            
             <?php 
              if(function_exists('vukkul_view')) {
                vukkul_view();
              }
              ?>
     
        </div>
               <?php } 
               if($config_name == 'other') {
               ?>
      <div id="other-comment">
            <?php
            $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
            print render($block['content']);
            ?>
        </div>
               <?php } ?>