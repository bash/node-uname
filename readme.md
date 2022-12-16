# node-uname

[![Build Status](https://github.com/bash/node-uname/workflows/Build/badge.svg)](https://github.com/bash/node-uname/actions)
[![npm](https://img.shields.io/npm/v/node-uname)](https://www.npmjs.com/package/node-uname)

A wrapper around the `uname` call.  
Works on GNU/Linux and MacOS.

## Installation

```bash
npm install node-uname
```

## Example

```javascript
const { uname } = require('node-uname')

console.log(uname())

// Utsname {
//   sysname: 'Darwin',
//   nodename: 'MacBook.local',
//   release: '15.0.0',
//   version: 'Darwin Kernel Version ...',
//   machine: 'x86_64' }
```

## uname()
The uname() function returns an object containing `sysname`, `nodename`, `release`, `version` and machine.

If the internal call to the kernel's [`uname`](http://man7.org/linux/man-pages/man2/uname.2.html) function fails an [Error](https://nodejs.org/api/errors.html) is thrown.
