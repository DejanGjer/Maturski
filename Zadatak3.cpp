#include <iostream>
#include <algorithm>
#define MAX 100008
using namespace std;
typedef long long ll;
int nzd(int a, int b) { return b == 0 ? a : nzd(b, a % b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a[MAX], rez[MAX], g;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    g = a[0] % k;
    for(int i = 1; i < n; i++)
    {
        g = nzd(g, a[i] % k);
        if(g == 1)
            break;
    }
    int br;  //presdtavljace broj resenja
    for(br = 1; br <= k; br++)
    {
        rez[br - 1] = (int)(((ll)br * (ll)g) % (ll)k);
        if(rez[br - 1] == 0)  //ako je ostatak nula, onda
            break;    //od sledeceg prolaza pravimo petlu
    }
    sort(rez, rez + br);  //sortiramo svih resenja
    cout << br << "\n";
    for(int i = 0; i < br; i++)
        cout << rez[i] << " ";
    return 0;
}
