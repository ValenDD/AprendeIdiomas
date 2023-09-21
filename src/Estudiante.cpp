#include "Estudiante.h"

Estudiante::Estudiante(std::string nombre, std::string nickname, std::string contrasenia, std::string descripcion, std::string pais, Fecha fechaNacimiento) : Usuario(nombre, nickname, contrasenia, descripcion)
{
    setPais(pais);
    setFechaNacimiento(fechaNacimiento);
};

Estudiante::~Estudiante(){};

std::string Estudiante::getPais()
{
    return this->pais;
};

Fecha Estudiante::getFechaNacimiento()
{
    return this->fechaNacimiento;
};

void Estudiante::setPais(std::string pais)
{
    this->pais = pais;
};

void Estudiante::setFechaNacimiento(Fecha fechaNacimiento)
{
    this->fechaNacimiento = fechaNacimiento;
};

// set<DataCursos> listarCursosNoAprobados(std::string nickname);
// void eliminarAvance(std::string e);
// set(dataEjercicio) listarEjerciciosPendientes(std::string nomCurso);
// DataCurso getCursos();
// DataEjercicio listarEjercicio();
// DataEstudiante crearData();
// set(DatainfoEstudiante) listarInfoCursos();

// void notificar(DataNotificacion notificacion) override;
// set<DataNotif> leerNotificaciones() override;