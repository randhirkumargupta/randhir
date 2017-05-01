<?php
print $no_result;
/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
?>
<?php
$date = date("Y-m-d H:i:s");
$time = new DateTime($date);
$current_day = $time->format('Y/m/d');
$counter = 0;
$day = strtoupper(date("D"));
global $base_url;
$mon = $base_url . "/tv-show/MON";
$tue = $base_url . "/tv-show/TUE";
$wed = $base_url . "/tv-show/WED";
$thu = $base_url . "/tv-show/THU";
$fri = $base_url . "/tv-show/FRI";
$sat = $base_url . "/tv-show/SAT";
$sun = $base_url . "/tv-show/SUN";
$class = 'class="active"';
$day = strtoupper(date("D"));
$clicked_day = arg(1);
if($clicked_day == "" && empty($_GET['date_zone']))
{
   $clicked_day= $day;
}

if (!empty($_GET['date_zone']) && empty(arg(1))) {
  $get_day_date = get_tv_schedule_date($_GET['date_zone'], 'no');
  $assign_day  = $get_day_date['program'];
}
?>
<!-- Listing shows and days option -->
<div class="tv-schedule-parent">
    <ul class="no-bullet schedule-days">
        <li><a <?php if(!empty(arg(1)) && arg(1) == 'MON'){ print $class; }elseif($assign_day == 'MON'){ print $class; } elseif($day == 'MON' && $clicked_day == 'MON'){ print $class; } ?> href="<?php print $mon; ?>"><?php print t('Monday'); ?></a></li>
        <li><a <?php if(!empty(arg(1)) && arg(1) == 'TUE'){ print $class; }elseif($assign_day == 'TUE'){ print $class; } ?> href="<?php print $tue; ?>"><?php print t('Tuesday'); ?></a></li>
        <li><a <?php if(!empty(arg(1)) && arg(1) == 'WED'){ print $class; }elseif($assign_day == 'WED'){ print $class; } ?>href="<?php print $wed; ?>"><?php print t('Wednesday'); ?></a></li>
        <li><a <?php if(!empty(arg(1)) && arg(1) == 'THU'){ print $class; }elseif($assign_day == 'THU'){ print $class; } ?>href="<?php print $thu; ?>"><?php print t('Thursday'); ?></a></li>
        <li><a <?php if(!empty(arg(1)) && arg(1) == 'FRI'){ print $class; }elseif($assign_day == 'FRI'){ print $class; } ?>href="<?php print $fri; ?>"><?php print t('Friday'); ?></a></li>
        <li><a <?php if(!empty(arg(1)) && arg(1) == 'SAT'){ print $class; }elseif($assign_day == 'SAT'){ print $class; } ?>href="<?php print $sat; ?>"><?php print t('Saturday'); ?></a></li>
        <li><a <?php if(!empty(arg(1)) && arg(1) == 'SUN'){ print $class; }elseif($assign_day == 'SUN'){ print $class; } ?>href="<?php print $sun; ?>"><?php print t('Sunday'); ?></a></li>
    </ul>
    <!-- Showing Search box and time zone drop down list -->
     
    <div class="tv-schedule-form-wrapper">
       <div class="tv-schedule-date-text"><?php print render(drupal_get_form('itg_tv_schedule_date_form')); ?></div>
        <div class="fleft choose-time"><?php print render(drupal_get_form('itg_tv_schedule_time_form')); ?></div>
    <?php print render(drupal_get_form('itg_tv_schedule_search_form')); ?>
    </div>
    
    <div class="tv-schedule-slide-wrapper">
    <!-- Shows time in slider upper part -->
    <div class="tv-schedule tv-schedule-time slider" style="margin-bottom: 30px;">
        <?php foreach ($output as $val): ?>

            <div>
                <span><?php print $val['time']; ?></span>   
            </div>    

        <?php endforeach; ?>
    </div>
    <!-- Shows program name in slider middle part -->
    <div class="tv-schedule tv-schedule-news slider">
        <?php foreach ($output as $val): ?>
            <div class="tv-schedule-task"> 
                <span><?php
                    if ($total == $counter && $day == $val['day'] && $current_day == $val['program date']) {
                        echo '<a href = "http://indiatoday.intoday.in/livetv.jsp">' . ucfirst($val['program']) . '</a>';
                        //print $val['program'];
                    }
                    else {
                        print ucfirst($val['program']);
                        print '<br/>';
                        if(!empty($val['story_attach'])) {
                        print ucfirst($val['story_attach']);
                        }
                    } $counter++;
                    ?></span>   
            </div>    
        <?php endforeach; ?>
    </div>
    <!-- Shows time in slider lower part -->
    <div class="tv-schedule tv-schedule-time slider" style="margin-top: 30px;">
        <?php foreach ($output as $val): ?>
            <div>
                <span><?php print $val['time']; ?></span>    
            </div>    
        <?php endforeach; ?>
    </div>
    </div>
</div>

