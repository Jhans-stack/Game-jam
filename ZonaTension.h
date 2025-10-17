#pragma once
#include "Entidad.h"

class ZonaTension : public Entidad {
private:
    int intensidad;
public:
    ZonaTension(int px, float py) : Entidad(px, py, 0, 0, 8, 15), intensidad(3) {}
    void borrar() override {
        for (int i = 0; i < 8; i++) {
            Console::SetCursorPosition(x, int(y) + i);
            std::cout << "               ";
        }
    }
    void posicionar() override {}
    void dibujar() override {
        if (activo) {
            Console::ForegroundColor = ConsoleColor::DarkYellow;
            for (int i = 0; i < 8; i++) {
                Console::SetCursorPosition(x, int(y) + i);
                if (i % 2 == 0) std::cout << "~~~~~~~~~~~~~~~";
                else std::cout << "               ";
            }
        }
    }
    int getIntensidad() const { return intensidad; }
};