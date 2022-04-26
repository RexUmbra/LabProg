#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;

void add(vector<int>& vec)
{
    int n;
    cout << "write count number: ";
    cin >> n;
    cout << "\nwrite number\n";
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.push_back(t);
    }
}
void print(vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << '\n';
}

void sort(vector<int>& vec)
{
    sort(vec.begin(), vec.end());
}
void binFind(vector<int>& vec)
{
    sort(vec);
    int find;
    cout << "write find number: ";
    cin >> find;
    int i = 0 , j = vec.size()-1, m;

    sort(vec);
    auto start_time = chrono::steady_clock::now();
    while (i < j)
    {
        m = (i + j) / 2;
        if (vec[m] < find) i = m + 1;
        else j = m;
    }
    if (vec[i] != find) cout << "element is not find\n";
    else cout << find << " is " << i << " element\n";
    auto end_time = chrono::steady_clock::now();
    int a;
    auto elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    cout << elapsed_ns.count() << " *10^-9 s (ns)\n";

}
void binFindRec(int& i, int& j, int find, vector<int>& vec)
{
    int m = (i + j) / 2;
    if (vec[m] < find) i = m + 1;
    else j = m;
    if (i < j)
        binFindRec(i, j, find, vec);
}
void user(vector<int>& vec)
{
    string ans;
    while (true)
    {
        cout << "\n1 - add, 2 - print, 3 - sort, 4 - bin find, 5 - bin find rec, 0 - exit\n";
        cin >> ans;
        if (ans == "1") add(vec);
        else if (ans == "2") print(vec);
        else if (ans == "3") sort(vec);
        else if (ans == "4") binFind(vec);
        else if (ans == "5")
        {
            sort(vec);
            cout << "\nwtite find number\n";
            int t;
            cin >> t;
            int i = 0, j = vec.size() - 1;
            auto start_time = chrono::steady_clock::now();
            binFindRec(i, j, t, vec);
            if (vec[i] == t)
                cout << t << " is " << i << " element\n";
            else
                cout << "element is not find\n";
            auto end_time = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
            cout << elapsed_ns.count() << " *10^-9 s (ns)\n";
        }
        else if (ans == "0") break;
    }
}
void outFile()
{
    ofstream fout("test.txt");
    for (int i = 0; i < 1001; i++)
        fout << i << ' ';
}
void fromFile(vector<int>& vec)
{
    ifstream fin("test.txt");
    int t;
    for (int i = 0; i < 1001; i++)
    {
        fin >> t;
        vec.push_back(t);
    }
}
int main()
{
    vector<int> vec;
    user(vec);
}