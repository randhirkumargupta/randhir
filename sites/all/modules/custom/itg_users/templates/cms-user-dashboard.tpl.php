<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
//p($data);
?>
<ul class="dashboard-tab">
<?php
foreach($data['user_link'] as $key => $val){
  ?>
  <li>
    <a class="dashboard-tab-item" href="<?php print $key;?>">
      <?php
        if ($key == 'manage-users') {
          $class = 'fa fa-users';
        } else if ($key == 'mydraft-story') {
          $class = 'fa fa-file-text';
        } else if ($key == 'manage-magazines') {
          $class = 'fa fa-book';
        } else if ($key == 'manage-supplements') {
          $class = 'fa fa-list-alt';
        } else if ($key == 'manage-issues') {
          $class = 'fa fa-files-o';
        } else if ($key == 'breaking-news') {
          $class = 'fa fa-newspaper-o';
        } else if ($key == 'manage-photogallery') {
          $class = 'fa fa-picture-o';
        } else if ($key == 'category-manager-listing') {
          $class = 'fa fa-list-alt';
        } else {
          $class = 'fa fa-list-alt';
        }
      ?>
      <i class="<?php print $class;?>"></i>
      <span><?php print $val;?></span>
    </a>
  </li>
<?php } ?>
 </ul>
