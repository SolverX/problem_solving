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
int DP[5001][5001];
int main(){
    freopen("in.txt","rt",stdin);
    string a,b;
    cin>>a>>b;
    int len = a.length();
    int z=0,ans;
    memset(DP,0,sizeof(DP));
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            if(a[i-1]==b[j-1] ){
                DP[i][j]=DP[i-1][j-1]+1;
            }else{
                DP[i][j]= max(DP[i][j-1],DP[i-1][j]);
            }
        }
    }
    cout<<DP[len][len]<<endl;
    return 0;
}