#include "RoundRobin.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;


RoundRobin::RoundRobin(int _size, float _q): size(_size), quantumm(_q){
    int tmp_bt = 0;
    string tmp_pid;

    y = 9;
    for(int i = 0; i < this->size; i++){
        y++;
 
        cout << "[" << i << "]BT: "; cin >> tmp_bt;
 
        cout << "PID: "; cin >> tmp_pid;
        this->push(tmp_pid, tmp_bt);
    }
    this->process(this->quantumm);
}

void RoundRobin::push(string _pid, int _bt){
    Node *nn = new Node;
    nn->name = _pid;
    nn->tm = _bt;
    nn->rt = nn->tm;

    if (head == NULL){
        head = nn;
        head->next = head;
    }else{
      Node *temp = head;
      while (temp->next != head){
        temp = temp->next;
      }
      nn->next = temp->next;
      temp->next = nn;
    }
}
void RoundRobin::pop(string x){
  Node *p = NULL;
  Node *temp = head;

  if (head->name == x){
    while (temp->next != head){
      temp = temp->next;
    }
    p = head;
    temp->next = head->next;
    head = head->next;
    delete p;
  }else{
    while (temp->name != x){
      p = temp;
      temp = temp->next;
    }
    p->next = temp->next;
    delete temp;
  }
}
void RoundRobin::process(int t){
  Node *temp = head;
  int c = 0, i = 0;
  float avg_tat = 0;
  y = y + 4;
  while (head != NULL){
  {
    temp->rt = temp->rt - t;
    c = c + t;
    if (temp->rt <= 0){
      y++;

       

      cout << temp->name; 

      cout << " BT: " << temp->tm;

      cout << " TAT: " << c;

      cout << " WT: " << c - temp->tm << endl;

      pop(temp->name);
      if (temp->next == temp){
        break;
      }
    }
    temp = temp->next;
  }
  }
}