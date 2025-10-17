#pragma once
#include "Mundo.h"

class MundoHumano : public Mundo {
public:
    MundoHumano() : Mundo(2, "LA LUZ DEL PENSAMIENTO",
        "¿La imperfeccion humana es debilidad o fortaleza?",
        "Mundo caotico donde la intuicion supera la logica.") {
    }
};