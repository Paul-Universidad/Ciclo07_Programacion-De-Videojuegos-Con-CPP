#include "JuegoPong.h"

int main() {
    JuegoPong juego;
    if (!juego.inicializar()) {
        return -1;
    }

    juego.ejecutar();
    return 0;
}