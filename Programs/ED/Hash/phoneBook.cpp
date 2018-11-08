#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void add(unordered_map<int, string> &book)
{
    int number;
    string name;

    cin >> number >> name;

    unordered_map<int, string>::iterator it;

    it = book.find(number);

    if (it == book.end())
        book.insert(make_pair(number, name));
    else
        it->second = name;
}

void find(unordered_map<int, string> &book)
{
    int number;
    cin >> number;

    unordered_map<int, string>::iterator it;

    it = book.find(number);

    if (it != book.end())
        cout << it->second << endl;
    else
        cout << "not found" << endl;
}

void del(unordered_map<int, string> &book)
{
    int number;
    cin >> number;

    book.erase(number);
}

void processQuery(unordered_map<int, string> &book, string command)
{
    switch (command[0])
    {
    case 'a':
        add(book);
        break;

    case 'f':
        find(book);
        break;

    case 'd':
        del(book);
        break;
    }
}

int main()
{
    unordered_map<int, string> book;

    string command;
    int queries;

    cin >> queries;

    for (int i = 0; i < queries; ++i)
    {
        cin >> command;
        processQuery(book, command);
    }

    return 0;
}