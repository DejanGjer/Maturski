#include <iostream>
using namespace std;
int t, n, m;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        if(n % (m + 1) == 0)
            cout << "2";
        else
            cout << "1";
    }
    return 0;
}
