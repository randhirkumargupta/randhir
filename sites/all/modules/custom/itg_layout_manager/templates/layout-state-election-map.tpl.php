<?php 
$itg_election_home_content_id = get_itg_variable('itg_election_home_content_id');
$story_title = get_first_story_title_by_tid($itg_election_home_content_id);
?>
<div class="state-election-map-wrapper">
<div class="full_state_graph">
	<div class="breadMap"><div class="breadMapLink"><?php echo $state_name;?> Detailed Result</div><div class="kikerNewsRightSec"><b> How to use:</b><ul><li><span>Click on the constituencies to get their result, or search by constituency name.</span></li><li><span>Use the + and - buttons (bottom right corner) to zoom in and zoom out. </span></li><li><span>Click on the home icon (bottom right) any time to return to the default view.</span></li></ul></div></div>
	<iframe src="<?php echo $map_data;?>" frameborder="0" style="overflow:hidden;height:100%;width:100%;" height="100%" width="100%" > </iframe>
</div>
</div>
  
