	

<?php $url = file_create_url($data->uri);
 global $base_url;
?>
 <link rel="stylesheet" type="text/css" href="<?php echo $base_url.'/'.drupal_get_path('module', 'itg_image_croping') . '/css/itg_tagging.css';?>">

<div id="container">
    <div id="imgtag"> 

        <img id="" src="<?php echo $url;?>" alt="" /> 
        <div id="tagbox">
        </div>
    </div> 
    <div id="taglist"> 
        <ol> 
        </ol> 
    </div> 
    
</div>
     <input type="hidden" value="<?php echo $data->fid; ?>" id="image_fiedlid">
<div id="loader-data" style="display: none"><img class="widget-loader" src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." /></div>


<?php

drupal_add_js(drupal_get_path('module', 'itg_image_croping') . '/js/jquery.min.js', array('
  type' => 'file', 'scope' => 'content'));
drupal_add_js(drupal_get_path('module', 'itg_image_croping') . '/js/itg_image_front.js', array('
  type' => 'file', 'scope' => 'content'));

print $js = drupal_get_js('content');
?>
