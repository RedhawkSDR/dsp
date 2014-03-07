all: doc
	make -C Release all

# Other Targets
clean:
	make -C Release clean
	rm -rf doc

doc:	inc/*.h src/*.cpp
	doxygen || exit 0

install: all
	mkdir -p $(DESTDIR)${SDRROOT}/dom/components/dsp
	install -m 664 dsp.spd.xml $(DESTDIR)${SDRROOT}/dom/components/dsp/dsp.spd.xml
	mkdir -p $(DESTDIR)${SDRROOT}/dom/components/dsp/Release
	install Release/libdsp.so $(DESTDIR)${SDRROOT}/dom/components/dsp/Release/libdsp.so
	mkdir -p $(DESTDIR)${SDRROOT}/dom/components/dsp/inc
	install -m 664 inc/*.h $(DESTDIR)${SDRROOT}/dom/components/dsp/inc
	cp -r doc $(DESTDIR)${SDRROOT}/dom/components/dsp
