var util = require('util');
var events = require('events');
var request = require('request');
function apiGet () {
  events.EventEmitter.call(this);
}
util.inherits(apiGet, events.EventEmitter);

apiGet.prototype.command = function(options, callback) {
  var self = this;
  this.api.perform(function() {
    setTimeout(function() {
      defaultOptions = {
        method: 'GET',
        json : true,
      };
      options = Object.assign(defaultOptions, options);

      request(options, function(error, response){
        if (error) {
          console.error(error);
          return;
        }
        if (callback) {
          callback(response);
        }
      });
      self.emit('complete');
    }, 10);
  });
  return this;
};

module.exports = apiGet;
