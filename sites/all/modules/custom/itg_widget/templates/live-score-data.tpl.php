<?php
if (!empty($data)) : global $base_url;
  $parts = parse_url($data['match_link']);
  parse_str($parts['query'], $query);
  $match_id = $query['matchid'];

?>
<div class="live-scorecard">
    <div class="team-detail"> <h4><?php echo $data['team1sabbr'] . ' <span>vs</span> ' . $data['team2sabbr']; ?> <?php echo $data['desc']; ?></h4>
            
            <span class="match-location"><?php echo $data['venue']; ?></span>
        </div>
    <div class="score"> 
            <span class="batteam"><?php echo $data['currentscore']->batteamname; ?></span>
            <span class="batteamscore"> <?php echo $data['currentscore']->batteamruns; ?>/<?php echo $data['currentscore']->batteamwkts; ?></span>
            <span class="crrrunrate">Crr <?php echo $data['currentscore']->crr; ?>  <span class="crrrunover">(<?php echo $data['currentscore']->batteamovers; ?> Over)</span></span>           
        </div>
        <span><?php print t('Live: Commentary'); ?></span> |
            <a href="scorecard/matchcenter/<?php echo $match_id; ?>" target="_blank"><span><?php print t('Full Scorecard');?> |</span></a>
            <span><?php print t('Graphs'); ?></span>       
    </div>
<?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>
