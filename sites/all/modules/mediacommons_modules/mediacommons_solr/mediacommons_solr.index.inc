<?php

/**
 * @file
 * MediaCommons Integration with the Apache Solr module.
 * Indexing task
 */

/**
 * Build the documents before sending them to Solr.
 * The function is the follow-up for apachesolr_update_index
 *
 * @param integer $document_id
 * @param array $entity
 * @param string $entity_type
 */
function mediacommons_solr_apachesolr_index_document_build(ApacheSolrDocument $document, $entity, $entity_type, $env_id) {
  global $base_url;
  $wrapper = entity_metadata_wrapper($entity_type, $entity);
  $bundle = $wrapper->getBundle();
  $document->addField('im_contributors', $entity->uid);
  $document->addField('ss_searchtype', $bundle);
  $document->addField('ss_baseurl', $base_url);
  $document->addField('ss_project', variable_get('mediacommons_project', 'project'));
  $document->addField('ss_projectname', variable_get('site_name', 'MediaCommons Project'));
  $document->addField('ss_projectclass', theme_get_setting('special_body_class', 'mediacommons'));
  $call = 'mediacommons_solr_apachesolr_index_document_build_' . $bundle;
  // content
  if (function_exists($call)) {
    $call($document, $wrapper, $entity);
  }
}

/**
 * Spoke
 */
function mediacommons_solr_apachesolr_index_document_build_spoke(&$document, $wrapper, $entity) {
  // Contributors
  $json = array();
  foreach ($wrapper->field_contributors->value() as $delta => $user_entity) {
    $document->addField('im_contributors', $user_entity->uid);
    $document->addField('im_contributor', $user_entity->uid);
    $json[] = mediacommons_solr_user_metadata($user_entity);
  }
  $document->addField('zs_contributors', json_encode($json));
  // Representative image
  $ri = array();
  $representativeimage = $wrapper->field_representative_image->value();
  if ($representativeimage['fid']) {
    foreach (image_styles() as $style) {
      $derivative_uri = image_style_path($style['name'], $representativeimage['uri']);
      if (!file_exists($derivative_uri)) {
        $image = image_style_create_derivative($style, $representativeimage['uri'], $derivative_uri);
        if ($image) {
          $imageurl = file_create_url($derivative_uri);
        }
      }
      else {
        $imageurl = file_create_url($derivative_uri);
      }
      if (isset($imageurl)) {
        $ri [$style['name']] = $imageurl;
      }
    }
  }
  $document->addField('ss_comment_count', $entity->comment_count);
  $document->addField('zs_ri', json_encode($ri));
  $pubdate = $wrapper->field_pubdate->value();
  if (empty($pubdate)) {
    $pubdate = $entity->created;
  }
  $document->addField('ss_periodstart', $pubdate);
  $document->addField('ss_createddate', date('F d, Y', $pubdate));
  $document->addField('ss_cdyyyymmdd', date('Y-m-d', $pubdate));
  $document->addField('ss_pubdate', date('F d, Y', $pubdate));
  // Timestamp of the node
  $document->addField('ds_pubdate', apachesolr_date_iso($pubdate));
  $document->addField('ds_pubdated', apachesolr_date_iso($pubdate));
  $document->addField('ds_pubdatea', apachesolr_date_iso($pubdate));
  /** searchable content; dump all you want to be searchable in this array */
  $searchableFields = array();
  $searchableFields[] = $document->content;
  unset($document->content);
  // Use node id to search for any reference (e.g., "Review" of this "Spoke")
  $query = new EntityFieldQuery;
  $keys = array();
  $result = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'review')
    ->fieldCondition('field_isreviewof', 'nid', array($entity->nid))
    ->execute();

  // Reviewers
  $json_reviewers = array();
  if (!empty($result['node'])) {
    $keys = array_keys($result['node']);
    foreach ($keys as $key) {
      $review_node = node_load($key);
      $searchableFields[] = apachesolr_clean_text($entity->title . ' ' . drupal_render(node_view($review_node, 'full')));
      // Use entity API
      $review_wrapper = entity_metadata_wrapper('node', $review_node);
      // Get all the reviewer using Entity API
      foreach ($review_wrapper->field_reviewer->value() as $delta => $reviewer) {
        $document->addField('im_reviewers', $reviewer->uid);
        $document->addField('im_reviewer', $reviewer->uid);
        $review_user = user_load($reviewer->uid);
        $json_reviewers[] = mediacommons_solr_user_metadata($review_user);
      }
    }
  }
  $document->addField('zs_reviewers', json_encode($json_reviewers));
  $document->addField('content', implode(' ', $searchableFields));
}

