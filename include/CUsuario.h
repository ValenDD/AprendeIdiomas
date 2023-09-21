#ifndef CUSUARIO_H_
#define CUSUARIO_H_

class CCurso;

#include <string>
#include <set>
#include <list>

#include "IAltaUsuario.h"
#include "IConsultarUsuario.h"

#include "Usuario.h"
#include "Estudiante.h"

#include "DataUsuario.h"
#include "Profesor.h"
#include "DataProfesorGeneral.h"

class CUsuario : public IAltaUsuario, public IConsultarUsuario
{
private:
    IAltaUsuario *usuario;
    CUsuario();

    // Recuerda
    std::string Rnombre;
    std::string Rnickname;
    std::string Rcontrasenia;
    std::string Rdescripcion;
    std::string Rinstituto;
    set<string> Ridiomas;
    std::list<Usuario *> Usuarios;
    std::list<Estudiante *> Estudiantes;
    std::list<Profesor *> Profesores;
    static CUsuario *instanciaUsuario;

public:
    static CUsuario &getInstance();
    std::string getNombre();
    std::string getNickname();
    std::string getContrasenia();
    std::string getDescripcion();
    std::string getInstituto();
    set<Idioma *> linkearIdiomas();

    // funciones de la interfaz

    void ingresarDatos(std::string nombre, std::string nickname, std::string contrasena, std::string descripcion) override;
    bool ingresoEstudiante(std::string pais, Fecha fechaNacimiento) override;
    void ingresoInstituto(std::string instituto) override;
    DataEstudiante *consultarEstudiante(std::string nickname) override;
    DataProfesor *consultarProfesor(std::string nickname) override;
    bool ingresoProfesor() override;
    bool ingresoIdioma(std::string idioma) override;

    Estudiante *buscarEstudiante(std::string nickname);
    Profesor *buscarProfesor(std::string nickname);
    void mostrarIdiomas();
    set<string> getProfe();
    set<DataProfesorGeneral *> mostrarProfesores();
};

#endif
