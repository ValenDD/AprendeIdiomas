    #ifndef CLeccion_h
    #define CLeccion_h

    class CCurso;
    
    #include <string>
    #include <set>

    #include "CCurso.h"
    #include "Leccion.h"

    #include "DataCurso.h"
    #include "DataLeccion.h"
    #include "IAgregarLeccion.h"

    using namespace std;

    class CLeccion : public IAgregarLeccion
    {
    private:
        static CLeccion *ControladorLeccion;
        CCurso * ControladorCurso;
        set<Leccion *> Lecciones;

        set<Leccion *> leccsAAgregar;

        // atributos para memoria

        Leccion *l;

        string nomCurso;
        string tema;
        string objetivo;

        enumTipo tipo;
        string descripcion;

        string frase;
        string solucion;

    public:
        CLeccion();
        ~CLeccion();
        static CLeccion *getInstance();

        void agregarLeccion(string, string);
        void agregarLink();

        set<DataCurso *> listarCursosNoHab() override;
        void agregarLeccion(string, string, string) override;

        void ingresarEjercicio(enumTipo, string) override;
        void ejCompletar(string, string) override;
        void ejTraducir(string, string) override;
    };

    #endif
