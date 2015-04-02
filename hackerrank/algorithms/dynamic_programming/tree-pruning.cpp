
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

long dfs_order[100001],weight[100001],DP[100001];
long cnt[100001];
int _cnt=1,N,K;
vector<vi> ADJ;
void dfs(int u){
    dfs_order[_cnt++] = u;
    cnt[u]=1;
    for(int i=0;i<ADJ[u].size();i++){
        int v = ADJ[u][i];
        if(cnt[v]) continue;
        dfs(v);
        cnt[u]+=cnt[v];
    }

}
int main(){
    freopen("in.txt","rt",stdin);
    cin>>N>>K;
    memset(DP,0,sizeof(DP));
    for(int i=1;i<=N;i++)
        cin>>weight[i];
    ADJ.assign(N+2,vi());
    for(int i=1;i<N;i++){
        int x,y;
        cin>>x>>y;
        ADJ[x].push_back(y);
        ADJ[y].push_back(x);
    }
    memset(dfs_order,0,sizeof(dfs_order));
    memset(cnt,0,sizeof(cnt));
    dfs(1);
    for(int i=1;i<=N;i++){
        DP[i]= weight[dfs_order[i]]+DP[i-1];
    }

    for(int i=1;i<=K;i++){
        for(int j=N;j>=1;j--){
            int pos = j + cnt[dfs_order[j]]-1;
            DP[pos] = max(DP[pos],DP[j-1]);
        }
        for(int j=1;j<=N;j++){
            DP[j] = max(DP[j],DP[j-1] + weight[dfs_order[j]]);   
        }

    }
    cout<<DP[N]<<endl;
    // cout<<maxValue(1,K)<<endl;
    return 0;
}