#ifndef DataCurso_h
#define DataCurso_h

#include <string>
#include <iostream>

#include "DataEjercicio.h"

using namespace std;

class DataCurso
{
private:
    string Nombre;
    string Descripcion;
    Dificultad Complejidad;
    int CantLecciones;
    bool Habilitado;
    int Promedio;
    string IdiomaC;
    string ProfesorC;

public:
    DataCurso(string, string, Dificultad, int, bool, int, string, string);
    ~DataCurso();

    string getNombre();
    string getDescripcion();
    Dificultad getComplejidad();
    int getCantLecciones();
    bool getHabilitado();
    int getPromedio();
    string getIdiomaC();
    string getProfesorC();
};

#endif