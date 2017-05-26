<?php if($form['row_count']) {
 echo "No Record Found !";
} else {?>
<form  method="post" id="section-wise-widget-form" accept-charset="UTF-8">
    <div>
        <table class="views-table">
            <thead>
                <tr>
                  <th><?php echo t("S.No") ?></th>
                  <th><?php echo t("Title") ?></th>
                  <th><?php echo t("Node Id") ?></th>
                  <th><?php echo t("Type") ?></th>
                  <th><?php echo t("Categories") ?></th>
                  <th><?php echo t("Created On") ?></th>
                  <th><?php echo t("Posted By") ?></th>
                  <th><?php echo t("Weight") ?></th>
                </tr>
            </thead>
            <tbody>
        <?php $sr = 0; foreach($form['widget_data'] as $key=>$form_data) : ?>
        	<?php if(is_numeric($key)) : ?>
        		<?php $row_data = _get_section_wise_widget_node_data($form_data['nid']['#value']); ?>
        		<tr>
        		<td><?php echo $sr++; ?></td>
        		<td><?php echo l($row_data['title'] , "node/".$row_data['nid'] , array("attributes" => array("target" => "_blank"))) ?></td>
        		<td><?php echo $row_data['nid']; ?></td>
        		<td><?php echo $row_data['type']; ?></td>
        		<td><?php echo _get_sections_name_related_to_nid($row_data['nid']); ?></td>
        		<td><?php echo date('d/m/Y' , $row_data['created']); ?></td>
        		<td><?php echo l($row_data['name'] , "user/".$row_data['uid'] , array("attributes" => array("target" => "_blank"))); ?></td>
        		<td>
		        <div class="form-item form-type-textfield form-item-widget-data-<?php echo $key; ?>weight">
                <input  required="required" id="edit-widget-data-<?php echo $key; ?>-weight" name="widget_data[<?php echo $key ?>][weight]" value="<?php echo $form_data['weight']['#value'] ?>" size="60" maxlength="128" class="form-text number-field" type="number" min="0">
		        </div>
		        <input name="widget_data[<?php echo $key ?>][nid]" value="<?php echo $form_data['nid']['#value'] ?>" type="hidden">
		        <input name="widget_data[<?php echo $key ?>][content_type]" value="<?php echo $form_data['content_type']['#value'] ?>" type="hidden">
		        <input name="widget_data[<?php echo $key ?>][cat_id]" value="<?php echo $form_data['cat_id']['#value'] ?>" type="hidden">
		        </td>
		        </tr>
    		<?php endif; ?>
    	<?php endforeach; ?>
            </tbody>
    	</table>
        <input name="form_build_id" value="<?php echo $form['form_build_id']['#value'] ?>" type="hidden">
        <input name="form_token" value="<?php echo $form['form_token']['#value'] ?>" type="hidden">
        <input name="form_id" value="<?php echo $form['form_id']['#value']; ?>" type="hidden">
        <br/>
        <input id="edit-submit" name="op" value="save" class="form-submit" type="submit">
    </div>
    <?php echo drupal_render($form['content_type_hint']); ?>
    <?php echo drupal_render($form['pagger']); ?>
</form>
<?php } ?>