var conf = require('../../nightwatch.conf.js');

module.exports = {
  tags: ['mc-490'],
  '@disabled': true,

  "MC-490 - HTML filter should be more flexible" : function (client) {
    client
      .url('http://mediacommons.local/user/logout')
      .url('http://mediacommons.local/user?destination=node/add/spoke')
      .waitForElementVisible('body', 1000)
      .waitForElementPresent('form#user-login', 1000)
      .setValue('input#edit-name', 'dlts.pa')
      .setValue('input#edit-pass', '000000')
      .saveScreenshot('mc-490-01.png')
      .submitForm('#user-login')
      .waitForElementVisible('body', 1000)
      .saveScreenshot('mc-490-02.png')
      .waitForElementPresent('body', 1000)
      .setValue('input#edit-title', 'MC-490 - Test')
      .setValue('textarea#edit-field-embed-und-0-value', '<p><i>MC-490</i> - Test - <br/><ol><li>LIST</li></ol><img id="mc_490_image_test" src="http://dlib.nyu.edu/aco/images/logos/nyu_short_color.png"></p>')
      .saveScreenshot('mc-490-03.png')
      .submitForm('form#spoke-node-form')
      .saveScreenshot('mc-490-04.png')
      .waitForElementPresent('body', 1000)
      .assert.elementPresent('#mc_490_image_test')
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
