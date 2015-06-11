#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
using namespace std;

#define SIZE 250
#define FILE_INPUT true

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long long coin[51];
unsigned long long DP[SIZE+1][51];
long N,M;

long countNumberOfWays(long long coins,int pos){
    if(coins<0 || pos>=M) return 0;
    if(coins==0) return 1;
    if(DP[coins][pos]) return DP[coins][pos];
    // cout<<coins<<endl;
    return DP[coins][pos]= countNumberOfWays(coins-coin[pos],pos)+countNumberOfWays(coins,pos+1);
}

int main(){
    if(FILE_INPUT)
        freopen("in.txt","r",stdin);
    cin>>N>>M;
    memset(DP,0,sizeof(DP));
    for(int i=0;i<M;i++){
        cin>>coin[i];
    }
    cout<<countNumberOfWays(N,0)<<endl;
    return 0;
}