/*
จงเขียนโปรแกรมรับค่าจากผู้ใช้มา N ค่า โดยที่ N≤5,000 และค่าแต่ละตัวที่ผู้ใช้ใส่เข้ามาจะเป็นเลขจํานวน
เต็มบวก มีค่าตังงแต่ 1 ถึง 10,000 (รวมเลข 1 และ 10,000 ด้วย) เมื่อผู้ใช้ใส่ค่าเข้ามาครบ N ค่าแล้ว โปรแกรมจะพิมพ์
เลขที่ผู้ใช้ใส่เข้ามาเรียงลําดับจากน้อยไปมาก ทั้งนี้หากผู้ใช้ใส่เลขซ้ำ โปรแกรมจะพิมพ์เลขดังกล่าวออกมาเพียงครั้งเดียว
เท่านั้น เช่น ถ้าผู้ใช้ใส่เลข 5 เข้ามาสามครั้ง โปรแกรมจะพิมพ์เลข 5 ออกมาเพียงหนึ่งครั้ง
Using Quick sort
Remove duplicate after sorted
*/
#include<iostream>
using namespace std;
int partition(int *arr,int low,int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int temp;
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quickSort(int *arr,int low,int high)
{
    if(low < high)
    {
        int pi = partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int removeDuplicate(int *arr,int n)
{
    if(n==0 || n==1)
        return n;
    
    int *temp = new int[n];

    int j=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i] != arr[i+1])
            temp[j++] = arr[i];
    }
    temp[j++] = arr[n-1];

    for(int i=0; i<j;i++)
        arr[i] = temp[i];
    
    delete []temp;
    return j;
}
main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    n = removeDuplicate(arr,n);
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    delete []arr;
}