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

int modularni_inverz1(int a, int m)
{
    a %= m;
    int x,y;
    int nzd = prosireniEuklidovAlgoritam(a, m, x, y);
    if(nzd != 1)
        return -1;
    else
        return (x % m + m) % m;
}

int mod_stepenovanje(ll x, ll y, ll m)
{
    ll rez = 1;
    x = x % m;
    while (y > 0)
    {
        // ako je y neparno mnozimo rez sa x
        // po modulu m
        if (y & 1)
            rez = (rez * x) % m;
        // sada je y sigurno parno
        y = y >> 1; // y = y/2
        x = (x * x) % m;
    }
    return (int)rez;
}
int modulani_inverz2(int a, int p)
{
    if(a == 0)  return -1;
    else
        return mod_stepenovanje(a % p, p - 2, p);
}


int main()
{
    cout << modularni_inverz1(3,7) << "\n";
    cout << modulani_inverz2(3,7);
    return 0;
}
