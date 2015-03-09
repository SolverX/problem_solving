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

int main(){
    freopen("in.txt","rt",stdin);
    int T;
    cin>>T;
    while(T--){
        ull A,N,M;
        cin>>A>>N>>M;
        ull Value=A;
        ull Mul=1;
        int tmp=A;
        // cout<<N<<endl;
        while(tmp>0){
            Mul*=10;
            tmp/=10;
        }
        while(Value<=M && --N){
            Value*=Mul;
            Value+=A;
        }
        // cout<<N<<endl;
        ull modValue = Value%M;
        while(N>1){
            N--;
            if(modValue!=0)
                modValue = (Value * Mul + modValue)%M;
            else
                modValue = Value % M;
        }
        cout<<modValue<<endl;
    }
    return 0;
}