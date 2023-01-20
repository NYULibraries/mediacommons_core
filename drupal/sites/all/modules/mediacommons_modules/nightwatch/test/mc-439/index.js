var conf = require('../../nightwatch.conf.js');

module.exports = {
  tags: ['MC-441'],
  '@disabled': true,
  
  'MC-439 - If I serch inTransition for "dolores tierney" I expect to see search results' : function (client) {
    client
      .url('http://mediacommons.local/intransition/search/site/%2522dolores%2520tierney%2522')
      .saveScreenshot('MC-439-1.png')
      .waitForElementVisible('ul.mc-searchresults', 1000)
      .assert.elementPresent('li.search-result')
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
