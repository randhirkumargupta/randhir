<?php
/**
 * @file itg_quiz_result.inc
 */

function itg_quiz_result() {
  $node = node_load(arg(1));
  if ($node->type == 'quiz') {
    print_r($node); exit;
  } else {
    drupal_access_denied();
  }
}