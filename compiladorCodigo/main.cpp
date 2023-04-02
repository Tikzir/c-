#include <fstream>
#include <iostream>
#include <sstream>
#include "crearGenerados.h"
// Esta funcion nos permite crear las funciones de acuerdo a lo que quiera el usuario
void menuFuncion(std::stringstream &flujoFuncionesCpp, std::stringstream &flujoFuncionesPy, std::stringstream &flujoFuncionesHtml)
{
  bool bucle(true);
  bool condicion(true);
  std::string nombreFuncion("");
  std::string tipoFuncionCpp;
  std::string variableFuncionCpp;
  std::string retornoFuncionCpp;
  std::string variableFuncionPy;
  std::string retornoFuncionPy;
  std::stringstream flujoParametrosCpp("");
  std::stringstream flujoParametrosPy("");
  std::stringstream flujoDescripcionFuncion("");
  std::string tipoDatoParametro("");
  int opcion(0);
  int opcionParametro(0);
  int opcionParametroDos(0);
  int opcionOtroParametro(0);
  std::string nombreParametro;
  std::string nombreOtroParametro;
  std::string comaParametros("");
  std::string descripcionFuncion("");


  do
  {
    std::cout << "Elige el tipo de funcion que deseas...\n\n";
    std::cout << "1.void\n2.int\n3.double/float\n4.bool\n5.string\n";
    std::cin >> opcion;
    switch (opcion)
    {
    case 1:
      tipoFuncionCpp = "void ";
      variableFuncionCpp = "";
      retornoFuncionCpp = "";
      variableFuncionPy = "";
      retornoFuncionPy = "return";
      break;
    case 2:
      tipoFuncionCpp = "int ";
      variableFuncionCpp = "int aux = 0;";
      retornoFuncionCpp = "return aux;";
      variableFuncionPy = "aux = 0";
      retornoFuncionPy = "return aux";
      break;
    case 3:
      tipoFuncionCpp = "double ";
      variableFuncionCpp = "double aux = 0.0;";
      retornoFuncionCpp = "return aux;";
      variableFuncionPy = "aux = 0.0";
      retornoFuncionPy = "return aux";
      break;
    case 4:
      tipoFuncionCpp = "bool ";
      variableFuncionCpp = "bool aux = false;";
      retornoFuncionCpp = "return aux;";
      variableFuncionPy = "aux = False";
      retornoFuncionPy = "return aux";
      break;
    case 5:
      tipoFuncionCpp = "std::string ";
      variableFuncionCpp = "std::string aux = "
                           "\"  \";";
      retornoFuncionCpp = "return aux;";
      variableFuncionPy = "aux = "
                          "\"  \"";
      retornoFuncionPy = "return aux";
      break;
    }
    if (opcion >= 1 && opcion <= 6)
    {
      std::cout << "\nIngresa el nombre para tu funcion...\n";
      std::cin >> nombreFuncion;
      // solicita al usuario la descripcion para la funcion que esta creando
      std::cout << "Ingresa la descripcion para tu funcion...\n";
      std::cin.ignore();
      getline(std::cin,descripcionFuncion);
   
      while (bucle == true)
      {
        std::cout << "Quieres ingresar parametros para tu funcion?...\n";
        std::cout << "1. Si\n2. No\n";
        std::cin >> opcionParametro;
        if (opcionParametro == 2 || opcionParametro == 1)
        {
          bucle = false;
        }
      }
    }

    switch (opcionParametro)
    {
    case 1:
      while (condicion == true)
      {
        do
        {
          std::cout << "Elige el tipo de dato para tu "
                       "parametro...\n1. char\n2. int\n3. double/float\n4. bool"
                       "\n5. string\n";

          std::cin >> opcionParametroDos;
          if (opcionParametroDos >= 1 && opcionParametroDos <= 5)
          {

            switch (opcionParametroDos)
            {
            case 1:
              tipoDatoParametro = "char ";
              break;

            case 2:
              tipoDatoParametro = "int ";
              break;

            case 3:
              tipoDatoParametro = "double ";
              break;

            case 4:
              tipoDatoParametro = "bool ";
              break;

            case 5:
              tipoDatoParametro = "std::string ";
              break;
            }

            std::cout << "\nIngresa el nombre para tu parametro...\n";
            std::cin >> nombreParametro;
          }
        } while (opcionParametroDos < 1 || opcionParametroDos > 6);

        flujoParametrosCpp << comaParametros << tipoDatoParametro << nombreParametro;
        flujoParametrosPy << comaParametros << nombreParametro;

        do
        {
          std::cout << "\nDesea ingresar mas parametros a su funcion?...\n";
          std::cout << "1. Si\n2. No\n";
          std::cin >> opcionOtroParametro;
          if (opcionOtroParametro == 1)
          {
            comaParametros = ",";
          }
          if (opcionOtroParametro == 2)
          {
            condicion = false;
          }
        } while (opcionOtroParametro < 1 || opcionOtroParametro > 2);
      }
    }
    break;

  } while (bucle == true);

  // ordenamiento de los flujos respectivos para funciones
  flujoFuncionesCpp << "\n//" << descripcionFuncion << "\n\n" << tipoFuncionCpp << nombreFuncion << "("
                    << flujoParametrosCpp.str() << "){\n"
                    << variableFuncionCpp << "\n"
                    << retornoFuncionCpp << "\n}" << std::endl;
  flujoFuncionesPy << "  " <<"\n#"<<descripcionFuncion << "\n\n" <<"def " << nombreFuncion << "(" << flujoParametrosPy.str()
                   << "):\n"
                   << "  "
                   << "\"\"\"" << nombreFuncion << "\"\"\"\n"
                   << "  " << variableFuncionPy << "\n"
                   << "  " << retornoFuncionPy << std::endl;
  flujoFuncionesHtml << "<tr>\n";
  flujoFuncionesHtml << "<td bgcolor = #EFF5F5><center>" << tipoFuncionCpp
                     << "</center></td>\n";
  flujoFuncionesHtml << "<td bgcolor = #EFF5F5><center>" << nombreFuncion
                     << "</center></td>\n";
  flujoFuncionesHtml << "<td bgcolor = #EFF5F5><center>" << descripcionFuncion
                     << "</center></td>\n";
}

