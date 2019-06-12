'use strict'

const { uname } = require('./uname')
const assert = require('assert')

describe('uname', () => {
  it('returns an object containing string values', () => {
    const info = uname()

    assertIsNonEmptyString(info.sysname)
    assertIsNonEmptyString(info.nodename)
    assertIsNonEmptyString(info.release)
    assertIsNonEmptyString(info.version)
    assertIsNonEmptyString(info.machine)
  })
})

function assertIsNonEmptyString(value) {
  assert.strictEqual('string', typeof value);
  assert.notStrictEqual('', value);
}
