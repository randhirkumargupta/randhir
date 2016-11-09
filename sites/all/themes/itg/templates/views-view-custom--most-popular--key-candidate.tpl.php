
<?php foreach($rows as $index => $row){

$consti[]=$row['cat_id'];
}

$resultdata=  array_unique($consti);
   ?>
<div class="key-candidate">

    <div class="list-state">   <?php       foreach ($resultdata as $mainids)
    {
      
      $term_data = taxonomy_term_load($mainids);  
      print '<span data-tag="kc-'.$term_data->tid.'">'.ucfirst($term_data->name).'</span>';
    }?>
    </div> 
<?php foreach($rows as $index => $row){
$term_data = taxonomy_term_load($row['cat_id']);

   ?> 

    <div class="key-candidate-detail" id="kc-<?php echo $term_data->tid;?>">
     <ul>
         <li><?php print $row['field_story_extra_large_image'];?></li>
         <li>
             <p class="candidate-name"><?php print ucfirst($row['title']);?></p>
             <p class="constituancy"><?php print ucfirst($row['field_constituancy']);?></p>
         </li>
         <li>
             <p class="status"><i class="fa fa-thumbs-o-up"></i></p>              
             <?php if($row['extra']!="")
      {
           print '<p class="'.$row['extra'].'" ></p>';
      
      }?>
         </li>         
     </ul>
     
 </div>
<?php }; ?>

     
 </div>

<script>
jQuery(document).ready(function(){    
   jQuery(".key-candidate .list-state span").click(function(){
        jQuery(".key-candidate .list-state span").removeClass('active');
        jQuery(this).addClass('active');
        jQuery('.key-candidate-detail').hide();
        var getval = jQuery(this).attr('data-tag');
        jQuery('#'+getval).show();
    });     
});
</script>
    