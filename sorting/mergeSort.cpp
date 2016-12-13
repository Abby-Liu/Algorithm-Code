// Merge Sorting
#include <iostream>
#define ENDP 100000000
using namespace std;
int* MergeSort(int *, int, int);
void Merge(int *, int, int, int);

int* MergeSort(int A[], int p, int r)
{
    if(p==r) return A;  //頭=尾 即只剩下一個元素時
    
    return 0;
}

void Merge(int A[], int p, int q, int r)
{
    int n = q-p+1;      //左半部陣列的index
    int m = r-q;        //右半部陣列的index
    int L[n];           //左半部陣列
    int R[m];           //右半部陣列
    
    for(int i = 0 ; i < n ; i ++)
        L[i]=A[p+i-1];  //將A左半邊的內容複製到L
    
    for(int i=0; i<m; i++)
        R[i]=A[q+i];    //將A右半邊的內容複製到R
    
    L[n+1]=ENDP;
    R[m+1]=ENDP;
    
    int i=1, j=1;
    
    for(int k=p;k<r;k++){
        ;
    }
    
    
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
