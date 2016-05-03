<?php
/**
 * Callback function for social media content edit page.
 * @param string $node_type
 * @param int $nid
 */
function social_media_edit_content($node_type, $nid) {
  dpm($node_type);
  dpm($nid);
  return 'hi';
}