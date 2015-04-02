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
int A[100001];
static int DP[100001][100001];
int calculate(int low,int high){
    if(low==high) return A[low];
    if(DP[low][high]!=0) return DP[low][high];
    int mid=(low+high)>>1;
    int val1 = calculate(low,mid);
    int val2 = calculate(mid+1,high);
    return DP[low][high]=min(val1,val2);
}
int main(){
    freopen("in.txt","rt",stdin);
    int N,T;
    cin>>N>>T;
    // memset(DP,0,sizeof(DP));
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    //cout<<"Works"<<endl;
   // int dummy=calculate(0,N);
    while(T--){
        int a,b;
        cin>>a>>b;
        cout<<calculate(a,b)<<endl;
    }

    return 0;
}