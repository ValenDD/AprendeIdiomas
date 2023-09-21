#include "CCurso.h"

using namespace std;

CCurso *CCurso::ControladorCurso = nullptr;

CCurso::CCurso() {}

CCurso *CCurso::getInstance()
{
    if (ControladorCurso == nullptr)
        ControladorCurso = new CCurso();
    return ControladorCurso;
}

void CCurso::crearCurso(string nombre, string descripcion, Dificultad dificultad, int cantLecc, int cantEjs, Idioma *idioma, Profesor *profesor, list<Leccion *> Lecciones, set<Curso *> cursos_previos)
{
    Curso *curso = new Curso(nombre, descripcion, dificultad, cantLecc, cantEjs, idioma, profesor, Lecciones, cursos_previos);
    cursos.insert(curso);
    cursos_no_habilitados.insert(curso);
}

void CCurso::selecCursoPrevio(set<string> previos, Curso *cur)
{
    set<Curso *> res = set<Curso *>();
    for (const string &previo : previos)
    {
        for (Curso *curso : this->cursos)
        {
            if (curso->getNombre() == previo)
            {
                res.insert(curso);
                break;
            }
        }
    }
    cur->setCursos_previos(res);
}

bool CCurso::existe_Curso(string nombre)
{
    bool res = false;
    for (Curso *curso : this->cursos)
    {
        if (curso->getNombre() == nombre)
        {
            res = true;
            break;
        }
    }
    return res;
}

// pre: existe_curso(nombre)
Curso *CCurso::getCurso(string nombre)
{
    Curso *res = nullptr;
    for (Curso *curso : this->cursos)
    {
        if (curso->getNombre() == nombre)
        {
            res = curso;
            break;
        }
    }
    return res;
}

set<DataCurso *> CCurso::listarCursos()
{
    set<DataCurso *> res = set<DataCurso *>();
    for (Curso *curso : cursos)
        res.insert(curso->crearDataCurso());
    return res;
}

set<DataCurso *> CCurso::listarCursosHabilitados()
{
    set<DataCurso *> res = set<DataCurso *>();
    for (Curso *curso : cursos_habilitados)
        res.insert(curso->crearDataCurso());
    return res;
}

set<DataCurso *> CCurso::listarCursosNoHabilitados()
{
    set<DataCurso *> res = set<DataCurso *>();
    for (Curso *curso : cursos_no_habilitados)
        res.insert(curso->crearDataCurso());
    return res;
}

// set <DataIdioma *> CCurso::ingresarDatosCurso(string nombre, string descripcion, string idioma, Dificultad dificultad) {
//     CUsuario * cu = this-> ControladorUsuario-> getInstance();
//     bool es_profe = cu-> existProfesor(nombre);
//     if (es_profe) {
//         set <DataIdioma *> res = cu-> getProfe(nombre);
//         return res;
//     }
//     else cout << "No existe profesor con nombre" << nombre << endl;
// }

set<DataEjercicio *> CCurso::listarEjsPendientes(string nombreCurso, Estudiante *estudiante)
{
    set<DataEjercicio *> res = set<DataEjercicio *>();
    bool existe = this->existe_Curso(nombreCurso);
    if (existe)
    {
        Curso *curso = this->getCurso(nombreCurso);
        set<DataEjercicio *> res = curso->getEjsNoAprobados(estudiante);
    }
    else
        cout << "No existe curso con nombre" << nombreCurso << endl;
    return res;
}

DataCurso *CCurso::listarInfoCurso(string nombreCurso)
{
    DataCurso *res = nullptr;
    bool existe = this->existe_Curso(nombreCurso);
    if (existe)
    {
        Curso *curso = this->getCurso(nombreCurso);
        res = curso->crearDataCurso();
    }
    else
        cout << "No existe curso con nombre" << nombreCurso << endl;
    return res;
}

// set <DataLeccion *> CCurso::listarLecciones(string nombreCurso) {
//     bool existe = this -> existe_curso(nombreCurso);
//     if (existe) {
//         Curso* curso = this -> getCurso(nombreCurso);
//         set<DataLeccion> res = curso -> getLecciones();
//         for (DataLeccion Leccion : res) {
//             cout << Leccion-> getNombre() << endl;
//             cout << Leccion-> getDescripcion() << endl;
//             cout << Leccion-> getNumero() << endl;
//             cout << Leccion-> getCantEjercicios() << endl;
//             cout << Leccion-> getHabilitado() << endl;
//             cout << Leccion-> getPromedio() << endl;
//             cout << Leccion-> getEjercicios() << endl;
//         }
//     }
//     else cout << "No existe curso con nombre" << nombreCurso << endl;
// }

