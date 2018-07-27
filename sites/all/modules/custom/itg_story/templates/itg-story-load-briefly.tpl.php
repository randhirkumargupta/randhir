<!-- <button id="opener"><svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
	 width="24px" height="24px" viewBox="0 0 24 24" enable-background="new 0 0 24 24" xml:space="preserve">
<g display="none"><image display="inline" overflow="visible" width="32" height="24" id="_x38_tQb2G_1_" xlink:href="341E23CB5CF74B60.jpg"  transform="matrix(1 0 0 1 -4 -2)"></image></g><path fill="#FFFFFF" d="M23,13c0,0.55-0.45,1-1,1H2c-0.55,0-1-0.45-1-1V2c0-0.55,0.45-1,1-1h20c0.55,0,1,0.45,1,1V13z"/><path fill="#FFFFFF" d="M19,17c0,0.55-0.45,1-1,1H5c-0.55,0-1-0.45-1-1l0,0c0-0.55,0.45-1,1-1h13C18.55,16,19,16.45,19,17L19,17z"/><path fill="#FFFFFF" d="M17,21c0,0.55-0.45,1-1,1H7c-0.55,0-1-0.45-1-1l0,0c0-0.55,0.45-1,1-1h9C16.55,20,17,20.45,17,21L17,21z"/></svg></button> -->
<?php
  if($_GET['test'] == 'abc') {
    p($data);
  }
?>
<script src="https://code.jquery.com/jquery-1.12.4.js"></script>
<script src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>
<div id="dialog" title="Basic dialog">  
<?php 
foreach ($data['data']['news'] as $key => $result) { ?>

    <div id="openModal<?php print $key; ?>" class="modalDialog">
        <div>
            <?php if($key > 0) { ?>
            <a href="#openModal<?php print $key; ?>">Previous</a>
            <?php } ?>
            
            <?php  if((count($data['data']['news']) -1) > $key) { ?>
            <a href="#openModal<?php print $key + 1; ?>">Next</a>
            <?php  } ?>
            <div><image src="<?php print $result['n_large_image']; ?>"></div>
            <ul>
              <li><?php print $result['n_title']; ?></li>
              <?php foreach ($result['highlight'] as $highlight) { ?>  
               <li><?php print $highlight['h_title']; ?></li>
              <?php } ?>
            </ul>
        </div>
    </div>

<?php } ?>
</div>            
  <script>
  jQuery( function($) {
    $( "#dialog" ).dialog({
      autoOpen: false,
      height: 400,
      width: 350,
      modal: true, 
    });
 
    $( "#opener" ).on( "click", function() {
      $( "#dialog" ).dialog( "open" );
    });
  } );
  
  
    
  </script>          