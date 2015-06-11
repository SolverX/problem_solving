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

#define FILE_INPUT true
#define SIZE 100005
typedef long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int N;
int sx,sy,ex,ey,bx,by;
int A[30][30];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
bool isPossible(int x,int y){
    if(x<0 || y<0 || x>=N || y>=N)
        return false;
    if(x==bx && y==by)
        return false;
    return true;    
}

int main(){
    if(FILE_INPUT)
        freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>N>>sx>>sy>>ex>>ey>>bx>>by;
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                A[i][j]=500;
        sx--;sy--;
        ex--;ey--;
        bx--;by--;
        queue<ii> Q;
        Q.push(ii(sx,sy));
        A[sx][sy]=0;
        bool found=false;
        while(!Q.empty() && !found){
            ii tmp = Q.front();
            Q.pop();
            int x = tmp.first;
            int y = tmp.second;
            for(int i=0;i<4;i++){
                int tmpx=x+dx[i],tmpy=y+dy[i];
                if(isPossible(tmpx,tmpy)){
                    if(A[tmpx][tmpy]==500){
                        A[tmpx][tmpy]=A[x][y]+1;
                        Q.push(ii(tmpx,tmpy));
                    }
                }
            }
        }
        cout<<A[ex][ey]<<endl;

    }

return 0;
}