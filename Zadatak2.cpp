#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
#define NAJVECA_VELICINA_SITA 10000010
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int n;
vector<ii> faktori;
vi prosti; //lista svih generisanih prostih brojeva
bitset<NAJVECA_VELICINA_SITA> bs;
ll velicina_sita;
void EratostenovoSito(ll gornja_granica)
{
    //dodajemo 1 da bi ukljucili i gornju granicu
    velicina_sita = gornja_granica + 1;
    bs.set();  //sve elemente postavlja na 1
    bs[0] = bs[1] = 0;
    for(ll i = 2; i < velicina_sita; i++)
        if(bs[i])
        {
            //precrtavamo sve brojeve deljive sa i pocevsi od i * i
            for(ll j = i * i; j < velicina_sita; j += i)
                bs[j] = 0;
            prosti.push_back((int)i);
        }
}

void prostiFaktori(int x)
{
    int PF_idx = 0;
    int PF = prosti[PF_idx];
    while(PF * PF <= x)
    {
        int st = 0;
        while(x % PF == 0)
        {
            x /= PF;
            st++;
        }
        if(st > 0)
            faktori.push_back(make_pair(PF, st));
        PF = prosti[++PF_idx];
    }
    if(x != 1)
        faktori.push_back(make_pair(x, 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(n == 1) //poseban slucaj
    {
        cout << "1 0";
        return 0;
    }
    int rez1 = 1, naj = 0, rez2;
    bool b = true;
    EratostenovoSito(n);
    prostiFaktori(n);
    int pocfaktor;
    for(int i = 0; i < (int)faktori.size(); i++)
    {
        if(i == 0)
            pocfaktor = faktori[i].second;
        rez1 *= faktori[i].first;
        naj = max(naj, faktori[i].second);
        if(pocfaktor != faktori[i].second)
            b = false;

    }
    if(!(log2(naj) == round(log2(naj))))
        b = false;
    //ako b ostane true ne treba izvrsiti mnozenje
    //na pocetku, vec se do kraja samo korenuje
    rez2 = 1 + ceil(log2(naj));
    if(b)
       rez2--;
    cout << rez1 << " " << rez2;
    return 0;
}
