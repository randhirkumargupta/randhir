/*
 * @file itg_story.js
 * Contains all functionality related to videogallery
 */
Drupal.behaviors.itg_video_front = {
  attach: function (context, settings) {
    jQuery('#block-itg-videogallery-itg-other-videogallery-section .view-display-id-block_4 .view-footer .load-more-video-dec').click(function(){
        if(jQuery(this).children('a').text().trim() == 'Load More'){
            jQuery("#block-itg-videogallery-itg-other-videogallery-section .view-display-id-block_4 .view-content .photo-list li").show();
            jQuery(this).html('<a href="javascript:void(0)" class="add-more-video-dec">Load Less<i class="fa fa-chevron-circle-up" aria-hidden="true"></i></a>');
        }else{
            jQuery('#block-itg-videogallery-itg-other-videogallery-section .view-display-id-block_4 .view-content .photo-list li').hide();
            jQuery('#block-itg-videogallery-itg-other-videogallery-section .view-display-id-block_4 .view-content .photo-list li:lt(4)').show();
            jQuery(this).html('<a href="javascript:void(0)" class="add-more-video-dec">Load More<i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>');
        }      
    });
  }
};
