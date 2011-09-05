CXX=g++
#CXX=g++45
#CXXFLAGS=-std=c++0x -Wno-deprecated -D TEST13 -D WITH_LEESA
CXXFLAGS=-Wno-deprecated -D WITH_LEESA 

ifndef $(XSD_ROOT)
  XSD_INCLUDE=
  XSD_BIN=xsdcxx
else
  XSD_INCLUDE=-I $(XSD_ROOT)/libxsd
  XSD_BIN=$(XSD_ROOT)/bin/xsd
endif

driver: driver.cpp xsd/g2sBonus.o xsd/g2sCabinet.o xsd/g2sCentral.o xsd/g2sCoinAcceptor.o xsd/g2sCommConfig.o xsd/g2sCommunications.o xsd/g2sDownload.o xsd/g2sEventHandler.o xsd/g2sGamePlay.o xsd/g2sGAT.o xsd/g2sHandpay.o xsd/g2sHopper.o xsd/g2sIdReader.o xsd/g2sIncludeClasses.o xsd/g2sIncludeConfig.o xsd/g2sIncludeGlobal.o xsd/g2sMessage.o xsd/g2sMeters.o xsd/g2sNoteAcceptor.o xsd/g2sNoteDispenser.o xsd/g2sOptionConfig.o xsd/g2sPlayer.o xsd/g2sPrinter.o xsd/g2sProgressive.o xsd/g2sVoucher.o xsd/g2sWAT.o
	$(CXX) $(CXXFLAGS) driver.cpp xsd/*.o -o driver  $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall -lxerces-c -D G2S_Export=
        
library-meta.o: library-meta.cxx library-meta.hxx
	$(CXX) -Wno-deprecated -c library-meta.cxx -o library-meta.o $(XSD_INCLUDE) -I$(LEESA_ROOT)/include -W -Wall

library.cxx: library.xsd
	$(XSD_BIN) cxx-tree --generate-ostream --generate-serialization --generate-default-ctor library.xsd

generate: library.cxx library.hxx
	$(LEESA_ROOT)/bin/gen-meta.py -doxygen library.hxx

clean:
	rm -f driver driver.o library.cxx library.hxx library.o library-meta.hxx library-meta.cxx library-meta.o all.xml
        
xsd/g2sBonus.o: xsd/g2sBonus.cxx xsd/g2sBonus.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sBonus.cxx -o xsd/g2sBonus.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sCabinet.o: xsd/g2sCabinet.cxx xsd/g2sCabinet.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sCabinet.cxx -o xsd/g2sCabinet.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sCentral.o: xsd/g2sCentral.cxx xsd/g2sCentral.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sCentral.cxx -o xsd/g2sCentral.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sCoinAcceptor.o: xsd/g2sCoinAcceptor.cxx xsd/g2sCoinAcceptor.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sCoinAcceptor.cxx -o xsd/g2sCoinAcceptor.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sCommConfig.o: xsd/g2sCommConfig.cxx xsd/g2sCommConfig.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sCommConfig.cxx -o xsd/g2sCommConfig.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sCommunications.o: xsd/g2sCommunications.cxx xsd/g2sCommunications.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sCommunications.cxx -o xsd/g2sCommunications.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sDownload.o: xsd/g2sDownload.cxx xsd/g2sDownload.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sDownload.cxx -o xsd/g2sDownload.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sEventHandler.o: xsd/g2sEventHandler.cxx xsd/g2sEventHandler.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sEventHandler.cxx -o xsd/g2sEventHandler.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sGamePlay.o: xsd/g2sGamePlay.cxx xsd/g2sGamePlay.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sGamePlay.cxx -o xsd/g2sGamePlay.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sGAT.o: xsd/g2sGAT.cxx xsd/g2sGAT.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sGAT.cxx -o xsd/g2sGAT.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sHandpay.o: xsd/g2sHandpay.cxx xsd/g2sHandpay.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sHandpay.cxx -o xsd/g2sHandpay.o -W -Wall -D G2S_Export=

xsd/g2sHopper.o: xsd/g2sHopper.cxx xsd/g2sHopper.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sHopper.cxx -o xsd/g2sHopper.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sIdReader.o: xsd/g2sIdReader.cxx xsd/g2sIdReader.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sIdReader.cxx -o xsd/g2sIdReader.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sIncludeClasses.o: xsd/g2sIncludeClasses.cxx xsd/g2sIncludeClasses.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sIncludeClasses.cxx -o xsd/g2sIncludeClasses.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sIncludeConfig.o: xsd/g2sIncludeConfig.cxx xsd/g2sIncludeConfig.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sIncludeConfig.cxx -o xsd/g2sIncludeConfig.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sIncludeGlobal.o: xsd/g2sIncludeGlobal.cxx xsd/g2sIncludeGlobal.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sIncludeGlobal.cxx -o xsd/g2sIncludeGlobal.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sMessage.o: xsd/g2sMessage.cxx xsd/g2sMessage.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sMessage.cxx -o xsd/g2sMessage.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sMeters.o: xsd/g2sMeters.cxx xsd/g2sMeters.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sMeters.cxx -o xsd/g2sMeters.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sNoteAcceptor.o: xsd/g2sNoteAcceptor.cxx xsd/g2sNoteAcceptor.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sNoteAcceptor.cxx -o xsd/g2sNoteAcceptor.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sNoteDispenser.o: xsd/g2sNoteDispenser.cxx xsd/g2sNoteDispenser.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sNoteDispenser.cxx -o xsd/g2sNoteDispenser.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sOptionConfig.o: xsd/g2sOptionConfig.cxx xsd/g2sOptionConfig.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sOptionConfig.cxx -o xsd/g2sOptionConfig.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sPlayer.o: xsd/g2sPlayer.cxx xsd/g2sPlayer.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sPlayer.cxx -o xsd/g2sPlayer.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sPrinter.o: xsd/g2sPrinter.cxx xsd/g2sPrinter.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sPrinter.cxx -o xsd/g2sPrinter.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sProgressive.o: xsd/g2sProgressive.cxx xsd/g2sProgressive.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sProgressive.cxx -o xsd/g2sProgressive.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sVoucher.o: xsd/g2sVoucher.cxx xsd/g2sVoucher.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sVoucher.cxx -o xsd/g2sVoucher.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

xsd/g2sWAT.o: xsd/g2sWAT.cxx xsd/g2sWAT.hxx
	$(CXX) -Wno-deprecated -c xsd/g2sWAT.cxx -o xsd/g2sWAT.o -W -Wall -D G2S_Export=  $(XSD_INCLUDE) 

