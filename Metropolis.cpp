#include <bits/stdc++.h>
using namespace std;
random_device rnd;
mt19937 mt(rnd());
uniform_real_distribution<> udist(0, 1);

// p(x) ~ exp(-S(x))からサンプリング（今回はN(0, 1))
double S(double x)
{
    return x * x / 2;
}

int main()
{
    cout << "Metropolis" << endl;
    int niter = 1000000;
    double step_size = 0.5;
    double x = 0;
    for (int i = 0; i < niter; i++)
    {
        double dx = (1 - udist(mt) * 2) * step_size;
        double nx = x + dx;
        double metropolis = udist(mt);
        if (exp(S(x) - S(nx)) > metropolis)
        {
            x = nx;
        }
        cout << x << " ";
    }
    cout << endl;
}