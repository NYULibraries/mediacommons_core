exports.command = function (callback) {
  console.log(`Log-out user`)
  const client = this
  const buildUrl = require('./buildUrl')  
  client.url(buildUrl({ path: 'user/logout' }))
  client.waitForElementPresent('body', 1000)
  if (typeof callback === 'function') {
    callback.call(client, result)
  }
  return this
}
