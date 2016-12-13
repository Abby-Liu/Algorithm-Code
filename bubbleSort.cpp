// 實作bubble sort並計算出排序完成至少需要swap幾次
// Input
// 第一行請輸入測資比數N
// 每一筆的測資都會有兩行，第一行為總長度L (0 ≤ L ≤ 50)，
// 第二行為從1到L的排列組合
// 現在要將此序列由小到大重新排列。
// Output
// 每組測資請輸出”Optimal swapping takes S swaps.” S為swap次數
// Sample Input
// 3
// 3
// 1 3 2
// 4
// 4 3 2 1
// 2
// 2 1
// Sample Output
// Optimal swapping takes 1 swaps.
// Optimal swapping takes 6 swaps.
// Optimal swapping takes 1 swaps.
#include <iostream>
using namespace std;

void bubble(int data[], int s)
{
    int count=0;
    bool flag=true;
    for(int i = 0; i < s - 1 && flag; i++)
    {
        flag = false;
        for(int j = 0; j < s - i - 1; j++)
        {
            if(data[j+1] < data[j])
            {
                swap(data[j+1], data[j]);
                flag = true;
                count++;
            }
        }
    }

    cout<<"Optimal swapping takes " << count <<" swaps."<<endl;
}


int main(int argc, const char * argv[]) {
    int input=0;
    cin>>input;
    while(input>0)
    {
        int len=0;
        cin>>len;
        int data[len];
        for(int i=0;i<len;i++)
        {
            cin>>data[i];
        }
        bubble(data,len);

        input--;
    }
    return 0;
}
