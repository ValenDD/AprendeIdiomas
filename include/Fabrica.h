#ifndef Fabrica_h
#define Fabrica_h

#include "IAgregarEjercicio.h"
#include "IAgregarLeccion.h"
#include "IAltaCurso.h"
#include "IAltaIdioma.h"
#include "IAltaUsuario.h"
#include "IConsultarCurso.h"
#include "IConsultarEstadisticas.h"
#include "IConsultarIdioma.h"
#include "IConsultarUsuario.h"
#include "IEliminarSuscripciones.h"
#include "IEliminarCurso.h"
#include "IHabilitarCurso.h"
#include "IInscribirseACurso.h"
#include "IRealizarEjercicio.h"
#include "ISuscribirseANotificaciones.h"

#include "CCurso.h"
#include "CIdioma.h"
class Fabrica{
    public:
        Fabrica();        
        
        IAgregarEjercicio *getIAgregarEjercicio();
        IAgregarLeccion* getIAgregarLeccion();
        IAltaCurso* getIAltaCurso();
        IAltaIdioma* getIAltaIdioma();
        IAltaUsuario* getIAltaUsuario();
        IConsultarCurso* getIConsultarCurso();
        IConsultarEstadisticas* getIConsultarEstadisticas();
        IConsultarIdioma* getIConsultarIdioma();
        IConsultarUsuario* getIConsultarUsuario();
        IEliminarSuscripciones * getIEliminarSuscripciones();
        IEliminarCurso* getIEliminarCurso();
        IHabilitarCurso* getIHabilitarCurso();
        IInscribirseACurso* getIInscribirseACurso();
        IRealizarEjercicio* getRealizarEjercicio();
        ISuscribirseANotificaciones* getISuscribirseANotificaciones();

};

#endif
