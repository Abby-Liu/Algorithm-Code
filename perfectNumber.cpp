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
        //��Xarr[i]��perfect number������
        for(j=1;j<=arr[i]/2;j++){
            if(arr[i]%j==0)
                //�p�G�O�]�ƴN�[�_�Ӧs��sum[i]
                sum[i]+=j;
        }
        if(sum[i]==arr[i])
            //�p�G�ۥ[�����G�Oinput���ȴN�L�X
            cout<<sum[i]<<" ";
    }
    return 0;
}

