<div class="header-ads mhide">
    <img src="<?php print base_path() ?>sites/all/themes/itg/images/header-ads.png" alt="ads">
</div>                               
<div class="container top-nav">                  
    <div class="social-nav mhide">
        <?php print drupal_render($data['header_social_menu']); ?>
    </div>
    <div class="main-nav">
        <?php print drupal_render($data['header_top_menu']); ?>
    </div>
</div>
<nav class="navigation">
    <div class="container">
        <?php print drupal_render($data['header_main_menu']); ?>
    </div>   
</nav>
