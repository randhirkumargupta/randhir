


<?php global $base_url;?>
<meta charset="utf-8">
<title>Untitled Document</title>
<meta name="viewport" content="width=device-width, initial-scale=1">

<link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet" integrity="sha384-wvfXpqpZZVQGK6TAh5PVlGOfQNHSoD2xbE+QkPxCAFlNEevoEH3Sl0sibVcOQVnN" crossorigin="anonymous">



<div class="row">
<div class="col-md-12 col-sm-7 col-xs-12 left-panel arts">
<!-- Slider Start-->

<h2>INDIA'S BEST ARTS COLLEGES 2016</h2>
<div class="slider_outer1">
<div id="myCarousel" class="carousel slide" data-ride="carousel">
    <!-- Indicators -->


    <!-- Wrapper for slides -->
    <div class="carousel-inner" role="listbox">

     <?php
                if (array_filter(views_get_view_result('best_college_image_slider', 'block_2'))) {
                    print views_embed_view('best_college_image_slider', 'block_2');
                }

              ?>




  <div class="clearfix"></div>
    </div>



  </div>
</div>

<!-- Slider End-->

<!-- Grid View-->
<div class="col-sm-12 col-xs-12 view1">
<div class="title col-md-6 col-sm-6 col-xs-12">Best of The Best 2016</div>

        <div class="right_Section pull-right  col-md-6  col-sm-6 col-xs-12 text-right hidden-xs">
        <strong>view as</strong>
        <div class="btn-group">
            <a href="#" id="list" class="btn btn-default btn-sm"><span class="fa fa-th-list"></span> List</a>
            <a href="#" id="grid" class="btn btn-default btn-sm active_btn"><span class="fa fa-th"></span> Grid</a>
        </div>
        </div>
</div>

<div>
<div class="clearfix"></div>
<div class="col-sm-12 remove_padd_right">
<div id="products" class="row list-group">
      <div class="clr_chn">

              <?php
                if (array_filter(views_get_view_result('best_college_image_slider', 'block_1'))) {
                    print views_embed_view('best_college_image_slider', 'block_1');
                }

              ?>



            </div>
        </div>
</div>
</div>
</div>

<!-- Right Side -->


<!-- Grid View End-->

</div>
