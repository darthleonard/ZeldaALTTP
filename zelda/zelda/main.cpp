#include <stdio.h>
#include <allegro.h>

#include <Link.h>
#include <Enemigo.h>

#define ANCHO 512
#define ALTO 512

#define MAXFILAS 32
#define MAXCOLS 33

BITMAP *buffer;
BITMAP *mapabmp;
BITMAP *seccion;

int mapaX = 0;
int mapaY = 0;

char mapa[MAXFILAS][MAXCOLS];

char mapa47[MAXFILAS][MAXCOLS] = {
    "         X                  X   ",
    "        X                   X   ",
    "       X                   X    ",
    "       X   x     x        X     ",
    "   XXX X  x        x     X      ",
    "   X  X                 X       ",
    "   X                    X       ",
    " XX                     X       ",
    " X     xxxxxxxxx        X       ",
    " X    x         x       X       ",
    " X   x           x      X       ",
    "X    x   xxxxxx  xx     X       ",
    "     x   x    x  xx      X      ",
    "     x   x    x  xx       X     ",
    "    x    x    x  xx       X     ",
    "xxxx     xxxxxx  xx       X     ",
    "         xxooxx  xx       X     ",
    "  xx   xxx    xx xx       X     ",
    "  xx   xxx    xx xx       X     ",
    "  xx             xx        X    ",
    "   x   xxx   xxx xx         X   ",
    "xxxx   xxxxxxxxxxxx       x  X  ",
    "   x   x         x        xx  XX",
    "xxx     xxxxxxxxx          xxx  ",
    "                                ",
    "                                ",
    "                                ",
    "     xxx           xxxxxxxxxxxxx",
    "xxxxx   xxx       x             ",
    "           x     x              ",
    "            x   x               ",
    "            x   x               "
};

char mapafull[320][257] = {
/*0*/"                               1                               2                               3                               4                               5                               6                               7                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
/*1*/"                               1                               2                               3                               4                               5                               6                               7                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
/*2*/"                               1                               2                               3                               4                               5                               6                               7                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
/*3*/"                               1                               2                               3                               4                               5                               6                               7                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
/*4*/"                               1                               2                               3                               4                               5                               6                               7                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
/*5*/"                               1                               2                               3                               4                               5                               6                               7                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
/*6*/"                               1                               2                               3                               4                               5                               6                               7                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
/*7*/"                               1                               2                               3      x    x                   4|        x                  x  5                               6                               7                                ",
     "                                                                                                     x     x                    |       x                   x  |                                                                                                ",
     "                                                                                                     x      x                   |       x                  x   |                                                                                                ",
     "                                                                                                    x       x                   |      x                  x    |                                                                                                ",
     "                                                                                                    x        x xx xxx  xxxx     |  xxx x                 x     |                                                                                                ",
     "                                                                                                    x         x  x  x  x  x     |  x  x                 x      |                                                                                                ",
     "                                                                                                     x              x  x  x     |  x                    x      |                                                                                                ",
     "                                                                                                     x    xxxxxxxxx xxx    x    | x    xxxxxxxx         x      |                                                                                                ",
     "                                                                                                     x   x        x        x    | x   xXXXXXXXXx        x      |                                                                                                ",
     "                                                                                                      x   x       x         x   |x   xX        Xx       x      |                                                                                                ",
     "                                                                                                       x  x       xx        x xx|x   xX         Xx      x      |                                                                                                ",
     "                                                                                                      x    x        x        x  x    x x xxxxxx  Xx     x      |                                                                                                ",
     "                                                                                                      x    x        x           |    x x x    x  Xx      x     |                                                                                                ",
     "                                                                                                     x    x        x            |   x  x x    x  Xx       x    |                                                                                                ",
     "                                                                                                     x   x         x        xxxxxxxx  x  x    x  Xx       x    |                                                                                                ",
     "                                                                                                    x     x       x        xXXXXXXX  x   x xx x  Xx       x    |                                                                                                ",
     "                                                                                                   x    xx    xxx x       xX    |  xx    xxooxx  Xx       x    |                                                                                                ",
     "                                                                                                   x    x     x  x      xxX     |      aaa    aa Xx       x    |                                                                                                ",
     "                                                                                                    xx  x     x        xXX      |      aaa    aa Xx       x    |                                                                                                ",
     "                                                                                                     x xx     xx      xX        |                Xx        x   |                                                                                                ",
     "                                                                                                     x x       x xx   xX  X  X  |  X   X         Xx         x  |                                                                                                ",
     "                                                                                                    x  x       x xx    xXXX  XXXXXXX   XXXXXXXXXXXx          x |                                                                                                ",
     "                                                                                                    x  x xx xx x        x x  x  |  x   x         x            xx                                                                                                ",
     "                                                                                                    x   x  x  x          x    xxxxx     xxxxxxxxx              |                                                                                                ",
     "                                                                                                   x                            |                              |                                                                                                ",
     "                                                                                                  x                  x          |                              |                                                                                                ",
     "                                                                                                  x                 x x         |                              |                                                                                                ",
     "                                                                                                  xxxxx            x   x        |    xxx          xxxxxxxxxxxxxx                                                                                                ",
     "                                                                                                       x      xxxxx     xxxxxxxxxxxxx   xxxx     x             |                                                                                                ",
     "                                                                                                      x      x                  |           x   x              |                                                                                                ",
     "                                                                                                       xx   x                   |           x   x              |                                                                                                ",
     "                                                                                                        x   x                   |           x   x              |                                                                                                ",
/*8*/"                               1                               2                               3                               4                               5                               6                               7                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
/*9*/"                               1                               2                               3                               4                               5                               6                               7                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                ",
     "                                                                                                                                                                                                                                                                "
};

