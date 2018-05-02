<?php if (!empty($data)) : global $base_url;
$jsondata = json_decode($data);
?>
<div class="row mb-20">
    <div class="col-md-12" id="other-past-results">
			<div class="other-past-results-details">
			<table class="table" id="past-results-list">
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
  <script type="text/javascript">
  	if (is_mobile) {
var oRows = document.getElementById('past-results-list').getElementsByTagName('tr');
var iRowCount = oRows.length; iRowCount = iRowCount - 1;
var totalwidth = iRowCount*330;
document.getElementById('past-results-list').style.width = totalwidth +'px';
}
  </script>
<?php endif;