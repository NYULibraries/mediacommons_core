exports.command = function (configuration = {}, callback) {
  const client = this
  const buildUrl = require('./buildUrl')
  client.url(buildUrl('node/add/hub'), function () {
    // for autocomplete fields to work, they need to be populated before other fields
    client.setValue('input#edit-field-co-editor-und-0-uid', configuration.coEditor)
    client.setValue('input#edit-title', configuration.label)
    client.submitForm('form#hub-node-form')
    client.waitForElementVisible('body', 1000)
    if (typeof callback === 'function') {
      callback.call(client, result)
    }
  })
  return this
}
