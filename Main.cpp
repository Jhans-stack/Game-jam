#include "pch.h"
#include "Controlador.h"
#include "Utilidades.h"

using namespace std;

int main() {
    srand((unsigned int)time(0));

    while (true) {
        int opcionMenu = mostrarMenu();

        if (opcionMenu == 1) {
            mostrarPantallaCarga();
            system("cls");
            Console::ForegroundColor = ConsoleColor::Cyan;
            Console::SetCursorPosition(30, 10); cout << "OBJETIVO: 3 recursos por mundo en 90 segundos";
            Console::ForegroundColor = ConsoleColor::Red;
            Console::SetCursorPosition(28, 12); cout << "CUIDADO! Los enemigos del Mundo 1 disparan";
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::SetCursorPosition(25, 14); cout << "MUNDO 3: Requiere colaboracion para abrir puertas";
            Console::ForegroundColor = ConsoleColor::Green;
            Console::SetCursorPosition(35, 17); cout << "Presiona cualquier tecla...";
            _getch();

            Controlador* controlador = new Controlador();
            controlador->inicializarNivel(1);

            while (controlador->estaActivo()) {
                controlador->borrarTodo();
                controlador->colisiones();
                controlador->verificarProgreso();
                controlador->gestionarMundo3();

                if (_kbhit()) {
                    char tecla = _getch();
                    controlador->procesarMovimiento(tecla);
                }

                controlador->posicionarTodo();
                controlador->dibujarTodo();
                controlador->actualizarEscudo();
                _sleep(50);
            }

            system("cls");
            if (controlador->getTiempoAgotado()) {
                Console::ForegroundColor = ConsoleColor::Red;
                Console::SetCursorPosition(40, 12); cout << "TIEMPO AGOTADO";
                Console::SetCursorPosition(35, 14); cout << "Puntaje: " << controlador->getJugador()->getPuntaje();
            }
            else if (controlador->getJugador()->getVidas() <= 0) {
                Console::ForegroundColor = ConsoleColor::Red;
                Console::SetCursorPosition(40, 12); cout << "GAME OVER";
                Console::SetCursorPosition(35, 14); cout << "Puntaje: " << controlador->getJugador()->getPuntaje();
            }

            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(35, 20); cout << "Presiona cualquier tecla para volver al menu...";
            _getch();
            delete controlador;
        }
        else if (opcionMenu == 2) {
            mostrarInstrucciones();
        }
        else if (opcionMenu == 3) {
            mostrarCreditos();
        }
        else if (opcionMenu == 4) {
            system("cls");
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::SetCursorPosition(35, 14); cout << "Gracias por jugar!";
            _sleep(1500);
            break;
        }
    }

    return 0;
}