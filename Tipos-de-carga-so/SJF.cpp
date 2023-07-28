#include "SJF.hpp"
#include <iostream>
using namespace std;


void SJF::Node::setWT(int _wt){
    this->wt = _wt;
}

void SJF::QuickSort::swap(Node *a, Node *b){
    Node t = *a;
    *a    = *b;
    *b    = t;
}
void SJF::QuickSort::sort(Node* bucket, int _low, int _high){
    // Lowest to greatest number order
    if(_low < _high){
        // Creating a partition
        int _partiton = separate(bucket, _low, _high);

        sort(bucket, _low, _partiton - 1);
        sort(bucket, _partiton + 1, _high);
    }
}
int SJF::QuickSort::separate(Node* bucket, int _low, int _high){
    int pivot = bucket[_high].bt;
    // Index of smallest element
    int i     = _low - 1;
    // Traversing array for comparision
    for(int x = _low; x <= _high - 1; x++){
        if(bucket[x].bt <= pivot){
            i++;
            swap(&bucket[i], &bucket[x]);
        }
    }
    // Swap on the next element before smallest element
    swap(&bucket[i + 1], &bucket[_high]);
    return i + 1;
}
void SJF::QuickSort::show(Node *bucket, int n){
    for(int i = 0; i < n; i++){
        cout << "["<<i<<"]"<<bucket[i].at << " Data: " << bucket[i].data <<endl;
    }
}
int SJF::QuickSort::size(int bucket[]){
    return sizeof(bucket);
}

SJF::SJF(int x): size(x){
    this->bucket = new Node[size];
    this->awt    = 0;
    this->twt    = 0;
    // Leyendo los datos
    this->setData();
    // Ordenando los datos
    QuickSort::sort(this->bucket, 0, size - 1);
}
void SJF::scheduler(){
    this->waitingCalculator();
    this->print();

    cout << "Tiempo de espera: " << this->twt << endl;
   
    cout << "Tiempo de espera promedio: " << this->awt << endl;
}
// Ingresar datos
void SJF::setData(){
    y = 12;
    Node tmp;
    int _key  = 0;
    int _at = 0;
    string _data;
    for(int i = 0; i < this->size; i++){
        this->y = this->y + 2;
    
        cout << "["<<i<<"] Arrival time: "; cin >> _at;
   
        cout << "["<<i<<"] Burst time: "; cin >> _key;
    
        cout << "["<<i<<"] Data: "; cin >> _data;
        tmp = Node(_key, _at, _data);
        this->bucket[i] = tmp;
    }
}
// Calcular waiting times
void SJF::waitingCalculator(){
    int sum = 0;
    for(int i = 0; i < this->size; i++){
        // Guardar los waiting times
        int _key = this->bucket[i].bt;
        if(i == 0){
            this->bucket[i].setWT(_key);
            // cout << this->bucket[i].data << " " << "CWT: " << _key << " BT:" << this->bucket[i].bt << endl;
        }else{
            this->bucket[i].setWT(this->bucket[i - 1].bt + _key);
            // cout << this->bucket[i].data << " " << "CWT: " << this->bucket[i - 1].bt + _key <<" BT: " << this->bucket[i].bt << endl;
        }
        sum = this->bucket[i].wt;
        // cout << this->bucket[i].data << " " << this->bucket[i].bt << endl; 
    }
    this->twt = sum;
    this->awt = float(sum) / this->size;

    //cout << "Suma: " << sum << endl;
    //cout << "Prom: " << float(sum) / this->size << endl;
}
void SJF::print(){
    
    for(int i = 0; i < this->size; i++){
        this->y++;
      
        cout << "["<<i<<"] Data: " << this->bucket[i].data;
    
        cout << " WT: " << this->bucket[i].wt;
 
        cout << " BT: " << this->bucket[i].bt << endl;
    }
}