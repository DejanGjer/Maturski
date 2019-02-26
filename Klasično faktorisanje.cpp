#include <iostream>
#include <vector>
#include <bitset>
#define NAJVECA_VELICINA_SITA 10000010
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
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

vll prostiFaktori(ll N)
{
    // moze se ustedeti malo memorije i vremena ako se koristi vector<int> faktori
    //ali moramo biti sigurni da nece preci njegove granice
    vll faktori;
    // proste faktore dobijamo iz vec generisane liste prosti(iz Eratostenovog sita)
    ll PF_idx = 0, PF = prosti[PF_idx];
    while (N != 1 && (PF * PF <= N))
    {
        while (N % PF == 0)
        {
            N /= PF;
            faktori.push_back(PF);
        }
        PF = prosti[++PF_idx];
    }
    if (N != 1)
        faktori.push_back(N);    // N koji je ostao nakon petlje ako nije 1 je prost
    return faktori;
}

int main()
{
    EratostenovoSito(10000000);
    vll res = prostiFaktori(2147483647);   // slowest, 2147483647 is a prime
    for (vll::iterator i = res.begin(); i != res.end(); i++) cout << *i << "\n";

    res = prostiFaktori(136117223861LL);   // slow, 2 large pfactors 104729*1299709
    for (vll::iterator i = res.begin(); i != res.end(); i++) cout << *i << "\n";

    res = prostiFaktori(430186210740LL);   // faster, 2^10*3^4*5*7^4*11*13
    for (vll::iterator i = res.begin(); i != res.end(); i++) cout << *i << "\n";

    //res = prostiFaktori((ll)(1010189899LL * 1010189899LL)); // "error"
    //for (vll::iterator i = res.begin(); i != res.end(); i++) cout << *i << "\n";
    return 0;
}
