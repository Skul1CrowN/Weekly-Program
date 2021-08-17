/*
จงเขียนโปรแกรมรับชุดตัวเลขจำนวนเต็มบวก N ตัว
จากนั้นพิมพ์เลขที่มีต่าซ้ำมากที่สุดมาและพิมพ์ด้วยว่ามีเลขดังกล่าวเป็นจำนวนเท่าใดในข้อมูลเข้า
ในกรณีที่ซ้ำกันมากที่สุดมากกว่าหนึ่งค่าให้เลือกเอาตัวเลขที่มีค่ามากที่สุด
Using std::map
*/
#include<iostream>
#include<map>
using namespace std;
main()
{
    int n;
    cin >> n;
    map <int,int> m;
    int in;
    for(int i=0;i<n;i++)
    {
        cin >> in;
        if(m.find(in)==m.end())
        {
            m.insert({in,1});
        }
        else
        {
            m[in]++;
        }
    }
    int max_dup=0;
    int max_num=0;
    for(map<int,int>::iterator itr=m.begin();itr!=m.end();itr++)
    {
        if(itr->second>=max_dup)
        {
            max_dup = itr->second;
            max_num = itr->first;
        }
    }
    cout << max_num << endl;
    cout << max_dup;
}