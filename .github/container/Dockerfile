ARG codename=stable

FROM debian:${codename}-slim

RUN if [[ "${codename}" != "stable" ]] ; "deb [trusted=yes] http://archive.debian.org/debian/ ${codename} main" > /etc/apt/sources.list ; fi
