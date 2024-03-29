<?php
/**
 * @file
 * Returns the HTML for the basic html structure of a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728208
 */
?><!DOCTYPE html>
<!--[if IEMobile 7]><html class="iem7" <?php print $html_attributes; ?>><![endif]-->
<!--[if lte IE 6]><html class="lt-ie9 lt-ie8 lt-ie7" <?php print $html_attributes; ?>><![endif]-->
<!--[if (IE 7)&(!IEMobile)]><html class="lt-ie9 lt-ie8" <?php print $html_attributes; ?>><![endif]-->
<!--[if IE 8]><html class="lt-ie9" <?php print $html_attributes; ?>><![endif]-->
<!--[if (gte IE 9)|(gt IEMobile 7)]><!--><html <?php print $html_attributes . $rdf_namespaces; ?>><!--<![endif]-->
<head>
    <?php
    switch ($special_body_class):

    // https://jira.nyu.edu/browse/MC-587
    case "alt": ?>
      <!-- Google tag (gtag.js) -->
      <script async src="https://www.googletagmanager.com/gtag/js?id=G-MDN2P2CESM"></script>
      <script>
        window.dataLayer = window.dataLayer || [];
        function gtag(){dataLayer.push(arguments);}
        gtag('js', new Date());
        gtag('config', 'G-MDN2P2CESM');
      </script>
    <?php break;

    // https://jira.nyu.edu/browse/MC-588
    case "imr": ?>
      <!-- Google tag (gtag.js) -->
      <script async src="https://www.googletagmanager.com/gtag/js?id=G-620Z0BY5J7"></script>
      <script>
        window.dataLayer = window.dataLayer || [];
        function gtag(){dataLayer.push(arguments);}
        gtag('js', new Date());
        gtag('config', 'G-620Z0BY5J7');
      </script>
    <?php
    break;

    // https://jira.nyu.edu/browse/MC-589
    case "int":  ?>
       <!-- Google tag (gtag.js) -->
       <script async src="https://www.googletagmanager.com/gtag/js?id=G-NCE9W08B82"></script>
       <script>
         window.dataLayer = window.dataLayer || [];
         function gtag(){dataLayer.push(arguments);}
         gtag('js', new Date());

         gtag('config', 'G-NCE9W08B82');
       </script>
     <?php
    break;

    // https://jira.nyu.edu/browse/MC-591
    case "mc": ?>
      <!-- Google tag (gtag.js) -->
      <script async src="https://www.googletagmanager.com/gtag/js?id=G-YRX14WBRQ8"></script>
      <script>
        window.dataLayer = window.dataLayer || [];
        function gtag(){dataLayer.push(arguments);}
        gtag('js', new Date());
        gtag('config', 'G-YRX14WBRQ8');
      </script>
     <?php
    break;

    // https://jira.nyu.edu/browse/MC-593
    case "tne": ?>
      <!-- Google tag (gtag.js) -->
      <script async src="https://www.googletagmanager.com/gtag/js?id=G-733X060GBL"></script>
      <script>
        window.dataLayer = window.dataLayer || [];
        function gtag(){dataLayer.push(arguments);}
        gtag('js', new Date());
        gtag('config', 'G-733X060GBL');
      </script>
    <?php
    break;

    // https://jira.nyu.edu/browse/MC-590
    case "fieldguide": ?>
        <!-- Global site tag (gtag.js) - Google Analytics -->
        <script async src="https://www.googletagmanager.com/gtag/js?id=UA-30270469-7"></script>
        <script>
        window.dataLayer = window.dataLayer || [];
        function gtag(){dataLayer.push(arguments);}
        gtag('js', new Date());

        gtag('config', 'UA-30270469-7', { 'anonymize_ip': true });
        </script>

    <?php endswitch; ?>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php if ($default_mobile_metatags): ?>
    <meta name="MobileOptimized" content="width">
    <meta name="HandheldFriendly" content="true">
    <meta name="viewport" content="width=device-width, initial-scale=1">
  <?php endif; ?>
  <link rel="shortcut icon" href="<?php print base_path() . path_to_theme(); ?>/favicon.ico" type="image/x-icon" />
 <meta http-equiv="cleartype" content="on">
  <?php print $styles; ?>
  <?php if ($add_html5_shim and !$add_respond_js): ?>
    <!--[if lt IE 9]>
    <script src="<?php print $base_path . $path_to_zen; ?>/js/html5.js"></script>
    <![endif]-->
  <?php elseif ($add_html5_shim and $add_respond_js): ?>
    <!--[if lt IE 9]>
    <script src="<?php print $base_path . $path_to_zen; ?>/js/html5-respond.js"></script>
    <![endif]-->
  <?php elseif ($add_respond_js): ?>
    <!--[if lt IE 9]>
    <script src="<?php print $base_path . $path_to_zen; ?>/js/respond.js"></script>
    <![endif]-->
  <?php endif; ?>
    <script type="text/javascript">
      WebFontConfig = {
        google: { families: [ 'Open+Sans:300,400,700:latin',
          'Droid+Sans:400,700:latin'] }
      };
      (function() {
        var wf = document.createElement('script');
        wf.src = ('https:' == document.location.protocol ? 'https' : 'http') +
          '://ajax.googleapis.com/ajax/libs/webfont/1/webfont.js';
        wf.type = 'text/javascript';
        wf.async = 'true';
        var s = document.getElementsByTagName('script')[0];
        s.parentNode.insertBefore(wf, s);
      })();
    </script>

</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php if ($skip_link_text && $skip_link_anchor): ?>
    <a id="skip-link" href="#<?php print $skip_link_anchor; ?>" class="element-invisible element-focusable"><?php print $skip_link_text; ?></a>
  <?php endif; ?>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $scripts; ?>
  <?php print $page_bottom; ?>
</body>
</html>
