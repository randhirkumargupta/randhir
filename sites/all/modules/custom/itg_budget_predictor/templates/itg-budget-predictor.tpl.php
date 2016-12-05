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
?>

<style>
    #sortable1, #sortable2, #sortable3, #sortable4 { width:100%; min-height:400px;}
            #sortable1 li, #sortable2 li, #sortable3 li, #sortable4 li { display:block;cursor:move;margin: 0 5px 5px 5px;}    
</style>

<?php if ($budget_exist == 1) { ?>    
  <!--        <p class="success" style="display:none;">Success</p>-->
<h1 class="budget-predictor-heading">Budget - Predictor</h1>
  <div id="main-container-budget">
        <div class="top-side-block">
            <div id="ranking-content" class="col-md-2 col-list col-list-1">
                <span id="ranking-label" class="title">Cheaper</span>        
                <ul id="sortable1" class="connectedSortable">
                    <?php echo $column1; ?>
                </ul>
            </div>
            <div id="ranking-content" class="col-md-2 col-list col-list-2">
                <span id="ranking-label" class="title">Dearer</span>    
                <ul id="sortable2" class="connectedSortable">
                    <?php echo $column2; ?>
                </ul>
            </div>
            <div id="ranking-content" class="col-md-2 col-list col-list-3">
                <span id="ranking-label" class="title">Same</span>    
                <ul id="sortable3" class="connectedSortable">
                    <?php echo $column3; ?>
                </ul>
            </div>
            <div id="ranking-content-main" class="col-md-6 col-list col-list-4">
                <span id="ranking-label" class="title">Items</span>    
                <ul id="sortable4" class="connectedSortable">
                    <?php echo $column4; ?>
                    <?php echo ($budget_message_flag) ? $budget_message : ''; ?>
                </ul>                
            <div class="bottom-side-block">
                <div class="social-share">
                  <ul>
                      <li><a href="javascript:void(0)"><i class="fa fa-share-alt"></i></a></li>
                      <li><div id="fb-root"></div><a class="facebook" href="javascript:void(0)" onclick="badget_fb_share('<?php print $actual_link; ?>', '<?php print $budget_title; ?>', '<?php print $budget_social_message; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a></li>
                      <li><a href="javascript:void(0)" class="twitter" onclick="badget_twitter_share('<?php print urlencode($budget_title); ?>', '<?php print urlencode($actual_link); ?>')"><i class="fa fa-twitter"></i></a></li>
                      <li><a title="share on google+" class="google" href="javascript:void(0)" onclick="return badget_google_plus_share('<?php print $actual_link; ?>')"></a></li>                                            
                  </ul>
                </div>
            </div> 
                
            <?php if (empty($file_name)) { ?>
            <button class="btn btn-save" type="button" onclick="captureCurrentDiv()">Submit</button>
            <?php
            }
                } else {
            ?>
            <p class="success">Not Exist</p>
            <?php
                }
            ?>
                
                
            </div>
        </div>    
      
      <?php if (empty($file_name)) { ?>
            <button class="btn btn-save" type="button" onclick="captureCurrentDiv()">Save Budget</button>
            <?php
            }
               else {
            ?>
            <p class="success">Not Exist</p>
            <?php
                }
            ?>
     
  </div>

 