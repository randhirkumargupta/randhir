<h3><span><?php print t("Other podcast") ?></span></h3>
<ul class="photo-list">    
<?php foreach ($rows as $index => $row): ?>
    <li class="col-md-3 col-sm-3 col-xs-6">
        <div class="tile">
            <?php if(!empty($row['field_story_extra_large_image'])) : ?>
            <figure>                
                <?php print $row['field_story_extra_large_image'] ?>    
                    <figcaption><i class="fa fa-volume-up" aria-hidden="true" id="demo-<?php echo $row['nid'] ?>"></i></figcaption>
                    <audio class="hide" id="myAudio-<?php echo $row['nid'] ?>" controls>
                      <source src="<?php print _get_audio_file_url($row['nid']); ?>" type="audio/mpeg">
                      Your browser does not support the audio element.
                    </audio>
                <?php endif;?>
            </figure>
            <?php if(!empty($row['created'])) : ?>
            <span class="posted-on"><?php print $row['created'] ?></span>        
            <?php endif;?>
             <?php if(!empty($row['title'])) : ?>
        <?php print $row['title'] ?>
    <?php endif;?>

        </div>
    </li>    

<?php endforeach; ?>
</ul>
<script>
  jQuery(window).load(function(){
   <?php foreach ($rows as $index => $row): ?>
        var audio_duration = parseInt(document.getElementById("myAudio-<?php echo $row['nid'] ?>").duration);
      var minutes = parseInt(audio_duration / 60, 10);
      var seconds = parseInt(audio_duration % 60);
        document.getElementById("demo-<?php echo $row['nid'] ?>").innerHTML = "&nbsp;" + minutes + ":" + seconds;
   <?php endforeach;?>
  });
</script>