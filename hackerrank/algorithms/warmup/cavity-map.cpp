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
using namespace std;
#define VISITED 2
#define EXPLORED 1
#define UN_VISISTED 0

typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int main(){
    freopen("in.txt","rt",stdin);
    int N;
    cin>>N;
    string s[200];
    for(int i=0;i<N;i++){
        cin>>s[i];
    }
    for(int i=1;i<N-1;i++){
        for(int j=1;j<N-1;j++){
            bool isCavity=true;
            for(int k=0;k<4;k++){
                int tx=i+dx[k],ty=j+dy[k];
                if(s[tx][ty]>=s[i][j]){
                    isCavity=false;
                    break;
                }

            }
            if(isCavity){
                s[i][j]='X';
            }
        }
    }
    for(int i=0;i<N;i++)
        cout<<s[i]<<endl;
    return 0;
}