<?php

/**
 * @file
 * projects.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function projects_user_default_roles() {
  $roles = array();

  // Exported role: user manager.
  $roles['user manager'] = array(
    'name' => 'user manager',
    'weight' => 5,
  );

  return $roles;
}
