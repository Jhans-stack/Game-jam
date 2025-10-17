#pragma once
#include "Mundo.h"

class MundoColaborativo : public Mundo {
public:
    MundoColaborativo() : Mundo(3, "EL PUENTE DEL FUTURO",
        "¿Como mantener humanidad aprovechando la IA?",
        "Solo la colaboracion perfecta puede salvarte.") {
    }
};