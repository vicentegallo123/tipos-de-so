#include "Fifo.hpp"
#include "iostream"
#include <stdio.h>
#include <iostream>

using namespace std;
// Constructor
Fifo::Fifo(int c): _capacity(c){
    this->_size = 0;
    this->eos = NULL;
    this->sos = NULL;
}
// Destructor
Fifo::~Fifo(){
    while(!isEmpty()){
        dequeue();
    }   
}
// Enlista procesos
void Fifo::enqueue(int bt, string pid){
    // PrecondiciÃ³n para controlar si estÃ¡ llena
    if(isFull()){ 
        cout << "No se puede enlistar un proceso nuevo." << endl;
    }else{
        // Un puntero temporal para guardar los datos del nuevo nodo
        Process *tmp = new Process(pid, bt);
        tmp->next(NULL); // Su puntero next se guarda en NULL porque no hay datos mas allÃ¡ de el
        // Revisamos si es el primer dato ingresado
        if(getSize() == 0){
            // Si es el primer dato, head y tail es lo mismo
            eos = tmp;
            sos = tmp;
        }else{
            // Si no, hacemos que el next head sea el nuevo dato
            eos->next(tmp);
            eos = tmp;
        }
        // Aumentamos el tamaÃ±o +1
        _size++;
    }
}
bool Fifo::dequeue(){
    // PrecondiciÃ³n para controlar si esta vacÃ­a
    if(isEmpty()){
        cout << "Empty process list " << endl;
        return false; // Retornamos falso
    }else{
        // Si solo existe un dato en la lista, entonces head y tail ahora son nulos
        // y borramos head
        if(getSize() == 1){
            delete sos;
            sos = NULL;
            eos = NULL;

            _size = 0; 
        }else{
            // Hacemos un temporal de head
            Process *tmp = sos;
            // Hacemos que head ahora sea igual a su next
            sos = sos->next(); 
            // Borramos el temporal
            delete tmp;
            // Decrementamos el size
            _size--;
        }
        return true;
    }
}
void Fifo::FifoProcess(){
  
    int wt = 0; // Waiting time
    int y = 7;
    // PrecondiciÃ³n para controlar si esta vacÃ­a
    if(isEmpty()){
        cout << "Cannot print an empty schedule list" << endl;
    }else{
        // Hacemos un head temporal para no modificar el original
        Process *tmp_sos = sos;
        // Mientras head no sea null ejectuamos el algoritmo de scheduler
        while(tmp_sos != NULL){
            y = y + 1;
            // Sumamos el tiempo de espera original mas el proceso actual
            wt = wt + tmp_sos->getBT();
            // Imprimimos los datos
       
            cout << left << "PID: " << tmp_sos->getPID();
          
            cout << left << " WT: " << wt << endl;
            // Cambiamos al next
            tmp_sos = tmp_sos->next();
        }   
  cout << "_______________________________________" << endl;
      
        cout << "Process count: " << getSize() << endl;
      
        cout << "Average Wait Time: " << wt / float(getSize()) << endl;
      
        cout << "Total Wait Time: " << wt << endl;
        cout << endl;
        // Free tmp_sos space
        delete tmp_sos;
    }
}
void Fifo::peek(){
    cout << eos->getPID() << endl;
    cout << eos->getBT() << endl;
} 
