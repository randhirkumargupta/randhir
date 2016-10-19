<?php  if (!empty($data)) : global $base_url; ?>
<div>
    <div> <h2><?php echo $data->attributes()->team1sabbr.'<span>vs</span>'.$data->team2sabbr;?></h2></div>
    
</div>
<?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>
