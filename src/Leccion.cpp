#include "Leccion.h"
#include <string>
#include <set>

Leccion::Leccion(string tema, string objetivo)
{
    setTema(tema);
    setObjetivo(objetivo);
};

Leccion::~Leccion()
{
    // for (Ejercicio* itr: ejercicios)
    // {
    //     ????????
    // }
};

string Leccion::getTema()
{
    return this->tema;
};

string Leccion::getObjetivo()
{
    return this->objetivo;
};

int Leccion::getCantEjercicios()
{
    return this->cantEjercicios;
};

void Leccion::setTema(string tema)
{
    this->tema = tema;
};

void Leccion::setObjetivo(string objetivo)
{
    this->objetivo = objetivo;
};

void Leccion::setCantEjercicios(int cantEjercicios)
{
    this->cantEjercicios = cantEjercicios;
};

