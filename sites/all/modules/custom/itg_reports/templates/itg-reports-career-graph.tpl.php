<?php
/**
 * @file
 *   Career graph page template.
 */
$arg = arg();
$node = node_load($arg[1]);
$source_type = $node->field_story_source_type[LANGUAGE_NONE][0]['value'];
if($source_type != 'migrated') { ?>
<?php foreach ($output as $key => $value): ?>
  <?php
  if (strpos($actor[$key]['pic_uri'], 'public://') !== false) {
    $actor_pic = theme(
        'image_style', array(
      'style_name' => 'mr_graph_pic',
      'path' => $actor[$key]['pic_uri'],
        )
    );
  }
  else {
    $actor_pic = '<img src="' . $actor[$key]['pic_uri'] . '" alt="" />';
  }
  ?>
  <div class="career-graph-data">
    <div class="gray-bg"><?php print t('Career Graph'); ?></div>
    <div class="black-bg"><?php print $actor[$key]['name']; ?></div>
    <?php print $actor_pic; ?>
  </div>
<div class="dots-know-more"><?php print t('Click on dots to know more'); ?></div>
  <div id="container_<?php echo $key; ?>" style="min-width: 290px; height: 400px; margin: 0 auto"></div>

<?php endforeach; ?>

<script>
  window.onload = function() {

<?php
foreach ($output as $key => $value) {

  $graph_data_all = $value['chart']['career']['#data'];
  $earning = "";
  $drow_data = "";
  $moviename = array();
  $year = array();
  $graph_image = array();
  $graph_pic_url = '';
  foreach ($graph_data_all as $g_key => $graph_data) {
    
    if (!empty($graph_data[3])) {
      $grapg_file = file_load($graph_data[3]);
      $uri = $grapg_file->uri;
      $graph_pic_url = '<img src="' . file_create_url($uri) . '" alt="' .  $graph_data[2] . '" />';
      if(function_exists('itg_common_global_alt_title')) {
        $img_attr = itg_common_global_alt_title('field_movie_graph_image', $graph_data[3]);
      }
    }
    else {
      $graph_pic_url = '';
    }
    
    if ($graph_data[1] == "") {
      $graph_data[1] = 'null';
    }
    if ($graph_data[2] == "") {
      $drow_data .= '{ x:' . $graph_data[0] . ', y: ' . $graph_data[1] . ' },';
    }
    else {
      if(!empty($uri)) {
      $image = "<img src='".file_create_url($uri)."' alt='".$img_attr[0]['field_movie_graph_image_alt']."' title='".$img_attr[0]['field_movie_graph_image_title']."'>";
      } else {
      $image = ''; 
      }
      $drow_data .= '{ x:' . $graph_data[0] . ', y: ' . $graph_data[1] . ' , movie_name:"' . $graph_data[2] . '", graph_name:"' . $image . '"},';
    }
    
  }
  ?>
      var chart = new CanvasJS.Chart("container_<?php echo $key; ?>", {
        title: {
          text: ""
        },
        toolTip: {
          content: '{movie_name},{y} cr in {x} <img src={graph_name} alt={movie_name}>',
        },
        axisX: {
          interval: 1,
          valueFormatString: "####", //try
          labelAngle: 90
        },
        data: [{
            type: "line",
            xValueFormatString: "Year ####",
            toolTipContent: '{movie_name},{y} cr in {x} {graph_name}',
            connectNullData: true,
            dataPoints: [
  <?php echo rtrim($drow_data, ','); ?>
            ]
          }]
      });
      chart.render();
<?php } ?>
  };

</script>
<?php } ?>

<?php
if ($source_type == 'migrated') {
  foreach ($node->field_mega_review_cast['und'] as $field_collection) {
    if (function_exists('itg_get_migrated_carrer_graph_data')) {
      $graph_html = itg_get_migrated_carrer_graph_data($field_collection['target_id']);
      print $graph_html;
    }
  }
}
?>
