<?php
/**
 * @file : personalization_follow_unfollow.inc
 */
?>
<?php
/**
 * Remove own follow activity
 */
function itg_personalization_remove_activity() {
  global $user;
  $nid = $_POST['nd_id'];
  if (function_exists('mongodb')) {
    $con = mongodb();
    // check connection
    if ($con && !empty($nid)) {
        $people = $con->front_user_activity;
        $people->remove(array("nid" => $nid, "uid" => $user->uid));
        $response = array('success' => 'true');
        print json_encode($response);
    } //close connection
  }
}

/**
 * get following user for story
 * @return mixed
 */
function _get_following_user_story() {
  $date = date('2017-07-23'); //todo
  $start_date = strtotime($date);

  $results = db_query("SELECT DISTINCT n.nid, n.title, n.type FROM {node} AS n
WHERE n.type = 'story' AND n.status = 1 AND n.created >= (:created)", array(':created' => $start_date))->fetchAll();
  $html = "<table>";
  foreach ($results as $row) {
    $nid = $row->nid;
    $node = node_load($nid);
    $options['node'][$nid] = $node->title;
    $html .= "<tr><td>" . l($node->title, FRONT_URL . '/node/' . $nid, array('absolute' => TRUE)) . "</td></tr>";
    //$options['node_url'][$nid] = l($node->title, FRONT_URL . '/node/' . $nid, array('absolute' => TRUE));

    if ($tags = field_get_items('node', $node, 'field_story_itg_tags')) {
      foreach ($tags as $v) {
        if(is_array($v) && count($v) > 0) {
          foreach ($v as $tag) {
            $data[] = $tag;
          }
        }
      }
    }
    if ($reporter = field_get_items('node', $node, 'field_reporter_publish_id')) {
      $reporter_array = explode(',', $reporter[0]['value']);
      if(!in_array($reporter_array[0], $data)) {
        $data[] = $reporter_array[0];
      }

    }
  }

  $html .= "</table>";
  $options['node_url'] = $html;
  if (function_exists('mongodb')) {
    $con = mongodb();
    // check connection
    if ($con) {
      $people = $con->front_user_activity;
      $cursor = $people->find(array("nid" => array('$in' => $data)
      ));

      foreach ($cursor as $document) {
        if(!in_array($document['uid'], $options[$document['ntype']])) {
          $options[$document['ntype']][] = $document['uid'];
        }
      }
      return $options;
    } //close connection
  }
}

/**
 * get following user for anchor
 * @return mixed
 */
function _get_following_user_anchor() {
  $date = date('2017-06-23'); // todo
  $start_date = strtotime($date);

  $results = db_query("SELECT DISTINCT n.nid, n.title, n.type FROM {node} AS n
WHERE n.type = 'videogallery' AND n.status = 1 AND n.created >= (:created)", array(':created' => $start_date))->fetchAll();

  $html = "<table>";
  foreach ($results as $row) {
    $nid = $row->nid;
    $node = node_load($nid);

    $options['node'][$nid] = $node->title;
    $html .= "<tr><td>" . l($node->title, FRONT_URL . '/node/' . $nid, array('absolute' => TRUE)) . "</td></tr>";

    if ($anchor = field_get_items('node', $node, 'field_video_anchor')) {
      foreach ($anchor as $target) {
        $data[] = $target['target_id'];
      }
    }

  }

  $html .= "</table>";
  $options['node_url'] = $html;
  if (function_exists('mongodb')) {
    $con = mongodb();
    // check connection
    if ($con) {
      $people = $con->front_user_activity;
      $cursor = $people->find(array("nid" => array('$in' => $data)
      ));

      foreach ($cursor as $document) {
        if(!in_array($document['uid'], $options[$document['ntype']])) {
          $options[$document['ntype']][] = $document['uid'];
        }
      }
      return $options;
    } //close connection
  }
}

/**
 * get followers by anchor.
 * @param int $nid
 * @return mixed
 */
function itg_get_followers($nid) {
  if (function_exists('mongodb')) {
    $con = mongodb();
    // check connection
    if ($con && !empty($nid)) {
      $ntype = 'anchor';
      $people = $con->front_user_activity;
      return $count = $people->find(array("nid" => $nid, "ntype" => $ntype, 'status' => '1'))->count();
    } //close connection

  }
}

/**
 * Html follow / unfollow for story details page.
 * @param int $nid
 * @param string $ntype
 * @param string $activity
 * @param string $t_name
 */
function itg_story_follow_unfollow_print($nid, $ntype, $activity, $t_name) {
  global $user, $base_url;
  $replace_tag_name = str_replace(" ","-","$t_name");
  if($t_name) {
      $tag_label = '<span class="tag-follow"><a target=\"_blank\" href="' . FRONT_URL . '/topic/' . $replace_tag_name . '"> ' . $t_name . '</a></span>';
    } else {
      $tag_label = '';
    }
    
  if ($user->uid > 0) {
    $follow_status = itg_get_front_activity_info($nid, $ntype, $user->uid, $activity, '');
    if (!empty($follow_status['nid']) && $follow_status['status'] == '1') {
      $html = "<li class=\"author\"><a title='Unfollow' href='javascript:' id='follow-anchor".$nid."' data-rel='".$nid."' data-tag=\"$ntype\" data-activity=\"$activity\" data-ftitle='Follow' data-untitle='Unfollow' data-status='0' class='follow-activity'>Unfollow</a>".$tag_label."</li>";
    }
    else
    {
      $html = "<li class=\"author\"><a title='Follow' href='javascript:' id='follow-anchor".$nid."' data-rel='".$nid."' data-tag=\"$ntype\" data-activity=\"$activity\" data-ftitle='Follow' data-untitle='Unfollow' data-status='1' class='follow-activity'>Follow</a>".$tag_label."</li>";
    }
  }
  else
  {
    $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
    // prepare url for sharing
    $uri = base64_encode($actual_link);
    $sso_url = PARENT_SSO . '/saml_login/other/' . $uri;
    $html = "<li class=\"author mhide\"><a title='follow' href='".$sso_url."'>Follow</a>".$tag_label."</li>";
  }
  print $html;
}

/**
 * function for follow / unfollow.
 * @param int $nid
 */
function itg_follow_unfollow_print($nid) {
  global $user;
  $activity = 'follow_anchor';
  $ntype = 'anchor';
  if ($user->uid > 0) {
    $follow_status = itg_get_front_activity_info($nid, $ntype, $user->uid, $activity, '');

    if (!empty($follow_status['nid']) && $follow_status['status'] == '1') {
      $html = "<li class='follow-activity-anchor'><a title='Unfollow' href='javascript:' id='follow-anchor".$nid."' data-rel='".$nid."' data-tag='anchor' data-activity='follow_anchor' data-ftitle='Follow' data-untitle='Unfollow' data-status='0' class='follow-activity'>".t('Unfollow')."</a></li>";
    }
    else
    {
      $html = "<li class='follow-activity-anchor'><a title='Follow' href='javascript:' id='follow-anchor".$nid."' data-rel='".$nid."' data-tag='anchor' data-activity='follow_anchor' data-ftitle='Follow' data-untitle='Unfollow' data-status='1' class='follow-activity'>".t('Follow')."</a></li>";
    }
  }
  else
  {
    $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
    // prepare url for sharing
    $uri = base64_encode($actual_link);
    $sso_url = PARENT_SSO . '/saml_login/other/' . $uri;
    $html = "<li class='follow-activity-anchor'><a title='Follow' href='".$sso_url."'>".t('Follow')."</a></li>";
  }
  print $html;
}
