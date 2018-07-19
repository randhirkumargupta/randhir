<?php
print views_embed_view('authors_and_people_listing', 'block_1');

// Pagination
$page = (int) (!isset($_GET["page"]) ? 1 : $_GET["page"]);
$limit = 15;
$startpoint = ($page * $limit) - $limit;

function pagination($per_page = 10,$page = 1, $url = '?'){
    $total = 500;
    $adjacents = "2";
    $page = ($page == 0 ? 1 : $page);
    $start = ($page - 1) * $per_page;
    $prev = $page - 1;
    $next = $page + 1;
    $lastpage = ceil($total/$per_page);
    $lpm1 = $lastpage - 1;
    $pagination = "";

    if($lastpage > 1){
        $pagination .= "<ul class='pagination'>";
        //$pagination .= "<li class='details'>Page $page of $lastpage</li>";
        if ($lastpage < 7 + ($adjacents * 2)){
            for ($counter = 1; $counter <= $lastpage; $counter++){
                if ($counter == $page)
                $pagination.= "<li><a class='current'>$counter</a></li>";
                else
                $pagination.= "<li><a href='{$url}page=$counter'>$counter</a></li>";
            }
        }
        elseif($lastpage > 5 + ($adjacents * 2)){
            if($page < 1 + ($adjacents * 2)){
                for ($counter = 1; $counter < 4 + ($adjacents * 2); $counter++){
                    if ($counter == $page)
                        $pagination.= "<li><a class='current'>$counter</a></li>";
                    else
                        $pagination.= "<li><a href='{$url}page=$counter'>$counter</a></li>";
                }
                $pagination.= "<li class='dot'>...</li>";
                $pagination.= "<li><a href='{$url}page=$lpm1'>$lpm1</a></li>";
                $pagination.= "<li><a href='{$url}page=$lastpage'>$lastpage</a></li>";
            }
            elseif($lastpage - ($adjacents * 2) > $page && $page > ($adjacents * 2)){
                $pagination.= "<li><a href='{$url}page=1'>1</a></li>";
                $pagination.= "<li><a href='{$url}page=2'>2</a></li>";
                $pagination.= "<li class='dot'>...</li>";
                for ($counter = $page - $adjacents; $counter <= $page + $adjacents; $counter++){
                    if ($counter == $page)
                        $pagination.= "<li><a class='current'>$counter</a></li>";
                    else
                        $pagination.= "<li><a href='{$url}page=$counter'>$counter</a></li>";
                }
                $pagination.= "<li class='dot'>..</li>";
                $pagination.= "<li><a href='{$url}page=$lpm1'>$lpm1</a></li>";
                $pagination.= "<li><a href='{$url}page=$lastpage'>$lastpage</a></li>";
            }
            else{
                $pagination.= "<li><a href='{$url}page=1'>1</a></li>";
                $pagination.= "<li><a href='{$url}page=2'>2</a></li>";
                $pagination.= "<li class='dot'>..</li>";
                for ($counter = $lastpage - (2 + ($adjacents * 2)); $counter <= $lastpage; $counter++){
                    if ($counter == $page)
                        $pagination.= "<li><a class='current'>$counter</a></li>";
                    else
                        $pagination.= "<li><a href='{$url}page=$counter'>$counter</a></li>";
                }
            }
        }
        if ($page < $counter - 1){
            $pagination.= "<li><a href='{$url}page=$next'>Next</a></li>";
            $pagination.= "<li><a href='{$url}page=$lastpage'>Last</a></li>";
        }
        else{
            $pagination.= "<li><a class='current'>Next</a></li>";
            $pagination.= "<li><a class='current'>Last</a></li>";
        }
        $pagination.= "</ul>\n";
    }
    return $pagination;
}

