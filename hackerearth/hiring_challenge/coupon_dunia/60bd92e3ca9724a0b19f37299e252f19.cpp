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
        ull N[3];
        cin>>N[0]>>N[1]>>N[2];
        sort(N,N+3);
        ull A=N[1];
        ull B=N[2];
        if(A<=0){
            if(B>0)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }else if (A==B) {
            cout<<A+B<<endl;
        }else{
            cout<<(A+A+1)<<endl;
        }
    }
    return 0;
}