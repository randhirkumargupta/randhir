<?php
/**
 * @file
 * Theme implementation for ugc comment form.
 * 
 */

?>
<div id="total-comment">
<?php
if(isset($_SESSION['msg'])) {
  print $_SESSION['msg'];
  unset($_SESSION['msg']);
} 
if(!empty($variables['total_comments'])) {
print $variables['total_comments'].' Comment(s)';
}
else
{
  print 'Leave a comment';
}

$comment_existance = itg_get_comment_question(arg(1));
?></div>
<div class="">
    <?php if(!empty($comment_existance)) { ?>
    <strong><?php print t('Q:')?></strong> <?php print $comment_existance; ?>
    <?php } ?>
    <div class="ugc-comment-popup">
    <a class="close-comment-popup" href="javascript:;"><i class="fa fa-times" aria-hidden="true"></i></a>
<?php print drupal_render($variables['comment_form']); ?>
    </div>
</div>
<?php print $variables['comment_data']; ?>
  
