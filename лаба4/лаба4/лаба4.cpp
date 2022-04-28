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

int main()
{
    Queue *q = NULL;
    
    ::begin = ::end = q;
    /*pushFront(q, 1);
    pushFront(q, 2);
    pushFront(q, 3);
    pushFront(q, 4);*/
    pushBack(q, 1);
    pushBack(q, 2);
    pushBack(q, 3);
    pushBack(q, 4);
    print();
    deleteEveryM(q,2);
    print();
    
}
