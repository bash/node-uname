/**
 * (c) 2015 Ruben Schmidmeister
 */

'use strict';

var uname = require('./uname'),
    assert = require('assert');

describe('uname', function () {
  it('returns an object containing string values', function () {
    var info = uname();

    assert('string', typeof info.sysname);
    assert('string', typeof info.nodename);
    assert('string', typeof info.release);
    assert('string', typeof info.version);
    assert('string', typeof info.machine);
  });
});
