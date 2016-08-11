<?php
global $user, $base_url;
?>
<?php
if (isset($_GET["section"]) && isset($_GET["template_name"])) {
?>
<div class="layout-button" id="<?php print $_GET['template_name']?>-button">    
    <a class="btn btn-save" href="javascript:void(0)" id="layout-button-save">Publish</a>
<!--    <a class="btn btn-preview" href="javascript:void(0)" id="layout-button-preview">Preview</a>-->
    <a class="colorbox-load btn btn-preview" href="<?php print $base_url.'/itg-layout-manager/'.arg(1).'/preview/?section='.$_GET["section"].'&template_name='. $_GET["template_name"].'&width=1240&height=700' ?>">Preview</a>
    <a class="btn btn-cancel mr-0" href="javascript:void(0)" id="layout-button-cancel">Cancel</a>
</div>

<?php } ?>