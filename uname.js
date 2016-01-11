/**
 * (c) 2015 Ruben Schmidmeister
 */

'use strict'

module.exports = uname

var native = require('bindings')('uname')

/**
 *
 * @param {string} sysname
 * @param {string} nodename
 * @param {string} release
 * @param {string} version
 * @param {string} machine
 * @constructor
 */
function Utsname(sysname, nodename, release, version, machine) {
  /**
   *
   * @type {string}
   */
  this.sysname = sysname

  /**
   *
   * @type {string}
   */
  this.nodename = nodename

  /**
   *
   * @type {string}
   */
  this.release = release

  /**
   *
   * @type {string}
   */
  this.version = version

  /**
   *
   * @type {string}
   */
  this.machine = machine
}


/**
 *
 * @returns {Utsname}
 * @throws {Error}
 */
function uname() {
  var info = native.uname()

  return new Utsname(info.sysname, info.nodename, info.release, info.version, info.machine)
}
