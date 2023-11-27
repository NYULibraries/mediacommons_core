<?php
/**
 * @file
 * mediacommons_content_types.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mediacommons_content_types_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: cluster curator.
  $roles['cluster curator'] = array(
    'name' => 'cluster curator',
    'weight' => 2,
  );

  // Exported role: contributor.
  $roles['contributor'] = array(
    'name' => 'contributor',
    'weight' => 4,
  );

  // Exported role: managing editor.
  $roles['managing editor'] = array(
    'name' => 'managing editor',
    'weight' => 3,
  );

  return $roles;
}
