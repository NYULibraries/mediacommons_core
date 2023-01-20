exports.command = function (configuration, callback) {
  const buildUrl = require('./buildUrl')
  const client = this
  client.url(buildUrl( { path: `api/user/${configuration.name}/edit`} ), function (result) {
    client.waitForElementPresent('#edit-cancel', 1000)
    client.assert.attributeContains('#edit-cancel', 'value', 'Cancel account')
    // click Cancel account button
    client.click('#edit-cancel')
    // delete new user
    client.click('#edit-user-cancel-method--5')
    client.click('#edit-submit')
    client.waitForElementVisible('body', 1000)
    client.assert.containsText('.messages.status', `${configuration.name} has been deleted.`)
    if (typeof callback === 'function') {
      callback.call(client, result)
    }
  })

  return this
}
