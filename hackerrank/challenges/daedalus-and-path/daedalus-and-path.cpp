#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
string MAP[1006];
long DP[1006][1006];
long R,C;
long dx[]={-1,0,0,1},dy[]={0,-1,1,0};
long floodfill(long x,long y){
    //cout<<MAP[x][y]<<endl;
    if(MAP[x][y] == 'F')
        return DP[x][y]=1;
    if(DP[x][y]!=0) return DP[x][y];
    MAP[x][y]='T';
    long result = 999999;
    for(long i=0;i<4;i++){
        long tx=x+dx[i],ty=y+dy[i];
        if(tx>=0 && ty>=0 && tx<R && ty<C && MAP[tx][ty]!='T'){
            // cout<<MAP[tx][ty]<<endl;
            result = min(1+floodfill(tx,ty),result);
        }
    }
    return DP[x][y] = result;
}
int main(){
    freopen("in.txt","r",stdin);
    cin>>R>>C;
    long sx=-1,sy=-1;
    memset(DP,0,sizeof(DP));
    for(long i=0;i<R;i++){
        cin>>MAP[i];
        if(sx==-1)
        for(long j=0;j<C;j++){
            if(MAP[i][j]=='S')
                sx=i,sy=j;
            
        }
        //cout<<MAP[i][1]<<endl;
    }
    long result = floodfill(sx,sy)-1;
    for(long i=0;i<R;i++){
        for(long j=0;j<C;j++)
        if(MAP[i][j]=='F' && DP[i][j]==0){
            cout<<(-1)<<endl;
            return 0;
        }
    }
    if(result<999999)
        cout<<result<<endl;
    else
        cout<<(-1)<<endl;
}