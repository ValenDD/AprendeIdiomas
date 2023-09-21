#ifndef IALTAUSUARIO_H
#define IALTAUSUARIO_H

#include <string>
#include "Estructuras.h"

class IAltaUsuario
{
public:
    virtual void ingresarDatos(std::string nombre, std::string nickname, std::string contrasena, std::string descripcion) = 0;
    virtual bool ingresoEstudiante(std::string pais, Fecha fechaNacimiento) = 0;
    virtual void ingresoInstituto(std::string instituto) = 0;
    virtual bool ingresoProfesor() = 0;
    virtual bool ingresoIdioma(std::string idioma) = 0;
};

#endif
