Linkit Picker Solr
=============

Linkit Picker is an extention to Linkit and Linkit picker (http://drupal.org/project/linkit and http://drupal.org/project/linkit_picker).
Linkit Picker Solr adds the possibility to "browse" apache solr documents via apachesolr views.

Currenlty this module dependes of apachesolr_views module and a lot of patches which are still waiting in the issue queue.
Please, see below:

projects[apachesolr_views][type] = "module"
projects[apachesolr_views][subdir] = "contrib"
projects[apachesolr_views][download][type] = "git"
projects[apachesolr_views][download][url] = "http://git.drupal.org/project/apachesolr_views.git"
projects[apachesolr_views][download][branch] = "7.x-1.x"
projects[apachesolr_views][download][revision] = "36f14d15efc01dc528a224148ae15d576b7e0901"
projects[apachesolr_views][patch][1761432] = "http://drupal.org/files/set_group_operator-1761432-1.patch"
projects[apachesolr_views][patch][1750952] = "http://drupal.org/files/use_arguments-1750952-13.patch"
projects[apachesolr_views][patch][1791908] = "http://drupal.org/files/1791908.patch"
projects[apachesolr_views][patch][2145205] = "http://drupal.org/files/issues/exposed_multiple_sort-apachesolr_views-2145205-1.patch"
projects[apachesolr_views][patch][1766254] = "http://drupal.org/files/issues/apachesolr_views-1766254-10-do-not-test.patch"
projects[apachesolr_views][patch][2191157] = "http://drupal.org/files/issues/date_filter_relative-apachesolr_views-2191157-1.patch"
projects[apachesolr_views][patch][2194541] = "http://drupal.org/files/issues/drush_site_install_errors-apachesolr_views-2194541-1.patch"
projects[apachesolr_views][patch][1651386] = "http://drupal.org/files/apachesolr_views_decode_entities.patch"


Actually you can use the module without appling the patches above but with them you will be able to create much more
improved filters (site filter with autocomplete widget, content type filter with drop down list widget and etc)