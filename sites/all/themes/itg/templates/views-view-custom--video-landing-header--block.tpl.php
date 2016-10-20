<?php foreach ($rows as $row): ?>
  <div class="container">
    <div class ="video-landing-header">
      <div class="row">
        <div class="col-md-12">
          <h2><?php print $row['title']; ?></h2>
        </div>
        <div class="col-md-8 video-header-left">
          <div class="video"><?php
            if (module_exists('itg_videogallery')) {
              $vid = itg_videogallery_get_videoid($row['fid']);
            }
            ?>
            <div class="iframe-video">
              <iframe frameborder="0"
                      src="https://www.dailymotion.com/embed/video/<?php print $vid; ?>?autoplay=0&mute=1&ui-start-screen-info"
                      allowfullscreen></iframe></div></div>
          <div class="social-likes">
            <ul>
              <li><a href="#"><i class="fa fa-heart"></i> <span>585</span></a></li>
              <li><?php print $row['ops']; ?></li>
              <li><a href="#"><i class="fa fa-facebook"></i> <span>Share</span></a></li>
              <li><a href="#"><i class="fa fa-twitter"></i> <span>Twitter</span></a></li>
              <li><a href="#"><i class="fa fa-envelope"></i> <span>Email</span></a></li>
              <li class="mhide"><a href="#"><i class="fa fa-link"></i> <span>Embed</span></a></li>
              <li><a href="#"><i class="fa fa-comment"></i> <span>Comment</span></a></li>
              <li class="mhide"><a href="#"><i class="fa fa-share"></i> <span>Submit Video</span></a></li>
            </ul>
          </div>
        </div>
        <div class="col-md-4 video-header-right"><p><?php print $row['field_story_expert_description']; ?></p>
          <p class="upload-date"><?php print $row['timestamp']; ?></p>
          <div class="ads mhide"></div>
        </div>
      </div>
    </div>
  </div>
<?php endforeach; ?>
