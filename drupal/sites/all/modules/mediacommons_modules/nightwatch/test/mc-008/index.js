'use strict'

const conf = require('../../nightwatch.conf.js')
const testId = 'mc-008'
const disabled = true
const url = process.env.BASEURL
const userAdminId = process.env.USERADMINID
const userAdminPass = process.env.USERADMINPASS

module.exports = {
  tags: [testId],
  '@disabled': disabled,

  'As Administrator I should be able to manage users': function (client) {
    client.url(`${url}/user?destination=admin/people`)
    client.waitForElementPresent('form#user-login', 1000)
    client.setValue('input#edit-name', userAdminId)
    client.setValue('input#edit-pass', userAdminPass)
    client.submitForm('#user-login')
    client.waitForElementVisible('body', 1000)
    client.saveScreenshot(`${testId}-01.png`)
    client.url(`${url}/user/logout`)
    client.end()
  },

  'As Administrator I should be able to create/delete users': function (client) {
    const crypto = require('crypto')
    let newUserId = crypto.randomBytes(10).toString('hex')
    let newUserPass = crypto.randomBytes(10).toString('hex')    
    // log in as administrator
    client.url(`${url}/user?destination=admin/people/create`)
    client.waitForElementPresent('form#user-login', 1000)
    client.setValue('input#edit-name', userAdminId)
    client.setValue('input#edit-pass', userAdminPass)
    client.submitForm('#user-login')
    client.waitForElementVisible('body', 1000)
    client.saveScreenshot(`${testId}-02-01.png`)
    // populate new user form
    client.setValue('input#edit-name', newUserId)
    client.setValue('input[name="mail"]', `${newUserId}@dlib.nyu.edu`)
    client.setValue('input#edit-pass-pass1', newUserPass)
    client.setValue('input#edit-pass-pass2', newUserPass)
    client.submitForm('#edit-submit')
    // test if the new user was created
    client.waitForElementVisible('body', 1000)
    client.assert.containsText('.messages.status', `Created a new user account for ${newUserId}.`)
    client.saveScreenshot(`${testId}-02-02.png`)
    // browse to the user page
    client.url(`${url}/users/${newUserId}`)
    client.waitForElementVisible('body', 1000)
    client.saveScreenshot(`${testId}-02-03.png`)
    // click edit user link
    client.waitForElementPresent('.tabs-primary__tab:nth-child(2) a', 5000)
    client.click('.tabs-primary__tab:nth-child(2) a')
    client.saveScreenshot(`${testId}-02-04.png`)
    // click Cancel account button
    client.click('#edit-cancel')
    // delete new user
    client.click('#edit-user-cancel-method--5')
    client.saveScreenshot(`${testId}-02-05.png`)
    client.click('#edit-submit')
    client.waitForElementVisible('body', 5000)
    client.assert.containsText('.messages.status', `${newUserId} has been deleted.`)
    client.saveScreenshot(`${testId}-02-06.png`)
    // log out
    client.url(`${url}/user/logout`)
    client.end()
  },

  'Finished': function (client) {
    client.perform(() => {
      console.log('[perform]: Finished Test:', client.currentTest.name)
    }).end()
  }

}
