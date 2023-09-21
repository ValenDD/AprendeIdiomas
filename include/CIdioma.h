#ifndef CIDIOMA_H
#define CIDIOMA_H

#include <string>

#include <map>

#include "Idioma.h"
#include "IAltaIdioma.h"
#include "IConsultarIdioma.h"

using namespace std;

class CIdioma : public IAltaIdioma, public IConsultarIdioma
{
private:
    IAltaIdioma *crearIdioma;
    IConsultarIdioma *consultaI;
    static CIdioma *instanciaIdioma;
    CIdioma();
    string MemNombre; // Para uso de memoria
    map<string, Idioma *> ColIdiomas;

public:
    static CIdioma &getInstance();
    virtual ~CIdioma();
    bool existeIdioma(string nombre);
    set<string *> mostrarIdiomas();
    Idioma *encontrarIdioma(string nombre);
    string *getDataIdioma(string nombre);
    void selecIdioma(string idioma);
    //  void desuscribir(string nickname);

    // Metodo de IAltaIdioma
    void ingresoDatos(string nombre) override;

    // Metodo de IConsultarIdioma
    set<DataIdioma *> listarIdiomas() override;
};

#endif