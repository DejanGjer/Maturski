#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
#define NAJVECA_VELICINA_SITA 10000010
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
vll prosti; //lista svih generisanih prostih brojeva
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

ll brojPF(ll N)   //koristimo ll za tip long long kao i pre
{
    ll PF_idx = 0 , PF = prosti[PF_idx], rez = 0;
    while(N != 1 && (PF * PF <= N))
    {
        while(N % PF == 0)
        {
            N /= PF;
            rez++;
        }
        PF = prosti[++PF_idx];
    }
    if(N != 1)
        rez++;
    return rez;
}

ll brojDelilaca(ll N)
{
    ll PF_idx = 0 , PF = prosti[PF_idx], rez = 1;
    while(N != 1 && (PF * PF <= N))
    {
        int stepen = 0;
        while(N % PF == 0)
        {
            N /= PF;  stepen++;
        }
        rez *= (stepen + 1);
        PF = prosti[++PF_idx];
    }
    if(N != 1)  rez *= 2;
    return rez;
}

ll zbirDelilaca(ll N)
{
    ll PF_idx = 0 , PF = prosti[PF_idx], rez = 1;
    while(N != 1 && (PF * PF <= N))
    {
        int stepen = 0;
        while(N % PF == 0)
        {
            N /= PF;  stepen++;
        }
        rez *= ((ll)pow((double)PF, stepen + 1.0) - 1) / (PF - 1);
        PF = prosti[++PF_idx];
    }
    if(N != 1)  rez *= (N + 1);
    return rez;
}

ll EulerPhi(ll N)
{
    ll PF_idx = 0 , PF = prosti[PF_idx], rez = N;
    while(N != 1 && (PF * PF <= N))
    {
        if(N % PF == 0)
            rez -= rez / PF;
        while(N % PF == 0)
            N /= PF;
        PF = prosti[++PF_idx];
    }
    if(N != 1)
        rez -= rez / N;
    return rez;
}

int main()
{
    EratostenovoSito(10000000);
    ll broj = 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 7 * 13 * 23 * 43;
    cout << brojPF(broj) << " " << brojDelilaca(broj) << " " << zbirDelilaca(broj) << " " << EulerPhi(broj) << "\n";
    ll n = 12;
    cout << brojPF(n) << " " << brojDelilaca(n) << " " << zbirDelilaca(n) << " " << EulerPhi(n) << "\n";
    return 0;
}
