#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Data
{
    int n;
    string str;
    void print()
    {
        cout << n << "(" << str << ")" << '\n';
    }
};
struct Tree
{
    Data data;
    Tree* left, * right;
};
void add(Tree*& tr, int n, string str)
{
    if (tr == NULL)
    {
        Tree* t = new Tree();
        t->data.n = n;
        t->data.str = str;
        t->left = NULL;
        t->right = NULL;
        tr = t;
        return;
    }
    else if (n < tr->data.n) add(tr->left, n, str);
    else add(tr->right, n, str);

}
void print(Tree* tr, int lvl)
{
    if (tr != NULL)
    {
        print(tr->right, ++lvl);
        for (int i = 0; i < lvl; ++i) cout << "  ";
        tr->data.print();
        print(tr->left, ++lvl);
        lvl--;
    }
}
void addToVec(Tree* tr, vector<Data> &vec)
{
    if (tr != NULL)
    {
        vec.push_back(tr->data);
        if (tr->left) addToVec(tr->left, vec);
        if (tr->right) addToVec(tr->right, vec);
    } 
}
void addFromVec(Tree*& tr, vector<Data>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        add(tr, vec[i].n, vec[i].str);
    }
}
void print(vector<Data> vec)
{
    cout << '\n';
    for (int i = 0; i < vec.size(); i++)
        vec[i].print();
}
void find(Tree* tr, int n, string str)
{
    if (tr != NULL)
    {
        find(tr->right, n, str);
        if (tr->data.n == n && tr->data.str == str)
            tr->data.print();
        find(tr->left, n, str);
    }
}
void findTr(Tree* tr, int n, string str, Tree*& trpDel)
{
    if (tr != NULL)
    {
        if (tr->right != NULL)
            if (tr->right->data.n == n && tr->right->data.str == str)
            {
                trpDel = tr;
                return;
            }
        if (tr->left != NULL)
            if (tr->left->data.n == n && tr->left->data.str == str)
            {
                trpDel = tr;
                return;
            }
        if (tr->left != NULL)
            findTr(tr->left, n, str, trpDel);
        if (tr->right != NULL)
            findTr(tr->right, n, str, trpDel);
    }   
}
void delAll(Tree*& tr, Data data)
{
    if (!tr) return;
    delAll(tr->left, data);
    delAll (tr->right, data);
    if (data.n != tr->data.n && data.str != tr->data.str)
    {
        delete tr;
    }
    else
    {
        tr = NULL;
    }
    return;
}

void del(Tree*& tr, int n, string str)
{
    if (tr != NULL)
    {
        Tree* sTree;
        if (tr->data.n != n || tr->data.str != str)
        {
            Tree* trPdel = NULL;
            findTr(tr, n, str, trPdel);
            if (trPdel != NULL)
            {
                if (trPdel->left->data.n == n && trPdel->left->data.str == str)
                {
                    sTree = trPdel->left->left;
                    if (trPdel->left->right == NULL)
                    {
                        trPdel->left = sTree;
                    }
                    else if (trPdel->left->right != NULL)
                    {
                        trPdel->left = trPdel->left->right;
                        Tree* min = trPdel->left;
                        while (min->left != NULL)
                            min = min->left;
                        min->left = sTree;
                    }
                }
                else if (trPdel->right->data.n == n && trPdel->right->data.str == str)
                {
                    sTree = trPdel->right->left;
                    if (trPdel->right->right == NULL)
                    {
                        trPdel->right = sTree;
                    }
                    else if (trPdel->right->right == NULL)
                    {
                        trPdel->right = trPdel->right->right;
                        Tree* min = trPdel->right;
                        while (min->left != NULL)
                            min = min->left;
                        min->left = sTree;
                    }
                }
            }
            else
            {
                cout << "not find\n";
                return;
            }
            
        }
        else if (tr->data.n == n || tr->data.str == str)
        {
            sTree = tr->left;
            tr = tr->right;
            Tree* min = tr;
            while (min->left != NULL)
                min = min->left;
            min->left = sTree;
        }
        
    }
}
void clearVec(vector<Data>& vec)
{
    vec.clear();
}
void self(Tree* tr, int& n) //col vo listov
{
    if (tr != NULL)
    {
        self(tr->right, n);
        if (tr->right == NULL && tr->left == NULL)
            n++;
        self(tr->left, n);

    }
}
void t(Tree*& tr)
{
    add(tr, 9, "9");
    add(tr, 17, "17");
    add(tr, 6, "6");
    add(tr, 3, "3");
    add(tr, 8, "8");
    add(tr, 16, "16");
    add(tr, 20, "20");
    add(tr, 1, "1");
    add(tr, 4, "4");
    add(tr, 7, "7");
    add(tr, 12, "12");
    add(tr, 19, "19");
    add(tr, 21, "21");
    add(tr, 11, "11");
    add(tr, 14, "14");
    add(tr, 18, "18");
    add(tr, 10, "10");
    add(tr, 13, "13");
    add(tr, 15, "15");
}

void menu(vector<Data> vec, Tree*& tr)
{
    string ans;
    while (true)
    {
        cout << "1 - add, 2 - print, 3 - add to vector, 4 - add from vector, 5 - clean vector, 6 - clean tree, 7 - find, 8 - delete element, 9 - self, 10 - standart, 11 - print vec, 0 - exet\n";
        cin >> ans;
        if (ans == "1")
        {
            cout << "write n ans string\n";
            int n;
            string str;
            cin >> n >> str;
            add(tr, n, str);
        }
        else if (ans == "2")
            print(tr, 0);
        else if (ans == "3")
            addToVec(tr, vec);
        else if (ans == "4")
            addFromVec(tr, vec);
        else if (ans == "5")
            clearVec(vec);
        else if (ans == "6")
            delAll(tr,tr->data);
        else if (ans == "7")
        {
            cout << "write n ans string\n";
            int n;
            string str;
            cin >> n >> str;
            find(tr,n,str);
        }
        else if (ans == "8")
        {
            cout << "write n ans string\n";
            int n;
            string str;
            cin >> n >> str;
            del(tr, n, str);
        }
        else if (ans == "9")
        {
            int n = 0;
            self(tr, n);
            cout << "listov: " << n << '\n';
        }
        else if (ans == "10")
        {
            t(tr);
        }
        else if (ans == "0")
        {
            break;
        }
        else if (ans == "11")
        {
            print(vec);
        }
    }
}
int main()
{
    vector<Data> vec;
    Tree* tr = NULL;
    menu(vec, tr);
    
}
