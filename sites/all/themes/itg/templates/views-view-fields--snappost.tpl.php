<?php
/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
$snap= "snap".$row->nid;
$snapurl = urlencode('http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI'].'/#'.$snap);
$fb_title = addslashes($row->field_field_story_snap_post[0]['raw']['value']);
$fb_url = 'http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI'];
$share_desc = '';
$node = node_load($row->nid);
$image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
?>
<div class="container"  id="<?php print $snap; ?>">
    <?php foreach ($fields as $id => $field): ?>
      <?php if (!empty($field->separator)): ?>
        <?php print $field->separator; ?>
      <?php endif; ?>

      <?php print $field->wrapper_prefix; ?>
        <?php print $field->label_html; ?>
        <?php print $field->content; ?>
      <?php print $field->wrapper_suffix; ?>
    <?php endforeach; ?>
    <div class="snap-post-btm">
        <div class="snap-button">
            
                <?php 
                  if (function_exists('itg_flag_get_count')) {
                    $like = itg_flag_get_count($row->nid, 'like_count');
                    $dislike = itg_flag_get_count($row->nid, 'dislike_count');
                  }
                  if(!empty($like['like_count'])) {
                    $like_count = '('.$like['like_count'].')';
                  }
                  if(!empty($dislike['dislike_count'])) {
                    $dislike_count = '('.$dislike['dislike_count'].')';
                  }
                  $pid= "voted_".$row->nid;
                  $like= "no-of-likes_".$row->nid;
                  $dislike= "no-of-dislikes_".$row->nid;
                  
                  ?>
        <button id="like_count" rel="<?php print $row->nid; ?>" class="agree"><i class="fa fa-thumbs-o-up"></i> Like <span id="<?php print $like;?>"><?php print $like_count; ?></span></button> <button id="dislike_count" rel="<?php print $row->nid; ?>" class="disagree"><i class="fa fa-thumbs-o-down"></i> Dislike <span id="<?php print $dislike;?>"><?php print $dislike_count; ?></span> </button>
        <p class="error-msg" id="<?php print $pid; ?>"></p>
        </div>
        <div class="snap-social">
            <ul>
                <li><a class="def-cur-pointer" href="javascript:" onclick="fbpop('<?php print $fb_url;?>', '<?php print $fb_title; ?>','<?php print $share_desc; ?>', '<?php print $image;?>')"><i class="fa fa-facebook"></i><span>Share</span></a></li>
                <li><a href="javascript:" onclick="twitter_popup('<?php print urlencode($row->field_field_story_snap_post[0]['raw']['value']);?>', '<?php print $snapurl; ?>')"><i class="fa fa-twitter"></i><span>Twitter</span></a><!--<span class="twt-count">0</span>--></li>
                <li><a href="javascript:"><i class="fa fa-comment-o"></i><span>Comment</span></a></li>
            </ul>
        </div>
    </div>
</div>