#include <iostream>
using namespace std;
struct Stack
{
    int ch;
    Stack* next;
};
Stack *last;

void pushFront(Stack*& st, int ch)
{

    Stack* t = new Stack;
    t->ch = ch;
    t->next = NULL;
    if (st == NULL)
        st = t;
    else
    {
        t->next = st;
        st = t;
    }
}
void print(Stack *st)
{
    Stack* t = st;
    if (t == NULL)
        cout << "stack is empty\n";
    else
    {
        while (t != last->next)
        {
            cout << t->ch << " ";
            t = t->next;
        } 
    }
    
    cout << "\n";
}
void pushBack(Stack*&st, int ch)
{
    Stack* t = new Stack;
    t->ch = ch;
    t->next = NULL;
    if (st == NULL)
    {
        st = t;
        last = st;
    }
    else
    {
        last->next = t;
        last = last->next;
    }
}
int size(Stack*& st)
{
    Stack* t = st;
    int i = 0;
    if (t != NULL)
    {
        while (t != last->next)
        {
            i++;
            t = t->next;
        }
    }
    return i;
}

int del(Stack*& st, int t)
{
    int i = 0;
    Stack* th = st;
    if(st != NULL)
    if (t == 0)
    {
        Stack* tempDel = st;
        st = st->next;
        last = st;
        delete(tempDel);
    }
    else
    {
        while (th != last)
        {
            if (i == t-1)
            {
                Stack* del = th->next;

                th->next = th->next->next;
                if (th->next == NULL)
                {
                    last = th;
                }
                delete del;
                return 1;
            }
            i++;
            th = th->next;
        }
    }
}
void popBack(Stack*& st)
{
    del(st, size(st)-1);
}
void popFront(Stack*& st)
{
    del(st, 0);
}
void delAll(Stack*& st)
{
    int size = ::size(st);
    for (int i = 0; i < size; i++)
    {
        popBack(st);
    }
}
void self(Stack*& st, int m) //delete each n element
{
    if (m == 1)
        delAll(st);
    else
    {
    Stack* t = st;
        int i = 2;
        while (t != last)
        {
            //cout << t->ch;
            if (i % m != 0)
            {
                t = t->next;
                i++;
            }
            else
            {
                Stack* temp = t->next;
                //cout << temp->ch << ":";
                t->next = t->next->next;
                if (t->next == NULL)
                {
                    last = t;
                    //cout << last->ch;
                }
                else
                t = t->next;
                delete temp;
                i = 2;
            }
        }
    }
}
void sort(Stack*& st)
{
    Stack* t = NULL, * t1;
    int r;
    do {
        for (t1 = st; t1->next != t; t1 = t1->next)
            if (t1->ch > t1->next->ch) {
                swap(t1->ch, t1->next->ch);
            }
        t = t1; 
    } while (st->next != t);
}
void sortRev(Stack*& st)
{
    Stack* t = NULL, * t1;
    int r;
    do {
        for (t1 = st; t1->next != t; t1 = t1->next)
            if (t1->ch < t1->next->ch) {
                swap(t1->ch, t1->next->ch);
            }
        t = t1;
    } while (st->next != t);
}
void menu(Stack*& st)
{
    string str;
    while (true)
    {
        cout << "1 - pushBack, 2 - pushFront, 3 - popBack, 4 - popFront, 5 - print, 6 - size, 7 - delite All, 8 - self, 9 - sort, 0 - exit, 10 - rev sort\n";
        cin >> str;
        if (str == "1")
        {
            cout << "write number\n";
            int t;
            cin >> t;
            pushBack(st, t);
        }
        else if (str == "2")
        {
            cout << "write number\n";
            int t;
            cin >> t;
            pushBack(st, t);

        }else if (str == "3")
        {
            popBack(st);
        }else if (str == "4")
        {
            popFront(st);
        }else if (str == "5")
        {
            print(st);
        }else if (str == "6")
        {
            cout << "size: " << size(st) <<'\n';
        }else if (str == "7")
        {
            delAll(st);
        }else if (str == "8")
        {
            cout << "write element\n";
            int t;
            cin >> t;
            self(st,t);
        }else if (str == "9")
        {
            sort(st);
        }
        else if (str == "0")
        {
            break;
        }
        else if (str == "10")
        {
            sortRev(st);
        }
    }


}

int main()
{
    Stack* st = NULL;
    last = st;
    menu(st);
}
