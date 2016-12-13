// 假設今天有一種特殊的方陣，邊長為7，且該方陣的每個元素是由外到內從1開始不斷增加，如以下範例：
//
//
// １１１１１１１
// １２２２２２１
// １２３３３２１
// １２３４３２１
// １２３３３２１
// １２２２２２１
// １１１１１１１
// 給定一個數字ｋ（例如11），則從方陣的左上角開始，以斜向且接續的方式數到第11個數字，例如以上的範例為1，則問題的答案即為1
// Input
// 第一行代表測資的筆數ｎ
// 接下來有ｎ行，每行兩個數字以空白間隔
// 第一個數字代表方陣的邊長，第二個數字ｋ代表要求的第ｋ個數
// Output
// 將數到的第ｋ個數字輸出
// Sample input
// 3
// 7 11
// 3 5
// 4 9
// Sample output
// 1
// 2
// 2
#include <iostream>
#include <math.h>

using namespace std;

void findNum(double l, int n){
    double pre_len = l;
    int center_n = (int)ceil(pre_len / 2);
    int len = (int)pre_len;
    int cnt = 0;
    int arr[len][len];

    for (int a=0; a<center_n; a++)
        for (int i=a; i<len - a; i++)
            for (int j=a; j<len-a; j++)
                arr[i][j] = a + 1;

    for(int i = 0; i < len * 2; i++)
        for(int k = 0; k <= i; k++)
            for(int l = 0; l <= i; l++)
                if (k + l == i && (i & 1) && k<len && l < len){
                    if(++cnt == n)
                        cout << arr[l][k] << endl;
                }
                else if(k+l == i&&!(i & 1) && k<len && l<len)
                    if(++cnt==n)
                        cout << arr[k][l] << endl;
}

int main(int argc, const char * argv[]){
    int pairs=0;
    double len=0;
    int n=0;
    cin>>pairs;
    while(pairs>0){
        cin>>len>>n;
        findNum(len, n);
        --pairs;
    }
    return 0;
}
