<?php /*<?php foreach($rows as $index => $row){
    $video_class="";
    if(strtolower($row['type'])=='videogallery')
    {
       $video_class='content-video'; 
    }
    $desc="";
    if($row['field_story_kicker_text']!="")
    {
        $desc = $row['field_story_kicker_text'];
    }else if($row['field_story_kicker_text']=="" && $row['body']!=""){
         $desc = $row['body'];
    }
   if($index==0){?>
       <div class="first-buying-guid-block <?php echo $video_class;?>"><?php print $row['field_story_extra_large_image'];?></div>
<div><?php echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></div>
   <?php }else{
?>
<div class="<?php echo $video_class;?>"><?php print $row['field_story_extra_large_image'];?></div>
<div><?php echo $row['title']; ?></div>

<div><?php echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></div>
   <?php } ?>

<?php }; ?>

*/?>

<div class="row buying-guides">
    <div class="col-md-6">

        <a href="http://52.76.214.186/stage/content/ms-dhoni-trailer-sushant-singh-rajput-neeraj-pandey-unleash-helicopter-shots-promising">
            <img src="http://52.76.214.186/stage/sites/default/files/styles/section_ordering_widget/public/gallery/sushant-story_647_081216101317.jpg?itok=--n6LLmM">
        </a>

        <h3>Which Kindle? All are great but only 3 worth buying</h3>

        <ul>
            <li>
                <span class="title">Reader</span>
                <p><a href="#">Over 30 people killed in Brussels terror attacks, cops crackdown protest </a></p>
            </li>            
        </ul>

    </div>

    <div class="col-md-6">

        <ul>
            <li>
                <span class="title">Reader</span>
                <p><a href="#">Over 30 people killed in Brussels terror attacks, cops crackdown protest </a></p>
            </li>
            <li>
                <span class="title">Reader</span>
                <p><a href="#">Over 30 people killed in Brussels terror attacks, cops crackdown protest </a></p>
            </li>
            <li>
                <span class="title">Reader</span>
                <p><a href="#">Over 30 people killed in Brussels terror attacks, cops crackdown protest </a></p>
            </li>
            <li>
                <span class="title">Reader</span>
                <p><a href="#">Over 30 people killed in Brussels terror attacks, cops crackdown protest </a></p>
            </li>

        </ul>

    </div>



</div>