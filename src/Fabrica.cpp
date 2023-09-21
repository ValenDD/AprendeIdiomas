#include "Fabrica.h"

Fabrica::Fabrica(){};

// IAgregarEjercicio *Fabrica::getIAgregarEjercicio()
// {
//     return CEjercicio::getInstance();
// };

IAgregarLeccion *Fabrica::getIAgregarLeccion()
{
    return CLeccion::getInstance();
};

// IAltaIdioma *Fabrica::getIAltaIdioma()
// {
//     return IAltaIdioma::getInstance();
// };

// IConsultarEstadisticas *Fabrica::getIConsultarEstadisticas()
// {
//     return IConsultarEstadisticas::getInstance();
// };

// IConsultarIdiomas *Fabrica::getIConsultarIdiomas()
// {
//     return IConsultarIdiomas::getInstance();
// };

// IEliminarCurso *Fabrica::getIEliminarCurso()
// {
//     return IEliminarCurso::getInstance();
// };

// IEliminarSuscripciones *Fabrica::getIEliminarSuscripciones()
// {
//     return IEliminarSuscripciones::getInstance();
// };

// IHabilitarCurso *Fabrica::getIHabilitarCurso()
// {
//     return IHabilitarCurso::getInstance();
// };

// IInscribirseACurso *Fabrica::getIInscribirseACurso()
// {
//     return IInscribirseACurso::getInstance();
// };

// IRealizarEjercicio *Fabrica::getIRealizarEjercicio()
// {
//     return IRealizarEjercicio::getInstance();
// };


IAltaCurso *Fabrica::getIAltaCurso()
{
    return CCurso::getInstance();
}

IConsultarCurso *Fabrica::getIConsultarCurso()
{
    return CCurso::getInstance();
}

IAltaUsuario *Fabrica::getIAltaUsuario()
{
    return &CUsuario::getInstance();
};

IConsultarUsuario *Fabrica::getIConsultarUsuario()
{
    return &CUsuario::getInstance();
};

IAltaIdioma *Fabrica::getIAltaIdioma()
{
    return &CIdioma::getInstance();
};

IConsultarIdioma *Fabrica::getIConsultarIdioma()
{
    return &CIdioma::getInstance();
};
