#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double f(double x) { return x * x + 10 * pow(sin(x), 2) + 2; }
double df(double x) { return 2 * x - 10 * sin(x * 2); }

int main() {
    double tmp, x, eps;

    cout << "eps=";
    cin >> eps;   
    cout << "x0=";
    cin >> x;     
    tmp = x + 2 * eps;
    while (fabs(x - tmp) > eps) { 
        tmp = x;
        x = x - f(x) / df(x);
    }
    cout << "x=" << x;
    return 0;
}
