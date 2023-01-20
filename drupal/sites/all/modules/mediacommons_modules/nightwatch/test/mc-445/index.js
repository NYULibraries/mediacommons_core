var conf = require('../../nightwatch.conf.js');

module.exports = {
  tags: ['MC-441'],
  '@disabled': true,

  'MC-445 - Navigating to "profile" from MC dashboard leads to blank page' : function (client) {
    // I need to fix this test. Leave it as-is for now
    return;
    client
      .url('http://mediacommons.local/fieldguide/search/site/art')
      .waitForElementVisible('body', 1000)
      .elements('.mc-searchresults', function (result) {  
       })
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
