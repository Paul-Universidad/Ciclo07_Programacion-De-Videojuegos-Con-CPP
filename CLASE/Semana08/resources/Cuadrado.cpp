#include "Cuadrado.h"
#include <cmath>
#include <cstdlib>

const double Cuadrado::VELOCIDAD_INICIAL = 6.0;
const double Cuadrado::VELOCIDAD_MIN = 0.5;
const double Cuadrado::VELOCIDAD_MAX = 35.0;
const double Cuadrado::ACELERACION = 2.5;

Cuadrado::Cuadrado()
    : lado(80)
    , velocidad(VELOCIDAD_INICIAL)
    , color_cuadrado(al_map_rgb(std::rand() % 255, std::rand() % 255, std::rand() % 255))
{
    double rx;
    double ry;
    double len = 0.0;
    do {
        rx = (std::rand() / (static_cast<double>(RAND_MAX) + 1.0)) * 2.0 - 1.0;
        ry = (std::rand() / (static_cast<double>(RAND_MAX) + 1.0)) * 2.0 - 1.0;
        len = std::hypot(rx, ry);
    } while (len < 1e-6);
    dir_x = rx / len;
    dir_y = ry / len;
    const int mitad = lado / 2;
    pos_x = mitad + std::rand() % (ANCHO_VENTANA - lado);
    pos_y = mitad + std::rand() % (ALTO_VENTANA - lado);
}

Cuadrado::~Cuadrado() {}

void Cuadrado::mover() {
    pos_x += dir_x * velocidad;
    pos_y += dir_y * velocidad;
}

void Cuadrado::rebote() {
    const double mitad = lado / 2.0;
    if (pos_y <= mitad || pos_y >= ALTO_VENTANA - mitad) {
        dir_y = -dir_y;
        if (pos_y < mitad) pos_y = mitad;
        if (pos_y > ALTO_VENTANA - mitad) pos_y = ALTO_VENTANA - mitad;
    }
    if (pos_x <= mitad || pos_x >= ANCHO_VENTANA - mitad) {
        dir_x = -dir_x;
        if (pos_x < mitad) pos_x = mitad;
        if (pos_x > ANCHO_VENTANA - mitad) pos_x = ANCHO_VENTANA - mitad;
    }
}

void Cuadrado::fijarDireccionDesdeFlechas(int dx, int dy) {
    if (dx == 0 && dy == 0) {
        return;
    }
    if (dx < -1) dx = -1;
    if (dx > 1) dx = 1;
    if (dy < -1) dy = -1;
    if (dy > 1) dy = 1;

    const double len = std::hypot(static_cast<double>(dx), static_cast<double>(dy));
    dir_x = static_cast<double>(dx) / len;
    dir_y = static_cast<double>(dy) / len;
}

void Cuadrado::acelerar() {
    velocidad += ACELERACION;
    if (velocidad > VELOCIDAD_MAX) velocidad = VELOCIDAD_MAX;
}

void Cuadrado::desacelerar() {
    velocidad -= ACELERACION;
    if (velocidad < VELOCIDAD_MIN) velocidad = VELOCIDAD_MIN;
}
