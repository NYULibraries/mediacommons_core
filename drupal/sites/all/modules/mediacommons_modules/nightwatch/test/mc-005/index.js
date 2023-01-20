'use strict'

const conf = require('../../nightwatch.conf.js')
const { join } = require('path')
const testId = 'mc-005'
const disabled = true
const url = process.env.BASEURL
const project = 'fieldguide'
const userAdminId = process.env.USERADMINID
const userAdminPass = process.env.USERADMINPASS

module.exports = {
  tags: [testId],
  '@disabled': disabled,

  before: function (client) {
    client.url(`${url}/user?destination=admin/structure/types&project=${project}&hail=${project}`)
    client.waitForElementPresent('form#user-login', 1000)
    client.setValue('input#edit-name', userAdminId)
    client.setValue('input#edit-pass', userAdminPass)
    client.submitForm('#user-login')
    client.waitForElementVisible('body', 1000)
  },  

  after: function (client) {    
    client.url(`${url}/user/logout`).end()
  },

  'Content type "Page" available': function (client) {
    client.assert.elementPresent(`a[href="/${project}/admin/structure/types/manage/page"]`)
  },

  'Content type "Hub" available': function (client) {
    client.assert.elementPresent(`a[href="/${project}/admin/structure/types/manage/hub"]`)
  },
  
  'Content type "Review" available': function (client) {
    client.assert.elementPresent(`a[href="/${project}/admin/structure/types/manage/review"]`)
  },

  'Content type "Spoke" available': function (client) {
    client.assert.elementPresent(`a[href="/${project}/admin/structure/types/manage/spoke"]`)
  },

  'Finished': function (client) {
    client.perform(() => {
      console.log('[perform]: Finished Test:', client.currentTest.name)
    })
  }

}
