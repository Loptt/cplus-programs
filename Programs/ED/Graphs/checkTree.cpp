#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void leeListAdj(vector<vector<int> > &listAdj, int e){
	int a, b;
	for (int i=0; i<e; i++){
		cin >> a >> b;
		listAdj[a-1].push_back(b-1);
	}
}

void printListAdj(vector<vector<int> > &listAdj, int e){
	for (int i=0; i<listAdj.size(); i++){
		cout << i << " ";
		for (int j=0; j< listAdj[i].size(); j++){
			cout << " - " << listAdj[i][j];
		}
		cout << endl;
	}
}

bool isTree(vector<vector<int> > &listAdj, int e){

    if (e > listAdj.size()-1)
        return false;

    stack<int> pila;
    pila.push(0);
    int data;
    vector<bool> status(listAdj.size(), false);

    while (!pila.empty())
    {
        data = pila.top();
        pila.pop();
        if (!status[data])
        {
            status[data] = true;
            for (int i = listAdj[data].size()-1; i >= 0; i--)
            {
                if (!status[listAdj[data][i]])
                {
                    pila.push(listAdj[data][i]);
                }
                else
                    return false;
            }
        }
    }

    return true;
}

int main(){

	int v, e;
	cin >> v >> e;
	vector<vector<int> > listAdj(v);
	leeListAdj(listAdj, e);
//	printListAdj(listAdj, v);
	cout << (isTree(listAdj, e)? "YES" : "NO") << endl;
	return 0;
}