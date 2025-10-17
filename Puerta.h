#pragma once
#include "Entidad.h"

class Puerta : public Entidad {
private:
    bool abierta;
    int tiempoAbierta;
public:
    Puerta(int px, float py) : Entidad(px, py, 0, 0, 5, 3), abierta(false), tiempoAbierta(0) {}
    void borrar() override {
        for (int i = 0; i < 5; i++) {
            Console::SetCursorPosition(x, int(y) + i);
            std::cout << "   ";
        }
    }
    void posicionar() override {
        if (abierta) {
            tiempoAbierta++;
            if (tiempoAbierta > 100) {
                abierta = false;
                tiempoAbierta = 0;
            }
        }
    }
    void dibujar() override {
        if (abierta) {
            Console::ForegroundColor = ConsoleColor::Green;
            Console::SetCursorPosition(x, int(y));     std::cout << "   ";
            Console::SetCursorPosition(x, int(y) + 1); std::cout << " O ";
            Console::SetCursorPosition(x, int(y) + 2); std::cout << " P ";
            Console::SetCursorPosition(x, int(y) + 3); std::cout << " E ";
            Console::SetCursorPosition(x, int(y) + 4); std::cout << " N ";
        }
        else {
            Console::ForegroundColor = ConsoleColor::DarkRed;
            Console::SetCursorPosition(x, int(y));     std::cout << "|||";
            Console::SetCursorPosition(x, int(y) + 1); std::cout << "|||";
            Console::SetCursorPosition(x, int(y) + 2); std::cout << "|||";
            Console::SetCursorPosition(x, int(y) + 3); std::cout << "|||";
            Console::SetCursorPosition(x, int(y) + 4); std::cout << "|||";
        }
    }
    void abrir() { abierta = true; tiempoAbierta = 0; }
    bool estaAbierta() const { return abierta; }
};
