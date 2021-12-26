#include <bits/stdc++.h>
using namespace std;
random_device rnd;
mt19937 mt(rnd());
normal_distribution<> ndist(0.0, 1.0);

// p(x, y) ~ exp(x^2+y^2+xy)
int main()
{
    cout << "Gibbs" << endl;
    int niter = 1000000;
    double x = 0;
    double y = 0;
    for (int i = 0; i < niter; i++)
    {
        double sigma = 1;
        double mu;
        // xの更新
        mu = -y / 2;
        x = ndist(mt) * sigma + mu;
        // yの更新
        mu = -x / 2;
        y = ndist(mt) * sigma + mu;
        // 出力
        cout << x << " " << y << " ";
    }
    cout << endl;
}