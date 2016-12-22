<?php
global $base_url;
?>
<section class="footer-top">
    <div class="container">
        <div class="footer-top-link">
            <?php print drupal_render($data['footer-top-menu']); ?>
        </div>
        
        <div class="footer-social-link mhide">
            <ul>
                <li><a href="#" title=""><i class="fa fa-facebook"></i></a></li>
                <li><a href="#" title=""><i class="fa fa-twitter"></i></a></li>
                <li><a href="#" title=""><i class="fa fa-google-plus"></i></a></li>
                <li><a href="#" title=""><i class="fa fa-rss"></i></a></li>                
                <li><a href="javascript:void(0)" class="search-icon" title=""><i class="fa fa-search"></i></a></li>
            </ul>
            <div class="globle-search">
                <input class="search-text" placeholder="Type here" type="text" value="">
            </div>
        </div>
        <div class="footer-expand-icon"></div>
    </div>
</section>
<section class="footer-toggle">
 <section class="footer-mid mhide">
        <div class="container">
<!--         <img src="<?php print base_path() ?>sites/all/themes/itg/images/header-ads.png" alt="ads">-->
        <?php  print $data['itg_top']['150*150_footer']; ?>
        </div>
 </section>
   <section class="footer-bottom">
       <div class="container">
           <div class="row">
               <div class="cell">
                   <h4>Publications:</h4>
                   <?php print drupal_render($data['publications_footer']); ?>
               </div>
               <div class="cell">
                   <h4>Television:</h4>
                   <?php print drupal_render($data['television_footer']); ?>
                   <h4>Radio:</h4>
                   <?php print drupal_render($data['radio_footer']); ?>
               </div>
               <div class="cell">
                   <h4>Education:</h4>
                   <?php print drupal_render($data['education_footer']); ?>
                   <h4>Online Shopping:</h4>
                   <?php print drupal_render($data['shopping_footer']); ?>
               </div>
               <div class="cell">
                   <h4>Events:</h4>
                   <?php print drupal_render($data['events_footer']); ?>
               </div>
               <div class="cell">
                   <h4>Printing:</h4>
                   <?php print drupal_render($data['printing_footer']); ?>
                   <h4>Welfare</h4>
                   <?php print drupal_render($data['welfare_footer']); ?>
                   <h4>Music:</h4>
                   <?php print drupal_render($data['music_footer']); ?>
               </div>              
                <div class="cell">
                   <h4>Syndications:</h4>
                   <?php print drupal_render($data['syndication_footer']); ?>
                   <h4>Distribution:</h4>
                   <?php print drupal_render($data['distribution_footer']); ?>
                   <h4>Useful Links :</h4>
                   <?php print drupal_render($data['useful_footer']); ?>
               </div>
           </div>
       </div>
    </section>
    <section class="footer-copyright">
        <div class="container"><p>Copyright &copy; <?php echo date("Y") ?> Living Media India Limited. For reprint rights: Syndications Today</p></div>
    </section>
</section>
<div id="widget-ajex-loader" style="display: none">
    <img class="widget-loader" align="center" src="<?php echo $base_url . '/' . drupal_get_path('theme', 'itgadmin') . '/images/loader.svg'; ?>" alt="Loading..." />
</div>
<div id="iframe-display" style="display: none"></div>