#include "ReboteGame.h"
#include <iostream>

int main() {
    // 1. Instanciamos el objeto (se llama al constructor)
    ReboteGame miJuego;

    // 2. Preparamos el entorno
    if (!miJuego.inicializar()) {
        std::cerr << "Error crítico: No se pudo inicializar Allegro o sus recursos." << std::endl;
        return -1;
    }

    // 3. Arrancamos el Game Loop
    miJuego.ejecutar();

    // Al terminar la función, el objeto 'miJuego' se destruye
    // automáticamente llamando al destructor ~ContadorGame().
    return 0;
}