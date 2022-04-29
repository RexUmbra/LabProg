#include <iostream>
using namespace std;
struct Queue
{
    int ch;
    Queue* next, * pr;
};
Queue* begin, * end;

void pushBack(Queue*& q, int a)
{
    Queue* t = new Queue;
    t->ch = a;
    t->next = NULL;
    if (::begin == NULL)
    {
        t->pr = NULL;
        q = t;
        ::begin = ::end = q;
    }
    else
    {
        ::end->next = t;
        t->pr = ::end;
        ::end = t;
        ::end->next = NULL;
    }
    
}
void pushFront(Queue*& q, int a)
{
    Queue* t = new Queue;
    t->ch = a;
    t->pr = NULL;
    if (::begin == NULL)
    {
        t->next = NULL;
        q = t;
        ::begin = ::end = q;
    }
    else
    {
        ::begin->pr = t;
        t->next = ::begin;
        ::begin = t;
    }
}
void print()
{
    Queue* t = ::begin;
    if (::begin == NULL)
    {
        cout << "queue is enmpty\n";
    }
    else
    {
        while (t != ::end->next)
        {
            cout << t->ch << " ";
            t = t->next;
        }
    }
    cout << "\n";
}
void printRev()
{
    Queue* t = ::end;
    if (::begin == NULL)
    {
        cout << "queue if empty\n";
    }
    else
    {
        while (t != ::begin->pr)
        {
            cout << t->ch << " ";
            t = t->pr;
        }
    }
    cout << "\n";
}

void deleteEveryM(Queue*& q,int m)
{
    Queue* t = q;
    int i = 1;
    while (t != NULL)
    {
        if ((i % m) != 0)
        {
            t = t->next;
            i++;
        }
        else
        {
            Queue* temp = t;
            t->pr->next = t->next;
            if (t->next != NULL)
                t->next->pr = t->pr;
            else 
                ::end = t->pr;
            t = t->next;
            delete temp;
            i = 1;
        }
    }
}
void menu(Queue*& q)
{
    string ans;
    int m;
    while (true)
    {
        cout << "1 - push back, 2 - push front, 3 - print, 4 - print Rev, 5 - delete each m element, 6 - end\n";
        cin >> ans;
        if (ans == "1")
        {
            cout << "write number\n";
            cin >> m;
            pushBack(q, m);
        }
        else if (ans == "2")
        {
            cout << "write number\n";
            cin >> m;
            pushFront(q, m);
        }
        else if (ans == "3")
            print();
        else if (ans == "4")
            printRev();
        else if (ans == "5")
        {
            cout << "write number\n";
            cin >> m;
            deleteEveryM(q, m);
        }
        else if (ans == "6")
        {
            break;
        }
    }
    

}
int main()
{
    Queue *q = NULL;
    ::begin = ::end = q;
    menu(q);
}
