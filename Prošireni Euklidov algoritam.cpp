#include <iostream>
typedef long long ll;
using namespace std;

int prosireniEuklidovAlgoritam(int a, int b, int &x0, int &y0)
{
    if (b == 0) { x0 = 1; y0 = 0; return a; } //granicni slucaj
    int x1, y1;
    int nzd = prosireniEuklidovAlgoritam(b, a % b, x1, y1);
    x0 = y1;
    y0 = x1 - (a / b) * y1;
    return nzd;
}

ll nzd(ll a, ll b)
{
    return b == 0 ? a : nzd(b, a % b);
}
int main()
{
    int x0,y0;
    int d = prosireniEuklidovAlgoritam(27,59,x0,y0);
    cout << x0 << " " << y0 << " " << d;
    return 0;
}
