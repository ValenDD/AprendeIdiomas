#include "DataIdioma.h"

DataIdioma::DataIdioma(string nombre) {
    this->nombre = nombre;
}


DataIdioma::~DataIdioma() {
}

string DataIdioma::getNombre() {
    return this->nombre;
}

