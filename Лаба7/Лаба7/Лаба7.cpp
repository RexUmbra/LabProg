#include <iostream>
#include <math.h>
using namespace std;

double f(double x)
{
    return log(x) - 5 * cos(x);
}

double Simps(double a, double b, int n)
{
    double s = 0.0,
        h = (b - a) / n,
        x = a;
    for (int i = 1; i <= n; i++, x += h) {
        s += f(x) + 4.0 * f(x + h / 2.0) + f(x + h);
    }
    return s * h / 6.0;
}

int main()
{
    int n = 0;
    double eps = 0.0, a, b;
    string ans;
    while (true) {
        cout << "\nRazbienit - 1, tochnost - 2, exit - 3\n";

        cin >> ans;

        if (ans == "0")  return 0;

        if (ans == "1" || ans == "2") {
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            if (a == b)
            {
                cout << "S = 0\n";
            }
            if (ans == "1")
            {
                do
                {
                    cout << "write n(>0)\n";
                    cin >> n;
                } while (n <= 0);
                cout << Simps(a, b, n) << '\n';
            }
            if (ans == "2")
            {
                do
                {
                    cout << "write eps(>0)\n";
                    cin >> eps;
                } while (eps <= 0);
                n = 2;
                double S1, S2;
                S1 = Simps(a, b, n);
                do {
                    n *= 2;
                    S2 = Simps(a, b, n);
                    S1 = S2;
                } while (fabs(S2 - S1) > eps);
                cout << S1 << "\n";
            }
        }
        else cout << "incorrect ans\n";
    }
}