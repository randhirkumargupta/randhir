<?php

/*
 * Get The list of open poll in the system
 */

function polls_open_list($cpageno) {

    $output_array = array();
    $data_array = array();
    $updated_datetime = "";

    // list array building

    $data = polls_open_datalist($cpageno);


    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    //data array building

    $data_array['id'] = "1234"; //$poll_id
    $data_array['title'] = "Test title"; //$poll_title

    $data_array['polls'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

function polls_close_list($cpageno) {

    $output_array = array();
    $data_array = array();
    $updated_datetime = "";

    // list array building

    $data = polls_close_datalist($cpageno);


    if ($data['lcount'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    //data array building

    $data_array['id'] = "1234";
    $data_array['title'] = "Test Title";

    $data_array['polls'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

/*
 * cast poll based on args
 *  @args poll id
 *  @return the poll info in array
 */

function poll_cast_list($poll_id, $option_id, $user_id, $ip_address, $device) {

    $dsp_result = itg_poll_get_display_result($poll_id);
    $dsp_result = $dsp_result > 0 ? $dsp_result : 1;
    if (isset($dsp_result)) {
        $query = db_insert('itg_polls')
                ->fields(array(
                    'nId' => $poll_id,
                    'ansId' => $option_id,
                    'uid' => $user_id,
                    'display_result' => $dsp_result,
                    'ip' => $ip_address,
                    'device' => $device,
                    'created' => date('Y-m-d H:i:s', time())
                ))
                ->execute();
    }

    if ($query) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "customised_message ";
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
    $query->leftJoin('field_data_field_poll_question_image', 'qi', 'qi.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'changed'));
    $query->fields('pb', array('field_poll_banner_fid'));
    $query->fields('st', array('field_poll_start_date_value'));
    $query->fields('ai', array('field_poll_call_to_action_image_fid'));
    $query->fields('ed', array('field_poll_end_date_value'));
    $query->fields('qi', array('field_poll_question_image_fid'));

    $query->condition('n.type', 'poll');
    $query->condition('n.nid', $poll_id);
    $query->range(0, 2);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $k => $res) {

        $poll_sponsored_icon = completeFilePath($res['field_poll_banner_fid']);
        $poll_action_img = completeFilePath($res['field_poll_call_to_action_image_fid']);
        $poll_ques_img = completeFilePath($res['field_poll_question_image_fid']);

        $count_total_patic = itg_poll_getTotalPoll($res['nid']);
        $poll_result_options = poll_result($res['nid']);
        $poll_nid = $res['nid'];
        $poll_start_date_value = $res['field_poll_start_date_value'];
        $poll_node_title = $res['title'];

        $news['p_id'] = "$poll_nid";
        $news['p_is_sponsored'] = "";
        $news['p_sponsored_icon'] = "";
        $news['p_sponsored_link'] = "";
        $news['p_publish_datetime'] = "$poll_start_date_value";
        $news['p_title'] = "$poll_node_title";
        $news['p_image'] = $poll_ques_img;
        $news['p_share_link'] = get_node_firebase_weburl($res['nid']);
        $news['total_participants'] = "$count_total_patic";

        $news['p_option'] = isset($poll_result_options) ? $poll_result_options : ""; //set the options of the poll
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

    $data_array['id'] = "1234"; //$poll_id
    $data_array['title'] = "Test Title"; //$poll_title

    $data_array['polls'] = $data['data'];
    $output_array['data'] = $data_array;

    return $output_array;
}

/*
 * Return the data of open poll
 */

function polls_open_datalist($cpageno) {
    $range_max = 10;
    if (!$cpageno == 0) {
        $range_min = $cpageno * $range_max;
    } else {
        $range_min = 0;
    }
    $current_time = date('Y-m-d H:i:s', time());

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_poll_banner', 'pb', 'pb.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_start_date', 'st', 'st.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_call_to_action_image', 'ai', 'ai.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_end_date', 'ed', 'ed.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_question_image', 'qi', 'qi.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'changed'));
    $query->fields('pb', array('field_poll_banner_fid'));
    $query->fields('st', array('field_poll_start_date_value'));
    $query->fields('ai', array('field_poll_call_to_action_image_fid'));
    $query->fields('ed', array('field_poll_end_date_value'));
    $query->fields('qi', array('field_poll_question_image_fid'));

    $query->condition('n.type', 'poll');
    $query->condition('st.field_poll_start_date_value', $current_time, '<');
    $query->condition('n.status', '1');
    $query->orderBy('n.nid', 'DESC');
    $query->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $k => $res) {
        if ($res['field_poll_end_date_value'] != '' && $res['field_poll_end_date_value'] > $current_time) {
            $news2[] = open_poll_list($res);
        } else if ($res['field_poll_end_date_value'] == '') {//&& $res['field_poll_start_date_value'] >= $current_time
            $news2[] = open_poll_list($res);
        }
    }

    $data['data'] = $news2;
    $data['lcount'] = count($news2);
    $data['id'] = $res['id'];
    $data['title'] = $res['title'];
    return $data;
}

/*
 * args array 
 * return the associative array based on expected json
 */

function open_poll_list($res) {

    $poll_sponsored_icon = completeFilePath($res['field_poll_banner_fid']);
    $poll_action_img = completeFilePath($res['field_poll_call_to_action_image_fid']);
    $poll_ques_img = completeFilePath($res['field_poll_question_image_fid']);
    $poll_nid = $res['nid'];
    $poll_publish_date_time = $res['field_poll_start_date_value'];
    $poll_title = $res['title'];

    $query2 = db_select('field_data_field_poll_answer', 'pa');
    $query2->leftJoin('field_data_field_poll_answer_text', 'ot', 'ot.entity_id = pa.field_poll_answer_value');
    $query2->leftJoin('field_data_field_poll_answer_image', 'ai', 'ai.entity_id = pa.field_poll_answer_value');
    $query2->fields('pa', array('field_poll_answer_value'));
    $query2->fields('ot', array('field_poll_answer_text_value'));
    $query2->fields('ai', array('field_poll_answer_image_fid'));
    $query2->condition('pa.entity_id', $res['nid']);
    $result_option = $query2->execute()->fetchAll(PDO::FETCH_ASSOC);

    $options2 = array();

    foreach ($result_option as $p => $pv) {
        $options['o_id'] = isset($pv['field_poll_answer_value']) ? $pv['field_poll_answer_value'] : "";
        $options['o_title'] = isset($pv['field_poll_answer_text_value']) ? $pv['field_poll_answer_text_value'] : "";
        $options['o_image'] = completeFilePath($pv['field_poll_answer_image_fid']);
        $options2[] = $options;
    }

    $news['p_id'] = "$poll_nid";
    $news['p_is_sponsored'] = "";
    $news['p_sponsored_icon'] = "";
    $news['p_sponsored_link'] = "";
    $news['p_publish_datetime'] = "$poll_publish_date_time";
    $news['p_title'] = "$poll_title";
    $news['p_image'] = "$poll_ques_img";
    $news['p_share_link'] = get_node_firebase_weburl($res['nid']);
    $news['total_participants'] = "";

    $news['p_option'] = $options2;
    return $news;
}

/*
 * return all the close poll list
 */

function polls_close_datalist($cpageno) {
    $news2 = array();
    $range_max = 10;
    if (!$cpageno == 0) {
        $range_min = $cpageno * $range_max;
    } else {
        $range_min = 0;
    }

    $current_time = date('Y-m-d H:i:s', time());

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_poll_banner', 'pb', 'pb.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_start_date', 'st', 'st.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_call_to_action_image', 'ai', 'ai.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_end_date', 'ed', 'ed.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_question_image', 'qi', 'qi.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'changed'));
    $query->fields('pb', array('field_poll_banner_fid'));
    $query->fields('st', array('field_poll_start_date_value'));
    $query->fields('ai', array('field_poll_call_to_action_image_fid'));
    $query->fields('ed', array('field_poll_end_date_value'));
    $query->fields('qi', array('field_poll_question_image_fid'));

    $query->condition('n.type', 'poll');
    $query->condition('ed.field_poll_end_date_value', $current_time, '<');
    //$query->condition('st.field_poll_start_date_value', $current_time, '<');
    $query->condition('n.status', '1');
    $query->orderBy('n.nid', 'DESC');
    $query->range($range_min, $range_max);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $k => $res) {
        if ($res['field_poll_end_date_value'] != '' && $res['field_poll_end_date_value'] < $current_time) {
            $news2[] = poll_close_datalist($res);
        } elseif ($res['field_poll_end_date_value'] == '' && $res['field_poll_start_date_value'] < $current_time) {

            $news2[] = poll_close_datalist($res);
        }
    }


    $data['data'] = $news2;
    $data['lcount'] = count($news2);
    $data['id'] = $res['id'];
    $data['title'] = $res['title'];
    return $data;
}

/*
 * return the poll list 
 * @param
 * $res , associative array
 * @return , Associative array of all the values with keys
 */

function poll_close_datalist($res) {

    $poll_sponsored_icon = completeFilePath($res['field_poll_banner_fid']);
    $poll_action_img = completeFilePath($res['field_poll_call_to_action_image_fid']);
    $poll_ques_img = completeFilePath($res['field_poll_question_image_fid']);

    $query2 = db_select('field_data_field_poll_answer', 'pa');
    $query2->leftJoin('field_data_field_poll_answer_text', 'ot', 'ot.entity_id = pa.field_poll_answer_value');
    $query2->leftJoin('field_data_field_poll_answer_image', 'ai', 'ai.entity_id = pa.field_poll_answer_value');
    $query2->fields('pa', array('field_poll_answer_value'));
    $query2->fields('ot', array('field_poll_answer_text_value'));
    $query2->fields('ai', array('field_poll_answer_image_fid'));
    $query2->condition('pa.entity_id', $res['nid']);
    $result_option = $query2->execute()->fetchAll(PDO::FETCH_ASSOC);

    $options2 = array();
    $options = array();
    foreach ($result_option as $p => $pv) {
        $options['o_id'] = isset($pv['field_poll_answer_value']) ? $pv['field_poll_answer_value'] : "";
        $options['o_title'] = isset($pv['field_poll_answer_text_value']) ? $pv['field_poll_answer_text_value'] : '';
        $options['o_image'] = completeFilePath($pv['field_poll_answer_image_fid']);
        $options2[] = $options;
    }

    $count_total_patic = itg_poll_getTotalPoll($res['nid']);
    $poll_nid = $res['nid'];
    $poll_start_date_value = $res['field_poll_start_date_value'];
    $poll_title = $res['title'];

    $news['p_id'] = "$poll_nid";
    $news['p_is_sponsored'] = "";
    $news['p_sponsored_icon'] = "";
    $news['p_sponsored_link'] = "";
    $news['p_publish_datetime'] = "$poll_start_date_value";
    $news['p_title'] = "$poll_title";
    $news['p_image'] = "$poll_ques_img";
    $news['p_share_link'] = get_node_firebase_weburl($res['nid']);
    $news['total_participants'] = "$count_total_patic";

    $news['p_option'] = $options2;
    return $news;
}

function poll_detail_datalist($poll_id) {

    $current_time = date('Y-m-d H:i:s', time());
    $news = array();
    $news2 = array();

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_poll_banner', 'pb', 'pb.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_start_date', 'st', 'st.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_call_to_action_image', 'ai', 'ai.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_end_date', 'ed', 'ed.entity_id = n.nid');
    $query->leftJoin('field_data_field_poll_question_image', 'qi', 'qi.entity_id = n.nid');

    $query->fields('n', array('nid', 'title', 'type', 'changed'));
    $query->fields('pb', array('field_poll_banner_fid'));
    $query->fields('st', array('field_poll_start_date_value'));
    $query->fields('ai', array('field_poll_call_to_action_image_fid'));
    $query->fields('ed', array('field_poll_end_date_value'));
    $query->fields('qi', array('field_poll_question_image_fid'));

    $query->condition('n.type', 'poll');
    //$query->condition('n.status','1');
    $query->condition('n.nid', $poll_id);
    $query->range(0, 2);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);


    foreach ($result as $k => $res) {

        $poll_sponsored_icon = completeFilePath($res['field_poll_banner_fid']);
        $poll_action_img = completeFilePath($res['field_poll_call_to_action_image_fid']);
        $poll_ques_img = completeFilePath($res['field_poll_question_image_fid']);

        $query2 = db_select('field_data_field_poll_answer', 'pa');
        $query2->leftJoin('field_data_field_poll_answer_text', 'ot', 'ot.entity_id = pa.field_poll_answer_value');
        $query2->leftJoin('field_data_field_poll_answer_image', 'ai', 'ai.entity_id = pa.field_poll_answer_value');
        $query2->fields('pa', array('field_poll_answer_value'));
        $query2->fields('ot', array('field_poll_answer_text_value'));
        $query2->fields('ai', array('field_poll_answer_image_fid'));
        $query2->condition('pa.entity_id', $res['nid']);
        $result_option = $query2->execute()->fetchAll(PDO::FETCH_ASSOC);


        $options2 = array();
        $options = array();
        foreach ($result_option as $p => $pv) {
            $options['o_id'] = isset($pv['field_poll_answer_value']) ? $pv['field_poll_answer_value'] : "";
            $options['o_title'] = isset($pv['field_poll_answer_text_value']) ? $pv['field_poll_answer_text_value'] : "";
            $options['o_image'] = completeFilePath($pv['field_poll_answer_image_fid']);
            $options2[] = $options;
        }

        $count_total_partic = itg_poll_getTotalPoll($res['nid']);
        $poll_id = isset($res['nid']) ? $res['nid'] : "";
        $poll_publish_date_time = isset($res['field_poll_start_date_value']) ? $res['field_poll_start_date_value'] : "";
        $poll_title = $res['title'];

        $news['p_id'] = "$poll_id";
        $news['p_is_sponsored'] = "";
        $news['p_sponsored_icon'] = "";
        $news['p_sponsored_link'] = "";
        $news['p_publish_datetime'] = "$poll_publish_date_time";
        $news['p_title'] = "$poll_title";
        $news['p_image'] = "$poll_ques_img";
        $news['p_share_link'] = get_node_firebase_weburl($res['nid']);
        $news['total_participants'] = "$count_total_partic";

        $news['p_option'] = $options2;
        $news2[] = $news;
    }


    $data['data'] = $news2;
    $data['id'] = $res['id'];
    $data['title'] = $res['title'];
    return $data;
}

