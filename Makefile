all:
	$(MAKE) -C Pop $@

clean:
	$(MAKE) -C Pop $@
	$(RM) test.dot test.png

deps-clean:
	$(MAKE) -C Pop $@

format-xml:
	tidy -bcimq -utf8 -w 120 -xml -asxml data.xml

tidy:
	$(MAKE) -C Pop $@

test.dot: all
	Pop/pop > $@

test.png: test.dot
	dot -Tpng -o $@ test.dot

.PHONY: all clean deps-clean format-xml tidy
