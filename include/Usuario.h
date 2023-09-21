#ifndef USUARIO_H
#define USUARIO_H

#include <string>
// #include "IAltaUsuario.h"
// #include "IConsultarUsuario.h"

class Usuario
{
private:
    std::string nombre;
    std::string nickname;
    std::string contrasenia;
    std::string descripcion;
    // set<DataNotificacion> notificaciones;

public:
    Usuario(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion);

    std::string getNombre();
    std::string getNickname();
    std::string getContrasenia();
    std::string getDescripcion();

    void setNombre(std::string nombre);
    void setNickname(std::string nickname);
    void setContrasenia(std::string contrasenia);
    void setDescripcion(std::string descripcion);

    // virtual void notificar(DataNotificacion notificacion);
    // virtual set<DataNotif> leerNotificaciones();
};

#endif