<?php
$i = 0;
global $base_url;
foreach ($data as $tid => $info) :
  ?>
  <div class="widget-personlization-<?php print $i ?>">
    <h3><?php print $info['taxonomy_term_load']->name ?></h3>
    <?php
    foreach ($info['data'] as $key => $nodes) {
      $node_info = $nodes[0];
      ?>
      <li>
        <div>

          <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_info['nid']}"); ?>">
            <?php
            if (isset($node_info['uri'])) {
              print theme('image_style', array(
                  'style_name' => 'video_landing_page_170_x_127',
                  'path' => $node_info['uri'],
                              )
              );
            }
            else {
              ?>
              <img src="<?php print base_path() . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
            <?php } ?>
          </a>
        </div>
        <div>
          <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$node_info['nid']}"); ?>">
            <?php print $node_info['title']; ?>
          </a>
        </div>
      </li>
    <?php } ?>
  </div>
  <?php
endforeach;
