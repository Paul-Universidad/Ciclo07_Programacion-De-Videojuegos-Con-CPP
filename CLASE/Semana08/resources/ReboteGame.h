#ifndef CONTADOR_GAME_H
#define CONTADOR_GAME_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h> 
#include "Cuadrado.h"

class ReboteGame {
private:
    // Punteros a recursos de Allegro
    ALLEGRO_DISPLAY* ventana;
    ALLEGRO_EVENT_QUEUE* cola_eventos;
    ALLEGRO_FONT* fuente;
    Cuadrado* cuadrado;

    // Estado del juego
    int contador;
    bool running;

    // Qué partes de Allegro llegaron a activarse (para cerrar en orden si falla inicializar)
    bool addon_font_activo_;
    bool addon_ttf_activo_;
    bool addon_primitives_activo_;
    bool teclado_instalado_;

    // Métodos privados de soporte
    void actualizar();
    void dibujar();
    void procesarEntrada(); 

public:
    ReboteGame();  // Constructor
    ~ReboteGame(); // Destructor
    
    bool inicializar();
    void ejecutar();
};

#endif