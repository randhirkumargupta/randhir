<link type="text/css" rel="stylesheet" href="sites/all/modules/custom/itg_story/css/popModal.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js"></script>
<script src="sites/all/modules/custom/itg_story/js/popModal.js"></script>
<script src="sites/all/modules/custom/itg_story/js/popModal.min.js"></script>

<button id="dialogModal_ex1" class="btn btn-primary">Briefly</button>
<?php
  if($_GET['test'] == 'abc') {
    p($data);
  }
?>

<?php foreach ($data['data']['news'] as $key => $result) { ?>
<div id="dialog_content<?php print $key; ?>" class="dialog_content">
		<div class="dialogModal_header">Dialog header 1</div>
		<div class="dialogModal_content">
        <div><image src="<?php print $result['n_large_image']; ?>"></div>
        <ul>
         <li><?php print $result['n_title']; ?></li>
         <?php foreach ($result['highlight'] as $highlight) { ?>  
          <li><?php print $highlight['h_title']; ?></li>
         <?php } ?>
        </ul>
    </div>
		<div class="dialogModal_footer">
			<button type="button" class="btn btn-primary" data-dialogmodal-but="next">Next</button>
			<button type="button" class="btn btn-default" data-dialogmodal-but="cancel">Cancel</button>
		</div>
	</div>

<style> 
  #dialog_content<?php print $key; ?> { display: none; }
</style>

<?php } ?>






<script>
 jQuery(function($){
   
    jQuery('#dialogModal_ex1').on('click', function(e) {    
      jQuery('.dialog_content').dialogModal({
        onOkBut : function(){ },
        onCancelBut : function(){ },
        onLoad : function(){ },
        onClose : function(){ },
      });
    });
 }); 
  
</script>  