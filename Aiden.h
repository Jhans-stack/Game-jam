#pragma once
#include "Entidad.h"

class Aiden : public Entidad {
private:
    bool identidadRevelada;
    int nivelConfianza, seguirOffsetX;
    std::string estadoActual;
    int movimientosRecientes;
public:
    Aiden(int px, float py) : Entidad(px, py, 0, 0, 4, 7) {
        identidadRevelada = false; nivelConfianza = 0; estadoActual = "misterioso";
        seguirOffsetX = 12; movimientosRecientes = 0;
    }
    void borrar() override {
        for (int i = 0; i < 4; i++) {
            Console::SetCursorPosition(x_anterior, int(y_anterior) + i);
            std::cout << "       ";
        }
    }
    void posicionar() override {}
    void dibujar() override {
        if (!identidadRevelada) {
            Console::ForegroundColor = ConsoleColor::DarkGray;
            Console::SetCursorPosition(x, int(y));     std::cout << "   ?   ";
            Console::SetCursorPosition(x, int(y) + 1); std::cout << "  ???  ";
            Console::SetCursorPosition(x, int(y) + 2); std::cout << " ????? ";
            Console::SetCursorPosition(x, int(y) + 3); std::cout << "  ???  ";
        }
        else {
            Console::ForegroundColor = ConsoleColor::Cyan;
            Console::SetCursorPosition(x, int(y));     std::cout << "  <A>  ";
            Console::SetCursorPosition(x, int(y) + 1); std::cout << " [|||] ";
            Console::SetCursorPosition(x, int(y) + 2); std::cout << " {***} ";
            Console::SetCursorPosition(x, int(y) + 3); std::cout << " AIDEN ";
        }
    }
    void revelarIdentidad() { identidadRevelada = true; estadoActual = "revelado"; }
    void aumentarConfianza() { nivelConfianza++; }
    bool estaRevelado() { return identidadRevelada; }
    int getConfianza() { return nivelConfianza; }
    void seguirJugador(int jugadorX, int jugadorY) {
        guardarPosicionAnterior();
        x = jugadorX + seguirOffsetX;
        y = jugadorY;
        if (x > Console::WindowWidth - 10) x = Console::WindowWidth - 10;
        if (x < 2) x = 2;
        movimientosRecientes++;
    }
    void acercarse() { if (seguirOffsetX > 6) seguirOffsetX -= 2; }
    int getMovimientosRecientes() { return movimientosRecientes; }
    void resetMovimientos() { movimientosRecientes = 0; }
};
