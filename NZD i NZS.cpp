#include <iostream>

using namespace std;
typedef long long ll;
ll nzd(ll a, ll b)
{
    return b == 0 ? a : nzd(b, a % b);
}
ll nzs(ll a, ll b)
{
    return a * (b / nzd(a, b));
}

int main()
{
    cout << nzd(252, 918);
    return 0;
}
