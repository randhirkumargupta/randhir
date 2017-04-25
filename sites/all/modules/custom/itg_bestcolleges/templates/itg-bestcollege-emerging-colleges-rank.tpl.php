<div class="emergingCollege-section">
<div class="streamtitle"><?php print t('STREAM: '.drupal_strtoupper(arg(3))); ?></div>
<?php if(is_array($data) && count($data) > 0) { ?>
<table style="border-collapse: collapse;" width="100%" align="CENTER" border="1" bordercolor="#c4c4c4" cellpadding="0" cellspacing="0">
  <tr>
    <th width="50"><?php print t('Rank'); ?></th>
    <th width="180"><?php print t('Name of the college'); ?></th>
    <th><?php print t('Reputation'); ?></th>
    <th><?php print t('Academic Input'); ?></th>
    <th><?php print t('Student Care'); ?></th>
    <th><?php print t('Infra'); ?></th>
    <th><?php print t('Placement'); ?></th>
    <th><?php print t('Perceptual Rank'); ?></th>
    <th><?php print t('Factual Rank'); ?></th>

  </tr>
  <?php foreach($data as $data_key => $data_val) { ?>
  <tr>
    <td data-title="Rank"><?php print $data_val->overall_rank; ?>.</td>
    <td data-title="Name of the college"><?php print $data_val->collegename; ?></td>
    <td data-title="Reputation"><?php print $data_val->reputation; ?></td>
    <td data-title="Academic Input"><?php print $data_val->academic_input; ?></td>
    <td data-title="Student Care"><?php print $data_val->studentcare; ?></td>
    <td data-title="Infra"><?php print $data_val->infrastructure; ?></td>
    <td data-title="Placement"><?php print $data_val->placement; ?></td>
    <td data-title="Perceptual Rank"><?php print $data_val->preceptual_rank; ?></td>
    <td data-title="Factual Rank"><?php print $data_val->factual_rank; ?></td>
  </tr>
  <?php } ?>
</table>
<?php } else { print "<div class='bestcollege_empty_message'>".t("No record founds")."</div>"; } ?>
</div>

<!-- Grid View-->
<div class="col-sm-12 col-xs-12 view1">
<div class="title col-md-6 col-sm-6 col-xs-12"><?php print t("Best of The Best ") . arg(1);; ?></div>

        <div class="right_Section pull-right  col-md-6  col-sm-6 col-xs-12 text-right hidden-xs">
        <strong>view as</strong>
        <div class="btn-group">
            <a href="#" class="btn btn-default btn-sm grid"><span class="fa fa-th"></span> Grid</a>
            <a href="#" class="btn btn-default btn-sm active_btn list"><span class="fa fa-th-list"></span> List</a>
        </div>
        </div>
</div>

<div class="clearfix"></div>
<div class="col-sm-12 remove_padd_right">
<div class="row list-group college">
      <div class="clr_chn right_align_bestcollege" >


            <?php
               $url_get = explode('/',$_SERVER['REQUEST_URI']);
                if (array_filter(views_get_view_result('best_college_image_slider', 'block_1', $url_get[2]))) {
                    print views_embed_view('best_college_image_slider', 'block_1', $url_get[2]);
                }
            ?>



            </div>
        </div>
</div>

<!-- code for like dislike -->
<div class="col-sm-12 col-xs-12 col-md-12">
  <?php
       $arg = arg();
      // get global comment config
      //$config_name = trim($global_comment_last_record[0]->config_name);
      $config_name = 'vukkul';
      if($arg && $arg[0] == "bestcolleges") {
        $term_name = "Bestcolleges " . $arg[1];
        $term_data = taxonomy_get_term_by_name($term_name);
      }
      $tid = array_pop($term_data)->tid;

      $get_val = $tid;
      if (function_exists('itg_flag_get_count')) {
        $like = itg_flag_get_count($get_val, 'like_count');
        $dislike = itg_flag_get_count($get_val, 'dislike_count');
      }

      $like_count_like = $like['like_count'] + $migrated_count[0]['like_count'];
      $dislike_count_like = $dislike['dislike_count'] + $migrated_count[0]['dislike_count'];

      $pid = "voted_" . $get_val;
      $like = "no-of-likes_" . $get_val;
      $dislike = "no-of-dislikes_" . $get_val;
  ?>

    <!--- Like Dis-Like -->
     <div class="agbutton story-like-dislike">
          <div id="name-dv"><?php print t('Do You Like This Bestcolleges'); ?>
            <span id="lky"><button title="Like" id="like_count" rel="<?php print $get_val; ?>" data-tag="sty"><i class="fa fa-thumbs-o-up"></i> <span id="<?php print $like; ?>"><?php print $like_count_like; ?></span> </button>
              <span id="sty-dv" style="display:none">Awesome! </br> Now share the story </br> <a title="share on facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a>
                <a title="share on twitter" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:void(0)" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a>
                <a title="share on google+" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" href="javascript:void(0)" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a>
                <?php
                if ($config_name == 'vukkul') {
                  ?>
                  <a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment" class="def-cur-pointer"><i class="fa fa-comment"></i></a>
                <?php } if ($config_name == 'other') { ?>
                  <a onclick ="scrollToAnchor('other-comment');" title="comment" class="def-cur-pointer"><i class="fa fa-comment"></i></a>
                <?php } ?>
              </span></span>
            <span id="dlky"> <button title="Dislike" id="dislike_count" rel="<?php print $get_val; ?>" data-tag="dsty"><i class="fa fa-thumbs-o-down"></i> <span id="<?php print $dislike; ?>"><?php print $dislike_count_like; ?></span></button>
              <?php
              if ($config_name == 'vukkul') {
                ?>
                <span id="dsty-dv" style="display:none"><?php print t('Too bad.'); ?></br> <?php print t("Tell us what you didn't like in the"); ?> <a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><?php print t('comments'); ?></a></span>

              <?php } if ($config_name == 'other') { ?>
                <span id="dsty-dv" style="display:none"><?php print t('Too bad.'); ?></br> <?php print t("Tell us what you didn't like in the"); ?> <a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><?php print t('comments'); ?></a></span>
              <?php } ?>

            </span>
          </div>
          <p class="error-msg" id="<?php print $pid; ?>"></p>
        </div>

    <!--- End Like Dis-Like -->
</div>
<!-- Grid View End-->

      <?php
        if (function_exists('taboola_view')) {
          //taboola_view();
        }
        ?>

        <?php
        if ($config_name == 'vukkul') {
          if (!empty($node->field_story_comment_question['und'][0]['value'])) {
            $question = 'Q:' . $node->field_story_comment_question['und'][0]['value'];
          }
          ?>
          <div class="c_ques"><?php print $question; ?></div>
          <div class="vukkul-comment">
            <div id="vuukle-emote"></div>
            <div id="vuukle_div"></div>

            <?php
            if (function_exists('vukkul_view')) {
              vukkul_view();
            }
            ?>

          </div>
          <?php
        }
        if ($config_name == 'other' && in_array('comment', $config)) {
          ?>
          <div id="other-comment">
            <?php
            $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
            print render($block['content']);
            ?>
          </div>
        <?php }
        ?>


