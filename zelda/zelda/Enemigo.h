#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <allegro.h>


class Enemigo {
    BITMAP *linksprite;
    BITMAP *linkimg;
    int x;
    int y;
    int alto;
    int ancho;
    int dir;
    int img_index;

    public:
        Enemigo(int _x, int _y);
        void Mover(BITMAP &buffer);
};

#endif // ENEMIGO_H
