<?php
/**
 * @file
 *   Career graph page template.
 */
?>
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
        <?php print $actor_pic;  ?>
    </div>  <?php
    
    ?>

    <div id="container_<?php echo $key; ?>" style="min-width: 310px; height: 400px; margin: 0 auto"></div>

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
    foreach ($graph_data_all as $g_key => $graph_data) {

        if ($graph_data[1] == "") {
            $graph_data[1] = 'null';
        }
        if ($graph_data[2] == "") {
            $drow_data .= '{ x:' . $graph_data[0] . ', y: ' . $graph_data[1] . ' },';
        }
        else {
            $drow_data .= '{ x:' . $graph_data[0] . ', y: ' . $graph_data[1] . ' , movie_name:"' . $graph_data[2] . '" },';
        }
    }
    ?>

            var chart = new CanvasJS.Chart("container_<?php echo $key; ?>", {
                title: {
                    text: ""
                },
                toolTip:{   
			content: '{movie_name},{y} cr in year {x}',  
                        
		},
                axisX: {
                    interval: 1,
                     valueFormatString: "####", //try
                },
                data: [{
                        type: "line", 
                        xValueFormatString: "Year ####",
                        
                        toolTipContent: '{movie_name},{y} cr in year {x}',
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