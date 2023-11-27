<?php

/**
 * Implements hook_drush_command().
 */
function mc_drush_command() {

  $items = array();

  $items['rebuild-cache'] = array(
    'description' => 'Rebuild all MediaCommons blocks cache.',
    'arguments' => array(),
    'options' => array(),
    'aliases' => array('mcrc'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['claim-network-jobs'] = array(
    'description' => 'Run MediaCommons network jobs.',
    'arguments' => array(),
    'options' => array(),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['reset-globalnav'] = array(
    'description' => 'Reset MediaCommons Global nav.',
    'arguments' => array(),
    'options' => array(),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['solr-metadata'] = array(
    'description' => 'Refresh Apache Solr Multi-Site metadata.',
    'aliases' => array('amrm'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['set-theme-setting-class-name'] = array(
    'description' => 'Set theme settings Special Body Class Name.',
    'arguments' => array(
      'class' => 'Special Body Class Name',
    ),
    'options' => array(
      'option-name' => array(
        'description' => 'Set the Special Body Class Name.',
        'example-value' => 'e.g., tne',
      ),
    ),
    'aliases' => array('stscn'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['update-fieldguide-umbrella-block'] = array(
    'description' => 'Update fieldguide Umbrella block',
    'arguments' => array(
      'feed' => 'Fieldguide URL',
    ),
    'options' => array(
      'option-name' => array(
        'description' => 'Fieldguide URL',
        'example-value' => 'e.g., http://example.com',
      ),
    ),
    'aliases' => array('ufub'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['list-user-by-role'] = array(
    'description' => 'List users by role',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['check-develop'] = array(
    'description' => 'Check develop',
    'arguments' => array(),
    'options' => array(),
    'aliases' => array('mccd'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['reload-mc-menu'] = array(
    'description' => 'Reload MediaCommons Global Navigation',
    'arguments' => array(),
    'options' => array(),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['before-import'] = array(
    'description' => 'Run task before update',
    'arguments' => array(),
    'options' => array(),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  $items['update-filters'] = array(
    'description' => 'Update filters',
    'arguments' => array(),
    'options' => array(),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  return $items;

}

/**
 * Implements hook_drush_help().
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function mc_drush_help($section) {
  switch ($section) {
    case 'drush:solr-metadata':
      return dt('Refresh Apache Solr Multi-Site metadata');

    case 'drush:set-theme-setting-class-name':
      return dt('Set theme settings Special Body Class Name.');

    case 'drush:rebuild-cache':
      return dt("Rebuild all MediaCommons blocks cache.");
  }
}

// $ drush update-filters
function drush_mc_update_filters() {
  $result = db_query('SELECT * FROM {mediacommons_filter}');
  $domains = array();
  foreach ($result as $record) {
    $domain = str_replace('https://', '', $record->domain);
    $id = md5($domain);
    $domains[$id] = array(
      'did' => $id,
      'domain' => $domain,
    );
  }
  mediacommons_filter_update_7001();
  foreach ($domains as $record) {
    db_insert('mediacommons_filter')->fields($record)->execute();
  }
}

/**
 * Implementation of drush_hook_COMMAND().
 */
function drush_mc_solr_metadata() {
  module_load_include('inc', 'apachesolr_multisitesearch', 'apachesolr_multisitesearch.index');
  // Delete all current variables and refresh them
  variable_del('apachesolr_multisitesearch_last_metadata_update');
  variable_del('apachesolr_multisitesearch_last_metadata_fetch');
  apachesolr_multisitesearch_refresh_metadata();
  drush_log(dt('The metadata has been refreshed.'), 'ok');
}

/**
 * Implementation of drush_hook_COMMAND().
 */
function drush_mc_set_theme_setting_class_name($class) {
  $settings = variable_get('theme_mediacommons_settings');
  $settings['special_body_class'] = $class;
  variable_set('theme_mediacommons_settings', $settings);
}

function drush_mc_update_fieldguide_umbrella_block() {
  mediacommons_fieldguide_cron();
}

function drush_mc_reload_mc_menu() {
  _mediacommons_globalnav_config();
}

function drush_mc_init_fieldguide() {
  module_enable(array('mediacommons_fieldguide'));
  mediacommons_fieldguide_cron();
}

function drush_mc_claim_network_jobs() {
  $project = variable_get('mediacommons_project', 'mediacommons');
  $update = array(
    'processed' => 1,
    'changed' => time(),
  );
  $items = db_query_range('SELECT * FROM {mc_network_actions} WHERE processed = 0 AND project = :project ORDER BY aid ASC', 0, 25, array(':project' => $project))->fetchAll();
  if ($items) {
    foreach ($items as $item) {
      drush_log('Job ' . $item->aid, 'ok');
      $data = unserialize($item->data);
      $callback = $item->callback;
      if (function_exists($callback)) {
        try {
          $callback($data);
          $succeeded = db_update('mc_network_actions')->fields($update)->condition('aid', $item->aid, '=')->execute();
        } catch (Exception $e) {
          die(__FILE__ . ' ' .  __LINE__ . ' ' . $e->getMessage());
        }
      }
      else {
        $update['processed'] = 9;
        $succeeded = db_update('mc_network_actions')->fields($update)->condition('aid', $item->aid, '=')->execute();
        die(__FILE__ . ' ' .  __LINE__ . ' callback "' . $callback . '" does not exists.');
      }
    }
  }
}

/**
 * Implementation of drush_hook_COMMAND().
 */
function drush_mc_rebuild_cache () {
  while (TRUE) {
    $update = array(
      'proceed' => time(),
      'expire' => time() + (3600 * 4),
    );
    $item = db_query_range("SELECT mbid, type, url, callback FROM {mediacommons_blocks_blocks} WHERE expire > 0 AND type = '2' ORDER BY proceed ASC", 0, 1, array())->fetchObject();
    if ($item) {
      if ($item->type == 2) {
        // 2 stands for source. See: mediacommons_blocks_list_types
        if ($item->url) {
          $url = check_url($item->url);
          $request = drupal_http_request($url);
          if ($request->status_message) {
            $status_message = strtolower(check_plain($request->status_message));
            if ($status_message == 'ok') {
              $text = filter_xss($request->data, mediacommons_filter_allowed_tags());
              $update['content'] = serialize($text);
            }
          }
        }
        $succeeded = db_update('mediacommons_blocks_blocks')->fields($update)->condition('mbid', $item->mbid, '=')->execute();
        if ($succeeded) {
          drush_log('MediaCommons Blocks: Cache cleaned', 'ok');
          return $item;
        }
      }
      else {
        // at the moment we only cache source
        // No items currently available to claim.
        return FALSE;
      }
    }
    else {
      // No items currently available to claim.
      return FALSE;
    }
  }
}

function drush_mc_user_picture($uri) {
  $filepath = pathinfo($uri);
  $destination_file = 'public://pictures/' . $filepath['basename'];
  $handle = fopen($uri, 'r');
  $file = file_save_data($handle, $destination_file, FILE_EXISTS_REPLACE);
  fclose($handle);
  return $file;
}

/** Create a taxonomy term and return the tid */
function drush_mc_create_taxonomy_term($vocabulary, $term) {
  $new = new stdClass();
  $new->vid = $vocabulary->vid;
  $new->name = $term->name;
  $new->description = $term->description;
  $new->weight = $term->weight;
  $new->parent = (int) $term->parent;
  return $new;
}

function drush_mc_check_develop() {
  $modules = array(
    'devel',
    'ds_devel',
    'reroute_email',
  );
  module_enable($modules);
}

function drush_mc_reset_globalnav() {
  if (function_exists('_mediacommons_globalnav_config')) {
    _mediacommons_globalnav_config();
  }
}

function  drush_mc_list_user_by_role() {
  $authenticated_user = 2;
  $contributor = 5;
  $uids = array();
  $query = 'SELECT DISTINCT(ur.uid)
    FROM {users_roles} AS ur
    WHERE ur.rid IN (:rids)';
  $result = db_query($query, array(':rids' => array(5)));

  foreach ($result as $row) {
    $user = module_invoke('user', 'load', $row->uid);
    print($user->uid);
    echo PHP_EOL;
    unset($user->roles[5]);
    user_save($user, array('roles' => $user->roles));
  }
}