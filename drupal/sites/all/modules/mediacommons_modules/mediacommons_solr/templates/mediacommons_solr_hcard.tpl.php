<?php foreach ($peoplelist as $person) : ?>
  <div class="h-card">
    <?php if ($person->name) : ?>
      <span class="p-name name fn">
        <a href="<?php print url($person->url, array('absolute' => TRUE)) ?>" data-uid="<?php print $person->uid ?>"><?php print $person->name ?></a>
      </span>
    <?php endif; ?>
    <?php if ($person->organization) : ?>
      <span class="p-org"><a href="<?php print url($person->organization->url, array('absolute' => TRUE)) ?>" data-vocabulary="<?php print $person->organization->vocabulary ?>" data-tid="<?php print $person->organization->tid ?>" data-vid="<?php print $person->organization->vid ?>"><?php print $person->organization->name ?></a></span>      
    <?php endif; ?>
  </div>
<?php endforeach; ?>
