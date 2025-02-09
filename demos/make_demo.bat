c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/droplet_sprites.o data/tiles/droplet_sprites.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/SpriteSquare16.o src/SpriteSquare16.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/BackgroundMap.o src/BackgroundMap.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/Position.o src/Position.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/Droplet.o src/Droplet.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -I%CD% -DUSE_SFR_FOR_REG -c -o build/demo.o src/demo.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o build/demo.gb ^
    build\droplet_sprites.o ^
    build\SpriteSquare16.o ^
    build\BackgroundMap.o ^
    build\Position.o ^
    build\Droplet.o ^
    build\demo.o