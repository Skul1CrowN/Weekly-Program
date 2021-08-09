//Use Dynamic Programming
#include<iostream>
using namespace std;
long long factorial(long long n)
{
    int arr[10000];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++)
        arr[i]=i*arr[i-1];
    return arr[n];
}
main()
{
    long long n;
    cin >> n;
    cout << factorial(n);
}