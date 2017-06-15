<div id="compare-section" class="auto-compare-section <?php echo $data['column']; ?>">
    <?php
    global $base_url;
    $class = 'col-md-5';
    $tableClass = 'col-md-4';
    $tableClass2 = 'col-md-4';
    if ($data['second'] == null) {
        $class = 'col-md-12';
        $tableClass = 'col-md-6';
        $tableClass2 = 'col-md-6';
    }
    ?>
    <div class="compare-left txtcenter borderbott <?php echo $class; ?>">
        <img src="<?php echo $data['first'][0]->image; ?>" alt="<?php echo $data['first'][0]->brand; ?>" title="<?php echo $data['first'][0]->brand; ?>">
    </div>
    <?php if ($data['second'] != null): ?>
        <div class="compare-left vssection"><div class="vs_text"><img src="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_auto_search'); ?>/images/big-vs.jpg" alt="" title=""></div></div>
        <div class="compare-right txtcenter borderbott <?php echo $class; ?>">
            <img src="<?php echo $data['second'][0]->image; ?>" alt="<?php echo $data['second'][0]->brand; ?>" title="<?php echo $data['second'][0]->brand; ?>">
        </div>
    <?php endif; ?>
    <div class="compare-left <?php echo $class; ?>">
        <div class="lft ltext">
            <h3><?php echo $data['first'][0]->brand; ?></h3>
            <div class="rating_icon">
                <img src="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_auto_search'); ?>/images/rating.jpg" alt="" title="">
            </div>
        </div>

        <div class="flr rtext"></div>
    </div>
    <?php if ($data['second'] != null): ?>
        <div class="compare-left vssection"><div class="arrow_bottom"><img src="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_auto_search'); ?>/images/v-img.jpg" alt="" title=""></div></div>
        <div class="compare-right <?php echo $class; ?>">
            <div class="flr rtext">
                <h3><?php echo $data['second'][0]->brand; ?></h3>
                <div class="rating_icon">
                    <img src="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_auto_search'); ?>/images/rating.jpg" alt="" title="">
                </div>
            </div>
        </div>
    <?php endif; ?>
    <div class='col-md-12 grybg_background'>
        <div class="left-table tableCompareHead <?php echo $tableClass; ?>">
            <table>
                <tr><th><?php print t("Brand Name"); ?></th></tr>
                <tr><th><?php print t("Model"); ?></th></tr>
                <tr><th><?php print t("Delhi Price"); ?></th></tr>
                <tr><th><?php print t("Mumbai Price"); ?></th></tr>
                <tr><th><?php print t("Kolkata Price"); ?></th></tr>
                <tr><th><?php print t("Banglore price"); ?></th></tr>
                <tr><th><?php print t("Chennai Price"); ?></th></tr>
                <tr><th><?php print t("Body Type"); ?></th></tr>
                <tr><th><?php print t("Engine Displacement (in CC)"); ?></th></tr>
                <tr><th><?php print t("Cylinder"); ?></th></tr>
                <tr><th><?php print t("Power"); ?></th></tr>
                <tr><th><?php print t("Torque"); ?></th></tr>
                <tr><th><?php print t("Gears"); ?></th></tr>
                <tr><th><?php print t("Gear Type"); ?></th></tr>
                <tr><th><?php print t("Fuel Type"); ?></th></tr>
                <tr><th><?php print t("0-100kmph (Sec)"); ?></th></tr>
                <tr><th><?php print t("Top Speed"); ?></th></tr>
                <tr><th><?php print t("Fuel Efficiency (ARAI claimed)"); ?></th></tr>
                <tr><th><?php print t("Fuel Efficiency (Tested)"); ?></th></tr>
                <tr><th><?php print t("AC"); ?></th></tr>
                <tr><th><?php print t("Climate Control"); ?></th></tr>
                <tr><th><?php print t("Adjustable Steering Rake"); ?></th></tr>
                <tr><th><?php print t("Adjustable Steering Reach"); ?></th></tr>
                <tr><th><?php print t("Steering mounted controls"); ?></th></tr>
                <tr><th><?php print t("Cruise Control"); ?></th></tr>
                <tr><th><?php print t("Central Lock"); ?></th></tr>
                <tr><th><?php print t("Remote Lock"); ?></th></tr>
                <tr><th><?php print t("Keyless entry"); ?></th></tr>
                <tr><th><?php print t("Power Windows"); ?></th></tr>
                <tr><th><?php print t("Driver seat adjust"); ?></th></tr>
                <tr><th><?php print t("Parking sensor"); ?></th></tr>
                <tr><th><?php print t("Parking camera"); ?></th></tr>
                <tr><th><?php print t("Split folding rear seats"); ?></th></tr>
                <tr><th><?php print t("Multi-function trip computer"); ?></th></tr>
                <tr><th><?php print t("Door mirror"); ?></th></tr>
                <tr><th><?php print t("MP3 CD Player"); ?></th></tr>
                <tr><th><?php print t("USB port"); ?></th></tr>
                <tr><th><?php print t("Blue tooth"); ?></th></tr>
                <tr><th><?php print t("Fog lamps"); ?></th></tr>
                <tr><th><?php print t("Rear AC vents"); ?></th></tr>
                <tr><th><?php print t("Rear defogger"); ?></th></tr>
                <tr><th><?php print t("Wash wipe"); ?></th></tr>
                <tr><th><?php print t("Airbags"); ?></th></tr>
                <tr><th><?php print t("ESP"); ?></th></tr>
                <tr><th><?php print t("ABS"); ?></th></tr>
            </table>
        </div>
        <div class="left-table tableComparedata <?php echo $tableClass2; ?>">
            <table>
                <tr><td><?php echo $data['first'][0]->brand; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->vehicle; ?></td></tr>
                <tr><td><?php echo '<span>&#8377; ' . $data['first'][0]->delhi_price;
    echo'</span>' ?></td></tr>
                <tr><td><?php echo '<span>&#8377; ' . $data['first'][0]->mumbai_price;
    echo'</span>' ?></td></tr>
                <tr><td><?php echo '<span>&#8377; ' . $data['first'][0]->kolkata_price;
    echo'</span>' ?></td></tr>
                <tr><td><?php echo '<span>&#8377; ' . $data['first'][0]->bangalore_price;
    echo'</span>' ?></td></tr>
                <tr><td><?php echo '<span>&#8377; ' . $data['first'][0]->Chennai_price;
    echo'</span>' ?></td></tr>
                <tr><td><?php echo $data['first'][0]->bodytype; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->EngineDisplacement; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->cylinders; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->power; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->torque; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->gears; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->geartype; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->fueltype; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->runningkm; ?></td></tr>
                <tr><td><?php print $data['first'][0]->topspeed; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->ARAI_Claimed; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Tested; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->AC; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Climate_Control; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Adjustable_Steering_rake; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Adjustable_Steering_Reach; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Steering_mounted_controls; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Cruise_Control; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Centrallock; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Remotelock; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Keyless; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Power_windows; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Driver_seat_adjust; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Parking_sensor; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Parking_camera; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Split_foalding; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Multi_function; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Door_mirror; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->MP3_CD_Player; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->USB; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Bluetooth; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Foglamps; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Rear_AC_vents; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Rear_defogger; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Wash_wipe; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->Airbags; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->ESP; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->ABS; ?></td></tr>
            </table>
        </div>

