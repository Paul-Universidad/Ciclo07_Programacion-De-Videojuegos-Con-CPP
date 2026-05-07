#include "Raqueta.h"

Raqueta::Raqueta(float inicioX, float inicioY, float ancho, float alto, float velocidad, int teclaArriba, int teclaAbajo)
    : x(inicioX)
    , y(inicioY)
    , ancho(ancho)
    , alto(alto)
    , velocidad(velocidad)
    , teclaArriba(teclaArriba)
    , teclaAbajo(teclaAbajo)
{
}

void Raqueta::actualizar(const ALLEGRO_KEYBOARD_STATE& teclado, float limiteSuperior, float limiteInferior) {
    if (al_key_down(&teclado, teclaArriba)) {
        y -= velocidad;
    }
    if (al_key_down(&teclado, teclaAbajo)) {
        y += velocidad;
    }

    if (y < limiteSuperior) {
        y = limiteSuperior;
    }
    if (y + alto > limiteInferior) {
        y = limiteInferior - alto;
    }
}

void Raqueta::dibujar() const {
    ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
    al_draw_filled_rectangle(x, y, x + ancho, y + alto, color);
}

float Raqueta::getX() const {
    return x;
}

float Raqueta::getY() const {
    return y;
}

float Raqueta::getAncho() const {
    return ancho;
}

float Raqueta::getAlto() const {
    return alto;
}