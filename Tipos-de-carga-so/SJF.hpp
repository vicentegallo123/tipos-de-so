#ifndef SJF_hpp
#define SJF_hpp

#include <cstdlib>
#include <iostream>
using namespace std;

class SJF{

class Node{
    public:
        Node(){}
        Node(int bt, int at, string d): bt(bt), at(at), data(d){}
        void setWT(int wt);
        int bt;
        int at;
        int wt;
        string data;
};
class QuickSort{
    public:
        static void swap(Node*, Node*);
        static void sort(Node*, int, int);
        static void show(Node*, int);
        static int separate(Node*, int, int);
        static int size(int data[]);
};
    int size;
    int twt;
    float awt;
    int y;
    Node *bucket;
    public:
        SJF(int);
        SJF(){}
        // Scheduler
        void scheduler();
        // Setters
        void setData();
        // Testing
        void print();
        // Calcular wt
        void waitingCalculator();
};

#endif