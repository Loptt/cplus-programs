/*
Code created by Carlos Estrada
Classwork Switch
September 18, 2017
*/

#include <iostream>
using namespace std;

/*
readCharacter
Function to get the character from the user
Parameters: none
Return: the character inputted
*/
char readCharacter()
{
  char cChar;
  cin >> cChar;
  return cChar;
}

/*
calculateKey
Function to get the char if vowel, consonant, or something else
Parameters: The character inputted by the user
Return: The resulting char of the switch statement
*/
int calculateKey(char cChar)
{
  char cKey;
  
  switch(cChar)
  {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      cKey = 'a';
      break;
    
    case 'b':
    case 'c':
    case 'd':
    case 'f':
    case 'g':
    case 'h':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'B':
    case 'C':
    case 'D':
    case 'F':
    case 'G':
    case 'H':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
      cKey = 'b';
      break;
      
    default:
      cKey = '!';
      break;
  }
  return cKey;
}

/*
showResult
Displays the char whether it's a vowel consonant or else
Parameters: the Key calculated
Return: nothing
*/
void showResult(char cKey)
{
  cout << cKey << endl;
}

/*
main
Function to call all other functions
Parameters: none
Return: 0 
*/
int main()
{
  //Declare the variables
  int cCharacter, cKey;
  
  //Read the char to be tested
  cCharacter = readCharacter();
  
  //Call a function to assign a key to the char
  cKey = calculateKey(cCharacter);
  
  //Display the result to the console
  showResult(cKey);
  
  return 0;
  
}