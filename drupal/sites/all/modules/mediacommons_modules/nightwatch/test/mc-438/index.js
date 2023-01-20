var conf = require('../../nightwatch.conf.js');

module.exports = {
  tags: ['MC-441'],
  '@disabled': true,
  
  'MC-438 - When I search for "daniel day-lewis" on IMR I should get result "Bastard from a Basket: Deafness in There Will Be Blood"' : function (client) {
    client
      .url('http://mediacommons.local/imr/search/site/%22daniel%20day-lewis%22')
      .saveScreenshot('MC-438-1.png')
      .waitForElementVisible('ul.mc-searchresults', 1000)
      .assert.elementPresent('li.search-result')
      .assert.containsText('li.search-result', "Bastard from a Basket: Deafness in There Will Be Blood")
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
