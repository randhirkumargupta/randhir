<?php

/**
 * Inc file contains the functions for user list report API
 */

/**
 * main function for generate user list array
 * @pram string $user_type
 * @pram string $user_sub_type
 * @pram int $item_per_page
 * @pram int $pageno
 *
 * @return array userList
 */
function getUserList_Report($user_type, $user_sub_type) {
    global $base_url;
    $list = array();
    $data = array();
    $total_cont = 0;
    if ($user_type == "user") {
        $query = db_select('node', 'n');
        $query->leftJoin('users', 'u', 'u.uid=n.uid');
        $query->leftJoin('users_roles', 'ur', 'ur.uid=u.uid');
        $query->fields('u', array('uid', 'name', 'mail', 'status'));
        //filter of content type 
        $query->condition('ur.rid', 25, '<>');
        $query->orderBy('u.name', 'DESC');
        $query->groupBy('n.uid');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        foreach ($result as $reskey => $resvalue) {
            $uid = $resvalue['uid'];
            $name = $resvalue['name'];
            $mail = $resvalue['mail'];
            $status = $resvalue['status'];
            // list data
            $list[$total_cont]['user_id'] = "$uid";
            $list[$total_cont]['name'] = "$name";
            $list[$total_cont]['email'] = "$mail";
            $list[$total_cont]['status'] = "$status";

            $total_cont++;
        }
    } elseif ($user_type == "author") {
        $query_n = db_select('node', 'n');
        $query_n->leftJoin('field_data_field_reporter_email_id', 're', 'n.nid = re.entity_id');
        $query_n->fields('n', array('nid', 'title', 'status'));
        $query_n->fields('re', array('field_reporter_email_id_value'));
        $query_n->condition('n.type', 'reporter', '=');
        $result_n = $query_n->execute()->fetchAll(PDO::FETCH_ASSOC);
        foreach ($result_n as $reskey_n => $resvalue_n) {
            $nid = $resvalue_n['nid'];
            $title = $resvalue_n['title'];
            $status = $resvalue_n['status'];
            $field_reporter_email_id_value = $resvalue_n['field_reporter_email_id_value'];
            // list data
            $list[$total_cont]['user_id'] = "$nid";
            $list[$total_cont]['name'] = "$title";
            $list[$total_cont]['email'] = "$field_reporter_email_id_value";
            $list[$total_cont]['status'] = "$status";

            $total_cont++;
        }
    }

    $data['results'] = $list;
    $data['total_records'] = "$total_cont";
    return $data;
}

/**
 * main function for get total user records
 * @pram string $user_type
 * @pram string $user_sub_type
 * @pram int $item_per_page
 * @pram int $pageno
 *
 * @return int  $total_records
 */
function totalUser_Report($user_type, $user_sub_type, $item_per_page, $pageno) {
  $query = db_select('users', 'u');
  $query->leftJoin('users_roles', 'ur', 'ur.uid=u.uid');
  $query->fields('u', array('uid'));

  $query->condition('ur.rid', 1, '<>')->condition('ur.rid', 25, '<>');
  $result = $query->execute()->fetchAll();
  $total_records = count($result);
  return $total_records;
}

