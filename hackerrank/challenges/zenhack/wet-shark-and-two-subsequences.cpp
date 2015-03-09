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

int A[20000],N,R,S;
int DP[100][2000][2000];
int findCount(int n,int R,int S){
    cout<<n<<" "<<R<<" "<<S<<endl;
    
    if(R==0 && S==0) return 1;
    if(n>=N || R<0 || S<0) return 0;
    if(DP[n][R][S]!=-1) return DP[n][R][S];
    int maxValue=0;
    for(int i=n+1;i<N;i++){
        maxValue = max(maxValue,findCount(i,R-(A[n]+A[i]),S-abs(A[i]-A[n]))+findCount(i,R,S));
    }
    return DP[n][R][S]=maxValue;

}
int main(){
    freopen("in.txt","rt",stdin);
    cin>>N>>R>>S;
    for(int i=0;i<N;i++)
        cin>>A[i];
    memset(DP,-1,sizeof(DP));
    cout<<R<<" "<<S<<endl;
    cout<<findCount(0,R,S)<<endl;
    return 0;
}