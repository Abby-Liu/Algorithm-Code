// F(0)=0
// F(1)=1
// F(n) = F(n-1)+ F(n-2)   (n≧2)
// 用文字來說，就是費波那契數列由0和1開始，之後的費波那契系數就由之前的兩數相加。首幾個費波那契系數是：
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233……
// 請實作一程式,當輸入n時,請輸出F(n)
// 
// INPUT
// 第一行是測資個數k
// 接下來一行一個數字n , 共k行
//
// OUTPUT
// 請一行一個的輸出每個n的F(n)
//
// SAMPLE INPUT
// 3
// 1
// 10
// 8
//
// SAMPLE OUTPUT
// 1
// 55
// 21
#include <iostream>
using namespace std;

int fib(int x){
    int fNum=x;
    if(x==0)
        fNum=0;
    if(x==1)
        fNum=1;
    if(x>1)
        fNum=fib((x-1))+fib((x-2));
    return fNum;
}

int main(int argc, const char * argv[]){
    int i,n=0;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
        cout<<fib(arr[i])<<endl;
}
