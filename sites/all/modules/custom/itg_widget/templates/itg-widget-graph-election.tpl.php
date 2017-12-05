<?php if (!empty($data)) : global $base_url, $theme; ?>
<?php
  global $base_url;
  $classrow = 6;
  $rowcounter = ceil(12 / count($data));
  if (count($data) <= 2) {
    $classrow = "col-md-$rowcounter";
  }
  else if (count($data) > 2) {
    if (count($data) > 5) {
      $datacount = 5;
    }
    else {
      $datacount = count($data);
    }
    $classrow = "col-el-" . $datacount;
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
  }
  // Start high chart Graph
  foreach ($data as $index => $row):
	$graph_link = $base_url . '/state-election/' . $section . '/' . $row->field_election_state_tid
	if(!empty($row->field_graph_category_value)){
		$graph_link = $base_url . '/'. drupal_get_path_alias('taxonomy/term/' . $row->field_graph_category_value)
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

    print '
</tbody>


</table><div class="social-share">
                    <ul>
                        <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                        <li><a title="share on facebook" class="facebook def-cur-pointer" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $fb_share_title . "'" . ', ' . "'" . $share_desc . "'" . ', ' . "'" . $src . "'" . ')"><i class="fa fa-facebook"></i></a></li>
                        <li><a  title="share on twitter" class="twitter def-cur-pointer" onclick="twitter_popup(' . "'" . urlencode($search_title) . "'" . ', ' . "'" . urlencode($short_url) . "'" . ')"><i class="fa fa-twitter"></i></a></li>
                        <li><a title="share on google+" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')" class="google def-cur-pointer"></a></li>
                    </ul>
                </div>';
    ?>
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
                     <span id = "hmelect-<?php echo $state_name;?>" onclick="openStateHref('up');"  class="tallyChartImageCursor"></span>
                     <script type="text/javascript">
                       var chart_path = "<?php echo $row->field_election_chart_json_url_value; ?>";
                       var svg_path = "<?php echo $row->field_election_svg_json_url_value; ?>";
                       var state_name = "<?php echo $state_name; ?>";
                        hmelection(state_name, '1',svg_path,chart_path);
                      </script>
                      <div class="statename" ><span class="stateNameText" onclick="openStateHref('up');" rel="<?php echo strtoupper(str_replace("-"," ",$state_name));?>" ><?php echo strtoupper(str_replace("-"," ",$state_name));?></span> <span class="sharethis">
                         <?php
                                  print '<div class="social-share">
                                         <ul>
                                             <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                                             <li><a title="share on facebook" class="facebook def-cur-pointer" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $fb_share_title . "'" . ', ' . "'" . $share_desc . "'" . ', ' . "'" . $src . "'" . ')"><i class="fa fa-facebook"></i></a></li>
                                             <li><a  title="share on twitter" class="twitter def-cur-pointer" onclick="twitter_popup(' . "'" . urlencode($search_title) . "'" . ', ' . "'" . urlencode($short_url) . "'" . ')"><i class="fa fa-twitter"></i></a></li>
                                             <li><a title="share on google+" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')" class="google def-cur-pointer"></a></li>
                                         </ul>
                                     </div>';
                         ?>
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
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>
