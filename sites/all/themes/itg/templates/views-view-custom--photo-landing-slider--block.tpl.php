<?php
// configuration for social sharing
$photo_node = node_load(arg(1));
$f_collection = entity_load('field_collection_item', array($photo_node->field_gallery_image[LANGUAGE_NONE][0]['value']));
$actual_link = 'http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI'];
$short_url = shorten_url($actual_link, 'goo.gl');
$share_title = addslashes($photo_node->title);
$share_desc = '';
$image = file_create_url($f_collection[$photo_node->field_gallery_image[LANGUAGE_NONE][0]['value']]->field_images[LANGUAGE_NONE][0]['uri']);
?>
<div class="row">
    <div class="col-md-12">
        <h2><?php print $rows[0]['title']; ?></h2>    
        <div class="social-icon desktop-hide">
            <ul>
                <li><a title="share on facebook" onclick="fbpop('<?php print $actual_link;?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image;?>')"><i class="fa fa-facebook"></i></a></li>
                <li><a title="share on google+" href="#" onclick="return googleplusbtn('<?php print $actual_link;?>')"><i class="fa fa-google-plus"></i></a></li>
                <li><a title="share on twitter" href="javascript:" onclick="twitter_popup('<?php print urlencode($share_title);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                <li><a href="javacript:void();" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
                <li><a href="#" title="Embed"><i class="fa fa-link"></i></a></li>
                <li class="mhide"><a href="#" title="post video"><i class="fa fa-share"></i></a></li>
                <?php global $user; ?>
                  <?php if ($user->uid > 0): ?>
                     <?php $read_later = flag_create_link('my_saved_content', arg(1)); ?>                      
                     <li class="mhide"><?php print $read_later; ?></li>
                  <?php else: ?>
                     <?php print '<li class="mhide">' . l('<i class="fa fa-bookmark"></i>', 'user/login', array('html' => TRUE, 'attributes' => array('title' => 'Save'))) . '</li>'; ?>
                <?php endif; ?>                  
            </ul>
        </div>
    </div>
    
    <div class="col-md-8">
        <ul class="slickslide">
            <?php foreach ($rows as $index => $row): 
                
                ?>
                <li >
                    <figure class="" img-fid=" <?php print $row['fid'];?>">

                        <?php print $row['field_images']; ?>                    
                    </figure>
                </li>
            <?php endforeach; ?>
        </ul>
        <div class="slick-thumbs">
            <ul class="slick-thumbs-slider">
                <?php foreach ($rows as $index => $row): ?>
                    <li >
                        <?php print $row['field_images_1']; ?>
                    </li>
                <?php endforeach; ?>
            </ul>
        </div>
        <div class="photo-by-slider">
       <?php foreach ($rows as $index => $row): ?>
        <?php if (!empty($row['field_photo_byline'])) { ?>
            <p class="photo-by">PHOTO: <?php print $row['field_photo_byline']; ?></p>
        <?php } elseif (!empty($row['field_photo_by'])) { ?>
            <p class="photo-by">PHOTO: <?php print $row['field_photo_by']; ?></p>
        <?php } ?>
            <?php endforeach; ?>
        </div>
    </div>
    <div class="col-md-4">
        <div class="other-details-main">
        <ul class="counterslide">
            <?php foreach ($rows as $index => $row): ?>
                <li>
                    <div class="other-details">
                        <div class="counter">
                            <i class="fa fa-camera" aria-hidden="true"></i>
                            <?php print $row['counter']; ?>
                        </div>
                        <div class="caption"><?php print $row['field_image_caption']; ?></div>
                    </div>
                </li>
            <?php endforeach; ?>
        </ul>
        
        <div class="social-icon mhide">
            <ul>
                <li><a title="share on facebook" onclick="fbpop('<?php print $actual_link;?>', '<?php print $share_title; ?>', '<?php print $share_desc; ?>', '<?php print $image;?>')"><i class="fa fa-facebook"></i></a></li>
                <li><a title="share on google+" href="#" onclick="return googleplusbtn('<?php print $actual_link;?>')"><i class="fa fa-google-plus"></i></a></li>
                <li><a title="share on twitter" href="javascript:" onclick="twitter_popup('<?php print urlencode($share_title);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                <li><a href="javacript:void();" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
                <li><a href="#" title="Embed"><i class="fa fa-link"></i></a></li>
                <li><a href="#" title="post video"><i class="fa fa-share"></i></a></li>
                <?php global $user; ?>
                  <?php if ($user->uid > 0): ?>                     
                     <li><?php print $read_later; ?></li>
                  <?php else: ?>
                     <?php print '<li>' . l('<i class="fa fa-bookmark"></i>', 'user/login', array('html' => TRUE, 'attributes' => array('title' => 'Save'))) . '</li>'; ?>
                <?php endif; ?>
            </ul>
        </div>
        
        
        <div class="photo-ad">       
        </div>
        
    </div>
    </div>
</div>


<script>
jQuery(document).ready(function (e) {    
    jQuery('.slickslide').slick({
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: true,
        fade: false,
        asNavFor: '.slick-thumbs-slider, .counterslide, .photo-by-slider'
    });
    jQuery('.slick-thumbs-slider').slick({
        slidesToShow: 7,
        slidesToScroll: 1,
        asNavFor: '.slickslide, .counterslide, .photo-by-slider',
        dots: false,
        centerMode: false,
        arrows: true,
        variableWidth: true,
        focusOnSelect: true,
        responsive: [
            {
              breakpoint: 1024,
              settings: {
                slidesToShow: 7,                  
                slidesToScroll: 1,
                arrows: false
              }
            },
            {
              breakpoint: 600,
              settings: {
                slidesToShow: 4,
                 arrows: false,
                slidesToScroll: 1
              }
            },
            {
              breakpoint: 480,
              settings: {
                slidesToShow: 3,
                 arrows: false,
                slidesToScroll: 1
              }
            }
        ]
    });
        
    jQuery('.counterslide').slick({
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: true,
        fade: true,
        asNavFor: '.slick-thumbs-slider, .slickslide, .photo-by-slider'
    });
    jQuery('.photo-by-slider').slick({
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: false,
        fade: true,
        asNavFor: '.slick-thumbs-slider, .slickslide, .counterslide'
    });
});

</script>








    
  



