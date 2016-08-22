/**
 * Implementation of Drupal behavior.
 */
(function ($) {
  Drupal.behaviors.rubik = {};
  Drupal.behaviors.rubik.attach = function (context, settings) {
    // If there are both main column and side column buttons, only show the main
    // column buttons if the user scrolls past the ones to the side.
    $('div.form:has(div.column-main div.form-actions):not(.rubik-processed)', context).each(function () {
      var form = $(this);
      var offset = $('div.column-side div.form-actions', form).height() + $('div.column-side div.form-actions', form).offset().top;
      $(window).scroll(function () {
        if ($(this).scrollTop() > offset) {
          $('div.column-main .column-wrapper > div.form-actions#edit-actions', form).show();
        }
        else {
          $('div.column-main .column-wrapper > div.form-actions#edit-actions', form).hide();
        }
      });
      form.addClass('rubik-processed');
    });

    $('a.toggler:not(.rubik-processed)', context).each(function () {
      var id = $(this).attr('href').split('#')[1];
      // Target exists, add click handler.
      if ($('#' + id).size() > 0) {
        $(this).click(function () {
          var toggleable = $('#' + id);
          toggleable.toggle();
          $(this).toggleClass('toggler-active');
          return false;
        });
      }
      // Target does not exist, remove click handler.
      else {
        $(this).addClass('toggler-disabled');
        $(this).click(function () {
          return false;
        });
      }
      // Mark as processed.
      $(this).addClass('rubik-processed');
    });

    // If there's no active secondary tab, make the first one show.
    var activeli = $('.primary-tabs li.active .secondary-tabs li.active');
    if (activeli.length === 0) {
      $('.primary-tabs li.active .secondary-tabs li:first-child a').css('display', 'block');
    }

    $('.secondary-tabs li a, .secondary-tabs', context).bind('focus blur', function () {
      $(this).parents('.secondary-tabs').toggleClass('focused');
    });

    // Sticky sidebar functionality.
    var disableSticky = (settings.rubik !== undefined) ? settings.rubik.disable_sticky : false;
    if ($('#content .column-side .column-wrapper').length !== 0) {

      // Move fields to sidebar if it exists.
      $('.rubik_sidebar_field', context).once('rubik', function () {
        $('.column-side .column-wrapper').append($(this));
      });

      // Check if the sidebar should be made sticky.
      if (!disableSticky) {
        var rubikColumn = $('#content .column-side .column-wrapper', context);
        if (rubikColumn && rubikColumn.offset()) {
          var rubikStickySidebar = rubikColumn.offset().top;
          $(window).scroll(function () {
            if ($(window).scrollTop() > rubikStickySidebar) {
              rubikColumn.each(function () {
                $(this).addClass("fixed");
                $(this).width($(this).parent().width());
              });
            }
            else {
              rubikColumn.each(function () {
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
      $(window).resize(function () {
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
      $primaryTabs.each(function (index) {
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
    $(window).scroll(function () {
      if ($(this).scrollTop() > 90) {
        $('#block-itg-podcast-podcast-tab-form-block, #block-itg-blog-blog-tab-form-block, #block-itg-reporter-reporter-tab-form-block, .action-with-title, .block-itg-astro, .block-itg-poll, .block-itg-breaking-news, #block-menu-menu-story-content-admin-menu, .block-itg-photogallery, .block-itg-recipe, .block-itg-survey, .block-itg-quiz, .block-itg-mega-reviews-critics, #block-itg-event-backend-sponsor-tab-form-block, .block-itg-newsletter').addClass('fixed');
      } else {
        $('#block-itg-podcast-podcast-tab-form-block, #block-itg-blog-blog-tab-form-block, #block-itg-reporter-reporter-tab-form-block, .action-with-title, .block-itg-astro, .block-itg-poll, .block-itg-breaking-news, #block-menu-menu-story-content-admin-menu, .block-itg-photogallery, .block-itg-recipe, .block-itg-survey, .block-itg-quiz, .block-itg-mega-reviews-critics, #block-itg-event-backend-sponsor-tab-form-block, .block-itg-newsletter').removeClass('fixed');
      }
    });
    $('body').on('click', '.target-link', function (e) {
      var offSet = 194;
      if($('.region-form-tab .block').hasClass('fixed') || $('.action-with-title').hasClass('fixed')){
        offSet = 100;
      }
      
      
      var dti = $(this).attr('data-target-id');
      var dataOffset = $('#' + dti).offset().top;
      var targetOffset = $('#' + dti).offset().top - offSet;
      if (dti == "BasicDetails" || dti == "BreakingNewsBasicDetails" || dti == "Element" || dti == "basicdetails") {
        $(this).addClass('active').siblings('.target-link').removeClass('active');
        $("body,html").animate({scrollTop: 0}, 300);
      }
      else {
        $(this).addClass('active').siblings('.target-link').removeClass('active');
        $("body,html").animate({scrollTop: targetOffset}, 300);
      }

    });
    //Incorrect navigation when user click on home page from view blog page
    $("a[href='/itgcms/blog']").attr('href', '/itgcms/mydraft-blogs');

    // Jquery code to close preview popup
    $(document).on('click', '.close-preview', function () {
      $(this).parents('.preview-wrapper').remove();
    });

    // jQuery code to change text URL alias to Sef URL
    var urlTxt = $('.form-item-path-alias label').text();
    if (urlTxt == 'URL alias ') {
      $('.form-item-path-alias label').html('SEF URL');
    }

    var urlTxt = $('.form-item-path-pathauto label').text();
    if (urlTxt == 'Generate automatic URL alias ') {
      $('.form-item-path-pathauto label').html('Generate automatic SEF URL');
    }
//  $('.path-form #edit-path-pathauto').attr('checked', false);
    if ($('.path-form #edit-path-pathauto').is(':checked') == false) {
      $('.path-form #edit-path-alias').removeAttr('disabled');
    }
    $('.page-admin-structure-taxonomy-category-management .form-type-hierarchical-select').append('<div class="discription">Root is the section.</div>');


    // jQuery Code for category manager page
    $('.item-list ul li:not(:has(".item-list"))').find('.term-wrapper .cmd-heading .fa').remove();
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
    $('.itg-section').click(function (e) {
      $(this).addClass('active').siblings().removeClass('active');
      var el = $('.view-content > .item-list > ul > li > .category-manager-details > .cmd-heading');
      el.not('.active').addClass('active').parent().next().addClass('hide').find('.cmd-heading').addClass('active');
    });
    $('.itg-category').click(function (e) {
      $(this).addClass('active').siblings().removeClass('active');
      var el = $('.view-content > .item-list > ul > li > .item-list > ul > li > .category-manager-details > .cmd-heading');
      el.addClass('active').parent().parent().parent().parent().removeClass('hide').find('.item-list').addClass('hide');
      el.parent().parent().parent().parent().prev().children('.cmd-heading').removeClass('active');
    });
    $('.itg-sub-category').click(function (e) {
      $(this).addClass('active').siblings().removeClass('active');
      var el = $('.view-content > .item-list > ul > li > .item-list > ul > li > .item-list > ul > li > .category-manager-details > .cmd-heading');
      el.addClass('active').parent().parent().parent().parent().removeClass('hide').find('.item-list').addClass('hide');
      el.parents('.item-list').removeClass('hide').prev().children('.cmd-heading').removeClass('active');
    });
    $('.itg-sub-sub-category').click(function (e) {
      $(this).addClass('active').siblings().removeClass('active');
      var el = $('.view-content > .item-list > ul > li > .item-list > ul > li > .item-list > ul > li .item-list > ul > li > .category-manager-details > .cmd-heading');
      el.addClass('active').parent().parent().parent().parent().removeClass('hide').find('.item-list').addClass('hide');
      el.parents('.item-list').removeClass('hide').prev().children('.cmd-heading').removeClass('active');
    });

    // jQuery code for flexslider
    $('.photogallery-list').flexslider({
      animation: "slide",
      slideshowSpeed: 3000,
      controlNav: false,
      prevText: "<i class='fa fa-angle-left' aria-hidden='true'></i>",
      nextText: "<i class='fa fa-angle-right' aria-hidden='true'></i>"
    });

    // jQuery code to hide select option whenever user hover on ITGCMS navbar
    $('#block-menu-menu-admin-left-menu').mouseover(function () {
      $('select').blur();
    });

    $('.field-name-field-survey-answer-option-2 > div > .form-item > div.clearfix .field-add-more-submit').val('+');


    $('#edit-field-gallery-image .field-name-field-images').find('.image-widget-data .file-size').each(function () {
      var txt = $(this).text();
      $(this).prev().attr('title', txt);
    });
    $('#edit-field-gallery-image .field-name-field-audio').find('.file-widget .file-size').each(function () {
      var txt = $(this).text();
      $(this).prev().attr('title', txt);
    });

    $('a.filefield-sources-imce-browse').hover(function (e) {
      e.stopPropagation();
      $(this).parents('.form-type-managed-file').addClass('no-image-selected');
    }, function (e) {
      e.stopPropagation();
      $(this).parents('.form-type-managed-file').removeClass('no-image-selected');
    });
//  $('#page-title:contains("00:00:00")').html().split("00:00:00").join("");
    $('.node-type-issue #page-title:contains("00:00:00")').each(function () {
      $(this).html($(this).html().split("00:00:00").join(""));
    });

    $('input.rating').hover(function () {
      $(this).parent().addClass('rating-hover').prevAll().addClass('rating-hover');
      $(this).parent().nextAll().removeClass('rating-hover');
    }, function () {
      $('.form-checkboxes.rating .form-type-checkbox').removeClass('rating-hover');
    });

    $('input.rating').click(function () {
      $(this).parent().addClass('rated-div current-rating').prevAll().addClass('rated-div');
      $(this).parent().nextAll().removeClass('rated-div current-rating').find('input[type="checkbox"]').attr('checked', false);
      $('.rated-div').find('input[type="checkbox"]').attr('checked', true);
    });

    $('.survey-submit, .survey-submit-skip').mousedown(function () {
      var checkValue = $(this).parents('.question-container').find('.form-checkbox').is(':checked');
      var radioValue = $(this).parents('.question-container').find('.form-radio').is(':checked');
      var textValue = $(this).parents('.question-container').find('.form-text').val();
      var skipValue = $(this).parents('.question-container').find('.question-skip').val();
      var surveyTaken = $('body').find('input[name="survey_taken"]').val();

      if (checkValue && skipValue == 'no' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      } else if (skipValue == 'yes' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      }

      if (radioValue && skipValue == 'no' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      } else if (skipValue == 'yes' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      }

      if (textValue && skipValue == 'no' && textValue != 'undefined' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      } else if (skipValue == 'yes' && surveyTaken == 'no') {
        $(this).ajaxSuccess(function () {
          $('.question-container').hide();
          $(this).parents('.question-container').next().show();
        });
      }

    });

    var loader = '<div class="ajax-loader"><img src="sites/all/themes/itgadmin/images/loader.svg" alt=""/></div>';

    $('#itg-survey-survey-form .button-yes').mousedown(function () {
      var checkValue = $(this).parents('.question-container').find('.form-checkbox').is(':checked');
      var radioValue = $(this).parents('.question-container').find('.form-radio').is(':checked');
      var textValue = $(this).parents('.question-container').find('.form-text').val();
      var skipValue = $(this).parents('.question-container').find('.question-skip').val();

      if (checkValue && skipValue == 'no') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });

      } else if (skipValue == 'yes') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });
      }

      if (radioValue && skipValue == 'no') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });
      } else if (skipValue == 'yes') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });
      }

      if (textValue && skipValue == 'no' && textValue != 'undefined') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });
      } else if (skipValue == 'yes') {
        $('.question-container').hide();
        $('body').find('.ajax-loader').remove();
        $(this).parents('.block-content').append(loader);
        $(this).ajaxSuccess(function () {
          $('body').find('.ajax-loader').remove();
        });
      }
    });

    $('#itg-quiz-quiz-form .quiz-submit').mousedown(function () {
      $(this).ajaxSuccess(function () {
        $('.question-container').hide();
        $(this).parents('.question-container').next().show();
      });
    });


    $('.field-name-field-poll-answer-text .form-text').attr('placeholder', 'Poll Answer');
    $('.field-name-field-poll-manipulate-value .form-text').attr('placeholder', 'Manipulate Poll');




    $('.page-user, .page-admin-people-create').find('.password-suggestions').removeClass('description');

    /* jQuery code ITGCMS QUIZ */
    $('.field-name-field-quiz-option').on('change', 'select', function () {
      var selvalue = $(this).val();
      $(this).parent().parent().parent().find('.field-name-field-quiz-answer-video').find('.button-remove').trigger('mousedown');
      $(this).parent().parent().parent().find('.field-name-field-quiz-answer-image').find('.button-remove').trigger('mousedown');
      $(this).parent().parent().parent().find('.field-name-field-quiz-answer-text').find('.form-text').val('');
      if (selvalue == "Text") {
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-video').hide();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-image').hide();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-text').show();
      }
      if (selvalue == "Video") {
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-video').show();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-image').hide();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-text').hide();
      }
      if (selvalue == "Photo") {
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-image').show();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-video').hide();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-text').hide();
      }
    });
    $('.field-name-field-quiz-option select').each(function () {
      var selvalue = $(this).val();
      if (selvalue == "Text") {
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-video').hide();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-image').hide();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-text').show();
      }
      if (selvalue == "Video") {
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-video').show();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-image').hide();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-text').hide();
      }
      if (selvalue == "Photo") {
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-image').show();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-video').hide();
        $(this).parent().parent().parent().find('.field-name-field-quiz-answer-text').hide();
      }
    });
    $('.field-name-field-quiz-options-answer .form-item').find('.field-add-more-submit').val('+');
    $('input[name="field_quiz_add_questions_add_more"], input[name="field_survey_add_questions_add_more"]').val('Add another question');
    $('input[name="field_newsl_add_news_add_more"]').val('Add More News');
    
    $('.field-name-field-quiz-answer-type').on('change', '.form-radio[value="single_correct"]', function(){
      var correctVal = $(this).is(":checked");
      if(correctVal == true){
        $(this).parents('.field-name-field-quiz-answer-type').siblings('.field-name-field-quiz-options-answer').find('.form-checkbox').attr('checked', false);
      }
    });
    $('.field-name-field-quiz-answer-type').on('change', '.form-radio[value="multiple_correct"]', function(){
      var correctVal = $(this).is(":checked");
      if(correctVal == true){
        $(this).parents('.field-name-field-quiz-answer-type').siblings('.field-name-field-quiz-options-answer').find('.form-checkbox').attr('checked', false);
      }
    });
    $('.field-name-field-quiz-options-answer').on('change', '.form-checkbox', function(){
      var correctVal = $(this).parents('.field-name-field-quiz-options-answer').siblings('.field-name-field-quiz-answer-type').find('.form-radio[value="single_correct"]').is(':checked');
      if(correctVal == true){
        $(this).closest('tr').siblings().find('.field-name-field-quiz-correct-answer .form-checkbox').attr('checked', false);
      }
    });



    /* Java script code for itgadmin */
    if (!$('.img-crt').parent().hasClass('.generate-image')) {
      $('.img-crt, .pre-desc').wrapAll('<div class="generate-image"></div>');
    }
    $('.form-field-name-field-credit-to-all, .form-field-name-field-credit-name').wrapAll('<div class="credit-to-all"></div>');
    $('.image-widget').each(function () {
      var filename = $(this).find('.file').html();
      var filesize = $(this).find('.file-size').html();
      var fullname = filename + filesize;
      if (!($(this).find('.image-preview').children().hasClass('image-fullname'))) {
        $(this).find('.image-preview').append('<div class="image-fullname">' + fullname + '</div>');
      }
      $(this).find('.image-widget-data .file, .image-widget-data .file-size').remove();
    });
    $('.image-widget-data').find('.form-text').each(function () {
      var plaholderText = $(this).prev().text();
      $(this).attr('placeholder', plaholderText);
      $(this).prev('label').hide();
    });

    /* jQuery code for photo Gallery and Video Gallery */
    
