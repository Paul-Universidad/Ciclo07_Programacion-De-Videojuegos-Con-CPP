#ifndef CUADRO_H
#define CUADRO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Cuadro {
private:
    float x, y;
    float tamano;
    float velocidad;

public:
    Cuadro();

    void actualizar();
    void dibujar();
};

#endif