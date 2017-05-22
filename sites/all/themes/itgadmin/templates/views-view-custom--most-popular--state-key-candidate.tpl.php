
<?php
foreach ($rows as $index => $row) {


    $consti[] = $row['state'];
}

$resultdata = array_unique($consti);
?>
<div class="key-candidate">

    <div class="list-state">   <?php
foreach ($resultdata as $key => $mainids) {
    $firstactive = "";
    if ($key == 0) {
        $firstactive = "active";
    }
    $term_data = taxonomy_term_load($mainids);
    print '<span class="' . $firstactive . '" data-tag="kc-' . $term_data->tid . '">' . ucfirst($term_data->name) . '</span>';
}
?>
    </div> 
        <?php
        // p($rows);
        foreach ($resultdata as $key => $mainids) {
            $first_show = "";
            if ($key == 0) {
                $first_show = "key-candidate-detail-first";
            }
            ?>
        <div class="key-candidate-detail <?php echo $first_show; ?> kc-<?php echo $mainids; ?>" id="">

            <?php
            foreach ($rows as $index => $row) {
                if ($row['state'] == $mainids) {
                    $term_data = taxonomy_term_load($row['state']);
                    ?> 


                    <ul>
            <?php if (!empty($row['field_story_extra_large_image'])) { ?>
                            <li><?php print $row['field_story_extra_large_image']; ?></li>
                        <?php
                        }
                        else {
                            print "<li><img width='88' height='66'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image88x66.jpg' alt='' /></li>";
                        }
                        ?>

                        <li>
                            <p class="candidate-name"><?php print ucfirst($row['title']); ?></p>
                            <p class="constituancy"><?php print ucfirst($row['constituency']); ?></p>
                            <p class="party"><?php print ucfirst($row['field_party_name']); ?></p>
                        </li>
                        <li>

                            <?php
                            if ($row['extra'] == "Win") {
                                print ' <p class="status green"><i class="fa fa-thumbs-o-up"></i><span>'.t('WON').'</span></p>';
                            }
                            else if ($row['extra'] == "Lost") {
                                print ' <p class="status red"><i class="fa fa-thumbs-o-down"></i><span>'.t('LOST').'</span></p>';
                            }
                            else if ($row['extra'] == "Lead") {
                                print ' <p class="status orange"> <i class="fa fa-hand-o-up" aria-hidden="true"></i><span>'.t('LEADING').'</span></p>';
                            }
                            ?>
                        </li>         
                    </ul>

                <?php }
            } print '</div>';
        }; ?>


    </div>

    <script>
        jQuery(document).ready(function() {
            jQuery(".key-candidate .list-state span").click(function() {
                jQuery(".key-candidate .list-state span").removeClass('active');
                jQuery(this).addClass('active');
                jQuery('.key-candidate-detail').hide();
                var getval = jQuery(this).attr('data-tag');
                jQuery('.' + getval).show();
            });
        });
    </script>
