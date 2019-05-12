#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

using namespace std;
 
#define INF INT_MAX
 
vector<vector<pair<int,int>>> G(250);

vector<int> Dist;


void Dijkstra(int N) {
    priority_queue<pair<int,int>, vector<pair<int,int>>,
    greater<pair<int,int>>> Q;

    Dist.assign(N, INF);
    Dist[0] = 0;
    pair<int, int> p(0,0);
    Q.push(p);

    while (!Q.empty()) {
        int u = Q.top().first;
        Q.pop();

        for (int i = 0; i < G[u].size(); i++) {
            pair<int,int> p = G[u][i];
            int v = p.first;
            int w = p.second;

            if (Dist[v] > Dist[u] + w) {
                Dist[v] = Dist[u] + w;
                pair<int,int> nvo(v, Dist[v]);
                Q.push(nvo);
            }
        }
    }
}

int main() {
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++) {
       
        int N, M, w, v, u;

        char cv, cu;   
        cin >> N >> M;
        
        for(int i=0;i<M;++i){
            cin >> cu >> cv >> w;
            u = (int) cu - 64;
            v = (int) cv - 64;
            pair<int,int> n1(v -1,w);
            pair<int,int> n2(u -1,w);
            G[u-1].push_back(n1);
            G[v-1].push_back(n2);
        }
        Dijkstra(N);

        int max = INF * -1;
        int maxi = 0;

        for (int i = 1; i < N; i++) {
            if (Dist[i] > max && Dist[i] != INF) {
                max = Dist[i];
                maxi = i;
            }
        }

        cout << "Case " << i+1 << ": " << (char) (maxi + 65) << endl;
        for (int i = 0; i < 2000; i++) {
            G[i].clear();
        }
    }
    
    return 0;
}

/*
5 8
1 2 2
1 3 12
1 4 10
2 3 9
2 5 5
3 4 6
3 5 3
4 5 7
*/