<?php if (!empty($data)) : global $base_url;
$jsondata = json_decode($data);
?>
<div class="row mb-20">
    <div class="col-md-12" id="other-past-results">
			<h3 class="labels"><?php print !empty($jsondata->label)?$jsondata->label:'Past Results';?></h3>
			<div class="other-candidates-details">
			<table class="table" id="othercandidates-list">
				 <thead>
					 <th>Years</th><th>Winner</th><th>Party</th>
				 </thead>
				 <tbody>
             <?php foreach ($jsondata as $key => $value) {
               echo "<tr><td data-column='Years'>".$value->year."</td><td data-column='Winner'>".$value->candidate."</td><td data-column='Party'>".$value->party."</td></tr>";
             }?>
				 </tbody>
			</table>
			</div>
    </div>
  </div>
<?php endif;