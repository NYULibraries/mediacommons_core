const _ = require('lodash')

module.exports = function (role) {
      const roles = [
        {
          'label': 'Administrator',
          'role': 'administrator',
          'selectors': [ 
            {
              'click': 'edit-roles-3'
            }
          ]
        },
        {
          'label': 'Cluster curator',
          'role': 'cluster curator',
          'selectors': [ 
            {
              'click': 'edit-roles-4'
            }
          ]
        },
        {
          'label': 'Managing Editor',
          'role': 'managing editor',
          'selectors': [ 
            {
              'click': 'edit-roles-6'
            }
          ]
        },
        {
          'label': 'Contributor',
          'role': 'contributor',
          'selectors': [ 
            {
              'click': 'edit-roles-5'
            }
          ]
        },
        {
          'label': 'User Manager',
          'role': 'user manager',
          'selectors': [ 
            {
              'click': 'edit-roles-7'
            }
          ]
        }
      ]
      return _.find(roles, { 'role': role } )
    }