#pragma once
#include "Enemigo.h"

class EnemigoAlgoritmo : public Enemigo {
private:
    int contadorDisparo;
public:
    EnemigoAlgoritmo(int px, float py) : Enemigo(px, py, 1, 0, 3, 13, "algoritmo"), contadorDisparo(0) {}
    void borrar() override {
        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x_anterior, int(y_anterior) + i);
            std::cout << "             ";
        }
    }
    void posicionar() override {
        guardarPosicionAnterior();
        x += direccionX * dx;
        if (x <= 2 || x >= Console::WindowWidth - 15) direccionX *= -1;
        contadorDisparo++;
    }
    void dibujar() override {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(x, int(y));     std::cout << " [#########] ";
        Console::SetCursorPosition(x, int(y) + 1); std::cout << " | CONTROL | ";
        Console::SetCursorPosition(x, int(y) + 2); std::cout << " [#########] ";
    }
    bool puedeDisparar() override {
        if (contadorDisparo >= 50) {
            contadorDisparo = 0;
            return true;
        }
        return false;
    }
};
