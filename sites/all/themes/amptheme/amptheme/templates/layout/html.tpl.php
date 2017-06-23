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
    <?php include $ampsubtheme_path_file . '/css/amp-custom-styles.css' ?>
    <link href="https://fonts.googleapis.com/css?family=Roboto+Slab:400,700" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Roboto:400,500,600" rel="stylesheet">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css">
    <script async custom-element="amp-carousel" src="https://cdn.ampproject.org/v0/amp-carousel-0.1.js"></script>
    
    <?php //if (!empty($ampsubtheme_path_file)): ?>
      <style amp-custom>
        
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
        .image-alt{color: #aeaeae; font-size: 12px; font-family: 'Roboto'; padding: 10px 0; border-bottom: 1px solid #ddd;}
        .related-story ul{list-style: none;}
        .related-story ul li{display: inline-block; vertical-align: top; width: 100%; padding: 10px 0;}
        .related-story ul li + li{border-top: 1px solid #ddd;}
        .related-story ul li .tile{float: left; width: 75%; padding-right: 10px;}
        .related-story ul li .tile a{color: #000; text-decoration: none;}
        .related-story ul li > a{float: right; width: 25%;}
        .photo-slide{position: relative;}
        .photo-slide .caption{position: absolute; left: 0; bottom: 0; width: 100%; background-color: #222; color: #aeaeae; font-size: 12px; font-family: 'Roboto'; padding: 5px 10px;}
        .story-right{padding-bottom: 30px;}
        .carousel-preview button{margin-right: 10px;}
        .listicle-feedback .listical_title {
            text-transform: uppercase;
            font-weight: 700;
        }
        .story-section .listicle-page .listicle-detail + .listicle-detail {
            border-top: 1px solid #ccc;
        }
        .story-section .listicle-page .listicle-detail > span {
          width: 34px;
          height: 34px;
          background: #a00606;
          border-radius: 100%;
          font-size: 24px;
          display: inline-block;
          vertical-align: top;
          text-align: center;
          line-height: 34px;
          color: #fff;
          font-weight: 700;
          margin-top: 10px;
      }
      .story-section .listicle-page .listicle-detail > span.bullet_points {
          width: 10px;
          height: 10px;
          line-height: 10px;
          margin-top: 22px;
      }
      .story-section .listicle-page .listicle-detail .listicle-description {
          font-size: 16px;
          color: #282828;
          display: inline-block;
          vertical-align: top;
          width: 95%;
          padding: 18px 20px;
      }
      .story-section .listicle-page .listicle-detail .listicle-description span {
    font-weight: 600;
    text-transform: capitalize;
}
.factoids-slider ul {
    background: #a00606;
    padding: 0px;
    margin-top: 20px;
    display: inline-block;
    vertical-align: top;
    width: 100%;
    list-style: none;
    overflow-x: auto;
    white-space: nowrap;
}
.factoids-slider ul li {
    padding: 25px; 
    font-size: 15px;
    line-height: 24px;
    color: #fff;
    display: inline-block;
    vertical-align: top;
    width: 220px;
}
.factoids-slider ul li:nth-child(odd) {
    background: #a00606;
}
.factoids-slider ul li:nth-child(even) {
    background: #000;
}
.buzz-feedback .buzz-section{margin-bottom: 20px;}
.buzz-feedback .buzz-section h1{margin-bottom: 20px;}
.buzz-feedback .buzz-section h1 span {
    background: #a00606;
    color: #fff;
    width: 32px; 
    height: 32px; 
    display: inline-block;
    vertical-align: top;
    font-size: 24px;
    line-height: 34px;
    text-align: center;
    border-radius: 100%;
    margin: 0 12px 0 0;
}
.buzz-img-wrapper{position: relative;}
.story-photo-list-wrapper h3 {
    text-transform: uppercase;
    font-weight: 700;
    color: #bb0a0a;
    position: relative;
}
.story-photo-list-wrapper h3:before {
    content: '';
    position: absolute;
    left: 0;
    width: 100%;
    height: 3px;
    background: #ddd;
    top: 0;
    bottom: 3px;
    margin: auto;

}
.story-photo-list-wrapper h3 span {
    background: #fff;
    z-index: 1;
    position: relative;
    padding: 20px 20px 20px 0;
    display: inline-block;
}
.story-photo-list-wrapper .story-photo-list {
  overflow-x: auto;
  white-space: nowrap;
}
.story-photo-list-wrapper .story-photo-list-item {
    padding: 0 11px;
    width: 192px;
    display: inline-block;
    vertical-align: top;
}
.story-photo-list-wrapper .story-photo-list-item p{
  line-height: 18px;
}
.smp-date {
    font-size: 12px;
    color: #b1b1b1;
    display: block;
}
.story-section .story-tech-chunk {
    background: #f3f3f3;
    padding: 10px;
    position: relative;
}
.story-section .story-tech-chunk .tech-rating {
    width: 88px;
    height: 33px;
    background: #b00808;
    color: #fff;
    font-size: 28px;
    position: absolute;
    top: 10px;
    right: 10px;
    text-align: center;
    line-height: 33px;
    font-weight: 700;
}
.field .field-label {
    font-weight: bold;
}
.story-section .story-right .stryimg .photoby .story-img-rating {
    background: #b00808;
    display: inline-block;
    vertical-align: top;
    padding: 5px 20px;
    font-size: 28px;
    font-weight: 700;
    color: #fff;
    line-height: 28px;
    position: absolute;
    bottom: 100%;
    left: 0;
}
.movie-rating {
    width: 111px;
    height: 18px;
    margin: 20px 0;
    position: relative;
}
.grey-star{
    position: absolute;
    left: 0;
    top: 0;
    z-index: 9;
}
.red-star{
    position: absolute;
    left: 0;
    top: 0;
    z-index: 10;
    overflow: hidden;
}
.story-section .story-movie .movie-detail div + div {
    margin-top: 15px;
}
.story-section .story-movie .movie-detail div .title {
    float: left;
    padding-right: 7px;
    width: 60px;
}
.story-section .story-movie .movie-detail div .detail {
    display: block;
    overflow: hidden;
}

.node-type-photogallery #header{margin: 0;}
.node-type-photogallery .i-amphtml-slide-item>*{height: auto;}
.black-box{margin: 0 -12px 20px; padding: 10px; background-color: #171717;}
.photo-title {
    font-size: 32px;
    margin: 20px 0;
    color: #fff;
    line-height: 42px;
}
.amp-other-gallery h2 {
    text-transform: uppercase;
    font-weight: 700;
    color: #bb0a0a;
    position: relative;
}
.amp-other-gallery h2:before {
    content: '';
    position: absolute;
    left: 0;
    width: 100%;
    height: 5px;
    background: #ddd;
    top: 0;
    bottom: 3px;
    margin: auto;

}
.amp-other-gallery h2 span {
    background: #fff;
    z-index: 1;
    position: relative;
    padding: 20px 20px 20px 0;
    display: inline-block;
}
.amp-photo-slider .photo-slide .caption{
    width: auto;
}
.amp-photo-slider p{
    color: #fff;
    line-height: 24px;
}
.amp-other-gallery ul{
    list-style: none;
    overflow: hidden;
    margin: 0 -6px;
}
.amp-other-gallery ul li{
    float: left;
    width: 183px;
    padding: 0 6px;
    max-width: 50%;
}
.other-img{
    position: relative;
}
.other-count{
    position: absolute;
    bottom: 0;
    padding: 5px;
    left: 0;
    background-color: rgba(0,0,0,.6);
    color: #aeaeae;
}
.other-date{
    display: block;
    font-size: 12px;
    color: #b1b1b1;
    padding: 8px 0 5px;
    font-family: "Roboto Slab";
}
.other-title a{
    color: #494949;
    font-family: "Roboto Slab";
    line-height: 18px;
    text-decoration: none;
}
.amp-photo-ad{text-align: center;}

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
