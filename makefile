all: 
	cd Release && make all  

# Other Targets
clean:
	cd Release && make clean   
	
install: all
	mkdir -p ${SDRROOT}/dom/components/dsp
	install -m 664 dsp.spd.xml ${SDRROOT}/dom/components/dsp/dsp.spd.xml
	mkdir -p ${SDRROOT}/dom/components/dsp/Release
	install Release/libdsp.so ${SDRROOT}/dom/components/dsp/Release/libdsp.so
	mkdir -p ${SDRROOT}/dom/components/dsp/inc
	install -m 664 inc/*.h ${SDRROOT}/dom/components/dsp/inc
	