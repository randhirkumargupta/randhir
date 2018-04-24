<?php if (!empty($data)) : global $base_url, $theme; ?>
<div class="karnataka-partylist">
  <div class="partylist-body">
  <ul>
    <?php foreach($data as $value){?>
    <li><span class="party-logo"><img src="<?php print file_create_url($value->uri);?>" alt="<?php print $value->field_cm_display_title_value;?>"></span><span class="party-details"><h6><?php print $value->field_cm_display_title_value;?></h6><p><?php print $value->field_story_kicker_text_value;?></p></span></li>
    <?php }?>
  </ul>
</div> 
</div>
<?php endif;?>  
<style type="text/css">
               .karnataka-partylist {border: 1px solid #d4d4d4; position: relative; padding: 10px; border-radius:5px;}
               .partylist-body{ height:350px; overflow-y:auto; }
               .karnataka-partylist:before{content: "";height: 6px;width: 100%; left: 0;position: absolute;bottom: 0px;background: #ffff00; border-radius:0px 0px 5px 5px;}
               .karnataka-partylist ul li{ display:block; overflow: hidden; border-bottom:1px solid #ededed; padding:5px 0; list-style: none;}
              .karnataka-partylist ul li span.party-logo{ width:85px; display: block; float:left; margin-right: 10px;}
              .karnataka-partylist ul li span.party-details{display: block; float: left; width: calc(100% - 95px); padding-top: 8px;}
              .karnataka-partylist ul li span.party-details h6{ margin:0; padding-bottom:5px; font-weight:600; font-size:14px; text-transform: uppercase; line-height: 16px;}
              .karnataka-partylist ul li span.party-details p{ font-size:13px; color:#969696; padding:0px; line-height:15px; margin:0px;}
             </style>