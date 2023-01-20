<?php

class mediacommons_user_picture_handler extends views_handler_field_user_picture {

  function image_url($uid) {
    $result = db_select('mediacommons_base_import_user_map', 'u')->fields('u', array('filename'))->condition('uid', $uid)->execute()->fetchField();
    if ($result && $result !== '0') {
      return  variable_get('user_picture_default', 'pictures') . '/' . $result;
    }
  }
  
  function render($values) {
    if ($this->options['image_style'] && module_exists('image')) {
      $picture_fid = $this->get_value($values);
      $uid = $this->get_value($values, 'uid');
      $picture_filepath = $this->image_url($uid);
      if ($picture_filepath) {
        $output = theme('image_style', array('style_name' => $this->options['image_style'], 'path' => $picture_filepath));
        if ($this->options['link_photo_to_profile'] && user_access('access user profiles')) {
          $output = l($output, "user/$uid", array('html' => TRUE));
        }
      }
      else {
        $output = '';
      }
    }
    else {
      // Fake an account object.
      $account = new stdClass();
      if ($this->options['link_photo_to_profile']) {
        // Prevent template_preprocess_user_picture from adding a link
        // by not setting the uid.
        $account->uid = $this->get_value($values, 'uid');
      }
      $account->name = $this->get_value($values, 'name');
      $account->mail = $this->get_value($values, 'mail');
      $account->picture = $this->get_value($values);
      $output = theme('user_picture', array('account' => $account));
    }
    return $output;
  }
}