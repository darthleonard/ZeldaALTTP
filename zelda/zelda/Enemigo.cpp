#include "Enemigo.h"

Enemigo::Enemigo(int _x, int _y) {
    x = _x;
    y = _y;
    dir = 0;

    ancho = 16;
    alto = 24;

    linksprite = load_bitmap("link1.bmp", NULL);
    linkimg = create_bitmap(ancho, alto);
}

void Enemigo::Mover(BITMAP &buffer) {
    if( x < 300) x++; else if (x > 200) x--;
    if(img_index <= 6) img_index++; else img_index = 0;
    blit(linksprite, linkimg, img_index*ancho, 0, 0, 0, ancho, alto);
    draw_sprite(&buffer, linkimg, x, y);
    //blit(&buffer, screen, 0,0,0,0, 600, 600);
    blit(&buffer, screen, x, y, x ,y, ancho, alto);

}


