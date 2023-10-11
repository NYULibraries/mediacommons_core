<?php if ($search_results): ?>
  <h2 class="contribution-type"><?php print $title ?></h2>
  <div class ="search-header-group">
  <?php if (isset($description)): ?>
    <div class="locator-text">
      <?php print $description ?>
    </div>
  <?php endif; ?>
   <?php if (isset($solr_sort)): ?>
    <?php print $solr_sort ?>
  <?php endif; ?>
  </div>
  <ul class="mc-searchresults <?php print $module ?>-results">
    <?php print $search_results ?>
  </ul>
  <?php print $pager ?>
<?php else : ?>
  <h2><?php print t('Your search yielded no results') ?></h2>
  <?php print search_help('search#noresults', drupal_help_arg()) ?>
<?php endif; ?>
