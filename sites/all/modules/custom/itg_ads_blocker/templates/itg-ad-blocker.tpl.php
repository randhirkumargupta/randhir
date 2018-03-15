<?php
/**
 * Manage Ad blocker page 
 */
?>

<div class='adblocker-box adblocker-page'>
  <h3><?php print t('YOUR AD BL'); ?><span class='otext'></span><?php print t('CKER IS ON'); ?></h3>
  <p><?php print t('Hi'); ?>,<br>
    <br>
    <?php print t("Don't like ads? Neither do we, but they help us bring all this content to you, absolutely free. Please whitelist us to continue reading and watching news from India's most trusted news source."); ?></p>
  <div class='clearsection'>
    <div class='tab_area'>
      <div class='tabs'>
        <ul>
          <li id='chrome'><span class='chrome'><?php print t('CHROME'); ?></span></li>
          <li id='firefox'><span class='firefox'><?php print t('FIREFOX'); ?></span></li>
          <li id='ie'><span class='ie'><?php print t('INTERNET EXPLORER'); ?></span></li>
        </ul>
      </div>
      <div class='show_instruction' id='tab11'>
        <h2><img src='http://media2.intoday.in/indiatoday/1.0.4/resources/css/images/abp.jpg' alt="" title=""/> - Using AdBlocks Plus</h2>
        <ul>
          <li><b><?php print t('STEP 1');?> -</b><?php print t('Click on the AdBlock Plus icon on the top right of your browser'); ?></li>
          <li><b><?php print t('STEP 2'); ?> -</b><?php print t(' A drop-down menu will appear with a check mark followed by'); ?><strong><?php print t('Enabled on this site'); ?></strong></li>
          <li><b><?php print t('STEP 3'); ?> -</b><?php print t('Click the button to until the text reads');?> <strong><?php print t('Disabled on this site'); ?></strong></li>
          <li><b><?php print t('STEP 4'); ?> -</b><?php print t(' Refresh the page or go to home Page, to access indiatoday.in'); ?> </li>
        </ul>
        <br/>
        <br/>
        <h2><img src='http://media2.intoday.in/indiatoday/1.0.4/resources/css/images/chrome_icon.jpg' alt="" title=""/> - <?php print t('Using Chrome adblock extension'); ?> </h2>
        <ul>
          <li><b><?php print t('STEP 1');?> -</b><?php print t('Click on the hand icon for adblock extension, on the top right corner of your browser'); ?></li>
          <li><b><?php print t('STEP 2');?> -</b> <?php print t('A drop-down menu will appear'); ?></li>
          <li><b><?php print t('STEP 3');?> -</b> <?php print t('Click the');?> <strong><?php print t("Don't run on pages on this domain");?></strong><?php print('option on the drop down');?> </li>
          <li><b><?php print t('STEP 4');?> -</b> <?php print t('Once clicked a settings popup will appear');?></li>
          <li><b><?php print t('STEP 5');?> -</b> <?php print t('Click Exclude');?> </li>
          <li><b><?php print t('STEP 6');?> -</b> <?php print t('Refresh the page or go to home Page, to access indiatoday.in');?></li>
        </ul>
      </div>
      <div class='show_instruction' id='tab12'>
        <ul>
          <li><b><?php print t('STEP 1');?> -</b> <?php print t('Click on the AdBlock Plus icon on the top right of your browser');?></li>
          <li><b><?php print t('STEP 2');?> -</b> <?php print t('A drop-down menu will appear');?></li>
          <li><b><?php print t('STEP 3');?> -</b> <?php print t('Click the');?> <strong><?php print t('Disabled on indiatoday.in');?></strong> <?php print t('option on the drop down');?></li>
          <li><b><?php print t('STEP 4');?> -</b> <?php print t('Refresh the page or Go to Home Page, to access indiatoday.in');?></li>
        </ul>
        <p><?php print t("Firefox 'Private Window' runs its own version of adblock. You will receive an adblock detection screen on private window, even if you are not running any adblock plugins. In this case, you will need to open indiatoday.in on your standard Firefox window.");?></p>
      </div>
      <div class='show_instruction' id='tab13'>
        <ul>
          <li><b><?php print t('STEP 1');?> -</b> <?php print t('Click on the AdBlock Plus icon on the bottom right hand side of your browser'); ?></li>
          <li><b><?php print t('STEP 2');?> -</b> <?php print t('A drop-down menu will appear');?> </li>
          <li><b><?php print t('STEP 3');?> -</b> <?php print t('Click the Disable on indiatoday.in option on the drop down');?></li>
          <li><b><?php print t('STEP 4');?> -</b> <?php print t('Refresh the page or go to home Page, to access indiatoday.in');?></li>
        </ul>
      </div>
    </div>
  </div>
</div>