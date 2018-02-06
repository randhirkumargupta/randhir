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
        <script async src="https://cdn.ampproject.org/v0.js"></script>
        <script async custom-element="amp-carousel" src="https://cdn.ampproject.org/v0/amp-carousel-0.1.js"></script>
        <script async custom-element="amp-bind" src="https://cdn.ampproject.org/v0/amp-bind-0.1.js"></script>
        <script async custom-element="amp-dailymotion" src="https://cdn.ampproject.org/v0/amp-dailymotion-0.1.js"></script>
        <script async custom-element="amp-jwplayer" src="https://cdn.ampproject.org/v0/amp-jwplayer-0.1.js"></script>
        <script async custom-element="amp-accordion" src="https://cdn.ampproject.org/v0/amp-accordion-0.1.js"></script>
        <script async custom-element="amp-social-share" src="https://cdn.ampproject.org/v0/amp-social-share-0.1.js"></script>
        <script async custom-element="amp-twitter" src="https://cdn.ampproject.org/v0/amp-twitter-0.1.js"></script>
        <script async custom-element="amp-facebook" src="https://cdn.ampproject.org/v0/amp-facebook-0.1.js"></script>
        <script async custom-element="amp-form" src="https://cdn.ampproject.org/v0/amp-form-0.1.js"></script>
        <script async custom-element="amp-video" src="https://cdn.ampproject.org/v0/amp-video-0.1.js"></script>
        <script async custom-element="amp-iframe" src="https://cdn.ampproject.org/v0/amp-iframe-0.1.js"></script>
        <script async custom-element="amp-instagram" src="https://cdn.ampproject.org/v0/amp-instagram-0.1.js"></script>
        <script async custom-element="amp-ad" src="https://cdn.ampproject.org/v0/amp-ad-0.1.js"></script>
        <script async custom-element="amp-analytics" src="https://cdn.ampproject.org/v0/amp-analytics-0.1.js"></script>

        <style amp-custom>
            #header,
