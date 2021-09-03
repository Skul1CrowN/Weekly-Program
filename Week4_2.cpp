//Using half adder in bitwise
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int add(int x,int y)
{
	while (y != 0)
	{
		int carry = x&y;
		x = x^y;
		y = carry << 1;
	}
	return x;
}

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
        bFile << add(num1,num2);
    }
}