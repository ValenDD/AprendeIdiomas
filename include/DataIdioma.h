#ifndef DATAIDIOMA_H
#define DATAIDIOMA_H

#include <string>
#include <set>

using namespace std;

class DataIdioma {
    private:
        string nombre;
    public:
        DataIdioma(string nombre);
        virtual ~DataIdioma();
        string getNombre();
};

#endif