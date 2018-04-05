<?php

/*
 * Inc file scorecard functions
 *
 *
 */

/**
 * Page callback for scorecard.
 * @param string $matchid
 * @return string
 * Implements itg_common_get_scorecard().
 */
function itg_common_get_scorecard($matchid) {
  module_load_include('inc', 'itg_widget', 'includes/itg_widget_live_score');
  $data = live_score();
  $teamsabbr = $data['team1'] . " vs " . $data['team2'];
  $year = substr($data['date'], 4, 4);
  $title = $teamsabbr . " : Live Score, Cricket Commentary, Match Stats- India Today";
  $description = $teamsabbr . ": Get " . $teamsabbr ." Live Score, Full Scorecard, Ball by Ball cricket commentary and match stats. Visit IndiaToday.com";
  $keywords = $teamsabbr . ", " . $teamsabbr . " " . $year . ", " . $teamsabbr . " live score, " . $teamsabbr . $year." full scorecard, " . $teamsabbr . " match commentary, " .$teamsabbr . " " . $year . " match result, ball by ball commentary, india today";
  drupal_set_title($title);
  $html_head = array(
    'description' => array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'description',
        'content' => $description,
      ),
    ),
    'keywords' => array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'keywords',
        'content' => $keywords,
      ),
    ),
  );
  foreach ($html_head as $key => $data) {
    drupal_add_html_head($data, $key);
  }
  $iframe_url = '';
  $iframe_url .= '<iframe  id="si-scorecard"   class="mhide"  width="100%"   height="740" src="https://assets-indiatoday.sportz.io/cricket/matchcentre.html?matchid=' . $matchid . '" frameborder="0"></iframe>';
  $iframe_url .= '<iframe style=" margin-top: 20px;" class="desktop-hide"  width="100%" height="740" src="https://assets-indiatoday.sportz.io/cricket/matchcentre-mobile.html?matchid=' . $matchid . '" frameborder="0"></iframe>';
  $iframe_url .= '<div id="taboola-below-scorecard"></div>';
  $iframe_url .= '<script type="text/javascript">window._taboola = window._taboola || [];_taboola.push({ mode: \'thumbs-3r\', container: \'taboola-below-scorecard\', placement: \'Below Scorecard\', target_type: \'mix\' });</script>';
  return $iframe_url;
}

/**
 * Implements itg_scorecard_live().
 * @param string $matchid
 * @return string
 */
function itg_scorecard_live() {
  $matchid = $_GET['matchid'];
  if (!$matchid) {
    return 'No Live match found.';
  }
  module_load_include('inc', 'itg_widget', 'includes/itg_widget_live_score');
  $data = live_score();
  $teamsabbr = $data['team1'] . " vs " . $data['team2'];
  $year = substr($data['date'], 4, 4);
  $title = $teamsabbr . " : Live Score, Cricket Commentary, Match Stats- India Today";
  $description = $teamsabbr . ": Get " . $teamsabbr ." Live Score, Full Scorecard, Ball by Ball cricket commentary and match stats. Visit IndiaToday.com";
  $keywords = $teamsabbr . ", " . $teamsabbr . " " . $year . ", " . $teamsabbr . " live score, " . $teamsabbr . $year." full scorecard, " . $teamsabbr . " match commentary, " .$teamsabbr . " " . $year . " match result, ball by ball commentary, india today";
  drupal_set_title($title);
  $html_head = array(
    'description' => array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'description',
        'content' => $description,
      ),
    ),
    'keywords' => array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'keywords',
        'content' => $keywords,
      ),
    ),
  );
  foreach ($html_head as $key => $data) {
    drupal_add_html_head($data, $key);
  }
  $iframe_url = '';
  $iframe_url .= '<iframe  id="si-scorecard"   class="mhide"  width="100%"   height="740" src="https://assets-indiatoday.sportz.io/cricket/matchcentre.html?matchid=' . $matchid . '" frameborder="0"></iframe>';
  $iframe_url .= '<iframe style=" margin-top: 20px;" class="desktop-hide"  width="100%" height="740" src="https://assets-indiatoday.sportz.io/cricket/matchcentre-mobile.html?matchid=' . $matchid . '" frameborder="0"></iframe>';
  return $iframe_url;
}
