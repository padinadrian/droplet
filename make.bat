del build\*.o

c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/droplet_splash_bg.o data/maps/droplet_splash_bg.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/droplet_splash_tiles.o data/tiles/droplet_splash_tiles.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/droplet_sprites.o data/tiles/droplet_sprites.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/SpriteSquare16.o src/SpriteSquare16.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/DropletMap.o src/DropletMap.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/Position.o src/Position.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/Droplet.o src/Droplet.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/Splash.o src/Splash.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/main.o src/main.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o build/bin/droplet.gb ^
    build\droplet_sprites.o ^
    build\droplet_splash_tiles.o ^
    build\droplet_splash_bg.o ^
    build\SpriteSquare16.o ^
    build\DropletMap.o ^
    build\Position.o ^
    build\Droplet.o ^
    build\Splash.o ^
    build\main.o