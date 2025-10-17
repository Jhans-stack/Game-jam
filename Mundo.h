#pragma once
#include "pch.h"

class Mundo {
protected:
    int numero;
    std::string nombre, preguntaReflexiva, contexto;
public:
    Mundo(int num, const std::string& nom, const std::string& pregunta, const std::string& cont)
        : numero(num), nombre(nom), preguntaReflexiva(pregunta), contexto(cont) {
    }
    virtual ~Mundo() {}
    int getNumero() const { return numero; }
    std::string getNombre() { return nombre; }
    std::string getPregunta() { return preguntaReflexiva; }
    std::string getContexto() { return contexto; }
    virtual void mostrarIntroduccion() {
        system("cls");
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(30, 5); std::cout << "========================================";
        Console::SetCursorPosition(30, 6); std::cout << "  MUNDO " << numero << ": " << nombre;
        Console::SetCursorPosition(30, 7); std::cout << "========================================";
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(20, 10); std::cout << "CONTEXTO:";
        Console::SetCursorPosition(20, 11); std::cout << contexto;
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(20, 14); std::cout << "PREGUNTA REFLEXIVA:";
        Console::SetCursorPosition(20, 15); std::cout << preguntaReflexiva;
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(35, 20); std::cout << "Presiona cualquier tecla para comenzar...";
        _getch();
        system("cls");
    }
};