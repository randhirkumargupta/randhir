<?php
global $base_url;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


if (!empty($title)):
    ?>
    <h3><?php print $title; ?></h3>
    <?php endif; ?>
<div class="search-img-list" id="easyPaginate">
    <?php foreach ($rows as $id => $row) {
       
        $allimage=  explode(' ', $row);
        if(!empty($allimage)) {
            foreach ($allimage as $img) {
                if(trim($img) !="") {
                      print '<img  width="100" height="44" src="'. $img.'">'; 
                }
            
            }
        }
      
    }

    if (empty($rows)) {
        ?>
        <div class="image-no-containt">No Image Found!</div>
<?php }
?> </div>

<script src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/js/jquery-pagination-min.js"></script>
<script src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/js/bootstrap.min.js"></script>
<script src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/js/jquery.snippet.min.js"></script>
<script src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/js/jquery.easyPaginate.js"></script>
<script src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/js/scripts.js"></script>
