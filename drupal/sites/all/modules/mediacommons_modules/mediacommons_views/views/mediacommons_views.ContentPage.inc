<?php

// $view = new view();
// $view->name = 'ContentPage';
// $view->description = 'Total Control over content: Contains an administration page for all content.';
// $view->tag = 'content_page';
// $view->base_table = 'node';
// $view->human_name = '';
// $view->core = 0;
// $view->api_version = '3.0';
// $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

// /* Display: Defaults */
// $handler = $view->new_display('default', 'Defaults', 'default');
// $handler->display->display_options['title'] = 'All ';
// $handler->display->display_options['use_ajax'] = TRUE;
// $handler->display->display_options['use_more_always'] = FALSE;
// $handler->display->display_options['access']['type'] = 'role';
// $handler->display->display_options['access']['role'] = array(
//   3 => '3',
// );
// $handler->display->display_options['cache']['type'] = 'none';
// $handler->display->display_options['query']['type'] = 'views_query';
// $handler->display->display_options['query']['options']['query_comment'] = FALSE;
// $handler->display->display_options['exposed_form']['type'] = 'basic';
// $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
// $handler->display->display_options['pager']['type'] = 'full';
// $handler->display->display_options['pager']['options']['items_per_page'] = '35';
// $handler->display->display_options['pager']['options']['offset'] = '0';
// $handler->display->display_options['pager']['options']['id'] = '0';
// $handler->display->display_options['style_plugin'] = 'table';
// $handler->display->display_options['style_options']['columns'] = array(
//   'views_bulk_operations' => 'views_bulk_operations',
//   'title' => 'title',
//   'name' => 'name',
//   'created' => 'created',
//   'changed' => 'changed',
//   'status' => 'status',
//   'edit_node' => 'edit_node',
// );
// $handler->display->display_options['style_options']['default'] = '-1';
// $handler->display->display_options['style_options']['info'] = array(
//   'views_bulk_operations' => array(
//     'align' => '',
//     'separator' => '',
//   ),
//   'title' => array(
//     'sortable' => 0,
//     'default_sort_order' => 'asc',
//     'align' => '',
//     'separator' => '',
//   ),
//   'name' => array(
//     'sortable' => 1,
//     'default_sort_order' => 'asc',
//     'align' => '',
//     'separator' => '',
//   ),
//   'created' => array(
//     'sortable' => 1,
//     'default_sort_order' => 'asc',
//     'align' => '',
//     'separator' => '',
//   ),
//   'changed' => array(
//     'sortable' => 1,
//     'default_sort_order' => 'asc',
//     'align' => '',
//     'separator' => '',
//   ),
//   'status' => array(
//     'sortable' => 0,
//     'default_sort_order' => 'asc',
//     'align' => '',
//     'separator' => '',
//   ),
//   'edit_node' => array(
//     'align' => '',
//     'separator' => '',
//   ),
// );
// /* No results behavior: Global: Text area */
// $handler->display->display_options['empty']['text']['id'] = 'area';
// $handler->display->display_options['empty']['text']['table'] = 'views';
// $handler->display->display_options['empty']['text']['field'] = 'area';
// $handler->display->display_options['empty']['text']['content'] = 'There is not any content on your site.';
// $handler->display->display_options['empty']['text']['format'] = '1';
// /* Relationship: Content: Content author */
// $handler->display->display_options['relationships']['uid']['id'] = 'uid';
// $handler->display->display_options['relationships']['uid']['table'] = 'node';
// $handler->display->display_options['relationships']['uid']['field'] = 'uid';
// /* Field: Bulk operations: Content */
// $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
// $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
// $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
// $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
// $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
// $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
// $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
// $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
// $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
// $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
// $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
//   'action::views_bulk_operations_delete_item' => array(
//     'selected' => 1,
//     'skip_confirmation' => 0,
//     'override_label' => 0,
//     'label' => '',
//     'postpone_processing' => 0,
//   ),
//   'action::node_promote_action' => array(
//     'selected' => 1,
//     'skip_confirmation' => 0,
//     'override_label' => 0,
//     'label' => '',
//     'postpone_processing' => 0,
//   ),
//   'action::node_publish_action' => array(
//     'selected' => 1,
//     'skip_confirmation' => 0,
//     'override_label' => 0,
//     'label' => '',
//     'postpone_processing' => 0,
//   ),
//   'action::node_unpromote_action' => array(
//     'selected' => 1,
//     'skip_confirmation' => 0,
//     'override_label' => 0,
//     'label' => '',
//     'postpone_processing' => 0,
//   ),
//   'action::node_unpublish_action' => array(
//     'selected' => 1,
//     'skip_confirmation' => 0,
//     'override_label' => 0,
//     'label' => '',
//     'postpone_processing' => 0,
//   ),
// );
// /* Field: Content: Title */
// $handler->display->display_options['fields']['title']['id'] = 'title';
// $handler->display->display_options['fields']['title']['table'] = 'node';
// $handler->display->display_options['fields']['title']['field'] = 'title';
// $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
// /* Field: User: Name */
// $handler->display->display_options['fields']['name']['id'] = 'name';
// $handler->display->display_options['fields']['name']['table'] = 'users';
// $handler->display->display_options['fields']['name']['field'] = 'name';
// $handler->display->display_options['fields']['name']['relationship'] = 'uid';
// $handler->display->display_options['fields']['name']['label'] = 'Author';
// $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
// $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
// /* Field: Content: Post date */
// $handler->display->display_options['fields']['created']['id'] = 'created';
// $handler->display->display_options['fields']['created']['table'] = 'node';
// $handler->display->display_options['fields']['created']['field'] = 'created';
// $handler->display->display_options['fields']['created']['label'] = 'Created date';
// $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
// $handler->display->display_options['fields']['created']['date_format'] = 'custom';
// $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d g:ia';
// /* Field: Content: Updated date */
// $handler->display->display_options['fields']['changed']['id'] = 'changed';
// $handler->display->display_options['fields']['changed']['table'] = 'node';
// $handler->display->display_options['fields']['changed']['field'] = 'changed';
// $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
// $handler->display->display_options['fields']['changed']['hide_alter_empty'] = FALSE;
// $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
// $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d g:ia';
// /* Field: Content: Published status */
// $handler->display->display_options['fields']['status']['id'] = 'status';
// $handler->display->display_options['fields']['status']['table'] = 'node';
// $handler->display->display_options['fields']['status']['field'] = 'status';
// $handler->display->display_options['fields']['status']['not'] = 0;
// /* Field: Content: Link to edit content */
// $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
// $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
// $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
// $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
// $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
// /* Sort criterion: Content: Post date */
// $handler->display->display_options['sorts']['created']['id'] = 'created';
// $handler->display->display_options['sorts']['created']['table'] = 'node';
// $handler->display->display_options['sorts']['created']['field'] = 'created';
// $handler->display->display_options['sorts']['created']['order'] = 'DESC';
// /* Filter criterion: Content: Published status */
// $handler->display->display_options['filters']['status']['id'] = 'status';
// $handler->display->display_options['filters']['status']['table'] = 'node';
// $handler->display->display_options['filters']['status']['field'] = 'status';
// $handler->display->display_options['filters']['status']['value'] = '1';
// $handler->display->display_options['filters']['status']['exposed'] = TRUE;
// $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
// $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
// /* Filter criterion: User: Name */
// $handler->display->display_options['filters']['uid']['id'] = 'uid';
// $handler->display->display_options['filters']['uid']['table'] = 'users';
// $handler->display->display_options['filters']['uid']['field'] = 'uid';
// $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
// $handler->display->display_options['filters']['uid']['value'] = '';
// $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
// $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
// $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
// $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
// $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
// /* Filter criterion: Search: Search Terms */
// $handler->display->display_options['filters']['keys']['id'] = 'keys';
// $handler->display->display_options['filters']['keys']['table'] = 'search_index';
// $handler->display->display_options['filters']['keys']['field'] = 'keys';
// $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
// $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
// $handler->display->display_options['filters']['keys']['expose']['label'] = 'Contains';
// $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
// $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
// /* Filter criterion: Content: Type */
// $handler->display->display_options['filters']['type']['id'] = 'type';
// $handler->display->display_options['filters']['type']['table'] = 'node';
// $handler->display->display_options['filters']['type']['field'] = 'type';
// $handler->display->display_options['filters']['type']['exposed'] = TRUE;
// $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
// $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
// $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
// $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
// /* Filter criterion: Content: Type */
// $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
// $handler->display->display_options['filters']['type_1']['table'] = 'node';
// $handler->display->display_options['filters']['type_1']['field'] = 'type';
// $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
// $handler->display->display_options['filters']['type_1']['value'] = array(
//   'message' => 'message',
//   'project' => 'project',
// );

// /* Display: All Content */
// $handler = $view->new_display('page', 'All Content', 'page_1');
// $handler->display->display_options['defaults']['title'] = FALSE;
// $handler->display->display_options['title'] = 'All content';
// $handler->display->display_options['path'] = 'admin/content';
// $handler->display->display_options['menu']['type'] = 'default tab';
// $handler->display->display_options['menu']['title'] = 'All content';
// $handler->display->display_options['menu']['description'] = 'All content';
// $handler->display->display_options['menu']['weight'] = '-19';
// $handler->display->display_options['menu']['name'] = 'management';
// $handler->display->display_options['menu']['context'] = 0;
// $handler->display->display_options['menu']['context_only_inline'] = 0;
// $handler->display->display_options['tab_options']['type'] = 'tab';
// $handler->display->display_options['tab_options']['title'] = 'Content';
// $handler->display->display_options['tab_options']['weight'] = '-19';
// $handler->display->display_options['tab_options']['name'] = 'management';
