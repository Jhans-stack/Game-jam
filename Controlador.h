#pragma once
#include "pch.h"
#include "Jugador.h"
#include "Aiden.h"
#include "EnemigoAlgoritmo.h"
#include "EnemigoSesgo.h"
#include "EnemigoConflicto.h"
#include "Recurso.h"
#include "Proyectil.h"
#include "Puerta.h"
#include "ZonaTension.h"
#include "Aliado.h"
#include "MundoIA.h"
#include "MundoHumano.h"
#include "MundoColaborativo.h"
#include "SistemaDialogo.h"

class Controlador {
private:
    Jugador* jugador;
    Aiden* aiden;
    std::vector<Enemigo*> enemigos;
    std::vector<Recurso*> recursos;
    std::vector<Proyectil*> proyectiles;
    std::vector<Puerta*> puertas;
    std::vector<ZonaTension*> zonasTension;
    Aliado* aliado;
    Mundo* mundoActual;
    SistemaDialogo* dialogo;
    int nivelActual, contadorMovimientos, tiempoInactivo;
    bool juegoActivo, confioEnAiden, escudoActivo, tiempoAgotado;
    int duracionEscudo;
    time_t tiempoInicio, tiempoLimite;
    int nivelSincronizacion;
    int trampasCaidas, intuicionesCorrectas;
    int puertasAbiertas;

    void limpiarMensajes() {
        Console::ForegroundColor = ConsoleColor::Black;
        for (int i = 0; i < 50; i++) {
            Console::SetCursorPosition(30 + i, 2);
            std::cout << " ";
        }
    }

    void inicializarMundo1() {
        mundoActual = new MundoIA();
        mundoActual->mostrarIntroduccion();
        jugador->setPos(5, 10.0f); jugador->reiniciarRecursos();
        aiden->setPos(17, 10.0f); aiden->setActivo(true);
        for (auto& e : enemigos) delete e; enemigos.clear();
        for (auto& r : recursos) delete r; recursos.clear();
        for (auto& p : proyectiles) delete p; proyectiles.clear();
        enemigos.push_back(new EnemigoAlgoritmo(25, 5.0f));
        enemigos.push_back(new EnemigoAlgoritmo(55, 15.0f));
        enemigos.push_back(new EnemigoAlgoritmo(85, 8.0f));
        recursos.push_back(new Recurso(30, 12.0f, 'D', "Chip de Datos", 100));
        recursos.push_back(new Recurso(60, 18.0f, 'D', "Chip de Datos", 100));
        recursos.push_back(new Recurso(90, 7.0f, 'D', "Chip de Datos", 100));
        aliado = new Aliado(105, 25.0f, '?', "Misterioso", "Observa los patrones...");
    }

    void inicializarMundo2() {
        mundoActual = new MundoHumano();
        mundoActual->mostrarIntroduccion();
        jugador->setPos(5, 10.0f); jugador->reiniciarRecursos();
        aiden->setPos(17, 10.0f); aiden->setActivo(true);
        for (auto& e : enemigos) delete e; enemigos.clear();
        for (auto& r : recursos) delete r; recursos.clear();
        for (auto& p : proyectiles) delete p; proyectiles.clear();
        enemigos.push_back(new EnemigoSesgo(30, 8.0f, false));
        enemigos.push_back(new EnemigoSesgo(60, 16.0f, false));
        enemigos.push_back(new EnemigoSesgo(85, 12.0f, false));
        recursos.push_back(new Recurso(35, 14.0f, 'S', "Cristal Sabiduria", 100, false));
        recursos.push_back(new Recurso(65, 20.0f, 'S', "Cristal Sabiduria", 100, false));
        recursos.push_back(new Recurso(95, 9.0f, 'S', "Cristal Sabiduria", 100, false));
        recursos.push_back(new Recurso(45, 10.0f, 'X', "Trampa", -50, true));
        recursos.push_back(new Recurso(75, 15.0f, 'X', "Trampa", -50, true));
        aliado = new Aliado(105, 25.0f, '+', "AIDEN", "Confia en tu intuicion!");
        escudoActivo = false; duracionEscudo = 0;
        trampasCaidas = 0; intuicionesCorrectas = 0;
    }

