#ifndef CUADRADO_H
#define CUADRADO_H

#include <allegro5/allegro.h>

class Cuadrado {
private:
    static const int ANCHO_VENTANA = 800;
    static const int ALTO_VENTANA = 600;

    double pos_x;
    double pos_y;
    int lado;
    double dir_x;
    double dir_y;
    double velocidad;
    ALLEGRO_COLOR color_cuadrado;

    static const double VELOCIDAD_INICIAL;
    static const double VELOCIDAD_MIN;
    static const double VELOCIDAD_MAX;
    static const double ACELERACION;

public:
    Cuadrado();
    ~Cuadrado();

    void mover();
    void rebote();
    void fijarDireccionDesdeFlechas(int dx, int dy);
    void acelerar();
    void desacelerar();

    double getX() { return pos_x; }
    double getY() { return pos_y; }
    int getLado() { return lado; }
    ALLEGRO_COLOR getColor() { return color_cuadrado; }
};

#endif
