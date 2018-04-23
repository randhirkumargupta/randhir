<?php 
$itg_election_home_content_id = get_itg_variable('itg_election_home_content_id');
$story_title = get_first_story_title_by_tid($itg_election_home_content_id);
?>
<div class="state-election-map-wrapper">
<div class="full_state_graph">
	<div class="breadMap"><div class="breadMapLink"><?php echo $state_name;?> Detailed Result</div><style>
.breadMap .breadMapLink {font-size: 29px;color: #000;padding-bottom: 10px;}
.kikerNewsRightSec { width:100%}
.kikerNewsRightSec b { margin:5px 0; display:inline-block}
.kikerNewsRightSec ul {list-style-type: disc;color: #c00;margin-left: 20px;}
.kikerNewsRightSec li {font: 400 13px/22px Roboto,sans-serif;}
.kikerNewsRightSec li span { color:#000}
.mapright-tally #keycondidates { border:0px;}
.mapright-tally #keycondidates iframe { box-shadow:0px !important;}

.state-election-map-wrapper{height: 800px;}
.full_state_graph{height: 100%;}
</style><div class="kikerNewsRightSec"><b> How to use:</b><ul><li><span>Click on the constituencies to get their result, or search by constituency name.</span></li><li><span>Use the + and - buttons (bottom right corner) to zoom in and zoom out. </span></li><li><span>Click on the home icon (bottom right) any time to return to the default view.</span></li></ul></div></div>
	<iframe src="<?php echo $map_data;?>" frameborder="0" style="overflow:hidden;height:100%;width:100%;" height="100%" width="100%" > </iframe>
</div>
</div>
  
