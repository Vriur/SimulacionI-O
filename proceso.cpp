#include "proceso.h"

proceso::proceso()
{
    tiempoCola = 0;
    entradaCola = 0;
}

proceso::~proceso(){}

void proceso::sumarTiempoCola(float cantidad)
{
    tiempoCola += cantidad;
}

void proceso::actualizarEntradaCola(float reloj)
{
    entradaCola = reloj;
}
