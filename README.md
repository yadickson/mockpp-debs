# Debian Package for Mockpp Project

**Build dependencies**

- debhelper (>= 10)
- dh-autoreconf (>= 2)
- autotools-dev
- libcppunit-dev (>= 1.12.1)

**Download source code**

- unzip
- wget

```
$ debian/rules orig
$ debian/rules source
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
- Debian jessie
- Debian stretch
- Debian buster

**Repositories**

[Debian repository](https://bintray.com/yadickson/debian)

```
$ wget -qO - https://bintray.com/user/downloadSubjectPublicKey?username=bintray | sudo apt-key add -
```
```
$ echo "deb https://dl.bintray.com/yadickson/debian [distribution] main" | sudo tee -a /etc/apt/sources.list.d/bintray.list
```
```
$ sudo apt-get update
$ sudo apt-get upgrade -y
$ sudo apt-get install libmockpp-dev
```

## License

GPL-3.0 © [Yadickson Soto](https://github.com/yadickson)

LGPL-2 © [Ewald Arnold](http://sourceforge.net/projects/mockpp/)
