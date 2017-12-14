<?php
function itg_app_api_user_login(&$edit, $account) {


    if (in_array("App Manager", $account->roles)) {
        $edit['redirect'] = 'itg-app-dashboard';
    }
}
