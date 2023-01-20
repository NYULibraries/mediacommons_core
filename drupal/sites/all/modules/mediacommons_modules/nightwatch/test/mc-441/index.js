/**
 * See: https://jira.nyu.edu/jira/browse/MC-441
 * Fix search problem: user profile, reviewer
 */
var conf = require('../../nightwatch.conf.js');

module.exports = {
  tags: ['MC-441'],
  '@disabled': true,

  "MC-441 - I should not see reviews in seach results" : function (client) {
    client
      .url('http://mediacommons.local/search/site/pirate')
      .waitForElementVisible('body', 1000)
      .assert.elementNotPresent('.node-review')
      .end();      
  },

  'MC-441 - Nodes type "reviewer" should show up in user\'s profile page if exists':  function (client) {
    client
      .url('http://mediacommons.local/users/pirateclub1')
      .saveScreenshot('MC-441-1.png')
      .waitForElementVisible('div.field-name-as-reviewer', 1000)
      .assert.elementPresent('div.field-name-as-reviewer ul.mc-searchresults')
      .assert.elementPresent('div.field-name-as-reviewer ul.mc-searchresults li')
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