<!-- Search result pop -->

<?php if (isset($title)): ?>
    <div  id="tv-search-popup" class="itg-popup" style="display: block;">
        <div class="popup-data">
            <div class="popup-header">
                <h2>Search Results <span style='font-size: 14px;'>(<?php  print $search_count.' results for '.$title; ?>)</span></h2>
                <a class="itg-close-popup" href="javascript:;"> Close </a>
            </div>
            <div class="popup-body">
                <table class="views-table">
                     <tr>
                         <td><b><?php print 'Schedule Time'; ?></b></td>
                         <td><b><?php print 'Days'; ?></b></td>
                         <td><b><?php print 'Program Name'; ?></b></td>
                         <td><b><?php print 'Program Date'; ?></b></td>
                       </tr>
                    <tbody>
                        <?php foreach ($search as $val1): ?>  
                        <?php $days_array = array('sun' => 'Sunday', 'mon' => 'Monday', 'tue' => 'Tuesday', 'wed' => 'Wednesday', 'thu' => 'Thursday', 'fri' => 'Friday', 'sat' => 'Saturday'); ?>  
                            <tr>
                                <td><?php print $val1['time'].' (IST)'; ?></td>
                                <td><?php print $days_array[strtolower($val1['day'])]; ?></td>
                                <td><?php print ucfirst($val1['program']); ?></td>
                                <td><?php print ucfirst($val1['program date']); ?></td>
                            </tr>

                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
    </div>

<?php endif; ?>





