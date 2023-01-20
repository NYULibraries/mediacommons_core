<?php
/**
 * @file
 * mediacommons_homepage_featured.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mediacommons_homepage_featured_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'recent_6_hubs';
  $view->description = 'For use on homepage, for all channels';
  $view->tag = 'homepage';
  $view->base_table = 'node';
  $view->human_name = 'Homepage featured hubs: for all channels';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Featured Content';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'featured_content_for_homepage' => 'featured_content_for_homepage',
    'featured_umbrella' => 0,
  );
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['label'] = 'Rep Image wrapper';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_representative_image',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'field-name-field-representative-image';
  /* Field: Content: Thumbnail image */
  $handler->display->display_options['fields']['field_representative_image']['id'] = 'field_representative_image';
  $handler->display->display_options['fields']['field_representative_image']['table'] = 'field_data_field_representative_image';
  $handler->display->display_options['fields']['field_representative_image']['field'] = 'field_representative_image';
  $handler->display->display_options['fields']['field_representative_image']['label'] = '';
  $handler->display->display_options['fields']['field_representative_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_representative_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_representative_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_representative_image']['settings'] = array(
    'image_style' => 'manual_crop_480_320',
    'image_link' => 'content',
  );
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['fieldset']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'created',
    1 => 'field_period',
    2 => 'title',
    3 => 'field_curators_editors',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'featuredhub-info';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['empty'] = 'no post date';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium_mc';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long_no_time';
  /* Field: Content: Start and end dates */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['label'] = '';
  $handler->display->display_options['fields']['field_period']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_period']['empty'] = '[created] ';
  $handler->display->display_options['fields']['field_period']['hide_alter_empty'] = FALSE;
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
  $handler->display->display_options['fields']['field_curators_editors']['label'] = '';
  $handler->display->display_options['fields']['field_curators_editors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_curators_editors']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_curators_editors']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_curators_editors']['settings'] = array(
    'user_reference_view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_curators_editors']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_curators_editors']['field_api_classes'] = TRUE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
  /* Sort criterion: Content: Start and end dates (field_period:value2) */
  $handler->display->display_options['sorts']['field_period_value2']['id'] = 'field_period_value2';
  $handler->display->display_options['sorts']['field_period_value2']['table'] = 'field_data_field_period';
  $handler->display->display_options['sorts']['field_period_value2']['field'] = 'field_period_value2';
  $handler->display->display_options['sorts']['field_period_value2']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hub' => 'hub',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = '.featured-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'featured-item-list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['recent_6_hubs'] = $view;

  $view = new view();
  $view->name = 'recent_hubs_fieldguide';
  $view->description = 'For use on homepage, for FieldGuide ';
  $view->tag = 'channels, fieldguide';
  $view->base_table = 'node';
  $view->human_name = 'Homepage Featured hubs: fieldguide ';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Featured Content';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'featured_content_for_homepage' => 'featured_content_for_homepage',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Content: Start and end dates */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['label'] = '';
  $handler->display->display_options['fields']['field_period']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_period']['empty'] = 'No Time Range Available';
  $handler->display->display_options['fields']['field_period']['settings'] = array(
    'format_type' => 'medium_mc',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<time class="timerangeheader">[field_period]</time><h3>[title_1]</h3>';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
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
    'hub' => 'hub',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['recent_hubs_fieldguide'] = $view;

  $view = new view();
  $view->name = 'single_hub_latest';
  $view->description = 'For use on homepage';
  $view->tag = 'homepage';
  $view->base_table = 'node';
  $view->human_name = 'Channels: Single Hub Latest';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'featured_content_for_homepage' => 'featured_content_for_homepage',
  );
  /* Field: Content: Thumbnail image */
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
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
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
  /* Field: Content: Contributors */
  $handler->display->display_options['fields']['field_contributors']['id'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['table'] = 'field_data_field_contributors';
  $handler->display->display_options['fields']['field_contributors']['field'] = 'field_contributors';
  $handler->display->display_options['fields']['field_contributors']['element_type'] = '0';
  $handler->display->display_options['fields']['field_contributors']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_contributors']['element_wrapper_class'] = 'peoplelist';
  $handler->display->display_options['fields']['field_contributors']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_contributors']['delta_offset'] = '0';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
  /* Sort criterion: Content: Start and end dates (field_period:value2) */
  $handler->display->display_options['sorts']['field_period_value2']['id'] = 'field_period_value2';
  $handler->display->display_options['sorts']['field_period_value2']['table'] = 'field_data_field_period';
  $handler->display->display_options['sorts']['field_period_value2']['field'] = 'field_period_value2';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hub' => 'hub',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'hub_home_vertical';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Single Hub Latest';
  $export['single_hub_latest'] = $view;

  return $export;
}
