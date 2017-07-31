all:
	$(MAKE) -C Pop $@

clean:
	$(MAKE) -C Pop $@

deps-clean:
	$(MAKE) -C Pop $@

format-xml:
	tidy -bcimq -utf8 -w 120 -xml -asxml data.xml

tidy:
	$(MAKE) -C Pop $@

.PHONY: all clean deps-clean format-xml tidy
