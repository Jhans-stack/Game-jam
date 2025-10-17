#pragma once
#include "Mundo.h"

class MundoIA : public Mundo {
public:
    MundoIA() : Mundo(1, "LA MAQUINA SUPREMA",
        "¿Estarias dispuesto a renunciar a tu libre albedrio?",
        "Mundo hiperdigitalizado donde algoritmos gobiernan todo.") {
    }
};