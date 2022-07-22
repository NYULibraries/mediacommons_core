#!/usr/bin/env php
<?php

$approot = realpath(dirname(__FILE__) . '/..');

chdir($approot);

define('DRUPAL_ROOT', getcwd() . '/drupal');

$xml = false;

// bootstrap.inc includes Drupal's version (defined as VERSION)
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';

$release_history = "$approot/tmp/release-history.xml";

if (file_exists($release_history)) {
  $mtime = filemtime($release_history);
  if ($mtime + 7200 > time()) {
    file_put_contents($release_history, file_get_contents('https://updates.drupal.org/release-history/drupal/7.x'));
  }
  $xml = simplexml_load_file($release_history);
} else {
  file_put_contents($release_history, file_get_contents('https://updates.drupal.org/release-history/drupal/7.x'));  
  $xml = simplexml_load_file($release_history);
}

if (!$xml) {
  echo 'Unable to read release history.';
  exit(1);
}

$release = $xml->releases->children()[0];

$release_version = (string) $release->version;

$release_download_link = (string) $release->download_link;

$release_status = (string) $release->status;

$release_mdhash = (string) $release->mdhash;

if (VERSION <= $release_version) {

  $url = parse_url($release_download_link);
  
  $filepath = explode('/', $url['path']);
  
  $filename = $filepath[3];

  // Download latest if not available in disk.
  if (!file_exists("$approot/tmp/$filename")) {
    file_put_contents("$approot/tmp/$filename", file_get_contents($release_download_link));
  }

  // Check if we have a valid file.
  if ($release_mdhash == md5_file("$approot/tmp/$filename")) {
    try {
      if (file_exists("$approot/tmp/drupal-$release_version")) {
        echo "Error: Directory already $approot/tmp/drupal-$release_version";
        exit(1);
      } else {

        $phar = new PharData("$approot/tmp/$filename");

        $extract = $phar->extractTo("$approot/tmp");

        if (file_exists("$approot/tmp/drupal-$release_version/robots.txt")) {
          rename("$approot/tmp/drupal-$release_version/robots.txt", "$approot/tmp/drupal-$release_version/robots.txt.tmp");
        }

        // Remove all text files. e.g., 
        array_map('unlink', glob("$approot/tmp/drupal-$release_version/*.txt"));
        if (file_exists("$approot/tmp/drupal-$release_version/robots.txt.tmp")) {
          rename("$approot/tmp/drupal-$release_version/robots.txt.tmp", "$approot/tmp/drupal-$release_version/robots.txt");
        }

        if (file_exists("$approot/tmp/drupal-$release_version/.htaccess")) {
          rename("$approot/tmp/drupal-$release_version/.htaccess", "$approot/tmp/drupal-$release_version/.htaccess.off");
        }

        // Remove not used file.
        if (file_exists("$approot/tmp/drupal-$release_version/install.php")) {
          unlink("$approot/tmp/drupal-$release_version/install.php");
        }

        // Remove not used file.
        if (file_exists("$approot/tmp/drupal-$release_version/.gitignore")) {
          unlink("$approot/tmp/drupal-$release_version/.gitignore");
        }
        
        // Remove not used file.
        if (file_exists("$approot/tmp/drupal-$release_version/web.config")) {
          unlink("$approot/tmp/drupal-$release_version/web.config");
        }

        // Remove sites directory. Will replace with current site.
        if (file_exists("$approot/tmp/drupal-$release_version/sites")) {
          system('rm -rf ' . escapeshellarg("$approot/tmp/drupal-$release_version/sites"));
        }

        // Move current sites directory to latest release.
        system('mv ' . escapeshellarg("$approot/drupal/sites") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/sites"));

        // Move profile mediacommons_projects to latest release.
        if (file_exists("$approot/drupal/profiles/mediacommons_projects")) {
          system('mv ' . escapeshellarg("$approot/drupal/profiles/mediacommons_projects") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/profiles/mediacommons_projects"));
        }

        // Move profile mediacommons_umbrella to latest release.
        if (file_exists("$approot/drupal/profiles/mediacommons_umbrella")) {
          system('mv ' . escapeshellarg("$approot/drupal/profiles/mediacommons_umbrella") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/profiles/mediacommons_umbrella"));
        }

        // Move vendor to latest release.
        if (file_exists("$approot/drupal/vendor")) {
          system('mv ' . escapeshellarg("$approot/drupal/vendor") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/vendor"));
        }

        if (file_exists("$approot/drupal/composer.lock")) {
          system('mv ' . escapeshellarg("$approot/drupal/composer.lock") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/composer.lock"));
        }

        if (file_exists("$approot/drupal/composer.json")) {
          system('mv ' . escapeshellarg("$approot/drupal/composer.json") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/composer.json"));
        }

        if (file_exists("$approot/drupal/android-chrome-192x192.png")) {
          system('mv ' . escapeshellarg("$approot/drupal/android-chrome-192x192.png") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/android-chrome-192x192.png"));
        }        

        if (file_exists("$approot/drupal/android-chrome-512x512.png")) {
          system('mv ' . escapeshellarg("$approot/drupal/android-chrome-512x512.png") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/android-chrome-512x512.png"));
        }

        if (file_exists("$approot/drupal/apple-touch-icon.png")) {
          system('mv ' . escapeshellarg("$approot/drupal/apple-touch-icon.png") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/apple-touch-icon.png"));
        }

        if (file_exists("$approot/drupal/favicon-16x16.png")) {
          system('mv ' . escapeshellarg("$approot/drupal/favicon-16x16.png") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/favicon-16x16.png"));
        }

        if (file_exists("$approot/drupal/favicon-32x32.png")) {
          system('mv ' . escapeshellarg("$approot/drupal/favicon-32x32.png") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/favicon-32x32.png"));
        }

        if (file_exists("$approot/drupal/favicon.ico")) {
          system('mv ' . escapeshellarg("$approot/drupal/favicon.ico") . ' ' . escapeshellarg("$approot/tmp/drupal-$release_version/favicon.ico"));
        }

        system('rm -rf ' . escapeshellarg("$approot/drupal"));

        system('mv ' . escapeshellarg("$approot/tmp/drupal-$release_version") . ' ' . escapeshellarg("$approot/drupal"));


      }
    } catch (Exception $e) {
      echo $e->getMessage(), PHP_EOL;
      exit(1);
    }
  } else {
    echo "File $approot/tmp/$filename mdhash does not match Drupal's core latest mdhash.";
    exit(1);
  }

}

exit(0);

