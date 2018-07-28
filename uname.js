'use strict'

const native = require('bindings')('uname')

class Utsname {
  constructor(sysname, nodename, release, version, machine) {
    this.sysname = sysname
    this.nodename = nodename
    this.release = release
    this.version = version
    this.machine = machine

    Object.freeze(this)
  }
}

function uname() {
  const info = native.uname()

  return new Utsname(info.sysname, info.nodename, info.release, info.version, info.machine)
}

module.exports = { uname, Utsname }