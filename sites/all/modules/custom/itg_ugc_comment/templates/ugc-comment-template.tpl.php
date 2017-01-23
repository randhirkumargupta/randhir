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
print $variables['total_comments'].' comments';
}
else
{
  print 'Leave a comment';
}
?></div>
<div class="">
    <div class="ugc-comment-popup">
    <a class="close-comment-popup" href="javascript:;"><i class="fa fa-times" aria-hidden="true"></i></a>
<?php print drupal_render($variables['comment_form']); ?>
    </div>
</div>
<?php print $variables['comment_data']; ?>
  
