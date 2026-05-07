#ifndef JUEGOPONG_H
#define JUEGOPONG_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "Raqueta.h"
#include "Pelota.h"

class JuegoPong {
public:
    JuegoPong();
    ~JuegoPong();

    bool inicializar();
    void ejecutar();

private:
    static const int ANCHO_VENTANA = 800;
    static const int ALTO_VENTANA = 600;
    static const int LIMITE_IZQUIERDO = 20;
    static const int LIMITE_DERECHO = ANCHO_VENTANA - 20;
    static const int LIMITE_SUPERIOR = 20;
    static const int LIMITE_INFERIOR = ALTO_VENTANA - 20;

    // Zonas de gol (arcos)
    static const int GOL_IZQUIERDO_Y_INICIO = 200;
    static const int GOL_IZQUIERDO_Y_FIN = 400;
    static const int GOL_DERECHO_Y_INICIO = 200;
    static const int GOL_DERECHO_Y_FIN = 400;

    ALLEGRO_DISPLAY* ventana;
    ALLEGRO_FONT* fuente;
    ALLEGRO_EVENT_QUEUE* cola_eventos;
    Raqueta raquetaIzquierda;
    Raqueta raquetaDerecha;
    Pelota pelota;
    int puntuacionIzquierda;
    int puntuacionDerecha;
    bool running;

    void procesarEvento(const ALLEGRO_EVENT& evento);
    void actualizarEstado();
    void dibujarEscena();
    void limpiar();
};

#endif // JUEGOPONG_H