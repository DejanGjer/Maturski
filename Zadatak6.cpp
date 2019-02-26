#include <iostream>
using namespace std;
#define NMAX 1000010
typedef long long ll;
int prost[NMAX], ephi[NMAX] = {0, 1}, t;
ll rez[NMAX] = {0, 1};
void preprocesiranje()
{
    for (int i = 2; i < NMAX; ++i)
    {
        if (prost[i] == 0)
        {
            ephi[i] = i - 1;
            for (int j = i; j < NMAX; j += i)
            {
                prost[j] = i;  //i je faktor od j
                rez[j] += i * (ll)ephi[i]; //dodajemo sabirak
            }
        }
        else
        {
            if ((i / prost[i]) % prost[i] == 0)
                ephi[i] = ephi[i / prost[i]] * prost[i];
        //vrednost ojlerove funkcije za i/prost[i] vec imamo
            else
                ephi[i] = ephi[i / prost[i]] * (prost[i] - 1);
            for (int j = i; j < NMAX; j += i)
                rez[j] += i * (ll)ephi[i];
        }
        rez[i] = ((rez[i] + 2) * i) / 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < NMAX; i++)
        prost[i] = 0;
    preprocesiranje();
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << rez[n] << "\n";
    }
    return 0;
}
