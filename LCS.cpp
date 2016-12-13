// LCS: 最長共同子序列
// Sample input
// 3
// aabbacd
// aabacab
// mississippi
// ispim
// 1123123
// 111233
// Sample output
// 5
// 4
// 5
#include <iostream>
#include <vector>
using namespace std;
string find_lcs(const string s1, const string s2, string s3){
    const size_t len1 = s1.size();
    const size_t len2 = s2.size();

    vector< vector<unsigned int> > d(len1+1, vector<unsigned int>(len2+1));
    vector< vector<unsigned int> > b(len1+1, vector<unsigned int>(len2+1));
    const int w=1, n=2, nw=3;
    for(int i=1;i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(s1[i-1] == s2[j-1]){
                d[i][j] = d[i-1][j-1]+1;
                b[i][j] = nw;
            }
            else{
                if(d[i-1][j]>= d[i][j-1]){
                    d[i][j] = d[i-1][j];
                    b[i][j] = n;
                }
                else{
                    d[i][j] = d[i][j-1];
                    b[i][j] = w;
                }
            }
        }
    }

    s3.resize(d[len1][len2]);
    int i=len1, j=len2, k=d[len1][len2]-1;
    while(k>=0 && i>0 &&j>0){
        if ( b[i][j] == nw )
        {
            s3[k--] = s1[i-1];
            i-- ;
            j-- ;
        }
        else if (b[i][j] == n)
            i-- ;
        else if (b[i][j] == w)
            j--;
        else
            break;
    }
    return s3;
}

int main(int argc, const char * argv[]) {
    int pairs=0;
    vector<string> seq;
    string seq1("abcbdab"), seq2("bdcaba"), seq3;
    string result;
    cin>>pairs;
    for(int i=0;i<pairs;i++){
        cin>>seq1;
        cin>>seq2;
        result=find_lcs(seq1, seq2, seq3);
        cout<<result.size()<<endl;
    }
    return 0;
}
