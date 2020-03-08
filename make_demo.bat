c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/demo.o src/demo.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/droplet_sprites.o tile_data/droplet_sprites.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o build/demo.gb build/demo.o build/droplet_sprites.o