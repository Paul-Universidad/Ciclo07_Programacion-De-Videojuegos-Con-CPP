#include "Cuadro.h"
#include <cstdlib>

Cuadro::Cuadro() {
    x = 375;
    y = 275;
    tamano = 50;
    velocidad = 5;
    color = al_map_rgb(255, 0, 0);
    prev_dx = 0;
    prev_dy = 0;
}

void Cuadro::actualizar() {
    ALLEGRO_KEYBOARD_STATE estado;
    al_get_keyboard_state(&estado);

    int dx = 0;
    int dy = 0;
    if (al_key_down(&estado, ALLEGRO_KEY_UP)) dy -= 1;
    if (al_key_down(&estado, ALLEGRO_KEY_DOWN)) dy += 1;
    if (al_key_down(&estado, ALLEGRO_KEY_LEFT)) dx -= 1;
    if (al_key_down(&estado, ALLEGRO_KEY_RIGHT)) dx += 1;

    if ((dx != prev_dx || dy != prev_dy) && (dx != 0 || dy != 0)) {
        color = al_map_rgb(rand() % 256, rand() % 256, rand() % 256);
    }
    prev_dx = dx;
    prev_dy = dy;

    if (al_key_down(&estado, ALLEGRO_KEY_UP)) y -= velocidad;
    if (al_key_down(&estado, ALLEGRO_KEY_DOWN)) y += velocidad;
    if (al_key_down(&estado, ALLEGRO_KEY_LEFT)) x -= velocidad;
    if (al_key_down(&estado, ALLEGRO_KEY_RIGHT)) x += velocidad;
}

void Cuadro::dibujar() {
    al_draw_filled_rectangle(x, y, x + tamano, y + tamano, color);
}