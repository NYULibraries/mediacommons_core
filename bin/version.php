#!/usr/bin/env php
<?php

$current = realpath(dirname(__FILE__) . '/..');

chdir($current);

define('DRUPAL_ROOT', getcwd() . '/drupal');

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';

echo VERSION;
