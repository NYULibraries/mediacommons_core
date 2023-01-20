<?php
/**
 * @file
 * mediacommons_homepage_featured.features.inc
 */

/**
 * Implements hook_views_api().
 */
function mediacommons_homepage_featured_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function mediacommons_homepage_featured_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: featured_content_for_homepage
  $nodequeues['featured_content_for_homepage'] = array(
    'name' => 'featured_content_for_homepage',
    'title' => 'Featured Content for Homepage: Channels',
    'subqueue_title' => '',
    'size' => 6,
    'link' => 'Add to Featured Content for Homepage',
    'link_remove' => 'Remove from Homepage',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 1,
    'insert_at_front' => 1,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'hub',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
