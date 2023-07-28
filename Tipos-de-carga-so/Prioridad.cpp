#include "Prioridad.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Prioridad::Prioridad(int x) : size(x) {
	
	bucket = new node[size];
	awt = 0;
	twt = 0;
	setData();
	QS::sort(bucket, 0, size - 1);
	y = 12;
}

void Prioridad::node::setWT(int _wt){
    WT = _wt;

}
void Prioridad::QS::swap(node *a, node *b){
  //Se rotan las pocisiones para actualizar los valores de prioridad
    node tmp = *a;
    *a = *b;
    *b = tmp;
}

int Prioridad::QS::separate(node* bucket, int low, int high) {
    int pivot = bucket[high].Prio;
    int i = low - 1;

    for (int x = low; x <= high - 1; x++) {
        if (bucket[x].Prio <= pivot) {
            i++;
            swap(&bucket[i], &bucket[x]);
        }
    }
    swap(&bucket[i + 1], &bucket[high]);
    return i + 1;
}

void Prioridad::QS::sort(node* bucket, int low, int high){
    
    if (low < high) {
        int part = separate(bucket, low, high);

        sort(bucket, low, part - 1);
        sort(bucket, part + 1, high);
    }

}

void Prioridad::QS::show(node* bucket, int size){
    for(int i = 0; i < size; i++){
      //imprime el array actualizado
        cout << "[" << i << "] Prioridad : " <<bucket[i].Prio<< endl;
    }
}

int Prioridad::QS::size(int* bucket) {
    return sizeof(bucket);
}

void Prioridad::scheduler() {
	waitingCalculator();
	print();

	cout << " Tiempo de Espera : " << twt << endl;

	cout << "Tiempo Promedio : " << awt << endl;
}

void Prioridad::setData() {
	node tmp;
	int bt = 0;
	int Prio = 0;
	for (int i = 0; i < size; i++) {

		cout << "["<< i << "] Burst Time : "; cin >> bt;

		cout << "[" << i << "] Priority : "; cin >> Prio;
		tmp = node(bt, Prio);
		bucket[i] = tmp;
		y++;
	}
}

void Prioridad::waitingCalculator() {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		int bt = bucket[i].BT;
		if (i == 0) {
			bucket[i].setWT(bt);
		}
		else {	
			bucket[i].setWT(bucket[i - 1].BT + bt);
		}
		sum = bucket[i].WT;
	}

	twt = sum;
	awt = float(sum) / size;

}
void Prioridad::print() {
	for (int i = 0; i < size; i++) {
		y++;

		cout << "[" << i << "] Priority : " << bucket[i].Prio << endl;

		cout << "WT : " << bucket[i].WT;
	
		cout << "BT : " << bucket[i].BT << endl;
	}
}
