<?php 
if (!empty($data)) {
    ?>
<div class="container">
<div class="featuredphoto-wrap">
			<div id="coverflow" class="">
				<ul class="flip-items" id="example">
                                    
                                             <?php $i = 1;  $countd = 1; foreach ($data as $entity_data_node) { ?>

                                    <li>
						<div class="inner">
							<a href="#">
								<?php //print $entity_data_node['file_url']; ?>
                                                            <img src="/itgcms/sites/all/themes/itg/images/demo-photo.jpg">
                                                            
								<span class="pic-tit"><span class="flex-count"><?php echo  $entity_data_node['count']; ?> Images </span><?php print $entity_data_node['caption']; ?></span>
							</a>
						</div>
					</li>
                                        
					    <?php $i++; } ?>

				
				</ul>
			</div>
		</div>
</div>
<!--<script>
    var coverflow = jQuery("#coverflow").flipster();
</script>-->

<?php } else { ?>
    No Feature content found
<?php } ?>