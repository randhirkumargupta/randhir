<?php 
if(!empty(get_itg_variable('itg_election_home_chunk'))){ ?>
<div class="row desktop-hide">
    <div class="col-md-12 col-sm-12 col-sm-12">
			<?php
			$itg_election_home_content_id = get_itg_variable('itg_election_home_content_id');
			$story_title = get_first_story_title_by_tid($itg_election_home_content_id);
			$story_title_display = $story_title[0]['title'];
			$content_link = FRONT_URL . "/" . drupal_get_path_alias('node/' . $story_title[0]['nid']);
			$story_title_display = l($story_title_display, $content_link);			
			echo '<div class="row"><div class="col-md-12 election-top-block"><h1 id="display_tit">' . $story_title_display . '</h1></div></div>';
			
			if(!empty($itg_election_home_content_id)){
      $block = block_load('itg_widget', 'election_livetv_block');
      $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
      print render($render_array);
      ?>
    </div>
</div>
<?php } ?>
<h3><span><?php print t('Show videos'); ?></span></h3>
<?php
$episodes_text = '';
global $base_url;
$current_time_program_tid = itg_live_tv_page_video_category();
?>
<div class="programe-container">
  <?php
  $counter = 0;
  foreach ($rows as $row) :
    if (function_exists('itg_category_manager_term_state')) {
      $status = itg_category_manager_term_state($row['tid']);
    }
    else {
      $status = 0;
    }
    if ($status) {
      $view = views_get_view('programme_content');
      $args = array($row['tid']);
      $view->preview('block', $args);
      $view_result = $view->result;
      $recent_video_under_cat = $view_result[0]->nid;
      if ($current_time_program_tid != $row['tid']) {
        ?>
        <div class="program-row">               
          <div class="program-right">
            <?php if (isset($row['field_cm_display_title'])) : ?>
              <div class="programe-title">
                <?php print l(html_entity_decode($row['field_cm_display_title']), 'taxonomy/term/' . $row['tid'], array('html' => TRUE)); ?>
              </div>
            <?php endif; ?>
          </div>

          <div class="toggle-icon">
            <span class="plus"><i class="fa fa-plus-circle"></i></span>
            <span class="minus"><i class="fa fa-minus-circle"></i></span>
          </div>

        </div>
        <div class="program_data"><?php print views_embed_view('programme_content_live_tv', 'block', $row['tid']); ?></div>
			<?php
				if($counter == 0){
					$block = block_load('itg_ads', 'ads_medium_rectangl_mtf_300x200');
					$render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
					print render($render_array);
					$counter++;
				}
			?>
      <?php }
    } endforeach; ?>
</div>