<?php if ($data['second'] != null): ?>
            <div class="right-table tableComparedata <?php echo $tableClass2; ?>">
                <table>
                    <tr><td><?php echo $data['second'][0]->brand; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->vehicle; ?></td></tr>
                    <tr><td><?php echo '<span>&#8377; ' . $data['second'][0]->delhi_price;
    echo'</span>' ?></td></tr>
                    <tr><td><?php echo '<span>&#8377; ' . $data['second'][0]->mumbai_price;
    echo'</span>' ?></td></tr>
                    <tr><td><?php echo '<span>&#8377; ' . $data['second'][0]->kolkata_price;
    echo'</span>' ?></td></tr>
                    <tr><td><?php echo '<span>&#8377; ' . $data['second'][0]->bangalore_price;
    echo'</span>' ?></td></tr>
                    <tr><td><?php echo '<span>&#8377; ' . $data['second'][0]->Chennai_price;
    echo'</span>' ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->bodytype; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->EngineDisplacement; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->cylinders; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->power; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->torque; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->gears; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->geartype; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->fueltype; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->runningkm; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->topspeed; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->ARAI_Claimed; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Tested; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->AC; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Climate_Control; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Adjustable_Steering_rake; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Adjustable_Steering_Reach; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Steering_mounted_controls; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Cruise_Control; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Centrallock; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Remotelock; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Keyless; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Power_windows; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Driver_seat_adjust; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Parking_sensor; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Parking_camera; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Split_foalding; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Multi_function; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Door_mirror; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->MP3_CD_Player; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->USB; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Bluetooth; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Foglamps; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Rear_AC_vents; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Rear_defogger; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Wash_wipe; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->Airbags; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->ESP; ?></td></tr>
                    <tr><td><?php echo $data['second'][0]->ABS; ?></td></tr>
                </table>
            </div>
<?php endif; ?>
    </div>
</div>
