// Copyright 2022 Tomas Mancera Villa - Sebastian Lopez - Juan Manuel Padilla -
// Carlos Perez
#include "crearGenerados.h"

void crearGenerados::generarCpp(std::stringstream &flujoFuncionesCpp,
                                std::stringstream &flujoVariablesCpp)
{
    // creacion de generado.cpp
    std::ofstream ofs;
    ofs.open("generado.cpp", std::ios::out);
    ofs << "// Copyright 2022 Tomas Mancera Villa - Sebastian Lopez - Juan "
           "Manuel Padilla - Carlos Perez\n#include <iostream>\n#include "
           "<string>\n\n";
    ofs << flujoFuncionesCpp.str();
    ofs << "/*\nflujoControl\n*/\nint flujoControl (){\n//Declarar e "
           "inicializar\n";
    ofs << flujoVariablesCpp.str();
    ofs << "//Lee\n//Calcula\n//Imprime resultados\nreturn (0);\n}\n";
    ofs << "\n/*\nFuncion main\n*/\nint "
           "main(){\nflujoControl();\nstd::cout<<\"Plantilla de código en C/C++ "
           "generada de manera exitosa!\";\nreturn 0;\n}";
    ofs.close();
}

void crearGenerados::generarPy(std::stringstream &flujoFuncionesPy,
                               std::stringstream &flujoVariablesPy)
{
    // creacion de generado.py
    std::ofstream ofsPy;
    ofsPy.open("generado.py", std::ios::out);
    ofsPy << "#Copyright 2022 Tomas Mancera Villa - Sebastian Lopez - Juan "
             "Manuel Padilla - Carlos Perez\n";
    ofsPy << flujoFuncionesPy.str();
    ofsPy << "def flujo_control(): \n  \"\"\"flujo_control\"\"\"\n  #Declara e "
             "inicializa\n";
    ofsPy << flujoVariablesPy.str();
    ofsPy << "  #Lee\n  #Calcula\n  #Imprime resultados\n  return 0\n";
    ofsPy << "\ndef main():\n  \"\"\"funcion main.\"\"\"\n  flujo_control()\n  "
             "print(\"Plantilla de código en Python generada de manera "
             "exitosa!\")\n  return 0\nmain()\n";
    ofsPy.close();
}

void crearGenerados::generarHtml(std::stringstream &flujoFuncionesHtml,
                                 std::stringstream &flujoVariablesHtml)
{
    // creacion de resultados.html
    std::ofstream ofsHtml;
    ofsHtml.open("resultados.html", std::ios::out);
    ofsHtml << "<!--Copyright 2022 Tomas Mancera Villa - Sebastian Lopez - Juan "
               "Manuel Padilla - Carlos Perez-->\n";
    ofsHtml << "<table border=\"1px solid black\" width=\"80%\""
               "align=\"center\">\n<tr><th>tipo dato funcion</th>\n<th>nombre "
               "de la funcion</th>\n<th>descripcion de la funcion</th>\n</tr>";
    ofsHtml << flujoFuncionesHtml.str();
    ofsHtml << "</table>\n";
    ofsHtml << "<table border=\"1px solid black\" width=\"80%\""
               "align=\"center\">\n<tr><th>tipo</th>\n<th>tipo de dato de "
               "la variable</th>\n<th>nombre de la variable</th>\n<th>descripcion "
               "de la variable</th>\n</tr>";
    ofsHtml << flujoVariablesHtml.str();
    ofsHtml << "</table>";
}
