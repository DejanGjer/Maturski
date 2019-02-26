#include <iostream>
#include <deque>
#define KMAX 100008
#define INT_MAX 2147483647
using namespace std;
int k, dist[KMAX];
deque<int> graf;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    for(int i = 0; i < k; i++)
        dist[i] = INT_MAX;
    dist[1] = 1;
    graf.push_back(1);
    while(!graf.empty())
    {
        int ost = graf.front();
        graf.pop_front();
        int sledeci1 = (10 * ost) % k;
        int sledeci2 = (ost + 1) % k;
        if(dist[sledeci1] > dist[ost])
        {
            dist[sledeci1] = dist[ost];
            graf.push_front(sledeci1);
        }
        if(dist[sledeci2] > dist[ost] + 1)
        {
            dist[sledeci2] = dist[ost] + 1;
            graf.push_back(sledeci2);
        }
    }
    cout << dist[0];
    return 0;
}
