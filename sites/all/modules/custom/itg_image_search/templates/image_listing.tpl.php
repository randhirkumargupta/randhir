


<div>
  <ul>
     <?php foreach ($data as $data_imageids): ?>
    <li>
        <?php $file = file_load($data_imageids['image_id']);
        $url = file_create_url($file->uri);?>
        <img src="<?php echo $url;?>" class="searched-image" height="250" width="250" imageid="<?php echo $file->fid;?>"/>
     
    </li>
      <?php endforeach; ?>
    
  </ul>
</div>