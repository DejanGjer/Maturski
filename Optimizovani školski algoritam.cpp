#include <iostream>
using namespace std;
typedef long long ll;
bool prostSkolski(ll n)
{
    // Granicni slucajevi
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    // Jedini prosti brojevi deljivi sa 2 i 3
    if (n % 2 == 0 || n % 3 == 0) return false;
    // Proveravamo da li je n deljivo za sve brojeve
    // oblika 6*k-1 i 6*k+1 takve da je njihov kvadrat
    // manji ili jednak sa n
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
           return false;

    return true;
}

int main()
{
    cout << prostSkolski(2) << "\n";
    cout << prostSkolski(11) << "\n";
    cout << prostSkolski(30) << "\n";
    cout << prostSkolski(31) << "\n";
    cout << prostSkolski(35) << "\n";
    cout << prostSkolski(104729) << "\n";
    cout << prostSkolski(2147483647) << "\n";
    cout << prostSkolski(2821) << "\n";
    cout << prostSkolski(112272535095293) << "\n";

    return 0;
}
