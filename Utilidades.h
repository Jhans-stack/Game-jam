#pragma once
#include "pch.h"

void mostrarPantallaCarga() {
    system("cls");
    Console::BackgroundColor = ConsoleColor::Blue;
    Console::ForegroundColor = ConsoleColor::White;
    system("cls");
    Console::SetCursorPosition(35, 10); std::cout << "+================================+";
    Console::SetCursorPosition(35, 11); std::cout << "|   LA ODISEA DEL PENSAMIENTO   |";
    Console::SetCursorPosition(35, 12); std::cout << "+================================+";
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(45, 15); std::cout << "Cargando";
    for (int i = 0; i < 20; i++) {
        Console::SetCursorPosition(38, 17); std::cout << "[";
        for (int j = 0; j < i; j++) std::cout << "=";
        for (int j = i; j < 20; j++) std::cout << " ";
        std::cout << "] " << (i * 5) << "%";
        _sleep(150);
    }
    Console::SetCursorPosition(38, 17); std::cout << "[====================] 100%";
    _sleep(500);
    Console::BackgroundColor = ConsoleColor::Black;
    system("cls");
}

int mostrarMenu() {
    int opcion = 1;
    while (true) {
        system("cls");
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(30, 5); std::cout << "+================================================+";
        Console::SetCursorPosition(30, 6); std::cout << "|       LA ODISEA DEL PENSAMIENTO               |";
        Console::SetCursorPosition(30, 7); std::cout << "+================================================+";
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 10); std::cout << "Un viaje filosofico sobre IA";
        Console::SetCursorPosition(38, 11); std::cout << "y Pensamiento Critico";
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(30, 14); std::cout << "========================================";

        if (opcion == 1) {
            Console::ForegroundColor = ConsoleColor::Green;
            Console::BackgroundColor = ConsoleColor::DarkGreen;
        }
        else {
            Console::ForegroundColor = ConsoleColor::White;
            Console::BackgroundColor = ConsoleColor::Black;
        }
        Console::SetCursorPosition(42, 16); std::cout << " 1. JUGAR ";

        if (opcion == 2) {
            Console::ForegroundColor = ConsoleColor::Cyan;
            Console::BackgroundColor = ConsoleColor::DarkCyan;
        }
        else {
            Console::ForegroundColor = ConsoleColor::White;
            Console::BackgroundColor = ConsoleColor::Black;
        }
        Console::SetCursorPosition(40, 18); std::cout << " 2. INSTRUCCIONES ";

        if (opcion == 3) {
            Console::ForegroundColor = ConsoleColor::Magenta;
            Console::BackgroundColor = ConsoleColor::DarkMagenta;
        }
        else {
            Console::ForegroundColor = ConsoleColor::White;
            Console::BackgroundColor = ConsoleColor::Black;
        }
        Console::SetCursorPosition(41, 20); std::cout << " 3. CREDITOS ";

        if (opcion == 4) {
            Console::ForegroundColor = ConsoleColor::Red;
            Console::BackgroundColor = ConsoleColor::DarkRed;
        }
        else {
            Console::ForegroundColor = ConsoleColor::White;
            Console::BackgroundColor = ConsoleColor::Black;
        }
        Console::SetCursorPosition(42, 22); std::cout << " 4. SALIR ";

        Console::BackgroundColor = ConsoleColor::Black;
        Console::ForegroundColor = ConsoleColor::Gray;
        Console::SetCursorPosition(30, 25); std::cout << "Usa W/S para moverte | ENTER para seleccionar";

        char tecla = _getch();
        if (tecla == 'w' || tecla == 'W') {
            opcion--;
            if (opcion < 1) opcion = 4;
        }
        else if (tecla == 's' || tecla == 'S') {
            opcion++;
            if (opcion > 4) opcion = 1;
        }
        else if (tecla == 13) {
            return opcion;
        }
    }
}

void mostrarInstrucciones() {
    system("cls");
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(30, 3); std::cout << "+================================================+";
    Console::SetCursorPosition(30, 4); std::cout << "|              INSTRUCCIONES                     |";
    Console::SetCursorPosition(30, 5); std::cout << "+================================================+";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(20, 8); std::cout << "OBJETIVO:";
    Console::SetCursorPosition(20, 9); std::cout << "- Recolecta 3 recursos en cada mundo antes de que acabe el tiempo";
    Console::SetCursorPosition(20, 10); std::cout << "- Sobrevive a los enemigos y descubre la verdad sobre AIDEN";
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(20, 13); std::cout << "CONTROLES:";
    Console::SetCursorPosition(20, 14); std::cout << "- W/A/S/D: Mover a Socrates";
    Console::SetCursorPosition(20, 15); std::cout << "- E: Activar escudo (Mundo 2 con AIDEN)";
    Console::SetCursorPosition(20, 16); std::cout << "- F: Abrir puerta (Mundo 3, requiere sincronizacion 60%)";
    Console::SetCursorPosition(20, 17); std::cout << "- ESPACIO: Ataque colaborativo (Mundo 3)";
    Console::SetCursorPosition(20, 18); std::cout << "- Q: Salir del juego";
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(20, 21); std::cout << "LOS 3 MUNDOS:";
    Console::SetCursorPosition(20, 22); std::cout << "1. LA MAQUINA SUPREMA - Algoritmos vs libertad";
    Console::SetCursorPosition(20, 23); std::cout << "2. LA LUZ DEL PENSAMIENTO - Intuicion vs sesgos";
    Console::SetCursorPosition(20, 24); std::cout << "3. EL PUENTE DEL FUTURO - Colaboracion humano-IA";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(35, 27); std::cout << "Presiona cualquier tecla para volver...";
    _getch();
}

void mostrarCreditos() {
    system("cls");
    Console::ForegroundColor = ConsoleColor::Magenta;
    Console::SetCursorPosition(30, 5); std::cout << "+================================================+";
    Console::SetCursorPosition(30, 6); std::cout << "|                 CREDITOS                       |";
    Console::SetCursorPosition(30, 7); std::cout << "+================================================+";
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(25, 10); std::cout << "LA ODISEA DEL PENSAMIENTO";
    Console::SetCursorPosition(25, 11); std::cout << "Un juego sobre IA y Pensamiento Critico";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(25, 14); std::cout << "Curso: Algoritmos (1ACC265)";
    Console::SetCursorPosition(25, 15); std::cout << "Universidad: UPC";
    Console::SetCursorPosition(25, 16); std::cout << "Ciclo: 2025-20";
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(25, 19); std::cout << "========== EQUIPO DE DESARROLLO ==========";
    Console::SetCursorPosition(30, 21); std::cout << "1. Jhans Huaraca";
    Console::SetCursorPosition(30, 22); std::cout << "2. Jhonatan Gutierrez";
    Console::SetCursorPosition(30, 23); std::cout << "3. Luis Quispe";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(35, 28); std::cout << "Presiona cualquier tecla para volver...";
    _getch();
}
