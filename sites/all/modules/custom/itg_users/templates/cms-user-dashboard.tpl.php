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

<!--  <li>
    <a class="dashboard-tab-item" href="manage-users">
      <i class="fa fa-users"></i>
      <span>User Management</span>
    </a>
  </li>
  <li>
    <a href="mydraft-story" class="dashboard-tab-item">
    <i class="fa fa-server"></i>
    <span>Content Management</span>
    </a>
  </li>
  <li>
    <a href="admin/structure/taxonomy/category_management" class="dashboard-tab-item">
    <i class="fa fa-list-alt"></i>
    <span>Category Management</span>
    </a>
  </li>
  <li>
    <a href="mydraft-story" class="dashboard-tab-item">
    <i class="fa fa-file-text"></i>
    <span>Story</span>
    </a>
  </li>
  <li>
    <a href="manage-magazines" class="dashboard-tab-item">
    <i class="fa fa-book"></i>
    <span>Magazine</span>
    </a>
  </li>
  <li>
    <a href="manage-supplements" class="dashboard-tab-item">
    <i class="fa fa-list-alt"></i>
    <span>Supplement</span>
    </a>
  </li>
  <li>
    <a href="manage-issues" class="dashboard-tab-item">
    <i class="fa fa-files-o"></i>
    <span>Issue</span>
    </a>
  </li>
  <li>
    <a href="breaking-news" class="dashboard-tab-item">
    <i class="fa fa-newspaper-o"></i>
    <span>Breaking News</span>
    </a>
  </li>
  <li>
    <a href="manage-photogallery" class="dashboard-tab-item">
    <i class="fa fa-picture-o"></i>
    <span>Photo Gallery</span>
    </a>
  </li>-->

