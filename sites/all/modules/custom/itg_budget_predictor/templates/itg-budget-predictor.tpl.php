<?php
$column1 = $data['column1'];
$column2 = $data['column2'];
$column3 = $data['column3'];
$column4 = $data['column4'];
$budget_exist = $data['exist'];
$file_name = $data['file_names'];
$image = $data['file_name'];
$actual_link = $data['actual_link'];
$budget_title = $data['budget_title'];
$budget_description = $data['budget_description'];
$budget_message = $data['budget_message'];
$budget_social_message = $data['budget_social_message'];
$budget_message_flag = $data['budget_message_flag'];
$budget_message_front_flag = $data['budget_message_front_flag'];
$budget_social_message_flag = $data['budget_social_message_flag'];
$admin_user = $data['admin_user'];
$section_id = $data['section_id'];
$user_id = $data['user_id'];
?>
<?php if ($budget_exist == 1) { ?>
  <h1 class="budget-predictor-heading"><?php print t('CHEAPER / DEARER'); ?></h1>
  <?php if(empty($user_id)) { ?>
    <h3 class="budget-predictor-msg"><?php print t('Please drag and drop images and please login if you know, your prediction will right or not.'); ?></h3>
  <?php } ?>
  <div id="main-container-budget">
    
    <table class="budget-predictor-table">
        <thead>
          <tr>
            <th class="title"><?php print t('Cheaper'); ?></th>
            <th class="title"><?php print t('Dearer'); ?></th>
            <th class="title"><?php print t('Same'); ?></th>
            <th class="title"><?php print t('Items'); ?></th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td class="ranking-content cheaper">
              <ul id="sortable1" class="connectedSortable">
                <?php echo $column1; ?>
              </ul>
            </td>
            <td class="ranking-content deaper">
              <ul id="sortable2" class="connectedSortable">
                <?php echo $column2; ?>
              </ul>
            </td>
            <td class="ranking-content same">
              <ul id="sortable3" class="connectedSortable">
                <?php echo $column3; ?>
              </ul>
            </td>
            <td class="ranking-content bp-items">
              <ul id="sortable4" class="connectedSortable">
                <?php echo $column4; ?>
                <div id="loader-data"><img class="widget-loader" style="display: none" src="<?php echo base_path(); ?>sites/all/themes/itg/images/tab-loading.gif" alt="Loading..." /></div>
              </ul>
              <?php
                  if ($budget_message_flag) {
                     print '<p class="success">'.$budget_message.'</p>';
                     if($admin_user) { ?>
                      <div class="cheaper-deaper-action"><button class="btn-reset" type="button" onclick="reset_budget(<?php print $section_id; ?>)"><?php print t('Reset'); ?></button></div>
                     <?php }
                  }
                  elseif ($budget_message_front_flag) {
                    print '<p class="success">'.$budget_social_message.'</p>';
                    ?>
                    <div class="budget-predictor-block">
                        <div class="budget-predictor-social-share">
                            <div class="share-msg"><?php print 'SHARE YOUR PREDICTION'; ?></div>
                            <ul>
                                <li><div id="fb-root"></div><a class="facebook" href="javascript:void(0)" onclick="badget_fb_share('<?php print $actual_link; ?>', '<?php print $budget_title; ?>', '<?php print $budget_social_message; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a></li>
                                <li><a href="javascript:void(0)" class="twitter" onclick="badget_twitter_share('<?php print urlencode($budget_title); ?>', '<?php print urlencode($actual_link); ?>')"><i class="fa fa-twitter"></i></a></li>
                                <li><a title="share on google+" class="google" href="javascript:void(0)" onclick="return badget_google_plus_share('<?php print $actual_link; ?>')"></a></li>
                            </ul>
                        </div>
                    </div>
  <?php } ?>

              <?php if (empty($file_name) && empty($budget_message_flag)) { ?>
                <?php if(empty($user_id)) { ?>
                      <div class="cheaper-deaper-action"><button class="btn-submit" type="button" onclick="Go (550, 500, 50, 'indiatoday', '', '<?php print PARENT_SSO; ?>', '/saml_login/other')"><?php print t('Submit'); ?></button></div>
                <?php } else { ?>
                      <div class="cheaper-deaper-action"><button class="btn-submit" type="button" onclick="captureCurrentDiv(<?php print $section_id; ?>)"><?php print t('Submit'); ?></button></div>
                <?php } ?>

                <?php
              }
            }
            else {
              ?>
              <p class="success"><?php print t('Not Exist'); ?></p>
              <?php
            }
            ?>
            </td>
          </tr>
        </tbody>
      </table>

  </div>  
    
    
    
    
  

