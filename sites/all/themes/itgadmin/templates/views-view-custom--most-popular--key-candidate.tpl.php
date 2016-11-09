
<?php foreach($rows as $index => $row){

$consti[]=$row['cat_id'];
}

$resultdata=  array_unique($consti);
   ?>
<div class="key-candidate">

    <div class="list-state">   <?php       foreach ($resultdata as $mainids)
    {
      
      $term_data = taxonomy_term_load($mainids);  
      print '<span id="'.$term_data->tid.'">'.ucfirst($term_data->name).'</span>';
    }?>
    </div> 
<?php foreach($rows as $index => $row){
$term_data = taxonomy_term_load($row['cat_id']);

   ?>

 <div datafor="<?php echo $term_data->tid;?>">
     <div class=""><?php print $row['field_story_extra_large_image'];?> 
   
      <div class="detail">
       
        <p ><?php print ucfirst($row['title']);?></p>
           <p class="constituancy" ><?php print ucfirst($row['field_constituancy']);?></p>
      <?php if($row['extra']!="")
      {
           print '<p class="'.$row['extra'].'" ></p>';
      
      }?>
      </div>
  

<?php }; ?>

     
 </div>

