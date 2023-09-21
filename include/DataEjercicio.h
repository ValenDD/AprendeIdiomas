#ifndef DATAEJERCICIO_H
#define DATAEJERCICIO_H

#include <string>

enum Dificultad{
    Principiante,
    Medio,
    Avanzado
};

using namespace std;

class DataEjercicio {
    private:
        string tipo;
        string descripcion;
    
    public:
        string getTipo();
        string getDescripcion();
};
#endif