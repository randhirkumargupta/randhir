<?php
/**
 * @file
 *   Career graph page template.
 */
?>
<script src="https://code.highcharts.com/highcharts.js"></script>
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
        <?php //print $actor_pic;  ?>
    </div>  <?php
    //print drupal_render($value); 
    $graph_data_all = $value['chart']['career']['#data'];
    ksort($graph_data_all);
    $earning = "";
    $moviename = array();
    foreach ($graph_data_all as $g_key => $graph_data) {
        $year[] = $g_key;
        if ($graph_data[1] == "") {
            $graph_data[1] = '""';
        }
        $earning .= $graph_data[1] . ',';
        if (isset($graph_data[2]) && !empty($graph_data[2])) {
            $moviename[$g_key] = $graph_data[2];
        }
    }
    ?>
    <script type="text/javascript">
        jQuery(function() {
            var xcontent = new Array();
    <?php foreach ($year as $key => $val) { ?>
                xcontent.push('<?php echo $val; ?>');
    <?php } ?>
            var moviename = {};
    <?php foreach ($moviename as $key => $val_movie) { ?>
                moviename[<?php echo $key; ?>] = '<?php echo $val_movie; ?>';
    <?php } ?>
            jQuery('#container_<?php echo $key; ?>').highcharts({
                title: {
                    text: '',
                    x: -20 //center
                },
                subtitle: {
                    text: '',
                    x: -20
                },
                xAxis: {
                    categories: xcontent,
                    title: {
                        text: 'Year'
                    },
                },
                yAxis: {
                    title: {
                        text: 'Earning'
                    },
                    plotLines: [{
                            value: 0,
                            width: 1,
                            color: '#808080'
                        }]
                },
                legend: {
                    layout: 'vertical',
                    align: 'right',
                    verticalAlign: 'middle',
                    borderWidth: 0
                },
                tooltip: {
                    formatter: function() {
                        var xcod = this.x;

                        return 'Earning for ' + this.x + '</b> is <b>' + this.y + '</b>, for Movie: ' + moviename[xcod];

                    },
                },
                series: [{
                        name: '',
                        data: [<?php echo rtrim($earning, ','); ?>]
                    }]
            });
        });
    </script>
    <div id="container_<?php echo $key; ?>" style="min-width: 310px; height: 400px; margin: 0 auto"></div>

<?php endforeach; ?>

