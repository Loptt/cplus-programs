/**
@progName Convertidor de Documentacion
@desc Programa que documenta un archivo cpp a HTML
@author Carlos Estrada
@date 1 de febrero del 2018
*/

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

/**
@funcName writeInitialHtml
@desc Funcion que escribe los atributos iniciales del HTML asi como el CSS necesario
@param Una variable de output, y un string con el nombre del archivo 
@return Nada
*/
void writeInitialHtml(ofstream &outputFile, string sFileName)
{
    outputFile << "<!DOCTYPE html>" << endl << "<html>" << endl;
    outputFile << "<head>" << endl;
    outputFile << "<title>Documentacion para " << sFileName << "</title>" << endl;
    outputFile << "<link href=\"https://fonts.googleapis.com/css?family=Lato\" rel=\"stylesheet\">" << endl;

    outputFile << "<style>" << endl;
    outputFile << "body { background-color: #FFFFFF; }" << endl;
    outputFile << "div#content { width: 60%; margin: 0 auto; padding: 40px; background-color: #E6F2FF; }" << endl;
    outputFile << "div#program { padding: 20px; border-radius: 10px; background-color: #FFFFFF;}" << endl;
    outputFile << "div.function { padding: 20px; margin: 20px; border-radius: 10px; background-color: #FFFFFF;}" << endl;
    outputFile << "h1 { font-family: 'Lato', sans-serif; color: #3b80ef; text-align: center;}" << endl;
    outputFile << "h3 { font-family: 'Lato', sans-serif; color: #666666;}" << endl;
    outputFile << "p { font-family: 'Lato', sans-serif; color: #666666;}" << endl;
    outputFile << "strong { color: #3b80ef;}" << endl;
    outputFile << "</style>" << endl;

    outputFile << "</head>" << endl;
    outputFile << "<body>" << endl;
    outputFile << "<div id=\"content\">" << endl;


}

/**
@funcName writeFinalHtml
@desc Funcion que escribe los atributos finales del HTML
@param Una variable de output
@return Nada
*/
void writeFinalHtml(ofstream &outputFile)
{
    outputFile << "</div>" << endl;
    outputFile << "</body>" << endl;
    outputFile << "</html>" << endl;
}

/**
@funcName analyzeComment
@desc Funcion escribe los necesarios tags dentro de un bloque de comentario
@param Una variable de output, y una variable de input como referencia
@return Nada
*/
void analyzeComment(ifstream &inputFile, ofstream &outputFile)
{
    string sLineOfCode;
    string sType;

    string sArrTypes[7] =
    {
        "@progName",
        "@funcName",
        "@author",
        "@date",
        "@desc",
        "@param",
        "@return"
    };

    int iTypeIndex = 7;
    int iTypePosition = 0;


    int iAtPosition;
    int iLoopCount = 0;
    size_t position = 0;

    getline(inputFile, sLineOfCode);
    position = sLineOfCode.find("*/");


    while (position == string::npos)
    {   

        for (int iCounter = 0; iCounter < 7; ++iCounter)
        {
            iTypePosition = sLineOfCode.find(sArrTypes[iCounter]);

            if (iTypePosition >= 0 && iTypePosition <= 1000)
            {
                iTypeIndex = iCounter;              
            }
        }

        switch (iTypeIndex)
        {
            case 0: //progName
                outputFile << "<div id=\"program\"><h1><strong>Programa: </strong>" << sLineOfCode.substr(iTypePosition+10);
                outputFile << "</h1></div>" << endl;
                break;

            case 1: //funcName
                outputFile << "<div class=\"function\"><h3><strong>Funcion: </strong>" << sLineOfCode.substr(iTypePosition+10);
                outputFile << "</h3>" << endl;
                break;

            case 2: //author
                outputFile << "<div><p><strong>Autor: </strong>" << sLineOfCode.substr(iTypePosition+8);
                outputFile << "</p>" << endl;
                break;

            case 3: //date
                outputFile << "<p><strong>Fecha: </strong>" << sLineOfCode.substr(iTypePosition+6);
                outputFile << "</p>" << endl;
                break;
                
            case 4: //desc
                outputFile << "<p><strong>Descripcion: </strong>" << sLineOfCode.substr(iTypePosition+6);
                outputFile << "</p>" << endl;
                break;
                
            case 5: //param
                outputFile << "<p><strong>Parametros: </strong>" << sLineOfCode.substr(iTypePosition+7);
                outputFile << "</p>" << endl;
                break;

            case 6: //return
                outputFile << "<p><strong>Return: </strong>" << sLineOfCode.substr(iTypePosition+8);
                outputFile << "</p>" << endl;
                break;

            default:
                cout << "Error: could not find tag in documentation" << endl;
                cout << sLineOfCode << endl;
                break;  
        }

        getline(inputFile, sLineOfCode);
        position = sLineOfCode.find("*/");

        iTypeIndex = 7;
    }
    outputFile << "</div>" << endl;
}

/**
@funcName main
@desc Funcion que llama el resto de las funciones
@param Nada
@return Nada
*/
int main()
{
    ifstream inputFile;
    string sFileName;

    cout << "Introduce el nombre del archivo cpp a documentar: ";
    getline(cin, sFileName);
    cout << endl;

    inputFile.open(sFileName);

    ofstream outputFile;
    outputFile.open("documentacion.html");

    string sLineOfCode;

    writeInitialHtml(outputFile, sFileName);

    while (getline(inputFile, sLineOfCode))
    {  
        if (sLineOfCode.find("/**") == 0)
        {
            analyzeComment(inputFile, outputFile);
        }
    }

    writeFinalHtml(outputFile);

    inputFile.close();
    outputFile.close();

    return 0;
}