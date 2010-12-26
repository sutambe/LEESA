CXX=g++

ifndef $(XSD_ROOT)
  XSD_INCLUDE=
  XSD_BIN=xsdcxx
else
  XSD_INCLUDE=-I $(XSD_ROOT)/libxsd
  XSD_BIN=$(XSD_ROOT)/bin/xsd
endif

driver: driver.cxx PICML.o PICML-meta.o
	$(CXX) driver.cxx PICML.o PICML-meta.o -o driver $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall -lxerces-c -D WITH_LEESA -D TEST4
        
PICML.o: PICML.cxx PICML.hxx
	$(CXX) -c PICML.cxx -o PICML.o $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall

PICML-meta.o: PICML-meta.cxx PICML-meta.hxx
	$(CXX) -c PICML-meta.cxx -o PICML-meta.o $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall

PICML.cxx: PICML.xsd
	$(XSD_BIN) cxx-tree --generate-ostream --generate-serialization --generate-default-ctor PICML.xsd

generate: PICML.cxx PICML.hxx
	$(LEESA_ROOT)/bin/gen-meta.py -doxygen PICML.hxx

clean:
	rm -f driver driver.o PICML.cxx PICML.hxx PICML.o PICML-meta.hxx PICML-meta.cxx PICML-meta.o all.xml
        
