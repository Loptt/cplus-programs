#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct circle
{
    double x, y, r;

    circle(double x, double y, double r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
    }
};

bool point_contain(circle a, circle b)
{
    if (a.x + a.r > b.x && a.x - a.r < b.x && a.y + a.r > b.y && a.y - a.r < b.y)
        ;
}

bool check(circle a, circle b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2)) <= (a.r + b.r));
}

int main()
{
    int n;
    double x, y, r;

    cin >> n;

    vector<circle> circ;

    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y >> r;
        circle c(x, y, r);

        circ.push_back(c);
    }

    int suma = 0;

    for (int i = 0; i < circ.size(); ++i)
    {
        for (int j = 0; j < circ.size(); ++j)
        {
            if (check(circ[i], circ[j]))
            {
                suma += 2;
            }
        }
    }

    if (suma > 2 * n)
        cout << "greater" << endl;

    else
        cout << suma << endl;

    return 0;
}