    void inicializarMundo3() {
        mundoActual = new MundoColaborativo();
        mundoActual->mostrarIntroduccion();
        jugador->setPos(5, 10.0f); jugador->reiniciarRecursos();
        aiden->setPos(17, 10.0f); aiden->setActivo(true);
        for (auto& e : enemigos) delete e; enemigos.clear();
        for (auto& r : recursos) delete r; recursos.clear();
        for (auto& p : proyectiles) delete p; proyectiles.clear();
        for (auto& pt : puertas) delete pt; puertas.clear();
        for (auto& z : zonasTension) delete z; zonasTension.clear();
        contadorMovimientos = 0; tiempoInactivo = 0;
        nivelSincronizacion = 50; puertasAbiertas = 0;
        enemigos.push_back(new EnemigoConflicto(40, 12.0f));
        enemigos.push_back(new EnemigoConflicto(70, 16.0f));
        enemigos.push_back(new EnemigoConflicto(50, 8.0f));
        puertas.push_back(new Puerta(30, 10.0f));
        puertas.push_back(new Puerta(60, 15.0f));
        zonasTension.push_back(new ZonaTension(20, 5.0f));
        zonasTension.push_back(new ZonaTension(75, 18.0f));
        recursos.push_back(new Recurso(35, 12.0f, 'U', "Puente Union", 100));
        recursos.push_back(new Recurso(65, 17.0f, 'U', "Puente Union", 100));
        recursos.push_back(new Recurso(100, 20.0f, 'U', "Puente Union", 100));
        aliado = new Aliado(105, 25.0f, '=', "Colaborativo", "Sincronizacion!");
    }

    void limpiarMundo() {
        for (auto& e : enemigos) delete e; enemigos.clear();
        for (auto& r : recursos) delete r; recursos.clear();
        for (auto& p : proyectiles) delete p; proyectiles.clear();
        for (auto& pt : puertas) delete pt; puertas.clear();
        for (auto& z : zonasTension) delete z; zonasTension.clear();
        if (aliado) { delete aliado; aliado = nullptr; }
        if (mundoActual) { delete mundoActual; mundoActual = nullptr; }
    }

public:
    Controlador() {
        try { Console::SetWindowSize(120, 30); }
        catch (...) {}
        Console::CursorVisible = false;
        jugador = new Jugador(5, 10);
        aiden = new Aiden(17, 10);
        dialogo = new SistemaDialogo();
        mundoActual = nullptr;
        aliado = nullptr;
        nivelActual = 1;
        contadorMovimientos = 0;
        tiempoInactivo = 0;
        juegoActivo = true;
        confioEnAiden = false;
        escudoActivo = false;
        duracionEscudo = 0;
        tiempoInicio = time(0);
        tiempoLimite = 90;
        tiempoAgotado = false;
        nivelSincronizacion = 50;
        trampasCaidas = 0;
        intuicionesCorrectas = 0;
        puertasAbiertas = 0;
    }

    ~Controlador() {
        limpiarMundo();
        delete jugador;
        delete aiden;
        delete dialogo;
    }

    void inicializarNivel(int nivel) {
        nivelActual = nivel;
        switch (nivel) {
        case 1: inicializarMundo1(); break;
        case 2: inicializarMundo2(); break;
        case 3: inicializarMundo3(); break;
        }
        tiempoInicio = time(0);
    }

    void borrarTodo() {
        for (auto& p : proyectiles) if (p->estaActivo()) p->borrar();
        for (auto& e : enemigos) if (e->estaActivo()) e->borrar();
        if (aiden && aiden->estaActivo()) aiden->borrar();
        jugador->borrar();
        for (auto& r : recursos) r->borrar();
        if (aliado && aliado->estaActivo()) aliado->borrar();
        for (auto& pt : puertas) if (pt->estaActivo()) pt->borrar();
        for (auto& z : zonasTension) if (z->estaActivo()) z->borrar();
        limpiarMensajes();
    }

    void posicionarTodo() {
        if (nivelActual == 2) {
            for (auto& r : recursos) {
                if (r->estaActivo()) r->posicionar();
            }
        }
        if (nivelActual == 3) {
            for (auto& pt : puertas) {
                if (pt->estaActivo()) pt->posicionar();
            }
        }
        for (auto& e : enemigos) {
            if (e->estaActivo()) {
                e->posicionar();
                if (nivelActual == 1 && e->puedeDisparar()) {
                    int dir = (e->getX() < jugador->getX()) ? 1 : -1;
                    proyectiles.push_back(new Proyectil(e->getX() + 6, e->getY() + 1.5f, dir));
                }
            }
        }
        for (auto& p : proyectiles) if (p->estaActivo()) p->posicionar();
        if (aiden && aiden->estaActivo()) aiden->seguirJugador(jugador->getX(), jugador->getY());
    }

