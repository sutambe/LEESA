CXX=g++

ifndef $(XSD_ROOT)
  XSD_INCLUDE=
  XSD_BIN=xsdcxx
else
  XSD_INCLUDE=-I $(XSD_ROOT)/libxsd
  XSD_BIN=$(XSD_ROOT)/bin/xsd
endif

driver: driver.cxx rss2.o rss2-meta.o
	$(CXX) $(CXXFLAGS) driver.cxx rss2.o rss2-meta.o -o driver $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall -lxerces-c
        
rss2.o: rss2.cxx rss2.hxx
	$(CXX) $(CXXFLAGS) -c rss2.cxx -o rss2.o $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall

rss2-meta.o: rss2-meta.cxx rss2-meta.hxx
	$(CXX) $(CXXFLAGS) -c rss2-meta.cxx -o rss2-meta.o $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall

rss2.cxx: rss2.xsd
	$(XSD_BIN) cxx-tree --generate-ostream --generate-serialization --generate-default-ctor rss2.xsd

generate: rss2.cxx rss2.hxx
	$(LEESA_ROOT)/bin/gen-meta.py -doxygen rss2.hxx

clean:
	rm -f driver driver.o rss2.cxx rss2.hxx rss2.o rss2-meta.hxx rss2-meta.cxx rss2-meta.o all.xml
        
