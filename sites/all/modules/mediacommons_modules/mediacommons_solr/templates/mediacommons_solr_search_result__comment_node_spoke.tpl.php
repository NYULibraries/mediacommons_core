<li class="<?php print $classes ?> ">
  <div class="field-name-field-project">
    <?php print $project_link ?>
  </div>
  <div class="comment">
    <div class="referenced-node">
      <span class="views-label">Re: </span>
      <a href="<?php print $referencedspoke->url ?>" data-nid="<?php print $referencedspoke->nid ?>">
        <?php print $referencedspoke->label ?>
      </a>
    </div>
    <h3 class="comment__title comment-title">
      <a href="<?php print $url ?>" class="permalink">
        <?php print $title; ?>
      </a>
    </h3>
    <div class="peoplelist contributors">
      <span>By</span>
      <?php print $peoplelist ?>
    </div>
    <time>
      <?php print $created_date ?>
    </time>
    <div class="comment-body">
      <?php print $snippet; ?>
    </div>
  </div>
</li>