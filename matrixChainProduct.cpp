// Matrix Priduct 矩陣鏈乘積
// 請實作矩陣鏈乘積演算法，計算最小的矩陣乘積
// Input
// 第一行代表矩陣的個數K
// 第二行有K+1個數,其中第n與第n+1個數代表第n個矩陣的row與column
// Sample input
// 6
// 30 35 15 5 10 20 25
// Sample output
// 15125
#include <iostream>

#include <vector>
using namespace std;

typedef vector< vector<int> > intMatrix;

int matrixChainOrder(const vector<int>&p, vector < vector<int> >&m, vector < vector<int> >&s)
{
	int n = (int)p.size()-1;
	m.resize(n);
	for (int i=0;i<n;i++)
		m[i].resize(n);
	s.resize(n);
	for (int i=0;i<n;i++)
		s[i].resize(n);
	for (int l=2;l<=n;l++)
	{
		// l:length
		for (int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			m[i][j] = 999999999;
			for (int k=i;k<j;k++)
			{
				int q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	return m[0][n-1];
}
void printSequence(const intMatrix& s, int i, int j)
{
	if (i<j)
	{
		cout<<"(";
		printSequence(s, i, s[i][j]);
		printSequence(s, s[i][j]+1,j);
		cout<<")";
	}
	else
		cout<< "M["<<i<<"]";
}

int main(int argc, const char * argv[]) {
    //int kk[]={30,35,15,5,10,20,25};
    int num;
    cin>>num;
    int k[num+1];
    for(int i=0;i<num+1;i++)
        cin>>k[i];
    //for(int i=0;i<num+1;i++)
    //    cout<<k[i];
    vector<int> p(k,k+sizeof(k)/sizeof(k[0]));
    intMatrix m;
    intMatrix s;
    // number of multiplication
    cout<<matrixChainOrder(p, m, s)<<endl;
    //backtrack the sequence
    //printSequence(s, 0,(int)p.size()-2);
    return 0;
}
