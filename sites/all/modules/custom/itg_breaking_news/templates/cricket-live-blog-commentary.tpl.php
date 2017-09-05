
<style>
#cricketblog .bolg-content .row{
	padding: 15px 0;
    border-bottom: 1px solid #E4E4E4;
    position: relative;
}
#cricketblog h2 {
    font: 300 16px/20px roboto;
    color: #767676;
    margin-bottom: 15px;
}
#cricketblog .batBollDetails {
    border: 1px solid #ccc;
    margin-top: 10px;
    box-sizing: border-box;
    padding: 10px 20px;
    background: #d00b26;
    height: 109px;
}

#cricketblog .bolg-content .row span.sectiontime {
    display: inline-block;
    width: 50%;
}
#cricketblog .bolg-content .row span.sectiontime {
    color: #fff!Important;
}
#cricketblog .bolg-content .row span.sectiontime {
    font-size: 14px;
    color: #111;
    display: block;
    line-height: 17px;
    font-style: normal;
    margin-bottom: 5px;
    font-weight: 500;
}
.float-left{
	float:left;
}
</style>
<?php
/**
 * @file
 * Theme implementation for Cricket live Blog.
 * 
 */
$innings = array_reverse($data->Match->Innings);
foreach($innings as $inning){
	$nodes = array_reverse($inning->Node);
	foreach($nodes as $commentary){
		$time = date('H:i T', strtotime($commentary->TimeOfDay));
		?>
		<?php if($commentary->Ball == 6):?>
		<?php 
			$_batsman = explode('|', $commentary->BatDetails);
			$batDetails = $_batsman[1] . '('. $_batsman[2] . 'b '. $_batsman[3] . '*4' . $_batsman[4] .'*6)';
			$_bowler = explode('|', $commentary->BowlDetails);
			$bowlDetails = $_bowler[1] . '-'. $_bowler[2] . '-'. $_bowler[3] . '-' . $_bowler[4];
		?>
			<div class="row">  
			<div class="batBollDetails">
				
					<span class="sectiontime">Score  <?php echo $commentary->Score;?> </span>
					<br>
					<span class="sectiontime float-left">Batsman</span><span class="sectiontime float-left">Bowler</span>
					<span class="sectiontime float-left"><?php echo $commentary->Batsman;?><span class='batsman_detail'><?php echo $batDetails;?></span></span><span class="sectiontime float-left"><?php echo $commentary->Bowler;?><span class="bowler_detail"><?php echo $bowlDetails;?></span></span>
			</div>
			</div>
		<?php endif;?>
		<div class="row">
		  <div>
		   <p itemprop="articleBody"><strong><?php echo $time; ?>: </strong><?php echo $commentary->Commentary;?></p>
		  </div>
		</div>
		<?php
	}
}
?>

