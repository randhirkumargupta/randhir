<?php
/**
 * @file
 * Theme implementation for breaking news form in tab display.
 * 
 */
?>
<div class="Crowdie News">
    <div style="width: 100%; height: 300px;" data-crowdynews-widget="AajTak/aajtak-mobile">
        <script src="//widget.crowdynews.com/js/widget.js" async="true"></script>
    </div>
</div>
<div class="api-grid">
<div class="Bse-market">
    <iframe src="http://businesstoday.acemf.co.in/Market/VolumeToppers.aspx?Exchg=NSE" frameborder="0"  height="1000" width="380" scrolling="auto"></iframe>
</div>
<div class="market">
    <iframe src="http://businesstoday.acemf.co.in/Market/MarketToday.aspx" frameborder="0"  height="1000" width="380" scrolling="auto"></iframe>
</div>

<div class="SensexNiftyFeed">
    <?php
    // get base path of server 
    $base_path_set = $_SERVER['SERVER_NAME'] . $_SERVER['REQUEST_URI'];
    $base_path_set = explode('/', $base_path_set);
    $path_instance = $base_path_set[1];
    $direc = $_SERVER['DOCUMENT_ROOT'].'/'.$path_instance. '/sites/default/files/gallery/nifty/';
    $newFileName = $direc . 'SensexNiftyFeed.txt';
    $html = implode('', file($newFileName));
    $pieces = explode("@", $html);


    foreach ($pieces as $pieces_value) {
      if (!empty($pieces_value)) {
        print "<table>";
        $pieces1 = explode(",", $pieces_value);
        $i = 1;
        foreach ($pieces1 as $pieces_value1) {
          if ($i == 3) {
            if($i == 3) {
              $numeric_val = substr($pieces_value1, strpos($pieces_value1, ":") + 1);
             if($numeric_val > 0) {
               $cls="positive-number";
            }
             
            else
            {
              $cls="negative-number";
            }
            }
            print "<tr><td><div class='$cls'>$pieces_value1</div></td></tr>";
          }
          else {
            print "<tr><td>$pieces_value1</td></tr>";
          }
          $i++;
        }
        print "</table>";
      }
    }
    ?>
</div>
</div>
<style>
  .api-grid > div{display: inline-block; vertical-align: top;}
</style>

