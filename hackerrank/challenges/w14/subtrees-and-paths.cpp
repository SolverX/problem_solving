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
vector<vi> CHILD;
int VAL[100004];
int PARENT[100004];
// map<int,int> PARENT;
int N,Q;
bitset<100004> visited;
int maxBetween(int x,int y){
    
    int maxValue[N+1];
    // memset(maxValue,)
    int maxVal=VAL[x];
    while(!visited[x]){
        visited[x]=true;
        maxVal=max(maxVal,VAL[x]);
        maxValue[x]=maxVal;
        x=PARENT[x];
    }
    maxVal = VAL[y];
    while(!visited[y]){
         visited[y]=true;
         //cout<<"came"<<endl;
         maxVal = max(maxVal,VAL[y]);
         maxValue[y]=maxVal;
         y=PARENT[y];

    }
     maxValue[y]=max(maxVal,maxValue[y]);

    return maxValue[y];

}
void findChilds(int u){
    if(visited[u]) return;
    visited[u]=true;
    for(int i=0;i<ADJ[u].size();i++){
        int v = ADJ[u][i];
        if(visited[v]) continue;
        PARENT[v]=u;
        CHILD[u].push_back(v);
        findChilds(v);
    }
}
void update(int u,int val){
    VAL[u]+=val;
    // cout<<"Updated "<<u<<" "<<VAL[u]<<endl;
    for(int i=0;i<CHILD[u].size();i++){
        int v = CHILD[u][i];
        update(v,val);
    }
}
int main(){
    freopen("in.txt","rt",stdin);
    cin>>N;
    ADJ.assign(N+1,vi());
    CHILD.assign(N+1,vi());
    for(int i=0;i<N-1;i++){
        int x,y;
        cin>>x>>y;
        ADJ[x].push_back(y);
        ADJ[y].push_back(x);
        VAL[i+1]=0;
        //CHILD[x].push_back(y);

    }
    VAL[N]=0;
    PARENT[1]=1;
    findChilds(1);
    cin>>Q;
    while(Q--){
        string s;
        cin>>s;
        int x,y;
        if(s=="max"){
            visited.reset();
            cin>>x>>y;
            cout<<maxBetween(x,y)<<endl;
        }else{
            cin>>x>>y;
            update(x,y);
            // for(int i=1;i<=N;i++){
            //     cout<<i<<" = "<<VAL[i]<<endl;
            // }
            // cout<<"----------------"<<endl;
        }
    }
    return 0;
}