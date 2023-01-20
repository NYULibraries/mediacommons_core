var conf = require('../../nightwatch.conf.js');

module.exports = {
  tags: ['MC-441'],
  '@disabled': true,

  'MC-447 - Attempting to comment leads to page not found' : function (client) {
    client
      .url('http://mediacommons.local/imr/2007/12/13/citizens-media-in-southern-colombia')
      .saveScreenshot('1.png')
      .waitForElementVisible('#comments', 1000)
      .assert.containsText('#comments article .links li span a:first-child', 'Log in')
      .click('#comments article .links li span a:first-child')
      .assert.urlContains('/user?project=imr')
      .saveScreenshot('2.png')
      .waitForElementVisible('form#user-login', 1000)
      .setValue('input#edit-name', 'mc.contributor.1')
      .setValue('input#edit-pass', '000000')
      .saveScreenshot('3.png')
      .submitForm('#user-login')
      .waitForElementVisible('body', 1000)
      .saveScreenshot('4.png')
      .assert.urlContains('/imr/node/461')
      .assert.containsText('header.comments-add h2.comments__form-title', 'Add new comment')
      .end();
  },
  
  'MC-447 - Click username link in a serch result should take you that user profile' : function (client) {
      client
      .url('http://mediacommons.local/fieldguide/search/site/art')
      .waitForElementVisible('.mc-searchresults .search-result .peoplelist .p-name a', 1000)
      .click('.mc-searchresults .search-result .peoplelist .p-name a')
      .pause(1000)
      .assert.urlContains('/user/')
      .assert.containsText('h2.contribution-type', 'As contributor')
      .end();
  },
  
  'Finished': function (client) {
    client
      .url('http://mediacommons.local/user/logout')      
      .perform(() => {
        console.log('[perform]: Finished Test:', client.currentTest.name)
      })
      .end();
  }       

};
