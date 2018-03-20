<?php

/**
 * @file
 * All custom variables of widgets in this file.
 *
 */

/**
 * This function is used to create settings.
 * 
 * {@inheritdoc}
 */
function itg_widgets_custom_variables() {
	$form = array();
	$form['program_category_id_for_programmes'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter Program Category Id'),
		'#default_value' => variable_get('program_category_id_for_programmes'),
		'#size' => 20,
		'#maxlength' => 20,
	);
	$form['so_sorry_category_id_for_widget'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter So Sorry Category Id'),
		'#default_value' => variable_get('so_sorry_category_id_for_widget'),
		'#size' => 20,
		'#maxlength' => 20,
	);
	$form['anchor_id_for_widget'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter Occupation for Anchors'),
		'#default_value' => variable_get('anchor_id_for_widget'),
		'#size' => 20,
		'#maxlength' => 20,
	);
//  $form['year_end_for_widget'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Enter tid of year end'),
//    '#default_value' => variable_get('year_end_for_widget'),
//    '#size' => 20,
//    '#maxlength' => 20,
////  );
//  $form['auto_for_widget'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Enter tid of Auto'),
//    '#default_value' => variable_get('auto_for_widget'),
//    '#size' => 20,
//    '#maxlength' => 20,
//  );
//  $form['tech_for_widget'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Enter tid of tech'),
//    '#default_value' => variable_get('tech_for_widget'),
//    '#size' => 20,
//    '#maxlength' => 20,
//  );
//  $form['entertainment_oscar_for_widget'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Enter tid of Entertainment Oscar Watch'),
//    '#default_value' => variable_get('entertainment_oscar_for_widget'),
//    '#size' => 20,
//    '#maxlength' => 20,
//  );
//  $form['movie_for_widget'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Enter tid of movie'),
//    '#default_value' => variable_get('movie_for_widget'),
//    '#size' => 20,
//    '#maxlength' => 20,
//  );

	$form['ipl_points_tally_for_widget'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter nid of ipl points tally'),
		'#default_value' => variable_get('ipl_points_tally_for_widget'),
		'#size' => 20,
		'#maxlength' => 20,
	);
	$form['ipl_top_performer_for_widget'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter nid of ipl tip performer'),
		'#default_value' => variable_get('ipl_top_performer_for_widget'),
		'#size' => 20,
		'#maxlength' => 20,
	);
	$form['ipl_for_widget'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter tid of ipl'),
		'#default_value' => variable_get('ipl_for_widget'),
		'#size' => 20,
		'#maxlength' => 20,
	);

	$form['we_may_suggest_block_condition'] = array(
		'#type' => 'textarea',
		'#title' => t('We may suggest block condition for arg(1)'),
		'#default_value' => variable_get('we_may_suggest_block_condition'),
	);

	$form['watch_right_now_block_condition'] = array(
		'#type' => 'textarea',
		'#title' => t('watch right now block condition for arg(1)'),
		'#default_value' => variable_get('watch_right_now_block_condition'),
	);

	$form['top_takes_block_condition'] = array(
		'#type' => 'textarea',
		'#title' => t('top takes block condition for arg(1)'),
		'#default_value' => variable_get('top_takes_block_condition'),
	);
	$form['tid_politician'] = array(
		'#type' => 'textarea',
		'#title' => t('tid of politician'),
		'#default_value' => variable_get('tid_politician'),
	);

	$form['apache_solr_sites_prefix_values'] = array(
		'#type' => 'textfield',
		'#title' => t('Apache solr sites prefix and has values'),
		'#description' => t("Ex: eoshds|IndiaToday,asdasd|AAJtak"),
		'#default_value' => variable_get('apache_solr_sites_prefix_values'),
	);
	$form['newsletter_education_tid'] = array(
		'#type' => 'textfield',
		'#title' => t('Newsletter Eduction Tid'),
		'#default_value' => variable_get('newsletter_education_tid'),
	);
	$form['category_manager_vid'] = array(
		'#type' => 'textfield',
		'#title' => t('Category Manager Vid'),
		'#default_value' => variable_get('category_manager_vid'),
	);
	$form['itg_newsletter_education_id'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter education tid'),
		'#default_value' => variable_get('itg_newsletter_education_id'),
		'#size' => 20,
		'#maxlength' => 20,
	);
	$form['quiz_taxonomy_tid'] = array(
		'#type' => 'textfield',
		'#title' => t('Quiz taxonomy vid'),
		'#default_value' => variable_get('quiz_taxonomy_tid'),
		'#size' => 20,
		'#maxlength' => 20,
	);
	$form['city_manager_vid'] = array(
		'#type' => 'textfield',
		'#title' => t('City Management Vid'),
		'#default_value' => variable_get('city_manager_vid'),
		'#size' => 20,
	);
	$form['reporter_tid'] = array(
		'#type' => 'textfield',
		'#title' => t('Reporter tid'),
		'#default_value' => variable_get('reporter_tid'),
		'#size' => 20,
	);
	$form['live_score_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Live schore URL'),
		'#default_value' => variable_get('live_score_url'),
		'#size' => 255,
	);
	$form['ipl_rhs_nids'] = array(
		'#type' => 'textfield',
		'#title' => t('node id for ipl rhs'),
		'#default_value' => variable_get('ipl_rhs_nids'),
		'#size' => 255,
	);
	$form['anchor_tid'] = array(
		'#type' => 'textfield',
		'#title' => t('Anchor Tid'),
		'#default_value' => variable_get('anchor_tid'),
		'#size' => 20,
	);

	$form['solr_server_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Solr server url'),
		'#default_value' => variable_get('solr_server_url'),
	);

	$form['solr_url_config'] = array(
		'#type' => 'textarea',
		'#title' => t('Solr urlconfig'),
		'#default_value' => variable_get('solr_url_config'),
	);

	$form['global_loyalty_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Global loyalty url'),
		'#default_value' => variable_get('global_loyalty_url'),
	);

	$form['aaj_tak_json_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Aaj tak json url'),
		'#default_value' => variable_get('aaj_tak_json_url'),
	);

	$form['business_today_json_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Business today json url'),
		'#default_value' => variable_get('business_today_json_url'),
	);

	$form['read_later_days_config'] = array(
		'#type' => 'textfield',
		'#title' => t('Read Later days configuration'),
		'#attributes' => array('placeholder' => t('Enter no of days')),
		'#default_value' => variable_get('read_later_days_config'),
	);

	$form['editor_pic_tid'] = array(
		'#type' => 'textfield',
		'#title' => t('Editor Pic Tid configuration'),
		'#attributes' => array('placeholder' => t('Enter Editor Pic Tid')),
		'#default_value' => variable_get('editor_pic_tid'),
	);

	$form['section_widget_keep_row_count'] = array(
		'#type' => 'textfield',
		'#title' => t('Rows You want to keep in section wise widget order'),
		'#attributes' => array('placeholder' => t('Enter Number')),
		'#default_value' => variable_get('section_widget_keep_row_count', 100),
	);

	$form['itg_nofollow_fields'] = array(
		'#type' => 'textfield',
		'#title' => t('Fileds Value that you want to add in nofollow list (add comma separated values like in placeholder)'),
		'#attributes' => array('placeholder' => t('field_blog_long_description, field_blog_short_description')),
		'#default_value' => variable_get('itg_nofollow_fields'),
	);

	$form['current_site_hash'] = array(
		'#type' => 'textfield',
		'#title' => t('Current site Hash configuration For online archive story'),
		'#attributes' => array('placeholder' => t('Enter Current site hash')),
		'#default_value' => variable_get('current_site_hash'),
	);

	$form['ads_blocker_content_limit'] = array(
		'#type' => 'textfield',
		'#title' => t('Ads blocker content limit'),
		'#attributes' => array('placeholder' => t('Enter Ads blocker content limit')),
		'#default_value' => variable_get('ads_blocker_content_limit'),
	);

	$form['reporter_tid_for_widgets'] = array(
		'#type' => 'textfield',
		'#title' => t('Reporter tid for widgets and anchors-listing page'),
		'#attributes' => array('placeholder' => t('Reporter tid for widgets')),
		'#default_value' => variable_get('reporter_tid_for_widgets'),
	);

	$form['itg_front_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Front Url'),
		'#attributes' => array('placeholder' => t('Enter Fron URL')),
		'#default_value' => variable_get('itg_front_url'),
	);

	$form['itg_backend_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Backend Url'),
		'#attributes' => array('placeholder' => t('Enter Fron URL')),
		'#default_value' => variable_get('itg_backend_url'),
	);

	$form['itg_sharing_app_id'] = array(
		'#type' => 'textfield',
		'#title' => t('Facebook share application id'),
		'#attributes' => array('placeholder' => t('Enter Facebook share application id')),
		'#default_value' => variable_get('itg_sharing_app_id'),
	);
  
  $form['logoutsec_time'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter sso logout in milisecond'),
		'#attributes' => array('placeholder' => t('Enter sso logout in milisecond')),
		'#default_value' => variable_get('logoutsec_time'),
	);

	$form['parent_sso'] = array(
		'#type' => 'textfield',
		'#title' => t('SSO url'),
		'#attributes' => array('placeholder' => t('Enter sso url')),
		'#default_value' => variable_get('parent_sso'),
	);

	$form['FRONT_URL_VIDEO'] = array(
		'#type' => 'textfield',
		'#title' => t('Front video url'),
		'#attributes' => array('placeholder' => t('Enter Front video url')),
		'#default_value' => variable_get('FRONT_URL_VIDEO'),
	);
	
	$form['SEE_PIC'] = array(
		'#type' => 'textfield',
		'#title' => t('Front see pic limit'),
		'#attributes' => array('placeholder' => t('Enter see pic limit')),
		'#default_value' => variable_get('SEE_PIC'),
	);
  
	$form['newsletter_content_limit'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter limit for Newsletter Item'),
		'#attributes' => array('placeholder' => t('Enter limit for Newsletter Item')),
		'#default_value' => variable_get('newsletter_content_limit'),
	);
  
	$form['ga_code'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter current GA code for FIA'),
		'#attributes' => array('placeholder' => t('Enter current GA code for FIA')),
		'#default_value' => variable_get('ga_code'),
	);
  
  $form['api_info'] = array(
      '#type' =>'checkbox',
      '#title'=>t('Enable agency feed'),
      '#required'=> FALSE,
      '#default_value' => variable_get('api_info'), // for default checked and false is not checked
  );
  
  $form["api_content_limit"] = array(
    "#type" => "select",
    "#title" => t("Select agency feed node limit"),
    "#default_value" => variable_get("api_content_limit", "5"),
    "#options" => array(
      "5" => t("5"),
      "10" => t("10"),
      "20" => t("20"),
      "50" => t("50"),
      "100" => t("100"),
      "500" => t("500"),
      "1000" => t("1000"),
      "2000" => t("2000"),
      "5000" => t("5000"),
      "10000" => t("10000"),
      "25000" => t("25000"),
    ),
  );
  
  $form['custom_canonical_amp'] = array(
      '#type' =>'checkbox',
      '#title'=>t('Enable custom canonical for amp'),
      '#required'=> FALSE,
      '#default_value' => variable_get('custom_canonical_amp'), // for default checked and false is not checked
  );

  $form['taboola_bottom_block'] = array(
		'#type' => 'textarea',
		'#title' => t('Taboola code for bottom block'),
		'#default_value' => variable_get('taboola_bottom_block'),
	);
  
  $form['third_party_may_recommend_block'] = array(
		'#type' => 'textarea',
		'#title' => t('Suggested Stories (taboola script)'),
		'#default_value' => variable_get('third_party_may_recommend_block'),
	);
  $form['third_party_recommend_new_block'] = array(
		'#type' => 'textarea',
		'#title' => t('Recommended (taboola script)'),
		'#default_value' => variable_get('third_party_recommend_new_block'),
	);
  $form['third_party_crowdynews_block'] = array(
		'#type' => 'textarea',
		'#title' => t('Crowdy News Ads Script'),
		'#default_value' => variable_get('third_party_crowdynews_block'),
	);
  
  $form['disable_third_party_api'] = array(
      '#type' =>'checkbox',
      '#title'=>t('Disable third party api'),
      '#required'=> FALSE,
      '#default_value' => variable_get('disable_third_party_api'), // for default checked and false is not checked
  );
  
  $form['amp_photo_ad'] = array(
		'#type' => 'textarea',
		'#title' => t('Amp photo ad script'),
		'#default_value' => variable_get('amp_photo_ad'),
	);
  
  $form['amp_video_ad'] = array(
		'#type' => 'textarea',
		'#title' => t('Amp video ad script'),
		'#default_value' => variable_get('amp_video_ad'),
	);
  
  $form['amp_story_ad'] = array(
		'#type' => 'textarea',
		'#title' => t('Amp story ad script'),
		'#default_value' => variable_get('amp_story_ad'),
	);
  
  $form['photo_block_refresh'] = array(
      '#type' =>'checkbox',
      '#title'=>t('Enable story, photo and video block refresh in case of akamai'),
      '#required'=> FALSE,
      '#default_value' => variable_get('photo_block_refresh'), // for default checked and false is not checked
  );
  
  $form['solr_down'] = array(
		'#type' => 'textarea',
		'#title' => t('Custom message when solr is down'),
		'#default_value' => variable_get('solr_down'),
	);
  
  $form['disable_livetv_embed'] = array(
      '#type' =>'checkbox',
      '#title'=>t('Disbale Live tv Embed'),
      '#required'=> FALSE,
      '#default_value' => variable_get('disable_livetv_embed'), // for default checked and false is not checked
  );

  $form['technology_review_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('Technology Review TID'),
    '#attributes' => array('placeholder' => t('Enter Technology Review Taxonomy ID')),
    '#default_value' => variable_get('technology_review_tid', 1207760),
  );
  
  $form['add_traffic_script'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add Traffic Script'),
    '#required' => FALSE,
    '#default_value' => variable_get('add_traffic_script'), // for default checked and false is not checked
  );

  $form['traffic_script_js'] = array(
    '#type' => 'textarea',
    '#title' => t('Traffic Script JS'),
    '#default_value' => variable_get('traffic_script_js'),
  );

  $form['pti_section_id'] = array(
    '#type' => 'textfield',
    '#title' => t('PTI Section TID'),
    '#attributes' => array('placeholder' => t('Enter PTI Section TID')),
    '#default_value' => variable_get('pti_section_id'),
  );
  
  $form['sso_cookie_domain'] = array(
		'#type' => 'textfield',
		'#title' => t('Enter sso cookie domain'),
		'#attributes' => array('placeholder' => t('Ex: .indiatoday.in')),
		'#default_value' => variable_get('sso_cookie_domain'),
	);
	
  $form['movies_review_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('Movies Review TID'),
    '#attributes' => array('placeholder' => t('Enter Movies Review Taxonomy ID')),
    '#default_value' => variable_get('movies_review_tid', 1207047),
  );
	
  $form['itg_programmes_order_by'] = array(
    '#type' => 'textarea',
    '#title' => t('Programmes category ids for order'),
    '#default_value' => variable_get('itg_programmes_order_by'),
  );
  
  $form['news_today_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('News Today Section TID'),
    '#default_value' => variable_get('news_today_tid', 1207797),
  );
  $form['site_mapindexurl'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Map Index url'),
    '#default_value' => variable_get('site_mapindexurl', 'https://instore-tosshub-com.s3.ap-south-1.amazonaws.com'),
  );
  $form['site_replaceurl'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Map Replace url'),
    '#default_value' => variable_get('site_replaceurl', 'indiatoday.intoday.in'),
  );
  // AMP Second ad variables
  $form['amp_photo_second_ad'] = array(
    '#type' => 'textarea',
    '#title' => t('Amp photo second ad script'),
    '#default_value' => variable_get('amp_photo_second_ad'),
  );

  $form['amp_video_second_ad'] = array(
    '#type' => 'textarea',
    '#title' => t('Amp video second ad script'),
    '#default_value' => variable_get('amp_video_second_ad'),
  );

  $form['amp_story_second_ad'] = array(
    '#type' => 'textarea',
    '#title' => t('Amp story second ad script'),
    '#default_value' => variable_get('amp_story_second_ad'),
  );
  // AMP Tabola Ad script
  $form['amp_taboola_ad_script'] = array(
    '#type' => 'textarea',
    '#title' => t('Amp tabola ad script'),
    '#default_value' => variable_get('amp_taboola_ad_script'),
  );
  // Unpublish content email alert
  $form['unpublish_alert_emails'] = array(
    '#type' => 'textarea',
    '#title' => t('Story/Photo Unpublish content email alert'),
    '#default_value' => variable_get('unpublish_alert_emails'),
  );

  $form['max_upload_image_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Max image count for upload'),
    '#default_value' => variable_get('max_upload_image_limit', 6),
  );
  $form['place_mobile_ad_after_paragraph'] = array(
    '#type' => 'textfield',
    '#title' => t('Place Mobile Ad After Paragraph'),
    '#default_value' => variable_get('place_mobile_ad_after_paragraph', 2),
  );
  // Unpublish content email alert
  $form['unpublish_alert_emails_videos'] = array(
    '#type' => 'textarea',
    '#title' => t('Video Unpublish content email alert'),
    '#default_value' => variable_get('unpublish_alert_emails_videos'),
  );
  $form['publish_alert_emails_videos'] = array(
    '#type' => 'textarea',
    '#title' => t('Video publish content email alert'),
    '#default_value' => variable_get('publish_alert_emails_videos'),
  );
  $form['place_amp_ad_within_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Place amp Ad After 250 words'),
    '#default_value' => variable_get('place_amp_ad_within_content'),
  );
  $form['section_category_sitemap_tids'] = array(
    '#type' => 'textarea',
    '#title' => t('Section and Categgory Sitemap Tids'),
    '#default_value' => variable_get('section_category_sitemap_tids'),
  );
  return system_settings_form($form);
}
