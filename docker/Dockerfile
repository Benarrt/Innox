FROM ubuntu:18.04 AS innox-app
WORKDIR /home

# Install
RUN apt-get update && apt-get install -y -q --no-install-recommends ca-certificates wget xz-utils libboost-system-dev libboost-thread-dev liblog4cxx-dev libglib2.0-0 libfreetype6-dev curl sudo

ARG APP_PATH="/home/innox"

RUN useradd -m innox && echo "innox:innox" | chpasswd && adduser innox sudo

# COPY

# Server
COPY --chown=innox:innox ./server/ ${APP_PATH}/

# Scripts
COPY --chown=innox:innox ./scripts/ ${APP_PATH}/public/scripts/

# html
COPY --chown=innox:innox ./index.html ${APP_PATH}/public/

# Qt Webassembly
COPY --chown=innox:innox ./Innox.wasm ${APP_PATH}/public/
COPY --chown=innox:innox ./qtloader.js ${APP_PATH}/public/
COPY --chown=innox:innox ./Innox.js ${APP_PATH}/public/

# Install node
ARG NODE_VER=v10.21.0
ARG NODE_REPO=https://nodejs.org/dist/${NODE_VER}/node-${NODE_VER}-linux-x64.tar.xz

RUN wget ${NODE_REPO} && \
    tar xf node-${NODE_VER}-linux-x64.tar.xz && \
    cp node-*/* /usr/local -rf && rm -rf node-*






