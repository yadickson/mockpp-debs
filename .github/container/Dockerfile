ARG CODENAME=stable

FROM debian:${CODENAME}-slim

RUN if [[ "${CODENAME}" != "stable" ]] ; "deb [trusted=yes] http://archive.debian.org/debian/ ${CODENAME} main" > /etc/apt/sources.list ; fi