// Default autors listing
$content_type = 'reporter';
$query = db_select('node', 'n');
$query->Join('field_data_field_celebrity_pro_occupation', 'fo', 'fo.entity_id = n.nid');
$query->Join('field_data_field_reporter_profile_type', 'pro', 'pro.entity_id = n.nid');
$query->Join('itg_multi_byline_info', 'bi', 'bi.byline_id = n.nid');
$query->leftJoin('field_data_body', 'bv', 'bv.entity_id = n.nid');
$query->leftJoin('field_data_field_inactive_profile', 'ip', 'ip.entity_id = n.nid');
$query->leftJoin('field_data_field_story_expert_name', 'fb', 'fb.entity_id = n.nid');
$query->leftJoin('field_data_field_reporter_twitter_handle', 'tw', 'tw.entity_id = n.nid');
$query->leftJoin('field_data_field_story_extra_large_image', 'img', 'img.entity_id = n.nid');
$query->condition('bi.publish_status', 1, '=');
$query->condition('n.status', 1, '=');
$query->fields('n', array('title', 'nid'));
$query->fields('bv', array('body_value'));
$query->fields('fb', array('field_story_expert_name_value'));
$query->fields('tw', array('field_reporter_twitter_handle_value'));
$query->fields('img', array('field_story_extra_large_image_fid'));
$query->condition('n.type', $content_type, '=');
$query->condition('fo.field_celebrity_pro_occupation_tid', '285750', '=');
$query->condition('fo.bundle', 'reporter', '=');
$query->condition('pro.bundle', 'reporter', '=');
$query->condition('pro.field_reporter_profile_type_value', 'internal', '=');
$or = db_or();
$or->condition('ip.field_inactive_profile_value', '0', '=');
$or->condition('ip.field_inactive_profile_value', NULL);
$query->condition($or);
$query->orderBy('bi.nid', 'DESC');
$query->groupBy('bi.byline_id');
$query->range($startpoint, $limit);
$result = $query->execute()->fetchAll();
if(!empty($result)){ ?>
    <div class="custom-author-listing-wrapper">
    <?php foreach ($result as $key => $value){?>
    <div class="author-listing">
    <div class="pic">
    <?php
    if(!empty($value->field_story_extra_large_image_fid)) {
        $file = file_load($value->field_story_extra_large_image_fid);
        $uri = $file->uri;
        $image = theme('image_style',array(
                    'style_name' => 'widget_small',
                    'path' => $uri,
                    'attributes' => array('class' => 'custom-inline', 'style' => 'border:1px solid #aaa;')
                  )
                );
        print l($image, 'node/' . $value->nid, array('html' => TRUE));

    }
    ?>
    </div>
    <div class="detail">
      <div class="author-right">
        <h3>
          <?php print l($value->title , 'node/' . $value->nid) ?>
        </h3>
        <p>
          <?php print mb_strimwidth(html_entity_decode(strip_tags($value->body_value)), 0, 245, "..");  ?>
        </p>
        <div class="social-icon">
          <ul>
            <?php
                      if (!empty($value->field_story_expert_name_value)) { ?>

            <li>
              <a class="def-cur-pointer" href="<?php  print  $value->field_story_expert_name_value;?>" target="_blank"><i class="fa fa-facebook"></i></a></a>
            </li>
            <?php } ?>


            <?php
                      if (!empty($value->field_reporter_twitter_handle_value)) { ?>

            <li>
              <a class="def-cur-pointer" href="<?php  print 'https://twitter.com/'.ltrim($value->field_reporter_twitter_handle_value, '@'); ?>" target="_blank"><i class="fa fa-twitter"></i></a>
            </li>
            <?php } ?>
          </ul>
        </div>
      </div>
    </div>
</div>
<?php }
 echo pagination($limit, $page, '/authors-list?');
?>
</div>
<?php } ?>
<script type="text/javascript">
(function ($, Drupal, window, document, undefined) {
Drupal.behaviors.itg_reporter = {
    attach: function (context, settings) {
        jQuery("#edit-submit-authors-and-people-listing").click(function () {
            var title = jQuery("#edit-title").val();
            if(title != '' && title != null){
                jQuery(".custom-author-listing-wrapper").hide();
            }else{
                jQuery(".custom-author-listing-wrapper").show();
            }

        })
    }
};
})(jQuery, Drupal, this, this.document);
</script>
<style type="text/css">
ul.pagination{
margin:0px;
padding:0px;
height:100%;
overflow:hidden;
font:12px 'Tahoma';
list-style-type:none;
}

ul.pagination li.details{
padding:7px 10px 7px 10px;
font-size:14px;
}

ul.pagination li.dot{padding: 3px 0;}

ul.pagination li{
float:left;
margin:0px;
padding:0px;
margin-left:5px;
}

ul.pagination li:first-child{
margin-left:0px;
}

ul.pagination li a{
color:black;
display:block;
text-decoration:none;
padding:7px 10px 7px 10px;
}

ul.pagination li a img{
border:none;
}
ul.pagination li.details{
color:#888888;
}

ul.pagination li a
{
color:#FFFFFF;
border-radius:3px;
-moz-border-radius:3px;
-webkit-border-radius:3px;
}

ul.pagination li a
{
color:#474747;
border:solid 1px #B6B6B6;
padding:6px 9px 6px 9px;
background:#E6E6E6;
background:-moz-linear-gradient(top,#FFFFFF 1px,#F3F3F3 1px,#E6E6E6);
background:-webkit-gradient(linear,0 0,0 100%,color-stop(0.02,#FFFFFF),color-stop(0.02,#F3F3F3),color-stop(1,#E6E6E6));
}

ul.pagination li a:hover,
ul.pagination li a.current
{
background:#FFFFFF;
}
</style>


