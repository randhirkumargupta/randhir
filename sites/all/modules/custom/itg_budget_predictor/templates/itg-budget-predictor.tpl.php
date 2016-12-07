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
$budget_year = $data['budget_year'];
?>

<style>
    #sortable1, #sortable2, #sortable3, #sortable4 { width:100%; min-height:450px; cursor: move;}
    #sortable1 li, #sortable2 li, #sortable3 li, #sortable4 li { display:block;cursor:move; margin: 10px 0px;
    background: transparent;
    border: none;
    text-align: center;}
    <?php if ($admin_user) { ?>
      #main-container-budget{width:100%;height:100%;display: inline-block;width: 100%;}
    <?php }
    else { ?>
      #main-container-budget{width:100%;height:600px;}
    <?php } ?>

</style>

<?php if ($budget_exist == 1) { ?>    
  <h1 class="budget-predictor-heading"><?php print t('Budget - Predictor'); ?></h1>
  <div id="main-container-budget">
      <div class="top-side-block">
          <div id="ranking-content" class="col-md-2 col-list col-list-1">
              <span id="ranking-label" class="title"><?php print t('Cheaper'); ?></span>        
              <ul id="sortable1" class="connectedSortable">
                  <?php echo $column1; ?>
              </ul>
          </div>
          <div id="ranking-content" class="col-md-2 col-list col-list-2">
              <span id="ranking-label" class="title"><?php print t('Dearer'); ?></span>    
              <ul id="sortable2" class="connectedSortable">
                  <?php echo $column2; ?>
              </ul>
          </div>
          <div id="ranking-content" class="col-md-2 col-list col-list-3">
              <span id="ranking-label" class="title"><?php print t('Same'); ?></span>    
              <ul id="sortable3" class="connectedSortable">
                  <?php echo $column3; ?>
              </ul>
          </div>
          <div id="ranking-content-main" class="col-md-6 col-list col-list-4">
              <span id="ranking-label" class="title"><?php print t('Items'); ?></span>    
              <ul id="sortable4" class="connectedSortable">
                  <?php echo $column4; ?>
                  <?php
                  if ($budget_message_flag) {
                    print $budget_social_message;
                  }
                  elseif ($budget_message_front_flag) {
                    print $budget_message;
                    ?>      
                    <div class="budget-predictor-block">
                        <div class="budget-predictor-social-share">
                            <ul>
                                <li><a href="javascript:void(0)"><i class="fa fa-share-alt"></i></a></li>
                                <li><div id="fb-root"></div><a class="facebook" href="javascript:void(0)" onclick="badget_fb_share('<?php print $actual_link; ?>', '<?php print $budget_title; ?>', '<?php print $budget_social_message; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a></li>
                                <li><a href="javascript:void(0)" class="twitter" onclick="badget_twitter_share('<?php print urlencode($budget_title); ?>', '<?php print urlencode($actual_link); ?>')"><i class="fa fa-twitter"></i></a></li>
                                <li><a title="share on google+" class="google" href="javascript:void(0)" onclick="return badget_google_plus_share('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>                                           
                            </ul>
                        </div>
                    </div>
  <?php } ?>
              </ul>

              <?php if (empty($file_name)) { ?>
                <button class="btn btn-save" type="button" onclick="captureCurrentDiv(<?php print $budget_year; ?>)"><?php print t('Submit'); ?></button>
                <?php
              }
            }
            else {
              ?>
              <p class="success"><?php print t('Not Exist'); ?></p>
              <?php
            }
            ?>


        </div>
    </div>    

</div>

