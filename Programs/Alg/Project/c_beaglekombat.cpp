#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> damage;
    int d;

    for (int i = 0; i < n; i++)
    {
        cin >> d;
        damage.push_back(d);
    }

    string seq;

    cin >> seq;

    priority_queue<int> q;

    int sum = 0;

    for (int i = 0; i < seq.length(); i++)
    {
        if (i != 0 && seq[i] != seq[i-1])
        {
            for (int i = 0; i < k && !q.empty(); i++)
            {
                sum += q.top();
                q.pop();
            }

            while (!q.empty())
            {
                q.pop();
            }
        }

        q.push(damage[i]);
    }

    for (int i = 0; i < k && !q.empty(); i++)
    {
        sum += q.top();
        q.pop();
    }

    cout << sum << endl;

    return 0;
}