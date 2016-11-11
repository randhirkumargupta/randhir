<?php
/**
 * @file
 *   Template file for user dashboard. 
 */
?>

<ul class="dashboard-tab">
    <?php foreach ($data['user_link'] as $key => $val): ?>
      <li>
          <a class="dashboard-tab-item" href="<?php print $key; ?>">
              <?php
              switch ($key) {
                case 'manage-users':
                  $class = 'fa fa-users';
                  break;

                default:
                  $class = 'fa fa-list-alt';
              }
              ?>
              <i class="<?php print $class; ?>"></i>
              <span><?php print $val; ?></span>
          </a>
      </li>
    <?php endforeach; ?>
</ul>
