# Debian Package for Mockpp Project

[![TravisCI Status][travis-image]][travis-url]

**Build dependencies**

- debhelper (>= 9)
- dh-autoreconf (>= 2)
- autotools-dev
- libcppunit-dev (>= 1.12.1)

**Download source code**

- unzip
- wget
- libc-bin
- dos2unix

```
$ debian/rules get-orig-source
$ debian/rules publish-source
```

**Build project**

```
$ dpkg-buildpackage -rfakeroot -D -us -uc -i -I -sa
```
or
```
$ QUILT_PATCHES=debian/patches quilt push -a
$ fakeroot debian/rules clean binary
```

**Tested**

- Debian wheezy

**Repositories**

[Debian repository](https://bintray.com/yadickson/debian)

```
$ echo "deb [trusted=true] https://dl.bintray.com/yadickson/debian [distribution] main" | sudo tee -a /etc/apt/sources.list.d/bintray.list
$ sudo apt-get update
$ sudo apt-get upgrade -y
$ sudo apt-get install libpf-java
```

## License

GPL-3.0 © [Yadickson Soto](https://github.com/yadickson)

LGPL-2 © [Ewald Arnold](http://sourceforge.net/projects/mockpp/)

[travis-image]: https://api.travis-ci.org/yadickson/mockpp-debs.svg?branch=wheezy
[travis-url]: https://travis-ci.org/yadickson/mockpp-debs
