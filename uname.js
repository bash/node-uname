import bindings from 'bindings'

let native

export class Utsname {
  constructor(sysname, nodename, release, version, machine) {
    this.sysname = sysname
    this.nodename = nodename
    this.release = release
    this.version = version
    this.machine = machine

    Object.freeze(this)
  }
}

export function uname() {
  native ??= bindings('uname')
  const info = native.uname()
  return new Utsname(info.sysname, info.nodename, info.release, info.version, info.machine)
}