/*
 * get result of poll based on poll id
 * @ args poll id
 */

function poll_result($nid) {

    $node = node_load($nid);
    $outputnew = '';
    $optionarr = itg_poll_getPollResult($nid);
    $opttotal = itg_poll_getTotalPoll($nid);

    foreach ($node->field_poll_answer[LANGUAGE_NONE] as $row) {
        $item_id[] = $row['value'];
    }

    $result_format = $node->field_result_format[LANGUAGE_NONE][0]['value'];
    $temp_entities = entity_load('field_collection_item', $item_id);

    if (is_array($optionarr) && count($optionarr) > 0) {

        $finaltotal = $opttotal;
        $outputnew = '';
        $poll_manipulate_allval = '';
        foreach ($temp_entities as $temp_ent_id => $temp_ents) {
            $poll_manipulate_allval += isset($temp_ents->field_poll_manipulate_value[LANGUAGE_NONE]) ? $temp_ents->field_poll_manipulate_value[LANGUAGE_NONE][0]['value'] : '';
        }
        $finaltotal += $poll_manipulate_allval;

        $poll_options = array();


        foreach ($temp_entities as $temp_ent_id => $temp_ents) {
            $poll_options['o_id'] = $temp_ents->item_id;
            $polls_answer_text = isset($temp_ents->field_poll_answer_text[LANGUAGE_NONE]) ? $temp_ents->field_poll_answer_text[LANGUAGE_NONE][0]['value'] : '';
            $polls_answer_image_fid = isset($temp_ents->field_poll_answer_image['und'][0]['fid']) ? $temp_ents->field_poll_answer_image['und'][0]['fid'] : '';

            // Poll Manipulate value
            $poll_manipulate_val = isset($temp_ents->field_poll_manipulate_value[LANGUAGE_NONE]) ? $temp_ents->field_poll_manipulate_value[LANGUAGE_NONE][0]['value'] : '';

            $preoptioncnt = isset($optionarr[$temp_ent_id]->optionCnt) ? $optionarr[$temp_ent_id]->optionCnt : 0;
            $optioncnt = $preoptioncnt + $poll_manipulate_val;
            $percentage = number_format(($optioncnt / $finaltotal) * 100);
            $polls_answer_text_render = '';
            if ($polls_answer_text) {
                $polls_answer_text_render = $polls_answer_text;
            }

            if ($result_format == 1) { // Percent
                $poll_options['o_title'] = $polls_answer_text_render;
                $poll_options['o_res'] = $percentage . '%';
            } elseif ($result_format == 2) { // Number of votes
                $poll_options['o_title'] = $polls_answer_text_render;
                $poll_options['o_res'] = $optioncnt;
            }
            $poll_options['o_image'] = completeFilePath($polls_answer_image_fid);
            $poll_options2[] = $poll_options;
        }
    }
    return $poll_options2;
}
