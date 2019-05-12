#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Bracket
{
    char cBra;
    int position;

    Bracket(char c, int pos)
    {
        cBra = c;
        position = pos;
    }
};

bool checkForOpeningBracket(char character)
{
    switch (character)
    {
    case '(':
        return true;

    case '[':
        return true;

    case '{':
        return true;
    }

    return false;
}

bool checkForClosingBracket(char character)
{
    switch (character)
    {
    case ')':
        return true;

    case ']':
        return true;

    case '}':
        return true;
    }

    return false;
}

bool validateBracket(char lastBracket, char closingBracket)
{
    switch (lastBracket)
    {
    case '(':
        if (closingBracket == ')')
            return true;
        return false;

    case '[':
        if (closingBracket == ']')
            return true;
        return false;

    case '{':
        if (closingBracket == '}')
            return true;
        return false;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    stack<Bracket> brackets;
    string input;

    getline(cin, input);

    for (int i = 0; i < input.length(); ++i)
    {
        if (checkForOpeningBracket(input[i]))
        {
            Bracket temp(input[i], i + 1);
            brackets.push(temp);
        }
        else
        {
            if (checkForClosingBracket(input[i]))
            {
                if (brackets.empty())
                {
                    cout << i + 1 << endl;
                    return 0;
                }
                if (!validateBracket(brackets.top().cBra, input[i]))
                {
                    cout << i + 1 << endl;
                    return 0;
                }

                brackets.pop();
            }
        }
    }

    if (!brackets.empty())
    {
        cout << brackets.top().position << endl;
        return 0;
    }

    cout << "Success" << endl;

    return 0;
}
