<div class="program-sub-title">Program Schedule</div>
<div class="row">
<?php foreach ($rows as $index => $row): ?>
<div class="col-md-6">
    <div class="content-list">
    <?php print $row['field_start_time']; ?>
        <div class="story-expert-name"> <?php print $row['field_story_expert_name']; ?></div>
    <?php //print $row['field_daywise_event']; ?>
              
     <?php //print $row['title']; ?>
   <?php print $row['view']; ?>
   
  </div>
</div>    
<?php endforeach; ?>
</div>