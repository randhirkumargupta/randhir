
<?php if (!empty($data)) : global $base_url; ?>
  <ul class="itg-listing">
    <?php
    foreach ($data as $entity) {
      if (!empty($entity['nid'])) :
        ?>
        <li class="<?php print $entity['type'] ?> top-story-<?php print $entity['nid'] ?>">
          <?php
          if (function_exists('itg_common_get_smiley_title')) {
            echo l(itg_common_get_smiley_title($entity['nid'], 0, 110), "node/" . $entity['nid'], array("html" => TRUE , 'attributes' => array("title" => $entity['title'])));
          }
          else {
            echo l(mb_strimwidth($entity['title'], 0, 110, ".."), "node/" . $entity['nid'] , array('attributes' => array("title" => $entity['title']))); 
          }
          ?>
        </li>
      <?php endif; ?>
    <?php } ?>
  </ul>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>