<?php
/**
 * @file
 * Theme implementation for Cricket live Blog.
 * 
 */
foreach ($data as $key => $commentary) {
    $is_new_over = FALSE;
    if (isset($data[$key + 1]) && !empty($data[$key + 1])) {
        if ((int) $commentary->Ball >= 6 && (int) $data[$key - 1]->Over != (int) $commentary->Over) {
            $is_new_over = TRUE;
        }
    }
    if (isset($commentary->TimeOfDay)) {
        $time = date('H:i T', strtotime($commentary->TimeOfDay));
    }
    else {
        $time = '';
    }
    ?>
    <?php if (isset($commentary->Ball) && (int) $commentary->Ball >= 6 && $is_new_over): ?>
        <?php
        $_batsman = explode('|', $commentary->BatDetails);
        $batDetails = $_batsman[1] . '(' . $_batsman[2] . 'b ' . $_batsman[3] . '*4' . $_batsman[4] . '*6)';
        $_bowler = explode('|', $commentary->BowlDetails);
        $bowlDetails = $_bowler[1] . '-' . $_bowler[2] . '-' . $_bowler[3] . '-' . $_bowler[4];
        $is_new_over = FALSE;
        ?>
        <div class="para-live-blog" data-id="<?php print $key; ?>" commentary-id="<?php echo $commentary->Id; ?>" current-inn="<?php echo $commentary->innings; ?>">  
            <div class="batBollDetails">

                <span class="sectiontime">Score  <?php echo $commentary->Score; ?> </span>
                <div class="batsmanDetails">
                    <span class="sectiontime batNameSaperator">Batsman</span>
                    <span class="sectiontime float-left"><?php echo $commentary->Batsman; ?><span class='batsman_detail batRun'><?php echo $batDetails; ?></span></span>
                </div>
                <div class="bollerDetails">
                    <span class="sectiontime bollNameSaperator">Bowler</span>
                    <span class="sectiontime float-left"><?php echo $commentary->Bowler; ?><span class="bowler_detail overball"><?php echo $bowlDetails; ?></span></span>
                </div>


            </div>
        </div>
    <?php endif; ?>
    <div class="para-live-blog" data-id="<?php print $key; ?>" commentary-id="<?php echo (isset($commentary->Id) ? $commentary->Id : ''); ?>" current-inn="<?php echo (isset($commentary->innings) ? $commentary->innings : ''); ?>">
        <div>
            <p itemprop="articleBody"> <?php if (!empty($time)): ?><span><?php echo $time; ?>: </span><?php endif; ?><?php echo $commentary->Commentary; ?></p>
        </div>
    </div>
    <?php
}
?>

