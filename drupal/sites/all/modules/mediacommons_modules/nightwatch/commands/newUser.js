exports.command = function (user = {}, configuration = {}, callback) {
  const client = this
  const buildUrl = require('./buildUrl')
  const rolesMap = require('./rolesMap')
  const _ = require('lodash')
  console.log(`Create new user ${user.name}`)
  configuration.path = 'admin/people/create'
  client.url(buildUrl(configuration))
  client.waitForElementVisible('body', 1000)
  client.setValue('input#edit-name', user.name)
  client.setValue('input[name="mail"]', user.mail)
  client.setValue('input#edit-pass-pass1', user.pass)
  client.setValue('input#edit-pass-pass2', user.pass)
  user.roles.map(roleId => {
    const role = rolesMap(roleId)
    const roleSelectorClick = _.find(role.selectors, 'click').click
    client.assert.containsText(`label[for="${roleSelectorClick}"]`, role.role)
    client.click(`input#${roleSelectorClick}`)
  })
  client.submitForm('#edit-submit')
  client.waitForElementVisible('body', 1000)
  client.assert.containsText('.messages.status', `Created a new user account for ${user.name}.`)
  if (typeof callback === 'function') {
    callback.call(client, result)
  }
  return this
}
