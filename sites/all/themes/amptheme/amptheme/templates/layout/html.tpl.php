<?php

/**
 * @file
 * Theme override for the basic structure of a single Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 * - $amp-skip_link: Markup for skip link.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
?><!doctype html>
<html amp lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
  <head>
    <meta charset="utf-8">
    <title><?php print $head_title; ?></title>
    <?php print $head; ?>
    <?php include $amptheme_path_file . '/templates/amp-css/amp-boilerplate-styles-min.inc' ?>
    <link href="https://fonts.googleapis.com/css?family=Roboto+Slab:400,700" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Roboto:400,500,600" rel="stylesheet">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css">
    <?php //if (!empty($ampsubtheme_path_file)): ?>
      <style amp-custom>
        <?php //include $ampsubtheme_path_file . '/css/amp-custom-styles.css' ?>
        *{margin: 0; padding: 0; box-sizing: border-box;}
        body{font: 400 14px/18px 'Roboto Slab';}
        h1, h2, h3, h4, h5, h6{font-family: 'Roboto';}
        h1{font-size: 25px; font-weight: 600; line-height: 30px;}
        p{line-height: 24px; margin: 10px 0;}
        #page-wrapper{max-width: 750px; margin: 0 auto;}
        #main-wrapper{padding: 0 12px;}
        #header{position: relative; background-color: #000; height: 75px; margin-bottom: 30px;}
        #logo{margin: 12px 20px 0 12px; display: inline-block; vertical-align: top; position: absolute; z-index: 10;}
        #navbar{position: absolute; left: 0; bottom: 0; width: 100%; height: 28px; background-color: #a41615; z-index: 9; padding: 0 12px 0 100px;}
        .nav-button, .nav-close{border: none; background-color: transparent; position: absolute; left: 100px; top: 0; color: #fff; padding: 6px 5px 4px; cursor: pointer;}
        .nav-button{z-index: 10;}
        .nav-close{z-index: 9; visibility: hidden;}
        .nav-button:focus{opacity: 0;}
        .nav-button:focus ~ .nav-close {z-index: 10; visibility: visible;}
        .nav-button .fa, .nav-close .fa{font-size: 18px;}
        .nav-items{position: absolute; left: 100px; top: 28px; list-style: none; width: 200px; display: none; background-color: #a41615; z-index: 10;}
        .nav-items li a{padding: 8px 10px; text-decoration: none; color: #fff; border-top: 1px solid rgba(255, 255, 255, .7); display: block; font-family: 'Roboto';}
        .nav-items li:first-child a{border-top: none;}
        .nav-button:focus ~ .nav-items{display: block;}
        .posted-by{margin: 10px 0; font-size: 12px; color: #8c8c8c; font-family: 'Roboto';}
        .stryimg{position: relative;}
        .photoby:empty{display: none;}
        .photoby{position: absolute; left: 0; bottom: 0; width: 100%; background-color: #222; color: #aeaeae; font-size: 12px; font-family: 'Roboto'; padding: 5px 10px;}
        .description a{color: #0883ed;}
      </style>
    <?php //endif; ?>
    <script async src="https://cdn.ampproject.org/v0.js"></script>
  </head>
  <body class="<?php print $classes; ?>" <?php print $attributes;?>>
    <?php //if (!empty($amp_skip_link)): ?>
      <?php //print render($amp_skip_link); ?>
    <?php //endif; ?>
    <?php print $page_top; ?>
    <?php print $page; ?>
    <?php print $page_bottom; ?>
  </body>
</html>
