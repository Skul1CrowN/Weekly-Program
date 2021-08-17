/*
จงเขียนโปรแกรมรับชุดตัวเลขจำนวนเต็มบวก N ตัว
จากนั้นพิมพ์เลขที่มีต่าซ้ำมากที่สุดมาและพิมพ์ด้วยว่ามีเลขดังกล่าวเป็นจำนวนเท่าใดในข้อมูลเข้า
ในกรณีที่ซ้ำกันมากที่สุดมากกว่าหนึ่งค่าให้เลือกเอาตัวเลขที่มีค่ามากที่สุด
Using only array
*/
#include<iostream>
using namespace std;
main()
{
    int n;
    cin >> n;
    int *num = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> num[i];
    }
    int max_dup=0;
    int current_dup;
    int result=0;
    for(int i=0;i<n;i++)
    {
        current_dup=0;
        for(int j=0;j<n;j++)
        {
            if(num[i]==num[j])
            {
                current_dup++;
            }
        }
        if(current_dup>=max_dup && num[i]> result)
        {
            max_dup=current_dup;
            result=num[i];
        }
    }
    cout << result << endl;
    cout << max_dup;
}