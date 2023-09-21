#ifndef IALTACURSO_H
#define IALTACURSO_H

#include "Estructuras.h"

#include "DataUsuario.h"
#include "DataIdioma.h"
#include "DataCurso.h"

using namespace std;

class IAltaCurso
{
public:
    virtual set<DataUsuario *> listar_nicknames_profesores() = 0;
    virtual set<DataIdioma *> listar_especialidades_profesor(string) = 0;
    virtual set<DataCurso *> listar_cursos_habilitados() = 0;
    virtual ejCompletar crear_estructura_ej_completar(string, string, string, string) = 0;
    virtual ejTraduccion crear_estructura_ej_traduccion(string, string, string, string) = 0;
    virtual void alta_curso(string, string, string, string, string, set<leccion_con_ejs>) = 0;
};

#endif
