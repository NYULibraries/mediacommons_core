<?php

/*
* Reviews Search Result Item Template
*
*  This is used by profile pages, not by search results
*  For search results, the spoke template -
*  mediacommons_solr_search_result__spoke.tpl.php
*  is used instead
*/

?>
<li class="<?php print $classes ?>"<?php print $attributes ?>>
  <div class="field field-name-field-project">
    <?php print $project_link ?>
  </div>
  <div class="thumb">
    <?php if (!empty($ri)) : ?>
    <a role="presentation" tabindex="-1" href="<?php print $url ?>">
      <img typeof="foaf:Image" src="<?php print $ri->thumbnail__120x80_ ?>" width="120" height="80" alt="">
    </a>
    <?php endif; ?>
  </div>
  <div class="spoke-teaser-meta node-meta">
    <h3 class="spoke-title node-title"<?php print $title_attributes ?>>
      <a href="<?php print $url ?>"><?php print $title ?></a>
    </h3>
    <div class="peoplelist contributors">
      <span>By</span> <?php print $peoplelist ?>
    </div>
    <time><?php print $created_date ?></time>
    <?php if ($comment_count): ?>
    <div class="comment-count">
      <a href="<?php print $url?>#comments" title="<?php print format_plural($comment_count, '1 comment', '@count comments') ?>">
        <?php print format_plural($comment_count, '1 comment', '@count comments') ?>
      </a>
    </div>
    <?php endif ?>
    <?php if (!empty($reviewby)) : ?>
    <div class="peoplelist reviewers">
      <span>Review by</span> <?php print $reviewby ?>
    </div>    
    <?php endif ?>
  </div>
</li>
