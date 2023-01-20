<?php

/**
 * This is invoked by apachesolr_search.module for the whole resultset returned
 * in a search.
 *
 * @param array $results
 *   The returned search results.
 * @param DrupalSolrQueryInterface $query
 *   The query for which we want to process the results from
 */
function mediacommons_solr_apachesolr_process_results(array &$results, DrupalSolrQueryInterface $query) {
  foreach ($results as $id => $result) {
    $results[$id]['link'] = $results[$id]['fields']['url'];
    $results[$id]['project'] = $results[$id]['fields']['ss_project'];
    $results[$id]['project_url'] = $results[$id]['fields']['ss_baseurl'];
    $results[$id]['searchtype'] = $results[$id]['fields']['ss_searchtype'];
    $results[$id]['projectname'] = $results[$id]['fields']['ss_projectname'];
    $results[$id]['projectclass'] = $results[$id]['fields']['ss_projectclass'];
    $results[$id]['periodstart'] = $results[$id]['fields']['ss_periodstart'];
    $results[$id]['periodend'] = $results[$id]['fields']['ss_periodend'];
    $results[$id]['pubdate'] = $results[$id]['fields']['ss_pubdate'];
  }
}

/**
 * Process variables for search-result.tpl.php.
 * https://api.drupal.org/api/drupal/modules%21search%21search.pages.inc/function/template_preprocess_search_result/7.x
 */
function mediacommons_solr_preprocess_search_result(&$variables) {
  $result = $variables['result'];
  $bundle = $result['bundle'];
  $variables['theme_hook_suggestions'][] = 'mediacommons_solr_search_result__base';
  $variables['theme_hook_suggestions'][] = 'mediacommons_solr_search_result__' . $bundle;
  $variables['projectname'] = $result['projectname'];
  $variables['projectclass'] = $result['projectclass'];
  $variables['link'] = $result['link'];
  $variables['project'] = $result['project'];
  $variables['project_url'] = $result['project_url'];
  $variables['project_link'] = l ( $result['projectname'], $result['project_url'], array('external' => TRUE));
  $variables['searchtype'] = $result['searchtype'];
  // add project to class_array
  $variables['classes_array'][] = 'node-' . $result['projectclass'];
  // add bundle to class_array
  $variables['classes_array'][] = 'node-' . $bundle;
  $variables['classes_array'][] = $result['projectclass'];
  $call = 'mediacommons_solr_preprocess_search_result_' . $bundle;
  if (function_exists ($call)) {
    $call($variables);
  }
}

function mediacommons_solr_preprocess_search_result_review(&$variables) {
  $fields = $variables['result']['fields'];
  $referencedspoke = json_decode($fields['ss_referencedspoke']);
  // we don't render the "review" view
  // we render the "spoke" view
  // Umbrella won't be able to render external nodes. We need to find it using Solr
  $key = '*:*';
  $conditions = array(
    'fq' => array(
      'entity_id:' . $referencedspoke->nid,
      'ss_project:' . $variables['project'],
    ),
    'spellcheck' => 'false',
    'sort' => 'timestamp desc',
  );
  $spoke = mediacommons_solr_runsearch('*:*', $conditions);
  if (!empty($spoke)) {
    $spoke = array_pop($spoke);
    $variables['link'] = $spoke['link'];  
    $variables['url'] = $spoke['link'];  
    $variables['classes_array'][] = 'node-teaser';
    $variables['classes_array'][] = 'view-mode-teaser';
    $spoke_fields = (object)$spoke['fields'];
    $variables['title'] = $spoke['title'];
    $variables['snippet'] = $spoke['snippet'];
    // Representative Image
    $variables['ri'] = json_decode($spoke_fields->zs_ri);
    // Period start
    $variables['created_date'] = $spoke_fields->ss_createddate;
    $variables['comment_count'] = $spoke_fields->is_comment_count;
    // contributors
    $peoplelist = array(
      'peoplelist' => json_decode($spoke_fields->zs_contributors)
    );    
    $variables['peoplelist'] = theme('mediacommons_solr_hcard', $peoplelist);    
    // reviewers
    if (isset($spoke_fields->zs_reviewers)) {
      $reviewerlist = json_decode($spoke_fields->zs_reviewers);
      if (!empty($reviewerlist)) {
       $variables['reviewby'] = theme('mediacommons_solr_hcard', array('peoplelist' => $reviewerlist));
      }
    }
  }
}

function mediacommons_solr_preprocess_search_result_comment_node_spoke(&$variables) {
  $fields = $variables['result']['fields'];
  $referencedspoke = json_decode($fields['ss_referencedspoke']);
  $variables['classes_array'][] = 'clearfix';
  $variables['classes_array'][] = 'node-comment';
  $variables['classes_array'][] = 'node-' . $fields['ss_projectclass'];
  $variables['created_date'] = $fields['ss_createddate'];
  $variables['referencedspoke'] = json_decode($fields['ss_referencedspoke']);
  // contributors
  $peoplelist = array(
    'peoplelist' => json_decode($fields['zs_contributors'])
  );
  $variables['peoplelist'] = theme('mediacommons_solr_hcard', $peoplelist);
}

function mediacommons_solr_preprocess_search_result_spoke(&$variables) {
  $node = $variables['result']['node'];
  $variables['classes_array'][] = 'node-teaser';
  $variables['classes_array'][] = 'view-mode-teaser';
  // Representative Image
  $variables['ri'] = json_decode($node->zs_ri);
  // Period start
  $variables['created_date'] = $node->ss_createddate;
  $variables['comment_count'] = $node->ss_comment_count;
  // contributors
  $peoplelist = array(
    'peoplelist' => json_decode($node->zs_contributors)
  );
  // reviewers
  if (isset($node->zs_reviewers)) {
     $reviewerlist = json_decode($node->zs_reviewers);
     if (!empty($reviewerlist)) {
       $variables['reviewlist'] = theme('mediacommons_solr_hcard', array('peoplelist' => $reviewerlist));
    }
  }
  $variables['peoplelist'] = theme('mediacommons_solr_hcard', $peoplelist);
}

function mediacommons_solr_preprocess_search_result_hub(&$variables) {
  $node = $variables['result']['node'];
  $variables['classes_array'][] = 'clearfix';
  // $variables['classes_array'][] = 'node-teaser'; this breaks the style
  // Representative Image
  $variables['ri'] = json_decode($node->zs_ri);
  // Period start
  $variables['created_date'] = $node->ss_createddate;
  $variables['cd_yyyy_mm_dd'] = $node->ss_cdyyyymmdd;
  // Period end
  $variables['end_date'] = $node->ss_enddate;
  $variables['ed_yyyy_mm_dd'] = $node->ss_edyyyymmdd;  
  /**
   * Curated by:
   * Data needed: All of the curators to a hub, and the links to their
   * profile pages, and their organization, and the link to the org page
   * @theme_file: templates/mediacommons_solr_hcard.tpl.php
   */
  $peoplelist = array(
    'peoplelist' => json_decode($node->zs_curatorseditors)
  );
  $variables['peoplelist'] = theme('mediacommons_solr_hcard', $peoplelist);
}

function mediacommons_solr_preprocess_search_results(&$variables) {
  $variables['theme_hook_suggestions'][] = 'mediacommons_solr_search_results';
  // https://jira.nyu.edu/jira/browse/MC-382
  if (is_array($variables['search_page']) && $variables['search_page']['page_id'] == 'core_search') {
    $block = module_invoke('mediacommons_blocks', 'block_view', 'mediacommons_solr_sort');
    $variables['solr_sort'] = render($block['content']);
  }
}
