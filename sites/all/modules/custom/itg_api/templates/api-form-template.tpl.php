<?php
/**
 * @file
 * Theme implementation for breaking news form in tab display.
 * 
 */

?>
<div class="Crowdie News">
    <h1>Crowdie News</h1>
   <div style="width: 100%; height: 300px;" data-crowdynews-widget="AajTak/aajtak-mobile">
       <script src="//widget.crowdynews.com/js/widget.js" async="true"></script>
   </div>
</div>
<div class="Bse-market">
    <h1>Bse Market</h1>
   <iframe src="http://businesstoday.acemf.co.in/Market/VolumeToppers.aspx?Exchg=NSE" frameborder="0"  height="1000" width="380" scrolling="auto"></iframe>
</div>
<div class="market">
    <h1>Market</h1>
   <iframe src="http://businesstoday.acemf.co.in/Market/MarketToday.aspx" frameborder="0"  height="1000" width="380" scrolling="auto"></iframe>
</div>
<div class="Top-indices">
    <h1>TopIndices</h1>
   <iframe src="http://businesstoday.acemf.co.in/Market/MarketToday.aspx" frameborder="0"  height="1000" width="380" scrolling="auto"></iframe>
</div>

    <div class="SensexNiftyFeed">
        <h1>SensexNiftyFeed</h1>
        <?php
  $direc = $_SERVER['DOCUMENT_ROOT'].'itgcms/sites/default/files/gallery/nifty/';
  $newFileName = $direc.'SensexNiftyFeed.txt';
  $html = implode('', file($newFileName));
  $pieces = explode("@", $html);
  
  
  foreach($pieces as $pieces_value) {
    if(!empty($pieces_value)) {
     print '<table>';
   $pieces1 = explode(",", $pieces_value);
   $i = 1;
   foreach($pieces1 as $pieces_value1) {
     if($i == 3) {
     print '<tr><td><div class="negative-number">'.$pieces_value1.'</div></td></tr>';
     }
     else
     {
      print '<tr><td>'.$pieces_value1.'</td></tr>'; 
     }
   $i++;
   }
    print '</table>';
  }
  }
  
  ?>
</div>