//    $('.form-field-name-field-videogallery-video-upload .file-widget').each(function () {
//      if ($(this).children().hasClass('form-file')) {
//        $(this).find('.image-preview').append('<div class="image-fullname">' + fullname + '</div>');
//      }
//      $(this).find('.image-widget-data .file, .image-widget-data .file-size').remove();
//    });
    
    $('.form-field-name-field-credit-name .form-item .form-text').attr('placeholder', 'Credit Name');
    $('.form-field-name-field-gallery-image, .field-name-field-story-expert-name').find('.form-text').each(function () {
      var plaholderText = $(this).prev().text();
      $(this).attr('placeholder', plaholderText);
    });
    $('.form-field-name-field-gallery-image, .field-name-field-story-expert-description, .field-name-field-podcast-description').find('.form-textarea').each(function () {
      var plaholderText = $(this).parent().prev().text();
      $(this).attr('placeholder', plaholderText);
    });
    $('.form-field-name-field-gallery-image .field-widget-image-image .form-managed-file, .form-field-name-field-podcast-audio-upload .field-widget-image-image .form-managed-file, .form-field-name-field-videogallery-video-upload .field-widget-image-image .form-managed-file').each(function () {
      if ($(this).children().hasClass('image-preview')) {
        $(this).addClass('has-preview');

      }
      else {
        $(this).removeClass('has-preview');
      }
    });
    
    $('.form-field-name-field-gallery-image .has-preview').each(function (i) {
      var altName = "field_gallery_image[und][" + i + "][field_images][und][0][alt]";
      var titleName = "field_gallery_image[und][" + i + "][field_images][und][0][title]";
      $("input[name='" + altName + "']").keyup(function () {
        var altVal = $(this).val();
        $(this).parent().next().find('.form-text').val(altVal);
      });
    });
    
    $('.form-field-name-field-videogallery-video-upload .has-preview').each(function (i) {
      var altName = "field_videogallery_video_upload[und][" + i + "][field_video_thumbnail][und][0][alt]";
      var titleName = "field_videogallery_video_upload[und][" + i + "][field_video_thumbnail][und][0][title]";
      $("input[name='" + altName + "']").keyup(function () {
        var altVal = $(this).val();
        $(this).parent().next().find('.form-text').val(altVal);
      });
    });
    
    $('.form-field-name-field-podcast-audio-upload .has-preview').each(function (i) {
      var altName = "field_podcast_audio_upload[und][" + i + "][field_podcast_audio_image_upload][und][0][alt]";
      var titleName = "field_podcast_audio_upload[und][" + i + "][field_podcast_audio_image_upload][und][0][title]";
      $("input[name='" + altName + "']").keyup(function () {
        var altVal = $(this).val();
        $(this).parent().next().find('.form-text').val(altVal);
      });
    });
    $('.form-field-name-field-podcast-audio-upload .file-widget, .form-field-name-field-videogallery-video-upload .file-widget').each(function (i) {
        var hasFile = $(this).find('span').hasClass('file');
        if(hasFile){
            $(this).addClass('has-file');
        } else{
            $(this).removeClass('has-file');
        }
    });
    
    $('.form-field-name-field-gallery-image .messages--error, .field-name-field-podcast-audio-image-upload .messages--error, .field-name-field-podcast-upload-audio-file .messages--error, .field-name-field-upload-video .messages--status, .field-name-field-upload-video .messages.error, .field-name-field-video-thumbnail .messages--error').each(function () {
      if (!$(this).children().hasClass('hide-message')) {
        $(this).append('<a class="hide-message" href="javascript:;">Close</a>');
      }
    });
    $('.form-field-name-field-gallery-image, .field-name-field-upload-video, .field-name-field-video-thumbnail, .field-name-field-podcast-upload-audio-file, .field-name-field-podcast-audio-image-upload').on('click', '.hide-message', function () {
      $(this).parent().remove();
    });

    $('.header__secondary-menu ul li.last a').html('<i class="fa fa-power-off" aria-hidden="true"></i>');

    /* jQuery code for Event Backend */

    $('.form-field-name-field-event-media table tbody tr').each(function () {
      var ebAudio = $(this).find('.field-name-field-browse-or-upload .form-radio[value="audio"]');
      var ebPhoto = $(this).find('.field-name-field-browse-or-upload .form-radio[value="photo"]');
      var ebVideo = $(this).find('.field-name-field-browse-or-upload .form-radio[value="video"]');
      var audioCheck = ebAudio.is(':checked');
      var photoCheck = ebPhoto.is(':checked');
      var videoCheck = ebVideo.is(':checked');
      if (videoCheck) {
        ebVideo.parents('.field-type-list-text').nextAll('div').hide().siblings('.field-name-field-poll-question-video').show();
      } else if (audioCheck) {
        ebAudio.parents('.field-type-list-text').nextAll('div').hide().siblings('.field-name-field-audio').show();
      } else if (photoCheck) {
        ebPhoto.parents('.field-type-list-text').nextAll('div').hide().siblings('.field-name-field-quiz-answer-image').show();
      }
    });

    $('.form-field-name-field-event-media').on('change', '.form-radio', function () {
      var isChecked = $(this).is(':checked');
      var isVal = $(this).val();
      if (isChecked == true && isVal == 'video') {
        $(this).parents('.field-type-list-text').nextAll('div').find('.form-submit[value="Remove"]').mousedown();
        $(this).parents('.field-type-list-text').nextAll('div').hide().siblings('.field-name-field-poll-question-video').show();
      }
      else if (isChecked == true && isVal == 'audio') {
        $(this).parents('.field-type-list-text').nextAll('div').find('.form-submit[value="Remove"]').mousedown();
        $(this).parents('.field-type-list-text').nextAll('div').hide().siblings('.field-name-field-audio').show();
      }
      else if (isChecked == true && isVal == 'photo') {
        $(this).parents('.field-type-list-text').nextAll('div').find('.form-submit[value="Remove"]').mousedown();
        $(this).parents('.field-type-list-text').nextAll('div').hide().siblings('.field-name-field-quiz-answer-image').show();
      }
    });

    $('body').on('click', '.data-popup-link', function () {
      var ID = $(this).attr('data-id');
      $('body').find('#' + ID).show();
    });
    $('body').on('click', '.itg-close-popup', function () {
      $(this).parent().parent().hide();
    });

    $('body').find('.image-preview').parent().addClass('has-image-preview');

    // Reset form Data
    function itg_clear_form_data(class_name) {
      jQuery("." + class_name).find(':input').each(function () {
        switch (this.type) {
          case 'text':
          case 'textarea':
            $(this).val('');
            break;
          case 'select-one':
            $(this).val('_none');
            break;
        }
      });
    }

    // Clear facebook data fields
    $('input[name="field_story_social_media_integ[und][facebook]"]').click(function () {
      if (!$(this).is(':checked')) {
        itg_clear_form_data('form-field-name-field-story-facebook-narrative');
        itg_clear_form_data('form-field-name-field-story-posted-by-facebook');
        itg_clear_form_data('form-field-name-field-story-time-facebook');
        jQuery('.form-field-name-field-story-facebook-image .ajax-processed').mousedown();
      }
    });

    // Clear twitter data fields
    $('input[name="field_story_social_media_integ[und][twitter]"]').click(function () {
      if (!$(this).is(':checked')) {
        itg_clear_form_data('form-field-name-field-story-tweet');
        jQuery('.form-field-name-field-story-tweet-image .ajax-processed').mousedown();
      }
    });
    
    // jQuery code for syndication rule details
    var srd_freq_el = $('.field-name-field-syndication-frequency').find('.form-radio');
    function srdFreq(freq_el){
      var radioCheck = freq_el.is(':checked');
      var radioVal = freq_el.val();
      if(radioCheck == true && radioVal == 'Daily'){
        freq_el.parents('td').find('.field-name-field-syndication-set-day, .field-name-field-syndication-set-day-month').hide();
      }
      if(radioCheck == true && radioVal == 'Weekly'){
        freq_el.parents('td').find('.field-name-field-syndication-set-day-month').hide();
        freq_el.parents('td').find('.field-name-field-syndication-set-day').show();
      }
      if(radioCheck == true && radioVal == 'Monthly'){
        freq_el.parents('td').find('.field-name-field-syndication-set-day').hide();
        freq_el.parents('td').find('.field-name-field-syndication-set-day-month').show();
      }
    }
    srdFreq(srd_freq_el);
    
    $('.field-name-field-syndication-frequency').on('change', '.form-radio', function(){
      var radioCheck = $(this).is(':checked');
      var radioVal = $(this).val();
      if(radioCheck == true && radioVal == 'Daily'){
        $(this).parents('td').find('.field-name-field-syndication-set-day, .field-name-field-syndication-set-day-month').find('select option:selected').prop('selected', false);
        $(this).parents('td').find('.field-name-field-syndication-set-day, .field-name-field-syndication-set-day-month').hide();
      }
      if(radioCheck == true && radioVal == 'Weekly'){
        $(this).parents('td').find('.field-name-field-syndication-set-day, .field-name-field-syndication-set-day-month').find('select option:selected').prop('selected', false);
        $(this).parents('td').find('.field-name-field-syndication-set-day-month').hide();
        $(this).parents('td').find('.field-name-field-syndication-set-day').show();
      }
      if(radioCheck == true && radioVal == 'Monthly'){
        $(this).parents('td').find('.field-name-field-syndication-set-day, .field-name-field-syndication-set-day-month').find('select option:selected').prop('selected', false);
        $(this).parents('td').find('.field-name-field-syndication-set-day').hide();
        $(this).parents('td').find('.field-name-field-syndication-set-day-month').show();
      }
    });
    
    $('.form-field-name-field-newsl-add-news .field-name-field-news-type').each(function(){
        var radioVal = $(this).find('.form-radio:checked').val();
        
        if (radioVal == 'internal') {
            $(this).find('.form-radio').parents('td').find('.field-name-field-news-external-url').hide();

        }
        if (radioVal == 'external') {
            $(this).find('.form-radio').parents('td').find('.field-name-field-news-cid').hide();
            $(this).find('.form-radio').parents('td').find('.newsletter-get-content').parent().hide();
        }
    });
    
    $('.field-name-field-news-type').on('change', '.form-radio', function(){
      var radioCheck = $(this).is(':checked');
      var radioVal = $(this).val();
      if(radioCheck == true && radioVal == 'internal'){
        $(this).parents('td').find('.field-name-field-news-cid .form-text').val('');
        $(this).parents('td').find('.field-name-field-news-external-url').hide();
        $(this).parents('td').find('.field-name-field-news-title').find('.form-text').val('');
        $(this).parents('td').find('.field-name-field-news-kicker').find('.form-textarea').val('');
        $(this).parents('td').find('.field-name-field-news-thumbnail .image-widget-data > .form-submit').trigger('mousedown');
        $(this).parents('td').find('.field-name-field-news-cid').show();
        $(this).parents('td').find('.newsletter-get-content').parent().show();
      }
      if(radioCheck == true && radioVal == 'external'){
        $(this).parents('td').find('.field-name-field-news-external-url .form-text').val('');
        $(this).parents('td').find('.field-name-field-news-cid').hide();
        $(this).parents('td').find('.field-name-field-news-title').find('.form-text').val('');
        $(this).parents('td').find('.field-name-field-news-kicker').find('.form-textarea').val('');
        $(this).parents('td').find('.field-name-field-news-thumbnail .image-widget-data > .form-submit').trigger('mousedown');;
        $(this).parents('td').find('.field-name-field-news-external-url').show();
        $(this).parents('td').find('.newsletter-get-content').parent().hide();
      }
    });
    
    
    // jQuery code for syndication client
    $('.form-field-name-field-syndication-delivery-mode').on('change', '.form-checkbox', function(){
      var check = $(this).is(':checked');
      var ftp = $(this).val();
      if(!check && ftp == 'FTP'){
        $(this).parents('#edit-field-syndication-delivery-mode').siblings('.form-field-name-field-syndication-ftp-details').find('table td .form-text').val('');
      }
      if(!check && ftp == 'Email'){
        $(this).parents('#edit-field-syndication-delivery-mode').siblings('.form-field-name-field-email-address').find('table td .form-text').val('');
      }
      
    });
    
    // jQuery code for Top Actions
    var labelID;
    $('.top-actions').on('click', 'span', function(e){
        e.preventDefault();
        labelID = $(this).attr('data-id');
       $('#'+labelID).trigger('click');
    });
    
    // Code for open link in new tab
    $(".views-field-name").find('a').attr('target', '_blank');
    
    
    // jQuery Code for tabbing
    $('.tab-buttons').on('click', 'span', function(){
      var dataID = '.' + $(this).attr('data-id');
      $(this).addClass('active').siblings().removeClass('active');
      $(this).parent().parent().find(dataID).show().siblings('.tab-data').hide();
    });
    
    jQuery('body').on('click','.sidebar-trigger',function(){
      jQuery(this).parent().toggleClass('active');
    });
    
    //ITG Listing top spacing          
    $('.tab-data').find('ul.itg-listing').css('padding-top','0');
    
    // jQuery code for widget-trigger
    $('body').on('click', '.widget-trigger', function(){
      $(this).prev().toggleClass('active');
      $(this).prev('.widget-title-wrapper.active').find('input[type="text"]').focus();
    });
    
  };
})(jQuery);


