#include "CUsuario.h"
#include "DataEstudiante.h"
#include "DataProfesor.h"
#include "CIdioma.h"

CUsuario::CUsuario()
{
    this->Rnombre = "";
    this->Rnickname = "";
    this->Rcontrasenia = "";
    this->Rdescripcion = "";
    this->Rinstituto = "";
    this->Usuarios = std::list<Usuario *>();
    this->Estudiantes = std::list<Estudiante *>();
    this->Profesores = std::list<Profesor *>();
};

CUsuario *CUsuario::instanciaUsuario = nullptr;

CUsuario &CUsuario::getInstance()
{
    if (instanciaUsuario == nullptr)
    {
        instanciaUsuario = new CUsuario();
    }
    return *instanciaUsuario;
};

void CUsuario::ingresarDatos(std::string nombre, std::string nickname, std::string contrasena, std::string descripcion)
{
    this->Rnombre = nombre;
    this->Rnickname = nickname;
    this->Rcontrasenia = contrasena;
    this->Rdescripcion = descripcion;
};

bool CUsuario::ingresoEstudiante(std::string pais, Fecha fechaNacimiento)
{
    Estudiante *estudiante = new Estudiante(getNombre(), getNickname(), getContrasenia(), getDescripcion(), pais, fechaNacimiento);
    this->Estudiantes.push_back(estudiante);
    this->Usuarios.push_back(estudiante);
    return true;
};

void CUsuario::ingresoInstituto(std::string instituto)
{
    this->Rinstituto = instituto;
};

bool CUsuario::ingresoIdioma(std::string idioma)
{

    this->Ridiomas.insert(idioma);
    return true;
};

bool CUsuario::ingresoProfesor()
{
    set<Idioma *> idiomas = linkearIdiomas();
    Profesor *profesor = new Profesor(getNombre(), getNickname(), getContrasenia(), getDescripcion(), getInstituto(), linkearIdiomas());

    this->Profesores.push_back(profesor);
    this->Usuarios.push_back(profesor);
    return true;
};

DataEstudiante *CUsuario::consultarEstudiante(std::string nickname)
{
    Estudiante *student = buscarEstudiante(nickname);
    DataEstudiante *dataEstudiante = new DataEstudiante(student->getNombre(), student->getDescripcion(), student->getPais(), student->getFechaNacimiento());
    return dataEstudiante;
};

DataProfesor *CUsuario::consultarProfesor(std::string nickname)
{
    Profesor *profesor = buscarProfesor(nickname);
    DataProfesor *dataProfesor = new DataProfesor(profesor->getNombre(), profesor->getDescripcion(), profesor->getInstituto(), profesor->getSetIdiomas());
    return dataProfesor;
};

Profesor *CUsuario::buscarProfesor(std::string nickname)
{
    std::list<Profesor *>::iterator it = this->Profesores.begin();
    while (it != this->Profesores.end() && (*it)->getNickname() != nickname)
    {
        ++it;
    }
    if (it == this->Profesores.end())
    {
        return nullptr;
    }
    else
    {
        return *it;
    }
};

Estudiante *CUsuario::buscarEstudiante(std::string nickname)
{
    std::list<Estudiante *>::iterator it = this->Estudiantes.begin();
    while (it != this->Estudiantes.end() && (*it)->getNickname() != nickname)
    {
        ++it;
    }
    if (it == this->Estudiantes.end())
    {
        return nullptr;
    }
    else
    {
        return *it;
    }
};

void CUsuario::mostrarIdiomas()
{
    CIdioma &idioma = CIdioma::getInstance();
    set<string *> idiomas = idioma.mostrarIdiomas();
    set<string *>::iterator it = idiomas.begin();
    while (it != idiomas.end())
    {
        printf("%s\n", (*it)->c_str());
        ++it;
    }
};

std::string CUsuario::getNombre()
{
    return this->Rnombre;
};

std::string CUsuario::getNickname()
{
    return this->Rnickname;
};

std::string CUsuario::getContrasenia()
{
    return this->Rcontrasenia;
};

std::string CUsuario::getDescripcion()
{
    return this->Rdescripcion;
};

std::string CUsuario::getInstituto()
{
    return this->Rinstituto;
};

set<Idioma *> CUsuario::linkearIdiomas()
{
    set<Idioma *> s;
    set<string>::iterator it = this->Ridiomas.begin();
    CIdioma &idioma = CIdioma::getInstance();
    while (it != this->Ridiomas.end())
    {
        Idioma *I = idioma.encontrarIdioma(*it);
        s.insert(I);
        ++it;
    }
    return s;
};

set<string> CUsuario::getProfe()
{
    set<string> s;
    std::list<Profesor *>::iterator it = this->Profesores.begin();
    while (it != this->Profesores.end())
    {
        set<Idioma *> idiomas = (*it)->getEspecializaciones();
        set<Idioma *>::iterator it2 = idiomas.begin();
        while (it2 != idiomas.end())
        {
            s.insert((*it2)->getNombre());
            ++it2;
        }
        ++it;
    }
    return s;
};

set<DataProfesorGeneral *> CUsuario::mostrarProfesores()
{
    set<DataProfesorGeneral *> s;
    std::list<Profesor *>::iterator it = this->Profesores.begin();
    while (it != this->Profesores.end())
    {
        DataProfesorGeneral *dataProfesor = new DataProfesorGeneral((*it)->getNombre(), (*it)->getNickname(), (*it)->getContrasenia(), (*it)->getDescripcion(), (*it)->getInstituto(), (*it)->getSetIdiomas());
        s.insert(dataProfesor);
        ++it;
    }
    return s;
};