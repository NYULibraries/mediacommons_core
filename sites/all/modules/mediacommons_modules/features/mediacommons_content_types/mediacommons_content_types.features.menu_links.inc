<?php
/**
 * @file
 * mediacommons_content_types.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function mediacommons_content_types_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_archives:archives.
  $menu_links['main-menu_archives:archives'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'archives',
    'router_path' => 'archives',
    'link_title' => 'Archives',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_archives:archives',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Archives');

  return $menu_links;
}
