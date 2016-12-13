// Input
// 輸入的第一列有一個整數代表以下有幾組測試資料。每組測試資料的第一列含有2個正整數 n（0 < n <= 50）和 m（0 < m <= 100），n 代表字串的長度，m 代表字串的數目。接下來的 m 列，每列有一個長度為 n 的字串。
// 第一列及第一組測試資料，以及各組測試資料間均有一空白列。
// Output
// 對每組測試資料按照「未排序」的程度，由小到大輸出各字串。假如有不只2個字串「未排序」的程度相同，則按照它們在輸入中的順序輸出。
// 各組測試資料之間請輸出一空白列
// Sample Input
// 2
// 10 6
// AACATGAAGG
// TTTTGGCCAA
// TTTGGCCAAA
// GATCAGATTT
// CCCGGGGGGA
// ATCGATGCAT
//
// 2 3
// TC
// TT
// TA
// Sample Output
// CCCGGGGGGA
// AACATGAAGG
// GATCAGATTT
// ATCGATGCAT
// TTTTGGCCAA
// TTTGGCCAAA
//
// TT
#include <iostream>
#include <string.h>

using namespace std;

int sort_level(char data[]);
void string_sort(int print[],int sort_flag[],int Size);

int main()
{
    int t,r;
    cin>>t;

    for( r=0;r<t;r++)
    {
        if(r!=0)
            cout<<endl;


        int num,len;
        cin>>len>>num;
        char in[200][60];
        for(int i=0;i<num;i++)
        {
            cin>>in[i];
        }
        int sort_refer[200]={0};
        for(int i=0;i<num;i++)
        {
            sort_refer[i]=sort_level(in[i]);
        }
        /*
         for(int i=0;i<num;i++)
         {
         cout<<sort_refer[i];
         }
         */
        int print[200];
        string_sort(print,sort_refer,num);
        for(int i=0;i<num;i++)
        {
            cout<<in[print[i]]<<endl;
        }


    }
    return 0;
}
void string_sort(int print[],int sort_flag[],int size)
{
    int i,j;
    int check[1000]={0};
    for(i=0;i<size;i++)
    {
        int minval=10000,mindex=0;
        for(j=0;j<size;j++)
        {
            if(sort_flag[j] < minval && !check[j])
            {
                mindex=j;
                minval=sort_flag[j];
            }
        }
        print[i]=mindex;
        check[mindex]=1;
    }

}

int sort_level(char data[])
{
    int num=0;
    for(int i=0;i<strlen(data);i++)
    {
        for(int j=i+1;j<strlen(data);j++)
        {
            if(data[i]>data[j])
                num++;
        }
    }//cout<<num;

    return num;
}
