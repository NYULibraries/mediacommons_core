exports.command = function (user, pass, configuration = {}, callback) {
  console.log(`Log-in as user ${user}`)
  const client = this
  const buildUrl = require('./buildUrl')  
  configuration.path = 'user'
  client.url(buildUrl(configuration))
  client.waitForElementPresent('form#user-login', 1000)
  client.setValue('input#edit-name', user)
  client.setValue('input#edit-pass', pass)
  client.submitForm('#user-login')
  client.waitForElementVisible('body', 1000)
  if (typeof callback === 'function') {
    callback.call(client, result)
  }
  return this
}