/**
 * Hub
 */
function mediacommons_solr_apachesolr_index_document_build_hub(&$document, $wrapper, $entity) {
  // Save representative image styles + URLs as JSON
  $ri = array();
  $representativeimage = $wrapper->field_representative_image->value();
  if ($representativeimage['fid']) {
    foreach (image_styles() as $style) {
			$derivative_uri = image_style_path($style ['name'], $representativeimage['uri']);
			if (!file_exists($derivative_uri)) {
				$image = image_style_create_derivative($style, $representativeimage['uri'], $derivative_uri);
				if ($image) {
					$imageurl = file_create_url($derivative_uri);
				}
			} else {
				$imageurl = file_create_url($derivative_uri);
			}
			// Make sure we have a URL
			if (isset($imageurl)) {
				$ri [$style ['name']] = $imageurl;
			}
		}
	}
	$document->addField('zs_ri', json_encode($ri));

	// Contributors
	$json = array();
	foreach ($wrapper->field_contributors->value () as $delta => $user_entity ) {
		$document->addField('im_contributors', $user_entity->uid );
		$document->addField('im_contributor', $user_entity->uid );
		$json [] = mediacommons_solr_user_metadata ($user_entity );
	}
	$document->addField('zs_contributors', json_encode ($json ) );

	// Curators editors
	$json = array ();
	foreach ($wrapper->field_curators_editors->value () as $delta => $user_entity ) {
		$document->addField('im_contributors', $user_entity->uid );
		$document->addField('im_curatorseditors', $user_entity->uid );
		$json [] = mediacommons_solr_user_metadata ($user_entity );
	}
	$document->addField('zs_curatorseditors', json_encode ($json ) );

	// Co-editors
	$json = array ();
	foreach ($wrapper->field_co_editor->value () as $delta => $user_entity ) {
		$document->addField('im_contributors', $user_entity->uid );
		$document->addField('im_coeditor', $user_entity->uid );
		$json [] = mediacommons_solr_user_metadata ($user_entity );
	}

	$document->addField('zs_coeditor', json_encode($json));

	$period = $wrapper->field_period->value();

	// Period start
	if (isset ($period ['value'] ) && ! empty ($period['value'])) {
		$document->addField('ss_periodstart', $period['value']);
		$document->addField('ss_createddate', date('F d, Y', $period['value']));
		$document->addField('ss_cdyyyymmdd', date('Y-m-d', $period['value']));
		$document->addField('ss_pubdate', date('F d, Y', $period['value']));
		$document->addField('ds_pubdate', apachesolr_date_iso($period['value']));
		$document->addField('ds_pubdated', apachesolr_date_iso($period['value']));
		$document->addField('ds_pubdatea', apachesolr_date_iso($period['value']));

	}
	else {
	  $document->addField('ss_periodstart', $entity->created );
      $document->addField('ss_createddate', date ('F d, Y', $entity->created ) );
      $document->addField('ss_cdyyyymmdd', date ('Y-m-d', $entity->created ) );
      $document->addField('ss_pubdate', date ('F d, Y', $entity->created ) );
      $document->addField('ds_pubdate', apachesolr_date_iso($entity->created));
      $document->addField('ds_pubdated', apachesolr_date_iso($entity->created));
      $document->addField('ds_pubdatea', apachesolr_date_iso($entity->created));
	}

	// Period end
	if (isset ($period ['value2'] ) && ! empty ($period ['value2'] )) {
		$document->addField('ss_periodend', $period ['value2'] );
		$document->addField('ss_enddate', date ('F d, Y', $period ['value2'] ) );
		$document->addField('ss_edyyyymmdd', date ('Y-m-d', $period ['value2'] ) );
	} else {
		$document->addField('ss_periodend', $entity->created );
		$document->addField('ss_enddate', date ('F d, Y', $entity->created ) );
		$document->addField('ss_edyyyymmdd', date ('Y-m-d', $entity->created ) );
	}
}

