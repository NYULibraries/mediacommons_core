<?php
/**
 * @file
 * mediacommons_homepage_featured.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function mediacommons_homepage_featured_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-all_users-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_users-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mediacommons' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mediacommons',
        'weight' => 0,
      ),
      'mediacommons_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mediacommons_admin',
        'weight' => 0,
      ),
      'zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-recent_6_hubs-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'recent_6_hubs-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mediacommons' => array(
        'region' => 'homepage_bottom',
        'status' => 1,
        'theme' => 'mediacommons',
        'weight' => -21,
      ),
      'mediacommons_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mediacommons_admin',
        'weight' => 0,
      ),
      'zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-recent_hubs_fieldguide-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'recent_hubs_fieldguide-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mediacommons' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mediacommons',
        'weight' => 0,
      ),
      'mediacommons_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mediacommons_admin',
        'weight' => 0,
      ),
      'zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-single_hub_latest-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'single_hub_latest-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mediacommons' => array(
        'region' => 'homepage_top',
        'status' => 1,
        'theme' => 'mediacommons',
        'weight' => 0,
      ),
      'mediacommons_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mediacommons_admin',
        'weight' => 0,
      ),
      'zen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
