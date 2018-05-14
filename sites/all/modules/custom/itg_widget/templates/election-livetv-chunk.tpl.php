<?php if (!empty($data)) : global $base_url, $theme; ?>


  <?php
  global $base_url;
  $section = get_itg_variable('home_page_election_tid');
 
?>

 <div class="row electionHome-section">
<?php  
  // Start high chart Graph
  foreach ($data as $index => $row):
		$graph_link = $base_url . '/state-elections/' . $section . '/' . $row->field_election_state_tid;
		if(!empty($row->field_graph_category_value)){
			$graph_link = $base_url . '/'. drupal_get_path_alias('taxonomy/term/' . $row->field_graph_category_value);
		}
    if ($row->field_graph_type_value == 'Dot Graph') { ?>

      <div class="<?php echo $classrow; ?> col-md-12 col-sm-12 col-sm-12">
       <?php
         $json_path = $row->field_election_svg_json_url_value;
         $from = "fullhousemap-";
         $to = ".json";
         $sub = substr($json_path, strpos($json_path,$from)+strlen($from),strlen($json_path));
         $state_name = substr($sub,0,strpos($sub,$to));
         ?>
      <div class="itg-widget">
        <h3><span>Karnataka Election Result</span></h3>
        <div class="droppable <?php print $gray_bg_layout; ?>">
          <div class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name']; ?>">
            <a href="<?php echo $graph_link; ?>" >
              <div class="data-holder">
                <div class="graph-design">
                <div class="statesvg-map">
                     <span id = "hmelect-<?php echo $state_name;?>" class="tallyChartImageCursor"></span>
                     <script type="text/javascript">
                       document.addEventListener("DOMContentLoaded", function(event) { 
                        var chart_path = "<?php echo $row->field_election_chart_json_url_value; ?>";
                        var svg_path = "<?php echo $row->field_election_svg_json_url_value; ?>";
                        var state_name = "<?php echo $state_name; ?>";
                        var refresh_time = "<?php echo (!empty(get_itg_variable('election_graph_refreshtime')) ? get_itg_variable('election_graph_refreshtime') : 3000); ?>";
                         hmelection(state_name, '1',svg_path,chart_path, refresh_time);
                      });                   
                      </script>
                      <div class="statename" ><span class="stateNameText"  rel="<?php echo strtoupper(str_replace("-"," ",$state_name));?>" ><?php echo strtoupper(str_replace("-"," ",$state_name));?></span> <span class="sharethis">
                         
                      </div>
                  </div>
                    <span id = "fhs-<?php echo $state_name;?>"></span>
                </div>
              </div>
            </a>
          </div>
        </div>
      </div>
    </div>
  <?php } ?>
  <?php endforeach; ?>
<!-- End High Cart graph -->
<div class="col-md-12 col-sm-12 col-sm-12">
    <div class="itg-widget">
			<?php
			$itg_election_home_content_id = get_itg_variable('itg_election_home_content_id');
			if(!empty($itg_election_home_content_id) && $arg(0) != 'livetv'){
				$story_title = get_first_story_title_by_tid($itg_election_home_content_id);
				$story_title_display = $story_title[0]['title'];
				$content_link = FRONT_URL . "/" . drupal_get_path_alias('node/' . $story_title[0]['nid']);
				$story_title_display = l($story_title_display, $content_link);			
				echo '<div class="row"><div class="col-md-12 election-top-block"><h1 id="display_tit">' . $story_title_display . '</h1></div></div>';
			}	
			?>
        <div class="data-holder" id="home-top-stories-election">
          <h3><span><?php echo get_itg_variable('itg_election_top_stories_label');?></span></h3>
          <?php
          $block = block_load('itg_widget', 'election_top_stories');
          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
          print render($render_array);
          ?>
        </div>
    </div>
</div>
</div>
<?php endif; ?>

