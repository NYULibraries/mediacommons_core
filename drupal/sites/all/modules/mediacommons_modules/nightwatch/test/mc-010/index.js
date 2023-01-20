'use strict'

const crypto = require('crypto')
const url = require('url')
const conf = require('../../nightwatch.conf.js')
const testId = 'mc-010'
const disabled = true
const baseurl = process.env.BASEURL
const userAdminId = process.env.USERADMINID
const userAdminPass = process.env.USERADMINPASS

module.exports = {
  tags: [testId],
  '@disabled': disabled,

  'As Managing Editor I should be able to edit/delete any Hub': function (client) {
    const newUserId = `managingeditor${crypto.randomBytes(10).toString('hex')}`
    const newUserPass = crypto.randomBytes(10).toString('hex')
    const label = `${testId} - Test - ${newUserId}`
    /**
     * Log-in as super user
     */
    client.url(`${baseurl}/user?destination=admin/people/create`)
    client.waitForElementPresent('form#user-login', 1000)
    client.setValue('input#edit-name', userAdminId)
    client.setValue('input#edit-pass', userAdminPass)
    client.submitForm('#user-login')
    client.waitForElementVisible('body', 1000)
    /**
     * Populate new user form
     */
    client.setValue('input#edit-name', newUserId)
    client.setValue('input[name="mail"]', `${newUserId}@dlib.nyu.edu`)
    client.setValue('input#edit-pass-pass1', newUserPass)
    client.setValue('input#edit-pass-pass2', newUserPass)    
    client.assert.containsText('label[for="edit-roles-6"]', 'managing editor')
    client.click('input#edit-roles-6')
    client.submitForm('#edit-submit')
    /**
     * Test if the new user was created
     */
    client.waitForElementVisible('body', 1000)
    client.assert.containsText('.messages.status', `Created a new user account for ${newUserId}.`)
    /**
     * Create a dummy Hub node
     */
    client.url(`${baseurl}/node/add/hub?destination=admin/content`)
    client.waitForElementPresent('body', 1000)
    client.setValue('input#edit-title', label)    
    client.submitForm('form#hub-node-form')
    /**
     * Check the new node was created
     */
    client.waitForElementPresent('body', 1000)
    client.assert.containsText('.views-table tr:nth-child(2) td:nth-child(2) a', label)
    /**
     * Find the edit node link
     */
    client.element('css selector', '.views-table tr:nth-child(2) td:nth-child(7) a', function (result) {
      client.elementIdAttribute(result.value.ELEMENT, 'href', function (link) {
        const testNodeURL = url.parse(link.value)
        const destination = testNodeURL.pathname.substring(1)
        let i = 0
        /**
         * Log-out the super user
         */ 
        client.url(`${baseurl}/user/logout`)
        /**
         * Log-in as the newly created managing editor user
         */
        client.url(`${baseurl}/user?destination=${destination}`)
        client.waitForElementPresent('form#user-login', 1000)
        client.setValue('input#edit-name', newUserId)
        client.setValue('input#edit-pass', newUserPass)
        client.submitForm('#user-login')
        client.waitForElementVisible('body', 1000)
        /**
         * Test if new user has access to edit this node
         */        
        client.assert.containsText('h1.page-title', `Edit Hub ${label}`)
        /**
         * Test if new user has access to delete node
         */
        client.click('#edit-delete')
        client.waitForElementVisible('#edit-submit', 1000)
        client.click('#edit-submit')
        client.assert.containsText('.status', `Hub ${label} has been deleted.`)
        /**
         * Log-out the newly created managing editor user
         */
        client.url(`${baseurl}/user/logout`)
        /**
         * Log-in as super user
         */
        client.url(`${baseurl}/user`)
        client.waitForElementPresent('form#user-login', 1000)
        client.setValue('input#edit-name', userAdminId)
        client.setValue('input#edit-pass', userAdminPass)
        client.submitForm('#user-login')
        client.waitForElementVisible('body', 1000)
        /**
         * Browse to the managing editor user page
         */
        client.url(`${baseurl}/users/${newUserId}`)
        client.waitForElementVisible('body', 1000)
        /**
         * Click edit user link
         */        
        client.waitForElementPresent('.tabs-primary__tab:nth-child(2) a', 1000)
        client.click('.tabs-primary__tab:nth-child(2) a')
        /**
         * Click Cancel account button
         */
        client.click('#edit-cancel')
        /**
         * Delete new user
         */
        client.click('#edit-user-cancel-method--5')
        client.click('#edit-submit')
        client.waitForElementVisible('body', 1000)
        client.assert.containsText('.messages.status', `${newUserId} has been deleted.`)
        /**
         * Log-out
         */
        client.url(`${baseurl}/user/logout`)
        client.end()
      })
    })
  },

  'Finished': function (client) {
    client.perform(() => {
      console.log('[perform]: Finished Test:', client.currentTest.name)
    }).end()
  }

}
