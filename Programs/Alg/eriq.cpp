#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

vector<vector<pair<int, int > > > G(20);

vector<int> Dist;

void Dijkstra(int N)
{
    // AquÃ­ va tu codigo.
    priority_queue<pair<int, int>, vector<pair<int, int > >, greater<pair<int, int > > > Q;

    Dist.assign(N, INF);
    Dist[0] = 0;
    pair<int, int> p(0, 0);
    Q.push(p);
    while (!Q.empty())
    {
        int u = Q.top().first;
        Q.pop();
        for (int i = 0; i < G[u].size(); i++)
        {
            pair<int , int> p = G[u][i];
            int v = p.first;
            int w = p.second;
            if (Dist[v] > Dist[u] + w)
            {
                Dist[v] = Dist[u] + w;
                pair<int, int> nvo(v, Dist[v]);
                Q.push(nvo);
            }
        }
    }
}

int main()
{
    int k;
    cin >>k;
    for (int t = 1; t <= k; ++t)
    {
    int N, M, u, v,w;
    char l, m;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        cin >> l >> m >> w;

        u = l - 'A' + 1;
        v = m - 'A' + 1; 

        pair<int, int> n1(v - 1, w);
        pair<int, int> n2(u - 1, w);
        G[u - 1].push_back(n1);
        G[v - 1].push_back(n2);
    }
    Dijkstra(N);
    int maxVal = Dist[1];
    int maxLet = 1;
    for (int i = 1; i < N; i++)
    {   
        if(Dist[i] > maxVal && Dist[i] != INF)
        {
            maxVal = Dist[i];
            maxLet = i;
        }
    }
    cout<< "Case "<< t <<": " << (char) (maxLet + 'A')<<endl;

    }
    return 0;
}