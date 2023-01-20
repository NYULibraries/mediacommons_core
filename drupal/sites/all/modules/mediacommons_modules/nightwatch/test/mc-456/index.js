var conf = require('../../nightwatch.conf.js');

module.exports = {
  tags: ['MC-441'],
  '@disabled': true,

  'MC-456 - Nodes type "reviewer" should show up in user\'s profile page if exists':  function (client) {
    client
      .url('http://mediacommons.local/users/pirateclub1')
      .saveScreenshot('MC-456-1.png')
      .waitForElementVisible('div.field-name-user-as-curator-editor', 1000)
      .assert.elementPresent('div.field-name-user-as-curator-editor ul.mc-searchresults')
      .assert.elementPresent('div.field-name-user-as-curator-editor ul.mc-searchresults li')
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
