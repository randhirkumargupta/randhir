
<?php if (!empty($data)) : global $base_url; ?>
<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
	$data_tb_region_item = 'data-tb-region-item';  
  }
  $home_top_story_sponsor = json_decode(get_itg_variable('home_top_story_sponsor'));
  $_position = array();
  foreach ($home_top_story_sponsor as $key => $row) {
    $_position[$key] = $row->position;
  }
  array_multisort($_position, SORT_ASC, $home_top_story_sponsor);
?>
  <ul class="itg-listing">
      <?php
      $counter = 1;
      $enable_top_story_ad = get_itg_variable('enable_top_story_ad');
      $top_story_ad_pos = get_itg_variable('top_story_ad_position');
      $top_story_ad_html = get_itg_variable('top_story_ad_html');
      foreach ($data as $entity) {
        if (!empty($entity['nid'])) :
          // code for add on story title and url
          if (function_exists('itg_common_get_addontitle')) {
            $add_on_data = itg_common_get_addontitle($entity['node_obj']);
            $pipelinetext = "";
            $pipelineclass = "";
            if (!empty($add_on_data['ad_title']) && !empty($add_on_data['ad_url'])) {
              $pipelinetext = ' <span class="add-on-story-pipline">|</span> <a target="_blank" href="' . $add_on_data['ad_url'] . '" title="' . $add_on_data['ad_title'] . '">' . ucfirst($add_on_data['ad_title']) . '</a>';
              $pipelineclass = ' pipeline-added';
            }
          }
          if(count($home_top_story_sponsor) > 0 && drupal_is_front_page()){
            foreach($home_top_story_sponsor as $_sponsor_home_value){
              if($_sponsor_home_value->position == $counter){
                $_node_nid = $_sponsor_home_value->nid;
                $_node_d = itg_common_get_node_title($_node_nid);
                if (count($_node_d) <= 0 || empty($_node_d[0]->status) || empty($_node_d[0]->title)) {
                  continue;
                }
                $_node_title = $_node_d[0]->title;
            ?>
              <li <?php echo $data_tb_region_item;?> title="<?php echo _widget_title($_node_title); ?>" class="story top-story-<?php print $_node_nid ?>">
                  <span class="itg-sponsor-title"><?php print t('IMPACT FEATURE'); ?></span>
                  <?php
                  echo l(mb_strimwidth($_node_title, 0, 110, ".."), "node/" . $_node_nid, array('attributes' => array("title" => $_node_title)));
                  ?>
              </li>
              <?php 
              $counter++;
              } } }
				  if (!empty($enable_top_story_ad) && $counter == $top_story_ad_pos){
						echo "<li class='itg-top-story-ad desktop-hide'>". $top_story_ad_html ."</li>";
					}
					$counter++;
          ?>
          <li <?php echo $data_tb_region_item;?> title="<?php echo _widget_title($entity['title']); ?>" class="<?php print $entity['type'] ?> top-story-<?php print $entity['nid'] ?>  <?php print $pipelineclass; ?>">
              <?php if ($entity['is_spnoser']): ?>
                <span class="itg-sponsor-title"><?php print t('IMPACT FEATURE'); ?></span>
                <?php
              endif;
              if (function_exists('itg_common_get_smiley_title')) {
                echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 110), "node/" . $entity['nid'], array("html" => TRUE, 'attributes' => array("title" => _widget_title($entity['title']))));
                echo $pipelinetext;
              } else {
                echo l(mb_strimwidth($entity['title'], 0, 110, ".."), "node/" . $entity['nid'], array('attributes' => array("title" => $entity['title'])));
                echo $pipelinetext;
              }
              ?>
          </li>
            <?php endif; ?>
          <?php } ?>
  </ul>
    <?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
