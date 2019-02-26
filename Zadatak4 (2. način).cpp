#include <iostream>
typedef long long ll;
using namespace std;
int a,b,p;
ll x;
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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> p >> x;
    ll rez = 0;
    int y1 = modularni_inverz1(p, p - 1);
    int y2 = modularni_inverz1(p - 1, p);
    for(int j = 0; j < p - 1; j++)
    {
        int y = (int)(((ll)b *
            modularni_inverz1(mod_stepenovanje(a,j,p), p)) % p);
        ll prvi = ((ll)p * y1 * j + (ll)(p - 1) * y2 * y)
            % ((ll)p * (p - 1));
        if(prvi > x)
            continue;
        else
            rez += (x - prvi) / ((ll)p * (p - 1)) + 1;
    }
    cout << rez;
    return 0;
}
