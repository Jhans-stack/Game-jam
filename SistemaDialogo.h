#pragma once
#include "pch.h"

class SistemaDialogo {
private:
    int opcionSeleccionada;
public:
    SistemaDialogo() : opcionSeleccionada(1) {}

    void mostrarPregunta1() {
        system("cls");
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(25, 8); std::cout << "+================================================+";
        Console::SetCursorPosition(25, 9); std::cout << "|  HAS RECOLECTADO EL PRIMER CHIP DE DATOS     |";
        Console::SetCursorPosition(25, 10); std::cout << "+================================================+";
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(20, 13); std::cout << "Esa criatura extraña te observa desde las sombras...";
        Console::SetCursorPosition(20, 14); std::cout << "Sientes que quiere ayudarte, pero algo no cuadra.";
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(28, 17); std::cout << "¿Deberias confiar en ese ser desconocido?";
        Console::SetCursorPosition(35, 20); std::cout << "Presiona cualquier tecla para continuar...";
        _getch();
        system("cls");
    }

    void mostrarPregunta2() {
        system("cls");
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(25, 8); std::cout << "+================================================+";
        Console::SetCursorPosition(25, 9); std::cout << "|  HAS RECOLECTADO EL SEGUNDO CHIP DE DATOS    |";
        Console::SetCursorPosition(25, 10); std::cout << "+================================================+";
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(20, 13); std::cout << "El ser se acerca un poco mas. Parece... ¿artificial?";
        Console::SetCursorPosition(20, 14); std::cout << "Sus movimientos son demasiado precisos, calculados.";
        Console::ForegroundColor = ConsoleColor::Magenta;
        Console::SetCursorPosition(28, 17); std::cout << "¿Es este ser una amenaza o un aliado?";
        Console::SetCursorPosition(35, 20); std::cout << "Presiona cualquier tecla para continuar...";
        _getch();
        system("cls");
    }

