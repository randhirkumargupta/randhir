<?php if (!empty($data)) : global $base_url, $theme; ?>


  <?php
  global $base_url;
  $classrow = "col-md-8 fullchart-table";
  $itg_election_home_webcast_livetv = get_itg_variable('itg_election_home_webcast_livetv');
  $itg_election_home_content_id = get_itg_variable('itg_election_home_content_id');
  if (!empty($itg_election_home_webcast_livetv)) {
    $classrow = "col-md-4";
  }  
  if ($theme != 'seven') {
    if ($theme == FRONT_THEME_NAME) {
      $section = arg(2);
    }
    else {
      $section = $_GET['section'];
    }
    if (empty($section)) {
      $section = $_GET['section_name'];
    }
    if (empty($section)) {
      $section = get_itg_variable('home_page_election_tid');
    }
  }
 
?>
<?php if(!empty($itg_election_home_content_id)){
  $story_title = get_first_story_title_by_tid($itg_election_home_content_id);
  $content_link = $base_url . "/" . drupal_get_path_alias('node/' . $story_title[0]['nid']);
  $story_title_display = $story_title[0]['title'];
  $actual_link = $content_link;
  $search_title = preg_replace("/'/", "\\'", $story_title_display);
  $fb_share_title = htmlentities($story_title_display, ENT_QUOTES);  
  $short_url = $actual_link;
  $story_title_display = l($story_title_display, $content_link);
  $display_title = "";
  if (empty($story_title)) {
    $display_title = 'style="display:none"';
  }
 if (!empty($story_title[0]['uri'])) {
   $src = file_create_url($story_title[0]['uri']);
 }
  echo '<div class="row"><div class="col-md-12 election-top-block"><h1 ' . $display_title . ' id="display_tit">' . $story_title_display . '<div class="social-share">
              <ul>
                  <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                  <li><a title="share on facebook" class="facebook def-cur-pointer" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $fb_share_title . "'" . ', ' . "'" . $share_desc . "'" . ', ' . "'" . $src . "'" . ')"><i class="fa fa-facebook"></i></a></li>
                  <li><a  title="share on twitter" class="twitter def-cur-pointer" onclick="twitter_popup(' . "'" . urlencode($search_title) . "'" . ', ' . "'" . urlencode($short_url) . "'" . ')"><i class="fa fa-twitter"></i></a></li>
                  <li><a title="share on google+" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')" class="google def-cur-pointer"><i class="fa fa-google-plus" aria-hidden="true"></i></a></li>
              </ul>
          </div></h1></div></div>';
 }?>
 <div class="row electionHome-section">
<?php if(!empty($itg_election_home_webcast_livetv)){?>
<div class="col-md-4 mt-50">
    <div class="itg-widget">
      <?php if($itg_election_home_webcast_livetv == 'livetv') {?>
      <div class="data-holder" id="home-livetv-election">
        <?php
        $block = block_load('itg_widget', 'live_tv');
        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
        print render($render_array);
        ?>
      </div>
      <?php } elseif ($itg_election_home_webcast_livetv == 'webcast') { ?>
        <div class="data-holder" id="home-webcast-election">
          <?php
            print get_itg_variable('itg_election_home_webcast_html');
          ?>
        </div>
      <?php }?>
    </div>
</div>
<?php }?>
<?php  
  // Start high chart Graph
  /*foreach ($data as $index => $row):
		$graph_link = $base_url . '/state-elections/' . $section . '/' . $row->field_election_state_tid;
		if(!empty($row->field_graph_category_value)){
			$graph_link = $base_url . '/'. drupal_get_path_alias('taxonomy/term/' . $row->field_graph_category_value);
		}
    if($row->field_graph_type_value == 'Graph'){

    ?>
    <div class="<?php echo $classrow; ?> mt-50">
      <div class="itg-widget">
        <div class="droppable <?php print $gray_bg_layout; ?>">
          <div class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name']; ?>">
            <a href="<?php echo $graph_link; ?>" >
              <div class="data-holder">
                <div class="graph-design">
                  <div id="container_<?php echo $index; ?>"></div>
                  <div class="divider"></div>
                </div>

    <?php
    $jsondata = file_get_contents($row->field_election_constituency_tall_value);
    $jsondata = json_decode($jsondata);

    if (!empty($jsondata)) {
      print '<table cellspacing="0" cellpadding="8" border="0" width="100%" id="allianceTable_delhi" class="schedule2"><tbody>
<tr><th></th><th>PARTIES</th><th>LEADS</th><th>WON</th><th>TOTAL</th></tr>
';
    }


    foreach ($jsondata->election->items as $elction_telly_data) {
      $total_result = (int) $elction_telly_data->pWon + (int) $elction_telly_data->pLead;
      print '<tr><td class="party-color" style="background:' . $elction_telly_data->pColor . '"></td><td class="padtext">' . ucfirst($elction_telly_data->pName) . '</td>
<td>' . $elction_telly_data->pLead . '</td>
<td>' . $elction_telly_data->pWon . '</td>
<td>' . $total_result . '</td></tr>';
    }

    ?>
</tbody>


</table><div class="social-share">
                    <ul>
                        <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                        <li><a title="share on facebook" class="facebook def-cur-pointer" onclick='fbpop("<?php echo $actual_link; ?>", "<?php echo urlencode($fb_share_title); ?>","<?php echo urlencode($share_desc); ?>","<?php echo $src; ?>")'><i class="fa fa-facebook"></i></a></li>
                        <li><a  title="share on twitter" class="twitter def-cur-pointer" onclick='twitter_popup("<?php echo urlencode($search_title) ?>" , "<?php echo urlencode($short_url)?>")'><i class="fa fa-twitter"></i></a></li>
                        <li><a title="share on google+" onclick='return googleplusbtn("<?php echo $actual_link ?>")' class="google def-cur-pointer"></a></li>
                    </ul>
                </div>'
     
              </div>
            </a>
          </div>             
        </div>
      </div>
    </div>
    <?php }elseif ($row->field_graph_type_value == 'Dot Graph') { ?>

      <div class="<?php echo $classrow; ?> mt-50">
       <?php
         $json_path = $row->field_election_svg_json_url_value;
         $from = "fullhousemap-";
         $to = ".json";
         $sub = substr($json_path, strpos($json_path,$from)+strlen($from),strlen($json_path));
         $state_name = substr($sub,0,strpos($sub,$to));
         ?>
      <div class="itg-widget">
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
  <?php endforeach; */?>
<!-- End High Cart graph -->
<div class="col-md-4 col-sm-4 mt-50">
    <div class="itg-widget">
        <div class="data-holder" id="home-top-stories-election">
          <?php
          $block = block_load('itg_widget', 'election_top_stories');
          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
          print render($render_array);
          ?>
        </div>
    </div>
</div>
</div>
  <?php 
  $bottom_label = get_itg_variable('itg_election_home_bottom_label');
  $bottom_label_url = get_itg_variable('itg_election_home_bottom_label_url');
  if(!empty($bottom_label)) {
    if(!empty($bottom_label_url)) {?>
<span class="fullcoverage-electionlink"><a href="<?php echo $bottom_label_url;?>"><?php echo $bottom_label;?></a></span> 
    <?php } else {?>
      <span class="fullcoverage-electionlink"><?php echo $bottom_label;?></span> 
    <?php }; ?>
  <?php }; ?>
<?php endif; ?>

