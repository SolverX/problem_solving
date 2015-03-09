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

typedef long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define MAX_NUM 1000000000
ull N,M;
bool isPerfectSquare(ull a)
{
  ull sqrtA = floor(sqrt(a*1.0));
  if( sqrtA*sqrtA == a )
    return true;
  return false;
}
int main(){
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>N>>M;
        ull a,b;
        a= ceil(sqrt(N));
        b= floor(sqrt(M));
        if(isPerfectSquare(N)){
            cout<<(b-a+1)<<endl;
        }else if(isPerfectSquare(M)){
            cout<<(b-a)<<endl;
        }else{
            cout<<(b-a)<<endl;
        }
    }
    return 0;
}