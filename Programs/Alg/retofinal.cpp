#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define MAX 1200

int g[MAX][MAX];
vector<int> jefes;

int k;

class Resp
{   
    public:
    int id, valor;
    Resp()
    {
        id = 0;
        valor = 0;
    }
};

class Compare
{
    public:
    bool operator() (Resp a, Resp b) {
        if (a.valor == b. valor)
            return a.id > b.id;

        return a.valor < b.valor;
    }
};

priority_queue<Resp, vector<Resp>, Compare> res;

int findValue(int x) {
    int suma = 0;
    for (int i = 0; i < k; i++) {
        if (g[x][i] > 0) {
            suma += g[x][i] + findValue(i);
        }
    }

    return suma;
}

void encontrarRespuesta() {
    for (int i = 0; i < jefes.size(); i++) {
        Resp resp;
        resp.id = jefes[i];
        resp.valor = findValue(jefes[i]);
        res.push(resp);
    }

    while(!res.empty()) {
        cout << res.top().id + 1 << " " <<res.top().valor << endl;
        res.pop();
    }
}

int main()
{
    int n, m;
    cin >> k >> n >> m;

    int jefe;

    //Inicializar grafo en -infinito
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            g[i][j] = INT_MIN;
        }
    }

    //Leer jefes
    for (int i = 0; i < n; i++) {
        cin >> jefe;
        jefes.push_back(jefe-1);
    }

    int emp, valor;

    //Leer conexion jefe empleado con valor
    for (int i = 0; i < m; i++) {
        cin >> jefe >> emp >> valor;
        g[jefe-1][emp-1] = valor;
    }

    encontrarRespuesta();

    return 0;
}