#pragma once
#include "pch.h"
#using <System.Drawing.dll>

using namespace System;
using namespace System::Drawing;

class Entidad {
protected:
    int x, x_anterior;
    float y, y_anterior;
    int dx, dy;
    int alto, ancho;
    bool activo;
public:
    Entidad(int px, float py, int pdx, int pdy, int palto, int pancho) {
        x = px; y = py; dx = pdx; dy = pdy; alto = palto; ancho = pancho; activo = true;
        x_anterior = px; y_anterior = py;
    }
    virtual ~Entidad() {}
    virtual void borrar() = 0;
    virtual void posicionar() = 0;
    virtual void dibujar() = 0;
    Rectangle obtenerRectangulo() { return Rectangle(x, int(y), ancho, alto); }
    int getX() const { return x; }
    int getY() const { return int(y); }
    bool estaActivo() const { return activo; }
    void setActivo(bool estado) { activo = estado; }
    void setPos(int px, float py) {
        x_anterior = x; y_anterior = y;
        x = px; y = py;
    }
    bool colisionaCon(Entidad* otro) {
        if (!activo || otro == nullptr || !otro->estaActivo()) return false;
        Rectangle r1 = obtenerRectangulo(); Rectangle r2 = otro->obtenerRectangulo();
        return r1.IntersectsWith(r2);
    }
    void guardarPosicionAnterior() { x_anterior = x; y_anterior = y; }
};