<?php
/**
 * @file
 * mediacommons_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mediacommons_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "corresponding_node_references" && $api == "default_corresponding_node_references_presets") {
    return array("version" => "1");
  }
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
function mediacommons_content_types_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function mediacommons_content_types_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['F j, Y'] = 'F j, Y';
  $custom_date_formats['l, F j, Y'] = 'l, F j, Y';
  $custom_date_formats['n/j/Y'] = 'n/j/Y';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function mediacommons_content_types_date_format_types() {
  $format_types = array();
  // Exported date format type: long_no_time
  $format_types['long_no_time'] = 'Long no time';
  // Exported date format type: medium_mc
  $format_types['medium_mc'] = 'Medium MC';
  // Exported date format type: short_no_time
  $format_types['short_no_time'] = 'Short no time';
  return $format_types;
}

/**
 * Implements hook_image_default_styles().
 */
function mediacommons_content_types_image_default_styles() {
  $styles = array();

  // Exported image style: 16_9_ratio.
  $styles['16_9_ratio'] = array(
    'label' => '16:9 ratio',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 270,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 21_9_ratio.
  $styles['21_9_ratio'] = array(
    'label' => '21:9 ratio',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 504,
          'height' => 216,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 450_by_175.
  $styles['450_by_175'] = array(
    'label' => '450 by 175',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 450,
          'height' => 175,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: homepage_featured_item__480x320_.
  $styles['homepage_featured_item__480x320_'] = array(
    'label' => 'Homepage Featured Item (480x320)',
    'effects' => array(
      8 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
      9 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 480,
          'height' => 320,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: manual_crop_480_320.
  $styles['manual_crop_480_320'] = array(
    'label' => 'Manual Crop 480 320',
    'effects' => array(
      3 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 240,
          'height' => 160,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'manual_crop_480_320',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: manual_crop_thumbnail_120_by_80.
  $styles['manual_crop_thumbnail_120_by_80'] = array(
    'label' => 'Manual Crop Thumbnail 120 by 80',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 120,
          'height' => 80,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'manual_crop_thumbnail_120_by_80',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: max_width_600px.
  $styles['max_width_600px'] = array(
    'label' => 'Max width 600px',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: mc_unchanged.
  $styles['mc_unchanged'] = array(
    'label' => 'MC_unchanged',
    'effects' => array(),
  );

  // Exported image style: profile_page_pic.
  $styles['profile_page_pic'] = array(
    'label' => 'Profile Page Pic',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 90,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_pic_small.
  $styles['profile_pic_small'] = array(
    'label' => 'Profile Pic Small',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: thumbnail__120x80_.
  $styles['thumbnail__120x80_'] = array(
    'label' => 'Thumbnail (120x80)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 120,
          'height' => 80,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function mediacommons_content_types_node_info() {
  $items = array(
    'hub' => array(
      'name' => t('Hub'),
      'base' => 'node_content',
      'description' => t('A collection of spokes. Also called a Theme Week (IMR), Issue (inTransition), Cluster (#Alt-Ac, TNE), or Survey Question (Field Guide).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'message' => array(
      'name' => t('Message'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'review' => array(
      'name' => t('Review'),
      'base' => 'node_content',
      'description' => t('Invited commentary (as opposed to Comments). Currently used by inTransition.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'spoke' => array(
      'name' => t('Spoke'),
      'base' => 'node_content',
      'description' => t('The basic building block of a MediaCommons channel. Also called a Post (IMR), Video (inTransition), or Article (TNE), Essay (#Alt-Ac).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
