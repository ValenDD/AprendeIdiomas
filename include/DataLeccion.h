#ifndef DataLeccion_h
#define DataLeccion_h

#include <string>
#include <set>
#include "Leccion.h"
#include "DataEjercicio.h"

using namespace std;

class DataLeccion
{
private:
    string tema;
    string objetivo;
    set<DataEjercicio*> ejercicios;

public:
    DataLeccion(string, string, set<DataEjercicio*>);
    ~DataLeccion();
    
    string getTema();
    string getObjetivo();

    void setTema(string);
    void setObjetivo(string);
    
    set <DataEjercicio*> getEjercicios();
};

#endif