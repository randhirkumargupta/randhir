<?php
//exit;z
/**
 * @file
 * Because the name of this file is the module name plus '.migrate.inc', when
 * hook_migrate_api is invoked by the Migrate module this file is automatically
 * loaded - thus, you don't need to implement your hook in the .module file.
 */

/*
 * You must implement hook_migrate_api(), setting the API level to 2, if you are
 * implementing any migration classes. If your migration application is static -
 * that is, you know at implementation time exactly what migrations must be
 * instantiated - then you should register your migrations here. If your
 * application is more dynamic (for example, if selections in the UI determine
 * exactly what migrations need to be instantiated), then you would register
 * your migrations using registerMigration() - see migrate_example_baseball for
 * more information.
 */
function itg_dbmigrate_migrate_api() {
  //exit;
 // watchdog("test arun@", '<pre>'. print_r($_GET, TRUE) .'</pre>');
  // Usually field mappings are established by code in the migration constructor -
  // a call to addFieldMapping(). They may also be passed as arguments when
  // registering a migration - in this case, they are stored in the database
  // and override any mappings for the same field in the code. To do this,
  // construct the field mapping object and configure it similarly to when
  // you call addFieldMapping, and pass your mappings as an array below.
//  $translate_mapping = new MigrateFieldMapping('translate', NULL);
//  $translate_mapping->defaultValue(0);
//  $ignore_mapping = new MigrateFieldMapping('migrate_example_beer_styles:ignore_case', NULL);
//  $ignore_mapping->defaultValue(1);

  $disable_hooks = array(
    'entity_insert' => array(
      'metatag',
      'og',
      'registration',
    ),
    'entity_presave' => array(
      'pathauto',
    ),
    'entity_update' => array(
      'metatag',
      'og',
      'registration',
    ),

    'taxonomy_term_insert' => array(
      'metatag',
      'pathauto',
      'shs',
      'taxonomy_menu',
    ),
    'taxonomy_term_update' => array(
      'pathauto',
      'shs',
      'taxonomy_menu',
    ),

  );

  $api = array(
    // Required - tells the Migrate module that you are implementing version 2
    // of the Migrate API.
    'api' => 2,

    'groups' => array(
      'itg_section' => array(
        'title' => t('Itg section Imports'),
      ),
      'itg_category' => array(
        'title' => t('Itg category Imports'),
      ),
      'itg_subcategory' => array(
        'title' => t('Itg subcategory Imports'),
      ),
      'itg_subsubcategory' => array(
        'title' => t('Itg subsubcategory Imports'),
      ),
      'itg_story' => array(
        'title' => t('Itg story Imports'),
      ),
       'itg_byline' => array(
        'title' => t('Itg byline Imports'),
      ),
      'itg_city' => array(
        'title' => t('Itg city Imports'),
      ),
      'itg_tags' => array(
        'title' => t('Itg tags Imports'),
        'disable_hooks' => $disable_hooks,
      ),
      'itg_photogallery' => array(
        'title' => t('Itg Photogallery Imports'),
      ),
      'itg_videogallery' => array(
        'title' => t('Itg Videogallery Imports'),
      ),
      'itg_user' => array(
        'title' => t('Itg User Migration'),
      ),
      'itg_country' => array(
        'title' => t('Itg Country Migration'),
      ),
      'itg_state' => array(
        'title' => t('Itg State Migration'),
      ),
      'itg_Photo_category' => array(
        'title' => t('Itg Photo Category Migration'),
      ),
      'itg_story_list' => array(
        'title' => t('Story Migrate by xml chunks'),
      ),
       'itg_issue' => array(
        'title' => t('Itg issue Imports'),
      ),
      'itg_supplements' => array(
        'title' => t('Itg Supplement Imports'),
      ),
      /*'itg_magazine' => array(
        'title' => t('Itg magazine Imports'),
      ),
      
      
      'itg_foodnews' => array(
        'title' => t('Itg Food News Imports'),
      ),
      'itg_sponsor' => array(
        'title' => t('Itg sponsor Imports'),
      ),
      'itg_sbreaking_news' => array(
        'title' => t('Itg breaking news Imports'),
      ),
      'itg_cooking_tips' => array(
        'title' => t('Itg Cooking Tips Imports'),
      ),
      'itg_astro' => array(
        'title' => t('Itg astro Imports'),
      ),
      'itg_recipe' => array(
        'title' => t('Itg recipe Imports'),//pending
      ),
      'itg_megareview' => array(
        'title' => t('Itg Megareview Imports'),
      ),*/

      'itg_best_college' => array(
        'title' => t('Itg Best College Migration'),
      ),

    ),

    // Here we register the individual migrations. The keys (ItgCategory, ItgStory
    // etc.) are the machine names of the migrations, and the class_name
    // argument is required. The group_name is optional (defaulting to 'default')
    // but specifying it is a best practice.
    'migrations' => array(
      'ItgSection' => array(
        'class_name' => 'ItgSectionMigration',
        'group_name' => 'itg_section',
      ),
      'ItgCategory' => array(
        'class_name' => 'ItgCategoryMigration',
        'group_name' => 'itg_category',
      ),
      'ItgSubCategory' => array(
        'class_name' => 'ItgSubCategoryMigration',
        'group_name' => 'itg_subcategory',
      ),
      'ItgSubSubCategory' => array(
        'class_name' => 'ItgSubSubCategoryMigration',
        'group_name' => 'itg_subsubcategory',
      ),
      'ItgStory' => array(
        'class_name' => 'ItgStoryMigration',
        'group_name' => 'itg_story',
      ),
      'ItgStoryList' => array(
        'class_name' => 'ItgStoryListMigration',
        'group_name' => 'itg_story_list',
      ),
      'ItgByline' => array(
        'class_name' => 'ItgBylineMigration',
        'group_name' => 'itg_byline',
      ),
      'ItgCity' => array(
        'class_name' => 'ItgCityMigration',
        'group_name' => 'itg_city',
      ),
      'ItgTags' => array(
        'class_name' => 'ItgTagsMigration',
        'group_name' => 'itg_tags',
      ),
      'ItgPhotogallery' => array(
        'class_name' => 'ItgPhotogalleryMigration',
        'group_name' => 'itg_photogallery',
      ),
      'ItgVideogallery' => array(
        'class_name' => 'ItgVideogalleryMigration',
        'group_name' => 'itg_videogallery',
      ),
      'ItgUser' => array(
        'class_name' => 'ItgUserMigration',
        'group_name' => 'itg_user',
      ),
      'ItgCountry' => array(
        'class_name' => 'ItgCountryMigration',
        'group_name' => 'itg_country',
      ),

      'ItgState' => array(
        'class_name' => 'ItgStateMigration',
        'group_name' => 'itg_state',
      ),
       'ItgIssue' => array(
        'class_name' => 'ItgIssueMigration',
        'group_name' => 'itg_issue',
      ),
      'ItgPhoto' => array(
        'class_name' => 'ItgPhotoMigration',
        'group_name' => 'itg_Photo_category',
      ),
       'ItgSupplements' => array(
        'class_name' => 'ItgSupplementsMigration',
        'group_name' => 'itg_supplement',
      ),
     
      /*'ItgMagazine' => array(
        'class_name' => 'ItgMagazineMigration',
        'group_name' => 'itg_magazine',
      ),
     
      'ItgFoodNews' => array(
        'class_name' => 'ItgFoodNewsMigration',
        'group_name' => 'itg_foodnews',
      ),
      'ItgSponsor' => array(
        'class_name' => 'ItgSponsorMigration',
        'group_name' => 'itg_sponsor',
      ),
      'ItgBreakingNews' => array(
        'class_name' => 'ItgBreakingNewsMigration',
        'group_name' => 'itg_sbreaking_news',
      ),
      'ItgCookingTips' => array(
        'class_name' => 'ItgCookingTipsMigration',
        'group_name' => 'itg_cooking_tips',
      ),
      'ItgAstro' => array(
        'class_name' => 'ItgAstroMigration',
        'group_name' => 'itg_astro',
      ),
      'ItgRecipe' => array(
        'class_name' => 'ItgRecipeMigration',
        'group_name' => 'itg_recipe',
      ),
      'ItgMegareview' => array(
        'class_name' => 'ItgMegareviewMigration',
        'group_name' => 'itg_megareview',
      ),*/

    ),

  );
  return $api;
}
