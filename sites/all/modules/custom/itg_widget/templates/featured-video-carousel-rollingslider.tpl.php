<?php 
if (!empty($data)) {
    ?>
<div class="featuredvideo-wrap">  
    
			<div id="featuredvideo" class="featuredvideo">
				<ul class="slide-wrap" id="example">
                                    
                                             <?php  $countd = 1; foreach ($data as $entity_data_node) { ?>

					<li class="pos<?php print $countd++; ?>">
						<div class="inner">
							<a href="#">
								<?php print $entity_data_node['file_url']; ?>
								<span class="pic-tit"><span class="flex-count"><?php echo  $entity_data_node['count']; ?> Images </span><?php print $entity_data_node['caption']; ?></span>
							</a>
						</div>
					</li>
					    <?php } ?>

				
				</ul>
				<i class="arrow prev" id="jprev">&lt;</i>
				<i class="arrow next" id="jnext">&gt;</i>
			</div>
		</div>


<?php } else { ?>
    No Feature content found
<?php } ?>