#!/bin/bash

for i in {1..13}
do
  touch driver.cxx
make CXX=g++45 CXXFLAGS="-Wno-deprecated -D TEST$i -D WITH_LEESA"
#make CXX=g++45 CXXFLAGS="-std=c++0x -Wno-deprecated -D TEST$i -D WITH_LEESA"
  if [ $? -ne 0 ] ; then break ; fi
done

