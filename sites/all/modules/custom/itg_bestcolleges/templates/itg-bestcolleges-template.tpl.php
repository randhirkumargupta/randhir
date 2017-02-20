<?php
/**
 * @file : itg-bestcolleges-template.tpl.php
 */
$comment_value = variable_get('COMMENT_CONFIG');
$config_name = $comment_value[0]->config_name;
?>
<div class="survey-form-main-container" style="margin:10px 0px 10px 0px;">
  <h1 class="survey-title"><?php //echo 'Quiz: '. $node->title; ?></h1>
<div class="row">
  <div class="row" style="border-size:2px; border-style:solid;border-color:black;">
   <?php
      if (array_filter(views_get_view_result('best_college_image_slider', 'block_2'))) {
          print '<h2 class="my-view-block-title">Best college list</h2>';
          print views_embed_view('best_college_image_slider', 'block_2');
      }
     ?>
     </div>
   <div class="row" style="border-size:2px; border-style:solid;border-color:black; margin-top: 17px;">
    <div class="list-grid">
        <a href="http://staging.indiatodayonline.in/taxonomy/term/878?view_type=list" class="active">
        <i class="fa fa-list" aria-hidden="true"></i>List</a><span class="pipline"> | </span>
        <a href="http://staging.indiatodayonline.in/taxonomy/term/878?view_type=grid">
        <i class="fa fa-th" aria-hidden="true"></i> Grid</a>
    </div>
    <?php
      if (array_filter(views_get_view_result('best_college_image_slider', 'block_1'))) {
          print views_embed_view('best_college_image_slider', 'block_1');
      }

    ?>
    </div>
</div>


  <?php
  if ($from_story != 'yes') {
    if (function_exists('taboola_view')) {
      taboola_view();
    }
  }

  if ($config_name == 'vukkul') {
    ?>
    <div class="vukkul-comment">
        <div id="vuukle-emote"></div>
        <div id="vuukle_div"></div>

        <?php
        if (function_exists('vukkul_view')) {
          vukkul_view();
        }
        ?>

    </div>
    <?php
  }
  if ($config_name == 'other') {
    ?>
    <div id="other-comment">
        <?php
        $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
        print render($block['content']);
        ?>
    </div>
  <?php } ?>
</div>