void initAllegro() {
    allegro_init();
    install_keyboard();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO, ALTO, 0, 0);
}

void cargaMapa() {
    for(int y = 0; y < MAXFILAS; y++) {
        for(int x = 0; x < MAXCOLS; x++) {
            mapa[y][x] = mapafull[mapaY*32 + y][mapaX*32 + x];
        }
    }
    rest(50);
}

void dibujaMapa(int A, int B) {
    blit(mapabmp, seccion, A, B, 0, 0, ANCHO, ALTO);
    draw_sprite(buffer, seccion, 0, 0);
    for(int y = 0; y <= MAXFILAS; y++) {
        for(int x = 0; x < MAXCOLS; x++) {
            rect(buffer, x*16, y*16, x*16+16, y*16+16, makecol(0, 0, 0));
            if(mapa[y][x] == 'x' || mapa[y][x] == 'X')
                rectfill(buffer, x*16, y*16, x*16+16, y*16+16, makecol(0, 0, 0));
        }
    }
}

int main() {
    initAllegro();

    mapaX = 4;
    mapaY = 7;
    cargaMapa();
    Link link(12, 17);
    Enemigo e(50,50);

    buffer = create_bitmap(ANCHO, ALTO);

    mapabmp = load_bitmap("mapa1.bmp", NULL);
    seccion = create_bitmap(512, 512);

    while(!key[KEY_ESC]) {
        clear(buffer);
        dibujaMapa((mapaX*512 + 2*mapaX), (mapaY*512 + mapaY*2));

        if(key[KEY_RIGHT]) {
            if((link.PX() + 1 == 32) && (mapaX + 1 <= 7)) {
                mapaX++;
                link.Posicion(0, link.PY());
                cargaMapa();
            }
            link.Mueve(0, mapa);
        }
        if(key[KEY_LEFT]) {
            if((link.PX() - 1 < 0) && (mapaX - 1 >= 0)) {
                mapaX--;
                link.Posicion(32, link.PY());
                cargaMapa();
            }
            link.Mueve(1, mapa);
        }
        if(key[KEY_DOWN]) {
            if((link.PY() + 1 == 32) && (mapaY + 1 <= 9)) {
                mapaY++;
                link.Posicion(link.PX(), 0);
                cargaMapa();
            }
            link.Mueve(2, mapa);
        }
        if(key[KEY_UP]) {
            if((link.PY() - 1 < 0) && (mapaY - 1 >= 0)) {
                mapaY--;
                link.Posicion(link.PX(), 31);
                cargaMapa();
            }
            link.Mueve(3, mapa);
        }
        if(key[KEY_SPACE]) {
            //link.Ataca(*buffer);
            if(!link.ataca)
                link.ataca = true;
        }

        //e.Mover(*buffer);
        link.Dibujar(*buffer);

        link.moviendo = false;
        rest(20);
     }

}
END_OF_MAIN();
