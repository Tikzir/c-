//copyright 2022 Tomas Mancera Villa - Sebastian Lopez - Juan Manuel Padilla - Carlos Perez
#ifndef CREAR_GENERADOS
#define CREAR_GENERADOS

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


namespace crearGenerados{
void generarPy(std::stringstream &flujoFuncionesPy,std::stringstream &flujoVariablesPy);
void generarCpp( std::stringstream &flujoFuncionesCpp, std::stringstream &flujoVariablesCpp);
void generarHtml(std::stringstream &flujoFuncionesHtml,std::stringstream &flujoVariablesHtml);
}

#endif

