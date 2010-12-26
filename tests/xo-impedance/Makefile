CXX=g++

ifndef $(XSD_ROOT)
  XSD_INCLUDE=
  XSD_BIN=xsdcxx
else
  XSD_INCLUDE=-I $(XSD_ROOT)/libxsd
  XSD_BIN=$(XSD_ROOT)/bin/xsd
endif

driver: driver.cxx impedance.o
	$(CXX) driver.cxx impedance.o -o driver $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall -lxerces-c
        
impedance.o: impedance.cxx impedance.hxx
	$(CXX) -c impedance.cxx -o impedance.o $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall

impedance.cxx: impedance.xsd
	$(XSD_BIN) cxx-tree --generate-ostream --generate-serialization --generate-default-ctor impedance.xsd

clean:
	rm -f driver driver.o impedance.cxx impedance.hxx impedance.o 
        
