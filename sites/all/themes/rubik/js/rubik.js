/**
 * Implementation of Drupal behavior.
 */
(function($) {
Drupal.behaviors.rubik = {};
Drupal.behaviors.rubik.attach = function(context, settings) {
  // If there are both main column and side column buttons, only show the main
  // column buttons if the user scrolls past the ones to the side.
  $('div.form:has(div.column-main div.form-actions):not(.rubik-processed)', context).each(function() {
    var form = $(this);
    var offset = $('div.column-side div.form-actions', form).height() + $('div.column-side div.form-actions', form).offset().top;
    $(window).scroll(function() {
      if ($(this).scrollTop() > offset) {
        $('div.column-main .column-wrapper > div.form-actions#edit-actions', form).show();
      }
      else {
        $('div.column-main .column-wrapper > div.form-actions#edit-actions', form).hide();
      }
    });
    form.addClass('rubik-processed');
  });

  $('a.toggler:not(.rubik-processed)', context).each(function() {
    var id = $(this).attr('href').split('#')[1];
    // Target exists, add click handler.
    if ($('#' + id).size() > 0) {
      $(this).click(function() {
        var toggleable = $('#' + id);
        toggleable.toggle();
        $(this).toggleClass('toggler-active');
        return false;
      });
    }
    // Target does not exist, remove click handler.
    else {
      $(this).addClass('toggler-disabled');
      $(this).click(function() { return false; });
    }
    // Mark as processed.
    $(this).addClass('rubik-processed');
  });

    // If there's no active secondary tab, make the first one show.
  var activeli = $('.primary-tabs li.active .secondary-tabs li.active');
  if (activeli.length === 0) {
    $('.primary-tabs li.active .secondary-tabs li:first-child a').css('display', 'block');
  }
  
  $('.secondary-tabs li a, .secondary-tabs', context).bind('focus blur', function(){
    $(this).parents('.secondary-tabs').toggleClass('focused');
  });

  // Sticky sidebar functionality.
  var disableSticky = (settings.rubik !== undefined) ? settings.rubik.disable_sticky : false;
  if ($('#content .column-side .column-wrapper').length !== 0 ) {

    // Move fields to sidebar if it exists.
    $('.rubik_sidebar_field', context).once('rubik', function() {
      $('.column-side .column-wrapper').append($(this));
    });

    // Check if the sidebar should be made sticky.
    if (!disableSticky) {
      var rubikColumn = $('#content .column-side .column-wrapper', context);
      if (rubikColumn && rubikColumn.offset()) {
        var rubikStickySidebar = rubikColumn.offset().top;
        $(window).scroll(function() {
          if ($(window).scrollTop() > rubikStickySidebar) {
            rubikColumn.each(function() {
              $(this).addClass("fixed");
              $(this).width($(this).parent().width());
            });
          }
          else {
            rubikColumn.each(function() {
              $(this).removeClass("fixed");
              $(this).width($(this).parent().width());
            });
          }
        });
      }
    }

  }
  
  // Cache the primary tabs.
  var $primaryTabsWrap = $('.primary-tabs');
  if ($primaryTabsWrap.length) {
    var $primaryTabs = $primaryTabsWrap.find('> li');
    // Trigger adjusting function upon first page load.
    adjustPrimaryTabs();
    // Trigger adjusting function upon any screen resizing.
    $(window).resize(function() {
      adjustPrimaryTabs();
    });
  }

  function adjustPrimaryTabs() {
    // Get the position of whole element.
    var parentPosition = $primaryTabs.offset().top;
    // Complicated count.
    var count = [];
    var rowNumber = 1;
    // Remove remainings of other classes we attached.
    $primaryTabs.removeClass('last-row-link');
    $primaryTabs.removeClass('first-row-link');
    // Loop through and compare the position of each tab.
    $primaryTabs.each(function(index) {
      var $this = $(this);
      // New row.
      if (count[rowNumber] != $this.offset().top) {
        // Increase the count for this row.
        rowNumber++;
        count[rowNumber] = $this.offset().top;
        // Add "first" class to this element.
        $this.addClass('first-row-link');
        // Add "last" class to the previous element, if there is one.
        if ($this.prev('li').length) {
          $this.prev('li').addClass('last-row-link');
        }
      }
      // Add "last" class if this is the last element.
      if (index === ($primaryTabs.length - 1)) {
        $this.addClass('last-row-link');
      }
    });
  }
  
  // scroll-to-top animate
  $(window).scroll(function() {
      if ($(this).scrollTop() > 90) {
          $('.block-itg-story, .block-itg-astro, .block-itg-poll, .block-itg-breaking-news, #block-menu-menu-story-content-admin-menu, .block-itg-photogallery, .block-itg-recipe').addClass('fixed');
      } else {
          $('.block-itg-story, .block-itg-astro, .block-itg-poll, .block-itg-breaking-news, #block-menu-menu-story-content-admin-menu, .block-itg-photogallery, .block-itg-recipe').removeClass('fixed');
      }
    });
  $('body').on('click', '.target-link', function(e) {
    var offSet = 80;
    var dti = $(this).attr('data-target-id');
    var targetOffset = $('#' + dti).offset().top - offSet;
    if(dti == "BasicDetails" || dti == "BreakingNewsBasicDetails" || dti == "Element"){
      $(this).addClass('active').siblings('.target-link').removeClass('active');
      $("body,html").animate({ scrollTop: 0 }, 1000);
    }
    else{
      $(this).addClass('active').siblings('.target-link').removeClass('active');
      $("body,html").animate({ scrollTop: targetOffset }, 1000);
    }
    
    });
  //Incorrect navigation when user click on home page from view blog page
  $("a[href='/itgcms/blog']").attr('href', '/itgcms/mydraft-blogs');
    
  // Jquery code to close preview popup
  $(document).on('click', '.close-preview', function(){
    $(this).parents('.preview-wrapper').remove();
  });
  
  // jQuery code to change text URL alias to Sef URL
  var urlTxt = $('.form-item-path-alias label').text();
  if(urlTxt == 'URL alias '){
    $('.form-item-path-alias label').html('SEF URL');
  }
  
  var urlTxt = $('.form-item-path-pathauto label').text();  
  if(urlTxt == 'Generate automatic URL alias '){
    $('.form-item-path-pathauto label').html('Generate automatic SEF URL');
  }
//  $('.path-form #edit-path-pathauto').attr('checked', false);
  if($('.path-form #edit-path-pathauto').is(':checked') == false){
    $('.path-form #edit-path-alias').removeAttr('disabled');
  }
  $('.page-admin-structure-taxonomy-category-management .form-type-hierarchical-select').append('<div class="discription">Root is the section.</div>');
  
  
  // jQuery Code for category manager page
  $('.item-list ul li:not(:has(".item-list"))').find('.cmd-heading .fa').remove();
  $('.cmd-heading').click(function () {
    $(this).toggleClass('active');
    if ($(this).parent().next().is(':visible')) {
      $(this).parent().next().addClass('hide').removeClass('show');
      $(this).parent().next().find('.cmd-heading').addClass('active');
    }
    else {
      $(this).parent().next().removeClass('hide').addClass('show');
      $(this).parent().next().find('.item-list').addClass('hide');
      $(this).parent().next().removeClass('hide');
    }
  });
  
  // jQuery code to filter category manager
  $('.itg-section').click(function(e){
    $(this).addClass('active').siblings().removeClass('active');
    var el = $('.view-content > .item-list > ul > li > .category-manager-details > .cmd-heading');
    el.not('.active').addClass('active').parent().next().addClass('hide').find('.cmd-heading').addClass('active');
  });
  $('.itg-category').click(function(e){
    $(this).addClass('active').siblings().removeClass('active');
    var el = $('.view-content > .item-list > ul > li > .item-list > ul > li > .category-manager-details > .cmd-heading');
    el.addClass('active').parent().parent().parent().parent().removeClass('hide').find('.item-list').addClass('hide');
    el.parent().parent().parent().parent().prev().children('.cmd-heading').removeClass('active');
  });
  $('.itg-sub-category').click(function(e){
    $(this).addClass('active').siblings().removeClass('active');
    var el = $('.view-content > .item-list > ul > li > .item-list > ul > li > .item-list > ul > li > .category-manager-details > .cmd-heading');
    el.addClass('active').parent().parent().parent().parent().removeClass('hide').find('.item-list').addClass('hide');
    el.parents('.item-list').removeClass('hide').prev().children('.cmd-heading').removeClass('active');
  });
  $('.itg-sub-sub-category').click(function(e){
    $(this).addClass('active').siblings().removeClass('active');
    var el = $('.view-content > .item-list > ul > li > .item-list > ul > li > .item-list > ul > li .item-list > ul > li > .category-manager-details > .cmd-heading');
    el.addClass('active').parent().parent().parent().parent().removeClass('hide').find('.item-list').addClass('hide');
    el.parents('.item-list').removeClass('hide').prev().children('.cmd-heading').removeClass('active');
  });
  
  // jQuery code for flexslider
  $('.photogallery-list').flexslider({
    animation: "slide",
    slideshowSpeed: 3000,
    controlNav: false
  });
  
  // jQuery code to hide select option whenever user hover on ITGCMS navbar
  $('#block-menu-menu-admin-left-menu').mouseover(function(){
    $('select').blur();
  });
  
  $('.field-name-field-survey-add-questions > .form-item > div.clearfix .field-add-more-submit').val('Add another question');
  $('.field-name-field-survey-answer-option-2 > div > .form-item > div.clearfix .field-add-more-submit').val('+');
  
  $('.field-name-field-gallery-image').find('.form-text').each(function(){
    var plaholderText = $(this).prev().text();
    $(this).attr('placeholder', plaholderText);
  });
  $('.field-name-field-gallery-image').find('.form-textarea').each(function(){
    var plaholderText = $(this).parent().prev().text();
    $(this).attr('placeholder', plaholderText);
  });
  $('#edit-field-gallery-image .field-name-field-images').find('.image-widget-data .file-size').each(function(){
    var txt = $(this).text();
    $(this).prev().attr('title', txt);
  });
  $('#edit-field-gallery-image .field-name-field-audio').find('.file-widget .file-size').each(function(){
    var txt = $(this).text();
    $(this).prev().attr('title', txt);
  });
  
  $('a.filefield-sources-imce-browse').hover(function(e){
    e.stopPropagation();
    $(this).parents('.form-type-managed-file').addClass('no-image-selected');
  }, function(e){
    e.stopPropagation();
    $(this).parents('.form-type-managed-file').removeClass('no-image-selected');
  });
//  $('#page-title:contains("00:00:00")').html().split("00:00:00").join("");
  $('.node-type-issue #page-title:contains("00:00:00")').each(function(){
    $(this).html($(this).html().split("00:00:00").join(""));
});

  $('input.rating').hover(function(){
    $(this).parent().addClass('rating-hover').prevAll().addClass('rating-hover');
    $(this).parent().nextAll().removeClass('rating-hover');
  }, function(){
    $('.form-checkboxes.rating .form-type-checkbox').removeClass('rating-hover');
  });
  
  $('input.rating').click(function(){
    $(this).parent().addClass('rated-div current-rating').prevAll().addClass('rated-div');
    $(this).parent().nextAll().removeClass('rated-div current-rating').find('input[type="checkbox"]').attr('checked', false);
    $('.rated-div').find('input[type="checkbox"]').attr('checked', true);
  });
  
  $('.survey-submit, .survey-submit-skip').mousedown(function(){
    var checkValue = $(this).parents('.question-container').find('.form-checkbox').is(':checked');
    var radioValue = $(this).parents('.question-container').find('.form-radio').is(':checked');
    var textValue = $(this).parents('.question-container').find('.form-text').val();
    var skipValue = $(this).parents('.question-container').find('.question-skip').val();
    
    if(checkValue && skipValue == 'no'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    } else if(skipValue == 'yes'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    }
    
    if(radioValue && skipValue == 'no'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    } else if(skipValue == 'yes'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    }
    
    if(textValue  && skipValue == 'no' && textValue != 'undefined'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    } else if(skipValue == 'yes'){
      $(this).ajaxSuccess(function(){
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    }
    
  });
  
  var loader = '<div class="ajax-loader"><img src="sites/all/themes/rubik/images/loader.svg" alt=""/></div>';
  
  $('#itg-survey-survey-form .button-yes').mousedown(function(){
    var checkValue = $(this).parents('.question-container').find('.form-checkbox').is(':checked');
    var radioValue = $(this).parents('.question-container').find('.form-radio').is(':checked');
    var textValue = $(this).parents('.question-container').find('.form-text').val();
    var skipValue = $(this).parents('.question-container').find('.question-skip').val();
    
    if(checkValue && skipValue == 'no'){
      $('.question-container').hide();
      $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
      
    } else if(skipValue == 'yes'){
     $('.question-container').hide();
     $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
    }
    
    if(radioValue && skipValue == 'no'){
      $('.question-container').hide();
      $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
    } else if(skipValue == 'yes'){
     $('.question-container').hide();
     $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
    }
    
    if(textValue  && skipValue == 'no' && textValue != 'undefined'){
      $('.question-container').hide();
      $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
    } else if(skipValue == 'yes'){
      $('.question-container').hide();
      $('body').find('.ajax-loader').remove();
      $(this).parents('.block-content').append(loader);
      $(this).ajaxSuccess(function(){
        $('body').find('.ajax-loader').remove();
      });
    }
  });
  
  
  $('.field-name-field-poll-answer-text .form-text').attr('placeholder', 'Poll Answer');
  $('.field-name-field-poll-manipulate-value .form-text').attr('placeholder', 'Manipulate Poll');
  
  $('.field-name-field-gallery-image .field-widget-image-image .filefield-source-imce').each(function(){
    if(!($(this).next().hasClass('gallery-browse'))){
      $(this).after('<a href="javascript:;" class="gallery-browse"><i class="fa fa-picture-o"></i><span>Browse</span></a>');
    }
  });
  $('.field-name-field-gallery-image .field-widget-image-image .form-managed-file').each(function(){
    if($(this).children().hasClass('image-preview')){
      $(this).addClass('has-preview');
    }
    else{
      $(this).removeClass('has-preview');
    }
  });
  
  $('.page-user, .page-admin-people-create').find('.password-suggestions').removeClass('description');
};
})(jQuery);