// MENU VARIABLES
void menuVariables(std::stringstream &flujoVariablesCpp,std::stringstream &flujoVariablesPy, std::stringstream &flujoVariablesHtml)
{
  std::string tipoVariableCpp("");
  std::string valorDefectoCpp("");
  std::string valorDefectoPy("");
  std::string nombreVariable("");
  std::string variableSeleccionada("");
  std::string descripcionVariable("");
  int opcion(0);
  int tipoVariableEleccion(0);
  do
  {
    std::cout << "Asistente de generador de codigo\n";
    std::cout << "Selecciona el Tipo de variable que deseas...\n";
    std::cout << "1. char/string\n2. int\n3. double\n4. bool\n5. string\n";
    std::cin >> opcion;
    std::cout << "Ingresa el nombre que quieres para la variable...\n";
    std::cin >> nombreVariable;

    switch (opcion)
    {
    case 1:
      tipoVariableCpp = "char ";
      valorDefectoCpp = "'a';";
      valorDefectoPy = "\" \"";
      break;
    case 2:
      tipoVariableCpp = "int ";
      valorDefectoCpp = "0;";
      valorDefectoPy = "0";
      break;
    case 3:
      tipoVariableCpp = "double ";
      valorDefectoCpp = "0.0;";
      valorDefectoPy = "0.0";

      break;
    case 4:
      tipoVariableCpp = "bool ";
      valorDefectoCpp = "false;";
      valorDefectoPy = "False";
      break;
    case 5:
      tipoVariableCpp = "std::string ";
      valorDefectoCpp = "\" \";";
      valorDefectoPy = "\" \"";

      break;
    }
  } while (opcion < 1 || opcion > 5);
  std::cout << "Ingresa la descripcion de la variable...\n";
  std::cin.ignore();
  getline(std::cin,descripcionVariable);
  // pregunta al usuario si la variable es in/aux/out
  do
  {
    std::cout << "Tipo variable seleccionada...\n";
    std::cout << "1.in\n2.aux\n3.out\n";
    std::cin >> tipoVariableEleccion;

    switch (tipoVariableEleccion)
    {
    case 1:
      variableSeleccionada = "in";
      break;
    case 2:
      variableSeleccionada = "aux";
      break;
    case 3:
      variableSeleccionada = "out";
      break;
    }

  } while (tipoVariableEleccion < 1 || tipoVariableEleccion > 3);

  // ordenamiento de los flujos respectivos para las variables
  flujoVariablesCpp << tipoVariableCpp << nombreVariable << " = "
                    << valorDefectoCpp << std::endl;
  flujoVariablesPy << "  " << nombreVariable << " = " << valorDefectoPy
                   << std::endl;
  flujoVariablesHtml << "<tr>\n";
  flujoVariablesHtml << "<td bgcolor = #EFF5F5><center>" << variableSeleccionada
                     << "</center></td>\n";
  flujoVariablesHtml << "<td bgcolor = #EFF5F5><center>" << tipoVariableCpp
                     << "</center></td>\n";
  flujoVariablesHtml << "<td bgcolor = #EFF5F5><center>" << nombreVariable
                     << "</center></td>\n";
  flujoVariablesHtml << "<td bgcolor = #EFF5F5><center>" << descripcionVariable
                     << "</center></td>\n";
  flujoVariablesHtml << "</tr>\n";
}