#navbar {
    position: relative
}
.copyright,
p {
    word-wrap: break-word
}
.collapsible-captions *,
.footer-latest * {
    -webkit-tap-highlight-color: rgba(255, 255, 255, 0)
}
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    outline: 0;
    border: none
}
body {
    font: 400 14px/18px 'Roboto Slab';
    color: #333
}
h1,
h2,
h3,
h4,
h5,
h6 {
    font-family: Roboto
}
h1 {
    font-size: 25px;
    font-weight: 600;
    line-height: 30px
}
p {
    line-height: 24px;
    margin: 10px 0;
    white-space: normal
}
img {
    max-width: 100%
}
#page-wrapper {
    max-width: 750px;
    margin: 0 auto
}
#main-wrapper {
    padding: 0 12px
}
.node-type-photogallery #main-wrapper,
.node-type-videogallery #main-wrapper {
    padding: 0
}
#header {
    margin-bottom: 0;
    z-index: 9999;
    box-shadow: 0 6px 5px -3px rgba(0, 0, 0, .1);
    height: 45px
}
#logo {
    margin: 12px 5px;
    display: inline-block;
    vertical-align: top;
    position: absolute;
    z-index: 10
}
#navbar {
    width: 100%
}
#navbar h2 {
    width: 20px;
    text-align: center;
    background: 0 0;
    border: none;
    padding: 3px 0;
    color: #5e5e5e;
    height: 28px;
    top: -4px;
    left: 5px
}
#navbar amp-accordion h2 span {
    position: absolute;
    left: 0;
    top: 3px
}
#navbar h2[aria-expanded=false] .show-less,
#navbar h2[aria-expanded=true] .show-more {
    opacity: 0
}
.header-menu {
    position: absolute;
    left: 0;
    top: 47px;
    list-style: none;
    width: 270px;
    background-color: #a41615;
    z-index: 10
}
.photo-slide .caption,
.photoby {
    bottom: 0;
    background-color: #222;
    font-size: 12px;
    font-family: Roboto;
    left: 0
}
.header-menu li a {
    padding: 0 10px;
    text-decoration: none;
    color: #fff;
    border-top: 1px solid rgba(255, 255, 255, .7);
    display: block;
    font-family: Roboto;
    height: 35px
}
.header-menu li:first-child a {
    border-top: none
}
.posted-by {
    margin: 10px 0;
    font-size: 12px;
    color: #8c8c8c;
    font-family: Roboto
}
.stryimg {
    position: relative
}
.photoby:empty {
    display: none
}
.photoby {
    position: absolute;
    width: 100%;
    color: #aeaeae;
    padding: 5px 10px
}
.description a {
    color: #0883ed
}
.description ol,
.description ul {
    padding-left: 18px
}
.image-alt {
    color: #aeaeae;
    font-size: 12px;
    font-family: Roboto;
    padding: 10px 0;
    border-bottom: 1px solid #ddd
}
.related-story ul {
    list-style: none
}
.related-story ul li {
    display: inline-block;
    vertical-align: top;
    width: 100%;
    padding: 10px 0
}
.related-story ul li+li {
    border-top: 1px solid #ddd
}
.related-story ul li .tile {
    float: left;
    width: 75%;
    padding-right: 10px
}
.related-story ul li .tile a {
    color: #000;
    text-decoration: none
}
.related-story ul li>a {
    float: right;
    width: 25%
}
.photo-slide {
    position: relative;
    text-align: center
}
.photo-slide .caption {
    position: absolute;
    width: 100%;
    color: #aeaeae;
    padding: 5px 10px
}
.other-date,
.other-title a {
    font-family: "Roboto Slab"
}
.story-right {
    padding-bottom: 30px
}
.carousel-preview {
    white-space: nowrap;
    overflow: auto
}
.carousel-preview button {
    margin-right: 10px
}
.listicle-feedback .listical_title {
    text-transform: uppercase;
    font-weight: 700;
    line-height: 24px
}
.story-section .listicle-page .listicle-detail+.listicle-detail {
    border-top: 1px solid #ccc
}
.story-section .listicle-page .listicle-detail>span {
    width: 24px;
    height: 24px;
    background: #a00606;
    border-radius: 100%;
    font-size: 14px;
    text-align: center;
    line-height: 24px;
    color: #fff;
    font-weight: 700;
    margin: 20px 0 0;
    float: left
}
.story-section .listicle-page .listicle-detail>span.bullet_points {
    width: 10px;
    height: 10px;
    line-height: 10px;
    margin-top: 27px
}
.story-section .listicle-page .listicle-detail .listicle-description {
    font-size: 14px;
    color: #282828;
    padding: 18px 10px;
    overflow: hidden;
    line-height: 24px
}
.story-section .listicle-page .listicle-detail .listicle-description span {
    font-weight: 600;
    text-transform: capitalize
}
.scroll-x {
    overflow-x: auto
}
.factoids-slider ul {
    background: #a00606;
    padding: 0;
    margin-top: 20px;
    display: table;
    vertical-align: top;
    list-style: none
}
.factoids-slider ul li {
    padding: 25px;
    font-size: 15px;
    line-height: 24px;
    color: #fff;
    display: table-cell;
    vertical-align: top;
    min-width: 220px;
    white-space: normal
}
.factoids-slider ul li:nth-child(odd) {
    background: #a00606
}
.factoids-slider ul li:nth-child(even) {
    background: #000
}
.buzz-feedback .buzz-section,
.buzz-feedback .buzz-section h1 {
    margin-bottom: 20px
}
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
    margin: 0 12px 0 0
}
.buzz-img-wrapper {
    position: relative
}
.story-photo-list-wrapper h3 {
    text-transform: uppercase;
    font-weight: 700;
    color: #bb0a0a;
    position: relative
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
    margin: auto
}
.story-photo-list-wrapper h3 span {
    background: #fff;
    z-index: 1;
    position: relative;
    padding: 20px 20px 20px 0;
    display: inline-block
}
.story-photo-list-wrapper .story-photo-list {
    overflow-x: auto;
    white-space: nowrap
}
.amp-other-gallery ul,
.amp-photo-slider,
.red-star {
    overflow: hidden
}
.story-photo-list-wrapper .story-photo-list-item {
    padding: 0 11px;
    width: 192px;
    display: inline-block;
    vertical-align: top
}
.story-photo-list-wrapper .story-photo-list-item p {
    line-height: 18px
}
.smp-date {
    font-size: 12px;
    color: #b1b1b1;
    display: block
}
.story-section .story-tech-chunk .field-label{
	display: none;
}
.field .field-label {
    font-weight: 700
}
.story-section .story-right .stryimg .photoby .story-img-rating {
    background: #b00808;
    display: inline-block;
    vertical-align: top;
    padding: 5px 10px;
    font-size: 22px;
    font-weight: 700;
    color: #fff;
    line-height: 20px;
    position: absolute;
    bottom: 100%;
    left: 0
}
.movie-rating {
    width: 111px;
    height: 18px;
    margin: 20px 0;
    position: relative;
    background: url(/sites/all/themes/itg/images/rating-grey.png) 0 0px no-repeat;
}
.movie-rating:after{
	content: '';
    position: absolute;
    left: 0;
    top: 0;
    background: url(/sites/all/themes/itg/images/rating-red.png) 0 0px no-repeat;
    height: 60px;
    width: 0;
	}
