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
long long B[1000001];
string a,b;
int sumOf(int l, int r){
    if(l < 0)
        l = 0;
    if(r >= b.length())
        r = b.length() - 1;
    if(l > r)
        return 0;
    return B[r] - (l == 0 ? 0 : B[l - 1]);
}

int main(){
    if(FILE_INPUT)
        freopen("in.txt","r",stdin);
    
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    const int NMAX = int(1e6);
    const int mod = int(1e9) + 7;
    const int n = 314159;
    B[0]= (b[0]-'0');
    for(int i=1;i<b.length();i++){
        B[i]= (B[i-1])+(b[i]-'0');
        // cout<<B[i]<< " ";
    }
    long long sum=0;
    long long power=1;
    long prev=0;
    for(int i=0;i<NMAX;++i){
        int start = i>=a.length()?0:a[i]-'0';
        int cnt= sumOf(i-n,i);
        // cout<<B[i]<<" ";
            if(start){
                sum = (sum + power * (n+1-cnt) )%mod;
            }else{
                sum = (sum +power * cnt)%mod;
                
            }
            power = (power*2LL)%mod;
            prev=i;
            // cout<<cnt<<endl;

    }
    cout<<sum<<endl;

    return 0;
}