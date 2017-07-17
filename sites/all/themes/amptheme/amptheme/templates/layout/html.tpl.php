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
    <script async custom-element="amp-dailymotion" src="https://cdn.ampproject.org/v0/amp-dailymotion-0.1.js"></script>
    <script async custom-element="amp-jwplayer" src="https://cdn.ampproject.org/v0/amp-jwplayer-0.1.js"></script>
    <script async custom-element="amp-accordion" src="https://cdn.ampproject.org/v0/amp-accordion-0.1.js"></script>
    <script async custom-element="amp-social-share" src="https://cdn.ampproject.org/v0/amp-social-share-0.1.js"></script>
    <script async custom-element="amp-twitter" src="https://cdn.ampproject.org/v0/amp-twitter-0.1.js"></script>
    <script async custom-element="amp-facebook" src="https://cdn.ampproject.org/v0/amp-facebook-0.1.js"></script>
    <script async custom-element="amp-form" src="https://cdn.ampproject.org/v0/amp-form-0.1.js"></script>
    <script async custom-element="amp-video" src="https://cdn.ampproject.org/v0/amp-video-0.1.js"></script>

    <?php //if (!empty($ampsubtheme_path_file)):  ?>
    <style amp-custom>

      *{margin: 0; padding: 0; box-sizing: border-box; outline: none; border: none;}
      body{font: 400 14px/18px 'Roboto Slab'; color: #333;}
      h1, h2, h3, h4, h5, h6{font-family: 'Roboto';}
      h1{font-size: 25px; font-weight: 600; line-height: 30px;}
      p{line-height: 24px; margin: 10px 0; white-space: normal;}
      img{max-width: 100%;}
      #page-wrapper{max-width: 750px; margin: 0 auto;}
      #main-wrapper{padding: 0 12px;}
      #header{position: relative; background-color: #000; height: 75px; margin-bottom: 0; z-index: 9999;}
      #logo{margin: 12px 20px 0 12px; display: inline-block; vertical-align: top; position: absolute; z-index: 10;}
      #navbar{position: absolute; left: 0; bottom: 0; width: 100%; height: 28px; background-color: #a41615; z-index: 9; padding: 0 12px 0 100px;}
      #navbar h2{
        width: 20px;
        text-align: center;
        background: transparent;
        border: none;
        padding: 3px 0;
        color: #fff;
        height: 28px;
      }
      #navbar amp-accordion h2 span{position: absolute; left: 0; top: 3px;}
      #navbar h2[aria-expanded="false"] .show-less{opacity: 0;}
      #navbar h2[aria-expanded="true"] .show-more{opacity: 0;}
      .header-menu{ left: 0; top: 0; list-style: none; width: 200px; background-color: #a41615; z-index: 10;}
      .header-menu li a{padding: 8px 10px; text-decoration: none; color: #fff; border-top: 1px solid rgba(255, 255, 255, .7); display: block; font-family: 'Roboto';}
      .header-menu li:first-child a{border-top: none;}
      .posted-by{margin: 10px 0; font-size: 12px; color: #8c8c8c; font-family: 'Roboto';}
      .stryimg{position: relative;}
      .photoby:empty{display: none;}
      .photoby{position: absolute; left: 0; bottom: 0; width: 100%; background-color: #222; color: #aeaeae; font-size: 12px; font-family: 'Roboto'; padding: 5px 10px;}
      .description a{color: #0883ed;}
      .description ul, .description ol{padding-left: 18px;}
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
      .carousel-preview{white-space: nowrap; overflow: auto;}
      .carousel-preview button{margin-right: 10px;}
      .listicle-feedback .listical_title {
        text-transform: uppercase;
        font-weight: 700;
        line-height: 24px;
      }
      .story-section .listicle-page .listicle-detail + .listicle-detail {
        border-top: 1px solid #ccc;
      }
      .story-section .listicle-page .listicle-detail > span {
        width: 24px;
        height: 24px;
        background: #a00606;
        border-radius: 100%;
        font-size: 14px;
        text-align: center;
        line-height: 24px;
        color: #fff;
        font-weight: 700;
        margin: 20px 0 0 0;
        float: left;
      }
      .story-section .listicle-page .listicle-detail > span.bullet_points {
        width: 10px;
        height: 10px;
        line-height: 10px;
        margin-top: 27px;
      }
      .story-section .listicle-page .listicle-detail .listicle-description {
        font-size: 14px;
        color: #282828;
        padding: 18px 10px;
        overflow: hidden;
        line-height: 24px;
      }
      .story-section .listicle-page .listicle-detail .listicle-description span {
        font-weight: 600;
        text-transform: capitalize;
      }
      .scroll-x{
        overflow-x: auto;
      }
      .factoids-slider ul {
        background: #a00606;
        padding: 0px;
        margin-top: 20px;
        display: table;
        vertical-align: top;
        list-style: none;
      }
      .factoids-slider ul li {
        padding: 25px; 
        font-size: 15px;
        line-height: 24px;
        color: #fff;
        display: table-cell;
        vertical-align: top;
        min-width: 220px;
        white-space: normal;
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
      .amp-photo-slider .amp-carousel-button{
        top: 25%;
      }
      .front-end-breadcrumb-photo-video + .black-box .amp-photo-slider .amp-carousel-button,
      .node-type-photogallery .amp-photo-slider .amp-carousel-button{top: 42%;}
      .node-type-videogallery .amp-photo-slider .amp-carousel-button{top: 34%;}
      .amp-photo-slider p{
        color: #a1a1a1;
        line-height: 24px;
      }
      .video-caption span {
        display: block;
        padding-top: 20px;
        color: #fff;
      }
      .amp-other-gallery ul{
        list-style: none;
        overflow: hidden;
        margin: 0 -6px;
      }
      .amp-other-gallery ul li {
          display: inline-block;
          width: 180px;
          padding: 0 5px 10px;
          max-width: 49.5%;
          vertical-align: top;
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
      .node-story h1 a{color: #0883ed; text-decoration: none;}
      .node-story h1 a:hover{color: #0883ed; text-decoration: underline;}
      .story-section h1 i {
        font-size: 13px;
        color: #f40000;
        animation-name: blinker;
        animation-iteration-count: infinite;
        animation-timing-function: cubic-bezier(1, 0, 0, 1);
        animation-duration: 1s;
      }
      .story-right .description iframe{width: 100%; max-width: 100%;}
      pre{white-space: inherit;}
      .amp-carousel-button{z-index: 99; visibility: visible; opacity: 1;}
      #block-itg-layout-manager-front-end-breadcrumb {
        position: relative;
        z-index: 9998;
        color: #a1a1a1;
        font-family: roboto;
      }
      #block-itg-layout-manager-front-end-breadcrumb div.lft {
        display: inline-block;
        vertical-align: top;
      }
      #block-itg-layout-manager-front-end-breadcrumb a {
        color: #a1a1a1;
        font-family: roboto;
      }
      .front-end-breadcrumb {
        margin: 0 -12px;
        padding: 20px 12px;
        color: #a1a1a1;
        font-family: roboto;
        font-size: 14px;
      }
      .front-end-breadcrumb > div {
        display: inline-block;
        vertical-align: top;
      }
      .front-end-breadcrumb a{
        color: #a1a1a1;
        font-family: roboto;
      }
      .front-end-breadcrumb.front-end-breadcrumb-photo-video{
          background-color: #171717;
          padding-bottom: 0;
      }
      #footer{
        background-color: #000;
        color: #fff;
        margin-top: 30px;
        font-family: roboto;
        position: relative;
      }
      #footer ul{
        list-style: none;
      }
      #footer a{
        color: #a6a6a6;
        font-family: "Roboto", sans-serif;
        text-decoration: none;
      }
      #footer a:hover{
        color: #ffc106;
      }
      .footer-top-link, .footer-bottom-menu{
        white-space: nowrap;
        overflow-x: auto;
        border-bottom: 1px solid #111111;
        position: relative;
        z-index: 9;
      }
      .footer-top-link{
        padding-right: 40px;
      }
      .footer-top-link ul li{
        display: inline-block;
        vertical-align: top;
        margin: 6px 12px;
      }
      .footer-top-link ul li a{
        display: block;
        height: 37px;
        line-height: 37px;
        font-size: 15px;
        text-transform: uppercase;
      }
      .footer-bottom-menu{
        padding-bottom: 10px;
      }
      .footer-bottom-menu .menu-col{
        display: inline-block;
        vertical-align: top;
        margin: 6px 12px;
        width: 170px;
      }
      .footer-bottom-menu h4{
        text-transform: uppercase;
        margin: 20px 0 5px;
      }
      .footer-bottom-menu ul li{
        padding: 3px 0;
      }
      #footer amp-accordion h2{
        width: 40px;
        height: 49px;
        text-align: center;
        padding: 0;
        border: none;
        background: #000;
        margin-top: -50px;
        z-index: 99;
        position: absolute !important;
        right: 0;
        top: 0;
      }
      .copyright{
        color: #a6a6a6;
        padding: 10px 12px;
        text-align: center;
        font-size: 12px;
        border-top: 1px solid #111111;
      }
      .photo-story .amp-carousel-button {top: 100px;}
      .photo-story amp-carousel {
        height: 500px;
      }
      .nav-right{position: absolute; top: 0; right: 0; width: 100px;}
      .nav-right .phone .fa{width: 20px; height: 20px; border: 1px solid; border-radius: 50%; text-align: center; line-height: 18px; margin-top:  3px;}
      .nav-right .comment .fa{margin-top:  3px; font-size: 20px;}
      .nav-right .share .fa{margin-top:  5px; font-size: 18px;}
      #navbar .social-share h2{height: 24px; margin: 0; left: 70px;}
      #navbar .social-share .share-link{padding: 5px 10px; background-color: #a00606; margin-top: 5px;}
      #navbar .social-share .share-link a{ display: inline-block; vertical-align: middle; color: #fff; font-size: 20px; }
      #navbar .social-share .share-link a + a{margin-left: 10px;}
      .node-type-photogallery #header, .node-type-videogallery #header{margin: 0;}
      .node-type-photogallery .front-end-breadcrumb, 
      .node-type-videogallery .front-end-breadcrumb{background-color: #171717; padding-bottom: 0;}
      .buzz-img .social-share{position: absolute; left: 0; bottom: 28px; width: 100px; z-index: 999; background-color: transparent; height: 22px;}
      .buzz-img .social-share h2{padding: 0; width: 22px; height: 21px; border: none; background-color: #222; color: #fff; text-align: center;}
      .buzz-img .social-share ul{list-style: none; top: -22px; left: 22px; height: 22px; background-color: #222; width: 70px; padding: 2px 0 0 3px;}
      .buzz-img .social-share ul li{float: left;}
      .buzz-img .social-share ul li a{color: #fff; font-size: 20px; margin-right: 5px;}
      .factoids-page{display: inline-block; vertical-align: top; width: 100%; margin-bottom: 20px;}
      .fun-facts{float: left;}
      .factoids-page .social-share{height: 22px;}
      .factoids-page .social-share h2{padding: 0; width: 22px; height: 22px; border: none; background-color: #fff; color: #aaa; text-align: center;left: 5px;}
      .factoids-page .social-share ul{list-style: none; top: -25px; left: 110px; height: 22px; background-color: #fff; width: 80px; padding: 2px 0 0 3px;}
      .factoids-page .social-share ul li{float: left;}
      .factoids-page .social-share ul li a{color: #222; font-size: 22px; margin-right: 5px;}
      .quotes {
          margin: 5px 0 5px 15px;
      }
      blockquote {
          color: #000;
          font: 600 20px/28px "Roboto Slab",sans-serif;
          position: relative;
          text-align: justify;
          text-indent: 40px;
      }
      .quotes .author {
          font-size: 12px;
          color: #828282;
          text-align: right;
      }
      blockquote:before {
        content: "\201C";
        display: inline-block;
        font: bold 60px/28px Georgia, serif;
        vertical-align: baseline;
        position: absolute;
        left: 0;
        top: 12px;
        text-indent: 0;
      }
     blockquote:after {
        content: "\201D";
        display: inline-block;
        font: bold 60px/0px Georgia, serif;
        vertical-align: top;
        text-indent: 10px;
        margin-top: 32px;
      }
      .description table{border: 1px solid #ddd; border-collapse: collapse; width: 100%;}
      .description table td{border: 1px solid #ddd; padding: 5px;}
      .rtejustify {
          text-align: justify;
      }
      .rtecenter {
          text-align: center;
      }
      .rteright {
          text-align: right;
      }
      .photo-story .carousel-preview button{position: relative;}
      .photo-story .carousel-preview button .counter{position: absolute; left: 0; top: 0; width: 100%; height: 100%; background-color: rgba(0,0,0,.3); color: #fff; padding-top: 28px; cursor: pointer;}
      .amp-carousel-button{width: 30px; background: none; cursor: pointer;}
      .amp-carousel-button-prev{left: 0;}
      .amp-carousel-button-next{right: 0;}
      .amp-carousel-button-next:before{padding-left: 3px; box-sizing: border-box;content: '\f054'; position: absolute; text-align: center; font-size: 20px; right: 0; top: 0; width: 28px; height: 34px; line-height: 34px; color: #fff;font-family: fontawesome; background: rgba(0,0,0,.5); border-radius: 3px 0 0 3px;}
      .amp-carousel-button-prev:before{padding-right: 3px; box-sizing: border-box;content: '\f053'; position: absolute; text-align: center; font-size: 20px; left: 0; top: 0; width: 28px; height: 34px; line-height: 34px; color: #fff;font-family: fontawesome; background: rgba(0,0,0,.5); border-radius: 0 3px 3px 0;}
      .amp-photo-slider .amp-carousel-button{height: 60px;}
      .amp-photo-slider .amp-carousel-button-next:before{padding-left: 12px; text-align: left; height: 60px; right: -30px; width: 60px; line-height: 60px; color: #000; background: rgba(255,255,255,.5); border-radius: 100%;}
      .amp-photo-slider .amp-carousel-button-prev:before{padding-right: 12px; text-align: right; height: 60px; left: -30px; width: 60px; line-height: 60px; color: #000; background: rgba(255,255,255,.5); border-radius: 100%;}
      @keyframes blinker { from {opacity:1.0;} to {opacity:0.0;} }
      .blurb {
        padding: 0 10px;
        border-left: 2px solid #d1d1d1;
        margin: 10px 0;
        text-align: justify;
        font-style: italic;
        color: #8d8d8d;
        font-family: Roboto;
      }
      .search-form {
        position: absolute;
        right: 10px;
        top: 10px;
      }
      .search-form input[type="search"] {
        height: 28px;
        width: 200px;
        padding-right: 35px;
        padding-left: 10px;
      }
      .search-form input[type="submit"] {
        position: absolute;
        top: 0;
        right: 0;
        width: 30px;
        height: 28px;
        border: none;
        padding: 0;
        margin: 0;
        z-index: 99;
        opacity: 0;
      }
      a.search {
        position: absolute;
        right: 0;
        top: 0;
        color: #666;
        font-size: 20px;
        width: 30px;
        height: 28px;
        z-index: 9;
        padding-top: 3px;
        text-align: center;
      }
    </style>
    <?php //endif;  ?>
    <script async src="https://cdn.ampproject.org/v0.js"></script>
  </head>
  <body class="<?php print $classes; ?>" <?php print $attributes; ?>>
    <?php //if (!empty($amp_skip_link)):  ?>
    <?php //print render($amp_skip_link); ?>
    <?php //endif; ?>
    <?php print $page_top; ?>
    <?php print $page; ?>
    <?php print $page_bottom; ?>
  </body>
</html>