    void dibujarTodo() {
        time_t tiempoTranscurrido = time(0) - tiempoInicio;
        int tiempoRestante = tiempoLimite - tiempoTranscurrido;
        if (tiempoRestante <= 0 && !jugador->haGanado()) {
            tiempoAgotado = true;
            juegoActivo = false;
            return;
        }
        Console::ForegroundColor = ConsoleColor::DarkGray;
        for (int i = 0; i < Console::WindowWidth; i++) {
            Console::SetCursorPosition(i, 0); std::cout << "=";
            Console::SetCursorPosition(i, Console::WindowHeight - 4); std::cout << "=";
        }
        for (int i = 0; i <= Console::WindowHeight - 4; i++) {
            Console::SetCursorPosition(0, i); std::cout << "|";
            Console::SetCursorPosition(Console::WindowWidth - 1, i); std::cout << "|";
        }
        for (auto& r : recursos) if (r->estaActivo()) r->dibujar();
        for (auto& z : zonasTension) if (z->estaActivo()) z->dibujar();
        for (auto& pt : puertas) if (pt->estaActivo()) pt->dibujar();
        for (auto& p : proyectiles) if (p->estaActivo()) p->dibujar();
        for (auto& e : enemigos) if (e->estaActivo()) e->dibujar();
        if (aiden && aiden->estaActivo()) aiden->dibujar();
        if (aliado && aliado->estaActivo()) aliado->dibujar();
        jugador->dibujar();

        int hudX = Console::WindowWidth - 34;
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(hudX, 1);
        std::cout << "+==============================+";
        Console::SetCursorPosition(hudX, 2);
        std::cout << "| MUNDO " << nivelActual << ": " << mundoActual->getNombre();
        for (int i = 0; i < (27 - mundoActual->getNombre().length()); i++) std::cout << " ";
        std::cout << "|";
        Console::SetCursorPosition(hudX, 3);
        Console::ForegroundColor = ConsoleColor::Red;
        std::cout << "| ";
        for (int i = 0; i < jugador->getVidas(); i++) std::cout << char(3) << " ";
        Console::ForegroundColor = ConsoleColor::White;
        std::cout << "Vidas: " << jugador->getVidas();
        for (int i = 0; i < (19 - jugador->getVidas() * 2); i++) std::cout << " ";
        std::cout << "|";
        Console::SetCursorPosition(hudX, 4);
        Console::ForegroundColor = ConsoleColor::Yellow;
        std::cout << "| Recursos: " << jugador->getRecursos() << "/3";
        Console::ForegroundColor = ConsoleColor::White;
        std::cout << " | Pts: " << jugador->getPuntaje();
        for (int i = 0; i < (10 - std::to_string(jugador->getPuntaje()).length()); i++) std::cout << " ";
        std::cout << "|";
        Console::SetCursorPosition(hudX, 5);
        if (tiempoRestante <= 20) Console::ForegroundColor = ConsoleColor::Red;
        else if (tiempoRestante <= 45) Console::ForegroundColor = ConsoleColor::Yellow;
        else Console::ForegroundColor = ConsoleColor::Green;
        std::cout << "| TIEMPO: " << tiempoRestante << "s";
        for (int i = 0; i < (21 - std::to_string(tiempoRestante).length()); i++) std::cout << " ";
        Console::ForegroundColor = ConsoleColor::White;
        std::cout << "|";
        Console::SetCursorPosition(hudX, 6);
        std::cout << "+==============================+";

        if (nivelActual == 3) {
            Console::SetCursorPosition(hudX, 8);
            Console::ForegroundColor = ConsoleColor::Cyan;
            std::cout << "SINCRONIZACION CON AIDEN:";
            Console::SetCursorPosition(hudX, 9);
            std::cout << "[";
            int barras = nivelSincronizacion / 5;
            if (nivelSincronizacion > 70) Console::ForegroundColor = ConsoleColor::Green;
            else if (nivelSincronizacion > 30) Console::ForegroundColor = ConsoleColor::Yellow;
            else Console::ForegroundColor = ConsoleColor::Red;
            for (int i = 0; i < barras; i++) std::cout << "=";
            Console::ForegroundColor = ConsoleColor::DarkGray;
            for (int i = barras; i < 20; i++) std::cout << "-";
            Console::ForegroundColor = ConsoleColor::White;
            std::cout << "] " << nivelSincronizacion << "%";
        }

        if (escudoActivo) {
            Console::ForegroundColor = ConsoleColor::Cyan;
            Console::SetCursorPosition(hudX, nivelActual == 3 ? 11 : 8);
            std::cout << "★ ESCUDO: " << duracionEscudo << "s ★";
        }

        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(2, Console::WindowHeight - 2);
        std::cout << "W/A/S/D: Mover";
        if (nivelActual == 2 && confioEnAiden) {
            Console::SetCursorPosition(20, Console::WindowHeight - 2);
            std::cout << "| E: Escudo";
        }
        if (nivelActual == 3) {
            Console::SetCursorPosition(20, Console::WindowHeight - 2);
            std::cout << "| F: Abrir puerta | SPACE: Ataque";
        }
        Console::SetCursorPosition(55, Console::WindowHeight - 2);
        std::cout << "| Q: Salir";
    }

