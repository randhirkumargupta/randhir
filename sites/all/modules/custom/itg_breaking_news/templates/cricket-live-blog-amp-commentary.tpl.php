<?php
/**
 * @file
 * Theme implementation for Cricket live Blog.
 * 
 */
$last_ball = -1;
$current_date_time = date("Y-m-dTH:i:s");   
foreach ($data as $key => $commentary) {
    if($commentary->Commentary == null || empty($commentary->Commentary)){
        continue;
    }
    $counter = 0;
    if($commentary->Commentary != null && count($commentary->Commentary) > 0 && strpos($commentary->Commentary,".6:")) {
            $finalBall = 6;
    } else {
            $finalBall = 0;
    }
    if (isset($data[$key])) {
        $over = $data[$key]->Over;
    }
    if (isset($commentary->TimeOfDay)) {
        $time = date('H:i T', strtotime($commentary->TimeOfDay));
    }
    else {
        $time = '';
    }
    
    ?>    
    <?php if ($finalBall == 6 && (int)$last_ball != (int)$over): ?>
        <?php
        $_batsman = explode('|', $commentary->BatDetails);
        $batDetails = $_batsman[1] . '(' . $_batsman[2] . 'b ' . $_batsman[3] . '*4 ' . $_batsman[4] . '*6)';
        $_bowler = explode('|', $commentary->BowlDetails);
        $bowlDetails = $_bowler[1] . '-' . $_bowler[2] . '-' . $_bowler[3] . '-' . $_bowler[4];
        $sort_timestamp = strtotime($commentary->TimeOfDay);
        $over_sort_time = $sort_timestamp+1;
        ?>
        <div class="para-live-blog" id="<?php print 'over_'.$over.'_'.$commentary->Id; ?>" data-sort-time="<?php print $over_sort_time; ?>">  
            <div class="batBollDetails">

                <span class="sectiontime">Score  <?php echo $commentary->Score; ?> </span>
                <div class="batsmanDetails">
                    <span class="sectiontime batNameSaperator">Batsman</span>
                    <span class="sectiontime float-left"><?php echo $commentary->Batsman; ?><span class='batsman_detail batRun'><?php echo $batDetails; ?></span></span>
                </div>
                <div class="bollerDetails">
                    <span class="sectiontime bollNameSaperator">Bowler</span>
                    <span class="sectiontime float-left"><?php echo $commentary->Bowler; ?><span class="bowler_detail overball">&nbsp;<?php echo $bowlDetails; ?></span></span>
                </div>


            </div>
        </div>
    <?php endif; ?>  
    <div class="para-live-blog" id="<?php print $commentary->Id; ?>" data-sort-time="<?php print strtotime($commentary->TimeOfDay); ?>" data-update-time="<?php print $current_date_time; ?>">
        <div>
            <p itemprop="articleBody"> <?php if (!empty($time)): ?><span><?php echo $time; ?>: </span><?php endif; ?><?php echo $commentary->Commentary; ?></p>
        </div>
    </div>  
    <?php
    $last_ball = $over;    
}
?>

