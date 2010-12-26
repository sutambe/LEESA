CXX=g++

ifndef $(XSD_ROOT)
  XSD_INCLUDE=
  XSD_BIN=xsdcxx
else
  XSD_INCLUDE=-I $(XSD_ROOT)/libxsd
  XSD_BIN=$(XSD_ROOT)/bin/xsd
endif

driver: driver.cxx supermen.o supermen-meta.o
	$(CXX) driver.cxx supermen.o supermen-meta.o -o driver $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall -lxerces-c
        
supermen.o: supermen.cxx supermen.hxx
	$(CXX) -c supermen.cxx -o supermen.o $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall

supermen-meta.o: supermen-meta.cxx supermen-meta.hxx
	$(CXX) -c supermen-meta.cxx -o supermen-meta.o $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall

supermen.cxx: supermen.xsd
	$(XSD_BIN) cxx-tree --generate-ostream --generate-serialization --generate-default-ctor --generate-polymorphic supermen.xsd

generate: supermen.cxx supermen.hxx
	$(LEESA_ROOT)/bin/gen-meta.py -doxygen supermen.hxx

clean:
	rm -f driver driver.o supermen.cxx supermen.hxx supermen.o supermen-meta.hxx supermen-meta.cxx supermen-meta.o all.xml
        
