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
int modulani_inverz(int a, int p)
{
    return mod_stepenovanje(a, p - 2, p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> p >> x;
    ll rez = 0;
    for(int j = 0; j < p - 1; j++)
    {
        int y = (int)(((ll)b * (ll)modulani_inverz(mod_stepenovanje(a,j,p), p)) % p);
        ll prvi = (ll)(p - 1) * ((j - y + p) % p) + j;
        if(prvi > x)
            continue;
        else
            rez += (x - prvi) / ((ll)p * (p - 1)) + 1;
    }
    cout << rez;
    return 0;
}
