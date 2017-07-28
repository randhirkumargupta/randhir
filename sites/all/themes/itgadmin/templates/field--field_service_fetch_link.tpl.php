<div class="field field-name-field-service-fetch-link field-type-text field-label-above">
    <div class="field-label">Via Web URL:&nbsp;</div>
    <div class="field-items">
        <div class="field-item even">
            <?php
            $link = strip_tags($items[0]['#markup']);
            $curr_date = date('d-m-Y');
            echo l($link . "?date=$curr_date", $link, array("query" => array('date' => $curr_date) ,"attributes" => array("title" => t("date format must be dd-mm-yyyy"))));
            ?>
        </div>
    </div>
</div>