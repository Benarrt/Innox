if [ $# -ge 2 ];then
    if [ $2 == "build" ];then
        ./build.sh
    fi
  fi

if [ $# -ge 3 ];then
    if [ $3 == "build" ];then
        ./build.sh
    fi
  fi

if [ $# -ge 2 ];then
    if [ $2 == "install" ];then
        ./install.sh
    fi
  fi

if [ $# -ge 3 ];then
    if [ $3 == "install" ];then
        ./install.sh
    fi
  fi


# COPY
APP_PATH="/home/innox"
# Server
docker cp ./server/ $1:${APP_PATH}/

# Scripts
docker cp ./scripts/ $1:${APP_PATH}/public/

# Resources
docker cp ./resources/ $1:${APP_PATH}/public/

# html
docker cp ./index.html $1:${APP_PATH}/public/

# Qt Webassembly
docker cp ./Innox.wasm $1:${APP_PATH}/public/
docker cp ./qtloader.js $1:${APP_PATH}/public/
docker cp ./Innox.js $1:${APP_PATH}/public/