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
                <li><a href="#" title=""><i class="fa fa-search"></i></a></li>
            </ul>
        </div>
        <div class="footer-expand-icon"></div>
    </div>
</section>
<section class="footer-toggle">
 <section class="footer-mid mhide">
        <div class="container">
         <img src="<?php print base_path() ?>sites/all/themes/itg/images/header-ads.png" alt="ads">
        </div>
 </section>
   <section class="footer-bottom">
       <div class="container">
           <div class="row">
               <div class="cell first-cell">
                   <h4>Publications:</h4>
                   <?php print drupal_render($data['footer-publications-menu']); ?>
               </div>
               <div class="cell">
                   <h4>Television:</h4>
                   <?php print drupal_render($data['footer-television-menu']); ?>
               </div>
           </div>
       </div>
    </section>
    <section class="footer-copyright">
        <div class="container"><p>Copyright &copy; <?php echo date("Y") ?> Living Media India Limited. For reprint rights: Syndications Today</p></div>
    </section>
</section>