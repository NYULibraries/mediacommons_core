const conf = require('../nightwatch.conf.js')

module.exports = function (configuration = {}) {
  const { join } = require('path')
  let url = process.env.BASEURL
  if (configuration.path) {
    url = `${url}/${configuration.path}`
  }
  if (configuration.destination) {
    url = `${url}?destination=${configuration.destination}`
  }
  return url
}
