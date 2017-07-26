<?php

/*
 * Get The list of open poll in the system
 */

function polls_open_list() {

    $output_array = array();
    $data_array = array();
    $updated_datetime = "";

    // list array building

    $data = polls_open_datalist();


    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    //data array building
    $poll_id = $data['id'];
    $poll_title = $data['title'];

    $data_array['id'] = ""; //$poll_id
    $data_array['title'] = ""; //$poll_title

    $data_array['polls'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

function polls_close_list() {

    $output_array = array();
    $data_array = array();
    $updated_datetime = "";

    // list array building

    $data = polls_close_datalist();


    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    //data array building
    $poll_id = $data['id'];
    $poll_title = $data['title'];

    $data_array['id'] = ""; //$poll_id
    $data_array['title'] = ""; //$poll_title

    $data_array['polls'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

/*
 * cast poll based on args
 *  @args poll id
 *  @return the poll info in array
 */

function poll_cast_list($poll_id, $option_id, $user_id) {

    $dsp_result = itg_poll_get_display_result($poll_id);
    $query = db_insert('itg_polls')
            ->fields(array(
                'nId' => $poll_id,
                'ansId' => $option_id,
                'uid' => 0,
                'display_result' => $dsp_result,
                'created' => date('Y-m-d H:i:s', time())
            ))
            ->execute();


    if ($query) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "Poll Has been updated successfully !";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    $data = poll_cast_datalist($poll_id);

    //data array building
    $poll_id = $data['id'];
    $poll_title = $data['title'];

    $data_array['id'] = ""; //$poll_id
    $data_array['title'] = ""; //$poll_title

    $data_array['polls'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

/*
 * return the responce of the poll after cast the vote
 */

function poll_cast_datalist($poll_id) {

    $current_time = date('Y-m-d H:i:s', time());

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_poll_banner', 'pb', 'pb.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_start_date', 'st', 'st.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_call_to_action_image', 'ai', 'ai.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_end_date', 'ed', 'ed.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'changed'));
    $query->fields('pb', array('field_poll_banner_fid'));
    $query->fields('st', array('field_poll_start_date_value'));
    $query->fields('ai', array('field_poll_call_to_action_image_fid'));
    $query->fields('ed', array('field_poll_end_date_value'));

    $query->condition('n.type', 'poll');
    $query->condition('n.nid', $poll_id);
    $query->range(0, 2);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $k => $res) {

        $poll_sponsored_icon = completeFilePath($res['field_poll_banner_fid']);
        $poll_action_img = completeFilePath($res['field_poll_call_to_action_image_fid']);

        $count_total_patic = itg_poll_getTotalPoll($res['nid']);
        $poll_result_options = poll_result($res['nid']);

        $news['p_id'] = $res['nid'];
        $news['p_is_sponsored'] = '';
        $news['p_sponsored_icon'] = "$poll_sponsored_icon";
        $news['p_sponsored_link'] = '';
        $news['p_publish_datetime'] = $res['field_poll_start_date_value'];
        $news['p_title'] = $res['title'];
        $news['p_image'] = $poll_action_img;
        $news['p_share_link'] = get_node_firebase_weburl($res['nid']);
        $news['total_participants'] = "$count_total_patic";

        $news['p_option'] = $poll_result_options; //set the options of the poll
        $news2[] = $news;
    }

    $data['data'] = $news2;
    $data['id'] = $res['id'];
    $data['title'] = $res['title'];
    return $data;
}

/*
 * cast poll based on args
 *  @args poll id
 *  @return the poll info in array
 */

function poll_detail_data($poll_id) {

    $output_array = array();
    $data_array = array();
    $updated_datetime = "";

    // list array building

    $data = poll_detail_datalist($poll_id);


    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    //data array building
    $poll_id = $data['id'];
    $poll_title = $data['title'];

    $data_array['id'] = ""; //$poll_id
    $data_array['title'] = ""; //$poll_title

    $data_array['polls'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

/*
 * Return the data of open poll
 */

function polls_open_datalist() {

    $current_time = date('Y-m-d H:i:s', time());

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_poll_banner', 'pb', 'pb.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_start_date', 'st', 'st.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_call_to_action_image', 'ai', 'ai.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_end_date', 'ed', 'ed.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'changed'));
    $query->fields('pb', array('field_poll_banner_fid'));
    $query->fields('st', array('field_poll_start_date_value'));
    $query->fields('ai', array('field_poll_call_to_action_image_fid'));
    $query->fields('ed', array('field_poll_end_date_value'));

    $query->condition('n.type', 'poll');
    $query->condition('ed.field_poll_end_date_value', $current_time, '>');
    $query->condition('n.status', '1');
    $query->orderBy('n.nid', 'DESC');
    $query->range(0, 2);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

//print_r(node_load(349643));
//exit();

    foreach ($result as $k => $res) {

        $poll_sponsored_icon = completeFilePath($res['field_poll_banner_fid']);
        $poll_action_img = completeFilePath($res['field_poll_call_to_action_image_fid']);

        $query2 = db_select('field_data_field_poll_answer', 'pa');
        $query2->leftJoin('field_data_field_poll_answer_text', 'ot', 'ot.entity_id = pa.field_poll_answer_value');
        $query2->leftJoin('field_data_field_poll_answer_image', 'ai', 'ai.entity_id = pa.field_poll_answer_value');
        $query2->fields('pa', array('field_poll_answer_value'));
        $query2->fields('ot', array('field_poll_answer_text_value'));
        $query2->fields('ai', array('field_poll_answer_image_fid'));
        $query2->condition('pa.entity_id', $res['nid']);
        $result_option = $query2->execute()->fetchAll(PDO::FETCH_ASSOC);

        // print_r($result_option);
        // exit();

        $options2 = array();
        foreach ($result_option as $p => $pv) {
            //$poll_options = field_collection_item_load($pv['field_poll_answer_value']);
            $options['o_id'] = $pv['field_poll_answer_value'];
            $options['o_title'] = $pv['field_poll_answer_text_value'];
            $options['o_image'] = completeFilePath($pv['field_poll_answer_image_fid']);
            $options2[] = $options;
            //print_r($poll_options);
        }

        $news['p_id'] = $res['nid'];
        $news['p_is_sponsored'] = '';
        $news['p_sponsored_icon'] = "$poll_sponsored_icon";
        $news['p_sponsored_link'] = '';
        $news['p_publish_datetime'] = $res['field_poll_start_date_value'];
        $news['p_title'] = $res['title'];
        $news['p_image'] = $poll_action_img;
        $news['p_share_link'] = get_node_firebase_weburl($res['nid']);
        $news['total_participants'] = '';

        $news['p_option'] = $options2;
        $news2[] = $news;
    }


    $data['data'] = $news2;
    $data['id'] = $res['id'];
    $data['title'] = $res['title'];
    return $data;
}

/*
 * return all the close poll list
 */

function polls_close_datalist() {

    $current_time = date('Y-m-d H:i:s', time());

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_poll_banner', 'pb', 'pb.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_start_date', 'st', 'st.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_call_to_action_image', 'ai', 'ai.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_end_date', 'ed', 'ed.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'changed'));
    $query->fields('pb', array('field_poll_banner_fid'));
    $query->fields('st', array('field_poll_start_date_value'));
    $query->fields('ai', array('field_poll_call_to_action_image_fid'));
    $query->fields('ed', array('field_poll_end_date_value'));

    $query->condition('n.type', 'poll');
    $query->condition('ed.field_poll_end_date_value', $current_time, '<');
    $query->condition('n.status', '1');
    $query->orderBy('n.nid', 'DESC');
    $query->range(0, 2);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

//print_r($result);
//exit();

    foreach ($result as $k => $res) {

        $poll_sponsored_icon = completeFilePath($res['field_poll_banner_fid']);
        $poll_action_img = completeFilePath($res['field_poll_call_to_action_image_fid']);

        $query2 = db_select('field_data_field_poll_answer', 'pa');
        $query2->leftJoin('field_data_field_poll_answer_text', 'ot', 'ot.entity_id = pa.field_poll_answer_value');
        $query2->leftJoin('field_data_field_poll_answer_image', 'ai', 'ai.entity_id = pa.field_poll_answer_value');
        $query2->fields('pa', array('field_poll_answer_value'));
        $query2->fields('ot', array('field_poll_answer_text_value'));
        $query2->fields('ai', array('field_poll_answer_image_fid'));
        $query2->condition('pa.entity_id', $res['nid']);
        $result_option = $query2->execute()->fetchAll(PDO::FETCH_ASSOC);

        // print_r($result_option);
        // exit();

        $options2 = array();
        foreach ($result_option as $p => $pv) {
            //$poll_options = field_collection_item_load($pv['field_poll_answer_value']);
            $options['o_id'] = $pv['field_poll_answer_value'];
            $options['o_title'] = $pv['field_poll_answer_text_value'];
            $options['o_image'] = completeFilePath($pv['field_poll_answer_image_fid']);
            $options2[] = $options;
            //print_r($poll_options);
        }

        $count_total_patic = itg_poll_getTotalPoll($res['nid']);

        $news['p_id'] = $res['nid'];
        $news['p_is_sponsored'] = '';
        $news['p_sponsored_icon'] = "$poll_sponsored_icon";
        $news['p_sponsored_link'] = '';
        $news['p_publish_datetime'] = $res['field_poll_start_date_value'];
        $news['p_title'] = $res['title'];
        $news['p_image'] = $poll_action_img;
        $news['p_share_link'] = get_node_firebase_weburl($res['nid']);
        $news['total_participants'] = "$count_total_patic";

        $news['p_option'] = $options2;
        $news2[] = $news;
    }


    $data['data'] = $news2;
    $data['id'] = $res['id'];
    $data['title'] = $res['title'];
    return $data;
}

function poll_detail_datalist($poll_id) {

    $current_time = date('Y-m-d H:i:s', time());

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_poll_banner', 'pb', 'pb.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_start_date', 'st', 'st.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_call_to_action_image', 'ai', 'ai.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_end_date', 'ed', 'ed.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'changed'));
    $query->fields('pb', array('field_poll_banner_fid'));
    $query->fields('st', array('field_poll_start_date_value'));
    $query->fields('ai', array('field_poll_call_to_action_image_fid'));
    $query->fields('ed', array('field_poll_end_date_value'));

    $query->condition('n.type', 'poll');
