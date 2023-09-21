#ifndef CONSULTARIDIOMA_H
#define CONSULTARIDIOMA_H

#include <string>
#include <set>
#include "DataIdioma.h"

using namespace std;

class IConsultarIdioma
{
public:
    virtual set<DataIdioma *> listarIdiomas() = 0;
};

#endif