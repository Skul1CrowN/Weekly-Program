//จงหาเศษจากการหารด้วย 7 (Big number นะจ๊ะ)
/*Series method
How it work?
1  % 7 = 1
10 % 7 = 3
100 % 7 = 2
1000 % 7 = 6 = (-1) % 7
10000 % 7 = 4 = (-3) % 7
100000 % 7 = 3 = (-2) % 7
--End Rotation--
1000000 % 7 = 1
10000000 % 7 = 3

Ex.
(12345 % 7) = (5*1 + 4*3 + 3*2 + 2*(-1) + 1*(-3)) % 7
            = (5 + 12 + 6 - 2 - 3)%7
            = (18) % 7
            = 4
hence 4 will be the remainder when we divide the number 12345 by 7. 
*/
#include<iostream>
using namespace std;
int findremainder(string num)
{
    int num_set[] = {1,3,2,-1,-3,-2};
    int index=0;
    int result=0;
    for(int i=num.length()-1;i>=0;i--)
    {
        int nom=num[i]-'0';
        result+=nom*num_set[index];
        index=(index+1)%6;
        result %= 7;
    }
    if(result<0)
        result = (result+7)%7;

    return result;
}
main()
{
    string num;
    cin >> num;
    cout << findremainder(num);
}