<style type="text/css">
    .slider{width: 820px;margin: 0  35px 0 auto;}
    .tv-schedule-parent {
        background-color: #3e4651;
        border-radius: 10px;
        margin: 0 auto;
        max-width: 1000px;
        padding: 10px;
    }
    .choose-time{position: relative; z-index: 999;}
    .tv-schedule{max-width: 820px;}
    .tv-schedule .slick-list{display: inline-block; width: 100%; vertical-align: top;}
    .tv-schedule-time{background-color: #008eb1; color: #fff; font-size: 14px; height: 34px; line-height: 12px; border: none;}
    .tv-schedule-time .slick-slide span{display: block; padding: 10px; text-align: center; border: none;}
    .tv-schedule .slick-arrow{position: absolute; top: 0; bottom: 0; margin: auto 10px; width: 0; height: 0; border: 10px solid; background: none; font-size: 0; cursor: pointer;}
    .tv-schedule .slick-prev{right: 100%; border-color: transparent #d9d9d9 transparent transparent;}
    .tv-schedule .slick-next{left: 100%; border-color: transparent transparent transparent #d9d9d9;}
    .tv-schedule-news .slick-slide span{display: block;}
    .tv-schedule-news{border: none; border-radius: 0 10px 10px 0; background: linear-gradient(#414D57, #293137);box-shadow: 0 0 3px #2f2f2f;}
    .tv-schedule-news .tv-schedule-task span{color: #fff; padding: 10px; border: none; overflow: hidden; height: 100px; font-size: 16px; font-weight: 500; position: relative;}
    .tv-schedule-news .tv-schedule-task{position: relative;}
    .tv-schedule-news .tv-schedule-task:after{content: ''; background-color: rgba(37,42,50,1); width: 1px; height: 100%; left: 100%; top: 0; bottom: 0; margin: auto; position: absolute;}
    .tv-schedule-news .tv-schedule-task span a{color: #008eb1; text-decoration: none;}
    .schedule-days{text-align: center; background-color: #37414f; border-radius: 10px; box-shadow: 0 0 3px #2f2f2f;}
    .schedule-days li{display: inline-block; vertical-align: top; color: #008eb1;}
    .schedule-days li a{display: block; color: #008eb1; text-decoration: none; padding: 10px 30px;}
    .schedule-days li a:hover, .schedule-days li a.active{color: #fff;}
    #itg-tv-schedule-search-form{padding: 20px 0;}
    #itg-tv-schedule-time-form .form-type-select{float: left;padding: 20px 0;}
    #itg-tv-schedule-time-form .form-submit{display: none;}
    #itg-tv-schedule-time-form .form-select{width: 200px;background-color: #252a32; border: 1px solid #252a32; color: #fff; border-radius: 5px;}
    #itg-tv-schedule-search-form > div{text-align: right; position: relative;}
    #itg-tv-schedule-search-form .form-submit{
        background: url('<?php print $base_url; ?>/sites/all/themes/itg/images/search.png') center center no-repeat #252a32; 
        border: medium none;
        border-radius: 0 5px 5px 0;
        box-shadow: 0 0 3px #000 inset;
        height: 32px;
        position: absolute;
        right: 0;
        text-indent: -9999px;
        top: 0;
        width: 40px;
        cursor: pointer;
    }
    #itg-tv-schedule-search-form .form-text{max-width: 332px; background-color: #252a32; border: 1px solid #252a32; color: #fff; border-radius: 5px;}
    .tv-schedule-time .slick-slide{position: relative; height: 34px;}
    .tv-schedule-time .slick-slide:after{content: ''; background-color: rgba(37,42,50,.5); width: 1px; height: 100%; left: 100%; top: 0; bottom: 0; margin: auto; position: absolute;}
    .tv_schedule {
    max-width: 1000px;
    margin: 0 auto 10px;
    }
    .itg-popup{
        display: none;
        background-color: rgba(0, 0, 0, 0.5);
        height: 100%;
        left: 0;
        position: fixed;
        top: 0;
        width: 100%;
        z-index: 99999;
        
    }
    .popup-data{
        width: 800px;
        border-radius: 5px;
        box-shadow: 0 0 10px #000;
        background-color: #fff;
        position: absolute;
        left: 0;
        top: 0;
        right: 0;
        bottom: 0;
        margin: auto;
        max-height: 440px;
    }
    .popup-body{
        max-height: 360px;
        overflow-y: auto;
        padding: 20px;
    }
    .popup-header{
        position: relative;
        padding: 20px;
        border-bottom: 1px solid #d9d9d9;
    }
    .itg-close-popup{
        position: absolute;
        right: 5px;
        top: 5px;
        width: 30px;
        height: 30px;
        border-radius: 50%;
        border: 1px solid #d00b26;
        background: url('<?php print $base_url; ?>/sites/all/themes/itg/images/cross_small.png') center center no-repeat #fff;
        text-indent: -9999px;
    }
    .views-table{
        width: 100%;
        border-collapse: collapse;
        border: 1px solid #d9d9d9;
        text-align: left;

    }
    .views-table th, .views-table td{
        padding: 8px 5px;
        max-width: 200px;
        border: 1px solid #d9d9d9;
    }
    .views-table thead{background-color: #f6f6f6;}
    .views-table th{font-weight: 500;}
    .views-table th a, .views-table td a{
        color: #0c8bb1;
    }
    .tv-schedule-news button{display: none !important;}
    .tv-schedule .slick-next, .tv-schedule .slick-prev{z-index: 9999;}
    .tv-schedule-slide-wrapper{
        padding: 10px;
        background-color: #2B333A;
        border-radius: 7px;
        box-shadow: 0 1px 0 1px #1e1e1e inset;
    }
    .tv-schedule-time{position: relative;}
    .tv-schedule-time:before{
        content: '';
        position: absolute;
        width: 34px;
        height: 34px;
        top: 0;
        left: -34px;
        background-color: #008eb1;
        border-radius: 5px 0 0 5px;
    }
    .tv-schedule-time:after{
        content: '';
        position: absolute;
        width: 34px;
        height: 34px;
        top: 0;
        right: -34px;
        background-color: #008eb1;
        border-radius: 0 5px 5px 0;
        border-left: 1px solid rgba(37,42,50,.5);
    }
    .tv-schedule-news:before{
        content:'';
        background: url('<?php print $base_url; ?>/sites/all/themes/itg/images/itg_group.jpg') 0 0 / 100% auto no-repeat;
        width: 100px;
        height: 100px;
        position: absolute;
        left: -100px;
        top: 0;
        z-index: 9999;
        box-shadow: 0 0 3px #000;
        border-radius: 5px 0 0 5px;
    }
    .tv-schedule-date-text{
        float: left;
        width: 200px;
        position: relative;
        z-index: 9;
    }
    .tv-schedule-date-text .form-item{
        margin: 0;
    }
    .tv-schedule-date-text .form-item label, 
    .tv-schedule-date-text .form-item .description, 
    .tv-schedule-date-text #edit-submit{
        display: none;
    }
    .tv-schedule-date-text .form-text{
            margin: 20px 20px 0 0;
            width: 180px !important;
            background-color: #252a32;
            border: 1px solid #252a32;
            color: #fff;
            border-radius: 5px;
            padding-left: 42px;
            background: url('<?php print $base_url; ?>/sites/all/themes/itg/images/date-icon.png') left 10px top 2px / 24px auto no-repeat;
    }
    .messages--error{
        background: #fefafb none repeat scroll 0 0;
        border: 1px solid red;
        padding: 10px 30px;
        margin: 20px auto;
        max-width: 1000px;
    }
    .messages__list{padding-left: 13px;}
    #ui-datepicker-div{z-index: 99999 !important;}
</style>
<script type="text/javascript">
    
    var current_time_slot = <?php if($total > 0){print $total;} else{ print 0;} ?>;
    jQuery(document).on('ready', function() {
        jQuery(".tv-schedule").slick({
            dots: false,
            infinite: false,
            slidesToShow: 7,
            slidesToScroll: 1,
            draggable: false,
            initialSlide: current_time_slot,
            asNavFor: '.tv-schedule'
        });


        jQuery('body').on('click', '.itg-close-popup', function() {
            jQuery(this).parent().parent().parent().hide();
            window.location.href =  window.location.href.split("?")[0];
        });

    });
</script>
