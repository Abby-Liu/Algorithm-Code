// min edir cost 最小編輯成本
// 操作一(remove)的成本為2
// 操作二(insertion)的成本為3
// 操作三(replace)的成本為4
// Input
// 第一行為測資組數N
// 接下來共有2*N行
// 每組第一行為字串A
// 每組第二行為字串B
// 字串長度上限為20
// Output
// 輸出每組的總成本
//
// Sample input
// 3
// HABCDACE
// DABCDACE
//
// AKNLH
// QWERTY
// HWTDDGKY
//
// Sample output
// 4
// 15
// 20
#include <iostream>
using namespace std;

int min(int x, int y, int z)
{
    if(x<y)
        return x<z? x:z;
    else
        return y<z? y:z;
}

int EditDistance(char *s1, int m, char *s2, int n)
{
    //s1 is empty, insert to s1 (cost:3 per char)
    if(m == 0)  return n*3;

    //s2 is empty, remove all characters from s1(cost:2 per char)
    if(n == 0)  return m*2;

    //if s1 and s2的最後一個字都一樣，繼續扣以比較
    if(s1[m-1] == s2[n-1])
        return EditDistance(s1, m-1, s2, n-1);
    //最後一個字不一樣，考慮三種操作：Insert / Remove / Replace
    return  min(EditDistance(s1, m-1, s2, n)+2,
                   EditDistance(s1, m, s2, n-1)+3,
                   EditDistance(s1, m-1, s2, n-1)+4);
}

int main(int argc, const char * argv[]) {
    int num,m,n;
    char s1[50],s2[50];
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>s1>>s2;
        m = strlen(s1);
        n = strlen(s2);
        //cout<<m<<" "<<n;
        cout<<EditDistance(s1, m, s2, n);
        //cout<<s1<<endl<<s2;
    }

    return 0;
}
