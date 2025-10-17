#pragma once
#include "Entidad.h"

class Enemigo : public Entidad {
protected:
    std::string tipo;
    int direccionX, direccionY;
    int salud;
public:
    Enemigo(int px, float py, int pdx, int pdy, int palto, int pancho, const std::string& t)
        : Entidad(px, py, pdx, pdy, palto, pancho), tipo(t) {
        direccionX = 1; direccionY = 0; salud = 100;
    }
    virtual ~Enemigo() {}
    std::string getTipo() { return tipo; }
    virtual bool puedeDisparar() { return false; }
    void recibirDanio(int cantidad) {
        salud -= cantidad;
        if (salud <= 0) activo = false;
    }
    int getSalud() const { return salud; }
};
