#pragma once
#include "Enemigo.h"

class EnemigoSesgo : public Enemigo {
private:
    int contadorMovimiento;
    bool esFalso;
public:
    EnemigoSesgo(int px, float py, bool falso = false) : Enemigo(px, py, 2, 2, 3, 13, "sesgo"),
        contadorMovimiento(0), esFalso(falso) {
    }
    void borrar() override {
        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x_anterior, int(y_anterior) + i);
            std::cout << "             ";
        }
    }
    void posicionar() override {
        contadorMovimiento++;
        if (contadorMovimiento % 2 == 0) {
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
        if (esFalso) {
            Console::ForegroundColor = ConsoleColor::DarkMagenta;
            Console::SetCursorPosition(x, int(y));     std::cout << "  <~~~~~~~>  ";
            Console::SetCursorPosition(x, int(y) + 1); std::cout << "  |ENGANO|  ";
            Console::SetCursorPosition(x, int(y) + 2); std::cout << "  <~~~~~~~>  ";
        }
        else {
            Console::ForegroundColor = ConsoleColor::Magenta;
            Console::SetCursorPosition(x, int(y));     std::cout << "  <~~~~~~~>  ";
            Console::SetCursorPosition(x, int(y) + 1); std::cout << "  | SESGO |  ";
            Console::SetCursorPosition(x, int(y) + 2); std::cout << "  <~~~~~~~>  ";
        }
    }
    bool esTrampa() const { return esFalso; }
};