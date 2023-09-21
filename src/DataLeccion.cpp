// #ifndef DataLeccion_h
// #define DataLeccion_h

// #include <string>
// #include <set>
// #include "Leccion.h"
// #include "DataEjercicio.h"

// using namespace std;

// class DataLeccion
// {
// private:
//     string tema;
//     string objetivo;
//     set<DataEjercicio*> ejercicios;

// public:
//     DataLeccion(string, string, set<DataEjercicio>);
//     ~DataLeccion();
    
//     string getTema();
//     string getObjetivo();

//     void setTema(string);
//     void setObjetivo(string);
    
//     set <DataEjercicio*> getEjercicios();
// };

// #endif

#include "DataLeccion.h"

using namespace std;

DataLeccion::DataLeccion (string a, string b, set<DataEjercicio *> c) {
    this-> tema = a;
    this-> objetivo = b;
    this-> ejercicios = c;
}

DataLeccion::~DataLeccion () {}

string DataLeccion::getTema () {
    return this-> tema;
}

string DataLeccion::getObjetivo () {
    return this-> objetivo;
}

void DataLeccion::setTema (string a) {
    this-> tema = a;
}

void DataLeccion::setObjetivo (string a) {
    this-> objetivo = a;
}

set<DataEjercicio *> DataLeccion::getEjercicios () {
    return this-> ejercicios;
}
