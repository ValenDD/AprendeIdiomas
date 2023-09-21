
#include "Usuario.h"
#include "Idioma.h"

using namespace std;

Idioma::Idioma(string nombre)
{
    setNombre(nombre);
};

Idioma::~Idioma() {}

std::string Idioma::getNombre()
{
    return nombre;
};

void Idioma::setNombre(string nombre)
{
    this->nombre = nombre;
};

// Agrega un observador al set de observadores
void Idioma::agregarObservador(Usuario *obs)
{
    this->ColObservadores.insert(obs);
};

// Elimina un observador del set de observadores
void Idioma::eliminarObservador(Usuario *obs)
{
    this->ColObservadores.erase(obs);
};

// Chequea que el usuario este suscrito al idioma
//  bool Idioma::estaSuscrito(string nickname){
//      for (set<Usuario>::iterator it = ColObservadores.begin(); it != ColObservadores.end(); ++it) {
//          if (it->getNickname() == nickname) {
//              return true;
//          }
//      }
//      return false;
//  }

// void Idioma::Actualizar(){
//     /*for (set<Usuario>::iterator it = ColObservadores.begin(); it != ColObservadores.end(); ++it) {
//         it->notificar();
//     }
//     */
// }
