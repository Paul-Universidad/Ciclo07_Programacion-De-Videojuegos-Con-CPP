#include "Pelota.h"
#include <cmath>
#include <cstdlib>

Pelota::Pelota(float radio, float velocidad)
    : x(0)
    , y(0)
    , radio(radio)
    , dx(1.0f)
    , dy(0.0f)
    , velocidad(velocidad)
{
}

void Pelota::reiniciar(int puntuacionIzq, int puntuacionDer, float anchoVentana, float altoVentana) {
    x = anchoVentana / 2.0f;
    y = altoVentana / 2.0f;
    velocidad = 7.5f;

    float angulo = (std::rand() % 120 + 30) * ALLEGRO_PI / 180.0f;
    if (puntuacionIzq > puntuacionDer) {
        dx = std::cos(angulo);
    } else if (puntuacionDer > puntuacionIzq) {
        dx = -std::cos(angulo);
    } else {
        dx = (std::rand() % 2 == 0) ? 1.0f : -1.0f;
    }
    dy = std::sin(angulo);
}

void Pelota::actualizar(const Raqueta& izquierda, const Raqueta& derecha, float limiteSuperior, float limiteInferior) {
    x += dx * velocidad;
    y += dy * velocidad;

    if (y - radio < limiteSuperior) {
        y = limiteSuperior + radio;
        dy = -dy;
    }
    if (y + radio > limiteInferior) {
        y = limiteInferior - radio;
        dy = -dy;
    }

    float izquierdaDerecha = izquierda.getX() + izquierda.getAncho();
    if (x - radio < izquierdaDerecha && x - radio > izquierda.getX() && y > izquierda.getY() && y < izquierda.getY() + izquierda.getAlto()) {
        x = izquierdaDerecha + radio;
        dx = -dx;
    }

    float derechaIzquierda = derecha.getX();
    if (x + radio > derechaIzquierda && x + radio < derechaIzquierda + derecha.getAncho() && y > derecha.getY() && y < derecha.getY() + derecha.getAlto()) {
        x = derechaIzquierda - radio;
        dx = -dx;
    }
}

void Pelota::dibujar() const {
    ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
    al_draw_filled_circle(x, y, radio, color);
}

float Pelota::getX() const {
    return x;
}

float Pelota::getY() const {
    return y;
}

float Pelota::getRadio() const {
    return radio;
}