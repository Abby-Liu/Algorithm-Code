#include<iostream>
using namespace std;

void happy(int a) {
    int sum=0;
    while(true){
        if(a<10){
            sum=a;
            break;
        }
        while(a){
            sum+=(a%10)*(a%10);
            a/=10;
        }
        a=sum;
        sum=0;
    }
    if(sum==1||sum==7)
        cout<<"Happy"<<endl;
    else
        cout<<"Not Happy"<<endl;
}

int main() {
    int i=0,j=0;
    //n�����h�֭ӼƦr
    int n=0;
    cin>>n;
    //��J��n �~�i�гy�@�}�Carr[n]
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];

    for(j=0;j<n;j++)
        happy(arr[j]);
    return 0;
}
