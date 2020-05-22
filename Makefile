# Makefile
# TODO: Change these to relative paths

SRCDIR = ./src
OBJDIR = ./build
BINDIR = ./build/bin
ROOTDIR = /mnt/c/Users/apadi/Documents/projects/gameboy
GBDKNBIN = $(ROOTDIR)/gbdk-n/bin

CC = /mnt/c/gbdk/bin/lcc.exe
CFLAGS = -Wa-l -Wl-m -Wl-j -I. -I$(SRCDIR) -DUSE_SFR_FOR_REG
LDFLAGS = -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG

# src = $(wildcard src/*.c) $(wildcard data/tiles/*.c) $(wildcard data/maps/*.c)
SOURCES = \
	$(wildcard src/*.c) \
	$(wildcard data/tiles/*.c) \
	$(wildcard data/maps/*.c)

OBJECTS := $(SOURCES:%.c=$(OBJDIR)/%.rel)

# $(OBJECTS):
# 	mkdir -p $(OBJDIR)/src
# 	mkdir -p $(OBJDIR)/data/tiles
# 	mkdir -p $(OBJDIR)/data/maps

$(OBJDIR)/%.rel: %.c
	$(GBDKNBIN)/gbdk-n-compile.sh -I. -I$(SRCDIR) -o $@ $<

droplet.gb: $(OBJECTS)
	$(GBDKNBIN)/gbdk-n-link.sh -o $(BINDIR)/droplet.ihx $^
	$(GBDKNBIN)/gbdk-n-make-rom.sh $(BINDIR)/droplet.ihx $(BINDIR)/droplet.gb

.PHONY: clean
clean:
	rm -f build/src/* build/data/tiles/* build/data/maps/* $(BINDIR)/*

.PHONY: play
play: droplet.gb
	$(ROOTDIR)/bgb_emulator/bgb.exe $(BINDIR)/$^ &

