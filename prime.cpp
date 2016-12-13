//prime solution
#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,nCount=0,nFact=0;
    cin>>n;
    cout<<n<<"=";
    for(int i=2;i<=n;) {
        //Case1: 若i能整除n
        if(n%i==0) {
            n/=i;   //若能整除n，就先找出商
            if(nFact!=i) {       //nFactor changed
                if(nCount>1) {     //指數大於一
                    cout<<"^"<<nCount;
                }
                if(nFact!=0) {     //the next nFact(not the first nFactor)
                    cout<<"*";
                }
                nFact=i;
                cout<<nFact;
                nCount=1;
                continue;
            }
            ++nCount;
            continue;
        }
        //Case2: 若不能整除，如果i>2一次+2，或+1繼續除
        if(i>sqrt(double(n)) )
        {
            i = n;
            continue;
        }
        if(i>2) {
            i+=2;
        }
        else {
            i++;
        }
    }
    return 0;
}