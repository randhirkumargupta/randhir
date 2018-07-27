<button id="opener">Briefly</button>
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