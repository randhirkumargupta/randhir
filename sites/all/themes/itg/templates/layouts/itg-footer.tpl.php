<?php
global $base_url;
?>
<section class="footer-top">
    <div class="container">
        <div class="footer-top-link">
            <?php print t('INDIATODAY.IN'); ?>
        </div>
        
        <div class="footer-social-link">
            <ul>
                <li><a rel="nofollow" href="https://www.facebook.com/IndiaToday/" title=""><i class="fa fa-facebook"></i></a></li>
                <li><a rel="nofollow" href="https://twitter.com/indiatoday" title=""><i class="fa fa-twitter"></i></a></li>
                <li><a rel="nofollow" href="https://plus.google.com/+indiatoday" title=""><i class="fa fa-google-plus"></i></a></li>
                <li><a href="<?php echo $base_url .'/rss' ?>" title=""><i class="fa fa-rss"></i></a></li>                
                <li class="search-icon-parent">
                  <a href="javascript:void(0)" class="search-icon-default" title=""><i class="fa fa-search"></i></a>
                  <a href="javascript:void(0)" class="search-icon-search" title=""><i class="fa fa-search"></i></a>
                  <div class="globle-search">
                    <input class="search-text" placeholder="Type here" type="text" value="" />
                  </div>
                </li>
                <li class="footer-expand-icon"></li>
            </ul>
        </div>
        <div class="footer-expand-icon"></div>
    </div>
</section>
<section class="footer-toggle">
 <section class="footer-mid">
        <div class="container">

        <?php
          $block = block_load('itg_ads', ADS_FOOTER);   
          $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
          print render($render_array);
         ?>
        </div>
 </section>
   <section class="footer-bottom">
       <div class="container">
           <div class="row multiple-items-footer">
               <div class="cell">
                   <h4><?php print t('Publications:'); ?></h4>
                   <?php print drupal_render($data['publications_footer']); ?>
               </div>
               <div class="cell">
                   <h4><?php print t('Television:'); ?></h4>
                   <?php print drupal_render($data['television_footer']); ?>
                   <h4><?php print t('Radio:') ;?></h4>
                   <?php print drupal_render($data['radio_footer']); ?>
               </div>
               <div class="cell">
                   <h4><?php print t('Education:') ;?></h4>
                   <?php print drupal_render($data['education_footer']); ?>
                   <!--<h4>Online Shopping:</h4>
                   <?php //print drupal_render($data['shopping_footer']); ?>-->
               </div>
               <div class="cell">
                   <h4><?php print t('Events:') ;?></h4>
                   <?php print drupal_render($data['events_footer']); ?>
               </div>
               <div class="cell">
                   <h4><?php print t('Printing:') ;?></h4>
                   <?php print drupal_render($data['printing_footer']); ?>
                   <h4><?php print t('Welfare'); ?></h4>
                   <?php print drupal_render($data['welfare_footer']); ?>
                   <h4><?php print t('Music:'); ?></h4>
                   <?php print drupal_render($data['music_footer']); ?>
               </div>              
                <div class="cell">
                   <h4><?php print t('Syndications:'); ?></h4>
                   <?php print drupal_render($data['syndication_footer']); ?>
                   <h4><?php print t('Distribution:'); ?></h4>
                   <?php print drupal_render($data['distribution_footer']); ?>
                   <h4><?php print t('Useful Links :'); ?></h4>
                   <?php print drupal_render($data['useful_footer']); ?>
               </div>
           </div>
       </div>
    </section>
    <section class="footer-copyright">
        <div class="container"><p><?php print t('Copyright &copy;');?> <?php echo date("Y") ?> <?php print t('Living Media India Limited. For reprint rights: Syndications Today'); ?></p></div>
    </section>
</section>
<div id="widget-ajex-loader" style="display: none">
	<?php if(drupal_is_front_page() && get_itg_variable('enable_custom_lazyload')) : ?>
    <img class="widget-loader lazyload" data-src="<?php echo file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/loading.gif'); ?>" src="<?php echo file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/loading.gif'); ?>" alt="Loading..." />
  <?php else : ?>
    <img class="widget-loader" src="<?php echo file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/loading.gif'); ?>" alt="Loading..." />
  <?php endif; ?>
</div>
<div id="iframe-display" style="display: none"></div>

<?php
if(!empty($sso_msg)) {
  print '<div class = "activate-message">
         <div class = "message-body">
         <p>' . $sso_msg . '</p>
         <a href = "javascript:void(0)" class = "close-pass-popup">ok</a>
         </div></div>';
}
?>        


