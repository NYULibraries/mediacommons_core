'use strict'

const conf = require('../../nightwatch.conf.js')
const testId = 'mc-001'
const disabled = true
const url = process.env.BASEURL
const userAdminId = process.env.USERADMINID
const userAdminPass = process.env.USERADMINPASS

module.exports = {
  tags: [testId],
  '@disabled': disabled,

  'MediaCommons sites, or channels are online': function (client) {
    const request = require('request')
    const sites = [
      url, 
      `${url}/alt-ac`,
      `${url}/fieldguide`,
      `${url}/imr`,
      `${url}/intransition`,
      `${url}/tne`,     
    ].map(function (site) {
      request(site, function (error, response, body) {
        client.assert.equal(response.statusCode, 200, `${site} statusCode ${response.statusCode} === 200`)
      })
    })
    client.end()
  },

  'Finished': function (client) {
    client.perform(() => {
      console.log('[perform]: Finished Test:', client.currentTest.name)
    }).end()
  }

}
