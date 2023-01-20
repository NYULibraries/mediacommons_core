exports.command = function (callback) {
  const client = this
  client.waitForElementPresent('body', 1000)
  /**
   * Test if new user has access to delete node
   */
  client.click('#edit-delete')
  /**
   * Confirm you want to delete node
   */
  client.click('#edit-submit')
  client.waitForElementPresent('.status', 1000)
  client.assert.containsText('.status', `has been deleted.`)  
  if (typeof callback === 'function') {
    callback.call(client, result)
  }
  return this
}
