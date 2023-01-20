var conf = require('../../nightwatch.conf.js');

module.exports = {
  tags: ['MC-441'],
  '@disabled': true,

  "MC-449 - I should see user profile page" : function (client) {
    client
      .url('http://mediacommons.local/user/1')
      .waitForElementVisible('body', 1000)
      .assert.urlContains('http://mediacommons.local/user/1')
      .end();
  },

  "MC-449 - I should be rediracted to Umbrella's user profile page" : function (client) {
    client
      .url('http://mediacommons.local/intransition/user/1')
      .waitForElementVisible('body', 1000)
      .saveScreenshot('MC-449-b-1.png')
      .assert.urlContains('http://mediacommons.local/user/1?project=intransition')
      .end();
  },

  "MC-449 - If I click on a user's name from a result on any channel, it should get me to the user's profile." : function (client) {
    client
      .url('http://mediacommons.local/intransition/')
      .waitForElementVisible('body', 1000)
      .saveScreenshot('MC-449-b-1.png')
      .assert.elementPresent('#edit-search-block-form--2')
      .setValue('#edit-search-block-form--2', 'art')
      .saveScreenshot('MC-449-2.png')
      .submitForm('#search-block-form')
      .waitForElementVisible('body', 1000)
      .saveScreenshot('MC-449-3.png')
      .waitForElementVisible('.mc-searchresults .search-result .peoplelist .p-name a', 1000)
      .click('.mc-searchresults .search-result .peoplelist .p-name a')
      .pause(1000)
      .assert.urlContains('/user/')
      .assert.containsText('h2.contribution-type', 'As contributor')
      .saveScreenshot('MC-449-4.png')
      .end();
  },

  'Finished': function (client) {
    client
      .perform(() => {
        console.log('[perform]: Finished Test:', client.currentTest.name)
      })
      .end();
  }       

};
