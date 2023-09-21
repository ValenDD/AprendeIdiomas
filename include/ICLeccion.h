#ifndef ICLeccion_h
#define ICLeccion_h

#include "Leccion.h"
#include <string>
#include <set>

class ICLeccion
{
private:
    set<Leccion*> Lecciones;
    ICLeccion();
    ~ICLeccion();

public:
    static ICLeccion *getInstance();

    void agregarLeccion(string, string);
    void agregarLink();
};

#endif