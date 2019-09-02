#!/usr/bin/env bash
DIR="/usr/src/gtest"
if [ ! -d "$DIR" ]; then
	apt-get install libgtest-dev
fi
prevdir=$(pwd)
GLIB=$DIR/libgtest.so  
if [ ! -d "$DIR" ]; then
	cd $DIR
	cmake CMakeLists.txt
	make
	cp *.a /usr/lib
	cd $prevdir
fi
