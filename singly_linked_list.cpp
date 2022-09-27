#include <iostream>
using namespace std;

class node{
    public:
    int info;
    node *next;
};

class sll:public node{
    private:
    node *temp, *head, *tail;
    public:
    sll()
    {
        // temp->info = 0;7yy
        temp->next = NULL;
        head = tail = NULL;
    }
    sll(int el, sll *ptr = NULL)
    {
        info = el;
        next = ptr;
    }
    void add_to_head();
    void display();
};

void sll::add_to_head()
{
    temp = new sll();//create a empty node step1
    int x;
    cout<<"Enter data: ";
    cin>>x;
    temp->info = x;//the node's info member is initialized to a particular interger.
    if(head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head; //the node is being included at the front of the list, the next member becomes
                           //a pointer to the first node on the list; that is the current value of head;
        head = temp;//update the value of head
    }
}

void sll::display()
{
    temp = head;
    while(temp != NULL)
    {
        cout<<temp->info<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    sll singly;
    singly.add_to_head();
    singly.display();
}