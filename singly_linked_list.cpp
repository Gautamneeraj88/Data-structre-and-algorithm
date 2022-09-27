#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        next = NULL;
    }
    node(int el, node *ptr = 0)
    {
        data = el;
        next = ptr;
    }
};

class sll : public node
{
    node *first, *last, *temp, *temp1;

public:
    sll()
    {
        first = NULL;
        last = NULL;
    }

    ~sll()
    {
        for (node *p; isempty();)
        {
            p = first->next;
            delete first;
            first = p;
        }
    }
    int isempty()
    {
        if (first == NULL)
            return first == 0;
    }

    void add_to_head(int el)
    {
        temp = new node(el);
        if (first == NULL)
        {
            first = last = temp;
        }
        else
        {
            temp->next = first;
            first = temp;
        }
    }

    void add_to_tail(int el)
    {
        temp = new node(el);
        if (first == NULL)
        {
            first = last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    void add_to_between(int el)
    {
        temp1 = new node(el);
        temp = first;
        int key;
        cout << "Enter value after you want to inster the node: ";
        cin >> key;
        while (temp != NULL)
        {
            if (key == temp->data)
            {
                temp1->next = temp->next;
                temp->next = temp1;
            }
            temp = temp->next;
        }
    }

    int delete_from_head()
    {
        int el = first->data;
        temp = first->next;
        if (first == last)
        {
            first = last = NULL;
        }
        else
        {
            delete first;
            first = temp;
        }
        return el;
    }

    int delete_from_tail()
    {
        int el = last->data;
        if (first == last)
        {
            delete first;
            first = last = NULL;
        }
        else
        {
            for (temp = first; temp->next != last; temp = temp->next)
            {
                delete last;
                last = temp;
                last->next = NULL;
            }
            return el;
        }
    }
    void display()
    {
        temp = first;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    sll singly;
    char ch = 'y';
    do
    {
        cout << "1. add to head"
             << "\t2. display"
             << "\t3.add to tail"
             << "\t4.add to between"
             << "\t5.delete from head"
             << "\t6.delete from tail" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter data: ";
            int x;
            cin >> x;
            singly.add_to_head(x);
            break;
        }
        case 2:
        {
            singly.display();
            break;
        }
        case 3:
        {
            cout << "Enter data: ";
            int x;
            cin >> x;
            singly.add_to_tail(x);
            break;
        }
        case 4:
        {
            cout << "Enter data: ";
            int x;
            cin >> x;
            singly.add_to_between(x);
            break;
        }
        case 5:
        {
            cout << "Deleted node is: " << singly.delete_from_head() << endl;
            break;
        }
        case 6:
        {
            cout << "Deleted node is: " << singly.delete_from_tail() << endl;
            break;
        }
        default:
        {
            cout << "Wrong choice" << endl;
            break;
        }
        }
        cout << "Do you want to continue or not (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}