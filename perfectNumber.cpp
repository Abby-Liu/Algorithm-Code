#include<iostream>
using namespace std;

int main() {
    unsigned long i,j,n=0;
    cin>>n;
    int arr[n];
    int sum[n];
    for(i=0;i<n;i++){
        sum[i]=0;
        cin>>arr[i];
        //找出arr[i]之perfect number有哪些
        for(j=1;j<=arr[i]/2;j++){
            if(arr[i]%j==0)
                //如果是因數就加起來存到sum[i]
                sum[i]+=j;
        }
        if(sum[i]==arr[i])
            //如果相加的結果是input之值就印出
            cout<<sum[i]<<" ";
    }
    return 0;
}

