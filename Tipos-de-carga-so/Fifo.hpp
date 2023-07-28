#ifndef Fifo_hpp
#define Fifo_hpp

#include <iostream>
#include <cstdlib>
using namespace std;

class Fifo{
    class Process{
    private:
        string PID;
        int BT;
        Process *p;

    public:
        Process(string _PID, int _BT): PID(_PID), BT(_BT){}
        int getBT() const { return BT; }
        string getPID() const { return PID; }
        Process *next() const { return p; }
        void next(Process *q) { p = q; } 
};


    private:
    
        // Fin-Fifo | Inicio-Fifo
        Process *eos;
        Process *sos;
        int _size, _capacity;

    public:
        // Constructor & destructor
        Fifo(){}
        Fifo(int);
        ~Fifo();
        // Procesos de enqueue y dequeue
        void enqueue(int, string);
        bool dequeue();
        // Procesar la lista actual
        void FifoProcess();
        // Getters
        int getCapacity() const { return _capacity; }
        int getSize() const { return _size; }
        // Operaciones de control
        bool isEmpty() const { return _size == 0; }
        bool isFull() const { return _size == _capacity; }
        // Testing
        void peek();
};
        

#endif