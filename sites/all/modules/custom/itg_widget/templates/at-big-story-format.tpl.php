<?php
if (!empty($data)) : global $base_url;
  $db_node = $data['node_data'];
  ?>
<div class="big-story-wrapper">
  <div class="extra-large-image">
    <?php if (!empty($db_node->field_story_extra_large_image['und'][0]['uri'])) { ?>
      <a href='<?php echo $base_url . '/' . drupal_get_path_alias("node/{$db_node->nid}") ?>'>
        <img src="<?php print image_style_url("at_big_story", $db_node->field_story_extra_large_image['und'][0]['uri']); ?>" />
      </a>  
      <?php
      // prepare configuration for sharing
      $image = file_create_url($data['node_data']->field_story_extra_large_image['und'][0]['uri']);
    }
    else {
      $default_image = array(
        '#theme' => 'image_style_outside_files',
        '#style_name' => 'at_big_story',
        '#path' => drupal_get_path('theme', 'itg') . "/images/default_for_all.png",
      );
      print l(render($default_image), "node/$db_node->nid", array("html" => true));
    }
    ?>
  </div>
  <div class="big-story-text">
    <div class="big-story-title">
      <?php print l($db_node->title, "node/$db_node->nid"); ?>
    </div>
    <div class="reported-by">
      <span class="name">
        <?php
        $user_data = user_load($db_node->uid);
        print l($user_data->name, "user/$user_data->uid");
        unset($user_data);
        ?>
      </span>
      <span class="date">
        <?php
        print date("h:s", $db_node->changed). " " .t("IST");
        ?>
      </span>
    </div>
  </div>
</div>
<?php 
$default_image_src = base_path() . "/" . drupal_get_path('theme', 'aajtak') . "/images/default_for_all.png";
$default_image = "<img src='" . $default_image_src . "' alt='Images'>";
?>
<div class="big-story-related-content">
  <div class="big-story-related-content-list">
    <div class="tile">
      <div class="pic">
        <?php echo $default_image; ?>
      </div>
      <div class="details">
        <div class="category-name">सिनेमा</div>
        <div class="title">'मोदी इफेक्ट' अब 'मोदी डिफेक्ट' हो गया है</div>
        <div class="reported-by">
          <span class="name">मोिहत कुमार</span>
          <span class="date">20:00 IST</span>
        </div>
      </div>
    </div>
  </div>
  <div class="big-story-related-content-list">
    <div class="tile">
      <div class="pic">
        <?php echo $default_image; ?>
      </div>
      <div class="details">
        <div class="category-name">सिनेमा</div>
        <div class="title">'मोदी इफेक्ट' अब 'मोदी डिफेक्ट' हो गया है</div>
        <div class="reported-by">
          <span class="name">मोिहत कुमार</span>
          <span class="date">20:00 IST</span>
        </div>
      </div>
    </div>
  </div>
  <div class="big-story-related-content-list">
    <div class="tile">
      <div class="pic">
        <?php echo $default_image; ?>
      </div>
      <div class="details">
        <div class="category-name">सिनेमा</div>
        <div class="title">'मोदी इफेक्ट' अब 'मोदी डिफेक्ट' हो गया है</div>
        <div class="reported-by">
          <span class="name">मोिहत कुमार</span>
          <span class="date">20:00 IST</span>
        </div>
      </div>
    </div>
  </div>
  <div class="big-story-related-content-list">
    <div class="tile">
      <div class="pic">
        <?php echo $default_image; ?>
      </div>
      <div class="details">
        <div class="category-name">सिनेमा</div>
        <div class="title">'मोदी इफेक्ट' अब 'मोदी डिफेक्ट' हो गया है</div>
        <div class="reported-by">
          <span class="name">मोिहत कुमार</span>
          <span class="date">20:00 IST</span>
        </div>
      </div>
    </div>
  </div>
  <div class="big-story-related-content-list">
    <div class="tile">
      <div class="pic">
        <?php echo $default_image; ?>
      </div>
      <div class="details">
        <div class="category-name">सिनेमा</div>
        <div class="title">'मोदी इफेक्ट' अब 'मोदी डिफेक्ट' हो गया है</div>
        <div class="reported-by">
          <span class="name">मोिहत कुमार</span>
          <span class="date">20:00 IST</span>
        </div>
      </div>
    </div>
  </div>
  <div class="big-story-related-content-list">
    <div class="tile">
      <div class="pic">
        <?php echo $default_image; ?>
      </div>
      <div class="details">
        <div class="category-name">सिनेमा</div>
        <div class="title">'मोदी इफेक्ट' अब 'मोदी डिफेक्ट' हो गया है</div>
        <div class="reported-by">
          <span class="name">मोिहत कुमार</span>
          <span class="date">20:00 IST</span>
        </div>
      </div>
    </div>
  </div>
</div>
<?php endif; ?>