#include "Cuadro.h"

Cuadro::Cuadro() {
    x = 375;
    y = 275;
    tamano = 50;
    velocidad = 5;
}

void Cuadro::actualizar() {
    ALLEGRO_KEYBOARD_STATE estado;
    al_get_keyboard_state(&estado);

    if (al_key_down(&estado, ALLEGRO_KEY_UP)) y -= velocidad;
    if (al_key_down(&estado, ALLEGRO_KEY_DOWN)) y += velocidad;
    if (al_key_down(&estado, ALLEGRO_KEY_LEFT)) x -= velocidad;
    if (al_key_down(&estado, ALLEGRO_KEY_RIGHT)) x += velocidad;
}

void Cuadro::dibujar() {
    ALLEGRO_COLOR morado = al_map_rgb(128, 0, 128);
    al_draw_filled_rectangle(x, y, x + tamano, y + tamano, morado);
}