//$query->condition('ed.field_poll_end_date_value',$current_time,'<');
//$query->condition('n.status','1');
    $query->condition('n.nid', $poll_id);
//$query->orderBy('n.nid','DESC');
    $query->range(0, 2);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

//print_r($result);
//exit();

    foreach ($result as $k => $res) {

        $poll_sponsored_icon = completeFilePath($res['field_poll_banner_fid']);
        $poll_action_img = completeFilePath($res['field_poll_call_to_action_image_fid']);

        $query2 = db_select('field_data_field_poll_answer', 'pa');
        $query2->leftJoin('field_data_field_poll_answer_text', 'ot', 'ot.entity_id = pa.field_poll_answer_value');
        $query2->leftJoin('field_data_field_poll_answer_image', 'ai', 'ai.entity_id = pa.field_poll_answer_value');
        $query2->fields('pa', array('field_poll_answer_value'));
        $query2->fields('ot', array('field_poll_answer_text_value'));
        $query2->fields('ai', array('field_poll_answer_image_fid'));
        $query2->condition('pa.entity_id', $res['nid']);
        $result_option = $query2->execute()->fetchAll(PDO::FETCH_ASSOC);

        // print_r($result_option);
        // exit();

        $options2 = array();
        foreach ($result_option as $p => $pv) {
            //$poll_options = field_collection_item_load($pv['field_poll_answer_value']);
            $options['o_id'] = $pv['field_poll_answer_value'];
            $options['o_title'] = $pv['field_poll_answer_text_value'];
            $options['o_image'] = completeFilePath($pv['field_poll_answer_image_fid']);
            $options2[] = $options;
            //print_r($poll_options);
        }

        $count_total_patic = itg_poll_getTotalPoll($res['nid']);

        $news['p_id'] = $res['nid'];
        $news['p_is_sponsored'] = '';
        $news['p_sponsored_icon'] = "$poll_sponsored_icon";
        $news['p_sponsored_link'] = '';
        $news['p_publish_datetime'] = $res['field_poll_start_date_value'];
        $news['p_title'] = $res['title'];
        $news['p_image'] = $poll_action_img;
        $news['p_share_link'] = get_node_firebase_weburl($res['nid']);
        $news['total_participants'] = "$count_total_patic";

        $news['p_option'] = $options2;
        $news2[] = $news;
    }


    $data['data'] = $news2;
    $data['id'] = $res['id'];
    $data['title'] = $res['title'];
    return $data;
}
