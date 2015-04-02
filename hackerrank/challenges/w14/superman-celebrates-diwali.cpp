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
 int acorn[1901][1901],dp[1901];
int main(){
    freopen("in.txt","rt",stdin);
    int t,h,f;
    cin>>t>>h>>f;

    memset(acorn,0,sizeof(acorn));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<t;i++){
        int Q;
        cin>>Q;
        while(Q--){
            int tmp;
            cin>>tmp;
            tmp--;
            acorn[i][tmp]++;
        }
    }
    for (int tree = 0; tree < t; tree++)
        dp[h] = max(dp[h], acorn[tree][h]);
    for (int height = h - 1; height >= 0; height--)
        for (int tree = 0; tree < t; tree++) {
            acorn[tree][height] += max(acorn[tree][height + 1],((height + f <= h) ? dp[height + f] : 0));
            dp[height] = max(dp[height], acorn[tree][height]);
        }
    printf("%d\n", dp[0]);
    return 0;
}