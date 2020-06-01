# Makefile
# TODO: Change these to relative paths

SRCDIR = ./src
OBJDIR = ./build
BINDIR = ./build/bin
ROOTDIR = /mnt/c/Users/apadi/Documents/projects/gameboy

CC = /mnt/c/gbdk/bin/lcc.exe
CFLAGS = -Wa-l -Wl-m -Wl-j -I. -I$(SRCDIR) -DUSE_SFR_FOR_REG
LDFLAGS = -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG

# Bank 0 sources are always in memory.
SOURCES_BANK0 = \
	src/main.c \
	src/Debug.c \
	src/BackgroundMap.c \
	src/Droplet.c \
	src/Gate.c \
	src/Level.c \
	src/Position.c \
	src/Levels.c \
	src/Sprites.c \
	src/SpriteSquare16.c \
	src/Switch.c \
	src/Utility.c \
	data/tiles/droplet_background_tiles.c \
	data/tiles/droplet_sprites.c

# Bank 1+ sources must be swapped in when needed.
SOURCES_BANK1 = \
	src/Splash.c \
	data/maps/droplet_splash_bg.c \
	data/tiles/droplet_splash_tiles.c

SOURCES_BANK2 = \
	src/LevelMenu.c \
	src/LevelSelector.c \
	data/tiles/droplet_level_menu_tiles.c \
	data/maps/droplet_level_menu_bg.c

SOURCES_BANK3 = \
	src/Level1.c \
	src/Level2.c \
	data/maps/droplet_level1_bg.c \
	data/maps/droplet_level2_bg.c
	# data/maps/droplet_level3_bg.c

# Each bank of objects requires different flags.
OBJECTS_BANK0 := $(SOURCES_BANK0:%.c=$(OBJDIR)/%.0.o)
OBJECTS_BANK1 := $(SOURCES_BANK1:%.c=$(OBJDIR)/%.1.o)
OBJECTS_BANK2 := $(SOURCES_BANK2:%.c=$(OBJDIR)/%.2.o)
OBJECTS_BANK3 := $(SOURCES_BANK3:%.c=$(OBJDIR)/%.3.o)

# $(OBJECTS):
# 	mkdir -p $(OBJDIR)/src
# 	mkdir -p $(OBJDIR)/data/tiles
# 	mkdir -p $(OBJDIR)/data/maps

# Bank 0 sources need no extra flags.
$(OBJDIR)/%.0.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Bank 1+ sources need the -Wf-boX flag to set the bank.
$(OBJDIR)/%.1.o: %.c
	$(CC) $(CFLAGS) -Wf-bo1 -c -o $@ $<

$(OBJDIR)/%.2.o: %.c
	$(CC) $(CFLAGS) -Wf-bo2 -c -o $@ $<

$(OBJDIR)/%.3.o: %.c
	$(CC) $(CFLAGS) -Wf-bo3 -c -o $@ $<

# Final ROM contains objects from all banks.
droplet.gb: $(OBJECTS_BANK0) $(OBJECTS_BANK1) $(OBJECTS_BANK2) $(OBJECTS_BANK3)
	$(CC) $(LDFLAGS) -Wl-yo4 -Wl-yt1 -o build/bin/$@ $^

.PHONY: clean
clean:
	rm -f build/src/*
	rm -f build/data/tiles/*
	rm -f build/data/maps/*
	rm -f $(BINDIR)/*

.PHONY: play
play: droplet.gb
	$(ROOTDIR)/bgb_emulator/bgb.exe $(BINDIR)/$^ &

