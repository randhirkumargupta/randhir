<?php
$itg_image_repository = & $itg_image_repository_ref['itg_image_repository']; //keep this line.
global $base_url;
?>

<script type="text/javascript">
<!--//--><![CDATA[//><!--
    itg_image_repository.hooks.load.push(itg_image_repository.initiateShortcuts); //shortcuts for directories and files
    itg_image_repository.hooks.load.push(itg_image_repository.initiateSorting); //file sorting
    itg_image_repository.hooks.load.push(itg_image_repository.initiateResizeBars); //area resizing

    //inline preview
    itg_image_repository.hooks.list.push(itg_image_repository.thumbRow);
    itg_image_repository.vars.tMaxW = 120; //maximum width of an image to be previewed inline
    itg_image_repository.vars.tMaxH = 120; //maximum height of an image to be previewed inline
    itg_image_repository.vars.prvW = 40; //maximum width of the thumbnail used in inline preview.
    itg_image_repository.vars.prvH = 40; //maximum height of the thumbnail used in inline preview.
    //itg_image_repository.vars.prvstyle = 'stylename'; //preview larger images inline using an image style(imagecache preset).

    //enable box view for file list. set box dimensions = preview dimensions + 30 or more
    //itg_image_repository.vars.boxW = 100; //width of a file info box
    //itg_image_repository.vars.boxH = 100; //height of a file info box

    //itg_image_repository.vars.previewImages = 0; //disable click previewing of images.
    //itg_image_repository.vars.cache = 0; //disable directory caching. File lists will always refresh.
    //itg_image_repository.vars.absurls = 1; //make itg_image_repository return absolute file URLs to external applications.
//--><!]]>
</script>

<div id="itg_image_repository-content" class="">

    <div id="message-box"></div>
    <div class="list-head image_repository">
        <div class="div-upload-img active" >Upload</div>
        <div class="div-search-img" disabled="disabled">Search</div>

    </div>

    <!-- 
    <div id="ops-wrapper">
      <div id="op-items"><ul id="ops-list"><li></li></ul></div>
      <div id="op-contents"></div>
    </div> -->

    <div id="resizable-content">

        <div id="browse-wrapper">

            <!-- <div id="navigation-wrapper">
               <div class="navigation-text" id="navigation-header"><span><?php //print t('Navigation');   ?></span></div>
               <ul id="navigation-tree"><li class="expanded root"><?php //print $tree;   ?></li></ul>
             </div>
            -->

            <div id="navigation-resizer" class="x-resizer"></div>

            <div id="sub-browse-wrapper">

                <div id="file-header-wrapper">
                    <table id="file-header" class="files"><tbody><tr>
                                <td class="name"><?php print t('File name'); ?></td>
                                <td class="size"><?php print t('Size'); ?></td>
                                <td class="width"><?php print t('Width'); ?></td>
                                <td class="height"><?php print t('Height'); ?></td>
                                <td class="date"><?php print t('Date'); ?></td>
                            </tr></tbody></table>
                </div>

                <div id="file-list-wrapper">
                    <?php print theme('itg_image_repository_file_list', array('itg_image_repository_ref' => $itg_image_repository_ref)); /* see itg_image_repository-file-list-tpl.php */ ?>
                </div>

                <div id="dir-stat"><?php
                    print t('!num files using !dirsize of !quota', array(
                        '!num' => '<span id="file-count">' . count($itg_image_repository['files']) . '</span>',
                        '!dirsize' => '<span id="dir-size">' . format_size($itg_image_repository['dirsize']) . '</span>',
                        '!quota' => '<span id="dir-quota">' . ($itg_image_repository['quota'] ? format_size($itg_image_repository['quota']) : ($itg_image_repository['tuquota'] ? format_size($itg_image_repository['tuquota']) : t('unlimited quota'))) . '</span>'
                    ));
                    ?>
                </div>

            </div><!-- sub-browse-wrapper -->
        </div><!-- browse-wrapper -->

    </div>

    <div id="forms-wrapper"><?php print $forms; ?></div>

</div><!-- itg_image_repository-content -->
<div id="browse-resizer" class="y-resizer"></div>
<div id="loader-data" style="display: none"><img class="widget-loader" src="<?php echo $base_url; ?>/sites/all/themes/itgadmin/images/loader.svg" alt="Loading..." /></div>
<div id="preview-wrapper"><div id="search-preview" style="display:none"><iframe onload="hideloader();" src="<?php echo base_path() . 'searchimage?keyword=' . $term; ?>" width="900" height="650"></iframe> 
    </div><div id="file-preview"></div></div>
<script>
    jQuery('.div-upload-img').addClass('active');
    jQuery('#forms-wrapper,#loader-data ').show();
    jQuery('#imce-search-form').remove();
</script>
