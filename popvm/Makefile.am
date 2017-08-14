bin_PROGRAMS = popvm

popvm_SOURCES = \
	main.c \
	ops.h \
	utils.c \
	utils.h

CODEGEN_DATA_FILE = $(top_srcdir)/scripts/codegen-data.xml
CODEGEN_SCRIPT = $(top_srcdir)/scripts/codegen.py
CODEGEN_DEPS = $(CODEGEN_DATA_FILE) $(CODEGEN_SCRIPT)
CODEGEN = $(AM_V_GEN)$(PYTHON) $(CODEGEN_SCRIPT) -d $(CODEGEN_DATA_FILE)

include $(srcdir)/ops/op_sources.mk

EXTRA_DIST = \
	$(CODEGEN_DATA_FILE) \
	decode.c.in \
	ops.h.in \
	ops/op_sources.mk \
	ops/template.c.in \
	$(popvm_op_sources)

if MAINTAINER_MODE

BUILT_SOURCES = decode.c ops.h
DISTCLEANFILES = $(BUILT_SOURCES)

decode.c: $(srcdir)/decode.c.in $(CODEGEN_DEPS)
	$(CODEGEN) -o $@ $(srcdir)/decode.c.in

ops.h: $(srcdir)/ops.h.in $(CODEGEN_DEPS)
	$(CODEGEN) -o $@ $(srcdir)/ops.h.in

endif
