ARG codename=stable

FROM debian:${codename}-slim

RUN if [[ "${codename}" != "stable" ]] ; then echo "deb [trusted=yes] http://archive.debian.org/debian/ ${codename} main" > /etc/apt/sources.list ; fi
