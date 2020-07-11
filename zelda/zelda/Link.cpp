#include "Link.h"
#include <stdio.h>

#define D_VENTANA 512

Link::Link(int _x, int _y) {
    x = _x*16;
    y = _y*16;
    ancho = 16;
    alto = 24;

    dx = ancho / 2;
    dy = alto / 2;

    px = (x / (D_VENTANA/33));
    py = (y / (D_VENTANA/32));

    dir = 2;
    img_index = 3;
    vel = 3;

    linksprite = load_bitmap("link1.bmp", NULL);
    linkimg = create_bitmap(ancho, alto);
}

void Link::Mueve(int _dir, char mapa[32][33]) {
    dir = _dir;
    moviendo = true;

    switch(dir) {
        case 0: // derecha
            x = ((mapa[py][px+1] == 'x' && x+dx >= (px + 1)*16) || (px+1 >= 32)) ? x : x + vel;
            break;
        case 1: // izquierda
            x = ((mapa[py][px-1] == 'x' && x <= px*16 + dx) || (px-1 < 0)) ? x : x - vel;
            break;
        case 2: // abajo
            y = ((mapa[py+1][px] == 'x' ) || (py >= 32)) ? y : y + vel;
            break;
        case 3: // arriba
            y = ((mapa[py-1][px] == 'x' && y+dy <= py*16+16 ) || (py <= 0)) ? y : y - vel;
            break;
    }

    px = (x / (D_VENTANA/32));
    py = (y / (D_VENTANA/32));
    //mapa[py][px] = '1';

    printf("(%d,%d) (%d,%d) (%d,%d)\n", x, y+dy, px*16, py*16+16, px, py);
    if(mapa[py][px] == 'o')
        printf("puerta\n");
}

void Link::Dibujar(BITMAP &buffer) {
    if(moviendo || ataca) {
        img_index++;
        if(img_index > 6)
            img_index = 0;
        if(ataca && img_index == 6)
            ataca = false;
    }else {
        img_index = 3;
    }

    if(ataca) {
        blit(linksprite, linkimg, img_index*ancho, 4*alto+1, 0, 0, ancho, alto);
    }else
        blit(linksprite, linkimg, img_index*ancho, dir*alto+1, 0, 0, ancho, alto);

    //blit(linksprite, linkimg, img_index*ancho, dir*alto+1, 0, 0, ancho, alto);
    draw_sprite(&buffer, linkimg, x-dx, y-dy);
    blit(&buffer, screen, 0, 0, 0, 0, buffer.w, buffer.h);
}

void Link::Ataca(BITMAP &buffer) {
    /*BITMAP *tmp = create_bitmap(ancho, alto);

    BITMAP *spriteaux = load_bitmap("ataca.bmp", NULL);
    linkimg = create_bitmap(28, 33);
    printf("ataca");
    for(int i = 0; i < 7; i++) {
        //clear(linkimg);
        blit(spriteaux, linkimg, i*28, 0, 0, 0, 28, 33);
        draw_sprite(&buffer, linkimg, x-dx, y-dy);
        blit(&buffer, screen, 0, 0, 0, 0, buffer.w, buffer.h);
        rest(10);
    }
    printf("\n");
    linkimg = tmp;*/
}

int Link::Arma(int _arma) {
    arma = (arma >= 0) ? _arma : 0;
}

int Link::Ancho() {
    return ancho;
}

int Link::Alto() {
    return alto;
}

int Link::X() {
    return x;
}

int Link::Y() {
    return y;
}

int Link::PX() {
    return px;
}

int Link::PY() {
    return py;
}

void Link::Posicion(int _x, int _y) {
    x = _x * 16;
    y = _y * 16;
    px = (x / (D_VENTANA/32));
    py = (y / (D_VENTANA/32));
}

BITMAP* Link::Sprite() {
    return linksprite;
}

BITMAP* Link::Image() {
    blit(linksprite, linkimg, dir*ancho, 0, 0, 0, ancho, alto);
    return linkimg;
}
