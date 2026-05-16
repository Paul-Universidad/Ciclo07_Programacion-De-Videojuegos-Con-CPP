#include "Pelota.h"
#include <cmath>
#include <cstdlib>

const double Pelota::VELOCIDAD_INICIAL = 6.0;
const double Pelota::VELOCIDAD_MIN = 0.5;
const double Pelota::VELOCIDAD_MAX = 35.0;
const double Pelota::ACELERACION = 2.5;

Pelota::Pelota()
    : radio(40)
    , angulo((std::rand() % 628) / 100.0)
    , velocidad(VELOCIDAD_INICIAL)
    , color_pelota(al_map_rgb(std::rand() % 255, std::rand() % 255, std::rand() % 255))
{
    const int margen = radio * 2;
    pos_x = radio + std::rand() % (ANCHO_VENTANA - margen);
    pos_y = radio + std::rand() % (ALTO_VENTANA - margen);
}

Pelota::~Pelota() {}

void Pelota::mover() {
    pos_x += std::cos(angulo) * velocidad;
    pos_y += std::sin(angulo) * velocidad;
}

void Pelota::rebote() {
    if (pos_y <= radio || pos_y >= ALTO_VENTANA - radio) {
        angulo = -angulo;
        if (pos_y < radio) pos_y = radio;
        if (pos_y > ALTO_VENTANA - radio) pos_y = ALTO_VENTANA - radio;
    }
    if (pos_x <= radio || pos_x >= ANCHO_VENTANA - radio) {
        angulo = ALLEGRO_PI - angulo;
        if (pos_x < radio) pos_x = radio;
        if (pos_x > ANCHO_VENTANA - radio) pos_x = ANCHO_VENTANA - radio;
    }
}

void Pelota::fijarDireccionDesdeFlechas(int dx, int dy) {
    if (dx == 0 && dy == 0) {
        return;
    }
    if (dx < -1) dx = -1;
    if (dx > 1) dx = 1;
    if (dy < -1) dy = -1;
    if (dy > 1) dy = 1;
    angulo = std::atan2(static_cast<double>(dy), static_cast<double>(dx));
}

void Pelota::acelerar() {
    velocidad += ACELERACION;
    if (velocidad > VELOCIDAD_MAX) velocidad = VELOCIDAD_MAX;
}

void Pelota::desacelerar() {
    velocidad -= ACELERACION;
    if (velocidad < VELOCIDAD_MIN) velocidad = VELOCIDAD_MIN;
}
