exports.command = function (callback) {
  const client = this
  client.waitForElementPresent('body', 1000)
  client.click('#edit-submit')        
  client.waitForElementVisible('body', 1000)
  client.assert.containsText('.messages.status', `has been updated.`)  
  if (typeof callback === 'function') {
    callback.call(client, result)
  }
  return this
}
