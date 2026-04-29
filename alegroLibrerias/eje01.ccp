#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

int main()
{
    printf("Iniciando programa...\n");

    if (!al_init()) {
        fprintf(stderr, "Error al inicializar Allegro.\n");
        return -1;
    }

    printf("Allegro inicializado correctamente.\n");

    if (!al_init_primitives_addon()) {
        fprintf(stderr, "Error al inicializar el addon de primitivas.\n");
        return -1;
    }

    printf("Addon de primitivas inicializado.\n");

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    al_set_new_display_flags(ALLEGRO_OPENGL);

    ALLEGRO_DISPLAY *display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!display) {
        fprintf(stderr, "Error: no se pudo crear el display.\n");
        return -1;
    }

    printf("Ventana creada correctamente.\n");

    ALLEGRO_COLOR negro = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR rojo = al_map_rgb(255, 0, 0);

    al_clear_to_color(negro);
    al_draw_filled_circle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 50, rojo);
    al_flip_display();

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    al_register_event_source(queue, al_get_display_event_source(display));

    bool running = true;

    while (running) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }
    }

    al_destroy_event_queue(queue);
    al_destroy_display(display);
    al_shutdown_primitives_addon();

    printf("Programa finalizado correctamente.\n");

    return 0;
}