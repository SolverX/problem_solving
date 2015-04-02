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

static int DP[10005];
int A[10005];
int N,Q,to,skip;
int findSkip(int pos){
    if(pos>N) return 0;
    if(skip+pos>to) return A[pos];
    if(DP[pos]!=0) return DP[pos];
    return DP[pos]= A[pos]+findSkip(pos+skip);

}
int main(){
    freopen("in.txt","rt",stdin);
    
    cin>>N>>Q;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        
    }
    skip=1;
    to=N;
    findSkip(1);

    while(Q--){
        int from;
        cin>>from>>to>>skip;

        cout<<findSkip(from)<<endl;
        //cout<<skip<<" "<<from<<" "<<last<<" "<<val<<" "<<DP[skip][last]<<" ";
        //cout<<DP[skip][last][0]<<endl;
    }

    return 0;
}