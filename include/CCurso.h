#ifndef CCURSO_H
#define CCURSO_H

class CLeccion;
class CUsuario;

#include <iostream>
#include <map>
#include <list>

#include "IAltaCurso.h"
#include "IConsultarCurso.h"

#include "CLeccion.h"
#include "CUsuario.h"
#include "Curso.h"
#include "Leccion.h"
#include "Idioma.h"
#include "Usuario.h"
#include "Estudiante.h"
#include "Profesor.h"

#include "DataEjercicio.h"
#include "DataCurso.h"
#include "DataIdioma.h"
#include "DataUsuario.h"
#include "dataInfoCurso.h"

using namespace std;

class CCurso : public IAltaCurso, public IConsultarCurso
{
private:
    static CCurso *ControladorCurso;
    CCurso();

    CUsuario *ControladorUsuario;
    CLeccion *ControladorLeccion;

    set<Curso *> cursos;
    set<Curso *> cursos_habilitados;
    set<Curso *> cursos_no_habilitados;

public:
    static CCurso *getInstance();

    set<Curso *> getCursos_habilitados(); // IMPLEMENTAR

    void crearCurso(string, string, Dificultad, int, int, Idioma *, Profesor *, list<Leccion *>, set<Curso *>);
    void selecCursoPrevio(set<string>, Curso *);

    set<DataCurso *> listarCursosHabilitados();
    set<DataCurso *> listarCursosNoHabilitados();
    // set <DataIdioma *> ingresarDatosCurso(string, string, string, Dificultad);
    set<DataEjercicio *> listarEjsPendientes(string, Estudiante *);
    DataCurso *listarInfoCurso(string);
    // set <DataLeccion *> listarLecciones(string);

    //string es el nombre del curso
    void LinkLeccion_Curso(Leccion *, string);

    Curso *getCurso(string);
    // void habilitarCurso(Curso *);
    // void eliminarCurso(string);

    // caso de uso "Inscribirse a curso"
    //  void inscribirseACurso(string);

    // interfaz iAltaCurso
    set<DataUsuario *> listar_nicknames_profesores() override;                            // hecho
    set<DataIdioma *> listar_especialidades_profesor(string) override;                    // hecho
    set<DataCurso *> listar_cursos_habilitados() override;                                // hecho
    ejCompletar crear_estructura_ej_completar(string, string, string, string) override;   // hecho
    ejTraduccion crear_estructura_ej_traduccion(string, string, string, string) override; // hecho
    void alta_curso(string, string, string, string, string, set<leccion_con_ejs>) override;

    // interfaz IConsultarCurso
    set<DataCurso *> listarCursos() override;
    bool existe_Curso(string) override;
    int getCantLecciones(string) override;
    set<DataLeccion *> getLecciones(string) override;
    set<DataEstudiante *> getInscriptos(string) override;
    Fecha getFechaInscripcion(string, string) override;
    DataCurso *obtenerCurso(string) override;
};

#endif
