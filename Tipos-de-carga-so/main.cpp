#include "Fifo.hpp"
#include "SJF.hpp"
#include "RoundRobin.hpp"
#include "Prioridad.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, const char *argv[]){
	int opc;
	
    string *names;
    int *test, s = 0;
	int menu_item = 0, run, x = 7;


// Titulo

cout << "Simulador de Algoritmos procesos."<<endl;

  // Menu principal

    do{
   printf("MENU \n");

    cout<<"No Expropiativos: \n";
  cout<<" 1.- FIFO.\n";
  cout<<" 2.- SJF. \n\n";
    cout<<"Expropiativos: \n";
  cout<<" 3.- Round Robin. \n";
  cout<<" 4.- Prioridad. \n\n";
  cout<<" 0.- Salir. \n";

  cout<<"Selecciona Opción: ";
cin>> opc; 
	

	switch(opc){
		case 1: {
      	cout << "Algoritmo FIFO " <<endl;
		// Borramos el sector derecho de la pantalla
int y = 4;
int n = 0;
int tmp_bt = 0;
string tmp_pid;
          
  cout << "Tamaño de la lista: "; 
      cin >> n;
      
   Fifo sch(n);
 // Ingresar datos
 for(int i = 0; i < n; i++){
y = y + 2;
        
cout << "[" << i+1 << "] Set PID: "; cin >> tmp_pid;
                  
  cout << "[" << i+1 << "] Set BT:  "; cin >> tmp_bt;
  sch.enqueue(tmp_bt, tmp_pid); 
                    }
sch.FifoProcess();
break;
				}
			
        
case 2: {

	cout << "Algoritmo SJF " <<endl;
  int size = 0;
  
cout << "Tamaño de lista: "; 
  cin >> size;
 // Inicializando la lista
 SJF sch(size);
sch.scheduler();

break;
				}
				
case 3: {

cout << "Algoritmo RoundRobin: "<<endl;
int p = 0;
int q = 0;

		
cout << "Ingresa la cantidad de procesos: ";
cin >> p;
		
cout << "Ingresa el quantum: "; 
  cin >> q;

  RoundRobin robin(p, q);
          
					break;
				}
	case 4: {

cout << "Algoritmo Prioridad: " <<endl;
	
				  
Prioridad p(3);
    
  p.scheduler();
					break;
				}
        
		
			}
      
}while(opc != 0);
  cout<<"Hasta luego ";

	return 0;
}
