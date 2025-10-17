#pragma once
#include "Entidad.h"

class Recurso : public Entidad {
private:
    std::string nombre;
    char simbolo;
    int valor;
    bool esVisible, esFalso;
    int tiempoParpadeo, contadorParpadeo;
public:
    Recurso(int px, float py, char sim, const std::string& nom, int val, bool falso = false)
        : Entidad(px, py, 0, 0, 2, 5), nombre(nom), simbolo(sim), valor(val), esFalso(falso) {
        esVisible = true;
        tiempoParpadeo = 30 + rand() % 30;
        contadorParpadeo = 0;
    }
    void borrar() override {
        Console::SetCursorPosition(x, int(y));     std::cout << "     ";
        Console::SetCursorPosition(x, int(y) + 1); std::cout << "     ";
    }
    void posicionar() override {
        contadorParpadeo++;
        if (contadorParpadeo >= tiempoParpadeo) {
            esVisible = !esVisible;
            contadorParpadeo = 0;
        }
    }
    void dibujar() override {
        if (activo && esVisible) {
            if (esFalso) {
                Console::ForegroundColor = ConsoleColor::DarkYellow;
                Console::SetCursorPosition(x, int(y));     std::cout << " [X] ";
                Console::SetCursorPosition(x, int(y) + 1); std::cout << " !!! ";
            }
            else {
                Console::ForegroundColor = ConsoleColor::Yellow;
                Console::SetCursorPosition(x, int(y));     std::cout << " [" << simbolo << "] ";
                Console::SetCursorPosition(x, int(y) + 1); std::cout << " *** ";
            }
        }
    }
    int getValor() const { return valor; }
    std::string getNombre() { return nombre; }
    bool esRecursoFalso() const { return esFalso; }
    bool estaVisible() const { return esVisible; }
    void hacerVisible() { esVisible = true; contadorParpadeo = 0; }
};
