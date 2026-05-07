#ifndef CUADRO_H
#define CUADRO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Cuadro {
private:
    float x, y;
    float tamano;
    float velocidad;
    ALLEGRO_COLOR color;
    int prev_dx;
    int prev_dy;

public:
    Cuadro();
    void actualizar();
    void dibujar();
    
};

#endif