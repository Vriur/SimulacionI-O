#include "manejadoreventos.h"

ManejadorEventos::ManejadorEventos()
{
    proximaSalidaCpu = INFINITO;
    proximaSalidaIO = INFINITO;
    proximoArribo = INFINITO;
    proximoSalirCpu = 0;
    proximoSalirIO = 0;
}

ManejadorEventos::~ManejadorEventos()
{

}

void ManejadorEventos::vaciarSalidaIO()
{
	 proximaSalidaIO = INFINITO;
	 proximoSalirIO = 0;
}

void ManejadorEventos::vaciarSalidaCpu()
{
	proximaSalidaCpu = INFINITO;
	proximoSalirCpu = 0;
}

int ManejadorEventos::obtenerProximoTiempo()
{
    int tiempo = -1;

    if(proximoArribo != INFINITO)
    {
        if(proximoArribo <= proximaSalidaIO && proximoArribo <= proximaSalidaCpu){
            tiempo = proximoArribo;
            printf("arribo %d\n",tiempo);
            return tiempo;
        }

    }

    if(proximaSalidaCpu != INFINITO)
    {
        if(proximaSalidaCpu <= proximoArribo && proximaSalidaCpu <= proximaSalidaIO){
            tiempo = proximaSalidaCpu;
            printf("cpu %d\n",tiempo);
            return tiempo;
        }

    }

    if(proximaSalidaIO != INFINITO)
    {
        if(proximaSalidaIO <= proximoArribo && proximaSalidaIO <= proximaSalidaCpu){
            tiempo = proximaSalidaIO;
            printf("io %d\n",tiempo);
            return tiempo;
        }

    }

    return tiempo;
}


void ManejadorEventos::indicarProximoArribo(int p)
{
    proximoArribo = p;
}
void ManejadorEventos::indicarProximaSalidaIO(int p, proceso * pid)
{
    proximaSalidaIO = p;
    proximoSalirIO = pid;

}
void ManejadorEventos::indicarProximaSalidaCpu(int p, proceso * pid )
{
    proximaSalidaCpu = p;
    proximoSalirCpu = pid;
}



//Retorna evento 1, 2, 3 o -1 para indicar que no hay ningun evento a ocurrir
int ManejadorEventos::ObtenerEventoMasProximo()
{
    int evento = -1;

    if(proximoArribo != INFINITO)
    {
        if(proximoArribo <= proximaSalidaIO && proximoArribo <= proximaSalidaCpu)
            evento = 1;
    }

    if(evento == -1 && proximaSalidaCpu != INFINITO)
    {
        if(proximaSalidaCpu <= proximoArribo && proximaSalidaCpu <= proximaSalidaIO)
            evento = 2;
    }

    if(evento == -1 && proximaSalidaIO != INFINITO)
    {
        if(proximaSalidaIO <= proximoArribo && proximaSalidaIO <= proximaSalidaCpu)
            evento = 3;
    }

    return evento;
}

proceso * ManejadorEventos::obtenerProximoProcesoIO()
{
    return proximoSalirIO;
}
proceso * ManejadorEventos::obtenerProximoProcesoCPU()
{
    return proximoSalirCpu;
}