declare module 'node-uname' {
  class Utsname {
    sysname: string
    nodename: string
    release: string
    version: string
    machine: string
  }

  function uname(): Utsname

  export = uname
}