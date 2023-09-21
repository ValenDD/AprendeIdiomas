#ifndef PROFESOR_H
#define PROFESOR_H

#include "Usuario.h"
#include <string>
#include <set>
#include "Idioma.h"

class Profesor : public Usuario
{
private:
    std::string instituto;
    set<Idioma *> especializaciones;

public:
    Profesor(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion, std::string instituto, set<Idioma *> especializaciones);
    virtual ~Profesor();

    std::string getInstituto();
    set<Idioma *> getEspecializaciones();
    set<std::string> getSetIdiomas();

    void setEspecializaciones(set<Idioma *> especializaciones);

    void setInstituto(std::string instituto);

    // set<string> getProfe();
    //  void agregarLink(Idioma idi);
    //  void notificar(DataNotificacion notificacion) override;
    //  set<DataNotif> leerNotificaciones() override;
};

#endif