<div class="oscar-slider">
    <div class="top-slider">
        <ul>
            <?php
            foreach ($rows as $index => $row) {
                
                    $video_class = "";
                    if (strtolower($row['type']) == 'videogallery') {
                        $video_class = 'video-icon';
                    }
                $first_image="";
                if($index==0)
                {
                    $first_image="first-image";
                }
                ?>
            <li class="<?php echo $first_image; ?> image-tab-<?php echo $index; ?> common-img"><?php print $row['field_story_extra_large_image']; ?><?php if (strtolower($row['type']) == 'videogallery') {print '<span class="osccar-play-icon"><i class="fa fa-play" aria-hidden="true"></i></span>';}?></li>
            <?php }; ?>
        </ul>

    </div>
    <div class="bottom-slider defalt-bar">
        <ul>
            <?php
            foreach ($rows as $index => $row) {
                
                    $video_class = "";
                    if (strtolower($row['type']) == 'videogallery') {
                        $video_class = 'video-icon';
                    }
                $desc = $row['title'];                                
                ?>
            
                <li data-tag="image-tab-<?php echo $index; ?>">
                    <a href="javascript:void(0)" class="<?php echo $video_class;?>"><?php print $row['field_story_extra_large_image_1']; ?></a>
                    <p class="title"><?php echo l(mb_strimwidth(strip_tags($desc), 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></p>
                </li>
            <?php }; ?>
        </ul>
    </div>
</div>
<script>
jQuery(document).ready(function(){    
    jQuery(".bottom-slider li").click(function(){
        jQuery('.common-img').hide();
        var getval = jQuery(this).attr('data-tag');
        jQuery('.'+getval).show();
    });    
    //    Event oscar page as discus with sharvan 
        var winWidth = window.innerWidth;
            if(winWidth > 680){
            var getLength = jQuery(".oscar-slider .bottom-slider li").length;    
            jQuery(".oscar-slider .bottom-slider ul").css("width", getLength*188 +"px");                
                    jQuery(".defalt-bar").mCustomScrollbar({
                        axis:"x",                    
                    });                       
            }else{
                jQuery(".oscar-slider .bottom-slider ul").slick({
                    vertical: true,
                    slidesToShow: 2,
                    dots: false,
                    nextArrow:"<i class='fa fa-chevron-down'></i>",
                    prevArrow:"<i class='fa fa-chevron-up'></i>"                    
                });
            }
});

</script>