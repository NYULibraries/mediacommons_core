<li class="<?php print $classes ?>" <?php print $attributes ?>
  >
  <div class="field-name-field-project">
    <?php print $project_link ?>
  </div>
  <div class="thumb">
    <a role="presentation" tabindex="-1"  href="<?php print $url ?>">
      <!-- $ri holds URL for all available styles defined by Drupal's image styles -->
      <img typeof="foaf:Image" src="<?php print $ri->thumbnail__120x80_ ?>" width="120" height="80" alt="">
    </a>
  </div>
  <div class="node-meta">
    <h3 class="hub-title node-title" <?php print $title_attributes; ?>>
      <a href="<?php print $url; ?>">
        <span class="content-type"></span>
        <?php print $title ?>
      </a>
    </h3>
    <time datetime="<?php print $cd_yyyy_mm_dd; ?>">
      <span class="date-display-range">
        <span class="date-display-start" property="dc:date" datatype="xsd:dateTime" content="<?php print $cd_yyyy_mm_dd ?>">
          <?php print $created_date ?>
        </span>
        <span>to</span>
        <span class="date-display-end" property="dc:date" datatype="xsd:dateTime" content="<?php print $ed_yyyy_mm_dd ?>">
          <?php print $end_date ?>
        </span>
      </span>
    </time>
    <?php
     if (isset($peoplelist) && (!empty($peoplelist))) : ?>
      <div class="peoplelist curator">
        <span class="curatorlabel"></span>
        <?php print $peoplelist ?>
      </div>
      <?php endif; ?>
</li>