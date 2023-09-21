#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Usuario.h"
#include <string>
#include "Estructuras.h"

class Estudiante : public Usuario
{
private:
    std::string pais;
    Fecha fechaNacimiento;

public:
    Estudiante(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion, std::string pais, Fecha fechaNacimiento);
    ~Estudiante();

    std::string getPais();
    Fecha getFechaNacimiento();

    void setPais(std::string pais);
    void setFechaNacimiento(Fecha fechaNacimiento);

    // set<DataCursos> listarCursosNoAprobados(std::string nickname);
    // void eliminarAvance(std::string e);
    // set(dataEjercicio) listarEjerciciosPendientes(std::string nomCurso);
    // DataCurso getCursos();
    // DataEjercicio listarEjercicio();
    // DataEstudiante crearData();
    // set(DatainfoEstudiante) listarInfoCursos();

    // void notificar(DataNotificacion notificacion) override;
    // set<DataNotif> leerNotificaciones() override;
};

#endif
