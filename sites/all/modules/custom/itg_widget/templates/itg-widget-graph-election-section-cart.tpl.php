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
 
  foreach ($data as $index => $row):
    ?>
    <div class="<?php echo $classrow; ?> mt-50">
      <div class="itg-widget">
        <div class="<?php print $gray_bg_layout; ?>">
          <div class="widget-wrapper ">
            
              <div class="data-holder"> 
                <div class="graph-design">
                  <div id="container_<?php echo $index; ?>"></div>
                  <div class="divider"></div>                                
                </div>

  
              </div>
          
          </div>             
        </div>
      </div>
    </div>




  <?php endforeach; ?>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>
