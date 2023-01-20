<?php

$view = new view();
$view->name = 'contributorscontent';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Contributor\'s content';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Contributor\'s content';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['style_plugin'] = 'table';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Field: Content: Publication Status */
$handler->display->display_options['fields']['field_pubstat']['id'] = 'field_pubstat';
$handler->display->display_options['fields']['field_pubstat']['table'] = 'field_data_field_pubstat';
$handler->display->display_options['fields']['field_pubstat']['field'] = 'field_pubstat';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['date_format'] = 'long_no_time';
$handler->display->display_options['fields']['changed']['second_date_format'] = 'long_no_time';
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Contextual filter: Content: Contributors (field_contributors) */
$handler->display->display_options['arguments']['field_contributors_uid']['id'] = 'field_contributors_uid';
$handler->display->display_options['arguments']['field_contributors_uid']['table'] = 'field_data_field_contributors';
$handler->display->display_options['arguments']['field_contributors_uid']['field'] = 'field_contributors_uid';
$handler->display->display_options['arguments']['field_contributors_uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_contributors_uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['field_contributors_uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_contributors_uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_contributors_uid']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'hub' => 'hub',
  'spoke' => 'spoke',
);

/* Display: I can contribute */
$handler = $view->new_display('block', 'I can contribute', 'block_i_can_contribute');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'I can contribute';
$handler->display->display_options['block_description'] = 'I can contribute';

/* Display: I can curate */
$handler = $view->new_display('block', 'I can curate', 'block_i_can_curate');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'I can curate';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Curated by (field_curators_editors) */
$handler->display->display_options['arguments']['field_curators_editors_uid']['id'] = 'field_curators_editors_uid';
$handler->display->display_options['arguments']['field_curators_editors_uid']['table'] = 'field_data_field_curators_editors';
$handler->display->display_options['arguments']['field_curators_editors_uid']['field'] = 'field_curators_editors_uid';
$handler->display->display_options['arguments']['field_curators_editors_uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_curators_editors_uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['field_curators_editors_uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_curators_editors_uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_curators_editors_uid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['block_description'] = 'I can curate';

/* Display: I am co-editor */
$handler = $view->new_display('block', 'I am co-editor', 'block_i_am_co_editor');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'I Am Co-editor';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Co-editor (field_co_editor) */
$handler->display->display_options['arguments']['field_co_editor_uid']['id'] = 'field_co_editor_uid';
$handler->display->display_options['arguments']['field_co_editor_uid']['table'] = 'field_data_field_co_editor';
$handler->display->display_options['arguments']['field_co_editor_uid']['field'] = 'field_co_editor_uid';
$handler->display->display_options['arguments']['field_co_editor_uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_co_editor_uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['field_co_editor_uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_co_editor_uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_co_editor_uid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['block_description'] = 'I Am Co-editor';

/* Display: I authored */
$handler = $view->new_display('block', 'I authored', 'block_i_authored');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'I Authored';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Author uid */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'node';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['block_description'] = 'I Authored';
