<?php 
foreach($data as $index => $row) { 
 $file = file_load($row['field_story_extra_large_image_fid']);
 $image = file_create_url($file->uri);
 $term_name = taxonomy_term_load($row['tid'])->name;
?>
<div class="item col-xs-12 col-sm-6 col-lg-3 list-group-item">
  <div class="thumbnail">
      <div class="thumbnail-img">
      <?php if (!empty($image)) : ?>
               <img src="<?php print $image; ?>" alt="" title="" width="125" align="left" height="93" />
       <?php else : ?>
                 <img src="<?php print  file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image483x271.jpg'); ?>" width="125" align="left" height="93" />
       <?php endif; ?>
      </div>
        <h4 class="list-group-item-heading"><a href="<?php echo $base_url . '/bestcolleges/' . $row['field_bestcollege_year'] . '/ranks/' . $row['tid']; ?>"><?php print $term_name; ?></a></h4>
        <div class="caption">            
            <p class="group inner list-group-item-text"> 
			 <a href="<?php echo $base_url . '/bestcolleges/' . $row['field_bestcollege_year'] . '/ranks/' . $row['tid']; ?>"> 
              <?php print $row['title'] . ", " . $row['field_bestcollege_city']; ?>
             </a>
            </p> 
            <div class="cl1"> 
				<a href="<?php echo $base_url . '/bestcolleges/' . $row['field_bestcollege_year'] . '/ranks/' . $row['tid']; ?>">
				 <?php print t('Rank') . ':' . $row['field_bestcollege_rank']; ?> 
				</a>
			</div>
            <div class="cl"> 
			<a href="<?php echo $base_url . '/bestcolleges/' . $row['field_bestcollege_year'] . '/ranks/' . $row['tid']; ?>">
			 <?php print t('SEE COMPLETE LIST') . '|' . t('DIRECTORY'); ?> 
            </a>
            </div>
        </div>
      <div class="clearfix"></div>
  </div>
</div>
<?php
 }
?>
