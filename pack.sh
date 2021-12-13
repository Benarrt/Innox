if [ $# -ge 1 ];then
    if [ $1 == "build" ];then
        ./build.sh
    fi
  fi

if [ $# -ge 2 ];then
    if [ $2 == "build" ];then
        ./build.sh
    fi
  fi

if [ $# -ge 1 ];then
    if [ $1 == "install" ];then
        ./install.sh
    fi
  fi

if [ $# -ge 2 ];then
    if [ $2 == "install" ];then
        ./install.sh
    fi
  fi

docker build --target innox-app -t innox:latest -f ./docker/Dockerfile .