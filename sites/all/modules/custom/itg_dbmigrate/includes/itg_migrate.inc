<?php
//exit;
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
  //watchdog("test shravan@", '<pre>'. print_r($_GET, TRUE) .'</pre>'); 
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

  $api = array(
    // Required - tells the Migrate module that you are implementing version 2
    // of the Migrate API.
    'api' => 2,
  
    'groups' => array(
      'itg_category' => array(
        'title' => t('Itg category Imports'),
      ),
      'itg_story' => array(
        'title' => t('Itg story Imports'),
      ),
       'itg_byline' => array(
        'title' => t('Itg byline Imports'),
      ),
      'itg_magazine' => array(
        'title' => t('Itg magazine Imports'),
      ),
       'itg_issue' => array(
        'title' => t('Itg issue Imports'),
      ),
      'itg_supplement' => array(
        'title' => t('Itg Supplement Imports'),
      ),
      'itg_foodnews' => array(
        'title' => t('Itg Food News Imports'),
      ),
      'itg_city' => array(
        'title' => t('Itg city Imports'),
      ),
      'itg_tags' => array(
        'title' => t('Itg tags Imports'),
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
      'itg_photogallery' => array(
        'title' => t('Itg Photogallery Imports'),
      ),
      'itg_videogallery' => array(
        'title' => t('Itg Videogallery Imports'),
      ),
      'itg_megareview' => array(
        'title' => t('Itg Megareview Imports'),
      ),
    ),

    // Here we register the individual migrations. The keys (ItgCategory, ItgStory
    // etc.) are the machine names of the migrations, and the class_name
    // argument is required. The group_name is optional (defaulting to 'default')
    // but specifying it is a best practice.
    'migrations' => array(
      'ItgCategory' => array(
        'class_name' => 'ItgCategoryMigration',
        'group_name' => 'itg_category',
      ),
      'ItgStory' => array(
        'class_name' => 'ItgStoryMigration',
        'group_name' => 'itg_story',
      ),
      'ItgByline' => array(
        'class_name' => 'ItgBylineMigration',
        'group_name' => 'itg_byline',
      ),
      'ItgMagazine' => array(
        'class_name' => 'ItgMagazineMigration',
        'group_name' => 'itg_magazine',
      ),
      'ItgIssue' => array(
        'class_name' => 'ItgIssueMigration',
        'group_name' => 'itg_issue',
      ),
      'ItgSupplement' => array(
        'class_name' => 'ItgSupplementMigration',
        'group_name' => 'itg_supplement',
      ),
      'ItgFoodNews' => array(
        'class_name' => 'ItgFoodNewsMigration',
        'group_name' => 'itg_foodnews',
      ),
      'ItgCity' => array(
        'class_name' => 'ItgCityMigration',
        'group_name' => 'itg_city',
      ),
      'ItgTags' => array(
        'class_name' => 'ItgTagsMigration',
        'group_name' => 'itg_tags',
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
      'ItgPhotogallery' => array(
        'class_name' => 'ItgPhotogalleryMigration',
        'group_name' => 'itg_photogallery',
      ),
      'ItgVideogallery' => array(
        'class_name' => 'ItgVideogalleryMigration',
        'group_name' => 'itg_videogallery',
      ),
      'ItgMegareview' => array(
        'class_name' => 'ItgMegareviewMigration',
        'group_name' => 'itg_megareview',
      ),
    ),
    
  );
  return $api;
}