void menuPrincipal()
{
  std::stringstream flujoVariablesCpp;
  std::stringstream flujoFuncionesCpp;
  std::stringstream flujoVariablesPy;
  std::stringstream flujoFuncionesPy;
  std::stringstream flujoVariablesHtml;
  std::stringstream flujoFuncionesHtml;
  int opcion(0);
  do
  {
    std::cout << "Asistente de generador de codigo\n";
    std::cout << "Digita acorde a tu opcion\n";
    std::cout << "1. Funcion\n2. Variables\n3. Terminar\n";
    std::cin >> opcion;
    if (opcion == 1)
    {
      menuFuncion(flujoFuncionesCpp, flujoFuncionesPy, flujoFuncionesHtml);
    }
    if (opcion == 2)
    {
      menuVariables(flujoVariablesCpp, flujoVariablesPy, flujoVariablesHtml);
    }
  } while (opcion != 3);
  crearGenerados::generarCpp(flujoFuncionesCpp, flujoVariablesCpp);
  crearGenerados::generarPy(flujoFuncionesPy, flujoVariablesPy);
  crearGenerados::generarHtml(flujoFuncionesHtml, flujoVariablesHtml);
}

bool llamadoSistema(std::string comando) {
  bool resultado(false);
  int llamado(0);
  std::cout << "Ejecutando el comando: " << comando << std::endl;
  llamado = system(comando.c_str());
  if (llamado != 0) {
    resultado = false;
    std::cerr << "Fallo en ejecución de comando!" <<  std::endl;
    return resultado;
  }
  return true;  
}

bool compilarEjecutarCpp() {
  bool resultado(false);
  std::string compilar = "g++ -o generado.exe generado.cpp";
  std::string ejecutar = "./generado.exe";  

  if (!llamadoSistema(compilar)) { return resultado;}
  if (!llamadoSistema(ejecutar)) { return resultado;}

  return true;
}
    
bool ejecutarPython() {
  bool resultado(false);
  std::string ejecutar = "python generado.py";  
  if (!llamadoSistema(ejecutar)) { return resultado;}
  return true;
}


int flujoControl() {

  if (!compilarEjecutarCpp()) { return -1; }
  if (!ejecutarPython()) { return -1; }
  return 0; 
}


int main ()
{  
  menuPrincipal();
  if (flujoControl()!=0) {
    std::cerr<<"\nLo sentimos, ha habido un fallo en el proceso de generación de código\n";
    return -1;
  }
  std::cout<<"\nGracias por usar nuestro generador de código fuente multilenguaje y documentación\n";
  return 0;
}


