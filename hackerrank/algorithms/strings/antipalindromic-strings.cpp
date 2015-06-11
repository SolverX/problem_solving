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

int main(){
    freopen("in.txt","rt",stdin);
    long T;
    cin>>T;
    while(T--){
        long N,M;
        cin>>N>>M;
        long sum=1;
        long neg=1;
        for(int i=0;i<N;i++){
            sum*=M;
            if(i!=0){
                neg*=M;
                neg%=MOD;
            }
            sum%=MOD;
        }
        long res = sum<=neg?(MOD-sum-neg):sum-neg;
        cout<<sum<<" "<<neg<<endl;
    }
    return 0;
}