<div id="compare-section" class="auto-compare-section">
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
    <div class="compare-left <?php echo $class; ?>">
        <img src="<?php echo $data['first'][0]->image; ?>" alt="<?php echo $data['first'][0]->brand; ?>" title="<?php echo $data['first'][0]->brand; ?>">
    </div>
    <?php if ($data['second'] != null): ?>
    <div class="compare-left col-md-2"><div class="vs_text"><img src="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_auto_search');?>/images/big-vs.jpg" alt="" title=""></div></div>
      <div class="compare-right <?php echo $class; ?>">
          <img src="<?php echo $data['second'][0]->image; ?>" alt="<?php echo $data['second'][0]->brand; ?>" title="<?php echo $data['second'][0]->brand; ?>">
      </div>
    <?php endif; ?>
    <div class="compare-left <?php echo $class; ?>">
        <div class="lft ltext">
            <h3><?php echo $data['first'][0]->brand; ?></h3>
            <div class="rating_icon">
                <img src="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_auto_search');?>/images/rating.jpg" alt="" title="">
            </div>
        </div>

        <div class="flr rtext"></div>
    </div>
    <?php if ($data['second'] != null): ?>
      <div class="compare-left col-md-2"><div class="arrow_bottom"><img src="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_auto_search');?>/images/v-img.jpg" alt="" title=""></div></div>
      <div class="compare-right <?php echo $class; ?>">
          <h3><?php echo $data['second'][0]->brand; ?></h3>
          <div class="rating_icon">
              <img src="<?php echo $base_url . '/' . drupal_get_path('module', 'itg_auto_search');?>/images/rating.jpg" alt="" title="">
          </div>
      </div>
    <?php endif; ?>
    <div class='col-md-12 grybg_background'>
        <div class="left-table <?php echo $tableClass; ?>">
            <table>
                <tr><td>Brand Name</td></tr>
                <tr><td>Model</td></tr>
                <tr><td>Delhi Price</td></tr>
                <tr><td>Mumbai Price</td></tr>
                <tr><td>Kolkata Price</td></tr>
                <tr><td>Banglore price</td></tr>
                <tr><td>Chennai Price</td></tr>
                <tr><td>Body Type</td></tr>
                <tr><td>Engine Displacement (in CC)</td></tr>
                <tr><td>Cylinder</td></tr>
                <tr><td>Power</td></tr>
                <tr><td>Torque</td></tr>
                <tr><td>Gears</td></tr>
                <tr><td>Gear Type</td></tr>
                <tr><td>Fuel Type</td></tr>
                <tr><td>0-100kmph (Sec)</td></tr>
                <tr><td>Top Speed</td></tr>
                <tr><td>Fuel Efficiency (ARAI claimed)</td></tr>
                <tr><td>Fuel Efficiency (Tested)</td></tr>
                <tr><td>AC</td></tr>
                <tr><td>Climate Control</td></tr>
                <tr><td>Adjustable Steering Rake</td></tr>
                <tr><td>Adjustable Steering Reach</td></tr>
                <tr><td>Steering mounted controls</td></tr>
                <tr><td>Cruise Control</td></tr>
                <tr><td>Central Lock</td></tr>
                <tr><td>Remote Lock</td></tr>
                <tr><td>Keyless entry</td></tr>
                <tr><td>Power Windows</td></tr>
                <tr><td>Driver seat adjust</td></tr>
                <tr><td>Parking sensor</td></tr>
                <tr><td>Parking camera</td></tr>
                <tr><td>Split folding rear seats</td></tr>
                <tr><td>Multi-function trip computer</td></tr>
                <tr><td>Door mirror</td></tr>
                <tr><td>MP3 CD Player</td></tr>
                <tr><td>USB port</td></tr>
                <tr><td>Blue tooth</td></tr>
                <tr><td>Fog lamps</td></tr>
                <tr><td>Rear AC vents</td></tr>
                <tr><td>Rear defogger</td></tr>
                <tr><td>Wash wipe</td></tr>
                <tr><td>Airbags</td></tr>
                <tr><td>ESP</td></tr>
                <tr><td>ABS</td></tr>
            </table>
        </div>
        <div class="left-table <?php echo $tableClass2; ?>">
            <table>
                <tr><td><?php echo $data['first'][0]->brand; ?></td></tr>
                <tr><td><?php echo $data['first'][0]->vehicle; ?></td></tr>
                <tr><td><?php echo '<span>&#8377;</span> ' . $data['first'][0]->delhi_price; ?></td></tr>
                <tr><td><?php echo '<span>&#8377;</span> ' . $data['first'][0]->mumbai_price; ?></td></tr>
                <tr><td><?php echo '<span>&#8377;</span> ' . $data['first'][0]->kolkata_price; ?></td></tr>
                <tr><td><?php echo '<span>&#8377;</span> ' . $data['first'][0]->bangalore_price; ?></td></tr>
                <tr><td><?php echo '<span>&#8377;</span> ' . $data['first'][0]->Chennai_price; ?></td></tr>
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
          <div class="right-table <?php echo $tableClass2; ?>">
              <table>
                  <tr><td><?php echo $data['second'][0]->brand; ?></td></tr>
                  <tr><td><?php echo $data['second'][0]->vehicle; ?></td></tr>
                  <tr><td><?php echo '<span>&#8377;</span> ' . $data['second'][0]->delhi_price; ?></td></tr>
                  <tr><td><?php echo '<span>&#8377;</span> ' . $data['second'][0]->mumbai_price; ?></td></tr>
                  <tr><td><?php echo '<span>&#8377;</span> ' . $data['second'][0]->kolkata_price; ?></td></tr>
                  <tr><td><?php echo '<span>&#8377;</span> ' . $data['second'][0]->bangalore_price; ?></td></tr>
                  <tr><td><?php echo '<span>&#8377;</span> ' . $data['second'][0]->Chennai_price; ?></td></tr>
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
