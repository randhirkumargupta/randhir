<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
    <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
      <div class='column-side'><div class='column-wrapper'>
            <?php endif; ?>

            <?php if (!empty($submitted)): ?>
              <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
            <?php endif; ?>

            <?php if (!empty($links)): ?>
              <div class='<?php print $hook ?>-links clearfix'>
                  <?php print render($links) ?>
              </div>
            <?php endif; ?>

            <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
          </div></div>
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
                  <div class="content-node-view">               
                      <h2>Client Details</h2>
                      <div class="content-view">
                          <div class="field">
                              <div class="field-label"><strong><?php print t('Client Title:'); ?></strong> </div> 
                              <div class="field-items"><?php print render($title); ?> </div>
                          </div>
                          <h2><?php print t('Business Contact'); ?></h2>
                          <?php print render($content['field_contact_person_name']); ?>
                          <?php print render($content['field_contact_business_email']); ?>
                          <?php print render($content['field_mobile_number']); ?>
                          <?php if (isset($node->field_contact_tech_person_name)): ?> 
                            <h2><?php print t('Technical Contact'); ?></h2>
                            <?php print render($content['field_contact_tech_person_name']); ?>
                            <?php print render($content['field_contact_tech_email_address']); ?>
                            <?php print render($content['field_contact_tech_mobile_number']); ?>
                          <?php endif; ?>   
                          <?php if (isset($node->field_content_sharing_mode)) { ?> 
                            <h2><?php print t('Sharing Mode'); ?></h2>
                            <?php
                            if (trim($node->field_content_sharing_mode[LANGUAGE_NONE][0]['value']) == 1) {
                              $latest_url = itg_mobile_get_latest_feed_byurl($node->nid);
                              //$path = file_create_url('public://');
                              global $base_url;
                              foreach ($latest_url as $row) {
                                $service_name = end(explode('/', $row->clients_feed_url));
                                $real_path = $base_url . '/vas/' . $row->service_id . '/' . $service_name;
                                print '<div class="field field-name-field-service-fetch-link field-type-text field-label-above"><div class="field-label">Latest Feed Link:&nbsp;</div><div class="field-items"><div class="field-item even">';
                                print "<a target='_blank' href='" . $real_path . "'>" . $real_path . "</a>";

                                print '</div></div></div>';
                              }

                              print '<div class="field field-name-field-service-fetch-link field-type-text field-label-above"><div class="field-label">Fetch link:&nbsp;</div><div class="field-items"><div class="field-item even">';
                              //  print "<a href='" . $node->field_service_fetch_link[LANGUAGE_NONE][0]['value'] . "'>Sharing url</a>";
                              global $base_url;
                              $protected_url = $base_url . '/admin/config/system/protected_pages';
                              print "  <div class='protected_url'><a href='" . $protected_url . "'>Protected url</a></div>";
                              print '</div></div></div>';
                            }
                            else if (trim($node->field_content_sharing_mode[LANGUAGE_NONE][0]['value']) == 2) {
                              print render($content['field_ftp_ip_address']);
                              print render($content['field_ftp_username']);
                              print render($content['field_ftp_password']);
                            }
                            else if (trim($node->field_content_sharing_mode[LANGUAGE_NONE][0]['value']) == 3) {
                              print render($content['field_service_email_address']);
                            }
                            ?>
                          <?php } ?>
                      </div>
                  </div>  
              </div>
            <?php endif; ?>

            <?php if ($layout): ?>
          </div></div>
    <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

