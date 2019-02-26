#include <iostream>
#include <time.h>

using namespace std;
typedef long long ll;

ll nzd(ll a, ll b)
{
    return b == 0 ? a : nzd(b, a % b);
}

ll PolardRo(ll n, int k)
{
    if(k <= 0)
        return n;
    if(n == 1)   //za 1 ne proveravamo
        return 1;
    if(n % 2 == 0)  //odmah proverimo deljivost za 2
        return 2;
    srand(time(NULL));

    ll x = rand() % (n - 2) + 2;
    ll y = x;
    ll c = rand() % (n - 1) + 1;
    ll d = 1;

    while(d == 1)
    {
        x = ((x * x) % n + c) % n;
        y = ((y * y) % n + c) % n;
        y = ((y * y) % n + c) % n;
        //koristimo nzd ciju implementaciju vec imamo
        d = nzd(n, abs(x - y));
    }
    //ako je NZD jednak n, znaci da je x - y = 0
    if(d == n)
        return PolardRo(n, k - 1);
    //mozemo ponovo pokusati sa drugom funkcijom
    //ili vratimo delilac ako je pronadjen
    return d;
}

int main()
{
    cout << PolardRo(589, 100) << "\n";
    return 0;
}
