#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <bitset>
using namespace std;
#define VISITED 2
#define EXPLORED 1
#define UN_VISISTED 0

typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
string s;
int DP[3001][3001];
int lps(int i, int j)
{
    if(DP[i][j]!=-1) return DP[i][j];
   if (i == j)
     return DP[i][j]=1;

   if (s[i] == s[j] && i + 1 == j)
     return DP[i][j]=2;

   if (s[i] == s[j])
      return DP[i][j]=lps (i+1, j-1) + 2;
   return DP[i][j]=max( lps(i, j-1), lps(i+1, j) );
}
void printPalindrome(int i,int j,int k,int l){
    cout<<"SET START"<<endl;
    for(;i<=j;i++)
        cout<<s[i];
    cout<<endl;
    for(;k<=l;k++)
        cout<<s[k];
    cout<<endl;
    cout<<"SET END"<<endl;
}
int main(){
    freopen("in.txt","rt",stdin);
    
    cin>>s;
    int len = s.length();
    memset(DP,-1,sizeof(DP));
    int maxValue = 1;
    for(int i=0;i<len-1;i++){
        maxValue = max(maxValue, lps(0,i) * lps(i+1,len-1));
    }
    cout<<maxValue<<endl;
    return 0;
}