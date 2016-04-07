<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
      <?php endif; ?>

      <?php if (!empty($submitted)): ?>
        <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
      <?php endif; ?>
        <?php
        //p($node);
        echo $node->moderation_history_block;
        ?>
      <!-- add && !$teaser for hide comment link -->
      <?php if (!empty($links) && !$teaser): ?>
        <div class='<?php print $hook ?>-links clearfix'>
          <?php print render($links) ?>
        </div>
      <?php endif; ?>

      <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($layout): ?>
    <div class='column-main'><div class='column-wrapper'>
      <?php endif; ?>

      <?php if (!empty($title_prefix)) print render($title_prefix); ?>

      <?php if (!empty($title) && !$page): ?>
        <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
          <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
          <a href="<?php print $node_url ?>"><?php print $title ?></a>
        </h2>
      <?php endif; ?>

      <?php if (!empty($title_suffix)) print render($title_suffix); ?>

      <?php if (!empty($content)): ?>
        <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
          <?php
          //print render($content) 
          //print '<pre>';
         // print_r($content);
         // print '</pre>';
          //exit;
           if ($node->op == 'Preview') {
          ?>

             
   
          
          <div class="content-node-view">
            <div class="poll-details">
              <h2><?php echo t('Client Client'); ?></h2>
              <div class="content-details">
                <?php
                $field_client_title = render($content['field_client_title']);
                if (!empty($field_client_title)): print $field_client_title;
                endif;
                ?>
                 <h3><?php echo t('Business Contact'); ?></h3>  
                <?php
                $field_short_description = render($content['field_short_description']);
                if (!empty($field_short_description)): print $field_short_description;
                endif;
                ?>
                <?php
                $field_email_address = render($content['field_email_address']);
                if (!empty($field_email_address)): print $field_email_address;
                endif;
                ?>
                
                <?php
                $field_mobile_number = render($content['field_mobile_number']);
                if (!empty($field_mobile_number)): print $field_mobile_number;
                endif;
                ?>
                 <h3><?php echo t('Technical Contact'); ?></h3>   
                <?php
                $field_contact_tech_person_name = render($content['field_contact_tech_person_name']);
                if (!empty($field_contact_tech_person_name)): print $field_contact_tech_person_name;
                endif;
                ?>
                <?php
                $field_contact_tech_email_address = render($content['field_contact_tech_email_address']);
                if (!empty($field_contact_tech_email_address)): print $field_contact_tech_email_address;
                endif;
                ?>
                <?php
                $field_contact_tech_mobile_number = render($content['field_contact_tech_mobile_number']);
                if (!empty($field_contact_tech_mobile_number)): print $field_contact_tech_mobile_number;
                endif;
                ?>
              </div>
            </div>
        </div>
           <?php } ?>
          
         </div>
      <?php endif; ?>
        
      <?php if ($layout): ?>
      </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object)  ?>
