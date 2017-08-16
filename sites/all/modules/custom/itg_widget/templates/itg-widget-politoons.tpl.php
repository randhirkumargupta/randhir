<div class="politoons-sosorry">
  <div class="row">
    <div class="col-md-12">
      <?php
      global $base_url;
      print t("<h2>CHOOSE <br/> YOUR FAVOURITE <span>POLITOONS</span></h2>");
      ?>
    </div>
  </div>
  <div class="row">
    <?php foreach ($data as $key => $taxonomy) :
      ?>
      <div class="col-md-4 col-sm-4 col-xs-4 politoons-<?php echo $key; ?>">
        <?php
        $title = $taxonomy['title'];
        $tid = $taxonomy['term_id'];
        $uri = $taxonomy['uri'];
        ?>
        <?php
        if (!empty($uri)) {
          $url = image_style_url("politoons", $uri);
          $image = "<img src='" . $url . "' alt='' />";
        } else {
          $url = $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image88x66.jpg";
          $image = "<img src='" . $url . "' width='88' height='88' alt='' />";
        }
        ?>

        <?php print l($image, "taxonomy/term/$tid", array("html" => TRUE , 'attributes' => array("title" => $title))); ?>

        <span class="title"><?php print l($title, "taxonomy/term/$tid" , array("attributes" => array("title" => $title))); ?></span>

      </div>

    <?php endforeach; ?>
  </div>
</div>