'use strict'

const { uname } = require('./uname')
const assert = require('assert')

describe('uname', () => {
  it('returns an object containing string values', () => {
    const info = uname()

    assert('string', typeof info.sysname)
    assert('string', typeof info.nodename)
    assert('string', typeof info.release)
    assert('string', typeof info.version)
    assert('string', typeof info.machine)
  })
})
