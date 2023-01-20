MediaCommons Content Types
====================

### Files and changes we need to preserve 

This module add extra code to support the feature. If you need to update the feature, be aware of a
small change in the code inside the files:

```php
/**
 * @file
 * mediacommons_content_types.features.field_base.inc
 */
/**
 * Implements hook_field_default_field_bases().
 */
function mediacommons_content_types_field_default_field_bases() {
  // add this line
  $fid = variable_get('mediacommons_content_types_default_image_fid', NULL);

```

```php
/**
 * @file
 * mediacommons_content_types.features.field_instance.inc
 */
/**
 * Implements hook_field_default_field_instances().
 */
function mediacommons_content_types_field_default_field_instances() {
  // add this line
  $fid = variable_get('mediacommons_content_types_default_image_fid', NULL);
```

Search for **'default_image'** inside this two files **mediacommons_content_types.features.field_base.inc**, **mediacommons_content_types.features.field_instance.inc**. Replace the interger value to **$fid**

### Good example of the change manual change: 

- https://github.com/NYULibraries/mediacommons_modules/commit/d954de73665cae59f8a0886db95fa46197a1da18 

### See also e.g., 

```php
'settings' => array(
  'alt_field' => 1,
  'default_image' => $fid,
  'file_directory' => '',
  'file_extensions' => 'png gif jpg jpeg',
  'max_filesize' => '10 MB',
  'max_resolution' => '1200x640',
  'min_resolution' => '450x175',
  'title_field' => 1,
  'user_register_form' => FALSE,
),
```

NOTE: You do not need to make this change. File **mediacommons_content_types.install** takes care of creating a database record in Drupal's file managed table so that Drupal knows about this image. Unless drastical changes in the code base of the project, **transparent.png** will always have the image id 1 (fid = 1) and "recreating" the feature will assing the "correct" file id to the defaul image setting of the field base and instances.

See: https://github.com/NYULibraries/mediacommons_modules/commit/d954de73665cae59f8a0886db95fa46197a1da18#diff-eafe5972135c420a8a57f0a6066862f7L70

```php
  'default_image' => 1
```