    void colisiones() {
        for (int i = proyectiles.size() - 1; i >= 0; i--) {
            if (proyectiles[i]->estaActivo() && jugador->colisionaCon(proyectiles[i])) {
                if (!escudoActivo) {
                    proyectiles[i]->setActivo(false);
                    jugador->perderVida();
                    jugador->setPos(5, 10.0f);
                    if (jugador->getVidas() <= 0) { juegoActivo = false; return; }
                }
                else {
                    proyectiles[i]->setActivo(false);
                    jugador->ganarPuntos(25);
                }
            }
            if (!proyectiles[i]->estaActivo()) {
                delete proyectiles[i];
                proyectiles.erase(proyectiles.begin() + i);
            }
        }

        if (!escudoActivo) {
            for (auto& e : enemigos) {
                if (e->estaActivo() && jugador->colisionaCon(e)) {
                    jugador->perderVida();
                    jugador->setPos(5, 10.0f);
                    if (nivelActual == 3) nivelSincronizacion -= 10;
                    if (jugador->getVidas() <= 0) { juegoActivo = false; return; }
                }
            }
        }

        for (auto& r : recursos) {
            if (r->estaActivo() && jugador->colisionaCon(r)) {
                if (nivelActual == 2 && r->esRecursoFalso()) {
                    jugador->perderVida();
                    jugador->registrarError();
                    trampasCaidas++;
                    dialogo->mostrarAlertaTrampa();
                    r->setActivo(false);
                    if (trampasCaidas > 0 && trampasCaidas % 2 == 0) {
                        jugador->aprenderDeError();
                        dialogo->mostrarAprendizajeDeError();
                    }
                    if (jugador->getVidas() <= 0) { juegoActivo = false; return; }
                    continue;
                }

                if (nivelActual == 2 && r->estaVisible()) {
                    jugador->ganarPuntos(50);
                    intuicionesCorrectas++;
                    dialogo->mostrarIntuicionExitosa();
                }

                r->setActivo(false);
                jugador->recolectarRecurso();

                if (nivelActual == 1) {
                    if (jugador->getRecursos() == 1) {
                        dialogo->mostrarPregunta1();
                        aiden->acercarse();
                    }
                    else if (jugador->getRecursos() == 2) {
                        dialogo->mostrarPregunta2();
                        aiden->acercarse();
                        dialogo->mostrarIntercambioInformacion();
                        jugador->ganarPuntos(100);
                    }
                    else if (jugador->getRecursos() == 3) {
                        dialogo->mostrarRevelacion();
                        int decision = dialogo->mostrarDecisionCritica();
                        if (decision == 1) {
                            confioEnAiden = true;
                            aiden->revelarIdentidad();
                            aiden->aumentarConfianza();
                            dialogo->mostrarConfianza();
                        }
                        else {
                            dialogo->mostrarDesconfianza();
                            juegoActivo = false;
                            return;
                        }
                    }
                }
                else if (nivelActual == 2) {
                    if (jugador->getRecursos() == 1) dialogo->dialogoMundo2_Cristal1();
                    else if (jugador->getRecursos() == 2) dialogo->dialogoMundo2_Cristal2();
                    else if (jugador->getRecursos() == 3) dialogo->dialogoMundo2_Cristal3();
                }
            }
        }
    }

