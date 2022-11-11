#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *previous;
    node()
    {
        next = nullptr;
        previous = nullptr;
    }
    node(int el, node *nptr = 0, node *pptr = 0)
    {
        data = el;
        next = nptr;
        previous = pptr;
    }
};