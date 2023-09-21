#ifndef Leccion_h
#define Leccion_h

#include <string>
#include <set>
#include "Ejercicio.h"
#include "DataEjercicio.h"
#include "DataLeccion.h"
#include "Estudiante.h"

using namespace std;

class Leccion
{
private:
    string tema;
    string objetivo;
    int cantEjercicios;
    set<Ejercicio*> ejercicios;

public:
    Leccion(string, string);
    ~Leccion();

    string getTema();
    string getObjetivo();
    int getCantEjercicios();
    
    void setTema(string);
    void setObjetivo(string);
    void setCantEjercicios(int);
    
    void agregarLink();
    set<DataEjercicio*> getEjerciciosIncompletos(Estudiante);
};

#endif  