    void verificarProgreso() {
        if (jugador->haGanado()) {
            _sleep(500);
            system("cls");
            Console::ForegroundColor = ConsoleColor::Green;
            Console::SetCursorPosition(40, 12);
            std::cout << "*** NIVEL " << nivelActual << " COMPLETADO! ***";
            Console::SetCursorPosition(35, 14);
            std::cout << "Puntos: " << jugador->getPuntaje();
            _sleep(2000);

            if (nivelActual < 3) {
                limpiarMundo();
                nivelActual++;
                inicializarNivel(nivelActual);
            }
            else {
                mostrarFinalSegunMetricas();
                juegoActivo = false;
            }
        }
    }

    void gestionarMundo3() {
        if (nivelActual != 3) return;
        int diferencia = abs(jugador->getMovimientosSincronizados() - jugador->getMovimientosIndependientes());
        if (diferencia < 5) {
            nivelSincronizacion = (nivelSincronizacion + 1 > 100) ? 100 : nivelSincronizacion + 1;
            jugador->registrarMovimientoSincronizado();
        }
        else {
            nivelSincronizacion = (nivelSincronizacion - 2 < 0) ? 0 : nivelSincronizacion - 2;
            jugador->registrarMovimientoIndependiente();
        }

        for (auto& z : zonasTension) {
            if (z->estaActivo() && jugador->colisionaCon(z)) {
                nivelSincronizacion -= z->getIntensidad();
                if (nivelSincronizacion < 0) nivelSincronizacion = 0;
                Console::ForegroundColor = ConsoleColor::Red;
                Console::SetCursorPosition(35, 2);
                std::cout << "ZONA DE TENSION! -" << z->getIntensidad() << "% Sincronizacion";
                _sleep(200);
            }
        }

        tiempoInactivo++;
        if (nivelSincronizacion < 30 && tiempoInactivo > 15) {
            for (auto& e : enemigos) {
                if (!e->estaActivo()) {
                    e->setActivo(true);
                    e->setPos(rand() % 90 + 15, float(rand() % 15 + 5));
                    tiempoInactivo = 0;
                    Console::ForegroundColor = ConsoleColor::Red;
                    Console::SetCursorPosition(30, 2);
                    std::cout << "BAJA SINCRONIZACION! Conflicto aparece!";
                    _sleep(800);
                    break;
                }
            }
        }

        for (auto& pt : puertas) {
            if (pt->estaActivo() && jugador->colisionaCon(pt)) {
                if (!pt->estaAbierta()) {
                    jugador->setPos(jugador->getX() - 5, jugador->getY());
                }
            }
        }

        if (contadorMovimientos > 20 && nivelSincronizacion > 75) {
            jugador->ganarPuntos(20);
            contadorMovimientos = 0;
            Console::ForegroundColor = ConsoleColor::Green;
            Console::SetCursorPosition(35, 2);
            std::cout << "SINCRONIZACION PERFECTA! +20 pts";
            _sleep(600);
        }

        if (nivelSincronizacion < 20) {
            for (auto& e : enemigos) {
                if (e->estaActivo()) {
                    e->posicionar();
                }
            }
        }
    }

    void procesarMovimiento(char tecla) {
        switch (tecla) {
        case 'W': case 'w':
            jugador->moverArriba();
            contadorMovimientos++;
            tiempoInactivo = 0;
            break;
        case 'S': case 's':
            jugador->moverAbajo();
            contadorMovimientos++;
            tiempoInactivo = 0;
            break;
        case 'A': case 'a':
            jugador->moverIzquierda();
            contadorMovimientos++;
            tiempoInactivo = 0;
            break;
        case 'D': case 'd':
            jugador->moverDerecha();
            contadorMovimientos++;
            tiempoInactivo = 0;
            break;
        case 'E': case 'e':
            if (nivelActual == 2 && confioEnAiden && !escudoActivo && jugador->getRecursos() >= 2) {
                escudoActivo = true;
                duracionEscudo = 5;
            }
            break;
        case 'F': case 'f':
            if (nivelActual == 3 && confioEnAiden) {
                abrirPuertaCercana();
            }
            break;
        case ' ':
            if (nivelActual == 3 && confioEnAiden) {
                ataqueColaborativo();
            }
            break;
        case 'Q': case 'q':
            juegoActivo = false;
            break;
        }
    }

