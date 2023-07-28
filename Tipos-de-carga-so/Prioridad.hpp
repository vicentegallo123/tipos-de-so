#ifndef Prioridad_hpp
#define Prioridad_hpp

#include <cstdlib>
#include <iostream>
using namespace std;

class Prioridad {
class node{

    public:
        node(){}
        node(int x, int y): BT(x), Prio(y){}
        void setWT(int wt);
        int BT;
        int Prio;
        int WT;
  };  

class QS{
    
    public:
//Swap sera para la rotacion de valores del array
static void swap(node*, node*);
//Sort sera el que hara el ordenamiento de menor a mayor o viceversa
static void sort(node*, int, int);
//Show actualiza el resultado final del acomodo
static void show(node*, int);

static int separate(node*, int, int);
static int size(int* data);
};
	
	

  

	int size;
	int twt;
	float awt;
	int y;
	node* bucket;

	public:
		Prioridad(int);
		Prioridad() {}

		void scheduler();
		void setData();
		void print();
		void waitingCalculator();

};

#endif