var conf = require('../../nightwatch.conf.js');

module.exports = {
  tags: ['MC-441'],
  '@disabled': true,
  
  'MC-440 - When I search for "lacuna" I should get results' : function (client) {
    client
      .url('http://mediacommons.local/intransition/search/site/lacuna')
      .saveScreenshot('MC-440-1.png')
      .waitForElementVisible('ul.mc-searchresults', 1000)
      .assert.elementPresent('li.search-result')
      .end();
  },

  'MC-440 - Review content should be indexed' : function (browser) {
    const request = require('request');
    request('http://mediacommons.local:8983/solr/mediacommons/select?q=*%3A*&wt=json&indent=true&fq=bundle:review', function (error, response, body) {    
      browser.assert.equal(response.statusCode, 200);  
      const datasource = JSON.parse(body); 
      const numFound = parseInt(datasource.response.numFound, 10);
      browser.assert.equal((numFound > 0 ? true : false), true);
      browser.end();
    });
  },
 
  'Finished': function (client) {
    client
      .perform(() => {
        console.log('[perform]: Finished Test:', client.currentTest.name)
      })
      .end();
  }       

};
