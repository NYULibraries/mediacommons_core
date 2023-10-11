<?php
/**
 * @file
 * mediacommons_homepage_umbrella.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mediacommons_homepage_umbrella_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mc_home_lede';
  $view->description = 'Displays the item that will be prominent at the top left of the home page.  Chooses #1 in nodequeue.';
  $view->tag = 'MC umbrella home';
  $view->base_table = 'node';
  $view->human_name = 'Umbrella: MC Homepage top featured';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'featured_umbrella' => 'featured_umbrella',
    'featured_content_for_homepage' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Nodequeue: In queue */
  $handler->display->display_options['sorts']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['sorts']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['sorts']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['in_queue']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'front_page_post' => 'front_page_post',
  );

  /* Display: Block: Umbrella Top Featured */
  $handler = $view->new_display('block', 'Block: Umbrella Top Featured', 'block');
  $handler->display->display_options['display_description'] = 'Umbrella homepage: large image at top left';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position in nodequeue and other parameter */
  $handler->display->display_options['sorts']['position_and_other']['id'] = 'position_and_other';
  $handler->display->display_options['sorts']['position_and_other']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position_and_other']['field'] = 'position_and_other';
  $handler->display->display_options['sorts']['position_and_other']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position_and_other']['order'] = 'DESC';
  $handler->display->display_options['block_caching'] = '-1';
  $export['mc_home_lede'] = $view;

  $view = new view();
  $view->name = 'recent_6_front_page_posts';
  $view->description = 'Umbrella site: from nodequeue';
  $view->tag = 'MC umbrella home';
  $view->base_table = 'node';
  $view->human_name = 'Umbrella: Featured front page posts';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'featured_umbrella' => 'featured_umbrella',
    'featured_content_for_homepage' => 0,
  );
  /* Field: Content: Representative Image */
  $handler->display->display_options['fields']['field_representative_image']['id'] = 'field_representative_image';
  $handler->display->display_options['fields']['field_representative_image']['table'] = 'field_data_field_representative_image';
  $handler->display->display_options['fields']['field_representative_image']['field'] = 'field_representative_image';
  $handler->display->display_options['fields']['field_representative_image']['label'] = '';
  $handler->display->display_options['fields']['field_representative_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_representative_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_representative_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_representative_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Start and end dates */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['label'] = '';
  $handler->display->display_options['fields']['field_period']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_period']['empty'] = 'No time range data available';
  $handler->display->display_options['fields']['field_period']['settings'] = array(
    'format_type' => 'short_no_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Curated by */
  $handler->display->display_options['fields']['field_curators_editors']['id'] = 'field_curators_editors';
  $handler->display->display_options['fields']['field_curators_editors']['table'] = 'field_data_field_curators_editors';
  $handler->display->display_options['fields']['field_curators_editors']['field'] = 'field_curators_editors';
  $handler->display->display_options['fields']['field_curators_editors']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_curators_editors']['element_wrapper_class'] = 'peoplelist';
  $handler->display->display_options['fields']['field_curators_editors']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_curators_editors']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_curators_editors']['delta_offset'] = '0';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'front_page_post' => 'front_page_post',
  );

  /* Display: Umbrella 12 Front Page Posts */
  $handler = $view->new_display('block', 'Umbrella 12 Front Page Posts', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = '.featured-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'featured-item-list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['recent_6_front_page_posts'] = $view;

  return $export;
}
