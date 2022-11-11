#include<iostream>
#include"Dll.cpp"
using namespace std;

int main()
{
    dll d;
    char ch = 'y';
    do
    {
        cout<<"\n1 add to head\n"
            <<"\n2 display\n"
            <<"\n3 add to tail\n"
            <<"\n4 add to between\n"
            <<"\n5 delete from head\n"
            <<"\n6 delete from tail\n"
            <<"\n7 delete from between\n"
            <<"\n8 search"<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:{
                int x;
                cout<<"Enter element: ";
                cin>>x;
                d.add_to_head(x);
                break;
            }
            case 2:{
                d.display();
                break;
            }
            case 3:{
                int x;
                cout << "Enter element: ";
                cin >> x;
                d.add_to_tail(x);
                break;
            }
            case 4:{
                int x;
                cout<<"Enter element: ";
                cin>>x;
                d.add_to_between(x);
                break;
            }
            case 5:{
                d.delete_from_head();
                break;
            }
            case 6:{
                d.delete_from_tail();
                break;
            }
            case 7:{
                d.delete_from_between();
                break;
            }
            case 8:{
                int x;
                cout<<"Enter element which do you want to find: ";
                cin>>x;
                d.search(x);
                break;
            }
        }
    }while(ch == 'y');
    return 0;
}