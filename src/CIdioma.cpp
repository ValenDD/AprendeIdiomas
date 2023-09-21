#include "CIdioma.h"
#include <iostream>

CIdioma *CIdioma::instanciaIdioma = nullptr;

CIdioma &CIdioma::getInstance()
{
    if (instanciaIdioma == nullptr)
    {
        instanciaIdioma = new CIdioma();
    }

    return *instanciaIdioma;
};

CIdioma::CIdioma()
{
    MemNombre = "";
    this->ColIdiomas = map<string, Idioma *>();
};

CIdioma::~CIdioma()
{
    map<string, Idioma *>::iterator it;
    for (it = ColIdiomas.begin(); it != ColIdiomas.end(); ++it)
    {
        Idioma *i = it->second;
        i->~Idioma();
    }
    ColIdiomas.clear();
    delete instanciaIdioma;
};

bool CIdioma::existeIdioma(string nombre)
{

    if (ColIdiomas.find(nombre) == ColIdiomas.end())
    {
        return false;
    }
    else
    {
        return true;
    }
};

Idioma *CIdioma::encontrarIdioma(string nombre)
{
    return ColIdiomas.find(nombre)->second;
};

set<string *> CIdioma::mostrarIdiomas()
{
    set<string *> s;
    map<string, Idioma *>::iterator it;
    for (it = ColIdiomas.begin(); it != ColIdiomas.end(); ++it)
    {
        Idioma *i = it->second;
        string *d = new string(i->getNombre());
        s.insert(d);
    }
    return s;
};

string *CIdioma::getDataIdioma(string nombre)
{
    Idioma *i = ColIdiomas.find(nombre)->second;
    string *d = new string(i->getNombre());
    return d;
};

void CIdioma::ingresoDatos(string nombre)
{
    if (!existeIdioma(nombre))
    {
        Idioma *i = new Idioma(nombre);
        ColIdiomas.insert(pair<string, Idioma *>(nombre, i));
        printf("Idioma ingresado con exito\n");
    }
    else
    {
        printf("El idioma ya existe\n");
    }
};

set<DataIdioma *> CIdioma::listarIdiomas()
{
    set<DataIdioma *> s;
    map<string, Idioma *>::iterator it;
    for (it = ColIdiomas.begin(); it != ColIdiomas.end(); ++it)
    {
        Idioma *i = it->second;
        DataIdioma *d = new DataIdioma(i->getNombre());
        s.insert(d);
    }
    return s;
};

void CIdioma::selecIdioma(string idioma)
{
    MemNombre = idioma;
};

/*void CIdioma::desuscribir(string nickname) {
    map<string, Idioma*>::iterator it;
    for (it = ColIdiomas.begin(); it != ColIdiomas.end(); ++it){
        Idioma *i = it->second;
        if (i->estaSuscrito(nickname)){
            i->eliminarObservador(nickname);
        }
    }
}
*/