.movie-rating[data-star-value="10%"]:after {
  width: 10%; }
.movie-rating[data-star-value="20%"]:after {
  width: 20%; }
.movie-rating[data-star-value="30%"]:after {
  width: 30%; }
.movie-rating[data-star-value="40%"]:after {
  width: 40%; }
.movie-rating[data-star-value="50%"]:after {
  width: 50%; }
.movie-rating[data-star-value="60%"]:after {
  width: 60%; }
.movie-rating[data-star-value="70%"]:after {
  width: 70%; }
.movie-rating[data-star-value="80%"]:after {
  width: 80%; }
.movie-rating[data-star-value="90%"]:after {
  width: 90%; }
.movie-rating[data-star-value="100%"]:after {
  width: 100%; }

.grey-star,
.red-star {
    position: absolute;
    top: 0;
    left: 0
}
.grey-star {
    z-index: 9
}
.red-star {
    z-index: 10
}
.story-section .story-movie .movie-detail div+div {
    margin-top: 15px
}
.story-section .story-movie .movie-detail div .title {
    float: left;
    padding-right: 7px;
    width: 60px
}
.story-section .story-movie .movie-detail div .detail {
    display: block;
    overflow: hidden
}
.black-box {
    margin: 0 -12px 20px;
    padding: 10px;
    background-color: #171717
}
.photo-title {
    font-size: 32px;
    margin: 20px 0;
    color: #fff;
    line-height: 42px
}
.amp-other-gallery h2 {
    text-transform: uppercase;
    font-weight: 700;
    color: #bb0a0a;
    position: relative
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
    margin: auto
}
.amp-other-gallery h2 span {
    background: #fff;
    z-index: 1;
    position: relative;
    padding: 20px 20px 20px 0;
    display: inline-block
}
.amp-photo-slider .photo-slide .caption {
    width: auto
}
.amp-photo-slider .amp-carousel-button {
    top: 25%
}
.front-end-breadcrumb-photo-video+.black-box .amp-photo-slider .amp-carousel-button,
.node-type-photogallery .amp-photo-slider .amp-carousel-button {
    top: 42%
}
.node-type-videogallery .amp-photo-slider .amp-carousel-button {
    top: 34%
}
.amp-photo-slider p {
    color: #a1a1a1;
    line-height: 24px
}
.video-caption span {
    display: block;
    padding-top: 20px;
    color: #fff
}
.amp-other-gallery ul {
    list-style: none;
    margin: 0 -6px
}
.amp-other-gallery ul li {
    display: inline-block;
    width: 180px;
    padding: 0 5px 10px;
    max-width: 49.5%;
    vertical-align: top
}
.other-img {
    position: relative
}
.other-count {
    position: absolute;
    bottom: 0;
    padding: 5px;
    left: 0;
    background-color: rgba(0, 0, 0, .6);
    color: #fff;
    font-size: 12px
}
.other-count .fa {
    font-size: 14px
}
.other-date {
    display: block;
    font-size: 12px;
    color: #b1b1b1;
    padding: 8px 0 5px
}
#block-itg-layout-manager-front-end-breadcrumb div.lft,
.footer-top-link ul li,
.front-end-breadcrumb>div {
    display: inline-block;
    vertical-align: top
}
.other-title a {
    color: #494949;
    line-height: 18px;
    text-decoration: none
}
.amp-photo-ad {
    text-align: center
}
.node-story h1 a {
    color: #0883ed;
    text-decoration: none
}
.node-story h1 a:hover {
    color: #0883ed;
    text-decoration: underline
}
#footer a,
#header a {
    text-decoration: none
}
.story-section h1 i {
    font-size: 13px;
    color: #f40000;
    animation-name: blinker;
    animation-iteration-count: infinite;
    animation-timing-function: cubic-bezier(1, 0, 0, 1);
    animation-duration: 1s
}
#block-itg-layout-manager-front-end-breadcrumb a,
.front-end-breadcrumb,
.front-end-breadcrumb a {
    color: #a1a1a1;
    font-family: roboto
}
.story-right .description iframe {
    width: 100%;
    max-width: 100%
}
pre {
    white-space: inherit
}
.amp-carousel-button {
    z-index: 99;
    visibility: visible;
    opacity: 1
}
#block-itg-layout-manager-front-end-breadcrumb {
    position: relative;
    z-index: 9998;
    color: #a1a1a1;
    font-family: roboto
}
.front-end-breadcrumb {
    margin: 0 -12px;
    padding: 20px 12px;
    font-size: 14px
}
.front-end-breadcrumb.front-end-breadcrumb-photo-video {
    background-color: #171717;
    padding-bottom: 0
}
#footer {
    background-color: #000;
    color: #fff;
    margin-top: 30px;
    font-family: roboto;
    position: relative
}
#footer ul {
    list-style: none
}
#footer a {
    color: #a6a6a6;
    font-family: Roboto, sans-serif
}
#footer a:hover {
    color: #ffc106
}
.footer-bottom-menu,
.footer-top-link {
    white-space: nowrap;
    overflow-x: auto;
    border-bottom: 1px solid #111;
    position: relative;
    z-index: 9
}
.footer-top-link {
    padding-right: 40px
}
.footer-top-link ul li {
    margin: 6px 12px
}
.footer-top-link ul li a {
    display: block;
    height: 37px;
    line-height: 37px;
    font-size: 15px;
    text-transform: uppercase
}
.footer-bottom-menu {
    padding-bottom: 10px
}
.footer-bottom-menu .menu-col {
    display: inline-block;
    vertical-align: top;
    margin: 6px 12px;
    width: 170px
}
.footer-bottom-menu h4 {
    text-transform: uppercase;
    margin: 20px 0 5px
}
.footer-bottom-menu ul li {
    padding: 3px 0
}
#footer amp-accordion h2 {
    width: 40px;
    height: 49px;
    text-align: center;
    padding: 0;
    border: none;
    background: #000;
    margin-top: -50px;
    z-index: 99;
    position: absolute;
    right: 0;
    top: 0
}
#footer amp-accordion h2 span.show-less,
#footer amp-accordion h2 span.show-more {
    line-height: 48px
}
#footer amp-accordion h2[aria-expanded=false] span.show-less,
#footer amp-accordion h2[aria-expanded=true] span.show-more {
    display: none
}
.copyright {
    color: #a6a6a6;
    padding: 10px 12px;
    text-align: center;
    font-size: 12px;
    border-top: 1px solid #111;
    white-space: normal
}
.photo-story .amp-carousel-button {
    top: 100px
}
.photo-story amp-carousel {
    height: 500px
}
.nav-right {
    position: absolute;
    top: 0;
    right: 0;
    width: 100px
}
.nav-right .phone .fa {
    width: 20px;
    height: 20px;
    border: 1px solid;
    border-radius: 50%;
    text-align: center;
    line-height: 18px;
    margin-top: 3px
}
.nav-right .comment .fa {
    margin-top: 3px;
    font-size: 20px
}
.nav-right .share .fa {
    margin-top: 5px;
    font-size: 18px
}
#navbar .social-share h2 {
    height: 24px;
    margin: 0;
    left: 70px
}
#navbar .social-share .share-link {
    padding: 5px 10px;
    background-color: #a00606;
    margin-top: 5px
}
#navbar .social-share .share-link a {
    display: inline-block;
    vertical-align: middle;
    color: #fff;
    font-size: 20px
}
#navbar .social-share .share-link a+a {
    margin-left: 10px
}
.node-type-photogallery #header,
.node-type-videogallery #header {
    margin: 0
}
.node-type-photogallery .front-end-breadcrumb,
.node-type-videogallery .front-end-breadcrumb {
    background-color: #171717;
    padding-bottom: 0;
    margin: 0
}
.node-type-photogallery .black-box,
.node-type-videogallery .black-box {
    margin-left: 0;
    margin-right: 0
}
.node-type-photogallery .amp-other-gallery,
.node-type-videogallery .amp-other-gallery {
    padding: 0 12px
}
.buzz-img .social-share {
    position: absolute;
    left: 0;
    bottom: 28px;
    width: 100px;
    z-index: 999;
    background-color: transparent;
    height: 22px
}
.buzz-img .social-share h2 {
    padding: 0;
    width: 22px;
    height: 21px;
    border: none;
    background-color: #222;
    color: #fff;
    text-align: center
}
.buzz-img .social-share ul {
    list-style: none;
    top: -22px;
    left: 22px;
    height: 22px;
    background-color: #222;
    width: 70px;
    padding: 2px 0 0 3px
}
.buzz-img .social-share ul li {
    float: left
}
.buzz-img .social-share ul li a {
    color: #fff;
    font-size: 20px;
    margin-right: 5px
}
.factoids-page {
    display: inline-block;
    vertical-align: top;
    width: 100%;
    margin-bottom: 20px
}
.fun-facts {
    float: left
}
.factoids-page .social-share {
    height: 22px
}
.factoids-page .social-share h2 {
    padding: 0;
    width: 22px;
    height: 22px;
    border: none;
    background-color: #fff;
    color: #aaa;
    text-align: left;
    left: 5px
}
.factoids-page .social-share ul {
    list-style: none;
    top: -24px;
    left: 120px;
    height: 22px;
    background-color: #fff;
    width: 80px;
    padding: 2px 0 0 3px
}
.factoids-page .social-share ul li {
    float: left
}
.factoids-page .social-share ul li a {
    color: #222;
    font-size: 22px;
    margin-right: 5px
}
.quotes {
    margin: 5px 0 5px 15px
}
blockquote {
    color: #000;
    font: 600 20px/28px "Roboto Slab", sans-serif;
    position: relative;
    text-align: justify;
    text-indent: 40px
}
.quotes .author {
    font-size: 12px;
    color: #828282;
    text-align: right
}
blockquote:before {
    content: "\201C";
    display: inline-block;
    font: 700 60px/28px Georgia, serif;
    vertical-align: baseline;
    position: absolute;
    left: 0;
    top: 12px;
    text-indent: 0
}
blockquote:after {
    content: "\201D";
    display: inline-block;
    font: 700 60px/0 Georgia, serif;
    vertical-align: top;
    text-indent: 10px;
    margin-top: 32px
}
#header .top-nav .main-nav li.desktop-hide,
#header .top-nav .main-nav ul.menu li.desktop-hide {
    display: none
}
.description table {
    border: 1px solid #ddd;
    border-collapse: collapse;
    width: 100%
}
.description table td {
    border: 1px solid #ddd;
    padding: 5px
}
.rtejustify {
    text-align: justify
}
.rtecenter {
    text-align: center
}
.rteright {
    text-align: right
}
.photo-story .carousel-preview button {
    position: relative
}
.photo-story .carousel-preview button .counter {
    position: absolute;
    left: 0;
    top: 0;
    width: 100%;
    height: 100%;
    background-color: rgba(0, 0, 0, .3);
    color: #fff;
    padding-top: 28px;
    cursor: pointer
}
.amp-carousel-button {
    width: 30px;
    background: 0 0;
    cursor: pointer
}
.amp-carousel-button-next:before,
.amp-carousel-button-prev:before {
    text-align: center;
    top: 0;
    width: 28px;
    height: 34px;
    line-height: 34px;
    color: #fff;
    font-family: fontawesome;
    background: rgba(0, 0, 0, .5);
    font-size: 20px;
    position: absolute;
    box-sizing: border-box
}
.amp-carousel-button-prev {
    left: 0
}
.amp-carousel-button-next {
    right: 0
}
.amp-carousel-button-next:before {
    padding-left: 3px;
    content: '\f054';
    right: 0;
    border-radius: 3px 0 0 3px
}
.amp-carousel-button-prev:before {
    padding-right: 3px;
    content: '\f053';
    left: 0;
    border-radius: 0 3px 3px 0
}
.amp-photo-slider .amp-carousel-button-next:before,
.amp-photo-slider .amp-carousel-button-prev:before {
    height: 60px;
    width: 60px;
    line-height: 60px;
    color: #000;
    background: rgba(255, 255, 255, .5);
    border-radius: 100%
}
.amp-photo-slider .amp-carousel-button {
    height: 60px
}
.amp-photo-slider .amp-carousel-button-next:before {
    padding-left: 12px;
    text-align: left;
    right: -30px
}
.amp-photo-slider .amp-carousel-button-prev:before {
    padding-right: 12px;
    text-align: right;
    left: -30px
}
@keyframes blinker {
    from {
        opacity: 1
    }
    to {
        opacity: 0
    }
}
.blurb {
    padding: 0 10px;
    border-left: 2px solid #d1d1d1;
    margin: 10px 0;
    text-align: justify;
    font-style: italic;
    color: #8d8d8d;
    font-family: Roboto
}
.search-form input[type=search] {
    height: 28px;
    width: 225px;
    padding-right: 35px;
    padding-left: 10px;
    position: absolute;
    left: 10px;
    top: 5px;
    background-color: transparent;
    transition: width .4s cubic-bezier(0, .795, 0, 1);
    cursor: pointer;
    z-index: 3;
    opacity: 1;
    border: 1px solid #ccc
}
.search-form input[type=submit] {
    position: absolute;
    top: 0;
    right: 0;
    width: 30px;
    height: 28px;
    border: none;
    padding: 0;
    margin: 0;
    z-index: 2;
    opacity: 0
}
a.search {
    position: absolute;
    right: 0;
    top: 0;
    color: #fff;
    font-size: 20px;
    width: 30px;
    height: 28px;
    z-index: 2;
    padding-top: 3px;
    text-align: center
}
.custom-amp-ad {
    text-align: center
}
#header .top-nav {
    padding: 0 0 0 5px;
    margin: 25px auto 15px;
    float: none;
    zoom: 1;
    background: 0 0
}
#header a {
    color: #a9a9a9;
    font-family: Roboto;
    font-size: 16px;
    margin: 0
}
.mobile-nav .bar1,
.mobile-nav .bar2,
.mobile-nav .bar3 {
    width: 20px;
    height: 2px;
    background-color: #5e5e5e;
    margin: 4px 0;
    transition: .4s
}
.collapsible-captions figcaption,
.footer-latest figcaption {
    bottom: 0;
    transition: max-height .2s cubic-bezier(.4, 0, .2, 1);
    z-index: 1000
}
#header .main-nav .nav-container-menu {
    width: calc(100% - 28px);
    margin: 0 auto
}
#header .top-nav .main-nav ul.menu {
    float: left
}
#header .top-nav ul {
    list-style-type: none
}
#header .main-nav .desktop-hide {
    float: left;
    padding-left: 10px;
    position: absolute;
    width: 38px;
    height: 38px
}
#header .top-nav ul li {
    display: inline-block;
    vertical-align: top;
    margin: 0 5px
}
#header .headeritg-logo {
    float: left;
    width: 70px;
    text-align: center;
    height: 40px
}
#header .logo {
    width: 70px;
    position: absolute;
    top: -10px
}
#header .top-nav ul.menu li.last.leaf,
.fa-search,
.navimgamp {
    position: relative
}
#header .logo a {
    display: block;
    overflow: visible;
    margin: 0
}
.navimgamp {
    width: 21px;
    height: 20px;
    margin: 0 10px 0 0;
    display: inline-block;
    top: 5px
}
.search-section-amp {
    height: 35px
}
.fa-search {
    top: 10px;
    right: 5px
}
ul.header-menu li:first-child {
    margin: 5px 0
}
#header .top-nav ul.menu li a {
    padding: 0 3px;
    font-size: 13px;
    text-transform: uppercase;
    font-weight: 500
}
#header .top-nav .top-first-menu ul.menu li.last.leaf:after {
    position: absolute;
    width: 5px;
    height: 5px;
    display: inline-block;
    top: 8px;
    left: 0;
    box-shadow: 0 0 0 rgba(214, 2, 12, .8);
    border-radius: 50%;
    background: #c00;
    animation: pulse 1.7s infinite;
    content: "";
    margin-left: -3px;
}
.container.top-nav .main-nav .nav-container-menu .nav-centerall {
    width: 296px;
    margin: 0 auto
}
.footer-latest * {
    box-sizing: border-box
}
.footer-latest .fixed-height-container {
    position: relative;
    width: 100%;
    height: var(--image-height)
}
.footer-latest amp-img img {
    object-fit: contain
}
.footer-latest figure {
    margin: 0;
    padding: 0
}
.footer-latest figcaption {
    position: absolute;
    margin: 0;
    width: 100%;
    max-height: var(--caption-height);
    line-height: var(--caption-height);
    padding: 0 var(--button-size);
    white-space: nowrap;
    overflow: hidden;
    text-overflow: ellipsis;
    color: var(--caption-color);
    background: var(--caption-bg-color)
}
.footer-latest figcaption.expanded1 {
    padding: var(--button-size);
    line-height: inherit;
    white-space: normal;
    text-overflow: auto;
    max-height: calc(var(--caption-height) + var(--image-height));
    overflow: auto
}
.footer-latest figcaption:focus {
    outline: 0;
    border: none
}
.footer-latest figcaption span {
    display: block;
    position: absolute;
    top: calc((var(--caption-height) - var(--button-size))/ 2);
    right: 2px;
    width: var(--button-size);
    height: var(--button-size);
    line-height: var(--button-size);
    text-align: center;
    font-size: 12px;
    color: inherit;
    cursor: pointer
}
.live-block .breaking-section.breaking-section {
    border-top: 1px solid #ddd
}
.live-block .breaking-section {
    padding: 10px 0;
    line-height: 22px;
    margin-top: 20px
}
#live-blog-amp-share h2[aria-expanded=false] .show-less,
#live-blog-amp-share h2[aria-expanded=true] .show-more {
    opacity: 0
}
#live-blog-amp-share h2 {
    border: none;
    background-color: #fff
}
.collapsible-captions,
.collapsible-captions figcaption,
.footer-latest {
    background: var(--caption-bg-color)
}
#live-blog-amp-share .show-less {
    position: relative;
    left: -18px
}
#live-blog-amp-share .social-share a {
    margin-right: 5px
}
#live-blog-amp-share .social-share .fa-twitter-square {
    color: #03a4d2;
    font-size: 30px
}
#live-blog-amp-share .social-share .fa-facebook-official {
    color: #09488b;
    font-size: 30px
}
#live-blog-amp-share .social-share .fa-google-plus-square {
    font-size: 30px;
    color: #b00808
}
#live-blog-amp-share .social-share #_AMP_content_0 {
    top: -5px;
    left: 25px;
    transform: translateY(-60%)
}
.live-block .breaking-section amp-instagram {
    width: 490px;
    margin: 0 auto
}
.live-block .timeline {
    border-bottom: 1px solid #ddd;
    padding-bottom: 25px;
    margin-bottom: 25px
}
.collapsible-captions {
    --caption-height: 32px;
    --image-height: 300px;
    --caption-padding: 1rem;
    --button-size: 28px;
    --caption-color: #f5f5f5;
    --caption-bg-color: #000
}
.collapsible-captions * {
    box-sizing: border-box
}
.collapsible-captions .fixed-height-container {
    position: relative;
    width: 100%;
    height: var(--image-height)
}
.collapsible-captions amp-img img {
    object-fit: contain
}
.collapsible-captions figure {
    margin: 0;
    padding: 0
}
.collapsible-captions figcaption {
    position: absolute;
    margin: 0;
    width: 100%;
    max-height: var(--caption-height);
    line-height: var(--caption-height);
    padding: 0 var(--button-size);
    white-space: nowrap;
    overflow: hidden;
    text-overflow: ellipsis;
    color: var(--caption-color)
}
.collapsible-captions figcaption.expanded {
    padding: var(--button-size);
    line-height: inherit;
    white-space: normal;
    text-overflow: auto;
    max-height: calc(var(--caption-height) + var(--image-height));
    overflow: auto
}
.collapsible-captions figcaption:focus {
    outline: 0;
    border: none
}
.collapsible-captions figcaption span {
    display: block;
    position: absolute;
    top: calc((var(--caption-height) - var(--button-size))/ 2);
    right: 2px;
    width: var(--button-size);
    height: var(--button-size);
    line-height: var(--button-size);
    text-align: center;
    font-size: 12px;
    color: inherit;
    cursor: pointer
}
.footer-latest {
    --caption-height: 42px;
    --image-height: 300px;
    --caption-padding: 1rem;
    --button-size: 28px;
    --caption-color: #f5f5f5;
    --caption-bg-color: #000
}
.story-section .story-tech-chunk .tech-rating {
    width: 88px;
    height: 33px;
    background: #b00808;
    color: #fff;
    font-size: 28px;
    position: absolute;
    top: 0;
    right: 10px;
    text-align: center;
    line-height: 33px;
    font-weight: 700
}
.tech-pros-cons-main h2 {
    font-size: 28px;
    line-height: 45px;
    color: #000;
    font-weight: 700;
    padding: 0 0 0 10px;
    float: left;
    margin-left: 42%;
    width: 58%;
    margin-bottom: 10px
}
.tech-pros-cons-main h2 strong {
    font-size: 30px;
    line-height: 35px;
    color: #fff;
    background-color: #b00808;
    float: right;
    padding: 0 10px
}
ul.pron-cons-img {
    width: 42%;
    float: left;
    list-style: none
}
ul.tech-pron-cons-img {
    width: 41.66666667%;
    float: left
}
ul.tech-cons,
ul.tech-pros {
    list-style: disc;
    width: 27%;
    float: left
}
ul.tech-pros {
    margin-left: 4%
}
ul.tech-cons li,
ul.tech-pros li {
    font-size: 14px;
    line-height: 26px;
    color: #939393;
    float: left;
    width: 100%
}
ul.tech-cons li span,
ul.tech-pros li span {
    color: #b00808;
    font-size: 17px;
    font-weight: 700;
    line-height: 24px;
    list-style: none;
    margin-left: -14px;
    text-transform: uppercase
}
ul.tech-cons li:first-child,
ul.tech-pros li:first-child {
    list-style: none
}
ul.pron-cons-img li img {
    margin-right: 10%;
    margin-top: -53px;
    width: 92%
}
.tech-pros-cons-main {
    width: 100%;
    padding: 10px;
    background-color: #edebec;
    overflow: hidden;
}
.tech-photos .tech-photos-head-section {
    display: block
}
.tech-photos .tech-photos-head-section .tech-photos-count {
    color: #B5B5B5;
    font-size: 13px;
    margin-bottom: 10px;
    display: block
}
.tech-photos {
    text-align: center
}
.tech-photos .tech-photo-item {
    display: inline-block;
    margin-right: 3%;
    position: relative
}
.tech-photos .tech-photo-item .tech-photo-overlay {
    position: absolute;
    top: 0;
    left: 0;
    text-align: center;
    color: #fff;
    background: rgba(0, 0, 0, .7);
    width: 100%;
    height: 100%
}
.tech-photos .tech-photo-item .tech-photo-overlay a .tech-photo-seemore {
    position: absolute;
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
    line-height: 22px
}
.tech-photos .tech-photo-item .tech-photo-overlay a,
.tech-photos .tech-photo-item .tech-photo-overlay a span:hover {
    color: #fff;
    text-decoration: underline
}
.tech-photos-count,
h3.tech-photo-head {
    text-align: left
}
nav#navbar amp-accordion {
    position: absolute;
}
ul.header-menu {
    background: #fff;
    border-right: 1px solid #ccc;
    top: 18px;
}
ul.header-menu li {
    border-bottom: 1px solid #ccc;
    width: 270px;
}
.story_ad_block.custom-amp-ad{margin-top:15px;}
.node-type-photogallery .story_ad_block.custom-amp-ad, .node-type-videogallery .story_ad_block.custom-amp-ad{margin-bottom:8px;}
section.sidebar .block-itg-ads > div {
    margin: auto;
}
.custom-amp-ad.ad-btf{margin-bottom:50px;}
button.searchbut{float: right; width: 27px; height: 27px; margin-right: 5px;} button.searchbut .fa-search { top: 1px; right: 0px;}
.node-type-story .posted-by{overflow:hidden;}
.node-type-story .posted-by .profile-pic, .node-type-story .posted-by .profile-detail { float: left;}
.node-type-story .posted-by .profile-pic{width: 50px;height: 50px; border-radius: 50%;}
.node-type-story .posted-by .profile-pic img { width: 50px;height: 50px; border-radius: 50%;border: 2px solid #e4e4e4;}
.node-type-story .posted-by .profile-detail li{list-style:none; font-size:12px;}
.node-type-story .posted-by .profile-detail{width: 78%; margin: 0 0 0 15px;}
.node-type-story .posted-by .profile-detail ul.profile-byline ul li.title{display: inline-block;color: #6b6b6b;font-size: 12px;line-height:14px;font-weight: 500; border-left:1px solid #ddd;padding:0 5px;}
.node-type-story .posted-by .profile-detail ul.profile-byline ul li.title:nth-child(1){border-left:0px;padding-left:0px;}
.node-type-story .posted-by .profile-detail ul.profile-byline ul{ font-size:0px; margin:0px;line-height: 0px;}
@media only screen and (max-width: 767px) {
    ul.pron-cons-img {
        width: 100%
    }
    .tech-pros-cons-main h2 {
        margin-left: 0;
        width: 100%
    }
    ul.pron-cons-img li img {
        margin-top: 0
    }
    ul.tech-cons,
    ul.tech-pros {
        width: 100%;
        margin-left: 6%;
        box-sizing: border-box
    }
}

.video_dec_amp {
    text-align: left;
  }
        </style>
    </head>
    <?php
    $node_title = '';
    if (arg(0) == 'node' && arg(1) && is_numeric(arg(1))) {
      $node = menu_get_object('node');
      $node_title = $node->title;
    }
    ?>
    <body class="<?php print $classes; ?>" <?php print $attributes; ?>>
        <?php print $page_top; ?>
        <?php print $page; ?>
        <?php print $page_bottom; ?>
    <amp-analytics type="comscore">
		<script type="application/json">
			{
			  "vars": {
				"c2": "8549097"
			  }
			}
		</script>
	</amp-analytics>
	<amp-analytics type="googleanalytics" id="analytics2"><script type="application/json">
	{
	  "vars": {
		"account": "UA-34080153-10"
	  },
	  "triggers": {
		"defaultPageview": {
		  "on": "visible",
		  "request": "pageview",
		  "vars": {
			"title": "<?php print $node_title;?>"
		  }
		}
	  }
	}
	</script></amp-analytics>
    </body>
</html>
