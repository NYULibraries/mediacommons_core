;
(function($) {
  function setUpLoginLink() {
    $('.utils a.login-link').unbind('click').click(function(e) {
      if (!e) {
        e = window.event;
      }
      e.preventDefault();
      if ($(this).next('ul').is(":visible")) {
        $('.utils a.login-link').removeClass("open");
        $('.utils ul').slideUp(300,
          function() {
            $('.utils ul[aria-hidden="false"]').attr('aria-hidden', 'true').removeAttr("style");
          });
      } else {
        $('.utils a.login-link').addClass("open");
        $('.utils ul').slideDown(300,
          function() {
            $('.utils ul[aria-hidden="true"]').attr('aria-hidden', 'false').removeAttr("style");
          });
      }
    });
  }

  function setUpNavLink() {
    // Global nav - Login - global behavior
    var w = $(window).width();
    if (w > 800) {
      $('.sites_nav ul[aria-hidden="true"]').attr('aria-hidden', 'false');
       $('.sites_nav ul').removeAttr("style");
      $('.sites_nav a.logolink').unbind("click");
    } else {
      $('.sites_nav').addClass("closed");
      $('.sites_nav ul').attr('aria-hidden', 'true');
      $('.sites_nav ul').css('display', 'none');
      $('.sites_nav a.logolink').unbind('click').click(function(e) {
        if (!e) {
          e = window.event;
        }
        e.preventDefault();
        if ($(this).next('ul').is(":visible")) {
          $('.sites_nav a.logolink').removeClass("open");
          $('.sites_nav ul').slideUp(300,
            function() {
              $('.sites_nav ul[aria-hidden="false"]').attr('aria-hidden', 'true');
              $('.sites_nav').removeClass("open").addClass("closed");
            });
        } else {
          $('.sites_nav a.logolink').addClass("open");
          $('.sites_nav').removeClass("closed").addClass("open");
          $('.sites_nav ul').slideDown(300,
            function() {
              $('.sites_nav ul[aria-hidden="true"]').attr('aria-hidden', 'false');
            });
        }
      });
    }
  }

  function closeTopTwo() {
    $('.sites_nav ul[aria-hidden="false"]').attr('aria-hidden', 'true').removeAttr("style");
    $('.utils ul[aria-hidden="false"]').attr('aria-hidden', 'true').removeAttr("style");
  }

  function setUpProjectNavMobile() {
    $("ul.main").attr('aria-hidden', 'true');
    $('header.banner [role=search] fieldset').removeAttr('style');
    $('header.banner [role=search] label').unbind('click').click(function() {
      $theSearchButton = $(this);
      // If search is open
      if ($("header.banner [role=search] fieldset").is(":visible")) {
        $("header.banner [role=search] fieldset").slideUp(300, 'easeInQuad',
          function() {
            $(this).parent('form').removeClass("open");
          });
      } else {
        // if search is closed
        closeTopTwo();
        // if main is already open, first close it 
        if ($('nav.main ul').is(":visible")) {
          $('nav.main ul').slideUp(300, 'easeInQuad', function() {
            $('header.banner [role=search] form').addClass("open");
            $('header.banner [role=search] fieldset').slideDown(300, 'easeInQuad',
              function() {
                $(this).parent('form').addClass("open");
              });
          });
        } else {
          // if main is closed
          $('header.banner [role=search] form').addClass("open");
          $('header.banner [role=search]  fieldset').slideDown(300, 'easeOutQuad');
        }
      }
    });
    // Main project nav
    if ($(".nav.main>ul").length) {
      $("header.banner button").unbind('click').click(function() {
        var $theMenuButton = this;
        if ($("nav.main ul").is(":visible")) {
          $('nav.main ul').slideUp(300, 'easeInQuad', function() {
            $("header.banner button").removeClass("open");
          });
        } else {
          closeTopTwo();
          if ($("header.banner form[role=search] fieldset").is(":visible")) {
            $('header.banner form[role=search] fieldset').slideUp(300, 'easeInQuad', function() {
              $('nav.main ul').slideDown(300, 'easeInQuad', function() {
                $('header.banner form[role=search]').removeClass("open");
                $("header.banner button").addClass("open");
                $('nav.main ul').attr('aria-hidden', 'false');
              });
            });
          } else {
            $('nav.main ul').slideDown(300, 'easeInQuad');
          }
        }
      });

    } else {
      $("header.banner button").remove();
    }
  }

  $(window).resize(_.debounce(function() {
    // executed when the DOM is ready
    setUpNavLink();
    setUpProjectNavMobile();
  }, 200));
  
  setUpLoginLink();
  setUpNavLink();
  setUpProjectNavMobile();

})(jQuery);