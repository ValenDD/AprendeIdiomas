
#ifndef IDIOMA_H
#define IDIOMA_H

#include <string>

#include "Usuario.h"
#include <set>
// #include "Curso.h"

using namespace std;

class Idioma
{
private:
    string nombre;
    set<Usuario *> ColObservadores;

public:
    Idioma(string nombre);
    virtual ~Idioma();
    string getNombre();
    void setNombre(string nombre);
    void agregarObservador(Usuario *obs);
    void eliminarObservador(Usuario *obs);
    // bool estaSuscrito(string nickname);
    // void Actualizar();
};
#endif
