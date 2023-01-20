// https://github.com/nightwatchjs/nightwatch/wiki/Understanding-the-Command-Queue

const conf = require('../../nightwatch.conf.js')
const buildUrl = require('../../commands/buildUrl.js')
const { randomBytes } = require('crypto')
const request = require('request')
const _ = require('lodash')
const url = require('url')
const testId = 'mc-013'
const disabled = true
const baseurl = process.env.BASEURL
const userAdminId = process.env.USERADMINID
const userAdminPass = process.env.USERADMINPASS

/**
 * Hub Editor
 * has the ability to edit spokes in those hubs
 */

module.exports = {
  tags: [testId],
  '@disabled': disabled,

  'As Hub Editor I can edit/delete hubs for which I am listed as the editor': function (client) {

    const name = `hubeditor${randomBytes(10).toString('hex')}`
    const pass = `hubeditor${randomBytes(10).toString('hex')}`
    const mail = `${name}@dlib.nyu.edu`

    /**
     * Log-in as super user
     */
    client.logIn(userAdminId, userAdminPass)
    /**
     * Populate new user form
     */
    client.newUser({
      name: name,
      mail: mail,
      pass: pass,
      roles: [ 'cluster curator' ],
    }, {
      destination: `users/${name}/user.json`
    })
    /**
     * Get the new user information
     */
    client.getText('pre', function (result) {
      const data = JSON.parse(result.value)
      const label = `${testId} - Test - Hub - ${data.name}`
      /**
       * Create a dummy Hub node
       */
      client.url(buildUrl({path: 'node/add/hub'}))
      client.waitForElementVisible('body', 1000)
      // for autocomplete fields to work, they need to 
      // be populated before other fields
      client.setValue('input#edit-field-co-editor-und-0-uid', data.name)
      client.setValue('input#edit-title', label)
      client.submitForm('form#hub-node-form')      
      client.waitForElementVisible('body', 1000)

      client.url(function (result) {
        const parsedHubUrl = url.parse(result.value)
        const editHubUrl = `${parsedHubUrl.pathname.substr(1)}/edit`
        /**
         * Log-out the super user
         */
        client.logOut()
        /**
         * Log-in as the newly created managing editor user
         */
        client.logIn(name, pass, { path: 'user', destination: editHubUrl })
        /**
         * Test if new user has access to edit this node
         */
        client.assert.containsText('h1.page-title', `Edit Hub ${label}`)
        /**
         * Test editing the node
         */
        client.editNode()
        /**
         * Return to edit page
         */
        client.url(buildUrl({path: editHubUrl}))

        client.waitForElementVisible('body', 1000)
        /**
         * Test deliting the node
         */
        client.deleteNode()
        /**
         * Log-out
         */
        client.logOut()
      })
    })
  }
}
