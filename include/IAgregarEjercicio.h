#ifndef IAgregarEjercicio_h
#define IAgregarEjercicio_h

#include <set>
#include <string>
#include "DataCurso.h"
#include "DataLeccion.h"

using namespace std;

class IAgregarEjercicio
{
public:
    virtual set<DataCurso *> listarCursosNoHabilitados() = 0;
    virtual set<DataLeccion *> listarLeccion(string nomCurso) = 0;
    virtual void ingresarEjercicio(string nomLeccion, enumTipo tipoEjercicio, string descripcionEjercicio) = 0;
    virtual void ejCompletar(string frase, string solucion) = 0;
    virtual void ejTraducir(string frase, string solucion) = 0;
};

#endif