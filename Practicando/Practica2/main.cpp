#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Cuadro.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    if (!al_init()) {
        std::cout << "Error al iniciar Allegro\n";
        return -1;
    }

    al_install_keyboard();
    al_init_primitives_addon();

    ALLEGRO_DISPLAY* ventana = al_create_display(800, 600);
    if (!ventana) {
        std::cout << "Error al crear ventana\n";
        return -1;
    }

    ALLEGRO_EVENT_QUEUE* cola_eventos = al_create_event_queue();
    al_register_event_source(cola_eventos, al_get_display_event_source(ventana));
    al_register_event_source(cola_eventos, al_get_keyboard_event_source());

    bool running = true;

    Cuadro cuadro;

    while (running) {
        ALLEGRO_EVENT evento;

        while (al_get_next_event(cola_eventos, &evento)) {
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                running = false;
            }
        }

        cuadro.actualizar();

        al_clear_to_color(al_map_rgb(20, 20, 20));

        cuadro.dibujar();

        al_flip_display();

        al_rest(0.016); // aprox 60 FPS
    }

    al_destroy_event_queue(cola_eventos);
    al_destroy_display(ventana);

    return 0;
}