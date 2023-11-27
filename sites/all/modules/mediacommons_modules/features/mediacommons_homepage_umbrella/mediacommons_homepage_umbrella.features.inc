<?php
/**
 * @file
 * mediacommons_homepage_umbrella.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mediacommons_homepage_umbrella_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mediacommons_homepage_umbrella_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function mediacommons_homepage_umbrella_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: featured_umbrella
  $nodequeues['featured_umbrella'] = array(
    'name' => 'featured_umbrella',
    'title' => 'Featured Content for Homepage: Umbrella',
    'subqueue_title' => '',
    'size' => 12,
    'link' => 'Add to homepage queue',
    'link_remove' => 'Remove from homepage queue ',
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
      0 => 'front_page_post',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function mediacommons_homepage_umbrella_image_default_styles() {
  $styles = array();

  // Exported image style: manual_crop_16_9.
  $styles['manual_crop_16_9'] = array(
    'label' => 'Manual Crop 16:9',
    'effects' => array(
      2 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 800,
          'height' => 450,
          'upscale' => 1,
          'respectminimum' => 0,
          'onlyscaleifcrop' => 0,
          'style_name' => 'manual_crop_16_9',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: manual_crop_user-defined.
  $styles['manual_crop_user-defined'] = array(
    'label' => 'Manual Crop User-defined',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 150,
          'height' => 150,
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'manual_crop_user-defined',
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function mediacommons_homepage_umbrella_node_info() {
  $items = array(
    'front_page_post' => array(
      'name' => t('Front Page Post'),
      'base' => 'node_content',
      'description' => t('Create a front page post. To add it to the front page carousel or in the list below.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
