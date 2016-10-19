<?php
if (!empty($data)) : global $base_url; ?>
    <div>
        <div> <h2><?php echo $data['team1sabbr'] . '<span>vs</span>' . $data['team2sabbr']; ?></h2>
            <span><?php echo $data['desc']; ?></span>
            <span class="match-location"><?php echo $data['venue']; ?></span>
        </div>
        <div> 
            <span class="batteam"><?php echo $data['currentscore']->batteamname; ?></span>
            <span class="batteamscore"> <?php echo $data['currentscore']->batteamruns; ?>/<?php echo $data['currentscore']->batteamwkts; ?></span>
            <span class="crrrunrate">Crr <?php echo $data['currentscore']->crr; ?></span>
            <span class="crrrunover">(<?php echo $data['currentscore']->batteamovers; ?> Over)</span>
        </div>
        <span>Live:Commentary</span> |
            <span>Full Scoredcard</span>
            <span>Graphs</span>
        <div>
            
            
        </div>
    </div>
<?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>
