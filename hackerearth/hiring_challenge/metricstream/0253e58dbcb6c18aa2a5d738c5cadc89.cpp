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
#define MOD 1000000007
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ull pow(ull n, ull exp){
  ull prod = 1;
  while (exp > 0){
    if ((exp & 1) != 0)

       prod *=n;
    prod%=MOD;

    n*=n;
    exp >>= 1;
  }
  return prod;
}
ull P[1000001],A[1000001];

int main(){
    // sieve();
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
        ull sum=1,X,sample=1;
        cin>>X;
        for(int i=0;i<X;i++){
           cin>>P[i];
           sample*=P[i];
           sample%=MOD;
        }
        for(int i=0;i<X;i++){
           cin>>A[i];    
           sum*=pow(P[i],A[i]);
           sum%=MOD;
           // cout<<pow(P[i],A[i])<<endl;
        }
        ull total=0,ans=(sum/sample);
        for(int i=1;i<=ans;i++){
            total+=(sample*i);
        }
        cout<<total<<endl;
    }
    return 0;
}