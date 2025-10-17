#pragma once
#include "Entidad.h"

class Proyectil : public Entidad {
private:
    int direccion;
public:
    Proyectil(int px, float py, int dir) : Entidad(px, py, 3, 0, 1, 1), direccion(dir) {}
    void borrar() override {
        Console::SetCursorPosition(x_anterior, int(y_anterior));
        std::cout << " ";
    }
    void posicionar() override {
        guardarPosicionAnterior();
        x += direccion * dx;
        if (x < 2 || x > Console::WindowWidth - 2) activo = false;
    }
    void dibujar() override {
        if (activo) {
            Console::ForegroundColor = ConsoleColor::Red;
            Console::SetCursorPosition(x, int(y));
            std::cout << "*";
        }
    }
};
