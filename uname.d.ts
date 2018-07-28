declare module 'node-uname' {
  export class Utsname {
    sysname: string
    nodename: string
    release: string
    version: string
    machine: string
  }

  export function uname(): Utsname
}