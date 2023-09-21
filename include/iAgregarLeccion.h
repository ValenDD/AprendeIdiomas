#ifndef IAgregarLeccion_h
#define IAgregarLeccion_h

using namespace std;

#include <set>
#include <string>
#include "Ejercicio.h"
#include "DataCurso.h"

class IAgregarLeccion
{
public:
    virtual set<DataCurso *> listarCursosNoHab() = 0; 
    virtual void agregarLeccion(string, string, string) = 0;
    virtual void ingresarEjercicio(enumTipo, string) = 0;
    virtual void ejCompletar(string, string) = 0;
    virtual void ejTraducir(string, string) = 0;
};

#endif