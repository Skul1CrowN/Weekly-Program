/*
จงเขียนโปรแกรมรับค่าจากผู้ใช้มา N ค่า โดยที่ N≤5,000 และค่าแต่ละตัวที่ผู้ใช้ใส่เข้ามาจะเป็นเลขจํานวน
เต็มบวก มีค่าตังงแต่ 1 ถึง 10,000 (รวมเลข 1 และ 10,000 ด้วย) เมื่อผู้ใช้ใส่ค่าเข้ามาครบ N ค่าแล้ว โปรแกรมจะพิมพ์
เลขที่ผู้ใช้ใส่เข้ามาเรียงลําดับจากน้อยไปมาก ทั้งนี้หากผู้ใช้ใส่เลขซ้ำ โปรแกรมจะพิมพ์เลขดังกล่าวออกมาเพียงครั้งเดียว
เท่านั้น เช่น ถ้าผู้ใช้ใส่เลข 5 เข้ามาสามครั้ง โปรแกรมจะพิมพ์เลข 5 ออกมาเพียงหนึ่งครั้ง
Using Bubble Sort
Check duplicate before insert array
*/
#include<iostream>
using namespace std;
void bubble_sort(int *arr,int n)
{
    int temp;
    int i, j; 
    for (i = 0; i < n-1; i++)     
    {
        for (j = 0; j < n-i-1; j++) 
        if (arr[j] > arr[j+1]) 
        {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}
main()
{
    int n;
    cin >> n;
    int arr[10001];
    int maxIndex=0;
    for(int i=0;i<n;i++)
    {
        int input;
        bool isExist=false;
        cin >> input;
        for(int j=0;j<maxIndex;j++)
        {
            if(arr[j]==input)
            {
                isExist=true;
            }
        }
        if(isExist==false)
        {
            arr[maxIndex++]=input;
        }
    }
    bubble_sort(arr,maxIndex);
    for(int i=0;i<maxIndex;i++)
    {
        cout << arr[i] << " ";
    }
}