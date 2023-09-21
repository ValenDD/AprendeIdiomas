#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "include/Fabrica.h"

#include "include/DataCurso.h"
#include "include/DataEstudiante.h"
#include "include/DataEjercicio.h"
#include "include/Estructuras.h"
#include "include/DataUsuario.h"
#include "include/DataIdioma.h"
#include "include/DataLeccion.h"

using namespace std;

string toHabilitado(bool a)
{
    if (a)
        return "Habilitado";
    else
        return "No habilitado";
};

string toFecha(Fecha fecha)
{
    string res = "";
    res += to_string(fecha.dia);
    res += "/";
    res += to_string(fecha.mes);
    res += "/";
    res += to_string(fecha.anio);
    return res;
};

void menu()
{
    int opcion;
    Fabrica F;
    IAltaCurso *iac = F.getIAltaCurso();
    IConsultarCurso *icc = F.getIConsultarCurso();
    IAgregarLeccion *iAL = F.getIAgregarLeccion();
    IAltaUsuario *altaUsuario = F.getIAltaUsuario();
    IConsultarUsuario *consultaUsuario = F.getIConsultarUsuario();
    IAltaIdioma *altaIdioma = F.getIAltaIdioma();
    IConsultarIdioma *consultaIdioma = F.getIConsultarIdioma();

    do
    {
        cout << "|===========================================|" << endl;
        cout << "|                    MENU                   |" << endl;
        cout << "|===========================================|" << endl;
        cout << "| 1)  Dar de alta un usuario                |" << endl;
        cout << "| 2)  Consultar información sobre un usuario|" << endl;
        cout << "| 3)  Dar de alta un idioma                 |" << endl;
        cout << "| 4)  Consultar idiomas                     |" << endl;
        cout << "| 5)  Dar de alta un curso                  |" << endl;
        cout << "| 6)  Agregar una lección                   |" << endl;
        cout << "| 7)  Agregar un ejercicio                  |" << endl;
        cout << "| 8)  Habilitar un curso                    |" << endl;
        cout << "| 9)  Eliminar un curso                     |" << endl;
        cout << "| 10) Consultar información sobre un curso  |" << endl;
        cout << "| 11) Inscribirse a un curso                |" << endl;
        cout << "| 12) Realizar un ejercicio                 |" << endl;
        cout << "| 13) Consultar estadísticas                |" << endl;
        cout << "| 14) Suscribirse a notificaciones          |" << endl;
        cout << "| 15) Consultar notificaciones              |" << endl;
        cout << "| 16) Eliminar suscripciones                |" << endl;
        cout << "| 0)  Salir                                 |" << endl;
        cout << "|===========================================|" << endl;
        cout << "Ingrese el número de la opción deseada: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
        case 1:
        {
            cout << "Dando de alta un usuario..." << endl;
            bool opcion2 = false;
            string nombre;
            string nickname;
            string contrasenia;
            string descripcion;
            string nombreIdioma;
            int YesOrNot;
            bool resP = false;

            printf("Ingrese Nombre\n");
            std::cin >> nombre;
            printf("Ingrese Nickname\n");
            std::cin >> nickname;
            while (!opcion2)
            {
                printf("Ingrese Contrasenia\n");
                std::cin >> contrasenia;
                if (contrasenia.length() <= 5)
                {
                    printf("La contrasenia debe tener al menos 6 caracteres\n");
                }
                else
                {
                    opcion2 = true;
                }
            }
            printf("Ingrese Descripcion\n");
            std::cin.ignore();
            std::getline(std::cin, descripcion);

            altaUsuario->ingresarDatos(nombre, nickname, contrasenia, descripcion);
            printf("Ingrese 1 si es estudiante o 2 si es profesor\n");
            std::cin >> YesOrNot;
            if (YesOrNot == 1)
            {
                string pais;
                string fechaNacimiento;
                int dia;
                int mes;
                int anio;
                bool opcion3 = false;
                bool resE = false;
                Fecha fechaNacimientoF;

                printf("Ingrese Pais\n");
                std::cin >> pais;

                while (!opcion3)
                {
                    printf("Ingrese Fecha de Nacimiento de la siguiente manera:\n DIA MES AÑO \n");
                    std::cin >> dia;
                    std::cin >> mes;
                    std::cin >> anio;
                    if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio >= 1900 && anio <= 2023)
                    {
                        opcion3 = true;
                    }
                    else
                    {
                        printf("Fecha invalida\n");
                    }
                }
                fechaNacimientoF.dia = dia;
                fechaNacimientoF.mes = mes;
                fechaNacimientoF.anio = anio;

                resE = altaUsuario->ingresoEstudiante(pais, fechaNacimientoF);
                if (resE)
                {
                    printf("Estudiante ingresado con exito\n");
                }
                else
                {
                    printf("No se pudo ingresar el estudiante\n");
                }
            }
            else if (YesOrNot == 2)
            {
                string instituto;
                bool opcion4 = false;
                printf("Ingrese Instituto\n");
                std::cin >> instituto;
                altaUsuario->ingresoInstituto(instituto);
                while (!opcion4)
                {
                    bool resI = false;
                    string idioma;
                    printf("Ingrese alguno de los idiomas mostrados anteriormente\n");
                    std::cin >> idioma;
                    resI = altaUsuario->ingresoIdioma(idioma);
                    if (resI)
                        printf("Idioma ingresado con exito\n");
                    else
                        printf("No se pudo ingresar el idioma\n");

                    printf("Ingrese 1 si desea agregar otro idioma o 2 si no\n");
                    std::cin >> YesOrNot;
                    if (YesOrNot == 2)
                    {
                        opcion4 = true;
                    }
                }
                resP = altaUsuario->ingresoProfesor();
                if (resP)
                {
                    printf("Profesor ingresado con exito\n");
                }
                else
                {
                    printf("No se pudo ingresar el profesor\n");
                }
            }
            else
            {
                printf("Numero invalido, redireccionando al inicio...\n");
            }
        }
        break;
        case 2:
        {
            string nickname;
            int opcion;

            cout << "Consultando información sobre un usuario..." << endl;
            cout << "Ingrese 1 si usted quiere consultar la informacion de un estudiante o 2 si usted quiere consultar la informacion de un profesor." << endl;

            cin >> opcion;
            if (opcion == 1)
            {
                cout << "Ingrese el nickname del estudiante que desea consultar: " << endl;
                cin >> nickname;
                DataEstudiante *data = consultaUsuario->consultarEstudiante(nickname);
                cout << "Nombre: " << data->getNombre() << endl;
                cout << "Descripcion: " << data->getDescripcion() << endl;
                cout << "Pais: " << data->getPais() << endl;
                cout << "Fecha de nacimiento: " << toFecha(data->getFechaNacimiento()) << endl;
            }
            else if (opcion == 2)
            {
                cout << "Ingrese el nickname del profesor que desea consultar: " << endl;
                cin >> nickname;
                DataProfesor *data = consultaUsuario->consultarProfesor(nickname);
                cout << "Nombre: " << data->getNombre() << endl;
                cout << "Descripcion: " << data->getDescripcion() << endl;
                cout << "Instituto: " << data->getInstituto() << endl;
                cout << "Idiomas: " << endl;
                set<string> idiomas = data->getIdiomas();
                for (string idioma : idiomas)
                {
                    cout << idioma << endl;
                }
            }
            else
            {
                cout << "Opcion invalida." << endl;
            }
        }
        break;
        case 3:
        {
            string nombreIdioma;
            cout << "Dando de alta un idioma..." << endl;
            std::cin >> nombreIdioma;
            altaIdioma->ingresoDatos(nombreIdioma);
        }
        break;
        case 4:
        {
            cout << "Consultando idiomas..." << endl;
            set<DataIdioma *> listaIdiomas = consultaIdioma->listarIdiomas();
            set<DataIdioma *>::iterator it;
            for (it = listaIdiomas.begin(); it != listaIdiomas.end(); ++it)
            {
                cout << (*it)->getNombre() << endl;
            }
            break;
        }
        case 5:
        {
            cout << "Dando de alta un curso..." << endl;

            set<DataUsuario *> res = iac->listar_nicknames_profesores();
            for (DataUsuario *dtUsr : res)
                cout << dtUsr->getNombre() << endl;
            // chequear si existen profesores en el sistema
            cout << "Ingrese el nickname del profesor que dictara el curso: " << endl;
            string nickname;
            bool existe = false;
            while (!existe)
            {
                cin >> nickname;
                for (DataUsuario *dtUsr : res)
                    if (dtUsr->getNombre() == nickname)
                        existe = true;
                if (!existe)
                    cout << "Nickname invalido. Intente nuevamente." << endl;
            }
            for (DataUsuario *dtUsr : res)
                delete dtUsr;
            res.clear();
            system("clear");

            cout << "Ingrese el nombre del curso: " << endl;
            string nombreCurso;
            cin >> nombreCurso;
            cout << "Ingrese la descripcion del curso: " << endl;
            string descripcion;
            cin >> descripcion;

            cout << "Ingrese la dificultad del curso (Principiante, Medio, Avanzado): " << endl;
            string dificultad;
            bool dificValida = false;
            while (!dificValida)
            {
                cin >> dificultad;
                if (dificultad == "Principiante" || dificultad == "principiante" || dificultad == "PRINCIPIANTE" || dificultad == "Medio" || dificultad == "medio" || dificultad == "MEDIO" || dificultad == "Avanzado" || dificultad == "avanzado" || dificultad == "AVANZADO")
                    dificValida = true;
                else
                    cout << "Dificultad invalida. Intente nuevamente." << endl;
            }
            system("clear");

            set<DataIdioma *> dtIdiomas = iac->listar_especialidades_profesor(nickname);
            for (DataIdioma *dtIdioma : dtIdiomas)
                cout << dtIdioma->getNombre() << endl;

            cout << "Ingrese el idioma en el que se dictara el curso: " << endl;
            string idioma;
            bool idiomaValido = false;
            while (!idiomaValido)
            {
                cin >> idioma;
                for (DataIdioma *dtIdioma : dtIdiomas)
                    if (dtIdioma->getNombre() == idioma)
                        idiomaValido = true;
                if (!idiomaValido)
                    cout << "Idioma invalido. Intente nuevamente." << endl;
            }
            for (DataIdioma *dtIdioma : dtIdiomas)
                delete dtIdioma;
            dtIdiomas.clear();
            system("clear");

            cout << "El curso " << nombreCurso << " requerira de cursos previos? (si/no)" << endl;
            string respuesta;
            cin >> respuesta;
            set<string> cursosPrevios = set<string>();
            if (respuesta == "SI" || respuesta == "si" || respuesta == "Si" || respuesta == "sI" || respuesta == "Sí" || respuesta == "sí" || respuesta == "SÍ" || respuesta == "Sí")
            {
                set<DataCurso *> cursos_hab = iac->listar_cursos_habilitados();
                for (DataCurso *dtCurso : cursos_hab)
                    cout << dtCurso->getNombre() << endl;

                string mas = "si";
                while (mas == "si" || mas == "Si" || mas == "SI" || mas == "sI" || mas == "Sí" || mas == "sí" || mas == "SÍ" || mas == "Sí" || mas == "s" || mas == "S")
                {
                    cout << "Ingrese el nombre del curso previo: " << endl;
                    string nombreCursoPrevio;
                    bool existe = false;
                    while (!existe)
                    {
                        cin >> nombreCursoPrevio;
                        for (DataCurso *dtCurso : cursos_hab)
                            if (dtCurso->getNombre() == nombreCursoPrevio)
                                existe = true;
                        if (!existe)
                        {
                            cout << "No existe curso con nombre " << nombreCursoPrevio << endl;
                            cout << "Ingrese un nombre valido para el curso previo: " << endl;
                        }
                    }
                    cursosPrevios.insert(nombreCursoPrevio);
                    cout << "Desea agregar otro curso previo? (si/no)" << endl;
                    cin >> mas;
                }
                for (DataCurso *dtCurso : cursos_hab)
                    delete dtCurso;
                cursos_hab.clear();
            }
            // recordar conjunto "cursoPrevios" para crear el curso
            system("clear");

            cout << "Desea agregar lecciones? (si/no)" << endl;
            cin >> respuesta;

            set<leccion_con_ejs> lecciones = set<leccion_con_ejs>();
            while (respuesta == "SI" || respuesta == "si" || respuesta == "Si" || respuesta == "sI" || respuesta == "Sí" || respuesta == "sí" || respuesta == "SÍ" || respuesta == "Sí")
            {
                string tema;
                cout << "Recuerde ingresar las lecciones en el orden que debe realizarlas el estudiante. " << endl;
                cout << "Ingrese el tema sobre el que tratara la leccion: " << endl;
                cin >> tema;

                cout << "Ingrese el objetivo de la leccion: " << endl;
                string objetivo;
                cin >> objetivo;

                cout << "Quiere agregar un ejercicio a la leccion? (si/no)" << endl;
                string quiereEjercicio;
                cin >> quiereEjercicio;

                set<ejCompletar> ejerciciosCompletar = set<ejCompletar>();
                set<ejTraduccion> ejerciciosTraduccion = set<ejTraduccion>();
                while (quiereEjercicio == "SI" || quiereEjercicio == "si" || quiereEjercicio == "Si" || quiereEjercicio == "sI" || quiereEjercicio == "Sí" || quiereEjercicio == "sí" || quiereEjercicio == "SÍ" || quiereEjercicio == "Sí")
                {
                    cout << "Ingrese el tipo de ejercicio (recuerde que los tipos disponibles son Completar y Traduccion): " << endl;
                    string tipoEjercicio;
                    bool ejValido = false;
                    while (!ejValido)
                    {
                        cin >> tipoEjercicio;
                        if (tipoEjercicio == "completar" || tipoEjercicio == "COMPLETAR" || tipoEjercicio == "Completar" || tipoEjercicio == "traduccion" || tipoEjercicio == "TRADUCCION" || tipoEjercicio == "Traduccion" || tipoEjercicio == "traducción" || tipoEjercicio == "TRADUCCIÓN" || tipoEjercicio == "Traducción")
                            ejValido = true;
                        else
                            cout << "Tipo de ejercicio invalido. Intente nuevamente." << endl;
                    }
                    system("clear");
                    cout << "Ingrese la descripcion del ejercicio: " << endl;
                    string descripcionEjercicio;
                    cin >> descripcionEjercicio;

                    if (tipoEjercicio == "completar" || tipoEjercicio == "COMPLETAR" || tipoEjercicio == "Completar")
                    {
                        cout << "Ingrese la frase a completar (las palabras faltantes se representan mediante 3 guiones): " << endl;
                        string frase;
                        cin >> frase;

                        cout << "Ingrese la respuesta correcta (separe mediante comas (,) cada palabra): " << endl; // revisar si solucion tiene que ser set<string>
                        string solucion;
                        cin >> solucion;

                        // crear struct ejercicio completar
                        ejCompletar agregar = iac->crear_estructura_ej_completar(tipoEjercicio, descripcionEjercicio, frase, solucion);
                        // agregar ejercicio completar al set de ejercicios de la leccion
                        ejerciciosCompletar.insert(agregar);
                    }
                    else
                    {
                        cout << "Ingrese la frase a traducir: " << endl;
                        string frase;
                        cin >> frase;

                        cout << "Ingrese la frase traducida" << endl;
                        string fraseTraducida;
                        cin >> fraseTraducida;

                        // crear struct ejercicio traduccion
                        ejTraduccion agregar = iac->crear_estructura_ej_traduccion(tipoEjercicio, descripcionEjercicio, frase, fraseTraducida);

                        // agregar ejercicio traduccion al set de ejercicios de la leccion
                        ejerciciosTraduccion.insert(agregar);
                    }
                    cout << "Quiere agregar otro ejercicio a la leccion? (si/no)" << endl;
                    cin >> quiereEjercicio;
                }
                // crear struct leccion
                leccion_con_ejs agregar;
                agregar.temaLeccion = tema;
                agregar.objetivoLeccion = objetivo;
                agregar.ejerciciosCompletar = ejerciciosCompletar;
                agregar.ejerciciosTraduccion = ejerciciosTraduccion;
                // agregar leccion al set de lecciones del curso
                lecciones.insert(agregar);
                cout << "Desea agregar otra leccion? (si/no)" << endl;
                cin >> respuesta;
            }
            // crear curso con lecciones
            iac->alta_curso(nickname, nombreCurso, descripcion, dificultad, idioma, lecciones);
            cout << "Curso creado exitosamente." << endl;
        }
        break;
        case 6:
        {
            cout << " Agregando leccion... " << endl;

            iAL->listarCursosNoHab();

            cout << "Ingrese el curso al que quiere adicionar la leccion, asi como el tema y objetivo de la misma:" << endl;
            string nomCurso;
            string tema;
            string objetivo;

            cin >> nomCurso;
            cin >> tema; // defino variables aca en el main??
            cin >> objetivo;

            iAL->agregarLeccion(nomCurso, tema, objetivo);

            string quiere_mas_ejercicios;
            cout << "¿Quiere agregar ejercicios a la leccion? (Y/n)" << endl;
            cin >> quiere_mas_ejercicios;

            string tipo;
            string descripcion;
            string frase;
            string solucion;

            while (quiere_mas_ejercicios == "Y")
            {
                cout << "Ingrese tipo y descripcion del ejercicio nuevo:" << endl;
                cin >> tipo;
                cin >> descripcion;

                enumTipo enumT;
                if (tipo == "Completar")
                    enumT = Completar;
                else if (tipo == "Traduccion")
                    enumT = Traduccion;

                iAL->ingresarEjercicio(enumT, descripcion);
                switch (enumT)
                {
                case Completar:
                {
                    cout << "Ingrese la frase a completar, junto con su solucion:" << endl;
                    cin >> frase;
                    cin >> solucion;
                    iAL->ejCompletar(frase, solucion);
                }
                case Traduccion:
                {
                    cout << "Ingrese la frase a completar, junto con su solucion:" << endl;
                    cin >> frase;
                    cin >> solucion;
                    iAL->ejCompletar(frase, solucion);
                }
                }
                cout << "¿Quiere agregar mas ejercicios a la leccion? (Y/n)" << endl;
                cin >> quiere_mas_ejercicios;
            }
            cout << "Leccion agregada correctamente" << endl;
            break;
        }
        case 7:
            cout << "Agregando un ejercicio..." << endl;
            break;
        case 8:
            cout << "Habilitando un curso..." << endl;
            break;
        case 9:
            cout << "Eliminando un curso..." << endl;
            break;
        case 10:
        {
            cout << "Consultando información sobre un curso..." << endl;
            set<DataCurso *> res = icc->listarCursos();
            if (res.size() == 0)
            {
                cout << "No hay cursos." << endl;
                break;
            }
            cout << "Cursos:" << endl;
            for (DataCurso *dtCurso : res)
            {
                cout << dtCurso->getNombre() << endl;
                delete dtCurso;
            }
            res.clear();
            cout << endl;
            string opcion;

            bool existe = false;
            while (!existe)
            {
                cout << "Elija un curso." << endl;
                cin >> opcion;
                bool existe = icc->existe_Curso(opcion);
                if (!existe)
                    cout << "No existe curso con nombre " << opcion << endl;
            }
            system("clear");

            DataCurso *dtCurso = icc->obtenerCurso(opcion);
            cout << "Nombre: " << dtCurso->getNombre() << endl;
            cout << "Descripcion: " << dtCurso->getDescripcion() << endl;
            cout << "Dificultad: " << dtCurso->getComplejidad() << endl;
            cout << "Idioma: " << dtCurso->getIdiomaC() << endl;
            cout << "Profesor: " << dtCurso->getProfesorC() << endl;
            cout << toHabilitado(dtCurso->getHabilitado()) << endl;
            delete dtCurso;
            cout << endl;

            set<DataLeccion *> lecciones = icc->getLecciones(opcion);
            if (lecciones.size() > 0)
            {
                cout << "Lecciones:" << endl;
                for (DataLeccion *dtLeccion : lecciones)
                {
                    cout << "Tema: " << dtLeccion->getTema() << endl;
                    cout << "Objetivo: " << dtLeccion->getObjetivo() << endl;
                    set<DataEjercicio *> ejercicios = dtLeccion->getEjercicios();
                    if (ejercicios.size() > 0)
                    {
                        cout << "Ejercicios de la leccion " << endl;
                        for (DataEjercicio *dtEjercicio : ejercicios)
                        {
                            cout << "Tipo: " << dtEjercicio->getTipo() << endl;
                            cout << "Descripcion: " << dtEjercicio->getDescripcion() << endl;
                            delete dtEjercicio;
                        }
                    }
                    ejercicios.clear();
                    delete dtLeccion;
                }
            }
            lecciones.clear();

            set<DataEstudiante *> inscriptos = icc->getInscriptos(opcion);
            if (inscriptos.size() > 0)
            {
                cout << "Inscriptos:" << endl;
                for (DataEstudiante *dtEstudiante : inscriptos)
                {
                    cout << "Nombre: " << dtEstudiante->getNombre() << endl;
                    Fecha fechaInscripcion = icc->getFechaInscripcion(opcion, dtEstudiante->getNombre());
                    cout << "Fecha de inscripcion: " << toFecha(fechaInscripcion) << endl;
                    delete dtEstudiante;
                }
            }
            inscriptos.clear();
        }
        break;
        case 11:
            cout << "Inscribiéndose a un curso..." << endl;
            break;
        case 12:
            cout << "Realizando un ejercicio..." << endl;
            break;
        case 13:
            cout << "Consultando estadísticas..." << endl;
            break;
        case 14:
            cout << "Suscribiéndose a notificaciones..." << endl;
            break;
        case 15:
            cout << "Consultando notificaciones..." << endl;
            break;
        case 16:
            cout << "Eliminando suscripciones..." << endl;
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
            break;
        }

        cout << endl;
    } while (opcion != 0);

    delete iac;
    delete icc;
    delete iAL;
    delete altaUsuario;
    delete consultaUsuario;
    delete altaIdioma;
    delete consultaIdioma;
}

void cargando()
{
    int i = 0;
    char load[26];
    while (i < 25)
    {
        system("clear");
        load[i++] = '#';
        load[i] = '\0';

        printf("\n\nLOADING [%-25s]", load);
        usleep(17000);
    }

    system("clear");
    printf("\n");
}

int main()
{
    system("clear");
    cargando();
    system("clear");
    menu();
    return 0;
}