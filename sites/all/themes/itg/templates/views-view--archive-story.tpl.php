<?php
/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <?php print $title; ?>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($header): ?>
      <div class="view-header">
          <?php print $header; ?>
      </div>
    <?php endif; ?>

    <?php if ($exposed): ?>
      <!--start-->
      <?php
      global $base_url;
      $month = date("m");
      $day = date("d");
      $year = date("Y");
      $arg = arg();
      ?>
      <div class="archive-header">
          <div id="archive-story-date-slider">
              <ul>
                  <?php for ($i = 30; $i >= 1; $i--) { ?>
                    <?php
                      $li_active_class = '';
                      $current_filter_date = date('d-m-Y', mktime(0, 0, 0, $month, ($day - $i), $year));
                      if ($current_filter_date == $_GET['ds_changed']['date']) {
                        $li_active_class = 'active';                        
                      }
                      
                      if(empty($arg[1])) {
                        $uri =  $base_url.'/archives'.'/'.date('d-m-Y', mktime(0, 0, 0, $month, ($day - $i), $year));
                      } else {
                        $uri = $base_url.'/archives/'.$arg[1].'/'. date('d-m-Y', mktime(0, 0, 0, $month, ($day - $i), $year));
                      }
                    ?>
                    <li class="atleta <?php print $li_active_class;?>"> <a href="<?php print $uri; ?>">

                            <span><?php print date('d', mktime(0, 0, 0, $month, ($day - $i), $year)); ?></span>
                            <?php print date('M', mktime(0, 0, 0, $month, ($day - $i), $year)); ?>

                        </a></li>
                  <?php } ?>
              </ul>
          </div>
          <div class="archive-calender-custom">
              <?php print $exposed; ?>
          </div>
      </div>

      <!--end start-->    
    <?php endif; ?>

    <?php if ($attachment_before): ?>
      <div class="attachment attachment-before">
          <?php print $attachment_before; ?>
      </div>
    <?php endif; ?>

    <?php if ($rows): ?>
      <div class="view-content">
          <?php print $rows; ?>
      </div>
    <?php elseif ($empty): ?>
      <div class="view-empty">
          <?php print $empty; ?>
      </div>
    <?php endif; ?>

    <?php if ($pager): ?>
      <?php print $pager; ?>
    <?php endif; ?>

    <?php if ($attachment_after): ?>
      <div class="attachment attachment-after">
          <?php print $attachment_after; ?>
      </div>
    <?php endif; ?>

    <?php if ($more): ?>
      <?php print $more; ?>
    <?php endif; ?>

    <?php if ($footer): ?>
      <div class="view-footer">
          <?php print $footer; ?>
      </div>
    <?php endif; ?>

    <?php if ($feed_icon): ?>
      <div class="feed-icon">
          <?php print $feed_icon; ?>
      </div>
    <?php endif; ?>

</div><?php /* class view */ ?>