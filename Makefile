all:
	$(MAKE) -C Pop $@

clean:
	$(MAKE) -C Pop $@

deps-clean:
	$(MAKE) -C Pop $@

format-xml:
	tidy -bcimq -utf8 -w 120 -xml -asxml data.xml

.PHONY: all clean deps-clean
