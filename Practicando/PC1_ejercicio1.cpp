#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(){
    const int WINDOW_WIDTH = 850;
    const int WINDOW_HEIGHT = 650;
    const int CENTER_X = WINDOW_WIDTH / 2;   // 425
    const int CENTER_Y = WINDOW_HEIGHT / 2;  // 325
    const int CIRCLE_RADIUS = 30;
    const float RADIO_Rectangulo=15;


    ALLEGRO_DISPLAY *display = NULL;
    
    // Inicializar Allegro
    if (!al_init()) {
        return -1;
    }
    
    // Inicializar el addon de primitivas (necesario para dibujar formas)
    if (!al_init_primitives_addon()) {
        return -1;
    }
    
    // Crear la ventana
    display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!display) {
        return -1;
    }
    
    // DEFINIR COLORES
    ALLEGRO_COLOR color_negro = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR color_rojo = al_map_rgb(255, 0, 0);
    ALLEGRO_COLOR color_verde = al_map_rgb(0, 255, 0);
    ALLEGRO_COLOR color_azul = al_map_rgb(0, 0, 255);
    ALLEGRO_COLOR color_amarillo = al_map_rgb(255, 255, 0);
    ALLEGRO_COLOR color_cyan = al_map_rgb(0, 255, 255);
    ALLEGRO_COLOR color_magenta = al_map_rgb(255, 0, 255);
    ALLEGRO_COLOR color_blanco = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR color_gris = al_map_rgb(128, 128, 128);

    
    
    // RENDERIZADO
    al_clear_to_color(color_negro);

    // Rectangulos azules
    al_draw_rectangle(410,60,440,590,color_azul,2.0);
    al_draw_rectangle(60,310,790,340,color_azul,2.0);

    // Lineas celestes/cyan
    al_draw_line(60, 60, 390, 290, color_cyan, 2.0); // linea 1
    al_draw_line(790, 60, 390+70, 290, color_cyan, 2.0); // linea 2
    al_draw_line(60, 590, 390, 360, color_cyan, 2.0); // linea 3
    al_draw_line(790, 590, 460, 350, color_cyan, 2.0); // linea 4

    // 1. CÍRCULO 
    al_draw_filled_circle(CENTER_X, CENTER_Y, CIRCLE_RADIUS, color_rojo);

    // Rectangulo con border redondeados    
    al_draw_rounded_rectangle(50,50,800,600,RADIO_Rectangulo,RADIO_Rectangulo,color_gris,2.0);
    
    // Rectangulo pequenio del centro
    al_draw_rectangle(390, 290, 460, 360, color_blanco, 2.0);

     // Mostrar todo
    al_flip_display();
    
    // Mantener la ventana abierta por 15 segundos
    al_rest(15.0);
    
    // Limpiar recursos
    al_destroy_display(display);
    
    return 0;
}