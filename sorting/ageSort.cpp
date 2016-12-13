#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long int n;
    //int* arr=new int[n];
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        int arr[n];
        int arr_len=sizeof(arr)/sizeof(int);

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+arr_len);

        for(int i=0;i<n;i++)
        {
            cout<<arr[i];
            if(i<(n-1))
                cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}
