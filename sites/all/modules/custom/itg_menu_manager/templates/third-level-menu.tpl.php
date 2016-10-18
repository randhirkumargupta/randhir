<div class="menu-wrapper" style="background: #595959">
    <div class="container">
        <div class="row">
            <div class="col-md-4">
                <?php
                if (isset($_GET['section']) && !empty($_GET['section'])) {
                    $cat_id = $_GET['section'];
                } else {
                    $cat_id = arg(2);
                }
                $section_banner_data = taxonomy_term_load($cat_id);
                $uri = $section_banner_data->field_cm_category_banner['und'][0]['uri'];
                $src = file_create_url($uri);
                if (!empty($src) && isset($uri)) {
                    print "<img src='" . $src . "'>";
                }
                ?>
            </div>
            <div class="col-md-8">
                <ul class="third-level-menu">
                    <?php foreach ($data as $key => $menu_data) : ?>
                        <?php
                        $link_url = "";
                        $target = "_self";
                        $link_text = isset($menu_data['term_load']->name) ? $menu_data['term_load']->name : $menu_data['db_data']['title'];
                        $url_type = $menu_data['db_data']['url_type'];
                        $db_target = $menu_data['db_data']['target'];
                        $tid = $menu_data['db_data']['tid'];
                        // if tid is not 0 then its internal url
                        if ($tid && $url_type == 'internal') {
                            $link_url = "taxonomy/term/$tid";
                        } else {
                            $link_url = $menu_data['db_data']['url'];
                        }
                        // manage target
                        if (trim($db_target) == 'new_window') {
                            $target = "__blank";
                        }
                        ?>
                        <li><?php print l($link_text, $link_url, array('attributes' => array('target' => $target, 'class' => array("third-level-child", "third-level-child-$key")))); ?></li>
                    <?php endforeach; ?>
                </ul>
            </div>
        </div>
    </div>
</div>