jQuery(document).ready(function(){
    
    // jQuery code for related content on edit page
    var item = [];
//     var itemString = jQuery('#edit-field-story-kicker-text-und-0-value').val();
    var itemString = jQuery('#edit-field-common-related-content-und-0-value').val();
    if(itemString){
        item = itemString.split(",");
    }
    var checkedlist = '';
    for ( var i = 0, l = item.length; i < l; i++ ) {
        checkedlist += '<li class="ui-state-default"><span class="ui-icon ui-icon-arrowthick-2-n-s"></span><span class="item-value">' + item[i] + '</span><i class="fa fa-times fright" aria-hidden="true"></i></li>';
    }
    // end of code
    
    
    jQuery('.checked-list').html(checkedlist);
    if(checkedlist){
        jQuery('.save-checklist-ordre').html('<span class="add-more save-checklist">Save</span>');
    }
    else{
        jQuery('.save-checklist-ordre').html('<span class="empty-checklist">No content associated for this story yet !</span>');
    }
    
    
    jQuery('.saved-search-link').click(function (e) {
        e.stopPropagation();
        jQuery(this).parent().parent().find('.my-saved-search').slideToggle();
    });
    jQuery('body').click(function () {
        jQuery(this).find('.my-saved-search').slideUp();
    });
    jQuery('body').click(function () {
        jQuery(this).find('.my-saved-search').slideUp();
    });
        
    jQuery('body').find( ".checked-list" ).sortable();
    jQuery('body').find( ".checked-list" ).disableSelection();
    
    // jQuery code to remove checked list item
    jQuery('.checked-list').on('click', '.fa-times', function () {
        jQuery(this).parent().remove();
    });
    // end of code
    
    jQuery('.data-holder').each(function(){
      if(jQuery(this).children().length > 0){
        jQuery(this).closest('.gray-bg-layout').removeClass('gray-bg-layout');
      }
    });
    
    
    // jQuery code to save check list after re-order
    jQuery('body').on('click', '.save-checklist', function () {
        var item = [];
        var listLength = jQuery(this).closest('.checked-list-parent').find('.checked-list li').length;
        if(!listLength){
            //alert('Changes made successfully');
            jQuery(this).parent().html('<span class="empty-checklist">No content associated for this story yet !</span>');
        }
        jQuery(this).closest('.checked-list-parent').find('.checked-list li').each(function(i){
            item.push(jQuery(this).find('.item-value').text());
        });
       jQuery('#edit-field-common-related-content-und-0-value').val(item);
       alert('Changes made successfully');
    });
    // end of code
    
    // jQuery code for Loader
    jQuery(document).ajaxStart(function () {
        jQuery(".ajax-loader").show();
    }).ajaxStop(function () {
        jQuery(".ajax-loader").hide();
    });
    
    
});


