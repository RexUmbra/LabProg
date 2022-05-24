#include <iostream>
#include <math.h>
using namespace std;

double func(double x)
{
    return log(x) - 5 * cos(x);
}

double MP(double x0, double h, double e)
{
    double x1, x2, x3;
    double y1, y2, y3;
    double z1, z2, zm1, zm2, zm;
    double r, d, p, q, D;
    x1 = x0 - h;
    x2 = x0;
    x3 = x0 + h;
    y1 = func(x1);
    y2 = func(x2);
    y3 = func(x3);
    for (int it = 1; it < 100; it++)
    {
        z1 = x1 - x3;
        z2 = x2 - x3;
        r = y3;
        d = z1 * z2 * (z1 - z2);
        p = ((y1 - y3) * z2 - (y2 - y3) * z1) / d;
        q = -((y1 - y3) * pow(z2, 2) - (y2 - y3) * pow(z1, 2)) / d;
        D = sqrt(pow(q, 2) - 4 * p * r);
        zm1 = (-q + D) / (2 * p);
        zm2 = (-q - D) / (2 * p);
        if (abs(zm1) < abs(zm2)) zm = zm1;
        else zm = zm2;
        x1 = x2;
        x2 = x3;
        y1 = y2;
        y2 = y3;
        x3 = x3 + zm;
        y3 = func(x3);
        if (abs(zm) < e) break;
    }
    return x3;
}

int main()
{
    int a, b, k = 1;
    double m, h, x, eps;
    while (k) {
        cout << "\nwrite a, b\n";
        cin >> a >> b;
        cout << "m\n";
        cin >> m;
        cout << "eps\n";
        cin >> eps;
        h = (b - a) / m;
        x = a + h / 2;
        do
        {
            if (func(x - h) * func(x) < 0 && MP(x - h / 2, h, eps) != NAN)
            {
                cout << "\nx = " << MP(x - h / 2, h, eps);
                k = 0;
            }
            x += h;
        } while (x <= b);
    }
    return 0;
}