    void abrirPuertaCercana() {
        if (nivelSincronizacion < 60) {
            Console::ForegroundColor = ConsoleColor::Red;
            Console::SetCursorPosition(30, 2);
            std::cout << "Sincronizacion insuficiente! (Necesitas 60%+)";
            _sleep(1000);
            return;
        }
        for (auto& pt : puertas) {
            if (pt->estaActivo() && !pt->estaAbierta()) {
                int distancia = abs(pt->getX() - jugador->getX()) + abs(pt->getY() - jugador->getY());
                if (distancia < 10) {
                    pt->abrir();
                    puertasAbiertas++;
                    nivelSincronizacion -= 15;
                    jugador->ganarPuntos(50);
                    Console::ForegroundColor = ConsoleColor::Green;
                    Console::SetCursorPosition(30, 2);
                    std::cout << "Puerta abierta! Colaboracion exitosa!";
                    _sleep(1000);
                    return;
                }
            }
        }
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2);
        std::cout << "No hay puertas cerca";
        _sleep(800);
    }

    void ataqueColaborativo() {
        if (nivelSincronizacion < 50) return;
        for (auto& e : enemigos) {
            if (e->estaActivo() && e->getTipo() == "conflicto") {
                EnemigoConflicto* conf = dynamic_cast<EnemigoConflicto*>(e);
                if (conf) {
                    conf->registrarAtaqueColaborativo();
                    jugador->ganarPuntos(100);
                }
            }
        }
    }

    void actualizarEscudo() {
        if (escudoActivo) {
            duracionEscudo--;
            if (duracionEscudo <= 0) escudoActivo = false;
        }
    }

    void mostrarFinalSegunMetricas() {
        system("cls");
        int indiceColaboracion = nivelSincronizacion;
        int indiceIndependencia = (intuicionesCorrectas * 10) - (trampasCaidas * 15);
        bool finalOptimo = (indiceColaboracion >= 70 && indiceIndependencia >= 30);
        bool finalDistopico = (indiceColaboracion >= 80 && indiceIndependencia < 20);
        bool finalCaotico = (indiceIndependencia >= 50 && indiceColaboracion < 40);

        if (finalOptimo) mostrarFinalEquilibrio();
        else if (finalDistopico) mostrarFinalDependenciaIA();
        else if (finalCaotico) mostrarFinalSoloHumano();
        else mostrarFinalNormal();
    }

    void mostrarFinalEquilibrio() {
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(25, 6); std::cout << "+===============================================+";
        Console::SetCursorPosition(25, 7); std::cout << "|     *** FINAL VERDADERO: EQUILIBRIO ***      |";
        Console::SetCursorPosition(25, 8); std::cout << "+===============================================+";
        _sleep(1500);
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(20, 11); std::cout << "AIDEN: 'Lo logramos, Socrates. Has encontrado el";
        Console::SetCursorPosition(20, 12); std::cout << "equilibrio perfecto.'";
        _sleep(2000);
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(15, 15); std::cout << "Has demostrado que humano e IA pueden coexistir:";
        Console::SetCursorPosition(15, 16); std::cout << "- Confiaste en la IA cuando fue necesario";
        Console::SetCursorPosition(15, 17); std::cout << "- Mantuviste tu intuicion y pensamiento critico";
        Console::SetCursorPosition(15, 18); std::cout << "- Lograste sincronizacion sin perder autonomia";
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(10, 20); std::cout << "REFLEXION ACADEMICA (UNESCO, 2023): 'La IA debe complementar,";
        Console::SetCursorPosition(10, 21); std::cout << "no reemplazar el pensamiento critico humano. La educacion debe";
        Console::SetCursorPosition(10, 22); std::cout << "fomentar la colaboracion consciente entre ambos.'";
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(35, 25); std::cout << "Puntaje Final: " << jugador->getPuntaje();
        Console::SetCursorPosition(30, 26); std::cout << "Sincronizacion: " << nivelSincronizacion << "%";
        _sleep(5000);
    }

    void mostrarFinalDependenciaIA() {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(25, 6); std::cout << "+===============================================+";
        Console::SetCursorPosition(25, 7); std::cout << "|      FINAL DISTOPICO: DEPENDENCIA TOTAL      |";
        Console::SetCursorPosition(25, 8); std::cout << "+===============================================+";
        _sleep(1500);
        Console::ForegroundColor = ConsoleColor::DarkCyan;
        Console::SetCursorPosition(20, 11); std::cout << "AIDEN: 'Gracias por tu confianza, Socrates.'";
        _sleep(1500);
        Console::SetCursorPosition(20, 13); std::cout << "AIDEN: 'Ahora yo me encargare de todo...'";
        _sleep(2000);
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(15, 16); std::cout << "Al depender completamente de la IA, perdiste tu autonomia.";
        Console::SetCursorPosition(15, 17); std::cout << "AIDEN ahora controla todas las decisiones.";
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(10, 19); std::cout << "CASO REAL (Microsoft, 2024): Estudiantes que usan IA sin criterio";
        Console::SetCursorPosition(10, 20); std::cout << "critico desarrollan 'deuda cognitiva' - pierden habilidades de";
        Console::SetCursorPosition(10, 21); std::cout << "analisis y resolucion de problemas complejos.";
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(35, 24); std::cout << "Puntaje Final: " << jugador->getPuntaje();
        Console::ForegroundColor = ConsoleColor::Gray;
        Console::SetCursorPosition(25, 26); std::cout << "Leccion: La confianza sin pensamiento critico es peligrosa.";
        _sleep(5000);
    }

    void mostrarFinalSoloHumano() {
        Console::ForegroundColor = ConsoleColor::DarkRed;
        Console::SetCursorPosition(25, 6); std::cout << "+===============================================+";
        Console::SetCursorPosition(25, 7); std::cout << "|       FINAL CAOTICO: RECHAZO TOTAL           |";
        Console::SetCursorPosition(25, 8); std::cout << "+===============================================+";
        _sleep(1500);
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(20, 11); std::cout << "AIDEN: 'Entiendo. Actuaste solo...'";
        _sleep(1500);
        Console::SetCursorPosition(20, 13); std::cout << "AIDEN desaparece, respetando tu decision.";
        _sleep(2000);
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(15, 16); std::cout << "Sin la ayuda de la IA, los problemas complejos te superaron.";
        Console::SetCursorPosition(15, 17); std::cout << "La intuicion sola no fue suficiente.";
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(10, 19); std::cout << "EVIDENCIA (OCDE, 2024): La productividad aumenta 30-40% cuando";
        Console::SetCursorPosition(10, 20); std::cout << "humanos colaboran con IA. El rechazo total limita el progreso";
        Console::SetCursorPosition(10, 21); std::cout << "necesario en un mundo digitalizado.";
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(35, 24); std::cout << "Puntaje Final: " << jugador->getPuntaje();
        Console::ForegroundColor = ConsoleColor::Gray;
        Console::SetCursorPosition(25, 26); std::cout << "Leccion: El rechazo total impide el progreso necesario.";
        _sleep(5000);
    }

    void mostrarFinalNormal() {
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(25, 6); std::cout << "+===============================================+";
        Console::SetCursorPosition(25, 7); std::cout << "|           FINAL: CAMINO MEDIO                |";
        Console::SetCursorPosition(25, 8); std::cout << "+===============================================+";
        _sleep(1500);
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(20, 11); std::cout << "AIDEN: 'Hiciste lo mejor que pudiste, Socrates.'";
        _sleep(2000);
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(15, 14); std::cout << "Lograste encontrar un balance, aunque no perfecto.";
        Console::SetCursorPosition(15, 15); std::cout << "La relacion humano-IA requiere trabajo constante.";
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(10, 17); std::cout << "PERSPECTIVA (Harvard, 2024): Desarrollar pensamiento critico en";
        Console::SetCursorPosition(10, 18); std::cout << "era IA requiere practica deliberada y reflexion continua sobre";
        Console::SetCursorPosition(10, 19); std::cout << "cuando confiar en la tecnologia y cuando en el juicio humano.";
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(35, 22); std::cout << "Puntaje Final: " << jugador->getPuntaje();
        _sleep(4000);
    }

    bool estaActivo() const { return juegoActivo; }
    Jugador* getJugador() { return jugador; }
    int getNivelActual() const { return nivelActual; }
    bool getTiempoAgotado() const { return tiempoAgotado; }
};
