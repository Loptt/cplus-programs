#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define N 10

struct Node 
{
    string name;
    int age;

    Node(){}

    void setAtt(string n, int i)
    {
        name = n;
        age = i;
    }

    bool operator>(const Node &n)
    {
        return age > n.age;
    }
};


void readMap(unordered_map<string, vector<Node>> &graph, int e)
{
    string papaName, sonName;
    int weight;

    Node n;

    vector<Node> vecNode(0);

    unordered_map<string, vector<Node>>::iterator it; 

    for (int i = 0; i < e; ++i)
    {
        cin >> papaName >> sonName >> weight;

        it = graph.find(papaName);

        if (it == graph.end())
        {
            vecNode.clear();
            n.setAtt(sonName, weight);
            vecNode.push_back(n);

            graph.insert(make_pair(papaName, vecNode));
        }
        else
        {
            n.setAtt(sonName, weight);
            it->second.push_back(n);
        }
    }
}

void printGuests(unordered_map<string, vector<Node>> &graph)
{
    unordered_map<string, vector<Node>>::iterator it;
    set<Node>::iterator setit;
    string name;

    set<Node> finds;

    stack<Node> s;

    Node n;
    n.setAtt("Berny", 100);

    finds.insert(n);

    Node papa;

    s.push(n);

    while (!s.empty())
    {   
        it = graph.find(s.top().name);

        for(int i = 0; i < it->second.size(); ++i)
        {
            setit = finds.find(*it);
            s.push(it->second[i]);
        }
    }
}

int main()
{
    unordered_map<string, vector<Node>> graph;

    int e;
    cin >> e;
    
    readMap(graph, e);



    return 0;
}