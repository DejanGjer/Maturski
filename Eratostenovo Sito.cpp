#include <iostream>
#include <bitset>
#include <vector>
#define NAJVECA_VELICINA_SITA 10000010
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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

bool prost(ll N)
{
    //O(1) za male proste brojeve
    if(N <= velicina_sita)
        return bs[N];
    for(int i = 0; i < (int)prosti.size(); i++)
        if(N % (ll)prosti[i] == 0)
            return false;
    return true;
}

int main()
{
    EratostenovoSito(10000000); // can go up to 10^7 (need few seconds)
    printf("%d\n", prost(2147483647)); // 10-digits prime
    printf("%d\n", prost(136117223861LL));
    return 0;
}