// void CCurso::habilitarCurso(Curso * curso) {

//     int cantLec = curso -> getCantLecciones();
//     if (cantLec > 0) {
//         bool todas_con_ej = true;
//         list<Leccion*> Lecciones = curso -> getLecciones();
//         for (Leccion* lec : Lecciones) {
//             int cantEjs = lec -> getCantEjercicios();
//             if (cantEjs == 0) {
//                 todas_con_ej = false;
//                 }
//             }
//         if (todas_con_ej) {
//             curso -> setHabilitado(true);
//             this-> cursos_habilitados.insert(curso);
//             this-> cursos_no_habilitados.erase(curso);
//         }
//         else cout << "No se puede habilitar el curso ya que no todas las Lecciones tienen ejercicios" << endl;
//     }
//     else cout << "No se puede habilitar el curso ya que este no tiene ninguna Leccion" << endl;
// }

// void CCurso::inscribirseACurso(string nomEstudiante) {
// CUsuario * cu = this-> ControladorUsuario-> getInstance();
// bool existe = cu-> existe_estudiante(nomEstudiante);
// if (existe) {
//     Estudiante * est = cu-> buscarEstudiante(nomEstudiante);
//     Curso * cursosAprobados = est-> getCursos_aprobados();
//     set<Curso *> cursos_hab = this-> getCursos_habilitados();
//     set<Curso *> res = set<Curso *>(); //cursos en los cuales se puede inscribir el estudiante

//     if (!cursos_hab.empty()) {
//         for (Curso * curso : cursos_hab) {
//             bool esta_inscripto = false;
//             set <Estudiante *> estudiantes = curso-> getEstudiantes_inscriptos();
//             for (Estudiante * estudiante : estudiantes) {
//                 if (estudiante-> getNombre() == nomEstudiante) {
//                     esta_inscripto = true;
//                     break;
//                 }
//             }
//             if (!esta_inscripto) {
//                 bool previos_aprobados = true;
//                 set <Curso *> cursos_previos = curso-> getCursos_previos();

//                 for (Curso * curso_previo : cursos_previos) {
//                     bool esta_aprobado = false;

//                     for (Curso * curso_aprobado : cursosAprobados) {
//                         if (curso_aprobado-> getNombre() == curso_previo-> getNombre()) {
//                             esta_aprobado = true;
//                             break;
//                         }
//                     }

//                     if (!esta_aprobado) { //tienen que estar TODOS los cursos previos aprobados
//                         previos_aprobados = false;
//                         break;
//                     }
//                 }
//                 if (previos_aprobados)
//                     res.insert(curso);
//             }
//         }
//         cout << "Elija un curso." << endl;
//         set <DataCurso *> dtRes = set<DataCurso *>();

//         for (Curso * curso : res) {
//             int cantEjercicios = 0;
//             DataCurso * dtCur = curso-> crearDataCurso();
//             list<Leccion *> Lecciones = curso-> getLecciones();
//             for (Leccion * lec : Lecciones) {
//                 cantEjercicios += lec-> getCantEjercicios();
//             }
//             cout << "Nombre: " << dtCur-> getNombre() << endl;
//             cout << "Descripcion: " << dtCur-> getDescripcion() << endl;
//             cout << "Dificultad: " << dtCur-> getComplejidad() << endl;
//             cout << "Cantidad de Lecciones: " << dtCur-> getCantLecciones() << endl;
//             cout << "Idioma: " << dtCur-> getIdiomaC() << endl;
//             cout << "Profesor: " << dtCur-> getProfesorC() << endl;
//             cout << "Cantidad de ejercicios: " << cantEjercicios << endl;
//         }
//         string opcion;
//         cin >> opcion;
//         bool existe = false;
//         for (Curso * curso : res) {
//             if (curso-> getNombre() == opcion) {
//                 existe = true;
//                 break;
//             }
//         }
//         if (existe) {
//             Curso * curso = this -> getCurso(opcion);
//             curso-> addInscripcion(est, Fecha());
//             cout << "Se ha inscripto al curso " << opcion << endl;
//         }
//         else cout << "No existe curso con nombre " << opcion << endl;
//     }
//     else cout << "No hay cursos habilitados" << endl;
// }
// else cout << "No existe estudiante con nombre " << nomEstudiante << endl;
// }

