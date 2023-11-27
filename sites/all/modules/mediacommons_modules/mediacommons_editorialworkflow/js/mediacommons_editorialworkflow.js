(function($) {
  Drupal.behaviors.mediacommons_editorialworkflow = {
    attach: function (context, settings) {
      if (settings.mediacommons_editorialworkflow) {
        if (settings.mediacommons_editorialworkflow.isAdminPage) {
          if (settings.mediacommons_editorialworkflow.redirect.trigger) {
            setInterval(function() {
              var node = $(context).find('#console .redirect');
              var count = parseInt(node.text(), 10) - 1;
              if (count => 0) {
                node.text(count);
              }
              if (count === 0) {
                window.location.replace(settings.mediacommons_editorialworkflow.redirect.path);
              }
            }, 995);
          }
          //setTimeout(function() {
          //  $(context).find('#console').hide();
          //}, 6000);
        }
      }
    }
  }
})(jQuery);
