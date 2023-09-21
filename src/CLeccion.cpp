#include <string>
#include <set>
#include "CLeccion.h"

using namespace std;

CLeccion *CLeccion::ControladorLeccion = nullptr;

CLeccion::CLeccion() {};

CLeccion::~CLeccion() {};

CLeccion *CLeccion::getInstance()
{
    if (ControladorLeccion == nullptr)
    {
        ControladorLeccion = new CLeccion();
    }
    return ControladorLeccion;
};

void CLeccion::agregarLeccion(string tema, string objetivo)
{
    l = new Leccion(tema, objetivo);
    this->Lecciones.insert(l);
    this->leccsAAgregar.insert(l);
}

set<DataCurso *> CLeccion::listarCursosNoHab(){
    CCurso *cc = this -> ControladorCurso -> getInstance();
    
    return cc -> listarCursosHabilitados();
};

void CLeccion::agregarLeccion(string nomCurso, string tema, string objetivo){
    this -> nomCurso = nomCurso;
    this -> tema = tema;
    this -> objetivo = objetivo;
};


    
void CLeccion::ingresarEjercicio(enumTipo tipo, string descripcion){
    this -> tipo = tipo;
    this -> descripcion = descripcion;
}

void CLeccion:: ejCompletar(string frase, string solucion){
    this -> frase = frase;
    this -> solucion = solucion;
}

void CLeccion:: ejTraducir(string frase, string solucion){
    this -> frase = frase;
    this -> solucion = solucion;
}