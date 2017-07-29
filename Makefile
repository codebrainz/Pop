all:
	$(MAKE) -C Pop $@

clean:
	$(MAKE) -C Pop $@

deps-clean:
	$(MAKE) -C Pop $@

.PHONY: all clean deps-clean
