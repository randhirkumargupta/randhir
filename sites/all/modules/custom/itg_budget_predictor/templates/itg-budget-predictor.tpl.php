<?php
if (!empty($data)) {
    global $base_url, $user;
    $budget_type = '1';
    $ip_address = $_SERVER['REMOTE_ADDR'];
    $column1 = '';
    $column2 = '';
    $column3 = '';

    $column4 = '';
    $user_id = $user->uid;
    foreach ($data as $key => $node_data) {
        $tid = $node_data['tid'];
        $name = $node_data['name'];
        $fid = $node_data['image'];
        $file = file_load($fid);
        $uri = $file->uri;
        if ($tid) {
            $column4 .= '<li id="entry_' . $tid . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
    }
    foreach ($data['ranking'] as $keys => $values) {
        $entity_id = $values['entity_id'];
        $fid = get_ranking_fid($entity_id);
        $file = file_load($fid);
        $uri = $file->uri;
        if ($values['ranking_column'] == '1') {
            $column1 .= '<li id="entry_' . $entity_id . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
        if ($values['ranking_column'] == '2') {
            $column2 .= '<li id="entry_' . $entity_id . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
        if ($values['ranking_column'] == '3') {
            $column3 .= '<li id="entry_' . $entity_id . '" class="ui-state-default"><img src="' . image_style_url("thumbnail", $uri) . '"></li>';
        }
    }
}

?>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; utf-8" />
        <title>Pilotmade Sortables Demo</title>
        <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.4.1/jquery.min.js"></script>
        <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.7.2/jquery-ui.min.js"></script>

        <style type="text/css">
            #sortable1, #sortable2, #sortable3, #sortable4 { width:15%; min-height:400px; border:1px solid #ccc; background:#f3f3f3;list-style-type: none; margin: 0; padding: 0; float: left; margin-right: 10px; }
            #sortable1 li, #sortable2 li, #sortable3 li, #sortable4 li { display:block; background:#e3e3e3; cursor:move;margin: 0 5px 5px 5px; padding: 5px; font-size: 1.2em;}
        </style>
    </head>
    <body>

        <p class="success" style="display:none;">Success</p>
        <div id="ranking-content">
            <div id="ranking-label">CHEAPER</div>    
            <ul id="sortable1" class="connectedSortable">
                <?php echo $column1; ?>
            </ul>
        </div>
        <div id="ranking-content">
            <div id="ranking-label">DEARER</div>    
            <ul id="sortable2" class="connectedSortable">
                <?php echo $column2; ?>
            </ul>
        </div>
        <div id="ranking-content">
            <div id="ranking-label">NONE</div>    
            <ul id="sortable3" class="connectedSortable">
                <?php echo $column3; ?>
            </ul>
        </div>
        <div id="ranking-content">
            <div id="ranking-label"></div>    
            <ul id="sortable4" class="connectedSortable">
                <?php echo $column4; ?>
            </ul>
        </div>
    </body>
</html>