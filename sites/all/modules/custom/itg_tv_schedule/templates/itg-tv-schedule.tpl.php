<?php

/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
?>
<?php
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
?>
<!-- Listing shows and days option -->
<div class="tv-schedule-parent">
    <ul class="no-bullet schedule-days">
        <li><a <?php if(arg(1) == 'MON'){ print $class; }elseif($day == 'MON'){ print $class; } ?> href="<?php print $mon; ?>"><?php print t('Monday'); ?></a></li>
        <li><a <?php if(arg(1) == 'TUE'){ print $class; }elseif($day == 'TUE'){ print $class; } ?> href="<?php print $tue; ?>"><?php print t('Tuesday'); ?></a></li>
        <li><a <?php if(arg(1) == 'WED'){ print $class; }elseif($day == 'WED'){ print $class; } ?>href="<?php print $wed; ?>"><?php print t('Wednesday'); ?></a></li>
        <li><a <?php if(arg(1) == 'THU'){ print $class; }elseif($day == 'THU'){ print $class; } ?>href="<?php print $thu; ?>"><?php print t('Thursday'); ?></a></li>
        <li><a <?php if(arg(1) == 'FRI'){ print $class; }elseif($day == 'FRI'){ print $class; } ?>href="<?php print $fri; ?>"><?php print t('Friday'); ?></a></li>
        <li><a <?php if(arg(1) == 'SAT'){ print $class; }elseif($day == 'SAT'){ print $class; } ?>href="<?php print $sat; ?>"><?php print t('Saturday'); ?></a></li>
        <li><a <?php if(arg(1) == 'SUN'){ print $class; }elseif($day == 'SUN'){ print $class; } ?>href="<?php print $sun; ?>"><?php print t('Sunday'); ?></a></li>
    </ul>
    <!-- Showing Search box and time zone drop down list -->
    <div class="tv-schedule-form-wrapper">
        <div class="fleft"><?php print render(drupal_get_form('itg_tv_schedule_time_form')); ?></div>
    <?php print render(drupal_get_form('itg_tv_schedule_search_form')); ?>
    </div>
    <!-- Shows time in slider upper part -->
    <div class="tv-schedule tv-schedule-time slider">
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
                    if ($total == $counter && $day == $val['day']) {
                        echo '<a href = "http://indiatoday.intoday.in/livetv.jsp">' . $val['program'] . '</a>';
                        //print $val['program'];
                    }
                    else {
                        print $val['program'];
                    } $counter++;
                    ?></span>   
            </div>    
        <?php endforeach; ?>
    </div>
    <!-- Shows time in slider lower part -->
    <div class="tv-schedule tv-schedule-time slider">
        <?php foreach ($output as $val): ?>
            <div>
                <span><?php print $val['time']; ?></span>    
            </div>    
        <?php endforeach; ?>
    </div>
</div>

<!-- Search result pop -->

<?php if (isset($search)): ?>
    <div  id="tv-search-popup" class="itg-popup" style="display: block;">
        <div class="popup-data">
            <div class="popup-header">
                <h2>Search Result</h2>
                <a class="itg-close-popup" href="javascript:;"> Close </a>
            </div>
            <div class="popup-body">
                <table class="views-table">
                    <tbody>
                        <?php foreach ($search as $val1): ?>  

                            <tr>
                                <td><?php print $val1['time']; ?></td>
                                <td><?php print $val1['program']; ?></td>
                                <td><?php print $val1['day']; ?></td>
                            </tr>

                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
    </div>

<?php endif; ?>





<style type="text/css">
    .slider{width: 1000px;margin: 20px auto;}
    .slider{width: 820px;margin: 0 auto;}
    .tv-schedule{max-width: 820px;}
    .tv-schedule .slick-list{display: inline-block; width: 100%; vertical-align: top;}
    .tv-schedule-time .slick-slide span{display: block; padding: 10px; text-align: center;border-left: 1px solid #d9d9d9;}
    .tv-schedule-time .slick-slide:first-child span{border-left: none;}
    .tv-schedule-time{border: 1px solid #d9d9d9;}
    .tv-schedule .slick-arrow{position: absolute; top: 0; bottom: 0; margin: auto 10px; width: 0; height: 0; border: 10px solid; background: none; font-size: 0; cursor: pointer;}
    .tv-schedule .slick-prev{right: 100%; border-color: transparent #d9d9d9 transparent transparent;}
    .tv-schedule .slick-next{left: 100%; border-color: transparent transparent transparent #d9d9d9;}
    .tv-schedule-news .slick-slide span{display: block;}
    .tv-schedule-news{border: 1px solid #d9d9d9;}
    .tv-schedule-news .tv-schedule-task span{padding: 10px; border: 1px solid #d9d9d9; overflow: hidden; height: 100px;}
    .schedule-days{text-align: center;}
    .schedule-days li{display: inline-block; vertical-align: top; color: #008eb1;}
    .schedule-days li a{background-color: #d9d9d9; display: block; color: #008eb1; text-decoration: none; padding: 5px 30px;}
    .schedule-days li a:hover, .schedule-days li a.active{color: #fff;background-color: #008eb1;}
    .tv-schedule-form-wrapper{max-width: 810px; margin: 0 auto;}
    #itg-tv-schedule-search-form{padding: 20px 0;}
    #itg-tv-schedule-time-form .form-type-select{float: left;padding: 20px 0;}
    #itg-tv-schedule-time-form .form-submit{display: none;}
    #itg-tv-schedule-time-form .form-select{width: 200px;}
    #itg-tv-schedule-search-form > div{max-width: 820px; margin: 0 auto; text-align: right;}
    #itg-tv-schedule-search-form .form-submit{display: none;}
    #itg-tv-schedule-search-form .form-text{max-width: 332px;}
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
</style>
<script type="text/javascript">
    var current_time_slot = <?php print $total; ?>;
    jQuery(document).on('ready', function() {
        jQuery(".tv-schedule").slick({
            dots: false,
            infinite: true,
            slidesToShow: 7,
            slidesToScroll: 1,
            initialSlide: current_time_slot,
            asNavFor: '.tv-schedule'
        });


        jQuery('body').on('click', '.itg-close-popup', function() {
            jQuery(this).parent().parent().parent().hide();
        });

    });
</script>
