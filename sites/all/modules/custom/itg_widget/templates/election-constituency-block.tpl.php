<?php if (!empty($data)) : global $base_url; ?>
<?php
$jsondata = json_decode($data);
$jsondata = $jsondata->$constituency;
$top_chuck = '';
$bottom_chuck = 'hide';
if ($jsondata->live == 1) {
  $top_chuck = 'hide';
  $bottom_chuck = '';  
}
	$isWon = FALSE;
	$isSeating = FALSE;
	$wonCondidate = NULL;
	$seatingCondidate = NULL;
	$otherCondidates = Array();
	foreach($jsondata->candidate as $value){
		if ($value->win_loss == "WON" && !$isWon) {
			$isWon = TRUE;
			$wonCondidate = $value;
		} else if ($value->candidate_type == "seating"){
			$isSeating = TRUE;
			$seatingCondidate = $value;
		} else {
			$otherCondidates[] = $value;
		}		
	}	
	if ($isWon) {
		$otherCondidates[] = $seatingCondidate;
	}
  if(!$isWon && $isSeating){
		$wonCondidate = $seatingCondidate;
	}
?>

<div class="row mb-20">
    <div class="col-md-12 <?php print $top_chuck;?>" id="other-candidates-past">
			<h3 class="labels"><?php print !empty($jsondata->lbl_otherscandidate)?$jsondata->lbl_otherscandidate:'Other Candidates'?></h3>
			<div class="other-candidates-details">
			<table class="table">
				 <thead>
					 <th>Candidate name</th><th>Party</th><th>Votes</th><th>% Votes</th><th>% Change</th>
				 </thead>
				 <tbody>
             <?php foreach ($otherCondidates as $key => $candidate) {
               echo "<tr><td data-column='Candidate Name'>".$candidate->candidate."</td><td data-column='Party'>".$candidate->party."</td><td data-column='Votes'>".$candidate->votes."</td><td data-column='%Votes'>".$candidate->percentage_votes."</td><td data-column='%Change'>".$candidate->percentage_change."</td></tr>";
             }?>
				 </tbody>
			</table>
			</div>
    </div>
  </div>
<?php if(!empty($wonCondidate)) {?>
  <div class="row mb-20" id="constituency-top-chunk">
    <div class="mb-viewsection">
    <div class="col-md-6" id="candidates">
			<h3 class="labels"><?php print !empty($jsondata->lbl_candidates)?$jsondata->lbl_candidates:'Candidates'?></h3>
			<div class="text-center" id="candidates-image">
             <span class="candidates-pic"><img src="<?php echo $wonCondidate->image;?>"></span>
				<div class="candidates-name"><?php echo $wonCondidate->candidate;?></div>
			</div>
			<div class="candidates-profile">
				<table class="table">
					<tbody>
			              <tr><td>Party</td><td><?php echo $wonCondidate->party;?></td></tr>
			              <tr><td>Gender</td><td><?php echo $wonCondidate->age;?></td></tr>
			              <tr><td>Education Qualification</td><td><?php echo $wonCondidate->qualification;?></td></tr>
			              <tr><td>Profession</td><td><?php echo $wonCondidate->profession;?></td></tr>
			              <tr><td>Marital status</td><td><?php echo $wonCondidate->marital_status;?></td></tr>
			              <tr><td>Criminal Cases</td><td><?php echo $wonCondidate->criminal_cases;?></td></tr>
			              <tr><td>Assets</td><td><?php echo $wonCondidate->assets;?></td></tr>
			              <tr><td>Movable Assets</td><td><?php echo $wonCondidate->moveable_assets;?></td></tr>
			              <tr><td>Immovable Assets</td><td><?php echo $wonCondidate->immovable_assets;?></td></tr>
			              <tr><td>Income</td><td><?php echo $wonCondidate->income;?></td></tr>
			              <tr><td>Spouse Dependants</td><td><?php echo $wonCondidate->spouse_dependants;?></td></tr>	
					</tbody>
				</table>
			</div>   
    </div>
    <div class="col-md-6" id="map-of-constituency">
			<h3 class="labels">Map of Constituency</h3>
			<div class="text-center" id="candidates-svg">			
          <?php echo $jsondata->svg;?>
			</div>
			<div class="constituency-details">
				<table class="table">
					<tbody>
			             <tr><td>AC name</td><td><?php echo $constituency;?></td></tr>
			             <tr><td>AC No</td><td><?php echo $jsondata->id;?></td></tr>
			             <tr><td>No of voters</td><td><?php echo $jsondata->voters_count;?></td></tr>
			             <tr><td>Area</td><td><?php echo $jsondata->district;?></td></tr>
			             <tr><td>Sitting MLA's name</td><td><?php echo $jsondata->candidate;?></td></td></tr>
					</tbody>
				</table> 
			</div>  
    </div>
    </div>
  </div>
<?php }?>
  <div class="row mb-20">
    <div class="col-md-12 <?php print $bottom_chuck;?>" id="other-candidates">
			<h3 class="labels"><?php print !empty($jsondata->lbl_otherscandidate)?$jsondata->lbl_otherscandidate:'Other Candidates'?></h3>
			<div class="other-candidates-details">
				<table class="table" id="othercandidates-list">
					 <thead>
						 <th>Candidate name</th><th>Party</th><th>Votes</th><th>% Votes</th><th>% Change</th>
					 </thead>
					 <tbody>
	            <?php foreach ($otherCondidates as $key => $candidate) {
	              echo "<tr><td data-column='Candidate Name'>".$candidate->candidate."</td><td data-column='Party'>".$candidate->party."</td><td data-column='Votes'>".$candidate->votes."</td><td data-column='%Votes'>".$candidate->percentage_votes."</td><td data-column='%Change'>".$candidate->percentage_change."</td></tr>";
	            }?>
					 </tbody>
				</table> 
				</div>
    </div>
  </div> 
<?php endif; ?>

<script type="text/javascript">
var oRows = document.getElementById('othercandidates-list').getElementsByTagName('tr');
var iRowCount = oRows.length; iRowCount = iRowCount - 1;
var totalwidth = iRowCount*310;
document.getElementById('othercandidates-list').style.width = totalwidth +'px';
</script>