/**
 * Review
 */
function mediacommons_solr_apachesolr_index_document_build_review(&$document, $wrapper, $entity) {
  global $base_url;
  $json = array();

  foreach ($wrapper->field_reviewer->value() as $item) {
    $document->addField('im_contributors', $item->uid);
    $document->addField('im_reviewer', $item->uid);
    $json[] = mediacommons_solr_user_metadata($item);
  }

  $document->addField('zs_reviewer', json_encode($json));
  $document->addField('ss_pubdate', apachesolr_date_iso($entity->created));
  $document->addField('ss_pubdated', apachesolr_date_iso($entity->created));
  $document->addField('ss_pubdatea', apachesolr_date_iso($entity->created));
  $isreviewof = $wrapper->field_isreviewof->value();

  $referencedspoke = array(
    'cid' => NULL,
    'nid' => $isreviewof->nid,
    'label' => $isreviewof->title,
    'url' => $base_url . '/' . drupal_get_path_alias('node/' . $isreviewof->nid),
  );

  $document->addField('ss_referencedspoke', json_encode($referencedspoke));

  unset($node);
}

/**
 * Comment node spoke
 */
function mediacommons_solr_apachesolr_index_document_build_comment_node_spoke(&$document, $wrapper, $entity) {
  global $base_url;
  $document->addField('ss_periodstart', $entity->created);
  // Data needed: date comment was created, in this format:  Monday, October 23, 2017 — 7:46 pm
  // http://php.net/manual/en/function.date.php
  $document->addField('ss_createddate', date('l, F j, Y — g:i a', $entity->created));
  $document->addField('ss_cdyyyymmdd', date('Y-m-d', $entity->created));
  $document->addField('ss_pubdate', date('F d, Y', $entity->created));
  $document->addField('ds_pubdate', apachesolr_date_iso($entity->created));
  $document->addField('ds_pubdated', apachesolr_date_iso($entity->created));
  $document->addField('ds_pubdatea', apachesolr_date_iso($entity->created));
  $node = node_load($entity->nid);
  $referencedspoke = array(
    'cid' => $entity->cid,
    'nid' => $entity->nid,
    'label' => $node->title,
    'url' => $base_url . '/' . drupal_get_path_alias('node/' . $entity->nid),
  );
  $document->addField('ss_referencedspoke', json_encode($referencedspoke));
  unset($node);
  $json = array();
  $document->addField('im_contributors', $entity->uid);
  $document->addField('im_contributor', $entity->uid);
  $account = user_load($entity->uid);
  $json[] = mediacommons_solr_user_metadata($account);
  $document->addField('zs_contributors', json_encode($json));
}

/**
 * Comment node spoke
 */
function mediacommons_solr_apachesolr_index_document_build_comment_node_hub(&$document, $wrapper, $entity) {
  global $base_url;
  $document->addField('ss_periodstart', $entity->created);
  // Data needed: date comment was created, in this format:  Monday, October 23, 2017 — 7:46 pm
  // http://php.net/manual/en/function.date.php
  $document->addField('ss_createddate', date('l, F j, Y — g:i a', $entity->created));
  $document->addField('ss_cdyyyymmdd', date('Y-m-d', $entity->created));
  $document->addField('ss_pubdate', date('F d, Y', $entity->created));
  $document->addField('ds_pubdate', apachesolr_date_iso($entity->created));
  $document->addField('ds_pubdated', apachesolr_date_iso($entity->created));
  $document->addField('ds_pubdatea', apachesolr_date_iso($entity->created));
  $node = node_load($entity->nid);
  $referencedspoke = array(
    'cid' => $entity->cid,
    'nid' => $entity->nid,
    'label' => $node->title,
    'url' => $base_url . '/' . drupal_get_path_alias('node/' . $entity->nid),
  );
  $document->addField('ss_referencedspoke', json_encode($referencedspoke));
  unset($node);
  $json = array();
  $document->addField('im_contributors', $entity->uid);
  $document->addField('im_contributor', $entity->uid);
  $account = user_load($entity->uid);
  $json[] = mediacommons_solr_user_metadata($account);
  $document->addField('zs_contributors', json_encode($json));
}

