#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;
    node()
    {
        next = nullptr;
    }
    node(int el, node *p = 0){
        data = el;
        next = p;
    }
};