#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &s, const vector<int> &b)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
}

int main()
{
    int n, q;

    cin >> n >> q;
    int sold;
    vector<long> soldiers;

    for (int i = 0; i < n; i++)
    {
        cin >> sold;
        soldiers.push_back(sold);
    }

    long ball;
    vector<int> balls;

    for (int i = 0; i < q; i++)
    {
        cin >> ball;
        balls.push_back(ball);
    }

    vector<long> truesoldiers = soldiers;
    long remaining = 0;
    long soldamount = soldiers.size();

    for (int i = 0; i < balls.size(); i++)
    {
        for (int j = 0; j < soldiers.size(); j++)
        {
            remaining = balls[i] - soldiers[j];
            //print(soldiers, balls);

            if (remaining <= 0 && soldiers[j] != 0)
            {
                soldiers[j] = remaining * -1;
                
                if (soldiers[j] == 0)
                {
                    soldamount--;
                    //cout << "REDUCE" << endl;
                    if (j == soldiers.size() - 1)
                    {
                        soldiers = truesoldiers;
                        soldamount = truesoldiers.size();
                    }
                }

                break;
            }
            else if (soldiers[j] != 0)
            {
                balls[i] = remaining;
                soldiers[j] = 0;
                soldamount--;
                //cout << "REDUCE" << endl;

                if (j == soldiers.size() - 1)
                {
                    soldiers = truesoldiers;
                    soldamount = truesoldiers.size();
                }
            }
        }

        cout << soldamount << endl;
    }

    return 0;
}