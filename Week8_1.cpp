//จงหาเศษจากการหารด้วย 7 (Big number นะจ๊ะ)
//Normally division method
#include<iostream>
using namespace std;
int findremainder(string num)
{
    int nom;
    int rem=0;
    for (int i=0; i<num.length(); i++)
    {
      nom = rem*10 + (num[i] - '0');
      rem = nom % 7;
   }
    return rem;
}
main()
{
    string num;
    cin >> num;
    cout << findremainder(num);
}