#ifndef DTEJERCICIO_H
#define DTEJERCICIO_H

#include <string>
#include "DataEjercicio.h"

using namespace std;

string DataEjercicio::getTipo() {
    return this->tipo;
}

string DataEjercicio::getDescripcion() {
    return this->descripcion;
}



#endif