set<DataUsuario *> CCurso::listar_nicknames_profesores()
{
    // CUsuario *cu = &this->ControladorUsuario->getInstance();
    set<DataUsuario *> res = set<DataUsuario *>();
    // set<DataUsuario *> res = cu->obtener_info_profesores();
    return res;
}

set<DataIdioma *> CCurso::listar_especialidades_profesor(string nombre)
{
    // CUsuario *cu = &this->ControladorUsuario->getInstance();
    // set<DataIdioma *> res = cu->getProfe(nombre);
    set<DataIdioma *> res = set<DataIdioma *>();
    return res;
}

set<DataCurso *> CCurso::listar_cursos_habilitados()
{
    set<DataCurso *> res = this->listarCursosHabilitados();
    return res;
}

ejCompletar CCurso::crear_estructura_ej_completar(string tipoEjercicio, string descripcionEjercicio, string frase, string solucion)
{
    ejCompletar res = ejCompletar();
    res.tipoEjercicio = tipoEjercicio;
    res.descripcionEjercicio = descripcionEjercicio;
    res.frase = frase;
    res.solucion = solucion;
    return res;
}

ejTraduccion CCurso::crear_estructura_ej_traduccion(string tipoEjercicio, string descripcionEjercicio, string frase, string fraseTraducida)
{
    ejTraduccion res = ejTraduccion();
    res.tipoEjercicio = tipoEjercicio;
    res.descripcionEjercicio = descripcionEjercicio;
    res.frase = frase;
    res.fraseTraducida = fraseTraducida;
    return res;
}

void CCurso::alta_curso(string nickname, string nombreCurso, string descripcion, string dificultad, string idioma, set<leccion_con_ejs> lecciones)
{
}

int CCurso::getCantLecciones(string nombreCurso)
{
    int res = 0;
    // bool existe = this -> existe_Curso(nombreCurso);
    // if (existe) {
    //     Curso* curso = this -> getCurso(nombreCurso);
    //     res = curso -> getCantLecciones();
    //     }
    // else cout << "No existe curso con nombre" << nombreCurso << endl;
    return res;
}

set<DataLeccion *> CCurso::getLecciones(string nombreCurso)
{
    set<DataLeccion *> res = set<DataLeccion *>();
    // bool existe = this -> existe_Curso(nombreCurso);
    // if (existe) {
    //     Curso* curso = this -> getCurso(nombreCurso);
    //     set<DataLeccion *> res = curso -> getLecciones();
    //     }
    // else cout << "No existe curso con nombre" << nombreCurso << endl;
    return res;
}

set<DataEstudiante *> CCurso::getInscriptos(string nombreCurso)
{
    set<DataEstudiante *> res = set<DataEstudiante *>();
    // bool existe = this -> existe_Curso(nombreCurso);
    // if (existe) {
    //     Curso* curso = this -> getCurso(nombreCurso);
    //     set<DataEstudiante *> res = curso -> getEstudiantes_inscriptos();
    //     }
    // else cout << "No existe curso con nombre" << nombreCurso << endl;
    return res;
}

Fecha CCurso::getFechaInscripcion(string nombreCurso, string nombreEstudiante)
{
    Fecha res;
    bool existe = this->existe_Curso(nombreCurso);
    if (existe)
    {
        Curso *curso = this->getCurso(nombreCurso);
        map<string, Fecha> inscripciones = curso->getInscripciones();
        res = inscripciones[nombreEstudiante];
    }
    else
        cout << "No existe curso con nombre" << nombreCurso << endl;
    return res;
}

DataCurso *CCurso::obtenerCurso(string nombreCurso)
{
    DataCurso *res = nullptr;
    // bool existe = this -> existe_Curso(nombreCurso);
    // if (existe) {
    //     Curso* curso = this -> getCurso(nombreCurso);
    //     res = curso -> crearDataCurso();
    //     }
    // else cout << "No existe curso con nombre" << nombreCurso << endl;
    return res;
}
