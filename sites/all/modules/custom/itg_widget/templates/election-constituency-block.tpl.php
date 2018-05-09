<?php if (!empty($data)) : global $base_url; ?>
<?php
$jsondata = json_decode($data);
$jsondata = $jsondata->$constituency;
$top_chuck = '';
$bottom_chuck = 'hide';
if ($jsondata->live != 1) {
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
  $condidate_lebels = $jsondata->label;
?>

<div class="row mb-20">
    <div class="col-md-12 <?php print $top_chuck;?>" id="other-candidates-past">
			<h3 class="labels"><?php print !empty($jsondata->lbl_otherscandidate)?$jsondata->lbl_otherscandidate:'Other Candidates'?></h3>
			<div class="other-candidates-details">
			<table class="table" id="othercandidates-list">
				 <thead>
					 <th><?php echo (!empty($condidate_lebels->candidate_name) ? $condidate_lebels->candidate_name : 'CANDIDATE NAME');?></th><th><?php echo (!empty($condidate_lebels->party) ? $condidate_lebels->party : 'PARTY');?></th><th><?php echo (!empty($condidate_lebels->status) ? $condidate_lebels->status : 'STATUS');?></th>
				 </thead>
				 <tbody>
             <?php foreach ($otherCondidates as $key => $candidate) {
               echo "<tr><td data-column='". (!empty($condidate_lebels->candidate_name) ? $condidate_lebels->candidate_name : 'CANDIDATE NAME') ."'>".$candidate->candidate."</td><td data-column='". (!empty($condidate_lebels->party) ? $condidate_lebels->party : 'PARTY') ."'>".$candidate->party."</td><td data-column='". (!empty($condidate_lebels->status) ? $condidate_lebels->status : 'STATUS') ."'>" . (!empty($candidate->win_loss) ? $candidate->win_loss : 'Result Awaited') ."</td></tr>";
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
			             <tr><td>Sitting MLA's name</td><td><?php echo $wonCondidate->candidate;?></td></td></tr>
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
				<table class="table" id="othercandidates-list-bottom">
					 <thead>
						 <th><?php echo (!empty($condidate_lebels->candidate_name) ? $condidate_lebels->candidate_name : 'CANDIDATE NAME');?></th><th><?php echo (!empty($condidate_lebels->party) ? $condidate_lebels->party : 'PARTY');?></th>
					 </thead>
					 <tbody>
	            <?php foreach ($otherCondidates as $key => $candidate) {
	              echo "<tr><td data-column='". (!empty($condidate_lebels->candidate_name) ? $condidate_lebels->candidate_name : 'CANDIDATE NAME') ."'>".$candidate->candidate."</td><td data-column='". (!empty($condidate_lebels->party) ? $condidate_lebels->party : 'PARTY') ."'>".$candidate->party."</td></tr>";
	            }?>
					 </tbody>
				</table> 
				</div>
    </div>
  </div> 
<?php endif; ?>

<script type="text/javascript">
function mobilecheck() { var check = false; (function (a) { if (/(android|ipad|playbook|silk|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i.test(a) || /1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i.test(a.substr(0, 4))) check = true })(navigator.userAgent || navigator.vendor || window.opera); return check;}
var is_mobile = mobilecheck() ? true : false;
if (is_mobile) {
var oRows = document.getElementById('othercandidates-list').getElementsByTagName('tr');
var oRowsT = document.getElementById('othercandidates-list-bottom').getElementsByTagName('tr');
var iRowCount = oRows.length; iRowCount = iRowCount - 1;
var totalwidth = iRowCount*330; totalwidth = totalwidth+30;
document.getElementById('othercandidates-list').style.width = totalwidth +'px';
var iRowCountT = oRowsT.length; iRowCountT = iRowCountT - 1;
var totalwidthT = iRowCountT*330; totalwidthT = totalwidthT+30;
document.getElementById('othercandidates-list-bottom').style.width = totalwidthT +'px';
}
</script>
