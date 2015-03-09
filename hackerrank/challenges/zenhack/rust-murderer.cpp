#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
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
int main(){
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
        vector<vi> ADJ;
        long N,P,S;
        cin>>N>>P;
        long dist[N+1],inDegree[N+1];
        ADJ.assign(N+1,vi());

        memset(inDegree,0,sizeof(inDegree));
        memset(dist,0,sizeof(dist));
        while(P--){
            int x,y;
            cin>>x>>y;
            x--;y--;
            ADJ[x].push_back(y);
            ADJ[y].push_back(x);
        }
        cin>>S;
        S--;
        queue<int> Q;
        Q.push(S);
        bool first = true;
        while(!Q.empty()){
            long u = Q.front();Q.pop();
            for(int i=0;i<ADJ[u].size();i++){
                int v = ADJ[u][i];
                if(dist[v]==0){
                    dist[v] = dist[u] +1;
                    Q.push(v);
                }
            }

        }
        for(int i=0;i<N;i++){
            if(i!=S){
                    if(!first)
                        cout<<" ";
                    first=false;
                cout<<dist[i]+1;
            }
        }
        cout<<endl;

    }
    return 0;
}