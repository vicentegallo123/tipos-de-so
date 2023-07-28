#ifndef RoundRobin_hpp
#define RoundRobin_hpp

#include <iostream>
#include <cstdlib>
using namespace std;

class RoundRobin{  


class Node{
    public:
    string name;
    int tm;
    int rt;
    float avg_tat;
    Node *next;
};
  
    private:
        Node *head = NULL;
        int size;
        float quantumm;
        int y;
    public:
        RoundRobin(int, float);      // Queue size | Quantumm
        void push(string, int); // PID | BT 
        void pop(string);
        void process(int);

};

#endif