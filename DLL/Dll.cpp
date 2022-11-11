#include<iostream>
#include"Node.cpp"
using namespace std;

class dll:public node
{
    private:
    node *temp, *head, *tail, *temp1;
    public:
    dll()
    {
        head  = nullptr;
        tail  = nullptr;
        temp  = nullptr;
        temp1 = nullptr;
    }
    ~dll()
    {
        for(node * p; isempty();)
        {
            p = head->next;
            delete head;
            head = p;
        }
    }
    int isempty();
    void add_to_head(int el);
    void add_to_tail(int el);
    void add_to_between(int el);
    void delete_from_head();
    void delete_from_tail();
    void delete_from_between();
    void search(int el);
    void display();
};

int dll::isempty()
{
    if(head == NULL)
    {
        return head == 0;
    }
}

void dll::add_to_head(int el)
{
    temp = new node(el);
    if(head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head;
        head->previous = temp;
        head = temp;
    }
}

void dll::add_to_tail(int el)
{
    temp = new node(el);
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }
}

void dll::add_to_between(int el)
{
    temp1 = new node(el);
    if (head == NULL)
    {
        head = tail = temp;
    }
    else{
        temp = head;
        int count = 0;
        int position;
        cout<<"Enter the positon for insertion of new node: ";
        cin>>position;
        while(temp != NULL)
        {
            if(count == position)
            {
                temp1->next = temp->next;
                temp1->previous = temp;
                temp->next = temp1;
                temp1->next->previous = temp1;
            }
            count+=1;
            temp = temp->next;
        }
    }
}

void dll::delete_from_head()
{
    int el = head->data;
    temp = head->next;
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(head == tail)
    {
        el = head->data;
        delete head;
        head = tail = nullptr;
    }
    else
    {
        head->next = nullptr;
        delete head;
        temp->previous = nullptr;
        head = temp;
    }
    cout << "Deleted element is: " << el << endl;
}

void dll::delete_from_tail()
{
    int el = tail->data;
    temp = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (head == tail)
    {
        el = tail->data;
        delete tail;
        tail = head = nullptr;
    }
    else
    {
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        temp->next->previous = nullptr;
        delete temp->next;
        temp->next = nullptr;
    }
    cout << "Deleted element is: " << el << endl;
}

void dll::delete_from_between()
{
    int el;
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(head == tail)
    {
        el = head->data;
        delete head;
        head = tail = nullptr;
    }
    else
    {
        temp = head;
        int count = 0;
        int del;
        cout<<"Enter at which position do you want to delete: ";
        cin>>del;
        while(temp != NULL)
        {
            if(count == del-1)
            {
                temp1 = temp->next;
                temp->next = temp1->next;
                temp1->next->previous = temp;
                el = temp1->data;
                temp1->previous = nullptr;
                temp1->next = nullptr;
                delete temp1;
            }
            count+=1;
            temp = temp->next;
        }
    }
    cout<<"Delete element is: "<<el<<endl;
}

void dll::search(int el)
{
    temp = head;
    bool find = false;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            find = true;
            break;
        }
        count += 1;
        temp = temp->next;
    }
    if (find)
    {
        cout << "Element is found at position: " << count + 1 << " element is: " << el << endl;
    }
    else
    {
        cout << "Element is not found" << endl;
    }
}

void dll::display()
{
    temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}