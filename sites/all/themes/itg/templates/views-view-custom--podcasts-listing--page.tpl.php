<?php
/**
 * @file
 * Default view for podcast laisting page for fornt user.
 *
 * @ingroup views_templates
 */
global $base_url;
?>
<?php foreach ($rows as $index => $row): ?>
<div class="podcast-container-<?php print $index ?> catagory-listing">
  <div class="podcast-left pic">
      <?php 
       if($row['field_story_extra_large_image'] == 'notFound') {
         print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' alt='' title='' />";
       } 
       else  {
          $doc = new DOMDocument();
          $doc->loadHTML($row['field_story_extra_large_image']);
          $xpath = new DOMXPath($doc);
          $src = $xpath->evaluate("string(//img/@src)");
         
         if(function_exists('url_exists') && url_exists($src)) {
           print $row['field_story_extra_large_image'];
         } else {
           print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' alt='' title='' />";
         }
       }
      ?>    
      <span><i id="demo-<?php echo $row['nid'] ?>" class="fa fa-volume-up" aria-hidden="true"></i>
          <audio class="hide" id="myAudio-<?php echo $row['nid'] ?>" controls>
        <source src="<?php print _get_audio_file_url($row['nid']); ?>" type="audio/mpeg">
        Your browser does not support the audio element.
      </audio>
      </span>
  </div>
  <div class="podcast-right detail">    
      <h3 title="<?php print strip_tags($row['title']) ; ?>"><?php print html_entity_decode($row['title']); ?></h3>
      <p><?php print $row['field_podcast_kicker_message']; ?></p>      
    </div>    
  </div>
<?php endforeach; ?>
<script>
  jQuery(window).load(function(){
   <?php foreach ($rows as $index => $row): ?>
        var audio_duration = parseInt(document.getElementById("myAudio-<?php echo $row['nid'] ?>").duration);
      var minutes = parseInt(audio_duration / 60, 10);
      var seconds = parseInt(audio_duration % 60);
      //console.log(audio);
        document.getElementById("demo-<?php echo $row['nid'] ?>").innerHTML = "&nbsp;" + minutes + ":" + seconds;
   <?php endforeach;?>
  });
</script>

