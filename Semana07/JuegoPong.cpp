#include "JuegoPong.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

JuegoPong::JuegoPong()
    : ventana(nullptr)
    , fuente(nullptr)
    , cola_eventos(nullptr)
    , raquetaIzquierda(LIMITE_IZQUIERDO + 10.0f, ALTO_VENTANA / 2.0f - 60.0f, 15.0f, 120.0f, 5.5f, ALLEGRO_KEY_W, ALLEGRO_KEY_S)
    , raquetaDerecha(LIMITE_DERECHO - 25.0f, ALTO_VENTANA / 2.0f - 60.0f, 15.0f, 120.0f, 5.5f, ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN)
    , pelota(10.0f, 5.5f)
    , puntuacionIzquierda(0)
    , puntuacionDerecha(0)
    , running(false)
{
}

JuegoPong::~JuegoPong() {
    limpiar();
}

bool JuegoPong::inicializar() {
    if (!al_init()) {
        std::cout << "Error al iniciar Allegro\n";
        return false;
    }

    al_install_keyboard();
    al_init_primitives_addon();
    al_init_font_addon();

    ventana = al_create_display(ANCHO_VENTANA, ALTO_VENTANA);
    if (!ventana) {
        std::cout << "Error al crear la ventana\n";
        return false;
    }

    fuente = al_create_builtin_font();
    if (!fuente) {
        std::cout << "Error al crear la fuente\n";
        return false;
    }

    cola_eventos = al_create_event_queue();
    if (!cola_eventos) {
        std::cout << "Error al crear la cola de eventos\n";
        return false;
    }

    al_register_event_source(cola_eventos, al_get_display_event_source(ventana));
    al_register_event_source(cola_eventos, al_get_keyboard_event_source());

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    pelota.reiniciar(puntuacionIzquierda, puntuacionDerecha, ANCHO_VENTANA, ALTO_VENTANA);

    running = true;
    return true;
}

void JuegoPong::ejecutar() {
    while (running) {
        ALLEGRO_EVENT evento;
        while (al_get_next_event(cola_eventos, &evento)) {
            procesarEvento(evento);
        }

        actualizarEstado();
        dibujarEscena();
        al_rest(0.016);
    }
}

void JuegoPong::procesarEvento(const ALLEGRO_EVENT& evento) {
    if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        running = false;
    }
}

void JuegoPong::actualizarEstado() {
    ALLEGRO_KEYBOARD_STATE teclado;
    al_get_keyboard_state(&teclado);

    raquetaIzquierda.actualizar(teclado, LIMITE_SUPERIOR, LIMITE_INFERIOR);
    raquetaDerecha.actualizar(teclado, LIMITE_SUPERIOR, LIMITE_INFERIOR);
    pelota.actualizar(raquetaIzquierda, raquetaDerecha, LIMITE_SUPERIOR, LIMITE_INFERIOR);

    // Verificar si la pelota sale por el lado izquierdo (gol para derecha)
    if (pelota.getX() - pelota.getRadio() < LIMITE_IZQUIERDO) {
        if (pelota.getY() >= GOL_IZQUIERDO_Y_INICIO && pelota.getY() <= GOL_IZQUIERDO_Y_FIN) {
            puntuacionDerecha += 1;
        }
        pelota.reiniciar(puntuacionIzquierda, puntuacionDerecha, ANCHO_VENTANA, ALTO_VENTANA);
    }
    // Verificar si la pelota sale por el lado derecho (gol para izquierda)
    if (pelota.getX() + pelota.getRadio() > LIMITE_DERECHO) {
        if (pelota.getY() >= GOL_DERECHO_Y_INICIO && pelota.getY() <= GOL_DERECHO_Y_FIN) {
            puntuacionIzquierda += 1;
        }
        pelota.reiniciar(puntuacionIzquierda, puntuacionDerecha, ANCHO_VENTANA, ALTO_VENTANA);
    }
}

void JuegoPong::dibujarEscena() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    ALLEGRO_COLOR blanco = al_map_rgb(255, 255, 255);
    al_draw_rectangle(LIMITE_IZQUIERDO, LIMITE_SUPERIOR, LIMITE_DERECHO, LIMITE_INFERIOR, blanco, 3);
    al_draw_line(ANCHO_VENTANA / 2.0f, LIMITE_SUPERIOR, ANCHO_VENTANA / 2.0f, LIMITE_INFERIOR, blanco, 2);

    // Dibujar arcos (zonas de gol)
    ALLEGRO_COLOR rojo = al_map_rgb(255, 0, 0);
    al_draw_filled_rectangle(LIMITE_IZQUIERDO - 10, GOL_IZQUIERDO_Y_INICIO, LIMITE_IZQUIERDO, GOL_IZQUIERDO_Y_FIN, rojo);
    al_draw_filled_rectangle(LIMITE_DERECHO, GOL_DERECHO_Y_INICIO, LIMITE_DERECHO + 10, GOL_DERECHO_Y_FIN, rojo);

    raquetaIzquierda.dibujar();
    raquetaDerecha.dibujar();
    pelota.dibujar();

    al_draw_textf(fuente, blanco, ANCHO_VENTANA / 4.0f, 5.0f, ALLEGRO_ALIGN_CENTER, "%d", puntuacionIzquierda);
    al_draw_textf(fuente, blanco, ANCHO_VENTANA * 3.0f / 4.0f, 5.0f, ALLEGRO_ALIGN_CENTER, "%d", puntuacionDerecha);

    al_flip_display();
}

void JuegoPong::limpiar() {
    if (cola_eventos) {
        al_destroy_event_queue(cola_eventos);
        cola_eventos = nullptr;
    }
    if (ventana) {
        al_destroy_display(ventana);
        ventana = nullptr;
    }
    if (fuente) {
        al_destroy_font(fuente);
        fuente = nullptr;
    }
    al_shutdown_font_addon();
    al_shutdown_primitives_addon();
}