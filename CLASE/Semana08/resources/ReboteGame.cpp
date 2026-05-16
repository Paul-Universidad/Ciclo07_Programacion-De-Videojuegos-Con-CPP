#include "ReboteGame.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>

ReboteGame::ReboteGame() : ventana(nullptr)
                             , cola_eventos(nullptr)
                             , fuente(nullptr)
                             , pelota(nullptr)
                             , contador(0)
                             , running(true) {}

bool ReboteGame::inicializar() {
    if (!al_init()) {
        printf("Error: No se pudo inicializar Allegro\n");
        return false;
    }
    if (!al_init_font_addon()) {
        printf("Error: No se pudo inicializar font addon\n");
        return false;
    }
    if (!al_init_ttf_addon()) {
        printf("Error: No se pudo inicializar ttf addon\n");
        return false;
    }
    if (!al_init_primitives_addon()) {
        printf("Error: No se pudo inicializar primitives addon\n");
        return false;
    }
    al_install_keyboard();
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    ventana = al_create_display(800, 600);
    if (!ventana) {
        printf("Error: No se pudo crear la ventana\n");
        return false;
    }
    
    al_set_window_title(ventana, "Juego de Rebote");  // ← Añade título

    fuente = al_load_ttf_font("arial.ttf", 48, 0);
    if (!fuente) {
        printf("Advertencia: No se pudo cargar arial.ttf, usando fuente por defecto\n");
        fuente = al_create_builtin_font();
    }

    cola_eventos = al_create_event_queue();
    al_register_event_source(cola_eventos, al_get_keyboard_event_source());
    al_register_event_source(cola_eventos, al_get_display_event_source(ventana));
    
    pelota = new Pelota();
    
    printf("Inicialización exitosa!\n");  // ← Mensaje de éxito
    return (cola_eventos != nullptr);
}

void ReboteGame::procesarEntrada() {
    ALLEGRO_EVENT evento;
    while (al_get_next_event(cola_eventos, &evento)) {
        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }
    }

    ALLEGRO_KEYBOARD_STATE teclas;
    al_get_keyboard_state(&teclas);

    int flecha_dx = 0;
    int flecha_dy = 0;
    if (al_key_down(&teclas, ALLEGRO_KEY_LEFT)) {
        flecha_dx -= 1;
    }
    if (al_key_down(&teclas, ALLEGRO_KEY_RIGHT)) {
        flecha_dx += 1;
    }
    if (al_key_down(&teclas, ALLEGRO_KEY_UP)) {
        flecha_dy -= 1;
    }
    if (al_key_down(&teclas, ALLEGRO_KEY_DOWN)) {
        flecha_dy += 1;
    }
    pelota->fijarDireccionDesdeFlechas(flecha_dx, flecha_dy);
    if (al_key_down(&teclas, ALLEGRO_KEY_LSHIFT) || al_key_down(&teclas, ALLEGRO_KEY_RSHIFT)) {
        pelota->acelerar();
    }
    if (al_key_down(&teclas, ALLEGRO_KEY_Z)) {
        pelota->desacelerar();
    }
}

void ReboteGame::actualizar() {
    pelota->mover();
    pelota->rebote();
}

void ReboteGame::dibujar() {
    al_clear_to_color(al_map_rgb(20, 20, 20)); // Un gris oscuro
    al_draw_filled_circle( pelota->getX()
                         , pelota->getY()
                         , pelota->getRadio()
                         , pelota->getColor() );
    al_flip_display();
}

void ReboteGame::ejecutar() {
    while (running) {
        procesarEntrada();
        actualizar();
        dibujar();
        al_rest(0.016);
    }
}

ReboteGame::~ReboteGame() {
    delete pelota;
    if (fuente) al_destroy_font(fuente);
    if (cola_eventos) al_destroy_event_queue(cola_eventos);
    if (ventana) al_destroy_display(ventana);
}