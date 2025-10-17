#pragma once
#include "Entidad.h"

class Aliado : public Entidad {
private:
    std::string mensaje, tipo;
    char simbolo;
public:
    Aliado(int px, float py, char sim, const std::string& t, const std::string& msg)
        : Entidad(px, py, 0, 0, 2, 5), simbolo(sim), tipo(t), mensaje(msg) {
    }
    void borrar() override {
        Console::SetCursorPosition(x, int(y));     std::cout << "     ";
        Console::SetCursorPosition(x, int(y) + 1); std::cout << "     ";
    }
    void posicionar() override {}
    void dibujar() override {
        if (activo) {
            Console::ForegroundColor = ConsoleColor::Green;
            Console::SetCursorPosition(x, int(y));     std::cout << " (" << simbolo << ") ";
            Console::SetCursorPosition(x, int(y) + 1); std::cout << " @@@ ";
        }
    }
    std::string getMensaje() { return mensaje; }
    std::string getTipo() { return tipo; }
};