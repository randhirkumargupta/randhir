<?php
   $column1 = $data['column1'];
    $column2 = $data['column2'];
    $column3 = $data['column3'];
    $column4 = $data['column4'];
    $budget_exist = $data['exist'];
    $file_name = $data['file_names'];
    $image     = $data['file_name'];
    $actual_link = $data['actual_link'];
    $budget_title = $data['budget_title'];
    $budget_description = $data['budget_description'];
    $budget_message = $data['budget_message'];
    $budget_message_flag = $data['budget_message_flag'];
   
?>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; utf-8" />
        <title><?php print $title; ?></title>
        <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.4.1/jquery.min.js"></script>
        <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.7.2/jquery-ui.min.js"></script>

        <style type="text/css">
            #sortable1, #sortable2, #sortable3, #sortable4 { width:15%; min-height:400px; border:1px solid #ccc; background:#f3f3f3;list-style-type: none; margin: 0; padding: 0; float: left; margin-right: 10px; }
            #sortable1 li, #sortable2 li, #sortable3 li, #sortable4 li { display:block; background:#e3e3e3; cursor:move;margin: 0 5px 5px 5px; padding: 5px; font-size: 1.2em;}
            *{margin:0;padding:0;}
            #main-container-budget
            {
                    margin:50px auto;
                    padding:15px;
                    border:solid #cdcdcd 1px;
                    width:800px;
                    height:600px;
                    background:#f9f9f9;
            }
        </style>
    </head>
    <body>
    <?php if($budget_exist == 1) { ?>    
        <p class="success" style="display:none;">Success</p>
        <div id="main-container-budget">
            <div id="ranking-content">
                <div id="ranking-label">Cheaper</div>    
                <ul id="sortable1" class="connectedSortable">
                    <?php echo $column1; ?>
                </ul>
            </div>
            <div id="ranking-content">
                <div id="ranking-label">Dearer</div>    
                <ul id="sortable2" class="connectedSortable">
                    <?php echo $column2; ?>
                </ul>
            </div>
            <div id="ranking-content">
                <div id="ranking-label">Same</div>    
                <ul id="sortable3" class="connectedSortable">
                    <?php echo $column3; ?>
                </ul>
            </div>
            <div id="ranking-content-main">
                <div id="ranking-label">ITEMS</div>    
                <ul id="sortable4" class="connectedSortable">
                    <?php echo $column4; ?>
                    <?php echo ($budget_message_flag) ? $budget_message : ''; ?>
                </ul>
            </div>
        </div>
 
           <div class="social-list">
            <ul>
                <li class="mhide"><a href="#"><i class="fa fa-share"></i></a> <span>SHARE</span></li>
                <li class="mhide"><div id="fb-root"></div><a onclick="badget_fb_share('<?php print $actual_link;?>', '<?php print $budget_title; ?>', '<?php print $budget_description; ?>', '<?php print $image;?>')"><i class="fa fa-facebook"></i></a></li>
                <li class="mhide"><a href="javascript:" onclick="badget_twitter_share('<?php print urlencode($budget_title);?>', '<?php print urlencode($actual_link); ?>')"><i class="fa fa-twitter"></i></a></li>
                <li class="mhide"><a title="share on google+" href="#" onclick="return badget_google_plus_share('<?php print $actual_link;?>')"><i class="fa fa-google-plus"></i></a></li>
                <li class="mhide"><a href="#"><i class="fa fa-comment"></i></a> <span>1522</span></li>
                <li class="mhide"><span class="share-count">4.3k</span> SHARES</li>
            </ul>
          </div>
        <?php if(empty($file_name)) { ?>
                <button type="button" onclick="captureCurrentDiv()">Save Budget</button>
<?php       } 
    } else {
?>
    <p class="success">Not Exist</p>
<?php
    }
?>
    </body>
    
</html>