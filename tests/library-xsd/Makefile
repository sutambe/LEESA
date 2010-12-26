CXX=g++

ifndef $(XSD_ROOT)
  XSD_INCLUDE=
  XSD_BIN=xsdcxx
else
  XSD_INCLUDE=-I $(XSD_ROOT)/libxsd
  XSD_BIN=$(XSD_ROOT)/bin/xsd
endif

driver: driver.cxx library.o library-meta.o
	$(CXX) driver.cxx library.o library-meta.o -o driver $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall -lxerces-c -D WITH_LEESA -D TEST4
        
library.o: library.cxx library.hxx
	$(CXX) -c library.cxx -o library.o $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall

library-meta.o: library-meta.cxx library-meta.hxx
	$(CXX) -c library-meta.cxx -o library-meta.o $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall

library.cxx: library.xsd
	$(XSD_BIN) cxx-tree --generate-ostream --generate-serialization --generate-default-ctor library.xsd

generate: library.cxx library.hxx
	$(LEESA_ROOT)/bin/gen-meta.py -doxygen library.hxx

clean:
	rm -f driver driver.o library.cxx library.hxx library.o library-meta.hxx library-meta.cxx library-meta.o all.xml
        
