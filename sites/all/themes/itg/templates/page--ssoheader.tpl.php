<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
<div class="sso-header">
    <div class="container">
        <div class="sso-head-left"><a href="<?php print FRONT_URL; ?>">Back to india the today</a></div>
        <div class="sso-head-right">
            <ul>
                <li><img src="<?php print base_path() ?>sites/all/themes/itg/images/span_itg_group.jpg" alt="" /></li>
            </ul>        
        </div>
    </div>
</div>

<div id="page">

  

  <main id="main">
    
    <section id="content" class="container" role="main">
      <?php print $messages; ?>
      <?php print render($page['content']); ?>
      
    </section>

    
 </main>
    
</div>

<div class="sso-footer">
    <div class="footer-container">
        <div class="cell">
            <?php print theme('links', array('links' => menu_navigation_links('menu-sso-footer-menu'), 'attributes' => array('class'=> array('links', 'site-menu')) ));?>
        </div>
        <div class="copy-right-footer">
         <p><?php print t('Copyright &copy;');?> <?php echo date("Y") ?> <?php print t('Living Media India Limited. For reprint rights: Syndications Today'); ?></p>
        </div>
    </div>
</div>

    
