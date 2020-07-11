#ifndef LINK_H
#define LINK_H

#include <allegro.h>

class Link {
    int x;
    int y;
    int px;
    int py;
    int dx;
    int dy;
    int alto;
    int ancho;
    int dir;
    int vel;
    int img_index;

    int arma;

    BITMAP *linksprite;
    BITMAP *linkimg;

    public:
        bool moviendo;
        bool ataca;

        Link(int _x, int _y);
        void Mueve(int _dir, char mapa[32][33]);
        void Dibujar(BITMAP &buffer);
        BITMAP* Sprite();
        BITMAP* Image();
        int X();
        int Y();
        int PX();
        int PY();
        void Posicion(int _x, int _y);
        int Alto();
        int Ancho();

        void Ataca(BITMAP &buffer);
        int Arma(int arma);
};

#endif // LINK_H
