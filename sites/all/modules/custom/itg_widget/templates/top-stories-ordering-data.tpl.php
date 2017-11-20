<?php if (!empty($data)) : global $base_url; ?>
<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
	$data_tb_region_item = 'data-tb-region-item';  
  }
?>
  <ul class="itg-listing">
      <?php
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
          ?>
          <li <?php echo $data_tb_region_item;?> title="<?php echo $entity['title']; ?>" class="<?php print $entity['type'] ?> top-story-<?php print $entity['nid'] ?>  <?php print $pipelineclass; ?>">
              <?php if (_is_sponsor_story_article($entity['nid'])): ?>
                <span class="itg-sponsor-title"><?php print t('SPONSORED'); ?></span>
                <?php
              endif;
              if (function_exists('itg_common_get_smiley_title')) {
                
                echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 110), "node/" . $entity['nid'], array("html" => TRUE, 'attributes' => array("title" => $entity['title'])));
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
