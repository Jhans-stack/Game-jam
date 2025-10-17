#pragma once
#include "Enemigo.h"

class EnemigoConflicto : public Enemigo {
private:
    int ataquesSoloJugador, ataquesSoloAiden, ataquesColaborativos;
public:
    EnemigoConflicto(int px, float py) : Enemigo(px, py, 2, 2, 3, 13, "conflicto") {
        activo = false;
        ataquesSoloJugador = 0; ataquesSoloAiden = 0; ataquesColaborativos = 0;
    }
    void borrar() override {
        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x_anterior, int(y_anterior) + i);
            std::cout << "             ";
        }
    }
    void posicionar() override {
        if (activo) {
            guardarPosicionAnterior();
            int dir = rand() % 4;
            switch (dir) {
            case 0: y -= dy; break; case 1: y += dy; break;
            case 2: x -= dx; break; case 3: x += dx; break;
            }
            if (x < 2) x = 2;
            if (x > Console::WindowWidth - 15) x = Console::WindowWidth - 15;
            if (y < 2) y = 2;
            if (y > Console::WindowHeight - 6) y = Console::WindowHeight - 6;
        }
    }
    void dibujar() override {
        if (activo) {
            Console::ForegroundColor = ConsoleColor::DarkRed;
            Console::SetCursorPosition(x, int(y));     std::cout << "  ><<<<<<<>  ";
            Console::SetCursorPosition(x, int(y) + 1); std::cout << " CONFLICTO  ";
            Console::SetCursorPosition(x, int(y) + 2); std::cout << "  ><<<<<<<>  ";
        }
    }
    void registrarAtaqueColaborativo() {
        ataquesColaborativos++;
        recibirDanio(50);
    }
    void registrarAtaqueSolitario(bool esJugador) {
        if (esJugador) ataquesSoloJugador++;
        else ataquesSoloAiden++;
        salud += 10;
    }
};