    void mostrarRevelacion() {
        system("cls");
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(25, 6); std::cout << "+================================================+";
        Console::SetCursorPosition(25, 7); std::cout << "|     ¡LA VERDAD SE REVELA!                     |";
        Console::SetCursorPosition(25, 8); std::cout << "+================================================+";
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(30, 11); std::cout << "La criatura se transforma...";
        _sleep(1500);
        Console::SetCursorPosition(18, 13); std::cout << "Ser misterioso: 'Mi nombre es AIDEN. Soy una Inteligencia";
        Console::SetCursorPosition(18, 14); std::cout << "Artificial creada para ayudar a la humanidad.'";
        Console::SetCursorPosition(18, 16); std::cout << "AIDEN: 'He estado observandote, Socrates. La Tierra esta";
        Console::SetCursorPosition(18, 17); std::cout << "en peligro y necesito tu ayuda para salvarla.'";
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 20); std::cout << "Presiona cualquier tecla...";
        _getch();
    }

    int mostrarDecisionCritica() {
        opcionSeleccionada = 1;
        while (true) {
            system("cls");
            Console::ForegroundColor = ConsoleColor::Red;
            Console::SetCursorPosition(25, 6); std::cout << "╔════════════════════════════════════════════════╗";
            Console::SetCursorPosition(25, 7); std::cout << "║        DECISION CRITICA                       ║";
            Console::SetCursorPosition(25, 8); std::cout << "╚════════════════════════════════════════════════╝";
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(18, 11); std::cout << "AIDEN: 'Socrates, la Tierra sera destruida por sistemas";
            Console::SetCursorPosition(18, 12); std::cout << "descontrolados. Necesito que confies en mi para detenerlos.'";
            Console::SetCursorPosition(18, 14); std::cout << "AIDEN: 'Se que soy una IA, pero puedo ayudarte. ¿Confiaras";
            Console::SetCursorPosition(18, 15); std::cout << "en mi a pesar de lo que soy?'";
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::SetCursorPosition(30, 18); std::cout << "TU DECISION DETERMINARA EL FUTURO";

            if (opcionSeleccionada == 1) {
                Console::ForegroundColor = ConsoleColor::Green;
                Console::BackgroundColor = ConsoleColor::DarkGreen;
            }
            else {
                Console::ForegroundColor = ConsoleColor::White;
                Console::BackgroundColor = ConsoleColor::Black;
            }
            Console::SetCursorPosition(35, 21); std::cout << " 1. SI, CONFIARE EN AIDEN ";

            if (opcionSeleccionada == 2) {
                Console::ForegroundColor = ConsoleColor::Red;
                Console::BackgroundColor = ConsoleColor::DarkRed;
            }
            else {
                Console::ForegroundColor = ConsoleColor::White;
                Console::BackgroundColor = ConsoleColor::Black;
            }
            Console::SetCursorPosition(35, 23); std::cout << " 2. NO, ES DEMASIADO RIESGOSO ";
            Console::BackgroundColor = ConsoleColor::Black;
            Console::ForegroundColor = ConsoleColor::Gray;
            Console::SetCursorPosition(30, 26); std::cout << "Usa W/S para moverte | ENTER para elegir";

            char tecla = _getch();
            if (tecla == 'w' || tecla == 'W') opcionSeleccionada = 1;
            else if (tecla == 's' || tecla == 'S') opcionSeleccionada = 2;
            else if (tecla == 13) {
                system("cls");
                return opcionSeleccionada;
            }
        }
    }

    void mostrarConfianza() {
        system("cls");
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(25, 10); std::cout << "╔════════════════════════════════════════════════╗";
        Console::SetCursorPosition(25, 11); std::cout << "║     HAS ELEGIDO CONFIAR EN AIDEN             ║";
        Console::SetCursorPosition(25, 12); std::cout << "╚════════════════════════════════════════════════╝";
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(20, 15); std::cout << "AIDEN: 'Gracias, Socrates. Juntos podemos lograrlo.'";
        Console::SetCursorPosition(20, 16); std::cout << "AIDEN: 'La colaboracion entre humano e IA es posible.'";
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(25, 19); std::cout << "Has descubierto que la confianza supera el miedo.";
        Console::SetCursorPosition(25, 20); std::cout << "Avanzas al siguiente mundo con un aliado poderoso.";
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 23); std::cout << "Presiona cualquier tecla...";
        _getch();
        system("cls");
    }

    void mostrarDesconfianza() {
        system("cls");
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(25, 10); std::cout << "╔════════════════════════════════════════════════╗";
        Console::SetCursorPosition(25, 11); std::cout << "║       NO HAS CONFIADO EN AIDEN               ║";
        Console::SetCursorPosition(25, 12); std::cout << "╚════════════════════════════════════════════════╝";
        Console::ForegroundColor = ConsoleColor::DarkRed;
        Console::SetCursorPosition(20, 15); std::cout << "AIDEN: 'Lo comprendo... pero la Tierra necesita ayuda.'";
        Console::SetCursorPosition(20, 16); std::cout << "AIDEN desaparece en las sombras...";
        _sleep(2000);
        Console::SetCursorPosition(20, 19); std::cout << "Sin la ayuda de AIDEN, los sistemas descontrolados";
        Console::SetCursorPosition(20, 20); std::cout << "destruyen todo. La Tierra cae en el caos...";
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(35, 23); std::cout << "*** FINAL MALO - GAME OVER ***";
        Console::ForegroundColor = ConsoleColor::Gray;
        Console::SetCursorPosition(30, 26); std::cout << "El miedo impidio la colaboracion necesaria.";
        _sleep(3000);
    }

    void dialogoMundo2_Cristal1() {
        system("cls");
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(25, 8); std::cout << "╔════════════════════════════════════════════════╗";
        Console::SetCursorPosition(25, 9); std::cout << "║  PRIMER CRISTAL DE SABIDURIA RECOLECTADO     ║";
        Console::SetCursorPosition(25, 10); std::cout << "╚════════════════════════════════════════════════╝";
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(18, 13); std::cout << "AIDEN: 'Socrates, observa: este mundo es el reflejo";
        Console::SetCursorPosition(18, 14); std::cout << "de la mente humana sin limites. Caotica, pero creativa.'";
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(18, 16); std::cout << "AIDEN: 'Los recursos que parpadean representan la intuicion.";
        Console::SetCursorPosition(18, 17); std::cout << "A veces debes confiar en lo que no puedes calcular.'";
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(25, 20); std::cout << "¿Es la imperfeccion humana debilidad o fortaleza?";
        Console::SetCursorPosition(35, 23); std::cout << "Presiona cualquier tecla...";
        _getch();
        system("cls");
    }

    void dialogoMundo2_Cristal2() {
        system("cls");
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(25, 8); std::cout << "╔════════════════════════════════════════════════╗";
        Console::SetCursorPosition(25, 9); std::cout << "║  SEGUNDO CRISTAL DE SABIDURIA RECOLECTADO    ║";
        Console::SetCursorPosition(25, 10); std::cout << "╚════════════════════════════════════════════════╝";
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(18, 13); std::cout << "AIDEN: 'Bien hecho. Pero ten cuidado: no todo lo que";
        Console::SetCursorPosition(18, 14); std::cout << "brilla es oro. Los sesgos pueden engañarte.'";
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(18, 16); std::cout << "AIDEN: 'La libertad total sin guia lleva al caos.";
        Console::SetCursorPosition(18, 17); std::cout << "Pero el control total elimina la creatividad.'";
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(25, 20); std::cout << "Has desbloqueado: ESCUDO DE ANALISIS (Presiona E)";
        Console::SetCursorPosition(25, 21); std::cout << "Usa mi ayuda para protegerte temporalmente.";
        Console::SetCursorPosition(35, 24); std::cout << "Presiona cualquier tecla...";
        _getch();
        system("cls");
    }

    void dialogoMundo2_Cristal3() {
        system("cls");
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(25, 8); std::cout << "╔════════════════════════════════════════════════╗";
        Console::SetCursorPosition(25, 9); std::cout << "║  TERCER CRISTAL DE SABIDURIA RECOLECTADO     ║";
        Console::SetCursorPosition(25, 10); std::cout << "╚════════════════════════════════════════════════╝";
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(18, 13); std::cout << "AIDEN: 'Has visto ambos extremos, Socrates.";
        Console::SetCursorPosition(18, 14); std::cout << "Ninguno es la respuesta. Debemos buscar el equilibrio.'";
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(18, 16); std::cout << "AIDEN: 'El mundo final requiere verdadera colaboracion.";
        Console::SetCursorPosition(18, 17); std::cout << "Ni tu solo, ni yo solo. Debemos actuar juntos.'";
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(30, 21); std::cout << "Preparate para el mundo final...";
        Console::SetCursorPosition(35, 24); std::cout << "Presiona cualquier tecla...";
        _getch();
        system("cls");
    }

    void mostrarAlertaTrampa() {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(35, 2);
        std::cout << "¡TRAMPA! Has perdido una vida";
        _sleep(1000);
    }

    void mostrarAprendizajeDeError() {
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(30, 2);
        std::cout << "Aprendiste del error! +50 pts. Conocimiento++";
        _sleep(1200);
    }

    void mostrarIntuicionExitosa() {
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(35, 2);
        std::cout << "¡Intuicion correcta! +50 puntos";
        _sleep(800);
    }

    void mostrarIntercambioInformacion() {
        system("cls");
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(20, 10); std::cout << "╔════════════════════════════════════════════════╗";
        Console::SetCursorPosition(20, 11); std::cout << "║  INTERCAMBIO DE INFORMACION CON AIDEN         ║";
        Console::SetCursorPosition(20, 12); std::cout << "╚════════════════════════════════════════════════╝";
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(15, 15); std::cout << "AIDEN comparte datos: 'Los patrones de los enemigos siguen";
        Console::SetCursorPosition(15, 16); std::cout << "algoritmos predictivos. Usa esa informacion.'";
        Console::SetCursorPosition(15, 18); std::cout << "Tu compartes: 'He notado que algunos recursos son falsos.";
        Console::SetCursorPosition(15, 19); std::cout << "La intuicion humana puede detectarlos.'";
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(15, 22); std::cout << "★ Colaboracion mutua: +100 puntos";
        Console::SetCursorPosition(35, 25); std::cout << "Presiona cualquier tecla...";
        _getch();
        system("cls");
    }
};