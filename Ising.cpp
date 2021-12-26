#include <bits/stdc++.h>
using namespace std;

// constant
double J = 1;
double beta = 1;
int n = 10;

random_device rnd;
mt19937 mt(rnd());
uniform_real_distribution<> udist(0.0, 1.0);
uniform_int_distribution<> uidist(0, n - 1);

double E(vector<vector<int>> &s, double h) // calculate energy
{
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    double inter = 0, sm = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sm += s[i][j];
            for (int d = 0; d < 4; d++)
            {
                int ni = (i + dx[d] + n) % n, nj = (j + dy[d] + n) % n;
                inter += s[i][j] * s[ni][nj];
            }
        }
    }
    return -J / 2 * inter - h * sm; // 相互作用項は2回足しているので /2 をする
}

int main()
{
    cout << "Ising" << endl;
    int niter = 15000;
    int report_interval = 100;
    double h = -0.4;
    vector<vector<int>> s(n, vector<int>(n, 1));

    int cnt = n * n; // +1の数
    for (int i = 0; i < niter; i++)
    {
        if (i > 0 && i % report_interval == 0)
        {
            cout << h << " " << cnt << " ";
            h -= 0.02;
        }
        int x = uidist(mt), y = uidist(mt); //ランダムにサイトを選択
        cnt -= s[x][y];

        s[x][y] = 1;
        double Ep = E(s, h);
        s[x][y] = -1;
        double Em = E(s, h);

        double p = exp(-beta * Ep) / (exp(-beta * Ep) + exp(-beta * Em));
        if (udist(mt) < p)
        {
            s[x][y] = 1;
        }
        cnt += s[x][y];
    }
    cout << endl;
}