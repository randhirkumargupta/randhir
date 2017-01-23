<div style="display: none">
  <?php if (!empty($content)): ?>
    <div class='<?php print $classes ?>'>
      <?php if ($view_mode == 'full'): ?>
        <a href="javascript:;" class="close-preview">&nbsp;</a>


        <div class="basic-details content-box">
          <h2><?php print t('Basic Details'); ?></h2>
          <div class="content-details">
            <div class="field">
              <div class="field-label"><?php print t('Audio Title:'); ?></div>
              <div class="field-items"><?php print $title; ?></div>
            </div>
            <?php print render($content['field_story_short_headline']); ?>
            <?php print render($content['field_podcast_kicker_message']); ?>
          </div>
        </div>

        <?php if (!isset($node->op) && $node->op != 'Preview') {
          ?>
          <div class="Story-details">
            <h2><?php print t('Audio Upload'); ?></h2>
            <div class="content-details">
              <?php print render($content['field_podcast_audio_upload']); ?>
            </div>
          </div> 
        <?php } ?>

        <?php
        $browsemedia = render($content['field_story_extra_large_image']);
        if (!empty($browsemedia)):
          ?>
          <div class="BrowseMedia">
            <h2>Image Upload </h2>
            <div class="content-details">
              <?php print render($content['field_story_extra_large_image']); ?>
            </div>
          </div>
        <?php endif; ?>



        <?php
        $configuration = render($content['field_story_itg_tags']);
        if (!empty($configuration)):
          ?>
          <div class="configuration content-box">
            <h2><?php print t('Configuration'); ?></h2>
            <div class="content-details"><?php print render($content['field_story_itg_tags']); ?></div>
          </div>

        <?php endif; ?>


        <?php
        $field_story_category = render($content['field_story_category']);
        if (!empty($field_story_category)):
          ?>
          <?php print render($content['field_story_category']); ?>
        <?php endif; ?>


      <?php endif; // end of view mode full condition  ?></div>

  <?php endif; ?>
</div>
<h1><?php print t("OTHER PODCASTS") ?></h1>
<?php print views_embed_view('podcasts_listing', 'block'); ?>
<?php
$config_name = trim($global_comment_last_record[0]->config_name);
?>
<?php if (function_exists('taboola_view')) : ?>
  <?php taboola_view(); ?>
<?php endif; ?>

<?php if ($config_name == 'vukkul') : ?>
  <div class="vukkul-comment">
    <div id="vuukle-emote"></div>
    <div id="vuukle_div"></div>
    <?php if (function_exists('vukkul_view')) : ?>
      <?php vukkul_view(); ?>
    <?php endif; ?>
  </div>
<?php endif; ?>


<?php if ($config_name == 'other') : ?>
  <div id="other-comment">
    <?php
    $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
    print render($block['content']);
    ?>
  </div>
<?php endif; ?>