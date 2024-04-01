# variables defined for "cc_and_flags" API
PACKAGE_NAME_NOTSTRING = lAng
PACKAGE_NAME = "$(PACKAGE_NAME_NOTSTRING)"
TARGET = lAng
PACKAGE_VERSION = 0.0.1
C_STD ?= c11
# setting up sources
SRCDIR = $(shell pwd)/src
OBJDIR = $(shell pwd)/obj
BINDIR = $(shell pwd)/bin
INCLUDES = $(wildcard $(SRCDIR)/include/*.h)
LANG_NAME = $(TARGET)

TARGET_ARCH ?= x86
ifeq ($(TARGET_ARCH), x86)
	MARCH = x86-64
endif

SOURCES_C = $(wildcard $(SRCDIR)/*.c)
OBJECTS_C = $(SOURCES_C:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


IVARS = -I$(SRCDIR)/include

COMMON_FLAGS = -O2 -pipe $(IVARS)
COMMON_FLAGS_C = -DLANGNAME_STRING=\"$(LANG_NAME)\" -DLINUX=1 -D_GNU_SOURCE
include cc_and_flags.mk
the_CFLAGS = -pedantic $(_CFLAGS)
the_LFLAGS = $(LDFLAGS) $(IVARS) $(_LFLAGS)

.PHONY: all clean remove

all:
	$(MAKE) remove
	$(MAKE) $(TARGET)



$(TARGET): $(OBJECTS_C) | $(BINDIR)
	$(CC) -o $(BINDIR)/$@ $^ $(IVARS) $(the_LFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -o $@ $(the_CFLAGS) $^ -c

$(BINDIR) $(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJECTS_C)

remove: clean
	rm -rf $(BINDIR)/$(TARGET)

