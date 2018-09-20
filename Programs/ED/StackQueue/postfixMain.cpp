#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
    string d, data;

    getline(cin, data);
    while (data != "#")
    {
        stringstream ss;
        ss << data;
        while (ss >> d)
        {
        }
        getline(cin, data);
    }

    return 0;
}
