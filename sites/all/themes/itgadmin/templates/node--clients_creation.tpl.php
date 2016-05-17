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
		<div class="content-rows">
		      <div class="content-rows">
			<div class="clent-left"><strong>Client Title:</strong> </div> 
		       <div class="clent-right"><?php print render($title); ?> </div>
		     </div>
		</div>
              	<h2>Business Contact</h2>
		<div class="content-rows">
	              
		       <div class="clent-right"><?php print render($content['field_contact_person_name']); ?> </div>
		</div>
		<div class="content-rows">
	              
		       <div class="clent-right"><?php print render($content['field_email_address']); ?> </div>
		</div>
		<div class="content-rows">
	               
		       <div class="clent-right"><?php print render($content['field_mobile_number']); ?> </div>
		</div>

		<h2>Technical Contact</h2>
		<div class="content-rows">
	              
		       <div class="clent-right"><?php print render($content['field_contact_tech_person_name']); ?> </div>
		</div>
		<div class="content-rows">
	               
		       <div class="clent-right"><?php print render($content['field_contact_tech_email_address']); ?> </div>
		</div>
		<div class="content-rows">
	              
		       <div class="clent-right"><?php print render($content['field_contact_tech_mobile_number']); ?> </div>
		</div>

            </div>
 </div>      

    </div>
  <?php endif; ?>

  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

