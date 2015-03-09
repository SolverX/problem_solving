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
map<int,int> DP;
int dfs(int u){
    // cout<<ADJ[u].size()<<endl;
    if(DP[u]!=0) return DP[u];
    if(u==100) return 0;
    int tmp = 99999;
    DP[u]=99999;
    // cout<<u<<endl;
    for(int i=u;i<=(u+6) && i<=100;i++){
        // cout<<i<<endl;
        if(ADJ[i].size()==1){
           
            if(ADJ[i][0]>i)
            tmp = min(tmp,dfs(ADJ[i][0]));
            
        }
        else
            tmp = min(tmp,dfs(i));
    }
    return DP[u] = tmp+1;

}

int main(){
    freopen("in.txt","rt",stdin);
    int T;
    scanf("%d\n",&T);
    while(T--){
        ADJ.assign(105,vi());
        ADJ.clear();
        DP.clear();
        int LadersCount,SnakesCount;
        scanf("%d,%d\n",&LadersCount,&SnakesCount);
        // 
        for(int i=0;i<LadersCount;i++){
            int start,end;
            scanf("%d,%d ",&start,&end);
            ADJ[start].push_back(end);
        }
        for(int i=0;i<SnakesCount;i++){
            int start,end;
            scanf("%d,%d ",&start,&end);
            ADJ[start].push_back(end);
        }
        // cout<<SnakesCount<<endl;
        cout<<dfs(1)<<endl;
    }
    return 0;
}