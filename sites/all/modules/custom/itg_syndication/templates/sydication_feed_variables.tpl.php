<?php if (!empty($content_type)): ?>
    <div id="tabs" class="variables-tabs">
        <div>
            <strong>Predefine variables for "<?php print $content_type; ?>"</strong>
            <?php
            $array_table = array_chunk($data, 6);
            print theme("table", array("rows" => $array_table));
            ?>
        </div>
    </div>
<?php endif; ?>
