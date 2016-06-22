<div id="tabs" class="variables-tabs">
    <?php foreach ($data as $CT => $val) { ?>
        <div  style="display:none;" id="tab-<?php print $CT ?>"><strong><?php print str_replace("_", " ", $CT); ?></strong>
                <?php
                $array_table = array_chunk($val, 6);
                print theme("table", array("rows" => $array_table));
                ?>

        </div>
    <?php } ?>
</div>
