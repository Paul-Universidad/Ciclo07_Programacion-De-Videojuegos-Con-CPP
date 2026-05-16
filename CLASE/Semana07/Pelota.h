#ifndef PELOTA_H
#define PELOTA_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Raqueta.h"

class Pelota {
private:
    float x;
    float y;
    float radio;
    float dx;
    float dy;
    float velocidad;

public:
    Pelota(float radio, float velocidad);

    void reiniciar(int puntuacionIzq, int puntuacionDer, float anchoVentana, float altoVentana);
    void actualizar(const Raqueta& izquierda, const Raqueta& derecha, float limiteSuperior, float limiteInferior);
    void dibujar() const;

    float getX() const;
    float getY() const;
    float getRadio() const;
};

#endif // PELOTA_H