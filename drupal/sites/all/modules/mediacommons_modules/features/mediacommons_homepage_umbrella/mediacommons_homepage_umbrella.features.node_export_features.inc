<?php
/**
 * @file
 * mediacommons_homepage_umbrella.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function mediacommons_homepage_umbrella_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => NULL,
      \'ds_switch\' => \'\',
      \'field_body\' => array(),
      \'field_featured_image_thumb\' => array(),
      \'field_large_image\' => array(),
      \'field_project\' => array(
        \'und\' => array(
          array(
            \'value\' => \'imr\',
          ),
        ),
      ),
      \'field_rlink\' => array(
        \'und\' => array(
          array(
            \'url\' => \'http://devmc.dlib.nyu.edu/imr/theme-week/2015/46/james-bond-novmeber-9-13-2015\',
            \'title\' => \'Lipsum.Lipsum.:  Lipsum.Lipsum.\',
            \'attributes\' => array(),
          ),
        ),
      ),
      \'files\' => array(),
      \'language\' => \'und\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'0\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'dlts.pa\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'James Bond\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'type\' => \'front_page_post\',
      \'uid\' => \'1\',
      \'uuid\' => \'1ffee66c-a01a-41fa-bf98-d8a1ed87aed6\',
      \'vid\' => NULL,
      \'vuuid\' => \'a5261b26-63dc-404d-8802-e75759cf8108\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => NULL,
      \'ds_switch\' => \'\',
      \'field_body\' => array(),
      \'field_featured_image_thumb\' => array(),
      \'field_large_image\' => array(),
      \'field_project\' => array(
        \'und\' => array(
          array(
            \'value\' => \'imr\',
          ),
        ),
      ),
      \'field_rlink\' => array(
        \'und\' => array(
          array(
            \'url\' => \'http://devmc.dlib.nyu.edu/imr/theme-week/2015/42/coen-brothers-october-12-16-2015\',
            \'title\' => \'Coen Brothers\',
            \'attributes\' => array(),
          ),
        ),
      ),
      \'files\' => array(),
      \'language\' => \'und\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'0\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'dlts.pa\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'1\',
      \'title\' => \'Coen Brothers\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'type\' => \'front_page_post\',
      \'uid\' => \'1\',
      \'uuid\' => \'45b8a7f2-c68a-4fef-a0e4-1b87b3875cf9\',
      \'vid\' => NULL,
      \'vuuid\' => \'efc3e75c-66fe-4075-8d5f-eb40fee81fdf\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => NULL,
      \'ds_switch\' => \'\',
      \'field_body\' => array(),
      \'field_featured_image_thumb\' => array(),
      \'field_large_image\' => array(),
      \'field_project\' => array(
        \'und\' => array(
          array(
            \'value\' => \'tne\',
          ),
        ),
      ),
      \'field_rlink\' => array(
        \'und\' => array(
          array(
            \'url\' => \'http://devmc.dlib.nyu.edu/tne/cluster/seeing-being-seen-surveillance-columbia-sc\',
            \'title\' => \'Seeing Being Seen--Surveillance in Columbia, SC\',
            \'attributes\' => array(),
          ),
        ),
      ),
      \'files\' => array(),
      \'language\' => \'und\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'0\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'dlts.pa\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Seeing Being Seen--Surveillance in Columbia, SC\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'type\' => \'front_page_post\',
      \'uid\' => \'1\',
      \'uuid\' => \'7fd600a0-c844-434c-9cec-aefee50741f8\',
      \'vid\' => NULL,
      \'vuuid\' => \'c444fd2a-7b8a-44ba-a789-f2c72ab226a6\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => NULL,
      \'ds_switch\' => \'\',
      \'field_body\' => array(),
      \'field_featured_image_thumb\' => array(),
      \'field_large_image\' => array(),
      \'field_project\' => array(
        \'und\' => array(
          array(
            \'value\' => \'mcpress\',
          ),
        ),
      ),
      \'field_rlink\' => array(
        \'und\' => array(
          array(
            \'url\' => \'http://mcpress.media-commons.org/postmedieval_comicmedievalisms/\',
            \'title\' => \'Postmedieval Crowd Review Comic Medievalisms\',
            \'attributes\' => array(),
          ),
        ),
      ),
      \'files\' => array(),
      \'language\' => \'und\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'0\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'dlts.pa\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Postmedieval Crowd Review Comic Medievalisms\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'type\' => \'front_page_post\',
      \'uid\' => \'1\',
      \'uuid\' => \'8b2dd7e0-8a3a-40d1-b59f-bd3b9f3dca22\',
      \'vid\' => NULL,
      \'vuuid\' => \'64ec747b-b7f6-4dbd-bd8e-ce2f2647d1b7\',
    ),
  (object) array(
      \'changed\' => NULL,
      \'cid\' => \'0\',
      \'comment\' => \'2\',
      \'comment_count\' => \'0\',
      \'created\' => NULL,
      \'data\' => NULL,
      \'ds_switch\' => \'\',
      \'field_body\' => array(),
      \'field_featured_image_thumb\' => array(),
      \'field_large_image\' => array(),
      \'field_project\' => array(
        \'und\' => array(
          array(
            \'value\' => \'int\',
          ),
        ),
      ),
      \'field_rlink\' => array(
        \'und\' => array(
          array(
            \'url\' => \'http://devmc.dlib.nyu.edu/intransition/theme-week/2015/32/journal-videographic-film-moving-image-studies-23-2015\',
            \'title\' => \'Journal of Videographic Film & Moving Image Studies, 2.3, 2015\',
            \'attributes\' => array(),
          ),
        ),
      ),
      \'files\' => array(),
      \'language\' => \'und\',
      \'last_comment_name\' => NULL,
      \'last_comment_timestamp\' => NULL,
      \'last_comment_uid\' => \'0\',
      \'log\' => \'\',
      \'menu\' => NULL,
      \'name\' => \'dlts.pa\',
      \'nid\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'path\' => NULL,
      \'picture\' => \'0\',
      \'promote\' => \'1\',
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'revision_timestamp\' => NULL,
      \'revision_uid\' => \'1\',
      \'status\' => \'1\',
      \'sticky\' => \'0\',
      \'title\' => \'Journal of Videographic Film & Moving Image Studies, 2.3, 2015\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'type\' => \'front_page_post\',
      \'uid\' => \'1\',
      \'uuid\' => \'a00c37e8-dca5-4de1-8c00-f578f063b220\',
      \'vid\' => NULL,
      \'vuuid\' => \'b529bb69-8395-4c20-a7c8-834ecd1c0a56\',
    ),
)',
);
  return $node_export;
}
