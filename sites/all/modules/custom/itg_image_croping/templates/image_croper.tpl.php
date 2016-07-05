<script type="text/javascript" src="<?php echo base_path().'sites/all/modules/custom/itg_image_croping/js/jquery.min.js';?>"></script>

<script type="text/javascript" src="<?php echo base_path().'sites/all/modules/custom/itg_image_croping/js/jquery.cropit.js';?>"></script>

<style>
      .cropit-preview {
        background-color: #f8f8f8;
        background-size: cover;
        border: 1px solid #ccc;
        border-radius: 3px;
        margin-top: 7px;
        width: <?php echo $image_width;?>px;
        height:<?php echo $image_height;?>px;
      }

      .cropit-preview2 {
        background-color: #f8f8f8;
        background-size: cover;
        border: 1px solid #ccc;
        border-radius: 3px;
        margin-top: 7px;
        width: 450px;
        height: 250px;
      }

      .cropit-preview-image-container {
        cursor: move;
      }

      .image-size-label {
        margin-top: 10px;
      }

      input {
        display: block;
      }

      button[type="submit"] {
        margin-top: 10px;
      }

      #result {
        margin-top: 10px;
        width: 900px;
      }

      #result-data {
        display: block;
        overflow: hidden;
        white-space: nowrap;
        text-overflow: ellipsis;
        word-wrap: break-word;
      }
      .first-resize,.second-resize{width:48%;float:left;padding: 30px 0;}
      .cropit-image-zoom-input{display: inline-block;}
    </style>

  <?php 

  
  $imagedata= base64_encode(file_get_contents($data->uri));
  $url = file_create_url($data->uri);
   ?>
   

 
   
 <div class="croper">
 <div class="first-resize">
   <?php echo $form;?>
    </div>

     <button class="crop-image">Crop</button>
    </div>

<!--   -->

    <script>
      jQuery(function() {
         // alert(1)
      jQuery('.image-editor').cropit({
           imageState: {
          src: '<?php echo $url;?>',
          },
        
          });
        jQuery('form').submit(function() {
          // Move cropped image data to hidden input
          var imageData = jQuery('.image-editor').cropit('export');
          jQuery('.hidden-image-data').val(imageData);

          // Print HTTP request params
          var formValue = $(this).serialize();
          jQuery('#result-data').text(formValue);

          // Prevent the form from actually submitting
          return false;
        });
         
      });
       


        jQuery('.crop-image').click(function() {
        showloader();
        var field_name=jQuery('#data_field_name').val();
        var image_data_first = jQuery('.image-editor').cropit('export');
        jQuery.ajax({
        url: Drupal.settings.basePath+'savecropedimage',
        type: 'post',
        data: {'image_data': image_data_first,'field_name':field_name},
        success: function(data) {
           
        var objdata=jQuery.parseJSON(data);
        var image_fiedlid=objdata.fid;
        var htmls=jQuery(window.opener.document).find('[name="'+field_name+'[und][0][fid]"]').val(image_fiedlid);
        
        window.opener.jQuery("body").find("input[name='"+field_name+"[und][0][filefield_itg_image_repository][button]").addClass('progress-disabled');
        window.opener.jQuery("body").find("input[name='"+field_name+"[und][0][filefield_itg_image_repository][button]").trigger('mousedown');
        window.close();
        
        },
        error: function(xhr, desc, err) {
        console.log(xhr);
        console.log("Details: " + desc + "\nError:" + err);
        }
        }); // end ajax call

        });
    </script>

    <?php die;?>
