
<?php
global $base_url;
print t("CHOOSE YOUR FAVOURITE <span>POLITOONS</span>");
foreach ($data as $key => $taxonomy) :
  ?>
  <div class="politoons-<?php echo $key; ?>">
    <?php
    $title = $taxonomy['title'];
    $tid = $taxonomy['term_id'];
    $uri = $taxonomy['uri'];
    ?>
    <?php
    if (!empty($uri)) {
      $url = image_style_url("politoons", $uri);
      $image = "<img src='" . $url . "'>";
    }
    else {
      $url = $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_for_all.png";
      $image = "<img src='" . $url . "' width='88' height='88'>";
    }
    ?>
    
    <?php print l($image, "taxonomy/term/$tid" , array("html"=>TRUE)); ?>
    
    <span class="title"><?php print l($title, "taxonomy/term/$tid"); ?></span>
  
  </div>

<?php endforeach; ?>
