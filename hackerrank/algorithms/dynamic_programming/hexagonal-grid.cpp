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
#define MOD 1000000007

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int A[2][12];
int N;
bool isPossibleMethod1(int i,int j){
    int x = i+1,y=j;
    if(x>=2 || y>=N || y<0 || x<0 || A[x][y]==1 || A[i][j]==1) return false;
    return true;
}
bool isPossibleMethod2(int i,int j){
    int x = i+1,y=j-1;
    if(x>=2 || y>=N || y<0 || x<0 || A[x][y]==1 || A[i][j]==1) return false;
    return true;
}
bool isPossibleMethod3(int i,int j){
    int x = i,y=j+1;
    if(x>=2 || y>=N || y<0 || x<0 || A[x][y]==1 || A[i][j]==1) return false;
    return true;

}
bool found=false;
int holes=0;
void print(){
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void backtrack(int i,int j){
    if(holes==0){
        found=true;

    }
    // print();
    // cout<<endl;
    if(i>=2 || j>=N)return;
    for(;i<2 && !found;i++,j=0){
        for(;j<N && !found;j++){
            int x,y;
            if(!found && isPossibleMethod2(i,j)){
                int x = i+1,y=j-1;
                A[i][j]=A[x][y]=1;
                holes-=2;
                backtrack(i,j);
                holes+=2;
                A[i][j]=A[x][y]=0;
            }
            if(!found && isPossibleMethod1(i,j)){
                int x = i+1,y=j;
                A[i][j]=A[x][y]=1;
                holes-=2;
                backtrack(i,j);
                holes+=2;
                A[i][j]=A[x][y]=0;
            }
            
            if(!found && isPossibleMethod3(i,j)){
                int x = i,y=j+1;
                A[i][j]=A[x][y]=1;
                holes-=2;
                backtrack(i,j);
                holes+=2;
                A[i][j]=A[x][y]=0;
            }
        }
    }
}
int main(){
    if(FILE_INPUT)
        freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        getchar();
        holes=0;
        int Ax,Bx;
        cin>>Ax>>Bx;
        for(int i=0;i<N;i++){
            A[0][N-i-1] = Ax%10;
            holes+= (Ax%10)==0;
            Ax/=10;
            
        }
        for(int i=0;i<N;i++){
            A[1][N-i-1]=Bx%10;
            holes+=(Bx%10)==0;
            Bx/=10;
            
        }
        // cout<<holes<<endl;
        found=false;
        backtrack(0,0);
        if(found){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}