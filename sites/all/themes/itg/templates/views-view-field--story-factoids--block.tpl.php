<?php
/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
if (isset($row->field_field_story_template_factoids) && !empty($row->field_field_story_template_factoids)) {
  $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
  $short_url = shorten_url($actual_link, 'goo.gl');
  $title = 'Factoids';
  $share_desc = $row->field_field_story_template_factoids[0]['raw']['value'];
  //print '';
  ?>

<div class="factoids-page">
  <div class="fun-facts"><h2>Funfacts</h2> </div>
  <div class="social-share">
  <ul>
      <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
      <li><a class="facebook" href="javascript:void(0)" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $title; ?>', '<?php print $share_desc; ?>')"><i class="fa fa-facebook"></i></a></li>
      <li><a class="twitter" href="javascript:" onclick="twitter_popup('<?php print urlencode($title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
      <li><a class="google" title="share on google+" href="javascript:void(0)" onclick="return googleplusbtn('<?php print $actual_link; ?>')"></a></li>
  </ul>      
  </div>
  
</div>


  
<div class="factoids-slider">
  <?php
  print $output;
  ?>
</div>
  <?php
}
?>

<script>
jQuery(document).ready(function(){
    jQuery('.factoids-slider .item-list ul').slick({                
        slidesToShow: 3,
        slidesToScroll: 1,  
        infinite: false,
        centerPadding: '20px',
        prevArrow: "<button class = 'slick-prev'><i class = 'fa fa-angle-left'></i></button>",
        nextArrow: "<button class = 'slick-next'><i class = 'fa fa-angle-right'></i></button>",
         responsive: [
            {
              breakpoint: 768,
              settings: {                
                slidesToShow: 2,
                centerPadding: '10px'
              }
            },
            {
              breakpoint: 480,
              settings: {                
                slidesToShow: 1,
                centerPadding: '10px'
              }
            }
         ]
    });    
});
</script>