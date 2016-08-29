<?php
foreach($data['itg_main_manu_header'] as $key => $val) {  
  if ($val['#localized_options']['attributes']['title'] == 1) {
    $data['itg_main_manu_header'][$key]['#attributes']['class'][] = 'sponser-link';
  }
}
?>
<div class="header-ads mhide">
    <img src="<?php print base_path() ?>sites/all/themes/itg/images/header-ads.png" alt="ads">
</div>                               
<div class="container top-nav">                  
    <div class="social-nav mhide">
        <ul class="social-nav mhide">
            <li><a href="#" title=""><i class="fa fa-facebook"></i></a></li>
            <li><a href="#" title=""><i class="fa fa-twitter"></i></a></li>
            <li><a href="#" title=""><i class="fa fa-google-plus"></i></a></li>
            <li><a href="#" title=""><i class="fa fa-rss"></i></a></li>
            <li><a href="#" title=""><i class="fa fa-mobile"></i></a></li>
            <li><a href="#" title=""><i class="fa fa-volume-up"></i></a></li>
            <li><a href="javascript:void(0)" class="search-icon" title=""><i class="fa fa-search"></i></a></li>                            
        </ul>
        <div class="globle-search">
            <input class="search-text" placeholder="Type here" type="text" value=""></div>
        </div>
    <div class="main-nav">
        <?php print drupal_render($data['itg_top_manu_header']); ?>
    </div>
</div>
<nav class="navigation">
    <div class="container">
        <?php print drupal_render($data['itg_main_manu_header']); ?>
    </div>   
</nav>
