SRCDIR = ./src
OBJDIR = ./build

CC = /mnt/c/gbdk/bin/lcc.exe
CFLAGS = -Wa-l -Wl-m -Wl-j -I. -I$(SRCDIR) -DUSE_SFR_FOR_REG
LDFLAGS = -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG

# src = $(wildcard src/*.c) $(wildcard data/tiles/*.c) $(wildcard data/maps/*.c)
SOURCES = \
	$(wildcard src/*.c) \
	$(wildcard data/tiles/*.c) \
	$(wildcard data/maps/*.c)

OBJECTS := $(SOURCES:%.c=$(OBJDIR)/%.o)

# $(OBJECTS):
# 	mkdir -p $(OBJDIR)/src
# 	mkdir -p $(OBJDIR)/data/tiles
# 	mkdir -p $(OBJDIR)/data/maps

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

droplet.gb: $(OBJECTS)
	echo $(LDFLAGS)
	$(CC) $(LDFLAGS) -o build/bin/$@ $^

.PHONY: clean
clean:
	rm -f $(OBJECTS) droplet.gb

.PHONY: play
play: droplet.gb
	/mnt/c/Users/apadi/Documents/projects/gameboy/bgb_emulator/bgb.exe build/bin/$^ &

