//Using arithmetic operators
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

main()
{
    ifstream aFile("a.txt");
    string text;
    if(aFile.is_open())
    {
        getline(aFile,text);
    }
    string text1,text2;
    int checkpoint=0;
    for(int i=0;i<text.size();i++)
    {
        if(text[i]!=' ')
            text1.push_back(text[i]);
        else
        {
            checkpoint=i+1;
            break;
        }
    }
    for(int i=checkpoint;i<text.size();i++)
    {
        text2.push_back(text[i]);
    }
    int num1 = stoi(text1);
    int num2 = stoi(text2);
    ofstream bFile("b.txt");
    if(bFile.is_open())
    {
        bFile << num1+num2;
    }
}