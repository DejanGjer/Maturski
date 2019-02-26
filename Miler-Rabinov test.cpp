#include <iostream>
using namespace std;
typedef long long ll;

ll mod_stepenovanje(ll x, ll y, ll m)
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
    return rez;
}

bool proveri(ll d, ll n)
{
    // funkcija vraca false ako je broj sigurno slozen
    // a u suprotnom vraca true (onda je broj verovatno prost)
    // biramo slucajan broj u opsegu[2..n-2]
    ll a = 2 + rand() % (n - 4);
    ll x = mod_stepenovanje(a, d, n);
    if (x == 1  || x == n - 1)
       return true;
    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}


bool test_miler_rabina(ll n, int k)
{
    // granicni slucajevi
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    // trazimo r tako da je n = 2^d * r + 1
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    // da bi rezultat bio pouzdaniji
    // proveravamo k puta
    for (int i = 0; i < k; i++)
         if (!proveri(d, n))
              return false;
    return true;
}

int main()
{
    printf("%d\n", test_miler_rabina(2147483647, 1));      // 10-digits prime
    printf("%d\n", test_miler_rabina(136117223861LL, 1));
    return 0;
}
