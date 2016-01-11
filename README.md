# node-uname

[![Build Status](https://travis-ci.org/bash/node-uname.svg?branch=master)](https://travis-ci.org/bash/node-uname)
[![Coverage Status](https://coveralls.io/repos/bash/node-uname/badge.svg?branch=master&service=github)](https://coveralls.io/github/bash/node-uname?branch=master)
[![npm version](https://badge.fury.io/js/node-uname.svg)](https://badge.fury.io/js/node-uname)
[![dependencies](https://david-dm.org/bash/node-uname.svg)](https://david-dm.org/bash/node-uname)

A wrapper around the `uname` call.

## installation

```
npm install node-uname
```

## example

```js
var uname = require('node-uname');

console.log(uname());

// Utsname {
//   sysname: 'Darwin',
//   nodename: 'MacBook.local',
//   release: '15.0.0',
//   version: 'Darwin Kernel Version ...',
//   machine: 'x86_64' }
```

## uname()
The uname() function returns an object containing sysname, nodename, release, version and machine.

If the internal call to the kernel's [`uname`](http://man7.org/linux/man-pages/man2/uname.2.html) function fails an [Error](https://nodejs.org/api/errors.html) is thrown.