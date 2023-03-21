#include <iostream>
#include <fstream>
#include <cmath>

void tablaHtml(int *datos, int *codigos){
  for(int idx=0; idx<25; idx++){
    std::cout<<"número "<<datos[idx]<<" codigo: "<<codigos[idx]<<"\n";
  }
}
void input(int *datos){
    std::ifstream file("input.txt");
    for(int idx=0;idx<25;idx++){
        file >> datos[idx];
        std::cout<<datos[idx]<<std::endl;
    }
}



int analizador(int numero){
int g(0);
 for(int i=2; i<numero; i++){ 
    if(numero%i==0){
    g++;  
    }
    }
  
  if(g==0 && numero!=1 && numero!=0 ){
   return 1;
  }else if (g == 1){
    return 3;
  } else
   if(g == 2 && numero%2!=1 && numero != 8 ){
    
    return 2;            
  }
  return 0;
}

void almacen(int *datos){
 int codigos [25];
  
  for(int idx=0; idx<25;idx++){
    codigos[idx]=analizador(datos[idx]); 
  }

  tablaHtml(datos, codigos);
}

void flujoControl(){
  //declarando
    int datos[25];
  
  //lectura de datos
  
  input(datos);
  almacen(datos);

}
int main(){

   flujoControl();
    return 0;
}