/**
 * Comment node spoke
 */
function mediacommons_solr_apachesolr_index_document_build_comment_node_review(&$document, $wrapper, $entity) {
  global $base_url;
  $document->addField('ss_periodstart', $entity->created);
  // Data needed: date comment was created, in this format:  Monday, October 23, 2017 — 7:46 pm
  // http://php.net/manual/en/function.date.php
  $document->addField('ss_createddate', date('l, F j, Y — g:i a', $entity->created));
  $document->addField('ss_cdyyyymmdd', date('Y-m-d', $entity->created));
  $document->addField('ss_pubdate', date('F d, Y', $entity->created));
  $document->addField('ds_pubdate', apachesolr_date_iso($entity->created));
  $document->addField('ds_pubdated', apachesolr_date_iso($entity->created));
  $document->addField('ds_pubdatea', apachesolr_date_iso($entity->created));
  $node = node_load($entity->nid);
  $referencedspoke = array(
    'cid' => $entity->cid,
    'nid' => $entity->nid,
    'label' => $node->title,
    'url' => $base_url . '/' . drupal_get_path_alias('node/' . $entity->nid),
  );
  $document->addField('ss_referencedspoke', json_encode($referencedspoke));
  unset($node);
  $json = array();
  $document->addField('im_contributors', $entity->uid);
  $document->addField('im_contributor', $entity->uid);
  $account = user_load($entity->uid);
  $json[] = mediacommons_solr_user_metadata($account);
  $document->addField('zs_contributors', json_encode($json));
}

/**
 * User metadata
 */
function mediacommons_solr_user_metadata($entity) {
  $user = array();
  try {

    // User entity wrapper
    $uwrapper = entity_metadata_wrapper('user', $entity);

    // User id
    $uid = $uwrapper->getIdentifier();

    // Array to hold derivative image URL
    $picture = array();

    // Image
    if (!empty($entity->picture)) {
      foreach (image_styles() as $style) {
        $derivative_uri = image_style_path($style['name'], $entity->picture->uri);
        if (!file_exists($derivative_uri)) {
          $image = image_style_create_derivative($style, $entity->picture->uri, $derivative_uri);
          if ($image) {
	    $imageurl = file_create_url($derivative_uri);
          }
        }
        else {
          $imageurl = file_create_url($derivative_uri);
        }
        // Make sure we have a URL
        if (isset($imageurl)) {
          $picture[$style['name']] = $imageurl;
        }
      }
    }

    // Organization
    $field_organization = $uwrapper->field_organization->value();
    $organization = array();

    if ($field_organization) {
      $organization['tid'] = $field_organization->tid;
      $organization['vid'] = $field_organization->vid;
      $organization['name'] = $field_organization->name;
      $organization['vocabulary'] = $field_organization->vocabulary_machine_name;
      $organization['url'] = drupal_get_path_alias('taxonomy/term/' . $field_organization->tid);
    }

    $user['uid'] = $uid;

    $user['url'] = mediacommons_homepage_umbrella_url() . '/' . drupal_get_path_alias('user/' . $uid);

    $user['organization'] = $organization;

    $user['picture'] = $picture;

    if (isset($entity->realname)) {
      $user['name'] = $entity->realname;
    }
    else {
      $user['name'] = $entity->name;
    }

  }
  catch (EntityMetadataWrapperException $exc) {
    $args = array('%function' => __FUNCTION__, '@trace' => $exc->getTraceAsString());
    $string = 'EntityMetadataWrapper exception in %function() <pre>@trace</pre>';
    watchdog('mediacommons_solr', $string, $args, WATCHDOG_ERROR);
    if (function_exists('drush')) {
      drush_log(dt($string, $args), 'error');
    }
  }
  return $user;
}

