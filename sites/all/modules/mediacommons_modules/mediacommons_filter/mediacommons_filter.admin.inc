<?php

/**
 * @file
 * Admin page.
 */

function mediacommons_filter_admin($form, &$form_state) {

  $result = db_query('SELECT * FROM {mediacommons_filter}');

  $form['sources'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add or edit allowed domains in an iframe'),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
  );

  foreach ($result as $record) {
    $form['sources']['sources_u_' . md5($record->domain)] = array(
      '#type' => 'textfield',
      '#title' => t('Allowed domain'),
      '#default_value' => $record->domain,
      '#size' => 60,
      '#maxlength' => 256,
      '#description' => t('Set host name. <acronym title="for example">e.g.</acronym>, nyu.edu'),
      '#required' => FALSE,
    );
  }

  $form['sources']['sources_n_1'] = array(
    '#type' => 'textarea',
    '#title' => t('Add more allowed domain'),
    '#description' => t('Set domains. <acronym title="for example">e.g.</acronym>, nyu.edu, example.com'),
    '#required' => FALSE,
  );

  $form['#submit'][] = 'mediacommons_filter_admin_settings_submit';

  return system_settings_form($form);

}

/**
 * Form submit handler for mediacommons_filter admin settings form.
 */
function mediacommons_filter_admin_settings_submit($form, &$form_state) {
  $result = db_query('SELECT * FROM {mediacommons_filter}');
  $domains = array();
  $cache = array();
  foreach ($form_state['values'] as $key => $value) {
    $value = trim(filter_xss($value));
    preg_match('/sources_([un]{1})_([\w]+)/', $key, $matches);
    if ($matches) {
      $op = $matches[1];
      $did = $matches[2];
      switch ($op) {
        case 'n':
          $new_domains = explode(',', $value);
          foreach ($new_domains as $new_domain) {
            $parsed_domain = parse_url(trim($new_domain));
            if (empty($value)) {
              continue;
            }
            // test URL scheme
            if (!isset($parsed_domain['scheme'])) {
              // set error msg
              drupal_set_message(t('An error occurred. Invalid URL @uri, please provide a valid URL. E.g., <em>https://</em>example.com', array('@uri' => $new_domain)), 'error');
              continue;
            }
            if (isset($parsed_domain['scheme']) && $parsed_domain['scheme'] == 'http') {
              // set error msg
              drupal_set_message(t('Invalid URL @uri, please provide a valid HTTPS URL. E.g., <em>https://</em>example.com', array('@uri' => $new_domain)), 'error');
              continue;
            }

            // test URL host
            if (!isset($parsed_domain['host'])) {
              // set error msg
              drupal_set_message(t('An error occurred. Invalid URL @uri, please provide a valid URL. E.g., https://<em>example.com</em>', array('@uri' => $new_domain)), 'error');
              continue;
            }
            // update allowed domain list
            if (!in_array($new_domain, $domains)) {
              $update = array(
                'did' => md5($new_domain),
                'domain' => $new_domain,
              );
              db_insert('mediacommons_filter')->fields($update)->execute();
            }
          }
          break;

        case 'u':
          $did = $matches[2];
          if (empty($value)) {
            if ($did) {
              db_delete('mediacommons_filter')->condition('did', $did)->execute();
            }
            else {
              drupal_set_message(t('An error occurred trying to remove source', array('@uri' => $new_domain)), 'error');
            }
          }
          elseif ($value != $domains[$did]) {
            db_update('mediacommons_filter')->fields(array('domain' => $value, 'did' => md5($value)))->condition('did', $did, '=')->execute();
          }
          break;
      }
    }
  }

}
