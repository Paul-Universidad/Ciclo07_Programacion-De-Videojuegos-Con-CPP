#ifndef PELOTA_H
#define PELOTA_H

#include <allegro5/allegro.h>

class Pelota {
private:
    static const int ANCHO_VENTANA = 800;
    static const int ALTO_VENTANA = 600;

    double pos_x;
    double pos_y;
    int radio;
    double angulo;
    double velocidad;
    ALLEGRO_COLOR color_pelota;

    static const double VELOCIDAD_INICIAL;
    static const double VELOCIDAD_MIN;
    static const double VELOCIDAD_MAX;
    static const double ACELERACION;

public:
    Pelota();
    ~Pelota();

    void mover();
    void rebote();
    void fijarDireccionDesdeFlechas(int dx, int dy);
    void acelerar();
    void desacelerar();

    double getX() { return pos_x; }
    double getY() { return pos_y; }
    int getRadio() { return radio; }
    ALLEGRO_COLOR getColor() { return color_pelota; }
};

#endif
