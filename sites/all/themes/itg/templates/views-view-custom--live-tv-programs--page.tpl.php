<h3><span><?php print t('Show videos'); ?></span></h3>
<?php
$episodes_text = '';
global $base_url;
$current_time_program_tid = itg_live_tv_page_video_category();
?>
<div class="programe-container">
  <?php
  foreach ($rows as $row) :
    if (function_exists('itg_category_manager_term_state')) {
      $status = itg_category_manager_term_state($row['tid']);
    }
    else {
      $status = 0;
    }
    if ($status) {
      $view = views_get_view('programme_content');
      $args = array($row['tid']);
      $view->preview('block', $args);
      $view_result = $view->result;
      $recent_video_under_cat = $view_result[0]->nid;
      if ($current_time_program_tid != $row['tid']) {
        ?>
        <div class="program-row">               
          <div class="program-right">
            <?php if (isset($row['field_cm_display_title'])) : ?>
              <div class="programe-title">
                <?php print l($row['field_cm_display_title'], 'node/' . $recent_video_under_cat, array('query' => array('category' => $row['tid']), 'html' => TRUE)); ?>
              </div>
            <?php endif; ?>
          </div>

          <div class="toggle-icon">
            <span class="plus"><i class="fa fa-plus-circle"></i></span>
            <span class="minus"><i class="fa fa-minus-circle"></i></span>
          </div>

        </div>
        <div class="program_data"><?php print views_embed_view('programme_content_live_tv', 'block', $row['tid']); ?></div>
      <?php }
    } endforeach; ?>
</div>

<?php
drupal_add_css(drupal_get_path('theme', 'itg') . '/css/jquery.mCustomScrollbar.min.css', array('scope' => 'footer'));
drupal_add_js(drupal_get_path('theme', 'itg') . '/js/jquery.mCustomScrollbar.concat.min.js', array('scope' => 'footer'));

drupal_add_js('jQuery(document).ready(function(){
        var programData = ".view-live-tv-programs .program_data";
        var iconMinus = ".toggle-icon .minus";
        var iconPluse = ".toggle-icon .plus";
        if(jQuery(programData).is(":visible")){
            jQuery(iconMinus).show();
        }else{
            jQuery(iconPluse).show();
        }        
        jQuery(".toggle-icon").click(function(){   
            var programRow = jQuery(this).parents(".program-row").next();            
            if(programRow.is(":visible")){                
               programRow.slideUp();
               jQuery(this).find(".minus").hide();
               jQuery(this).find(".plus").show();
            }else{
               programRow.slideDown();
               jQuery(this).find(".minus").show();
               jQuery(this).find(".plus").hide();
            }            
        });
  
        var winWidth = window.innerWidth;
        if(winWidth > 680){
          var getLength = jQuery(".view-programme-content-live-tv .defalt-bar .photo-list li").length;    
          jQuery(".view-programme-content-live-tv .defalt-bar .photo-list").css("width", getLength*190 +"px");                
              jQuery(".view-programme-content-live-tv .defalt-bar").mCustomScrollbar({
              axis:"x",                    
          });                       
        }else{
            jQuery(".view-programme-content-live-tv .defalt-bar .photo-list").slick({
                vertical: true,
                slidesToShow: 2,
                dots: false,
                nextArrow:"<i class=\'fa fa-chevron-down\'></i>",
                prevArrow:"<i class=\'fa fa-chevron-up\'></i>"                    
            });
        }
    });', array('type' => 'inline', 'scope' => 'footer'));
?>
