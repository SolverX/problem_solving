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

int BUILDING[1901][1901];
int DP[1901];

int main(){
    freopen("in.txt","rt",stdin);
    int n,h,f;
    cin>>n>>h>>f;
    memset(DP,0,sizeof(DP));
    memset(BUILDING,0,sizeof(BUILDING));
    for(int i=0;i<n;i++){
        int Q;
        cin>>Q;
        while(Q--){
            int tmp;
            cin>>tmp;
            tmp--;
            BUILDING[i][tmp]++;
        }
    }
    for(int i=0;i<n;i++){
        DP[h] = max(DP[h],BUILDING[i][h]);
    }
    for(int i=h-1;i>=0;i--){
        for(int j=0;j<n;j++){
            BUILDING[j][i]+=max(BUILDING[j][i+1], ((i+f)<=h)?DP[i+f]:0);
            DP[i]=max(DP[i],BUILDING[j][i]);
        }
    }
    cout<<DP[0]<<endl;
    return 0;
}