jQuery(document).ready(function() {
    var t = jQuery(".itg-region ul li").length,
        e = jQuery(".itg-region ul li").outerWidth(true),
        o = e * t;
    jQuery(".itg-region ul").css("width", o + 100);
    var s = 0;
    jQuery(".scroll-arrow-left").click(function() {
        if (0 == s) jQuery(this).show();
        else {
            var t = jQuery(".itg-region ul li").eq(s - 1).outerWidth(true);
            jQuery(".itg-region ul").animate({
                left: "+=" + t
            }), s -= 1, jQuery(".scroll-arrow-right").fadeIn()
        }
    }), jQuery(".scroll-arrow-right").click(function() {
        if (t - 7 >= s) {
            var e = jQuery(".itg-region ul li").eq(s).outerWidth();
            jQuery(".itg-region ul").animate({
                left: "-=" + e
            }), s += 1
        } else jQuery(".scroll-arrow-right").fadeOut()
    })
    
    //right side bar toggle    
    jQuery('.region-sidebar-second h2.block-title').click(function(){
         jQuery('.region-sidebar-second h2.block-title i.fa-minus-circle').hide();
         jQuery('.region-sidebar-second h2.block-title i.fa-plus-circle').show();
         jQuery('.region-sidebar-second h2.block-title').next().slideUp();
         
        if(jQuery(this).next().is(":visible")){
           jQuery(this).next().stop().slideUp();
            jQuery(this).find('i.fa-plus-circle').show();
            jQuery(this).find('i.fa-minus-circle').hide();
        }else{
            jQuery(this).next().stop().slideDown();
            jQuery(this).find('i.fa-plus-circle').hide();
            jQuery(this).find('i.fa-minus-circle').show();
        }
    });
    
});
