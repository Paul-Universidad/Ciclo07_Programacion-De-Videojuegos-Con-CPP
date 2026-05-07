#ifndef RAQUETA_H
#define RAQUETA_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Raqueta {
private:
    float x;
    float y;
    float ancho;
    float alto;
    float velocidad;
    int teclaArriba;
    int teclaAbajo;

public:
    Raqueta(float inicioX, float inicioY, float ancho, float alto, float velocidad, int teclaArriba, int teclaAbajo);

    void actualizar(const ALLEGRO_KEYBOARD_STATE& teclado, float limiteSuperior, float limiteInferior);
    void dibujar() const;

    float getX() const;
    float getY() const;
    float getAncho() const;
    float getAlto() const;
};

#endif // RAQUETA_H