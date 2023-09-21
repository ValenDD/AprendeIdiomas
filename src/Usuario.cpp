#include "Usuario.h"

Usuario::Usuario(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion)
{
    setNombre(nombre);
    setNickname(nickname);
    setContrasenia(contrasenia);
    setDescripcion(descripcion);
};

std::string Usuario::getNombre()
{
    return this->nombre;
};

// set<dataNotificacion> Usuario::getNotificaciones()
// {
//     return this->notificaciones;
// };

// void Usuario::setNotificaciones(set<dataNotificacion> notificaciones)
// {
//     this->notificaciones = notificaciones;
// };

std::string Usuario::getNickname()
{
    return this->nickname;
};

std::string Usuario::getContrasenia()
{
    return this->contrasenia;
};

std::string Usuario::getDescripcion()
{
    return this->descripcion;
};

void Usuario::setNombre(std::string nombre)
{
    this->nombre = nombre;
};

void Usuario::setNickname(std::string nickname)
{
    this->nickname = nickname;
};

void Usuario::setContrasenia(std::string contrasenia)
{
    this->contrasenia = contrasenia;
};

void Usuario::setDescripcion(std::string descripcion)
{
    this->descripcion = descripcion;
};

// virtual void notificar(DataNotificacion notificacion);
// virtual set<DataNotif> leerNotificaciones();