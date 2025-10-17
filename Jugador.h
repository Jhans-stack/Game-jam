#pragma once
#include "Entidad.h"

class Jugador : public Entidad {
private:
    int vidas, recursosRecolectados, puntaje;
    std::string direccion;
    int movimientosIndependientes, movimientosSincronizados;
    int erroresAprendizaje, conocimientoAdquirido;
public:
    Jugador(int px, float py) : Entidad(px, py, 2, 2, 4, 7) {
        vidas = 3; recursosRecolectados = 0; puntaje = 0; direccion = "frente";
        movimientosIndependientes = 0; movimientosSincronizados = 0;
        erroresAprendizaje = 0; conocimientoAdquirido = 0;
    }
    void borrar() override {
        for (int i = 0; i < 4; i++) {
            Console::SetCursorPosition(x_anterior, int(y_anterior) + i);
            std::cout << "       ";
        }
    }
    void posicionar() override {}
    void moverArriba() {
        guardarPosicionAnterior();
        if (y > 2) { y -= dy; direccion = "atras"; }
    }
    void moverAbajo() {
        guardarPosicionAnterior();
        if (y + alto < Console::WindowHeight - 5) { y += dy; direccion = "frente"; }
    }
    void moverIzquierda() {
        guardarPosicionAnterior();
        if (x > 2) { x -= dx; direccion = "izq"; }
    }
    void moverDerecha() {
        guardarPosicionAnterior();
        if (x + ancho < Console::WindowWidth - 2) { x += dx; direccion = "der"; }
    }
    void dibujar() override {
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(x, int(y));     std::cout << "   O   ";
        Console::SetCursorPosition(x, int(y) + 1); std::cout << "  /|" << char(92) << "  ";
        Console::SetCursorPosition(x, int(y) + 2); std::cout << "  / " << char(92) << "  ";
        Console::SetCursorPosition(x, int(y) + 3); std::cout << " SOCRA ";
    }
    void perderVida() { if (vidas > 0) vidas--; }
    void recolectarRecurso() { recursosRecolectados++; puntaje += 100; }
    void ganarPuntos(int p) { puntaje += p; }
    void reiniciarRecursos() { recursosRecolectados = 0; }
    int getVidas() const { return vidas; }
    int getRecursos() const { return recursosRecolectados; }
    int getPuntaje() const { return puntaje; }
    bool haGanado() const { return recursosRecolectados >= 3; }
    void registrarMovimientoIndependiente() { movimientosIndependientes++; }
    void registrarMovimientoSincronizado() { movimientosSincronizados++; }
    int getMovimientosIndependientes() const { return movimientosIndependientes; }
    int getMovimientosSincronizados() const { return movimientosSincronizados; }
    void registrarError() { erroresAprendizaje++; }
    void aprenderDeError() { conocimientoAdquirido++; puntaje += 50; }
    int getErrores() const { return erroresAprendizaje; }
    int getConocimiento() const { return conocimientoAdquirido; }
};