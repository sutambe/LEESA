CXX=g++
#CXX=g++45
#CXXFLAGS=-std=c++0x -Wno-deprecated -D TEST13 -D WITH_LEESA
CXXFLAGS=-Wno-deprecated -D WITH_LEESA -DTEST1 -DTEST2 -DTEST3 -DTEST4 -DTEST5 -DTEST6 -DTEST7 -DTEST8 -DTEST9 -DTEST10 -DTEST11 -DTEST12 -DTEST13 -DTEST20

ifndef XSD_ROOT
  XSD_INCLUDE=
  XSD_BIN=xsd
else
  XSD_INCLUDE=-I $(XSD_ROOT)/libxsd
  XSD_BIN=$(XSD_ROOT)/bin/xsd
  LEESA_INCLUDE=-I $(LEESA_ROOT)/include
  BOOST_INCLUDE=-I $(BOOST_ROOT)
  INCLUDE_HEADERS=$(XSD_INCLUDE) $(LEESA_INCLUDE) $(BOOST_INCLUDE)
endif

driver: driver.cxx library.o library-meta.o
	$(CXX) $(CXXFLAGS) driver.cxx library.o library-meta.o -o driver $(INCLUDE_HEADERS) -W -Wall -lxerces-c
        
library.o: library.cxx library.hxx
	$(CXX) -Wno-deprecated -c library.cxx -o library.o $(INCLUDE_HEADERS) -W -Wall

library-meta.o: library-meta.cxx library-meta.hxx
	$(CXX) -Wno-deprecated -c library-meta.cxx -o library-meta.o $(INCLUDE_HEADERS) -W -Wall

library.cxx: library.xsd
	$(XSD_BIN) cxx-tree --generate-ostream --generate-serialization --generate-default-ctor library.xsd

generate: library.cxx library.hxx
	$(LEESA_ROOT)/bin/gen-meta.py -doxygen library.hxx

clean:
	rm -f driver driver.o library.cxx library.hxx library.o library-meta.hxx library-meta.cxx library-meta.o all.xml
        
