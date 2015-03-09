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

vector<vi> ADJ;
map<int,int> ChildCount;

int dfs(int u){
    if(ChildCount[u]) return ChildCount[u];
    ChildCount[u] = 1;
    for(int i=0;i<ADJ[u].size();i++){
        int v = ADJ[u][i];
        if(ChildCount[v]==0){
            ChildCount[u]+=dfs(v);
        }
    }
    return ChildCount[u];
}
int main(){
    freopen("in.txt","rt",stdin);
    int N,M;
    cin>>N>>M;
    ADJ.assign(N+1,vi());
    bool inDegree[N+1];
    memset(inDegree,false,sizeof(inDegree));
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        ADJ[x].push_back(y);
        ADJ[y].push_back(x);
        inDegree[y]=true;
    }
    // int count = 0;
    for(int i=1;i<=N;i++){
        if(ChildCount[i]==0){
            //cout<<i<<endl;
            int tmp = dfs(i);
        }
    }
    ull sum=-1;
    for(int i=1;i<=N;i++){
       sum+= (ChildCount[i]%2==0);
    }
    cout<<sum<<endl;
    return 0;
}